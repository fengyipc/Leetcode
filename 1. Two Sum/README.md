## 1. Two Sum

### Description: 
>Given an array of integers, return indices of the two numbers such that they add up to a specific target.  
You may assume that each input would have exactly one solution, and you may not use the same element twice.  

>Difficulty:    Easy

### Example:  
>Given nums = **[2, 7, 11, 15]**, target = **9**,  
Because nums[0] + nums[1] = 2 + 7 = 9,    
return **[0, 1]**.

### Submission:

Version 1 : python3 5512 ms 13.9 MB
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)-1):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
```
Version 2 : python3 784 ms	13.9 MB
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            if target - nums[i] in nums and nums.index(target - nums[i]) != i:
                return [i, nums.index(target - nums[i])]
```              
Version 3 : python3 28 ms	14.6 MB (Solution, not my Submission)
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in d:
                return [d[m], i]
            else:
                d[n] = i
```
