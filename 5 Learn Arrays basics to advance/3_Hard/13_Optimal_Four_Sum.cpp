/*

Input: nums = [1, -2, 3, 5, 7, 9], target = 7
Output: [[-2, 1, 3, 5]]
Explanation: nums[1] + nums[0] + nums[2] + nums[3] = 7


Input: nums = [7, -7, 1, 2, 14, 3], target = 9
Output: []
Explanation: No quadruplets are present which add upto 9


Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.fourSum(nums, target);

    for (auto &quad : result) {
        for (int x : quad) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity  : O(N³)

// Space Complexity : O(1) (excluding the output vector)


/****************************************************************************************
Example

nums   = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
target = 8

Already Sorted

Index :  0  1  2  3  4  5  6  7  8  9 10 11 12 13
Value :  1  1  1  2  2  2  3  3  3  4  4  4  5  5

Answer should be

[
 [1,1,2,4],
 [1,1,3,3]
]

****************************************************************************************
STEP 1

i = 0
nums[i] = 1

j = 1
nums[j] = 1

k = 2
l = 13

Need

1 + 1 + nums[k] + nums[l] = 8

****************************************************************************************
STEP 2

+------+---+---+---+----+-----------------+-----+------------------+
|Step  | i | j | k | l  | Values          | Sum | Action           |
+------+---+---+---+----+-----------------+-----+------------------+
| 1    | 0 | 1 | 2 | 13 | 1 1 1 5         |  8  | Store Quadruplet |
+------+---+---+---+----+-----------------+-----+------------------+

Quadruplet

[1,1,1,5]

But this is NOT VALID because only two 1's should be paired?
No.
Actually there are three 1's.

So

1 + 1 + 1 + 5 = 8

This is also VALID.

(If using the given array, this quadruplet will also appear.)

****************************************************************************************
Move pointers

k++
l--

k = 3
l = 12

Now skip duplicates

nums[12] == nums[13]
5 == 5

l--

l = 11

****************************************************************************************
STEP 3

+------+---+---+---+----+-----------------+-----+------------------+
|Step  | i | j | k | l  | Values          | Sum | Action           |
+------+---+---+---+----+-----------------+-----+------------------+
| 2    | 0 | 1 | 3 | 11 | 1 1 2 4         |  8  | Store Quadruplet |
+------+---+---+---+----+-----------------+-----+------------------+

Store

[1,1,2,4]

Move

k++
l--

k = 4
l = 10

Skip duplicate 2

nums[4] == nums[3]

k++

k = 5

Again

nums[5] == nums[4]

k++

k = 6

Skip duplicate 4

nums[10] == nums[11]

l--

l = 9

Again

nums[9] == nums[10]

l--

l = 8

****************************************************************************************
STEP 4

Current

k = 6
l = 8

+------+---+---+---+---+----------------+-----+--------------+
|Step  | i | j | k | l | Values         | Sum | Action       |
+------+---+---+---+---+----------------+-----+--------------+
| 3    | 0 | 1 | 6 | 8 | 1 1 3 3        |  8  | Store        |
+------+---+---+---+---+----------------+-----+--------------+

Store

[1,1,3,3]

Move

k++
l--

k = 7
l = 7

k == l

Stop while loop.

****************************************************************************************
STEP 5

Now j++

j = 2

nums[2] == nums[1]

Duplicate

continue

No work done.

****************************************************************************************
STEP 6

j = 3

nums[j] = 2

k = 4
l = 13

+------+---+---+---+----+-----------------+-----+--------------+
|Step  | i | j | k | l  | Values          | Sum | Action       |
+------+---+---+---+----+-----------------+-----+--------------+
| 1    | 0 | 3 | 4 | 13 | 1 2 2 5         | 10  | l--          |
| 2    | 0 | 3 | 4 | 12 | 1 2 2 5         | 10  | l--          |
| 3    | 0 | 3 | 4 | 11 | 1 2 2 4         |  9  | l--          |
| 4    | 0 | 3 | 4 | 10 | 1 2 2 4         |  9  | l--          |
| 5    | 0 | 3 | 4 |  9 | 1 2 2 4         |  9  | l--          |
| 6    | 0 | 3 | 4 |  8 | 1 2 2 3         |  8  | Store        |
+------+---+---+---+----+-----------------+-----+--------------+

Store

[1,2,2,3]

Move pointers

Duplicate 2's skipped.
Duplicate 3's skipped.

while loop ends.

****************************************************************************************
Remaining iterations

i = 1

nums[1] == nums[0]

Duplicate

continue

-------------------------------------

i = 2

Duplicate

continue

-------------------------------------

i = 3

New first element

Again run same process.

No new unique quadruplet found.

Remaining duplicate i's are skipped.

****************************************************************************************
Final Answer

[
 [1,1,1,5],
 [1,1,2,4],
 [1,1,3,3],
 [1,2,2,3]
]

****************************************************************************************
Why duplicate skipping?

if(i>0 && nums[i]==nums[i-1])
    continue;

→ Don't start with the same first element again.

-------------------------------------

if(j!=i+1 && nums[j]==nums[j-1])
    continue;

→ Don't start with the same second element again.

-------------------------------------

while(k<l && nums[k]==nums[k-1])
    k++;

→ Skip repeated third elements after storing an answer.

-------------------------------------

while(k<l && nums[l]==nums[l+1])
    l--;

→ Skip repeated fourth elements after storing an answer.

****************************************************************************************
Pointer Movement Rule

sum < target
----------
Need a larger sum.

Move

k++

because array is sorted.

-------------------------------------

sum > target
----------
Need a smaller sum.

Move

l--

because array is sorted.

-------------------------------------

sum == target
----------
Store answer.

Move both pointers.

Skip duplicates.

****************************************************************************************

*/