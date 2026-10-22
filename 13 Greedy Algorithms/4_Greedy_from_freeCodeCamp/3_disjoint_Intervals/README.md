# Disjoint Intervals

**Difficulty:** Medium

## Problem Statement

Given a list of intervals `[start, end]`.

Find the length of the maximal set of mutually disjoint intervals.

Note: two intervals that share an endpoint (for example `[1, 2]` and `[2, 10]`) are considered overlapping.

## Examples

### Example 1

```
Input: nums = [[1, 2], [2, 10], [4, 6]]
Output: 2
Explanation:
Select [1, 2] and [4, 6].
Selecting [2, 10] will block [1, 2] and [4, 6].
```

### Example 2

```
Input: nums = [[1, 4], [2, 3], [3, 5], [6, 7]]
Output: 2
Explanation:
Select [2, 3] and [6, 7].
[1, 4], [2, 3] and [3, 5] overlap each other, so only one of them can be chosen.
```

### Example 3

```
Input: nums = [[1, 2], [3, 4], [5, 6]]
Output: 3
Explanation: No two intervals overlap, so all of them are selected.
```

## Constraints

- `1 <= N <= 10^5`
- `1 <= nums[i][0] <= nums[i][1] <= 10^9`