/* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int gcd(int a, int b) {
        return a ? a / abs(a) * abs(gcd(b % a, a)) : b;
    }
    public:
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same = 1, mx = 0;
            unordered_map<string, int> count;
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                int g = gcd(x, y);
                if (!g) { ++same; continue; }
                x /= g; y /= g;
                mx = max(mx, ++count[to_string(x) + " " + to_string(y)]);
            }
            ans = max(ans, mx + same);
        }
        return ans;
    }
};

