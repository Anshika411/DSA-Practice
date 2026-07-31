class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n = nums.size();
        int max_right = -1;
        for(int i = n-1; i>=0; i--){
            swap(nums[i], max_right);
            max_right = max(nums[i],max_right);
        }
        return nums;
    }
};