class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while (s<=e){
            int mid = s + (e - s)/2;
            for (int i=0; i<n; i++){
                if(target == nums[mid]){
                    return mid;
                }
                else {
                    if(target<nums[mid]){
                        e = mid - 1;
                    }
                    else{
                        s = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};