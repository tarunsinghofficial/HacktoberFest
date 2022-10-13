class Solution:         # Three line segments comprise a triangle if and only if the
                        # greatest length of the three sides is less than the sum of
                        #lengths of the other two sides. (A few sketches or playing
                        # with three sticks should convince you of this fact.)
                        # 
                        # Here's the Plan:
                        #   • Sort nums in non-decreasing order.
                        #
                        #   • Iterate though the list and pop off the first element until
                        #     nums[0] < nums[1]+nums[2]. The sum of these three nums is the
                        #     solution.
                        # 
                        #   •If no such three numbers exist, then return 0
                    
    def largestPerimeter(self, nums: list[int]) -> int:
        
        nums.sort(reverse = True)
        
        while len(nums) > 2 and nums[0] >= nums[1] + nums[2]:
            nums.pop(0)
            
        return 0 if len(nums) < 3 else sum(nums[:3])