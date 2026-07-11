/*

1. What is Binary Search?

Binary Search is a searching algorithm that finds an element in a sorted array by repeatedly dividing the search space into two halves.
Instead of checking every element like Linear Search, Binary Search eliminates half of the remaining elements in every step.

--------------------------------------------------------------------------------------------------------------------------
2. When can Binary Search be used?

Binary Search works only if the data is sorted (ascending or descending).
Example (Ascending):    1 3 5 7 9 11 13
Not possible:           4 8 1 7 2 10
--------------------------------------------------------------------------------------------------------------------------
3. Real-Life Example

Imagine a dictionary with 1000 pages.
Suppose you want to find the word
Mountain
You don't start from page 1.

Instead,

Open the middle page.
Compare the word.
If your word comes later alphabetically, go to the right half.
Otherwise, go to the left half.

Repeat until found.
This is Binary Search.
--------------------------------------------------------------------------------------------------------------------------
4. Linear Search vs Binary Search

Linear Search	Binary Search
Works on unsorted array	Requires sorted array
Checks one by one	Eliminates half every step
O(n)	O(log n)
Easy	Slightly harder
5. Idea Behind Binary Search

Suppose : 1 3 5 7 9 11 13

Target : 11

Initially
low = 0
high = 6
Middle mid = 3

nums[mid] = 7

Compare 11 > 7

Discard left half.

Now
9 11 13
Again
mid = 5
nums[mid]=11

Found.

--------------------------------------------------------------------------------------------------------------------------
6. Visualization

1 3 5 7 9 11 13

low             high

        mid

7 < 11

Discard left half

----------------------

9 11 13

low    high

   mid

Found

--------------------------------------------------------------------------------------------------------------------------
7. Binary Search Algorithm
low = 0

high = n-1

while(low<=high)

    mid

    if found

        return

    else if target bigger

        search right

    else

        search left

return -1

--------------------------------------------------------------------------------------------------------------------------
8. Standard Code
int low = 0;
int high = n - 1;

while (low <= high) {

    int mid = (low + high) / 2;

    if (nums[mid] == target)
        return mid;

    else if (target > nums[mid])
        low = mid + 1;

    else
        high = mid - 1;
}

return -1;

--------------------------------------------------------------------------------------------------------------------------
9. Why mid?

Suppose
low = 0
high = 9
Middle
mid = 4

Instead of checking
0
1
2
3
4
5
6
7
8
9

You immediately check
4

One comparison removes half the array.

--------------------------------------------------------------------------------------------------------------------------
10. Why Does It Work?

Sorted array
1 3 5 7 9 11 13

Target
11

Since
11 > 7
Everything before
7

is also smaller.
Therefore we safely ignore
1 3 5 7

--------------------------------------------------------------------------------------------------------------------------
11. Binary Search Dry Run

Array :1 3 5 7 9 11 13

Target :9

Iteration 1 :

low=0
high=6
mid=3

nums[mid]=7
9>7
Move
low=4

Iteration 2 :
low=4
high=6
mid=5

nums[mid]=11
9<11
Move
high=4

Iteration 3 :
low=4
high=4
mid=4
nums[mid]=9

Found.

--------------------------------------------------------------------------------------------------------------------------
12. Time Complexity

Every iteration removes half.

n

n/2

n/4

n/8

...

1

Number of divisions

log₂n

Time Complexity

O(log n)

--------------------------------------------------------------------------------------------------------------------------
13. Space Complexity

Iterative Binary Search
O(1)

Recursive Binary Search
O(log n)
because of recursion stack.

--------------------------------------------------------------------------------------------------------------------------
14. Binary Search on Descending Array

Ascending
target > nums[mid]
move right

Descending
target > nums[mid]
move left

Conditions reverse.

--------------------------------------------------------------------------------------------------------------------------
15. Recursive Binary Search

int binarySearch(vector<int>& nums,int low,int high,int target){

    if(low>high)
        return -1;

    int mid=(low+high)/2;

    if(nums[mid]==target)
        return mid;

    if(target<nums[mid])
        return binarySearch(nums,low,mid-1,target);

    return binarySearch(nums,mid+1,high,target);
}
    
--------------------------------------------------------------------------------------------------------------------------
16. Overflow Problem

Avoid
int mid=(low+high)/2;

Suppose
low = 2,000,000,000
high = 2,000,000,001

Adding them exceeds the range of int.

Correct : int mid=low+(high-low)/2;

Used in interviews.

--------------------------------------------------------------------------------------------------------------------------
17. Binary Search Conditions

Found
nums[mid]==target
Search Right
target>nums[mid]
Search Left
target<nums[mid]

--------------------------------------------------------------------------------------------------------------------------
18. Common Mistakes

Using

while(low<high)

instead of

while(low<=high)

Wrong

high=mid;

Correct

high=mid-1;

Wrong

low=mid;

Correct

low=mid+1;

Applying Binary Search on an unsorted array.

--------------------------------------------------------------------------------------------------------------------------
19. Binary Search Variants

Standard Binary Search
Lower Bound
Upper Bound
First Occurrence
Last Occurrence
Count Occurrences
Search Insert Position
Floor
Ceil
Peak Element
Rotated Sorted Array
Search in Rotated Sorted Array II
Minimum in Rotated Array
Single Element in Sorted Array
Infinite Sorted Array
Nearly Sorted Array
Binary Search on Answer
Aggressive Cows
Book Allocation
Painter's Partition
Koko Eating Bananas
Capacity to Ship Packages
Split Array Largest Sum
Median of Two Sorted Arrays
Matrix Binary Search

--------------------------------------------------------------------------------------------------------------------------
20. Binary Search on Answer

Sometimes the answer is not present in the array. 
Instead, you binary search over the range of possible answers.

Examples:

Koko Eating Bananas
Aggressive Cows
Book Allocation
Painter's Partition
Capacity to Ship Packages
Split Array Largest Sum
Minimize Maximum Distance to Gas Station

--------------------------------------------------------------------------------------------------------------------------
21. LeetCode Problems (Easy → Hard)                             |
-----------------------------------------------------------------
Easy

Binary Search
Search Insert Position
Sqrt(x)
First Bad Version
Guess Number Higher or Lower

-----------------------------------------------------------------
Medium

Find First and Last Position
Search in Rotated Sorted Array
Search in Rotated Sorted Array II
Find Minimum in Rotated Sorted Array
Find Peak Element
Single Element in a Sorted Array
Koko Eating Bananas
Capacity to Ship Packages Within D Days
Find the Smallest Divisor Given a Threshold

-----------------------------------------------------------------
Hard

Median of Two Sorted Arrays
Split Array Largest Sum

--------------------------------------------------------------------------------------------------------------------------
22. Binary Search Pattern

Whenever you see these words in a problem, think of Binary Search:

Sorted array
Sorted matrix
Find first/last occurrence
Minimum
Maximum
Smallest
Largest
Answer lies in a range
Can we do it in O(log n)?
Monotonic condition (true/false changes only once)

--------------------------------------------------------------------------------------------------------------------------
23. Complete Binary Search Roadmap

1. Binary Search Basics
        │
        ▼
2. Lower Bound
        │
        ▼
3. Upper Bound
        │
        ▼
4. First & Last Occurrence
        │
        ▼
5. Count Occurrences
        │
        ▼
6. Search Insert Position
        │
        ▼
7. Floor & Ceil
        │
        ▼
8. Rotated Sorted Array
        │
        ▼
9. Minimum in Rotated Array
        │
        ▼
10. Peak Element
        │
        ▼
11. Binary Search on Answers
        │
        ▼
12. Advanced Interview Problems

*/