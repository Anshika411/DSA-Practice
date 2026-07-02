class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        vector<int> freq(maxi-mini+1, 0);
        for(auto &num: nums){
            freq[num - mini] ++; 
        }

        int idx = 0;
        for(int num=0; num<freq.size(); num++){
            while(freq[num] > 0){
                nums[idx] = num + mini;
                freq[num] --;
                idx ++;
            }
        }
        return nums;
    }
};