#include<vector>
#include<algorithm>
class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while(num>0){
            int s=num%10;
            v.push_back(s);
            num=num/10;
        }
        sort(v.begin(), v.end());
        return(v[0]*10+v[2] +  v[1]*10+v[3]);
    }
};