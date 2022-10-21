// This question is based on DP+merge_interval
//Eg: [6,2,4] => [(6),(2,4)], [(6,2),(4)]
//Eg: [6,2,4,3] => [(6),(2,4,3)], [(6,2),(4,3)], [(6,2,4),(3)] each bracket of 3 can be solved from recursion
#include<climits>
class Solution {
public:
    int helper(vector<int>& arr, int **dp,int i, int j){
        if(i==j){
            dp[i][j]=0;
            return 0;
        }
        // cout<<"i and j are"<<i<<" "<<j<<endl;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int m1 = *max_element(arr.begin()+i, arr.begin()+k+1);
            int m2 = *max_element(arr.begin()+k+1, arr.begin()+j+1);
            int s1 = helper(arr, dp, i, k);
            int s2 = helper(arr, dp,k+1, j);
            int sol = m1*m2 + s1 + s2;
            if(sol<ans){
                ans=sol;
            }
        }
        dp[i][j]=ans;
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        int **dp;
        dp = new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        
        return helper(arr,dp,0,n-1);
    }
};