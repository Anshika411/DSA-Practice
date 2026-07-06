class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string s;
        int i = 0;
        int j = 0;

        for (; i < n && j < m; i++, j++) {
            s.push_back(word1[i]);
            s.push_back(word2[j]);
        }

        if (i <= n - 1) {
            for (int k = i; k < n; k++) {
                s.push_back(word1[k]);
            }
        } else if (j <= m - 1) {
            for (int k = j; k < m; k++) {
                s.push_back(word2[k]);
            }
        } else {
            return s;
        }
        return s;
    }
};