class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (balance > 0)
                    result += ch;   
                balance++;
            } else { 
                balance--;
                if (balance > 0)
                    result += ch;   
            }
        }
        return result;
    }
};