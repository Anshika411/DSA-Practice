class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort (g.begin(),g.end());
        sort (s.begin(),s.end());
        int cnt = 0;
        int i = 0;
        for (int j = 0; j < s.size() && i < g.size(); j++) {
            if(s[j] >= g[i]) {
                cnt++;
                i++;
            } 
        }
        return cnt;    
    }
};