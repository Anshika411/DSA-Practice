class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=1;
        vector<int> last_interval=intervals[0];
        while(i<n){
            int curr_end=intervals[i][1];
            int curr_start=intervals[i][0];
            int last_end=last_interval[1];
            if(curr_start>= last_end){
                last_interval=intervals[i];
            }
            else if(curr_end>=last_end){
                count++;
            }
            else if(curr_end<last_end){
                count++;
                last_interval=intervals[i];
            }
            i++;
        }
        return count;       
    }
};