#include<unordered_map>
#include<vector>
#include<climits>
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, vector<int>> hm;
        for(int i=0;i<s.size();i++){
            hm[s[i]].push_back(i);
        }
        unordered_map<char, int> m;
        for(auto i:hm){
            if(i.second.size()!=1){
                m[i.first]=i.second[1];                
            }
        }
        int lg=INT_MAX;
        char ans;
        for(auto i:m){
            if(i.second < lg){
                lg=i.second;
                ans=i.first;
            }
        }
        return ans;
        
    }
};