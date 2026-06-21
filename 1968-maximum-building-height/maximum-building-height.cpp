#include <vector>
#include <algorithm>

class Solution {
public:
    int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
        // Add boundary restrictions
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        // Sort restrictions by building ID
        std::sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Left-to-right pass to propagate height limits forward
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = std::min(restrictions[i][1], 
                                          restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }
        
        // Right-to-left pass to propagate height limits backward
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = std::min(restrictions[i][1], 
                                          restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        
        int max_height = 0;
        
        // Find the peak height between every two adjacent restrictions
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i-1][0];
            int h1 = restrictions[i-1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            
            // Calculate the maximum possible height between these two buildings
            int peak_height = h1 + (id2 - id1 + h2 - h1) / 2;
            max_height = std::max(max_height, peak_height);
        }
        
        return max_height;
    }
};