/* --------------------------------------------------------------------------------------------------------------------

Two Pointer — Theory

What: Technique using two indices to traverse a structure instead of nested loops/brute force, 
cutting O(n²) to O(n) in many cases.

How it works: Maintain two pointers (low/high or slow/fast) that move based on a comparison/condition at each step 
— no backtracking, each pointer moves in one direction (mostly).

--------------------------------------------------------------------------------------------------------------------

Types:

Opposite-direction (converging) — start at both ends, move inward. Needs sorted/structured data usually.
Same-direction (fast-slow) — both start at/near beginning, move forward at different rates/conditions.

--------------------------------------------------------------------------------------------------------------------

When to use:

Array/string is sorted (or can be sorted)
Looking for a pair/triplet satisfying a sum/condition
Need to detect cycles, find middle of linked list
Removing duplicates in-place, partitioning arrays
Comparing elements from both ends (palindrome check)

--------------------------------------------------------------------------------------------------------------------

Common question patterns:

    Pair with given sum in sorted array
    3Sum / 4Sum (fixed pointer + two pointer)
    Container with most water
    Trapping rain water
    Remove duplicates from sorted array in-place
    Merge two sorted arrays
    Linked list cycle detection (Floyd's, fast-slow)
    Find middle of linked list
    Valid palindrome / reverse string in-place
    Sort colors (Dutch national flag — 3 pointers)

--------------------------------------------------------------------------------------------------------------------

Sliding Window — Theory

What: A specialized two-pointer variant where you maintain a contiguous "window" [left,right] over an array/string, 
and expand/shrink it incrementally instead of recomputing from scratch for each subarray — avoids the O(n²)/O(n·k) 
brute force of checking every subarray.

How it works: Extend right to grow window, compute/update result incrementally; when window violates a condition, 
shrink from left until valid again. Each element added/removed at most once → O(n).

--------------------------------------------------------------------------------------------------------------------

Types:

Fixed-size window — window size k is given, doesn't change. Slide by removing leftmost, adding new right element.

Variable-size window — window grows/shrinks based on a condition (sum, distinct count, etc.), size not predetermined.

--------------------------------------------------------------------------------------------------------------------

When to use:

Problem involves a contiguous subarray/substring (not subsequence)
Asked for max/min/count of subarrays satisfying a size or sum condition
Keywords: "subarray", "substring", "contiguous", "at most/exactly k", "window of size k"
Brute force would recompute overlapping work for every window

When NOT to use: non-contiguous subsequences, need all combinations, or condition isn't monotonic 
(shrinking window doesn't consistently fix violation — sliding window relies on monotonic expand/shrink logic).

--------------------------------------------------------------------------------------------------------------------

Common question patterns:

    Max/min sum subarray of size k
    Average of all subarrays of size k
    Longest substring without repeating characters
    Longest substring with at most K distinct characters
    Smallest subarray with sum ≥ target
    Longest subarray with sum ≤ target
    Max consecutive ones (with at most k flips)
    Minimum window substring (contains all chars of pattern)
    Count anagrams / find all anagram indices in a string
    Longest repeating character replacement

--------------------------------------------------------------------------------------------------------------------

QUESTIONS LINKS ARE IN README.md FILE | Cheak it out and Solve.....

-------------------------------------------------------------------------------------------------------------------- */