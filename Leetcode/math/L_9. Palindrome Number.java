/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Follow up: Could you solve it without converting the integer to a string?

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:
Input: x = -101
Output: false

Constraints:
-231 <= x <= 231 - 1

Hint: Beware of overflow when you reverse the integer.
*/

class Solution {
    public boolean isPalindrome(int x) {
        String num = String.valueOf(x);
        for(int i=0,j=num.length()-1; i<j; i++,j--){
            if(num.charAt(i) != num.charAt(j)){
                return false;
            }
        }
        return true;
    }
}