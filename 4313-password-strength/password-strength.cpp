class Solution {
public:
    int passwordStrength(string password) {
        int n = password.length();
        unordered_set<char>set;
        for( char ch:password) {
            set.insert(ch);
        }
        int cnt = 0;
        for(char ch:set) {
            if(ch>='a' && ch<='z') {
                cnt+=1;
            } else if(ch>='A' && ch<='Z') {
                cnt+=2;
            } else if (ch>='0' && ch<='9') {
                cnt+=3;
            }else{
                cnt+=5;
            }
        }
        
        return cnt;
    }
};