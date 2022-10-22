#include<stack>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                s.pop();
            }
            else if(operations[i]=="D"){
                int temp=s.top();
                s.push(2*temp);
            }
            else if(operations[i]=="+"){
                int t1=s.top();
                s.pop();
                int t2=s.top();
                s.push(t1);
                s.push(t2+t1);
            }
            else{
                s.push(stoi(operations[i]));
            }     
        }
        int sm=0;
        while(s.size()!=0){
            int t = s.top();
            sm+=t;
            s.pop();
        }
        return sm;
    }
};