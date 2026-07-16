class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto it:mp) {
            if(it.second ==1) {
                return it.first;
            }
        }
        return -1;
    }
};