public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        String start = strs[0];
        for (int i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(start) != 0) {
                start = start.substring(0, start.length()-1);
            }
        }
        return start;
    }

    public static void main(String[] args) {
        String strs[] = {"flower","flow","flight"}
        this.longestCommonPrefix(strs)
    }
}