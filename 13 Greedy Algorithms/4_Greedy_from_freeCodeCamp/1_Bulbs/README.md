# Bulbs

**Difficulty:** Medium

## Problem Statement

Given an array `A` of `N` bulbs, where each bulb is either on (`1`) or off (`0`).

When you turn on the `i`th bulb, it causes all the remaining bulbs on its right to flip (on becomes off, off becomes on).

Find the minimum number of switches required to turn all the bulbs on.

## Examples

### Example 1

```
Input: A = [0, 1, 0, 1]
Output: 4
Explanation:
Switch bulb 1: [1, 0, 1, 0]
Switch bulb 2: [1, 1, 0, 1]
Switch bulb 3: [1, 1, 1, 0]
Switch bulb 4: [1, 1, 1, 1]
```

### Example 2

```
Input: A = [0, 1, 1, 1]
Output: 2
Explanation:
Switch bulb 1: [1, 0, 0, 0]
Switch bulb 2: [1, 1, 1, 1]
```

### Example 3

```
Input: A = [1, 1, 1]
Output: 0
Explanation: All bulbs are already on.
```

## Constraints

- `1 <= N <= 10^5`
- `A[i]` is either `0` or `1`
