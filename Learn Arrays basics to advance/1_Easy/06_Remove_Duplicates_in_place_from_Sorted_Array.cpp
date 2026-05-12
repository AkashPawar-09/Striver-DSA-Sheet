/*

Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and 
Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and 
Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.

Input: nums = [0, 0, 3, 3, 5, 6]
Output: 4
Explanation: Resulting array = [0, 3, 5, 6, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.

Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]
Output: 4
Explanation: Resulting array = [-2, 2, 4, 5, _, _, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.

Note : There is no need to give output as [1,2,3,4,_,_,_,_,_,_,_] using '_'
you can just give output like set 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); // created set to store unique elements in sorted way 

        int i = 0;              // index for giving input to set from vector 

        for (int x : s) {       // iteration for storing nums vector 
            nums[i] = x;        // storing element by element 
            i++;                // forwarding iteration
        }

        return s.size();        // return number of unique elements
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int k = obj.removeDuplicates(nums);

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
