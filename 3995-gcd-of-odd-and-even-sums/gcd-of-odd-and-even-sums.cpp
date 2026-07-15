class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);
        // gcd(n*n,n*n + n)= n (we can simply return n too)
        return gcd(sumOdd,sumEven);
    }
};