class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int col1 = coordinate1[0] - 'a';
        int row1 = coordinate1[1] - '0';
        int col2 = coordinate2[0] - 'a';
        int row2 = coordinate2[1] - '0';
        if((col1 + row1)%2 == (col2 + row2)%2){
            return true;
        }
        return false;
    }
};