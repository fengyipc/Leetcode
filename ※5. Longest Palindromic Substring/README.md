## 5. Longest Palindromic Substring

### Description: 
>Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

>Difficulty:    Medium

### Example 1:  
>**Input**: "babad",  
**Output**: "bab",  
**Note**: "aba" is also a valid answer.  

### Example 2:  
>**Input**: "cbbd",  
**Output**: "bb"  

### Submission:

**Version 1 :** Dynamic Programming
```C++
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int> > dp(2, vector<int>(s.size() + 10));
        int n = (int)s.size() - 1;
        dp[0][n] = 1;
        int mxi = n, mxj = n;
        bool last = 0;
    
        for(int i = (int)s.size() - 2; i >= 0 ; --i) {
            last = !last;
            for(int j = i; j < s.size(); ++j) {
                if(i == j) dp[last][j] = 1; 
                else if(j - i == 1) dp[last][j] = ((s[i] == s[j]) ? 1 : 0);
                else dp[last][j] = ((s[i] == s[j] && dp[!last][j - 1] == 1) ? 1  : 0);   
                if(dp[last][j] == 1) {if(j - i > mxj - mxi) {mxj = j; mxi = i;}}
            }
        }
        return s.substr(mxi, mxj - mxi + 1);
};
```

**Version 2 :** Expand Around Center
```C++
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0,maxLen=1,len=s.size();
        if(len<2) return s;
        for(int i=0;i<len;){
            if(len-i<=maxLen/2) break;
            int j=i,k=i;
            while(k<len-1&&s[k]==s[k+1]) k++;
            i=k+1;
            while(j>0&&k<len-1&&s[j-1]==s[k+1]){
                j--;
                k++;
            }
            int newLen=k-j+1;
            if(newLen>maxLen){
                maxLen=newLen;
                start=j;
            }
        }   
        return s.substr(start,maxLen);
    }
};
```
