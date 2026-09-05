class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> sufMin(n);
        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufMin[i] = min(sufMin[i + 1], nums[i]);
        }
        
        int prefMax = 0;
        
        // Iterate through each index to find the first stable index
        for (int i = 0; i < n; ++i) {
            prefMax = max(prefMax, nums[i]);
            
            // Instability score = max(nums[0..i]) - min(nums[i..n-1])
            if (prefMax - sufMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};