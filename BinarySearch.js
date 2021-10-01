/**
 * Binary Search
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const search = (nums, target) => {
  return helper(nums, target, 0, nums.length - 1);
};

/**
 * Helper Function
 * @param {number[]} nums
 * @param {number} target
 * @param {number} left - anchor or start
 * @param {number} right - end
 */
const helper = (nums, target, left, right) => {
  if (left > right) return -1;

  const mid = Math.floor((left + right) / 2);
  const check = nums[mid];

  return {
    [true]: () => helper(nums, target, mid + 1, right),
    [check === target]: () => mid,
    [check > target]: () => helper(nums, target, left, mid - 1)
  }.true();
};
