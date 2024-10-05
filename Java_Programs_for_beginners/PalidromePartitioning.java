package Java_Programs_for_beginners;

import java.util.*;

/*Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:1 <= s.length <= 16
s contains only lowercase English letters.*/
public class PalidromePartitioning {
    public static void main(String[] args) {Solution solution = new Solution();
        String s = "aab";
        List<List<String>> partitions = solution.partition(s);
        System.out.println(partitions);
    }
}
class Solution {
    List<List<String>> ans;
    public List<List<String>> partition(String s) {
        ans = new ArrayList<>();
        helper(s, new ArrayList<>());
        return ans;
    }

    public void helper(String s, List<String> currentPartitions){
        if(s.isEmpty()){
            ans.add(new ArrayList<>(currentPartitions));
            return;
        }
        for(int partition = 1; partition <= s.length(); partition++){
            String prefix = s.substring(0, partition);
            String remaining = s.substring(partition);
            if(isPalindrome(prefix)){
                currentPartitions.add(prefix);
                helper(remaining, currentPartitions);
                currentPartitions.remove(currentPartitions.size() - 1);
            }
        }
    }

    public boolean isPalindrome(String s){
        int l = 0, r = s.length() - 1;
        while(l < r){
            if(s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
}