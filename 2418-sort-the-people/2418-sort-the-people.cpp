#include<unordered_map>
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> hm;
        for(int i=0;i<heights.size();i++){
            hm[heights[i]]=names[i];
        }
        //sort in decreasing order
        sort(heights.begin(), heights.end(),greater<int>());
        vector<string> ans;
        for(int i=0;i<heights.size();i++){
            ans.push_back(hm[heights[i]]);
        }
        return ans;
    }
};