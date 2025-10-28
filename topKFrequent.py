from collections import Counter
class Solution:
def topKFrequent(self, nums: List[int], k: int) List[int]:
c Counter(nums)
min_heap = []
for num, freq in c.items():
heappush(min heap, (freq, num))
if len(min_heap) > k:
heappop(min_heap)
return [item[1] for item in min_heap]
