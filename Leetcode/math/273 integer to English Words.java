/*
Convert a non-negative integer num to its English words representation.

Example 1:
Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:
Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

Constraints:
0 <= num <= 231 - 1
*/

class Solution {
     public String appendReq(int i) {
        if (i == 3) return " Billion";
        else if (i == 2) return " Million";
        else if (i == 1) return " Thousand";
        else return "";
    }
    public String toWordsHelper(String temp, HashMap < Integer, String > hm, int i) {
        StringBuilder res = new StringBuilder();
        if (Integer.parseInt(temp) == 0)
            return res.toString();
        if (temp.length() == 3) {
            int first = Integer.parseInt(temp.substring(0, 1));
            if (first != 0)
            {
                res.append(hm.get(first));
                res.append(" Hundred");
            }
            temp = temp.substring(1);
        }
        if (temp.length() == 2) {
            int second = Integer.parseInt(temp);
            if (second != 0) {
                if (second <= 19) {
                    if (res.length() > 0)
                        res.append(" ");
                    res.append(hm.get(second));

                    res.append(appendReq(i));
                    return res.toString();
                } else {
                    if (res.length() > 0)
                        res.append(" ");
                    res.append(hm.get(Integer.parseInt((temp.substring(0, 1)) + "0")));
                }
            }
            temp = temp.substring(1);
        }
        if (temp.length() == 1) {
            if (Integer.parseInt(temp) != 0) {
                if (res.length() > 0)
                    res.append(" ");
                res.append(hm.get(Integer.parseInt(temp)));
            }
        }

        res.append(appendReq(i));
        return res.toString();
    }
     public void putstring(HashMap < Integer, String > hm) {
        hm.put(0, "Zero");
        hm.put(1, "One");
        hm.put(2, "Two");
        hm.put(3, "Three");
        hm.put(4, "Four");
        hm.put(5, "Five");
        hm.put(6, "Six");
        hm.put(7, "Seven");
        hm.put(8, "Eight");
        hm.put(9, "Nine");
        hm.put(10, "Ten");
        hm.put(11, "Eleven");
        hm.put(12, "Twelve");
        hm.put(13, "Thirteen");
        hm.put(14, "Fourteen");
        hm.put(15, "Fifteen");
        hm.put(16, "Sixteen");
        hm.put(17, "Seventeen");
        hm.put(18, "Eighteen");
        hm.put(19, "Nineteen");
        hm.put(20, "Twenty");
        hm.put(30, "Thirty");
        hm.put(40, "Forty");
        hm.put(50, "Fifty");
        hm.put(60, "Sixty");
        hm.put(70, "Seventy");
        hm.put(80, "Eighty");
        hm.put(90, "Ninety");
    }
    public String numberToWords(int num) {
          if (num == 0)
            return "Zero";
        HashMap < Integer, String > hm = new HashMap < > ();
        putstring(hm);
        String s = String.valueOf(num);
        ArrayList < String > str = new ArrayList < String > ();
        while (s.length() > 3) {
            str.add(s.substring(s.length() - 3));
            s = s.substring(0, s.length() - 3);
        }
        str.add(s);
        int n = str.size();
        StringBuilder ans = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            String txt = toWordsHelper(str.get(i), hm, i);
            ans.append(txt);
            if (i != 0 && txt.length() != 0)
                ans.append(" ");
        }
        return ans.toString().trim();
        
    }
}