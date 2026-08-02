# Find First and Last Position of Element in Sorted Array

## Problem

Given a sorted integer array `nums` and an integer `target`, find the starting and ending positions of the target.

If the target is not present, return:

```text
[-1, -1]
```

The required time complexity is `O(log n)`.

---

# Pattern Used

## Lower Bound and Upper Bound

This problem can be solved using binary search twice:

* Lower Bound finds the first occurrence.
* Upper Bound helps find the last occurrence.

---

# How to Recognize This Pattern

Think of Lower Bound and Upper Bound when:

* The array is sorted.
* Duplicate elements may exist.
* The problem asks for the first occurrence.
* The problem asks for the last occurrence.
* `O(log n)` time is required.

### Keywords

```text
Sorted Array
First Occurrence
Last Occurrence
Starting Position
Ending Position
Lower Bound
Upper Bound
```

---

# Important Definitions

## Lower Bound

Lower Bound is the first index where:

```text
nums[index] >= target
```

It tells us where the target is present or where it should be inserted.

---

## Upper Bound

Upper Bound is the first index where:

```text
nums[index] > target
```

Therefore, the last occurrence of the target is:

```text
upperBound(target) - 1
```

---

# Main Formula

```text
First Position = Lower Bound

Last Position = Upper Bound - 1
```

---

# Approach 1: Linear Search

## Idea

Traverse the complete array.

* Record the first index where the target appears.
* Continue traversing and update the last index.

## Complexity

* Time: `O(n)`
* Space: `O(1)`

This approach does not use the fact that the array is sorted.

---

# Approach 2: Binary Search for First and Last Occurrence

## Idea

Use binary search twice:

1. Search for the first occurrence.
2. Search for the last occurrence.

Whenever the target is found:

* For first occurrence, continue searching left.
* For last occurrence, continue searching right.

## Complexity

* Time: `O(log n)`
* Space: `O(1)`

---

# Approach 3: Lower Bound and Upper Bound

## Idea

Find:

```text
lowerBound = first index where value >= target

upperBound = first index where value > target
```

Then:

```text
First occurrence = lowerBound

Last occurrence = upperBound - 1
```

Before returning the answer, verify that the target actually exists.

---

# Target Existence Condition

The important condition is:

```text
firstPosition == nums.size()
OR
nums[firstPosition] != target
```

If either condition is true, the target does not exist.

---

# Why Does This Condition Handle All Cases?

## Case 1: Target Exists

```text
nums = [1, 2, 3, 3, 3, 5]
target = 3
```

Lower Bound:

```text
firstPosition = 2
nums[2] = 3
```

Condition:

```text
firstPosition == nums.size() → False
nums[firstPosition] != target → False
```

Therefore, the target exists.

Upper Bound of `3` is index `5`.

```text
Last Position = 5 - 1 = 4
```

Answer:

```text
[2, 4]
```

---

## Case 2: Target Is Smaller Than Every Element

```text
nums = [5, 6, 7]
target = 2
```

Lower Bound is index `0` because:

```text
nums[0] = 5 >= 2
```

But:

```text
nums[0] != 2
```

Therefore, the target is absent.

Answer:

```text
[-1, -1]
```

---

## Case 3: Target Is Larger Than Every Element

```text
nums = [1, 2, 3]
target = 10
```

There is no element greater than or equal to `10`.

Therefore:

```text
firstPosition = nums.size()
```

The first condition becomes true:

```text
firstPosition == nums.size()
```

Answer:

```text
[-1, -1]
```

---

## Case 4: Target Lies Between Two Elements

```text
nums = [1, 2, 4, 5]
target = 3
```

Lower Bound is index `2` because:

```text
nums[2] = 4 >= 3
```

But:

```text
nums[2] != 3
```

Therefore, the target is not present.

Answer:

```text
[-1, -1]
```

---

## Case 5: Empty Array

```text
nums = []
target = 5
```

Lower Bound returns:

```text
firstPosition = nums.size() = 0
```

Therefore:

```text
firstPosition == nums.size()
```

is true.

Answer:

```text
[-1, -1]
```

---

## Case 6: Only One Element and Target Exists

```text
nums = [5]
target = 5
```

Lower Bound:

```text
0
```

Upper Bound:

```text
1
```

Therefore:

```text
First Position = 0
Last Position = 1 - 1 = 0
```

Answer:

```text
[0, 0]
```

No separate single-element condition is required.

---

## Case 7: Only One Element and Target Does Not Exist

```text
nums = [5]
target = 3
```

Lower Bound:

```text
0
```

But:

```text
nums[0] != 3
```

Therefore:

```text
[-1, -1]
```

---

# Short-Circuit Evaluation

The condition uses the logical OR operator:

```text
firstPosition == nums.size()
OR
nums[firstPosition] != target
```

In C++, `||` uses short-circuit evaluation.

If the first condition is true, the second condition is not checked.

This is important when:

```text
firstPosition == nums.size()
```

because accessing:

```text
nums[firstPosition]
```

would be outside the array.

Short-circuit evaluation prevents that invalid access.

---

# Dry Run

## Input

```text
nums = [5, 7, 7, 8, 8, 10]
target = 8
```

### Lower Bound

First index where value is greater than or equal to `8`:

```text
index = 3
```

### Upper Bound

First index where value is greater than `8`:

```text
index = 5
```

### Final Answer

```text
First Position = 3
Last Position = 5 - 1 = 4
```

Answer:

```text
[3, 4]
```

---

# Complexity Comparison

| Approach                  | Time       | Space  |
| ------------------------- | ---------- | ------ |
| Linear Search             | `O(n)`     | `O(1)` |
| Two Binary Searches       | `O(log n)` | `O(1)` |
| Lower Bound + Upper Bound | `O(log n)` | `O(1)` |

---

# Pattern Summary

```text
Sorted Array
      ↓
Need First and Last Position
      ↓
Find Lower Bound
      ↓
Find Upper Bound
      ↓
Check Whether Target Exists
      ↓
First = Lower Bound
Last = Upper Bound - 1
```

---

# Quick Revision Note

```text
Pattern: Lower Bound and Upper Bound

Lower Bound:
First index where value >= target

Upper Bound:
First index where value > target

First occurrence:
lowerBound(target)

Last occurrence:
upperBound(target) - 1

Target exists only when:
lowerBound < n
and
nums[lowerBound] == target

Time: O(log n)
Space: O(1)
```

---

# Memory Trick

> Lower Bound gives the starting position, and Upper Bound minus one gives the ending position.

---

# Interview Trigger

Whenever you see:

```text
Sorted Array
+
Duplicate Elements
+
First and Last Occurrence
+
O(log n)
```

Think:

```text
Lower Bound + Upper Bound
```
