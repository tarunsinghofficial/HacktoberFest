public class ByteNode implements Comparable<ByteNode>{
    Byte data;
    int frequency;
    ByteNode left;
    ByteNode right;

    public ByteNode(Byte data, int weight)
    {
        this.data=data;
        this.frequency=weight;
    }
    public int compareTo(ByteNode o)
    {
        /*int frequencyCompare = Integer.compare(this.frequency,o.frequency);
        if(frequencyCompare != 0)
            return frequencyCompare;
        return 0;*/
        return this.frequency - o.frequency;
    }
}
