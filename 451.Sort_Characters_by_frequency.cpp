class Solution {
public:
    string frequencySort(string s) {
        int count[256] = {0};
        for (int i = 0;i < s.size();i++)
            count[s[i]]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            return count[a] > count[b] || (count[a] == count[b] && a<b);
        });
        return s;
    }
};