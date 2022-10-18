#include<stack>
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> v;
        v.push(s[s.size()-1]);
        for(int i=s.size()-2;i>=0;i--){
            if(v.size()!=0 && s[i]==v.top()){
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