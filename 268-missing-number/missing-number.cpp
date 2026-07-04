class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[j] == i) {
                j++;
            } else {
                return i;
            }
        }

        return n;
    }
};