class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n=len(nums)
        sm=((n)*(n+1))//2;
        for i in nums:
            if nums.count(i)>1:
                rep=i
                break
        ans=[]
        ans.append(rep)
        # print(sm)
        ans.append(rep+sm-sum(nums))
        return ans