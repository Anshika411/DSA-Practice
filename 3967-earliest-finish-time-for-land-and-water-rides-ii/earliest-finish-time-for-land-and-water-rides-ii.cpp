#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                                 vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        return min(calculate(landStartTime, landDuration, waterStartTime, waterDuration),
                   calculate(waterStartTime, waterDuration, landStartTime, landDuration));
    }

private:
    long long calculate(const vector<int>& start1, const vector<int>& dur1, 
                        const vector<int>& start2, const vector<int>& dur2) {
        
        // Find the earliest possible finish time for ANY ride in the first category
        long long minEnd1 = LLONG_MAX;
        for (size_t i = 0; i < start1.size(); ++i) {
            minEnd1 = min(minEnd1, (long long)start1[i] + dur1[i]);
        }
        
        // Use that minimum finish time to find the earliest completion of a second ride
        long long minTotalFinish = LLONG_MAX;
        for (size_t j = 0; j < start2.size(); ++j) {
            // Can start second ride at either its own opening time or after first ride ends
            long long startActual = max((long long)start2[j], minEnd1);
            minTotalFinish = min(minTotalFinish, startActual + dur2[j]);
        }
        
        return minTotalFinish;
    }
};