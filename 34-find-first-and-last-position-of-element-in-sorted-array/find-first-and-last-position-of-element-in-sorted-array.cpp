class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, second = -1;
        int s = 0, e = n - 1;
        while (s<=e) {
            int mid = s + (e - s)/2;
            if (target == nums[mid]) {
                first = mid;
                e = mid - 1;
            } else {
                if(target < nums[mid]){
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
        }
        s = 0;
        e = n - 1;
        while (s<=e) {
            int mid = s + (e - s)/2;
            if (target == nums[mid]) {
                second = mid;
                s = mid + 1;
            } else {
                if(target < nums[mid]){
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
        }
    
        return {first, second};
    }
};