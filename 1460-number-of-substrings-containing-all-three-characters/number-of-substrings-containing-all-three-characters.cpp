class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        vector<int> last_seen = {-1, -1, -1}; 
        
        for (int i = 0; i < s.size(); i++) {
            last_seen[s[i] - 'a'] = i; 
            
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                int min_idx = min({last_seen[0], last_seen[1], last_seen[2]});
                cnt += (min_idx + 1);
            }
        }
        
        return cnt;
    }
};