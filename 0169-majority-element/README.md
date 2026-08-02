# Majority Element (LeetCode 169)

## Problem

Given an integer array `nums`, return the element that appears **more than ⌊n/2⌋ times**.

The majority element is guaranteed to exist.

---

# Approaches

## Approach 1: Brute Force

### Idea

For every element, count its frequency by traversing the entire array.

If any element appears more than `n/2` times, return it.

### Algorithm

- Pick one element.
- Count its occurrences in the array.
- If frequency > `n/2`, return it.
- Otherwise, repeat for the next element.

### Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)`

### Why?

For every element (`n`), we again traverse the entire array (`n`).

```
n × n = O(n²)
```

---

## Approach 2: Hash Map (Better)

### Idea

Store the frequency of every element using a hash map.

After counting, find the element whose frequency is greater than `n/2`.

### Algorithm

1. Traverse the array.
2. Store frequency in an unordered_map.
3. Traverse the map.
4. Return the element having frequency > `n/2`.

### Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

### Why?

- One traversal to build the map.
- One traversal over the stored frequencies.

---

## Approach 3: Boyer-Moore Voting Algorithm (Optimal)

### Idea

Instead of storing frequencies, we eliminate (cancel) different elements.

The majority element appears more than half of the array, so it can never be completely cancelled.

Finally, the remaining element becomes the majority candidate.

---

## How to Recognize this Pattern

Use Boyer-Moore when:

- Frequency > `n/2`
- Majority element is guaranteed to exist
- O(n) time is expected
- O(1) extra space is expected

Keywords:

- Majority Element
- More than half
- Dominant element
- Frequency > n/2

---

## Core Idea

Think of every element as a vote.

- Same element → Vote increases.
- Different element → Vote decreases.

Different elements cancel each other.

Since the majority element occurs more than half the time, it always survives the cancellation process.

---

## Algorithm

### First Pass

Find a possible majority candidate.

```
If count == 0
    candidate = current element

If current == candidate
    count++

Else
    count--
```

### Second Pass (Optional)

Verify whether the candidate actually appears more than `n/2` times.

> **Note:** LeetCode guarantees that the majority element always exists, so this verification step is optional. It is useful in the general case where no majority element may exist.

---

## Dry Run

Input

```
nums = [2,2,1,1,1,2,2]
```

| Element | Candidate | Count |
|---------|-----------|------:|
|2|2|1|
|2|2|2|
|1|2|1|
|1|2|0|
|1|1|1|
|2|1|0|
|2|2|1|

Final Candidate = **2**

Verification:

```
Frequency of 2 = 4

n = 7

n/2 = 3

4 > 3

Answer = 2
```

---

## Why does this work?

Every non-majority element removes one vote from the majority element.

Since the majority element appears more than `n/2` times, it always has extra votes remaining after all cancellations.

Therefore, it becomes the final candidate.

---

# Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Hash Map | O(n) | O(n) |
| Boyer-Moore Voting | O(n) | O(1) ✅ |

---

# Pattern Summary

```
Frequency > n/2
        ↓
Need O(1) Space?
        ↓
YES
        ↓
Boyer-Moore Voting Algorithm
        ↓
Keep Candidate + Count
        ↓
Cancel Different Elements
        ↓
Majority Element Survives
```

---

# Interview Tip

Whenever you see:

- Majority Element
- Appears more than half the time
- Frequency > `n/2`
- O(1) space requirement

👉 Immediately think **Boyer-Moore Voting Algorithm**.
