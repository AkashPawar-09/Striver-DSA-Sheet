/* -------------------------------------------------------------------------------------------------------------------------

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. 
x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.


Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. 
We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.


Input: arr[] = [5, 5, 5, 5, 10, 5, 5], m = 2, k = 3,
Output: 10
Explanation: We need to make 2 bouquets, each consisting of 3 adjacent flowers.
-> By day 5, all flowers have bloomed except the flower at position 5 (1-indexed).
-> We can form the 1st bouquet using the first 3 bloomed flowers.
-> It is not possible to form the 2nd bouquet now.
-> By day 10, all the flowers have bloomed.
-> We can then form 2 bouquets, each consisting of 3 adjacent flowers.

------------------------------------------------------------------------------------------------------------------------- */


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();                        // n = size of bloomDay vector

        if ((long long) m * k > n)                      // if total flowers are greater than n
            return -1;                                  // then return -1 
        
        int mini = *min_element(bloomDay.begin(), bloomDay.end());  // mini is minimum element in bloomDay vector
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());  // maxi is maximum element in bloomDay vector

        for (int day = mini; day <= maxi; day++) {      // loop from day = mini to maxi 
            int flowers = 0;                            // flowers are initially 0
            int bouquets = 0;                           // also bouquets are initially 0

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= day)                 // cheaks adjecent flowers is smaller than or equal to mid OR NOT
                    flowers++;                          // then increase count of flowers
                else {
                    bouquets = bouquets + flowers / k;  // make bouquets from consecutive flowers
                    flowers = 0;                        // reset consecutive flowers
                }
            }

            bouquets = bouquets + flowers / k;          // last consecutive flowers

            if (bouquets >= m)                          // if possible to make m bouquets
                return day;                             // return that day
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> bloomDay(n);

    for (int i = 0; i < n; i++)
        cin >> bloomDay[i];

    int m, k;
    cin >> m >> k;

    Solution obj;

    cout << obj.minDays(bloomDay, m, k);

    return 0;
}


// Time Complexity  : O( (maxi-mini+1)*N )
// Space Complexity : O(1)


/* =======================================================================================================================

bloomDay = [7,7,7,7,12,7,7]
m = 2
k = 3
--------------------------------------------------------------------------------------------------------------------------

Step 1
int n = bloomDay.size();
n = 7
--------------------------------------------------------------------------------------------------------------------------

Step 2
if ((long long)m * k > n)
    return -1;
m * k = 2 * 3 = 6

n = 7
6 > 7 ?
No

Continue.
--------------------------------------------------------------------------------------------------------------------------

Step 3
mini = *min_element(...)
maxi = *max_element(...)
mini = 7
maxi = 12
--------------------------------------------------------------------------------------------------------------------------

Step 4 : Outer loop

for(int day = mini; day <= maxi; day++)

means

day = 7
day = 8
day = 9
day = 10
day = 11
day = 12

We check every day one by one.

-------------------------------------------------------------------------------------
DAY = 7

Initially ,
flowers = 0
bouquets = 0

Now traverse every flower.

i = 0
bloomDay[0] = 7
7 <= 7
Yes

flowers = 1
i = 1
bloomDay[1] = 7
7 <= 7
Yes

flowers = 2
i = 2
bloomDay[2] = 7
Yes

flowers = 3
i = 3
bloomDay[3] = 7
Yes

flowers = 4
Current consecutive flowers

✔ ✔ ✔ ✔
flowers = 4
i = 4
bloomDay[4] = 12
12 <= 7 ?
No

Now sequence breaks.

Execute :
bouquets += flowers / k;
flowers = 4
4 / 3 = 1
bouquets = 1

Reset

flowers = 0
i = 5
bloomDay[5] = 7
Yes

flowers = 1
i = 6
bloomDay[6] = 7
Yes

flowers = 2
Loop finished.
Still
flowers = 2

Execute :
bouquets += flowers / k;
2 / 3 = 0
bouquets = 1

Now
bouquets >= m ?
1 >= 2 ?
No
-------------------------------------------------------------------------------------
Go to next day.
DAY = 8

Again
flowers = 0
bouquets = 0
Every flower except 12 is bloomed.

Array :
✔ ✔ ✔ ✔ ✘ ✔ ✔
Exactly same as Day 7.
Result
bouquets = 1
Not enough.

-------------------------------------------------------------------------------------
DAY = 9
Same
✔ ✔ ✔ ✔ ✘ ✔ ✔
bouquets = 1

-------------------------------------------------------------------------------------
DAY = 10
Same
✔ ✔ ✔ ✔ ✘ ✔ ✔
bouquets = 1

-------------------------------------------------------------------------------------
DAY = 11
Same
✔ ✔ ✔ ✔ ✘ ✔ ✔

bouquets = 1

-------------------------------------------------------------------------------------
DAY = 12

Again 
flowers = 0
bouquets = 0

Now every flower blooms.
✔ ✔ ✔ ✔ ✔ ✔ ✔
Traverse
i=0 flowers=1
i=1 flowers=2
i=2 flowers=3
i=3 flowers=4
i=4 flowers=5
i=5 flowers=6
i=6 flowers=7

Loop finished.

Execute :
bouquets += flowers / k;
flowers = 7

7 / 3 = 2
bouquets = 2

Check
bouquets >= m
2 >= 2
Yes

Return :
return 12;

======================================================================================================================= */