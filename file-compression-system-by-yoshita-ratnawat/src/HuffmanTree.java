public class HuffmanTree {
    private Node root;
    private Message sequence;

    HuffmanTree(Message sequence) throws RuntimeException {
        if(sequence.isEmpty())
            throw new RuntimeException("Error: Sequence of length 0");
        this.sequence = sequence;
        root = buildHuffmanTree();
    }

    public Message getMessage() { return sequence; }

    public Node buildHuffmanTree() {
        MinPriorityQueue<Node> priorityQueue = populatePQ();

        if(priorityQueue.len() == 1) {
            priorityQueue.add(new Node('\0', 1, null, null));
        }

        while(priorityQueue.len() > 1) {
            final Node left = priorityQueue.poll();
            final Node right = priorityQueue.poll();
            final Node parent = new Node('\0', left.frequency + right.frequency, left, right);

            priorityQueue.add(parent);
        }
        return priorityQueue.poll();
    }


    private MinPriorityQueue<Node> populatePQ() {
        MinPriorityQueue<Node> pq = new MinPriorityQueue<>();
        int[] freqs = sequence.getFrequencies();
        for(char i = 0; i < freqs.length; i++) {
            if(freqs[i] > 0) {
                pq.add(new Node(i, freqs[i], null, null));
            }
        }
        return pq;
    }

    // Traversals to traverse through a huffman tree:

    public void inOrder() {
        inOrder(root);
        System.out.println();
    }

    public void preOrder() {
        preOrder(root);
        System.out.println();
    }

    public void postOrder() {
        postOrder(root);
        System.out.println();
    }

    private void inOrder(Node node) {
        if(node == null) return;
        inOrder(node.left);
        System.out.print(node.frequency + " ");
        inOrder(node.right);
    }

    private void preOrder(Node node) {
        if(node == null) return;
        System.out.print(node.frequency + " ");
        preOrder(node.left);
        preOrder(node.right);
    }

    private void postOrder(Node node) {
        if(node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.frequency + " ");
        }
    }

    public void levelOrder() {
        QueueLL<Node> q = new QueueLL<>();
        q.offer(root);
        Node trav;

        while(!q.isEmpty()) {
            trav = q.poll();
            if(trav != null) {
                System.out.print(trav.frequency + " ");
                q.offer(trav.left);
                q.offer(trav.right);
            }
        }
        System.out.println();
    }

    public Node getRoot() { return root; }
}

