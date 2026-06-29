class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();       
        int cnt = 0;
        for (string pattern : patterns) {
            int len = pattern.size();

        for (int i = 0; i + len <= word.size(); i++) {
            if (pattern == word.substr(i, len)) {
                cnt++;
                break;
            }
        }
        }
        return cnt;
    }
};