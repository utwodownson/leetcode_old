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
    static int cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
    Interval merge(Interval a, Interval b) {
        int st = min(a.start, b.start);
        int en = max(a.end, b.end);
        return Interval(st, en);
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (!intervals.size()) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        ans.push_back(intervals[0]);
        for (int i = 0; i < intervals.size(); ++i) {
            Interval tmp = ans.back(); 
            if (tmp.end >= intervals[i].start) {
                ans.pop_back();
                ans.push_back(merge(tmp, intervals[i]));
            } else 
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
