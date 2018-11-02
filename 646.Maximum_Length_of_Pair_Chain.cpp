class Solution {
private:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
public:    
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        int res=1, cur=pairs[0][1];
        for (int j = 1;j < n;j++)
            if (pairs[j][0]>cur) {
                res += 1;
                cur = pairs[j][1];
            }
        return res;
    }
};