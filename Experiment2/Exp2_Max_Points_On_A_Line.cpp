class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int duplicate = 1;
            int maxPoints = 0;

            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 == x2 && y1 == y2) {
                    duplicate++;
                } else {
                    int dx = x2 - x1;
                    int dy = y2 - y1;

                    int g = __gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    string slope = to_string(dy) + "/" + to_string(dx);
                    mp[slope]++;
                    maxPoints = max(maxPoints, mp[slope]);
                }
            }

            result = max(result, maxPoints + duplicate);
        }

        return result;
    }
};