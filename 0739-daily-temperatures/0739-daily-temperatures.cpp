#include<stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> t; //to store indexes of temperatures
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!t.empty() && temperatures[i]>=temperatures[t.top()]){
                //find day bigger than temperatures[i] in the stack
                t.pop();
            }
            if(t.empty()){
                t.push(i);
                ans[i]=0;
            }
            else if(temperatures[i]<temperatures[t.top()]){
                ans[i]=t.top()-i;
                t.push(i);
            }
        }
        return ans;
    }
};