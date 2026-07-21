class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();  // no. of people
        int m = accounts[0].size();
        int sum = 0;
        int maxsum = INT_MIN;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                sum+=accounts[i][j];   
            }
            maxsum = max(maxsum,sum);
            sum = 0;
        }

        return maxsum;
    }
};