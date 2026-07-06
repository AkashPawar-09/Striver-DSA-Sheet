/*

Input: arr = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
arr[0] + arr[1] + arr[2] = (-1) + 0 + 1 = 0.
arr[1] + arr[2] + arr[4] = 0 + 1 + (-1) = 0.
arr[0] + arr[3] + arr[4] = (-1) + 2 + (-1) = 0. // but -1 and -1 are not distinct   
The distinct triplets are [-1,0,1] and [-1,-1,2].

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Input: arr = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.threeSum(nums);

    for (auto &triplet : result) {
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}


// Time Complexity : O(N²)
// Space Complexity : O(1)  (excluding the output vector)


/* --------------------------------------Example--------------------------------------

nums = [-2,-2,-2,-1,-1,-1,0,0,0,2,2,2]

Already Sorted:
Index :  0  1  2  3  4  5  6  7  8  9  10  11
Value : -2 -2 -2 -1 -1 -1  0  0  0  2  2   2


===========================================================================================
Iteration 1
===========================================================================================

i = 0
nums[i] = -2

j = 1
k = 11

+------+---------+---------+----------+---------+---------+-------------------------+
| Step | i,j,k   | Values  | Sum      | Result  | Action  | Triplet                 |
+------+---------+---------+----------+---------+---------+-------------------------+
| 1    |0,1,11   |-2,-2,2  |-2        |< 0      |j++      |                         |
| 2    |0,2,11   |-2,-2,2  |-2        |< 0      |j++      |                         |
| 3    |0,3,11   |-2,-1,2  |-1        |< 0      |j++      |                         |
| 4    |0,4,11   |-2,-1,2  |-1        |< 0      |j++      |                         |
| 5    |0,5,11   |-2,-1,2  |-1        |< 0      |j++      |                         |
| 6    |0,6,11   |-2,0,2   |0         |Found    |Store    |[-2,0,2]                 |
+------+---------+---------+----------+---------+---------+-------------------------+

Duplicate Removal

Current:
j = 6
k = 11

After j++ and k--

j = 7
k = 10

Skip duplicate zeros

nums[7] == nums[6]
0 == 0

j++

j = 8

Again

nums[8] == nums[7]
0 == 0

j++

j = 9

Now

j = 9
k = 10

Skip duplicate twos

nums[10] == nums[11]
2 == 2

k--

k = 9

Now

j == k

Stop while loop.


===========================================================================================
Iteration 2
===========================================================================================

i = 1

nums[1] == nums[0]

-2 == -2

Duplicate

continue

Nothing happens.


===========================================================================================
Iteration 3
===========================================================================================

i = 2

nums[2] == nums[1]

-2 == -2

Duplicate

continue


===========================================================================================
Iteration 4
===========================================================================================

i = 3
nums[i] = -1

j = 4
k = 11

+------+---------+---------+----------+---------+---------+-------------------------+
| Step | i,j,k   | Values  | Sum      | Result  | Action  | Triplet                 |
+------+---------+---------+----------+---------+---------+-------------------------+
| 1    |3,4,11   |-1,-1,2  |0         |Found    |Store    |[-1,-1,2]                |
+------+---------+---------+----------+---------+---------+-------------------------+

Duplicate Removal

After storing

j = 5
k = 10

Skip duplicate -1

nums[5] == nums[4]

-1 == -1

j++

j = 6

Skip duplicate 2

nums[10] == nums[11]

2 == 2

k--

k = 9

Again

nums[9] == nums[10]

2 == 2

k--

k = 8

Now

j = 6
k = 8

Continue searching


+------+---------+---------+----------+---------+---------+-------------------------+
| Step | i,j,k   | Values  | Sum      | Result  | Action  | Triplet                 |
+------+---------+---------+----------+---------+---------+-------------------------+
| 2    |3,6,8    |-1,0,0   |-1        |<0       |j++      |                         |
| 3    |3,7,8    |-1,0,0   |-1        |<0       |j++      |                         |
+------+---------+---------+----------+---------+---------+-------------------------+

Now

j == k

Stop.


===========================================================================================
Iteration 5
===========================================================================================

i = 4

nums[4] == nums[3]

-1 == -1

Duplicate

continue


===========================================================================================
Iteration 6
===========================================================================================

i = 5

nums[5] == nums[4]

-1 == -1

Duplicate

continue


===========================================================================================
Iteration 7
===========================================================================================

i = 6
nums[i] = 0

j = 7
k = 11

+------+---------+---------+----------+---------+---------+-------------------------+
| Step | i,j,k   | Values  | Sum      | Result  | Action  | Triplet                 |
+------+---------+---------+----------+---------+---------+-------------------------+
| 1    |6,7,11   |0,0,2    |2         |>0       |k--      |                         |
| 2    |6,7,10   |0,0,2    |2         |>0       |k--      |                         |
| 3    |6,7,9    |0,0,2    |2         |>0       |k--      |                         |
| 4    |6,7,8    |0,0,0    |0         |Found    |Store    |[0,0,0]                  |
+------+---------+---------+----------+---------+---------+-------------------------+

After storing

j = 8
k = 7

j > k

Stop.


===========================================================================================
Remaining Iterations
===========================================================================================

i = 7

nums[7] == nums[6]

Duplicate

continue


i = 8

nums[8] == nums[7]

Duplicate

continue


i = 9

nums[9] = 2

j = 10
k = 11

sum = 2 + 2 + 2 = 6

> 0

k--

k = 10

j == k

Stop


i = 10

Duplicate

continue


i = 11

Duplicate

continue


===========================================================================================
Final Answer
===========================================================================================

[
    [-2,0,2],
    [-1,-1,2],
    [0,0,0]
]


===========================================================================================
Why Duplicate Skipping Works
===========================================================================================

1. Duplicate 'i'
   ----------------
   if(i > 0 && nums[i] == nums[i-1]) continue;

   Prevents starting from the same first element multiple times.

2. Duplicate 'j'
   ----------------
   while(j < k && nums[j] == nums[j-1]) j++;

   After a valid triplet is found, skips all repeated second elements.

3. Duplicate 'k'
   ----------------
   while(j < k && nums[k] == nums[k+1]) k--;

   After a valid triplet is found, skips all repeated third elements.

Because the array is sorted, all duplicates are adjacent, making them easy to skip.


*/