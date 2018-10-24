class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double> > glass(query_row+1, vector<double>(query_row+1, 0.0));
        glass[0][0] = (double)poured;
        int i = 1;
        while (i <= query_row) {
            int j = 0;
            while (j <= i) {
                if (j>0 && glass[i-1][j-1]>1.0) glass[i][j] += (glass[i-1][j-1]-1.0)/2;
                if (j<i && glass[i-1][j]>1.0) glass[i][j] += (glass[i-1][j]-1.0)/2;
                j += 1;
            }
            i += 1;
        }
        return min(glass[query_row][query_glass], 1.0);
    }
};