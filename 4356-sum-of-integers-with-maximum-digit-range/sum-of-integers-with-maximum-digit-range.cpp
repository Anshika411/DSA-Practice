class Solution {
int helper(int num){
    int maxx = 0, minn = INT_MAX;
    while(num>0){
        maxx = max(maxx,num%10);
        minn =min(minn,num%10);
        num/=10;
    }
    return maxx-minn;
}
public:
    int maxDigitRange(vector<int>& nums) {
        int maxx = 0;
        for(int i:nums){
            maxx = max(helper(i),maxx);
        }
        int ans=0;
        for(int i:nums){
            if(helper(i)==maxx) 
                ans+=i;
        }
        return ans;
    }
};