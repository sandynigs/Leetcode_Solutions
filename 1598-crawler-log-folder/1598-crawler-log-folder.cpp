class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(c!=0){
                    c-=1;
                }
                else{
                    continue;
                }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                c+=1;
            }
        }
        return c;
    }
};