class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map <char,int> mp;
        for (char c: text) {
            mp[c]++;
        }
        int minBalloons = mp['b'];
        minBalloons = min(minBalloons, mp['a']);
        minBalloons = min(minBalloons, mp['l'] / 2);
        minBalloons = min(minBalloons, mp['o'] / 2);
        minBalloons = min(minBalloons, mp['n']);
        
        return minBalloons;
    }
};