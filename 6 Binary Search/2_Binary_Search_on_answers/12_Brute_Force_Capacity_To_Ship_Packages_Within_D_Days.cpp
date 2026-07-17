/*

Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5
Output: 15
Explanation: 
Minimum ship capacity = 15. One way to ship in 5 days:
Day 1: 1 + 2 + 3 + 4 + 5 = 15
Day 2: 6 + 7 = 13
Day 3: 8
Day 4: 9
Day 5: 10
No day exceeds capacity 15 and all packages are shipped in order in 5 days.
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


Input: weights = [3, 2, 2, 4, 1, 4], days = 3
Output: 6
Explanation:
One possible division with capacity 6:
Day 1: 3 + 2 = 5
Day 2: 2 + 4 = 6
Day 3: 1 + 4 = 5
All packages shipped in order within 3 days.


Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();                                     // size of weights array

        int mini = *max_element(weights.begin(), weights.end());    // minimum possible capacity i.e. Maximum element in given vector
        int maxi = accumulate(weights.begin(), weights.end(), 0);   // maximum possible capacity i.e. Sum of all elments in vector

        for (int i = mini; i <= maxi; i++) {                        // check every capacity
            int load = 0;                                           // initilise load = 0 everytime
            int requiredDays = 1;                                   // initially 1 day

            for (int j = 0; j < n; j++) {
                if (load + weights[j] <= i) {                       // if total load is greater than current capacity 
                    load = load + weights[j];                       // add extra load until complete capacity 
                }
                else {                                              // if package is overload 
                    requiredDays++;                                 // then start next day
                    load = weights[j];                              // and fill the leftover load
                }
            }

            if (requiredDays <= days) {                             // if require days are smaller than given days to ship 
                return i;                                           // then return that number
            }
        }

        return maxi;                                                // otherwise return maximum elements 
    }
};


int main() {

    int n;
    cout << "Enter number of packages: ";
    cin >> n;

    vector<int> weights(n);

    cout << "Enter package weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int days;
    cout << "Enter number of days: ";
    cin >> days;

    Solution obj;

    cout << "Minimum Ship Capacity = " << obj.shipWithinDays(weights, days);

    return 0;
}

// Time Complexity : O((sum - maxWeight) × n)
// Space Complexity : O(1)



/* =======================================================================================================================

weights = [1,2,3,4,5,6,7,8,9,10]
days = 5

--------------------------------------------------------------------------------------------------------------------------
Step 1
int n = weights.size();
n = 10

--------------------------------------------------------------------------------------------------------------------------
Step 2
mini = *max_element(weights.begin(), weights.end());

Maximum package weight :
mini = 10

The ship capacity can never be smaller than 10, because the last package itself weighs 10.

--------------------------------------------------------------------------------------------------------------------------
Step 3
maxi = accumulate(weights.begin(), weights.end(), 0);
1+2+3+4+5+6+7+8+9+10 = 55
maxi = 55

If ship capacity is 55, then all packages can be shipped in one day.

--------------------------------------------------------------------------------------------------------------------------
Step 4

The loop checks every possible capacity.

for(int i = 10; i <= 55; i++)

We start with
capacity = 10
Capacity = 10

Initially
load = 0
requiredDays = 1

Now traverse every package.

| Package | Current Load | Action  |    Load | Days |
| ------- | ------------ | ------- | ------- | ---- |
| 1       |            0 | Fits    |       1 |    1 |
| 2       |            1 | Fits    |       3 |    1 |
| 3       |            3 | Fits    |       6 |    1 |
| 4       |            6 | Fits    |      10 |    1 |
| 5       |           10 | Not Fit | New Day |    2 |

--------------------------------------------------------------------------------------------------------------------------
Day 1

1+2+3+4 = 10
Continue

| Package | Load | Action  |    Days |   |
| ------- | ---: | ------- | ------: | - |
| 5       |    0 | Take    |       5 | 2 |
| 6       |    5 | Not Fit | New Day | 3 |

--------------------------------------------------------------------------------------------------------------------------
Day 2

5
Continue

| Package | Load | Action  |    Days |   |
| ------- | ---: | ------- | ------: | - |
| 6       |    0 | Take    |       6 | 3 |
| 7       |    6 | Not Fit | New Day | 4 |

--------------------------------------------------------------------------------------------------------------------------
Day 3

6
Continue

Day4 -> 7
Day5 -> 8
Day6 -> 9
Day7 -> 10

Final
requiredDays = 7
Need

--------------------------------------------------------------------------------------------------------------------------
days = 5

7 > 5
Not Possible

Go to next capacity.
Capacity = 11

Packing becomes :

Day1 -> 1+2+3+4 =10
Day2 -> 5+6 =11
Day3 -> 7
Day4 -> 8
Day5 -> 9
Day6 ->10
requiredDays = 6

Still
6 > 5
Not Possible


Capacity = 12
Day1 -> 1+2+3+4 =10
Day2 -> 5+6 =11
Day3 -> 7
Day4 -> 8
Day5 -> 9
Day6 ->10

Still
6 days
Not Possible.

The algorithm keeps checking


capacity = 13
capacity = 14
Capacity = 15

Initially
load = 0
requiredDays = 1

Traverse :
1 -> load =1
2 -> load =3
3 -> load =6
4 -> load =10
5 -> load =15

Next package
6
15+6 =21
Greater than 15

Start Day 2
requiredDays = 2
load = 6
Continue
6+7 =13

Next
13+8 =21
Greater than 15

Start Day 3
load =8
requiredDays =3

Next
8+9 =17
Greater than 15
Start Day 4

load =9
requiredDays =4

Next
9+10 =19
Greater than 15

Start Day 5
load =10
requiredDays =5

Finished.

Final division
Day1 : 1+2+3+4+5 =15
Day2 : 6+7 =13
Day3 : 8
Day4 : 9
Day5 : 10
requiredDays = 5
days = 5

Condition
if(requiredDays <= days)

becomes
5 <= 5
True

Return

return 15;
Why do we return 15 :
Because this is the first (minimum) capacity that allows shipping all packages within 5 days.

=========================================== IF YOU DONT KNOW WHAT IS accumulate ==========================================

vector<int> arr = {1,2,3,4,5};
int sum = accumulate(arr.begin(), arr.end(), 0);
cout << sum;

Calculation :
sum = 0
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
10 + 5 = 15

Output :
15


vector<int> arr = {10,20,30};
int sum = accumulate(arr.begin(), arr.end(), 0);

Calculation :
0 + 10 = 10
10 + 20 = 30
30 + 30 = 60

Output :
60

=======================================================================================================================

These both functions requires Time Conplexity : O(N)

int mini = *max_element(weights.begin(), weights.end());
int maxi = accumulate(weights.begin(), weights.end(), 0);

======================================================================================================================= */