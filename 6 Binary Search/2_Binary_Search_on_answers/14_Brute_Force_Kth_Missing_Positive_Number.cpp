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
        int num=0;
        for(int i=0;i<arr.size();i++){
            num++;
            if(arr[i]!=num){
                k--;
                i--;
            }
            if(k==0) break;
        }
        return num+k;
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

// Time Complexity: O(N + k)
// Space Complexity: O(1)


/* ===================================================== DRY RUN =====================================================

Example:

arr = [2,3,4,7,11]
k = 5

num = 0

| i | num | arr[i] | Missing? |  k |
| - | --- | ------ | -------- | -- |
| 0 |   1 |      2 |    Yes   |  4 |
| 0 |   2 |      2 |    No    |  4 |
| 1 |   3 |      3 |    No    |  4 |
| 2 |   4 |      4 |    No    |  4 |
| 3 |   5 |      7 |    Yes   |  3 |
| 3 |   6 |      7 |    Yes   |  2 |
| 3 |   7 |      7 |    No    |  2 |
| 4 |   8 |     11 |    Yes   |  1 |
| 4 |   9 |     11 |    Yes   |  0 |

--------------------------------------------------------------------------------------------------------------------------

num → current positive number (1,2,3,4...)
i → current array index

The trick is
i--;

Whenever a missing number is found.
Why i--?

Suppose
arr = [2,3,4,7,11]

Initially
i = 0
num = 0
Iteration 1
num++

num = 1

Compare
arr[0] = 2

2 != 1
So
1 is missing.

Decrease
k--

Now
i--;

makes
i = -1

But remember, after every for loop iteration,
i++
automatically happens.

So
i = -1
↓
for loop increments
↓
i = 0

Therefore
We check arr[0] again.
Why?

Because
We haven't matched 2 yet.

--------------------------------------------------------------------------------------------------------------------------

Why return num + k?
Sometimes the answer is after the last element of the array.

Example
arr = [1,2,3,4]
k = 2

Loop
num = 1 
num = 2 
num = 3 
num = 4 
The loop ends because the array is finished.

At this point
num = 4
k = 2

The missing numbers are
5
6

So
return num + k;
= 4 + 2
= 6
Correct answer
_______________________________________________________________________________________________________________________
|                                               MORE EXAMPLES TO UNDERSTAD                                             |
_______________________________________________________________________________________________________________________

arr = [5,7,10,12]
k = 4

Initially
num = 0
i = 0
k = 4

| Iteration |  i | num++ | arr[i] | arr[i] != num    |  k | i-- ? | Next i |
| --------- | -- | ----- | ------ | ---------------- | -- | ----- | ------ |
| 1         |  0 |     1 |      5 |       yes        |  3 |  Yes  |      0 |
| 2         |  0 |     2 |      5 |       yes        |  2 |  Yes  |      0 |
| 3         |  0 |     3 |      5 |       yes        |  1 |  Yes  |      0 |
| 4         |  0 |     4 |      5 |       yes        |  0 |  Yes  |   Stop |

Loop breaks.

Return
num + k
= 4 + 0
= 4

Missing Numbers
1,2,3,4,6,8,9,11,...

The 4th missing number = 4 

--------------------------------------------------------------------------------------------------------------------------

arr = [5,7,10,12]
k = 6

Initially

num = 0
i = 0
k = 6

| Iteration |  i | num++ | arr[i] | arr[i] != num |  k | i-- ? | Next i |
| --------- | -: | ----: | -----: | :-----------: | -: | :---: | -----: |
| 1         |  0 |     1 |      5 |      yes      |  5 |  Yes  |      0 |
| 2         |  0 |     2 |      5 |      yes      |  4 |  Yes  |      0 |
| 3         |  0 |     3 |      5 |      yes      |  3 |  Yes  |      0 |
| 4         |  0 |     4 |      5 |      yes      |  2 |  Yes  |      0 |
| 5         |  0 |     5 |      5 |       no      |  2 |   No  |      1 |
| 6         |  1 |     6 |      7 |      yes      |  1 |  Yes  |      1 |
| 7         |  1 |     7 |      7 |       no      |  1 |   No  |      2 |
| 8         |  2 |     8 |     10 |      yes      |  0 |  Yes  |   Stop |

Loop breaks.
Return :
num + k
= 8 + 0
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