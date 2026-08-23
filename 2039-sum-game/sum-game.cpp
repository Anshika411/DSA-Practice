class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int cnt = 0;
        int left = 0, right = 0;

        for (char c : num) {
            if (c == '?') cnt++;
        }

        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?')
                left += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] != '?')
                right += num[i] - '0';
        }

        if (cnt % 2 != 0) {
            return true;
        } else {
            int diff = left - right;
            int qLeft = 0, qRight = 0;

            for (int i = 0; i < n / 2; i++)
                if (num[i] == '?') qLeft++;

            for (int i = n / 2; i < n; i++)
                if (num[i] == '?') qRight++;

            if (diff + (qLeft - qRight) * 9 / 2 != 0)
                return true;
        }

        return false;
    }
};