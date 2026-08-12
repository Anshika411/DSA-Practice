class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int range = 0;
        int left = 0;
        for(int right = 0; right<n; right++){
            freq[nums[right]]++;
            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
            range = max(range,right - left + 1);
        }
        return range;
    }
};