class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()==0) return true;
        int s_size=s.size(),t_size = t.size(), ps=0, pt=0;
        while (pt < t.size()) {
            if (s[ps] == t[pt]) 
                if (++ps == s.size()) return true;
            pt++;
        }
        return false;
    }
};