/* Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 * You should pack your words in a greedy approach; 
 * that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * Extra spaces between words should be distributed as evenly as possible. 
 * If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 */
class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<string> result;  
            if (0 == words.size()) return result;      
            int i = 0;  
            while (i < words.size()) {  
                int start = i, sum = 0;  
                while (sum <= L && i < words.size()) {  
                    sum += words[i].size() + 1;  
                    i++;  
                }  
                if (sum - 1 > L)  {  
                    i--;  
                    sum -= words[i].size() + 1;          
                }  
                bool isLastLine = false;  
                if (i == words.size())  
                    isLastLine = true;  
                int end = i - 1;    
                int intervalCount = end - start;  
                int avgSp = 0, leftSp = 0;  
                if (intervalCount > 0) {  
                    avgSp = (L - sum + intervalCount + 1) / intervalCount;  
                    leftSp = (L - sum + intervalCount + 1) % intervalCount;  
                }        
                string line;        
                for (int j = start; j < end; ++j) {  
                    line += words[j];  
                    if (isLastLine)  
                        line.append(1, ' ');  
                    else {  
                        line.append(avgSp, ' ');  
                        if (leftSp > 0) {  
                            line.append(1, ' ');  
                            leftSp--;  
                        }  
                    }  
                }  
                line += words[end];  
                if (line.size() < L)  
                    line.append(L-line.size(), ' ');  
                result.push_back(line);        
            }  
            return result;  
        }
};
