class Solution:
    def reverseWords(self, s: str) -> str:
        lis = s.split()
        ans=''
        size=len(lis)
        for i in range(0, size):
            lis[i] = lis[i][::-1]
            if i==(size-1):
                ans=ans+lis[i]
            else:
                ans=ans+lis[i]+' '
        return ans
        
            
        