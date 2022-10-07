
public class LongestCommonPrefix{

	public String lcp(String[] strs) {
        StringBuffer com = new StringBuffer();
        int n = strs.length;
        if(n == 0)
            return "";
        if(n == 1)
            return strs[0];
        String first = strs[0];
        
        for(int i = 1; i < n; i++)
        {
            int len1 = first.length();
            int len2 = strs[i].length();
            com = new StringBuffer();
            for(int j = 0; j < Math.min(len1, len2); j++)
            {
                if(first.charAt(j) == strs[i].charAt(j))
                {
                    com.append(first.charAt(j));
                }
                else
                {
                    break;
                }
            }
            first = com.toString();
        }
        return com.toString();
    }
}