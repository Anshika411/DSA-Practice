class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int totalJumps = 0;
        int end = n-1;
        int lastJump = 0;
        int curr = 0;
        if(n == 1){
            return 0;
        }
        for(int i = 0; i<n; i++){
            curr = max(curr, i+nums[i]);
            if(i == lastJump){
                lastJump = curr;
                totalJumps++;

                if(curr>=end){
                    return totalJumps;
                }    
            }
        }
        return totalJumps;
    }
};