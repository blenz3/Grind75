class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        combinations = set()
        return [list(subset) for subset in self._generateSubsets(nums, [], combinations)]
        
        
    def _generateSubsets(self, nums, subset, allSubsets):
        if not nums:
            allSubsets.add(tuple(subset))
            return allSubsets
        
        # Add this number or don't 
        allSubsets = self._generateSubsets(nums[1:], subset, allSubsets)
        
        subset.append(nums[0])
        allSubsets = self._generateSubsets(nums[1:], subset, allSubsets) 
        subset.pop(-1)
        
        return allSubsets
        
        
