public class HuffmanEncoder {
    private String text;
    private Message msgObject;
    private HuffmanTree huffmanTree;
    private CharLinkedList charset;
    private boolean hasBeenCompressed;

    public HuffmanEncoder(String text) {
        this(new Message(text));
    }

    public HuffmanEncoder(Message msg) {
        this.msgObject = msg;
        this.text = msgObject.getMessage();
        huffmanTree = new HuffmanTree(msgObject);
        charset = new CharLinkedList();
        hasBeenCompressed = false;
    }

    public void compress() {
        lookUp(huffmanTree.getRoot(), "");
        hasBeenCompressed = true;
    }
    // Recursively building a lookup table from a huffman tree
    // using a linked list with their new sequence of bits.
    public void lookUp(Node node, String s) {
        if(!node.isLeaf()) {
            lookUp(node.left, s + "0");
            lookUp(node.right, s + "1");
        } else {
            charset.add(node.character, s, node.frequency);
        }
    }

    // returns the percentage of decrease in the size of the message
    public double howMuchCompressed() {
        if(!hasBeenCompressed)
            throw new RuntimeException("ERROR: Message has not been compressed!");
        return ((msgObject.getSize() - getSizeOfSequence()) /
                (double) msgObject.getSize()) * 100 ;
    }
    
    public CharLinkedList get_charset() {
        return charset;
    }

    public String[] compressedBinaryCode() {
        if(!hasBeenCompressed)
            throw new RuntimeException("ERROR: Message has not been compressed!");
        String[] d = new String[text.length()];
        for(int i = 0; i < text.length(); i++) {
            d[i] = charset.getCharNode(text.charAt(i)).bit_size;
        }
        return d;
    }

    public void indivSequence() {
        if(!hasBeenCompressed)
            throw new RuntimeException("ERROR: Message has not been compressed!");
        CharNode trav = charset.getLink();
        while(trav != null) {
            System.out.println(trav.ch + ": " + trav.bit_size);
            trav = trav.next;
        }
    }

    public int getSizeOfSequence() {
        if(!hasBeenCompressed)
            throw new RuntimeException("ERROR: Message has not been compressed!");
        int totalSize = 0;
        int bits = 0;
        CharNode n = charset.getLink();
        while(n != null) {
            totalSize += n.frequency * n.bit_size.length();
            bits += n.bit_size.length();
            n = n.next;
        }
        totalSize += (Message.CHAR_SIZE * charset.size()) + bits;
        return totalSize;
    }
}
