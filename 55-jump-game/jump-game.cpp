class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxpos = 0;
        for(int i = 0; i<n; i++) {
            if(i>maxpos){
                return false;
            }
            maxpos = max(maxpos, i + nums[i]);
        }
        if(maxpos<n-1){
            return false;
        }
        return true;
    }
};