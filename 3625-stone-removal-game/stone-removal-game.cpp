class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10 || n>18 && n<27 || n>33 && n<40 || n>44 && n<49 || n>50) {
            return false;
        } 
        return true;
    }
};