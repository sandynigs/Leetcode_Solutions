#include<stack>
#include<unordered_map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s; //to keep track of elements
        unordered_map<int,int> um; //to store indexes of elements in nums1
        int n = nums2.size();
        for(int i=0;i<n;i++){
            um[nums2[i]]=i;
        }
        
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=-1;
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums2[i]>=s.top()){
                s.pop();
            }
            if(s.empty()){
                s.push(nums2[i]);
            }
            else{
                arr[i]=s.top();
                s.push(nums2[i]);
            }
        }
        vector<int> b;
        for(int i=0;i<nums1.size();i++){
            b.push_back(arr[um[nums1[i]]]);
        }
        return b;
        
    }
};