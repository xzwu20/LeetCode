class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int i=0;i < asteroids.size();i++) {
            int con = asteroids[i];
            while (!result.empty() && con<0 && result.back()>0) {
                int target = result.back();
                if (abs(con)>=abs(target)) 
                    result.pop_back();
                if (abs(con)<=abs(target)) {
                    con = 0;
                    break;
                }
            }
            if (con!=0) result.push_back(con);
        }
        return result;
    }
};