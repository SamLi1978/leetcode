/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?


*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        
        map<int, int> m;
        int i = 0;
        int size = nums.size();
        for (auto x : nums)
            m[x] = i++;
        /*
        for (auto x : m)
            cout << x.first << " " << x.second << endl;
        */
        
        for (auto &x : m) 
        {
            if ((x.second + k - size)>=0)
                x.second = x.second + k - size;
            else
                x.second = x.second + k;

        }
        
        /*
        for (auto x : m)
            cout << x.first << " " << x.second << endl;     
        */
        
        nums.clear();
        
        for (int i=0; i<size; i++) 
        {
            for (auto x : m) 
            {
                if (x.second == i)           
                    nums.push_back(x.first);
            }            
        }
        
    }
};

int main()
{
    vector<int> array = {1,2,3,4,5,6,7};
    Solution s;
    s.rotate(array, 3);
    
    for (auto i : array)
        cout << i <<"\t";
    cout << endl;
    
    return 0;
}
