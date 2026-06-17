class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;

        // Step 1: Find NGE for nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Step 2: Build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nge[x]);
        }

        return ans;
    }
};