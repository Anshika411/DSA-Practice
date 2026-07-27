class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = n-2;
        int j = n-1;
        return (nums[i]-1)*(nums[j]-1);
        
    }
};