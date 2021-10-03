// LANGUAGE: Javas //Getter Setter
// ENV: Java 8 
// AUTHOR: Noopur Agarwal
// GITHUB: https://github.com/noopurAg

import java.util.*;

class FirstUniqueCharForString {
    public int firstUniqChar(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (map.containsKey(c))
                map.put(c, map.get(c) + 1);
            else
                map.put(c, 1);
        }
        for (int i = 0; i < s.length(); i++) {
            if (map.get(s.charAt(i)) == 1)
                return i;
        }
        return -1;
    }

    public static void main(String args[]) {

        FirstUniqueCharForString fchar = new FirstUniqueCharForString();
        String msg = "hachtoberfest-hack";
        int indexofChar = fchar.firstUniqChar(msg);
        System.out.println("First uniq character is ----> '" + msg.charAt(indexofChar) + "' loacated at " + indexofChar);
    }
}
