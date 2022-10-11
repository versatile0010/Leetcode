class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dist = 0; int ans = -1; int maxi = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            if (x == points[i][0] || y == points[i][1]) {
                dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (dist < maxi) {
                    maxi = dist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};