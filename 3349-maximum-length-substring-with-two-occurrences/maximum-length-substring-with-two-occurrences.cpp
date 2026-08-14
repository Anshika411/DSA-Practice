class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        
        int left = 0;
        int right = 0;
        int ans = 0;

        for (char c : s) {
            mp[c]++;

            while (mp[c] > 2) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};