# Search in Rotated Sorted Array II

## Problem

Given a rotated sorted array `arr` that may contain duplicate elements and an integer `k`, return `true` if the target exists.

Otherwise, return `false`.

---

# Pattern Used

## Modified Binary Search on Rotated Sorted Array

This is similar to searching in a rotated sorted array without duplicates.

The main difference is that duplicate values can make it difficult to identify which half of the array is sorted.

---

# How to Recognize This Pattern

Think of this pattern when:

* The array was originally sorted.
* The array has been rotated.
* Duplicate elements are allowed.
* We need to search for a target.
* Better than linear search is expected.

### Keywords

```text
Rotated Sorted Array
Duplicate Elements
Search Target
Modified Binary Search
Sorted Half
```

---

# Approach 1: Linear Search

## Idea

Traverse the complete array and check whether any element is equal to the target.

## Complexity

* Time: `O(n)`
* Space: `O(1)`

---

# Approach 2: Modified Binary Search

## Idea

At every step:

1. Check whether the middle element is the target.
2. Handle the duplicate-value condition.
3. Identify which half is sorted.
4. Check whether the target lies inside that sorted half.
5. Discard the other half.

---

# Core Observation

In a rotated sorted array without duplicates, at least one half can be identified as sorted.

But duplicates can create ambiguity.

Example:

```text
arr = [1, 0, 1, 1, 1]
```

Suppose:

```text
arr[low]  = 1
arr[mid]  = 1
arr[high] = 1
```

Now both ends and the middle have the same value.

Because of this, we cannot clearly determine whether the left half or the right half is sorted.

---

# Important Duplicate Condition

```text
arr[low] == arr[mid] == arr[high]
```

When this condition is true:

```text
low++
high--
```

We remove one duplicate element from both ends and continue searching.

---

# Why Is This Condition Needed?

Consider:

```text
arr = [1, 0, 1, 1, 1]
```

At one stage:

```text
low value  = 1
mid value  = 1
high value = 1
```

The condition:

```text
arr[low] <= arr[mid]
```

becomes true.

This may incorrectly suggest that the complete left half is sorted.

But the left part may actually contain the rotation point:

```text
[1, 0, 1]
```

Therefore, duplicate values hide the sorted half.

We first shrink the search space:

```text
low++
high--
```

After removing duplicate boundary values, we may get enough information to identify the sorted half.

---

# Why Is Shrinking Safe?

Before shrinking, we already check:

```text
arr[mid] == k
```

If the common duplicate value is the target, the function returns `true`.

If it is not the target, removing one copy from each boundary does not remove the target because all three checked values are equal and are not the target.

Therefore, shrinking both ends is safe.

---

# Memory Trick

```text
Duplicates hide the sorted half
            ↓
low == mid == high
            ↓
Shrink both ends
            ↓
Continue Binary Search
```

---

# Binary Search Logic

## Case 1: Left Half Is Sorted

The left half is sorted when:

```text
arr[low] <= arr[mid]
```

Check whether the target lies in:

```text
[arr[low], arr[mid])
```

If yes:

```text
Search left
```

Otherwise:

```text
Search right
```

---

## Case 2: Right Half Is Sorted

Otherwise, the right half is sorted.

Check whether the target lies in:

```text
(arr[mid], arr[high]]
```

If yes:

```text
Search right
```

Otherwise:

```text
Search left
```

---

# Algorithm Flow

```text
Check mid
    ↓
Target found?
    ↓
Yes → Return true
    ↓
No
    ↓
low == mid == high?
    ↓
Yes → low++, high--
    ↓
No
    ↓
Which half is sorted?
    ↓
Does target lie there?
    ↓
Yes → Search that half
No  → Search the other half
```

---

# Dry Run

## Input

```text
arr = [2, 5, 6, 0, 0, 1, 2]
k = 0
```

### Iteration 1

```text
low = 0
mid = 3
high = 6

arr[mid] = 0
```

Target found.

```text
Answer = true
```

---

# Duplicate Ambiguity Example

## Input

```text
arr = [1, 0, 1, 1, 1]
k = 0
```

Initially:

```text
low = 0
mid = 2
high = 4

arr[low] = 1
arr[mid] = 1
arr[high] = 1
```

All three values are equal.

We cannot identify the sorted half.

Therefore:

```text
low++
high--
```

Now the search range becomes smaller:

```text
[0, 1, 1]
```

The algorithm can then continue and find `0`.

---

# Edge Cases

## Target Exists

```text
arr = [2, 5, 6, 0, 0, 1, 2]
k = 0

Answer = true
```

---

## Target Does Not Exist

```text
arr = [2, 5, 6, 0, 0, 1, 2]
k = 3

Answer = false
```

---

## All Elements Are Equal

```text
arr = [1, 1, 1, 1, 1]
k = 1

Answer = true
```

```text
arr = [1, 1, 1, 1, 1]
k = 2

Answer = false
```

---

## Single Element

```text
arr = [5]
k = 5

Answer = true
```

```text
arr = [5]
k = 2

Answer = false
```

---

## Array Is Not Rotated

```text
arr = [1, 2, 2, 3, 4]
k = 3

Answer = true
```

The algorithm works even when the array is not rotated.

---

# Complexity

## Average Case

* Time: `O(log n)`
* Space: `O(1)`

## Worst Case

* Time: `O(n)`
* Space: `O(1)`

---

# Why Can the Worst Case Become O(n)?

Consider:

```text
arr = [1, 1, 1, 1, 1, 1, 2, 1]
```

Many times:

```text
arr[low] == arr[mid] == arr[high]
```

The algorithm can only shrink the range by:

```text
low++
high--
```

Instead of eliminating half of the array, it removes only a small number of elements.

Therefore, in the worst case, the time complexity becomes `O(n)`.

---

# Rotated Sorted Array I vs II

| Problem                 | Duplicates  | Time Complexity                  |
| ----------------------- | ----------- | -------------------------------- |
| Rotated Sorted Array I  | Not allowed | `O(log n)`                       |
| Rotated Sorted Array II | Allowed     | Average `O(log n)`, worst `O(n)` |

---

# Pattern Summary

```text
Rotated Sorted Array
        +
Duplicates Allowed
        +
Search Target
        ↓
Modified Binary Search
        ↓
If low == mid == high
        ↓
Shrink both ends
        ↓
Find sorted half
        ↓
Search the correct half
```

---

# Quick Revision

```text
Pattern:
Modified Binary Search on Rotated Array

Recognition:
✓ Sorted and rotated array
✓ Duplicate elements
✓ Search target

Special Condition:
If arr[low] == arr[mid] == arr[high]
→ low++
→ high--

Reason:
Duplicates make it impossible to identify
which half is sorted.

Complexity:
Average Time → O(log n)
Worst Time   → O(n)
Space        → O(1)
```

---

# One-Line Memory Trick

> When duplicates hide the sorted half, shrink both ends and continue.
