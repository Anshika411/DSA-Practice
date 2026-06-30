class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxpos = 0;
        int n = nums.size();
        for (int i = 0; i<n-1; i++){
            if(i>mxpos){
                return false;
            }     
            mxpos = max(i + nums[i],mxpos); 
        }
        if(mxpos >= n-1){
            return true;
        }else {
            return false;
        }
        return true;
    }
};