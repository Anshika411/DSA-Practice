class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;
        
        for (int i : nums) {
            int temp = curMax * i;
            curMax = max({temp, curMin * i, i});
            curMin = min({temp, curMin * i, i});
            res = max(res, curMax);
        }
        
        return res;
    }
};