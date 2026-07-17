/*

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.


Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.


Input: arr = [3, 5, 7, 10], k = 6
Output: 9
Explanation: The missing numbers are [1, 2, 4, 6, 8, 9, 11, ...]. The 6ᵗʰ missing number is 9.


Input: arr = [1, 4, 6, 8, 9], k = 3
Output: 5
Explanation: The missing numbers are [2, 3, 5, 7, 10, ...]. The 3ʳᵈ missing number is 5.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return k + high + 1;
    }
};


int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int ans = obj.findKthPositive(arr, k);

    cout << "Kth Missing Positive Number = " << ans << endl;

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(1)


/* ===================================================== DRY RUN =====================================================

Input :
arr = [2,3,4,7,11]
k = 5

Initially
low = 0
high = 4

--------------------------------------------------------------------------------------------------------------------------

Binary Search Iterations :

| Iteration | low | high | mid | arr[mid] | missing = arr[mid] - (mid + 1)  | Condition     | Action                |
| --------- | --- | ---- | --- | -------- | ------------------------------- | ------------- | --------------------- |
| 1         |   0 |    4 |   2 |        4 |              4 - (2+1) = 1      | 1 < 5         | low = mid + 1 = 3     |
| 2         |   3 |    4 |   3 |        7 |              7 - (3+1) = 3      | 3 < 5         | low = mid + 1 = 4     |
| 3         |   4 |    4 |   4 |       11 |             11 - (4+1) = 6      | 6 < 5         | high = mid - 1 = 3    |


Loop Ends
low = 4
high = 3

low > high

So Binary Search stops.

--------------------------------------------------------------------------------------------------------------------------

How missing is Calculated

| Index | arr[i] | Expected Number (i+1) | Missing = arr[i] - (i+1) | Missing Numbers Before arr[i] |
| ----: | -----: | --------------------: | -----------------------: | ----------------------------- |
|     0 |      2 |                     1 |                        1 | 1                             |
|     1 |      3 |                     2 |                        1 | 1                             |
|     2 |      4 |                     3 |                        1 | 1                             |
|     3 |      7 |                     4 |                        3 | 1, 5, 6                       |
|     4 |     11 |                     5 |                        6 | 1, 5, 6, 8, 9, 10             |

--------------------------------------------------------------------------------------------------------------------------

Why return k + high + 1?

After Binary Search ends,
high = 3
means the last index where
missing < k
is index 3.

That is
arr[3] = 7
Before 7, there are only 3 missing numbers:
1, 5, 6

We still need
k = 5

Already found = 3
Need 2 more missing numbers.
Those numbers are
8
9

Hence the 5th missing number is
9

The formula
k + high + 1

works because:

high + 1 gives the count of array elements that are before the answer.
Adding that count to k shifts the answer forward by the number of existing (non-missing) elements before it.

For this example:

+----------+----+
| k        | 5  |
| high + 1 | 4  |
+----------+----+

Answer = 5 + 4 = 9

which is exactly the 5th missing positive number.

_______________________________________________________________________________________________________________________
|                                               MORE EXAMPLES TO UNDERSTAD                                             |
_______________________________________________________________________________________________________________________

arr = [5,7,10,12]
k = 4

Initially

n = 4
low = 0
high = 3

| Iteration | low | high | mid | arr[mid] | missing = arr[mid] - (mid+1) | missing < k | Action    |
| --------- | --: | ---: | --: | -------: | ---------------------------: | :---------: | --------- |
| 1         |   0 |    3 |   1 |        7 |                7 - (1+1) = 5 |  No (5 < 4) | high = 0  |
| 2         |   0 |    0 |   0 |        5 |                5 - (0+1) = 4 |  No (4 < 4) | high = -1 |

Loop ends because
low = 0
high = -1

low > high

Return
k + high + 1
= 4 + (-1) + 1
= 4

Missing Numbers
1,2,3,4,6,8,9,11,...

The 4th missing number = 4

--------------------------------------------------------------------------------------------------------------------------

arr = [5,7,10,12]
k = 6

Initially
n = 4
low = 0
high = 3

| Iteration | low | high | mid | arr[mid] | missing = arr[mid] - (mid+1) | missing < k | Action   |
| --------- | --: | ---: | --: | -------: | ---------------------------: | :---------: | -------- |
| 1         |   0 |    3 |   1 |        7 |                7 - (1+1) = 5 | Yes (5 < 6) | low = 2  |
| 2         |   2 |    3 |   2 |       10 |               10 - (2+1) = 7 |  No (7 < 6) | high = 1 |

Loop ends because

low = 2
high = 1
low > high

Return :
k + high + 1
= 6 + 1 + 1
= 8

Missing Numbers
1,2,3,4,6,8,9,11,...

The 1st missing number = 1
The 2nd missing number = 2
The 3rd missing number = 3
The 4th missing number = 4
The 5th missing number = 6
The 6th missing number = 8

Answer = 8
_______________________________________________________________________________________________________________________ */