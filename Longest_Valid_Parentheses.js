/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function (s) {
    let c = 0;
    let a = []
    a.push(-1)
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "(") {
            a.push(i)
        }
        else {
            if (a.length !== 0) {
                a.pop()

            }
            if (a.length !== 0) {
                c = Math.max(c, i - a[a.length - 1])
            }
            else {
                a.push(i)
            }
        }
    }
    return c
};