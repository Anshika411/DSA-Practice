class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(int i = 1; i <= n + 1; i++){
            if(!st.count(k * i)){
                return k * i;
            }
        }

        return -1;
    }
};