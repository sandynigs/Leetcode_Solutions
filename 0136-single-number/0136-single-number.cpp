//XOR with 0 gives smae number, and xor of same numbers gives 0
// 0^2 = 2 and 2^2=0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};