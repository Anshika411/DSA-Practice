class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        vector<int> nz_indices;
        vector<long long> prefSum;
        vector<long long> prefVal;
        
        prefSum.push_back(0);
        prefVal.push_back(0);
        
        // Precompute Prefix Sum and Prefix Concatenated Value
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') {
                nz_indices.push_back(i);
                int d = s[i] - '0';
                prefSum.push_back(prefSum.back() + d);
                prefVal.push_back((prefVal.back() * 10 + d) % MOD);
            }
        }
        
        // Precompute Powers of 10 mod (10^9 + 7)
        int k = nz_indices.size();
        vector<long long> p10(k + 1, 1);
        for (int i = 1; i <= k; ++i) {
            p10[i] = (p10[i - 1] * 10) % MOD;
        }
        
        vector<int> result;
        result.reserve(queries.size());
        
        // Process each query
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            // Find bounds of non-zero digits strictly inside [l, r]
            auto it_l = lower_bound(nz_indices.begin(), nz_indices.end(), l);
            auto it_r = upper_bound(nz_indices.begin(), nz_indices.end(), r);
            
            int L = distance(nz_indices.begin(), it_l);
            int R_next = distance(nz_indices.begin(), it_r);
            int R = R_next - 1;
            
            if (L > R) {
                // No non-zero digits in this range
                result.push_back(0);
            } else {
                int len = R - L + 1;
                
                // Value of the concatenated substring mod 10^9+7
                long long x = (prefVal[R + 1] - (prefVal[L] * p10[len]) % MOD + MOD) % MOD;
                
                // Sum of the substring digits
                long long sum = prefSum[R + 1] - prefSum[L];
                
                // Multiply and push to result
                long long ans = (x * sum) % MOD;
                result.push_back(ans);
            }
        }
        
        return result;
    }
};