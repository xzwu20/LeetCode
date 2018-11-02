class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 0;
        while (i < s.length()-1) {
            if (s[i] > s[i+1]) break;
            i++;
        }
        if (i==s.length()-1) return N;
        while (i != 0 && s[i] <= s[i-1]) 
            i--;
        s[i]--;
        for (int j = i+1;j < s.length();j++) 
            s[j] = '9';
        return stoi(s);
    }
};