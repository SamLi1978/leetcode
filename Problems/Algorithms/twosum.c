/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/* making test

3	-1	2	-29	4	0	9	-2	

Find the numbers which can added up to sum 8 : array at [1,6]

*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;
        map<int, int> mp;
        map<int, int>::iterator it, itPos;
        
        for (auto i : nums)
            cout << i << "\t";
        cout << endl;
        
        for (unsigned i=0; i<nums.size(); i++)
            mp[nums[i]] = i;
        
        /*
        for (auto i : mp)
            cout << "[" << i.first << "," << i.second << "]" << "\t";
        cout << endl;
        */
        
        for (itPos=mp.begin(); itPos!=mp.end(); itPos++)
        {
            it = mp.find(target-itPos->first);
            if (it != mp.end())
            {
                ret.push_back(itPos->second);
                ret.push_back(it->second);
                
                return ret;
            }
        }
        
        return ret;
    }
};

int main()
{
    int sum = 8;
    vector<int> v = { 3, -1, 2, -29, 4, 0, 9, -2 };
    
    Solution s;
    vector<int> ret = s.twoSum(v, sum);
    
    if (ret.empty())
        return -1;
    
    cout << "\nFind the numbers which can added up to sum " << sum << " : array at [" << ret[0] << "," << ret[1] << "]" << endl;
    
    return 0;
}
