class Solution {
public:
    char processStr(string s, long long k) {
        long long m = 0;

        for(char c : s) {
            if(c == '*') {
                m = max(0LL, m - 1);
            }
            else if(c == '#') {
                m *= 2;
            }
            else if(c == '%') {
                continue;
            }
            else {
                m++;
            }
        }

        if(k >= m) return '.';

        for(int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if(c == '*') {
                m++;
            }
            else if(c == '#') {
                m /= 2;

                if(k >= m)
                    k -= m;
            }
            else if(c == '%') {
                k = m - 1 - k;
            }
            else {
                m--;

                if(k == m)
                    return c;
            }
        }

        return '.';
    }
};