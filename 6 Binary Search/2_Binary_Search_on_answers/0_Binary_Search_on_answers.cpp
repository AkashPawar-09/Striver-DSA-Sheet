/* =======================================================================================================================

What is Binary Search?

Binary Search is a searching algorithm that repeatedly divides the search space into two halves until the answer is found.
It works only when the search space has a monotonic property (usually sorted).
Condition to Apply Binary Search

--------------------------------------------------------------------------------------------------------------------------
The data must satisfy one of these:

Sorted array (ascending/descending)
Answer is monotonic (True/False pattern)
Search space is increasing/decreasing
Binary Search on Index

Searching for an element inside a sorted array.

--------------------------------------------------------------------------------------------------------------------------
Example:
Search 7 in [1,3,5,7,9]

Search Space: Array Indices
0 1 2 3 4
Binary Search on Answer

Here we don't search for an element.
Instead, we search for the smallest/largest answer that satisfies a condition.

--------------------------------------------------------------------------------------------------------------------------
Examples:

Square Root
Nth Root
Koko Eating Bananas
Minimum Days to Make Bouquets
Capacity to Ship Packages
Aggressive Cows
Painter Partition
Allocate Books
When to think of Binary Search?

--------------------------------------------------------------------------------------------------------------------------
Whenever you hear:

Minimum possible
Maximum possible
Smallest answer
Largest answer
At least
At most
Can we?
Possible?
Feasible?

Then think Binary Search.
--------------------------------------------------------------------------------------------------------------------------
Binary Search Template
int low = minimum_possible_answer;
int high = maximum_possible_answer;

while(low <= high){

    int mid = low + (high-low)/2;

    if(check(mid)){
        high = mid - 1;
    }
    else{
        low = mid + 1;
    }
}
Binary Search Formula

Always use

mid = low + (high-low)/2;

Never

mid = (low+high)/2;

Reason:
May overflow for very large numbers.

Search Space

Every Binary Search has two things:

Lowest Possible Answer
↓

-----------------------------

Highest Possible Answer

Example

Square Root of 28

0 -------------------- 28

Nth Root

1 -------------------- M

Koko Eating Bananas

1 -------------------- Maximum pile

Book Allocation

Maximum element -------- Sum of array
Binary Search Process
low            high
 |--------------|

        mid

Check mid.

If answer lies left
high = mid-1
If answer lies right
low = mid+1
Three Possibilities

Suppose
mid^N
There are only 3 cases.
--------------------------------------------------
Case 1

mid^N == M
Answer Found
Return mid
--------------------------------------------------
Case 2

mid^N < M
Need bigger value.
Move Right.
low = mid+1
--------------------------------------------------
Case 3
mid^N > M
Need smaller value.
Move Left.
high = mid-1

--------------------------------------------------------------------------------------------------------------------------
Binary Search on Answer Flow
Guess Answer
      ↓
Check if possible
      ↓
    YES ? ---------> Move Left
     |
    NO
     |
Move Right
Why Move Left after YES?

Suppose we want

Minimum Speed

If speed 10 works,
Maybe 9 works
Maybe 8 works
So search left.
Why Move Right after NO?
Suppose
Speed 5 doesn't work.
Then

4
3
2
1

will never work.
Need bigger answer.
Search right.

--------------------------------------------------------------------------------------------------------------------------

Two Types
1. Find Minimum Answer

Example

Minimum Eating Speed
Minimum Days
Minimum Capacity

Rule

Possible?

YES → Left
NO → Right
--------------------------------------------------------------------------------------------------------------------------

2. Find Maximum Answer

Example :
Maximum Distance
Maximum Minimum Value

Rule :

Possible?
YES → Right
NO → Left
Common Search Space

Problem	Low	High

Square Root	0	n
Nth Root	1	M
Koko Eating Bananas	1	Max pile
Ship Packages	Max element	Sum
Allocate Books	Max element	Sum
Aggressive Cows	1	Max distance
Painter Partition	Max board	Sum
Time Complexity

Normal Binary Search : O(log n)
Binary Search on Answer : O(log(Search Space))

Overall
O(log(Search Space) × Check Function)
Important Observations

Binary Search always needs

Monotonic Behaviour

Meaning

FFFFTTTT

or

TTTTFFFF

Only one transition.

======================================================================================================================= */