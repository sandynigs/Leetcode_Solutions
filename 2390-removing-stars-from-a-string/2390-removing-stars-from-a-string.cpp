#include<stack>
class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char> temp;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                temp.push(s[i]);
            }
            else{
                temp.pop();
            }
        }
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
            
    }
};