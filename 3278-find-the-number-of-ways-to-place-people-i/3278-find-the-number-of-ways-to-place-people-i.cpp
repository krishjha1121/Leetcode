class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto lambda = [](vector<int> p1, vector<int> p2){
            if(p1[0] == p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        };

        sort(points.begin(), points.end(), lambda);
        int res = 0;

        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxiY = INT_MIN;
            for(int j = i + 1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1) continue;

                if(y2 > maxiY){
                    res++;
                    maxiY = y2;
                }
            }
        }

        return res;
    }
};