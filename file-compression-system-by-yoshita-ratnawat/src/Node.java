public class Node implements Comparable<Node> {
    Node left;
    Node right;
    char character;
    int frequency;

    Node(final char character, final int frequency, final Node left, final Node right) {
        this.character = character;
        if(frequency < 0) throw new IllegalArgumentException("Error: Frequency must be >= 0");
        this.frequency = frequency;
        this.left = left;
        this.right = right;
    }

    public boolean isLeaf() {
        return this.left == null && this.right == null;
    }

    public int compareTo(final Node that) {
        final int frequencyCompare = Integer.compare(this.frequency, that.frequency);
        if(frequencyCompare != 0) {
            return frequencyCompare;
        }
        return Integer.compare(this.character, that.character);
    }

    public String toString() {
        String str = "" + character;
        return str;
    }
}
