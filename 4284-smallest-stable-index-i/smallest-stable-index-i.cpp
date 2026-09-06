class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int high = *max_element(nums.begin(), nums.begin() + i);
            int low = *min_element(nums.begin() + i, nums.end());
            int score = high - low;
            if (score <= k)
                return i;
        }
        return -1;
    }
};