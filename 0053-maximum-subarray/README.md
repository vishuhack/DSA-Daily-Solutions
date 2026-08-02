# Maximum Subarray (LeetCode 53)

## Problem

Given an integer array `nums`, find the **contiguous subarray** with the largest sum and return its sum.

---

# Pattern Used

## Kadane's Algorithm

Kadane's Algorithm is used to find the **maximum sum of a contiguous subarray** in **linear time**.

Instead of checking every possible subarray, it maintains a running sum and discards it whenever it becomes negative.

---

# How to Recognize This Pattern

Think of **Kadane's Algorithm** whenever you see:

* Contiguous Subarray
* Maximum Sum
* Minimum Sum (variation)
* Continuous Segment
* O(n) solution expected

### Keywords

```text
Maximum Subarray
Largest Sum
Maximum Contiguous Sum
Continuous Segment
Maximum Circular Sum
```

---

# When to Use?

Use Kadane when:

* Need the **maximum/minimum contiguous subarray**.
* Brute force is too slow.
* O(n) solution is expected.
* Only one continuous segment needs to be selected.

---

# When NOT to Use?

Do **not** use Kadane when:

* Elements can be skipped (subsequence).
* The subarray is not contiguous.
* The problem requires all possible subarrays.
* Another pattern like Sliding Window or Prefix Sum is more suitable.

---

# Approach 1: Brute Force

## Idea

Generate every possible subarray.

Compute its sum and keep track of the maximum.

### Complexity

* Time: **O(n³)**

If Prefix Sum is used:

* Time: **O(n²)**

---

# Approach 2: Kadane's Algorithm (Optimal)

## Idea

Maintain a running sum.

* Add the current element.
* Update the answer.
* If the running sum becomes negative, discard it.
* Start a new subarray from the next element.

---

# Core Idea

A negative running sum will always decrease the sum of any future subarray.

Therefore,

```text
If currentSum < 0
        ↓
Discard it
        ↓
Start a new subarray
```

---

# Why Does It Work?

Suppose the running sum is:

```text
-10
```

Next element is:

```text
20
```

Two choices:

```text
-10 + 20 = 10

or

20
```

Starting fresh gives a larger sum.

Therefore, carrying a negative running sum is never beneficial.

---

# Dry Run

Input

```text
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

| Element | Running Sum | Maximum Sum |
| ------- | ----------: | ----------: |
| -2      |          -2 |          -2 |
| 1       |           1 |           1 |
| -3      |  -2 → Reset |           1 |
| 4       |           4 |           4 |
| -1      |           3 |           4 |
| 2       |           5 |           5 |
| 1       |           6 |           6 |
| -5      |           1 |           6 |
| 4       |           5 |           6 |

Maximum Sum = **6**

Subarray:

```text
[4, -1, 2, 1]
```

---

# Complexity Comparison

| Approach           | Time  | Space  |
| ------------------ | ----- | ------ |
| Brute Force        | O(n³) | O(1)   |
| Prefix Sum         | O(n²) | O(n)   |
| Kadane's Algorithm | O(n)  | O(1) ✅ |

---

# Pattern Summary

```text
Contiguous Subarray
        ↓
Need Maximum / Minimum Sum
        ↓
Need O(n)
        ↓
Kadane's Algorithm
        ↓
Maintain Running Sum
        ↓
Negative Sum?
        ↓
Reset to Zero
```

---

# Related Problems

### Easy

* LeetCode 53 – Maximum Subarray

### Medium

* LeetCode 918 – Maximum Sum Circular Subarray
* LeetCode 152 – Maximum Product Subarray
* Best Time to Buy and Sell Stock (Kadane Concept)

### Hard

* Maximum Sum Rectangle in a 2D Matrix
* Flip Bits Problem
* Largest Variance in a String

---

# Interview Trigger

Whenever you read:

* Contiguous Subarray
* Maximum Sum
* Minimum Sum
* O(n) solution required

👉 Think **Kadane's Algorithm**.

---

# Quick Revision

```text
Pattern : Kadane's Algorithm

Recognition:
✓ Contiguous Subarray
✓ Maximum / Minimum Sum
✓ Linear Time

Core Idea:
If the running sum becomes negative,
discard it and start a new subarray.

Time  : O(n)
Space : O(1)
```

---

# One-Line Memory Trick

> **"If my past sum hurts my future, I leave the past and begin again."**
