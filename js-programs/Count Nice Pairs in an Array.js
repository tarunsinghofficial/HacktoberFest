/**
 * @param {number[]} nums
 * @return {number}
 */
var countNicePairs = function (nums) {
    let result = 0;
    for (let i = 0; i < nums.length; i++) {
        result += checks(nums.slice(i+1), nums[i])
    }
    return result;
};
const checks = (nums, value) => {
    let counter = 0;
    const revert = rev(value)
    if (nums.length === 0) {
        return 0
    }
    for (const elements of nums) {
        if (rev(elements) + value === revert + elements) {
            counter++
        }
    }
    return counter;
}
const rev = function (num) {
    let reverse = 0;
    let lastDigit;

    while (num !== 0) {
        lastDigit = num % 10;
        reverse = reverse * 10 + lastDigit;
        num = Math.floor(num / 10);
    }
    return reverse;
}
