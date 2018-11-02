class Solution {
private:
    int cal_times(vector<int> piles, int speed) {
        int times = 0;
        for (int i = 0;i < piles.size();i++) {
            times += piles[i] / speed;
            if (piles[i] % speed) times += 1;
        }
        return times;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {    
        int l=1, r = *max_element(piles.begin(), piles.end()), speed, result;
        while (l <= r) {
            speed = (l+r) / 2;
            int t1 = cal_times(piles, speed);
            if (t1 <= H) {
                result = speed;
                r = speed-1;
            }
            else l = speed + 1;
        }
        return result;
    }
};