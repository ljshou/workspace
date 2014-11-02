class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        assert(gas.size() == cost.size());
        if(gas.empty()) return -1;
        int local(0), global(0);
        int index(0);
        
        for(int i=0; i<gas.size(); ++i) {
            global += gas[i] - cost[i];
            local += gas[i] - cost[i];
            if(local < 0) {
                index = i+1;
                local = 0;
            }
        }
        return global >= 0 ? index : -1;
    }
};
