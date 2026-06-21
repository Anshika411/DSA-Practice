class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int long long sum = 0,cnt = 0;
        sort(costs.begin(),costs.end());
        for (int i = 0; i < n; i++) {
            sum += costs[i];
            if (sum <= coins) {
                cnt++;
            }
        }
        return cnt;
    }
};