## 3. Longest Substring Without Repeating Characters

### Description: 
>Given a string, find the length of the **longest substring** without repeating characters.

>Difficulty:  Medium

### Example:  
>Input: "abcabcbb"  
Output: 3  
Explanation: The answer is "abc", with the length of 3.

### Submission:

**Version 1 :** python3 1900 ms 13.2 MB
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        l = []
        result = 0
        while i < len(s):
            for j in range(i,len(s)):
                b = s[j]
                if b not in l:
                    l.append(b)
                    if j == len(s)-1:
                        i += l.index(b) + 1
                        result = max(result, len(l))
                        l = []
                else:
                    i += l.index(b) + 1
                    result = max(result, len(l))
                    l = []
                    break
        return result
```
**Version 2 :** python3 780 ms  13.3 MB
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        i = 0
        while i < len(s):
            for j, x in enumerate(s[i:]):
                if x in s[i:j+i]:
                    result = max(result, j)
                    i += s[i:j+i].index(x) + 1
                    break
                if i + j == len(s)-1:
                    result = max(result, j+1)
                    i = len(s)
        return result
```              
**Version 3 :** python3 76 ms	13.3 MB
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        result = 0
        if len(s) is 1:
            result = 1
        for i in range(len(s) - 1):
            head = s[start:i + 1]
            if s[i + 1] in head:
                start += head.index(s[i + 1]) + 1
            else:
                head += s[i+1]
            result = max(result, len(head))
        return result
```

减少循环层数，比抠细节优先级更高
