/*

Input: n = 4, nums = [7, 15, 6, 3], h = 8
Output: 5
Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. 
So, he will take 8 hours to complete all the piles.  


Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5
Output: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. 
So, he will take 5 hours to complete all the piles.


Input: piles = [3,6,7,11], h = 8
Output: 4


Input: piles = [30,11,23,4,20], h = 5
Output: 30


Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());        // find maximum number of banana's

        for (int k = 1; k <= maxi; k++) {                           // 

            int totalHours = 0;

            for (int pile : piles) {
                totalHours = totalHours + (pile + k - 1) / k;
            }

            if (totalHours <= h) {
                return k;
            }
        }

        return maxi;
    }
};


int main() {

    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << "Enter total hours: ";
    cin >> h;

    Solution obj;

    cout << "Minimum Eating Speed = "
         << obj.minEatingSpeed(piles, h);

    return 0;
}


// Time Complexity : O(n × max(piles))
// Space Complexity : O(1)



/*=======================================================================================================================
Brute Force Dry Run

Input:
n = 4
piles = [7, 15, 6, 3]
h = 8

Maximum pile = 15
So we will check every possible eating speed:
k = 1, 2, 3, 4, 5, ......15

--------------------------------------------------------------------------------------------------------------------------
Outer Loop
--------------------------------------------------------------------------------------------------------------------------

for(int k = 1; k <= maxi; k++)

Meaning:

Try every possible eating speed.

Iteration 1 -> k = 1
Iteration 2 -> k = 2
Iteration 3 -> k = 3
Iteration 4 -> k = 4
Iteration 5 -> k = 5
...
until 15

For every speed,
calculate how many total hours Koko needs.

--------------------------------------------------------------------------------------------------------------------------
Inner Loop
--------------------------------------------------------------------------------------------------------------------------

for(int pile : piles)

This loop visits every pile one by one.

For every pile,

hours required =
(pile + k - 1) / k

which is same as

ceil(pile / k)

because if bananas remain,
Koko needs one extra hour.

After calculating hours of one pile,
add it to totalHours.

=================================================================================
Iteration 1
=================================================================================

k = 1
totalHours = 0
Pile = 7
Hours = (7+1-1)/1 =7

totalHours = 7

------------------------

Pile =15
Hours =(15+1-1)/1 =15

totalHours =22

------------------------

Pile =6
Hours =6

totalHours =28

------------------------

Pile =3
Hours =3
totalHours =31

Final
totalHours =31

Check

31 <= 8 ?

No

Speed 1 is NOT possible.

=================================================================================
Iteration 2
=================================================================================

k = 2
totalHours =0

Pile=7
Hours = (7+2-1)/2 = 8/2 = 4

totalHours=4

------------------------

Pile=15
Hours = (15+2-1)/2 = 16/2 = 8

totalHours=12

------------------------

Pile=6
Hours =(6+2-1)/2
      =7/2
      =3

totalHours=15

------------------------

Pile=3

Hours =(3+2-1)/2
      =4/2
      =2

totalHours=17

Check
17<=8 ?
No

Speed 2 is NOT possible.

=================================================================================
Iteration 3
k = 3

Pile 7
(7+3-1)/3 = 9/3 =3

------------------------

Pile15
(15+3-1)/3 = 17/3 = 5

------------------------

Pile6
(6+3-1)/3 = 8/3 = 2

------------------------

Pile3
(3+3-1)/3 = 5/3 = 1

Total
3+5+2+1
=11
11<=8 ?

No

=================================================================================
Iteration 4
k = 4


Pile7
(7+4-1)/4 = 10/4 = 2

------------------------

Pile15

(15+4-1)/4
=18/4
=4

------------------------

Pile6

(6+4-1)/4
=9/4
=2

------------------------

Pile3

(3+4-1)/4
=6/4
=1

Total
2+4+2+1
=9

9<=8 ?
No

=================================================================================
Iteration 5
k = 5

Pile7
(7+5-1)/5
=11/5
=2

------------------------

Pile15

(15+5-1)/5
=19/5
=3

------------------------

Pile6

(6+5-1)/5
=10/5
=2

------------------------

Pile3

(3+5-1)/5
=7/5
=1

Total
2+3+2+1
=8

Check
8<=8 ?
YES

Immediately return k.
Answer = 5

+===============================================================================+
|                      Why do we return immediately?                            |
+===============================================================================+

The outer loop starts from k = 1 and increases one by one.

So the FIRST speed that satisfies

totalHours <= h

is automatically the minimum possible speed.

Therefore,

if(totalHours <= h)
{
    return k;
}

No need to check larger speeds because the question asks
for the MINIMUM eating speed.

+===============================================================================+
|                           Understanding the Formula                           |
+===============================================================================+

Hours = (pile + k - 1) / k

This is integer math for  ceil(pile / k)

Example

Pile = 15
k = 5

15/5 = 3

Hours = 3

-------------------------

Pile = 7
k = 5

7/5 = 1.4

Need 2 hours

Formula

(7+5-1)/5

=11/5

=2

-------------------------

Pile = 6
k = 5

6/5 =1.2

Need 2 hours

Formula

(6+5-1)/5

=10/5

=2

=========================================================
Flow of the Algorithm
=========================================================

Find maximum pile.
↓
Try k = 1
↓
Calculate totalHours
↓
If totalHours <= h
Yes → Return k

No
↓
Increase k
↓
Repeat until answer is found.

=========================================
Time Complexity
=========================================

Outer Loop  : O(max(pile))
Inner Loop  : O(n)

Overall : O(n × max(pile))

=========================================
Space Complexity : O(1)
======================================================================================================================= */