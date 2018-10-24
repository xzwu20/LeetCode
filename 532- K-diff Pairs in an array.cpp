class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k<0) return 0;
        unordered_map<int, int> count;
        for (int i = 0;i < nums.size();i++)
            count[nums[i]] += 1;
        int res=0;
        for (auto it = count.begin();it != count.end();it++) {
            if (k != 0 && count.find(it->first+k) != count.end()) res += 1;
            if (k == 0 && it->second > 1) res += 1;
        }
        return res;
    }
};