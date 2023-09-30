int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1); // Initialize with -1 to handle edge cases
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxLength = max(maxLength, i - stk.top());
            }
        }
    }

    return maxLength;
}
