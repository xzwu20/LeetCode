class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> min_backward(n), max_forward(n);
        max_forward[0] = A[0]; min_backward[n-1] = A[n-1];
        for (int i = 1;i < n;i++) 
            max_forward[i] = max(A[i], max_forward[i-1]);
        for (int i = n-2;i >= 0;i--)
            min_backward[i] = min(A[i], min_backward[i+1]);
        for (int i = 1;i < n;i++)
            if (max_forward[i-1] <= min_backward[i]) return i;
    }
};