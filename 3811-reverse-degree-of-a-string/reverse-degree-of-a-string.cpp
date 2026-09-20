class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            int value = 27 - (s[i] - 'a' + 1);
            res += value * (i + 1);
        }

        return res;
    }
};