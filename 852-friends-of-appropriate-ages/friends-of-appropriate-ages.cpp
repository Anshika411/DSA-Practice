class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());

        int n = ages.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = ages[i];

            int low = upper_bound(ages.begin(), ages.end(), x / 2 + 7) - ages.begin();
            int high = upper_bound(ages.begin(), ages.end(), x) - ages.begin();
            int cnt = high - low - 1;

            if (cnt > 0) {
                ans += cnt;
            }
        }

        return ans;
    }
};