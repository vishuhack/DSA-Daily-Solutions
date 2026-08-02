# Search in Rotated Sorted Array (LeetCode 33)

## Problem

Given a rotated sorted array `nums` and an integer `target`, return the index of the target.

If the target does not exist, return `-1`.

The required time complexity is **O(log n)**.

---

# Pattern Used

## Binary Search on Rotated Sorted Array

This is a modified Binary Search.

Instead of finding the pivot, we identify **which half of the array is sorted** in every iteration and decide where to continue the search.

---

# How to Recognize This Pattern

Think of this pattern whenever you see:

* Sorted array
* Rotated array
* Search an element
* O(log n) expected

### Keywords

```text
Rotated Sorted Array
Search
Binary Search
Pivot
Sorted Half
```

---

# Recognition Trick

```text
Sorted Array
      +
Rotated
      +
Search Element
      +
O(log n)

↓

Binary Search on Rotated Array
```

---

# Approach 1: Linear Search

## Idea

Traverse the array and compare every element with the target.

### Complexity

* Time: `O(n)`
* Space: `O(1)`

---

# Approach 2: Modified Binary Search (Optimal)

## Idea

In every iteration:

* One half of the array is always sorted.
* Identify the sorted half.
* Check whether the target belongs to that half.
* Continue searching only in the correct half.

---

# Core Idea

Every rotated sorted array has:

```text
One Sorted Half
+
One Unsorted Half
```

The goal is **not** to find the pivot.

Instead:

1. Find the sorted half.
2. Decide whether the target belongs to that half.
3. Continue Binary Search.

---

# Algorithm

### Step 1

Find the middle element.

```text
mid = (low + high) / 2
```

---

### Step 2

Check which half is sorted.

```text
nums[low] <= nums[mid]

↓

Left Half is Sorted
```

Otherwise,

```text
Right Half is Sorted
```

---

### Step 3

If the left half is sorted:

```text
Target ∈ [nums[low], nums[mid])

↓

YES → Search Left

NO → Search Right
```

---

### Step 4

If the right half is sorted:

```text
Target ∈ (nums[mid], nums[high]]

↓

YES → Search Right

NO → Search Left
```

Repeat until the target is found or the search space becomes empty.

---

# Dry Run

## Input

```text
nums = [4,5,6,7,0,1,2]

target = 0
```

### Iteration 1

```text
low = 0
mid = 3
high = 6

nums[mid] = 7
```

Left half:

```text
4 5 6 7
```

is sorted.

Target:

```text
0
```

does not belong to this range.

Search the right half.

---

### Iteration 2

```text
low = 4
mid = 5
high = 6

nums[mid] = 1
```

Left half:

```text
0 1
```

is sorted.

Target belongs to this range.

Search left.

---

### Iteration 3

```text
mid = 4

nums[mid] = 0
```

Target found.

Answer:

```text
4
```

---

# Why Does This Work?

A rotated sorted array is formed by rotating a sorted array.

Although the whole array is no longer sorted, **at least one half is always sorted**.

By identifying the sorted half and checking whether the target belongs there, we eliminate half of the search space every iteration.

Therefore, Binary Search still works.

---

# Edge Cases

## Case 1: Target Exists

```text
nums = [4,5,6,7,0,1,2]

target = 0

Answer = 4
```

---

## Case 2: Target Does Not Exist

```text
nums = [4,5,6,7,0,1,2]

target = 3

Answer = -1
```

---

## Case 3: Array Is Not Rotated

```text
nums = [1,2,3,4,5]

target = 4

Answer = 3
```

The algorithm still works because the left half is always sorted.

---

## Case 4: Single Element

```text
nums = [5]

target = 5

Answer = 0
```

```text
nums = [5]

target = 2

Answer = -1
```

---

## Case 5: Target Is the Pivot Element

```text
nums = [6,7,8,1,2,3,4]

target = 1

Answer = 3
```

The algorithm correctly identifies the sorted half and eventually reaches the pivot.

---

# Complexity

| Approach               | Time     | Space  |
| ---------------------- | -------- | ------ |
| Linear Search          | O(n)     | O(1)   |
| Modified Binary Search | O(log n) | O(1) ✅ |

---

# Pattern Summary

```text
Rotated Sorted Array
        ↓
Search Target
        ↓
Find the Sorted Half
        ↓
Does Target Belong There?
        ↓
YES → Search There
NO → Search Other Half
```

---

# Quick Revision

```text
Pattern:
Binary Search on Rotated Sorted Array

Recognition:
✓ Rotated Sorted Array
✓ Search Element
✓ O(log n)

Core Idea:
One half is always sorted.

Steps:
1. Find the sorted half.
2. Check if the target belongs to it.
3. Search that half.
4. Otherwise, search the other half.

Time : O(log n)

Space : O(1)
```

---

# Memory Trick

```text
Don't Find the Pivot

↓

Find the Sorted Half

↓

Check Where the Target Belongs

↓

Discard the Other Half
```

---

# Interview Trigger

Whenever you see:

* Rotated Sorted Array
* Search an element
* O(log n)
* No duplicate elements

👉 Think **Modified Binary Search (Find the Sorted Half)**.
