/**
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
    static int cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
        vector<Interval> merge(vector<Interval> &intervals) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(intervals.begin(), intervals.end(), cmp);
            vector<Interval> merged;
            Interval cur;
            size_t i = 0; 
            while (i < intervals.size()) {
                cur.start = intervals[i].start;
                int tmp = intervals[i].end;
                while (i < intervals.size() && intervals[i].start <= tmp) {
                    if (tmp < intervals[i].end) 
                        tmp = intervals[i].end; 
                    ++i;
                }
                cur.end = tmp;
                merged.push_back(cur);
            }
            return merged;
        }
};
