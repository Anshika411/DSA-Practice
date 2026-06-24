class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        double ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            nums.push_back(nums1[i]);
        }
        for (int j = 0; j < nums2.size(); j++) {
            nums.push_back(nums2[j]);
        }
        sort(nums.begin(), nums.end());
        if (nums.size()%2 == 1) {
            ans = nums[nums.size()/2.0];
        } else {
            ans = (nums[nums.size()/2.0] + nums[nums.size()/2.0 - 1.0])/2.0;
        }
        return ans;
    }
};