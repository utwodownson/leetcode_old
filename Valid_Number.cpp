/* Validate if a given string is numeric.
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */
class Solution {
    public:
        bool isNumber(const char *s) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            bool num = false, point = false, exp = false;

            while (*s && isspace(*s)) s++;
            if (*s == '+' || *s == '-') s++;

            while (*s && !isspace(*s)) {
                if (isdigit(*s)) {
                    num = true;
                } else if (*s == '.') {
                    if (point || exp) return false;
                    point = true;
                } else if (toupper(*s) == 'E') {
                    if (exp || !num) return false;
                    exp = true;
                    num = false;
                } else if (*s == '+' || *s == '-') {
                    if (toupper(s[-1]) != 'E') return false;
                } else {
                    return false;
                }
                s++;
            }
            while (*s && isspace(*s)) s++;

            return *s == 0 && num;
        }   
};

