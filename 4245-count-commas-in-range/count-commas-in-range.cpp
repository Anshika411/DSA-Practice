class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        if(n<1000){
            return 0;
        } else {
            cnt+= (n-999);
        }
        return cnt;
    }
};