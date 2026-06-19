class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>arr(n+1);
        int j = 1;
        arr[0] = 0;
        for (int i = 0; i<gain.size(); i++){
            arr[j] = arr[j-1] + gain[i];
            j++;
        }
        return *max_element(arr.begin(),arr.end());
    }
};