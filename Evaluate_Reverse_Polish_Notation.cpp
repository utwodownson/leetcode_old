/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<int> num;
            for (int i = 0; i < tokens.size(); ++i) {
                char tmp = tokens[i][0];

                if (tokens[i].length() != 1 || '0' <= tmp && tmp <= '9') 
                    num.push(atoi(tokens[i].c_str()));
                else {
                    int a = num.top(); num.pop();
                    int b = num.top(); num.pop();
                    int c = 0;
                    if (tmp == '+') c = a + b; 
                    else if (tmp == '-') c = b - a;
                    else if (tmp == '*') c = a * b;
                    else c = b / a;
                    num.push(c);
                }
            }
            return num.top();
        }
};

