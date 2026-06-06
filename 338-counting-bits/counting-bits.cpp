class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums(n + 1);

        for (int i = 0; i <= n; i++) {
            int temp = i;
            int cnt = 0;

            while (temp != 0) {
                temp = temp & (temp - 1);
                cnt++;
            }

            nums[i] = cnt;
        }

        return nums;
    }
};