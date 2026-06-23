class Solution {
public:
    long long mod = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long result = 1;
        base = base % mod;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            exp = exp / 2;
            base = (base * base) % mod;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;
        
        long long total_even_choices = power(5, even_pos);
        long long total_odd_choices = power(4, odd_pos);
        
        return (total_even_choices * total_odd_choices) % mod;
    }
};