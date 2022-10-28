#include<stack>
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')'){
                ans.push(s[i]);
            }
            else{
                string str2="";
                while(ans.top()!='('){
                    str2+=ans.top();
                    ans.pop();
                }
                ans.pop();
                // cout<<"str2 is:"<<str2<<endl;
                for(int j=0;j<str2.size();j++){
                    ans.push(str2[j]);
                }
            }
        }
        string temp="";
        while(!ans.empty()){
            temp+=ans.top();
            ans.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};