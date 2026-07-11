class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int pos=0;
        for(int j = 0; j<n; j++){
            if(j>pos) {
            return false;
            }
            pos = max(pos, j+nums[j]);
        }
        return true;
    }
};