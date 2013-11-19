/* Given a collection of intervals, merge all overlapping intervals.
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
    static int compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> merged;
        Interval current;
        for (int i = 0; i < intervals.size(); ++i) {
            if (i == 0 || intervals[i].start > current.end) {
                if (i > 0) 
                    merged.push_back(current);
                current = intervals[i];
            } else if (current.end < intervals[i].end) {
                current.end = intervals[i].end;
            }
        }
        if (intervals.size() > 0) {
            merged.push_back(current);
        }
        return merged;
    }
};
