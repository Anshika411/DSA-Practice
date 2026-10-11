class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int sum = 0;
        for (int i = 1; i <=n; i++) {
            if (n % i == 0) {
                ans.push_back(nums[i-1]);
            }
        }
        for(int i :ans){
            sum+= i*i;
        }
        return sum;
    }
};