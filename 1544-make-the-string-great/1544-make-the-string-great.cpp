#include<cstdlib>
class Solution {
public:
    string makeGood(string s) {
        stack<char> v;
        v.push(s[s.size()-1]);
        for(int i=s.size()-2;i>=0;i--){
            if(v.size()!=0 &&  abs(int(s[i]) - int(v.top()))==32 ){
                v.pop();
                continue;
            }
            else{
                v.push(s[i]);
            }
        }
        string ans="";
        while(v.size()!=0){
            ans+=v.top();
            v.pop();
        }
        return ans;        
    }
};