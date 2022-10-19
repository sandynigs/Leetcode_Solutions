class Solution {
public:
    string smallestNumber(string pattern) {
        //create general string first increasing.
        int l = pattern.size();
        string ans="";
        for(int i=1;i<l+2;i++){
            ans+=to_string(i);
        }
        for(int i=0;i<l;i++){
            if(pattern[i]=='D'){
                int j=i+1;
                while(pattern[j]!='\0' && pattern[j]!='I'){
                    j+=1;
                }
                // cout<<"i is:"<<i<<"and  j is:"<<j<<endl;
                reverse(ans.begin()+i, ans.begin()+j+1);
                // int t1=i;
                // int t2=j;
                // while(t1<t2){
                //     string x = ans[i];
                //     ans[i]=ans[j];
                //     ans[j]=x;
                //     t1++;
                //     t2--;
                // }
                i=j;
            }
        }
        return ans;
    }
};