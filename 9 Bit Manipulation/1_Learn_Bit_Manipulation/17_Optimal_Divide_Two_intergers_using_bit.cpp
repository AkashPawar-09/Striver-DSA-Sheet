#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) { 

        if (dividend == INT_MIN && divisor == -1) return INT_MAX;   // Case
        bool negative = (dividend < 0) ^ (divisor < 0);             // stores negative quotient

        long long dd = abs((long long)dividend);        // removes negative sign if it have 
        long long ds = abs((long long)divisor);         // removes negative sign if it have 

        long long quotient = 0;                         // created to store answer 

        while (dd >= ds) {
            long long temp = ds;
            long long multiple = 1;
            while ((temp << 1) <= dd) {
                temp = temp << 1;
                multiple = multiple << 1;
            }
            dd = dd - temp;
            quotient = quotient + multiple;
        }

        if (negative) { quotient = -(quotient) ; }      // if any one of dividend OR divisor is negative

        return quotient;
    }
};

int main() {

    int dividend = 29;
    int divisor = 5;

    Solution obj;

    int result = obj.divide(dividend, divisor);

    cout << "Dividend: " << dividend << endl;
    cout << "Divisor: " << divisor << endl;
    cout << "Result: " << result << endl;

    return 0;
}



// Time Complexity : O(log² |dividend| )
// Space Complexity : O(1)



/* --------------------------------------------------------------------------------------------------------------------

dd = the remaining dividend (starts as 43, shrinks every outer loop)
ds = the divisor (stays fixed at 3)
temp = a doubled-up version of ds, used to test "how big a chunk can I subtract right now?"
multiple = how many ds's that chunk represents

Outer Loop: "Keep subtracting chunks until nothing big enough is left"
Inner Loop: "Find the BIGGEST chunk I can subtract right now"

temp << 1 just means "temp × 2". So this loop keeps doubling temp 
(and doubling multiple right along with it) as long as the doubled value still fits inside dd. 
It stops right when doubling would overshoot.
Think of multiple as answering: "temp is multiple times the original divisor."

--------------------------------------------------------------------------------------------------------------------
Full Dry Run: dd = 43, ds = 3
--------------------------------------------------------------------------------------------------------------------

Outer loop — Round 1 (dd = 43)

+-----------+------+----------+--------------------------+
| Inner step | temp | multiple | temp << 1 <= 43?        |
+-----------+------+----------+--------------------------+
| start     |  3   |    1     | 6 <= 43  -> double      |
| step 1    |  6   |    2     | 12 <= 43 -> double      |
| step 2    | 12   |    4     | 24 <= 43 -> double      |
| step 3    | 24   |    8     | 48 <= 43 -> stop        |
+-----------+------+----------+--------------------------+
Inner loop stops with temp = 24, multiple = 8. (Meaning: 3 × 8 = 24, and 24 is the biggest "doubled chunk" of 3 that fits in 43.)

dd = 43 - 24 = 19
quotient = 0 - 8 = -8
--------------------------------------------------------------------------------------------------------------------

Outer loop — Round 2 :

dd = 19 (what's left to divide)
ds = 3 (divisor, never changes)
quotient = 8 (running total so far)

The outer loop checks: is dd(19) >= ds(3)? Yes → so we enter the loop body again for Round 2.
Step 1: Reset temp and multiple
long long temp = ds;        // temp = 3
long long multiple = 1;     // multiple = 1

Every round, we start fresh from the divisor itself (3) and try to double it as much as possible.

Step 2: Inner loop — keep doubling while it still fits in dd (19)

while ((temp << 1) <= dd) {
    temp = temp << 1;
    multiple = multiple << 1;
}

Let's trace it one line at a time:

Check 1: temp << 1 means temp * 2 = 3 * 2 = 6. Is 6 <= 19? Yes.
→ So update: temp = 6, multiple = 2

Check 2: temp << 1 = 6 * 2 = 12. Is 12 <= 19? Yes.
→ So update: temp = 12, multiple = 4

Check 3: temp << 1 = 12 * 2 = 24. Is 24 <= 19? No!
→ Loop stops here. temp stays at 12, multiple stays at 4.

So the inner loop found: "The biggest doubled chunk of 3 that fits inside 19 is 12, and that chunk equals 4 copies of 3."
(Sanity check: 3 × 4 = 12 , and 12 ≤ 19 while the next chunk 24 would be too big.)

Step 3: Subtract that chunk and add to quotient

dd = dd - temp;              // dd = 19 - 12 = 7
quotient = quotient + multiple;  // quotient = 8 + 4 = 12
What Round 2 "returns" (i.e., the state after it finishes)

+-------------+-----------------+----------------+
| Variable    | Before Round 2  | After Round 2  |
+-------------+-----------------+----------------+
| dd          | 19              | 7              |
| quotient    | 8               | 12             |
+-------------+-----------------+----------------+

--------------------------------------------------------------------------------------------------------------------

Outer loop — Round 3 (dd = 7)

+-----------+------+----------+------------------------+
| Inner step | temp | multiple | temp << 1 <= 7?       |
+-----------+------+----------+------------------------+
| start      |  3   |    1     | 6 <= 7  -> double     |
| step 1     |  6   |    2     | 12 <= 7 -> stop       |
+-----------+------+----------+------------------------+

dd       = 7 - 6 = 1
quotient = 12 + 2 = 14

Outer loop — Round 4 (dd = 1)

Check: dd(1) >= ds(3)? No → outer loop stops.
Result :
quotient = 14. Since 43 / 3 = 14.33..., truncated toward zero gives 14. 
Correct, and no sign-flipping was even needed here since both numbers were positive (negative = false).

-------------------------------------------------------------------------------------------------------------------- */