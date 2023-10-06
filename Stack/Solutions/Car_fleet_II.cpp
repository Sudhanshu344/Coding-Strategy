class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1);
        vector<int> stk;
        for (int i = n-1; i >= 0; i--){
            int p = cars[i][0];
            int s = cars[i][1];
            while (!stk.empty()){
                int j = stk.back(), p2 = cars[j][0], s2 = cars[j][1];
                if (s2 >= s || ( 1.0 * (p2-p)/(s-s2) >= res[j] && res[j] > 0)){
                    stk.pop_back();
                }
                else break;
            }
            if (!stk.empty())
                res[i] = 1.0 * (cars[stk[stk.size()-1]][0]-p)/(s-cars[stk[stk.size()-1]][1]);
            stk.push_back(i);
        }
        return res;
    }
};