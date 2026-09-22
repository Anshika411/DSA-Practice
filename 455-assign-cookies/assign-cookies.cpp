class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int cnt = 0;
        int j = 0;
        for(int i = 0; i<g.size() && j<s.size(); j++){
            if(s[j]>=g[i]){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};