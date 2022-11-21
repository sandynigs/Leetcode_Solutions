#include<climits>
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0]=0;
        
        int mncoin=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<mncoin){
                mncoin=coins[i];
            }
        }
        
        
        for(int i=1;i<=amount;i++){
            if(i-mncoin<0){
                dp[i]=-1;
            }
            else{
                int sol=INT_MAX;
                bool found=false;
                for(int j=0;j<coins.size();j++){
                    if(i-coins[j]>=0){
                        if(dp[i-coins[j]]!=-1 && dp[i-coins[j]]<sol){
                            if(!found){found=true;}
                            sol=dp[i-coins[j]];
                        }
                    }
                }
                dp[i] = (found)?(sol+1):(-1);
            }
        }
        return dp[amount];
    }
};