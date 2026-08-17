#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    int memo[501][501];
    int pref[501];

    int solve(int i, int j, const vector<int>& stoneValue) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        for (int k = i; k < j; ++k) {
            int leftSum = pref[k + 1] - pref[i];
            int rightSum = pref[j + 1] - pref[k + 1];

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k, stoneValue));
            } else if (rightSum < leftSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } else {
                maxScore = max(maxScore, leftSum + solve(i, k, stoneValue));
                maxScore = max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        for (int i = 0; i <= n; ++i) {
            pref[i] = 0;
            for (int j = 0; j <= n; ++j) {
                memo[i][j] = -1;
            }
        }

        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};