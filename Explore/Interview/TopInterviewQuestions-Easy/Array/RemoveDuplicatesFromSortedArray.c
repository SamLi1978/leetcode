#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        nums.clear();
        for (auto i : s)
            nums.push_back(i);
        return nums.size();
        
    }
};

int main()
{
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    
    Solution s;
    int len = s.removeDuplicates(v);
    for (auto i:v)
        cout << i << endl;

    return 0;
}

