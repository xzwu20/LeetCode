class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        vector<int> profit(gas.size()*2);
        for (int i = 0;i < gas.size();i++) {
            profit[i] = gas[i] - cost[i];
            sum += profit[i];
            profit[i+gas.size()] = profit[i];
        }
        if (sum < 0) return -1;
        int i = 1, length = 1;
        while (profit[i-1] < 0) i++;
        int remain = profit[i-1];
        while (i < profit.size() && length < gas.size()) {
            if (remain + profit[i] < 0) {
                remain = 0;length = 0;
            } 
            else {
                remain = remain + profit[i];length++;
            }
            i++;
        }
            
        if (length == gas.size()) return i-gas.size();
            else return -1;
    }
};
