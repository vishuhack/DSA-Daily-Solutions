# Find Minimum in Rotated Sorted Array (LeetCode 153)

## Problem

Given a rotated sorted array containing **unique elements**, return the minimum element.

The solution should run in **O(log n)** time.

---

# Pattern Used

## Binary Search on Rotated Sorted Array

Instead of finding the pivot directly, identify the sorted half and keep track of the smallest element from that half.

---

# How to Recognize This Pattern

Think of this pattern when:

* The array is sorted and rotated.
* Need the minimum (or pivot) element.
* O(log n) solution is expected.
* No duplicate elements.

### Keywords

```text
Rotated Sorted Array
Minimum Element
Pivot
Binary Search
Unique Elements
```

---

# Recognition Trick

```text
Sorted Array
      +
Rotated
      +
Find Minimum
      +
O(log n)

↓

Binary Search
```

---

# Approach 1: Linear Search

## Idea

Traverse the entire array and return the smallest element.

### Complexity

* Time: **O(n)**
* Space: **O(1)**

---

# Approach 2: Binary Search (Optimal)

## Idea

At every iteration:

* One half is always sorted.
* The smallest element of a sorted half is its **first element**.
* Compare that element with the current answer.
* Search in the unsorted half because the rotation (and minimum) must lie there.

---

# Core Idea

Suppose:

```text
4 5 6 7 | 0 1 2
```

The left half:

```text
4 5 6 7
```

is sorted.

Its minimum is:

```text
4
```

Since the overall minimum could still be in the other half (`0`), we store `4` and continue searching the right half.

Similarly, if the right half is sorted:

```text
0 1 2
```

its minimum is always:

```text
0
```

---

# Important Observation

### If Left Half is Sorted

```text
nums[low] <= nums[mid]
```

Minimum of this half:

```text
nums[low]
```

Search the right half.

---

### Otherwise

The right half is sorted.

Minimum of this half:

```text
nums[mid]
```

Search the left half.

---

# Algorithm

```text
Find Mid
      ↓
Is Left Half Sorted?
      ↓
YES
      ↓
Answer = min(answer, nums[low])
Search Right
------------------------
NO
      ↓
Answer = min(answer, nums[mid])
Search Left
```

---

# Dry Run

## Input

```text
nums = [4,5,6,7,0,1,2]
```

### Iteration 1

```text
low = 0
mid = 3
high = 6
```

Left half:

```text
4 5 6 7
```

Sorted.

Minimum of this half:

```text
4
```

Store:

```text
answer = 4
```

Search right.

---

### Iteration 2

```text
low = 4
mid = 5
high = 6
```

Left half:

```text
0 1
```

Sorted.

Minimum:

```text
0
```

Store:

```text
answer = 0
```

Search right.

---

### Iteration 3

```text
low = 6
mid = 6
high = 6
```

Minimum remains:

```text
0
```

Final Answer:

```text
0
```

---

# Why Does It Work?

Every rotated sorted array always has one sorted half.

The first element of a sorted half is its minimum.

Store that value and continue searching the unsorted half because the rotation point (true minimum) can only exist there.

Eventually, the global minimum is found.

---

# Edge Cases

## Array Not Rotated

```text
nums = [1,2,3,4,5]
```

Answer:

```text
1
```

---

## Rotated Once

```text
nums = [5,1,2,3,4]
```

Answer:

```text
1
```

---

## Single Element

```text
nums = [8]
```

Answer:

```text
8
```

---

## Two Elements

```text
nums = [2,1]
```

Answer:

```text
1
```

---

# Complexity

| Approach      | Time     | Space  |
| ------------- | -------- | ------ |
| Linear Search | O(n)     | O(1)   |
| Binary Search | O(log n) | O(1) ✅ |

---

# Pattern Summary

```text
Rotated Sorted Array
        ↓
Find Minimum
        ↓
Find Sorted Half
        ↓
Store Minimum of Sorted Half
        ↓
Search Unsorted Half
```

---

# Quick Revision

```text
Pattern:
Binary Search on Rotated Sorted Array

Recognition:
✓ Rotated Sorted Array
✓ Find Minimum
✓ O(log n)
✓ Unique Elements

Core Idea:
One half is always sorted.

Minimum of Left Sorted Half  = nums[low]
Minimum of Right Sorted Half = nums[mid]

Store answer and search the unsorted half.

Time  : O(log n)
Space : O(1)
```

---

# Memory Trick

> **Sorted half gives a candidate minimum; unsorted half may hide the actual minimum.**

---

# Interview Trigger

Whenever you see:

* Rotated Sorted Array
* Find Minimum
* O(log n)
* No Duplicates

👉 Think **Binary Search + Find the Sorted Half**.
