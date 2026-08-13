/*
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums, int left, int right) {
        if (left >= right) {return;}
        swap(nums[left], nums[right]);
        reverseArray(nums, left + 1, right - 1);
    }
};


int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    obj.reverseArray(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}



// Time Complexity: O(n)
// Space Complexity: O(n)