/* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
        Interval merge(Interval a, Interval b) {
            int st = min(a.start, b.start);
            int en = max(a.end, b.end);
            return Interval(st, en);
        }
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<Interval> ans;
            ans.push_back(newInterval);
            for (int i = 0; i < intervals.size(); ++i) {
                Interval tmp = ans.back();
                ans.pop_back();
                if (intervals[i].end < tmp.start) {
                    ans.push_back(intervals[i]);
                    ans.push_back(tmp);
                } else if (intervals[i].start > tmp.end) {
                    ans.push_back(tmp);
                    ans.push_back(intervals[i]);
                } else 
                    ans.push_back(merge(tmp, intervals[i]));
            }
            return ans;
        }
};
