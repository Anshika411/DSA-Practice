class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int sum = 0;
        while(x>0){
            int rem = x%10;
            x /= 10;
            sum+=rem;
        }
        if(temp%sum==0){
            return sum;
        }

        return -1;
    }
};