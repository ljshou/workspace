#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	multiset<int> bst;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		int x = nums[i];
    		if(bst.size() > k) bst.erase(bst.find(nums[i-k]));
    		auto it_lower = bst.lower_bound(x);
    		if(it_lower != bst.end() && *it_lower <= x + t) return true;
    		auto it_upper = bst.upper_bound(x);
    		if(it_upper != bst.begin() && *(--it_upper) >= x - t) return true;
    		bst.insert(x);
    	}
        return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	std::vector<int> v{0};
	cout << test.containsNearbyAlmostDuplicate(v, 0, 0) << endl;
	return 0;
}