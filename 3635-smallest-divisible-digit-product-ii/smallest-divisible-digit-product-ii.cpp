#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    // Calculates minimum digit slots needed to satisfy c2 factors of 2 and c3 factors of 3
    int min_slots(int c2, int c3) {
        if (c2 <= 0 && c3 <= 0) return 0;
        int count8 = max(0, c2) / 3;
        int rem2 = max(0, c2) % 3;
        int count9 = max(0, c3) / 2;
        int rem3 = max(0, c3) % 2;
        
        int extra = 0;
        if (rem2 == 0 && rem3 == 0) extra = 0;
        else if (rem2 == 0 && rem3 == 1) extra = 1; // '3'
        else if (rem2 == 1 && rem3 == 0) extra = 1; // '2'
        else if (rem2 == 1 && rem3 == 1) extra = 1; // '6'
        else if (rem2 == 2 && rem3 == 0) extra = 1; // '4'
        else if (rem2 == 2 && rem3 == 1) extra = 2; // '2' + '6' (or '4' + '3')
        
        return count8 + count9 + extra;
    }

    // Constructs the lexicographically smallest suffix of length 'len'
    string build_suffix(int len, int c2, int c3, int c5, int c7) {
        string res = "";
        for (int k = 0; k < len; ++k) {
            int rem_len = len - 1 - k;
            for (int d = 1; d <= 9; ++d) {
                int nc2 = max(0, c2 - (d == 2 || d == 6 ? 1 : (d == 4 ? 2 : (d == 8 ? 3 : 0))));
                int nc3 = max(0, c3 - (d == 3 || d == 6 ? 1 : (d == 9 ? 2 : 0)));
                int nc5 = max(0, c5 - (d == 5 ? 1 : 0));
                int nc7 = max(0, c7 - (d == 7 ? 1 : 0));

                if (nc5 + nc7 + min_slots(nc2, nc3) <= rem_len) {
                    res += to_string(d);
                    c2 = nc2; c3 = nc3; c5 = nc5; c7 = nc7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp_t = t;
        int need2 = 0, need3 = 0, need5 = 0, need7 = 0;
        while (temp_t % 2 == 0) { need2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { need3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { need5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { need7++; temp_t /= 7; }

        if (temp_t > 1) return "-1"; // Prime factor > 7 cannot be formed by digits 1-9

        int n = num.length();

        // Factor counts for digits 1-9
        int d2[10] = {0}, d3[10] = {0}, d5[10] = {0}, d7[10] = {0};
        for (int i = 1; i <= 9; ++i) {
            int v = i;
            while (v % 2 == 0) { d2[i]++; v /= 2; }
            while (v % 3 == 0) { d3[i]++; v /= 3; }
            while (v % 5 == 0) { d5[i]++; v /= 5; }
            while (v % 7 == 0) { d7[i]++; v /= 7; }
        }

        // Prefix factor sums
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            int d = num[i] - '0';
            p2[i + 1] = p2[i] + d2[d];
            p3[i + 1] = p3[i] + d3[d];
            p5[i + 1] = p5[i] + d5[d];
            p7[i + 1] = p7[i] + d7[d];
        }

        // Check if num itself is valid
        if (first_zero == -1 && p2[n] >= need2 && p3[n] >= need3 && p5[n] >= need5 && p7[n] >= need7) {
            return num;
        }

        // Try placing a larger digit at position i
        int max_prefix = (first_zero == -1) ? n - 1 : first_zero;
        for (int i = max_prefix; i >= 0; --i) {
            int start_digit = num[i] - '0' + 1;
            for (int d = start_digit; d <= 9; ++d) {
                int rem2 = max(0, need2 - p2[i] - d2[d]);
                int rem3 = max(0, need3 - p3[i] - d3[d]);
                int rem5 = max(0, need5 - p5[i] - d5[d]);
                int rem7 = max(0, need7 - p7[i] - d7[d]);

                int rem_len = n - 1 - i;
                if (rem5 + rem7 + min_slots(rem2, rem3) <= rem_len) {
                    string pref = num.substr(0, i) + to_string(d);
                    string suff = build_suffix(rem_len, rem2, rem3, rem5, rem7);
                    return pref + suff;
                }
            }
        }

        // If no solution of length n works, extend string length
        int req_slots = need5 + need7 + min_slots(need2, need3);
        int target_len = max(n + 1, req_slots);
        return build_suffix(target_len, need2, need3, need5, need7);
    }
};