# Majority Element II (LeetCode 229)

## Problem

Given an integer array `nums`, return **all elements** that appear **more than ⌊n/3⌋ times**.

The answer can contain **0, 1, or 2 elements**.

---

# Key Observation

There can be **at most two** majority elements.

### Why?

If three different elements each appeared more than `n/3` times, their total frequency would become greater than `n`, which is impossible.

Therefore,

```text
Frequency > n/3
        ↓
At most 2 majority elements
```

---

# How to Recognize This Pattern

Use **Extended Boyer-Moore Voting Algorithm** when:

* Frequency is greater than `n/3`
* Need **O(n)** time
* Need **O(1)** extra space
* Asked to return **all majority elements**

### Keywords

* Majority Element II
* Frequency > n/3
* More than one-third
* Constant extra space
* Voting Algorithm

---

# Approach 1: Brute Force

### Idea

For every element, count its frequency by traversing the entire array.

If its frequency is greater than `n/3`, include it in the answer.

### Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)`

---

# Approach 2: Hash Map

### Idea

Store the frequency of every element in a hash map.

Traverse the map and return every element whose frequency is greater than `n/3`.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

---

# Approach 3: Extended Boyer-Moore Voting Algorithm (Optimal)

### Idea

Instead of storing frequencies, maintain **two candidates** and their vote counts.

Whenever a new element is different from both candidates, cancel one vote from each candidate.

After the first traversal, only **possible majority candidates** remain.

Finally, verify their actual frequencies.

---

# Why Two Candidates?

For Majority Element-I (`> n/2`):

* At most **1** majority element.

For Majority Element-II (`> n/3`):

* At most **2** majority elements.

General Rule:

```text
Frequency > n/k
        ↓
Maximum possible answers = k - 1
```

---

# Algorithm

### First Pass

Maintain:

* Candidate 1
* Candidate 2
* Count 1
* Count 2

Rules:

* If current element matches Candidate 1 → increase Count 1
* Else if it matches Candidate 2 → increase Count 2
* Else if Count 1 becomes 0 → assign new Candidate 1
* Else if Count 2 becomes 0 → assign new Candidate 2
* Otherwise → decrease both counts

---

### Second Pass

The first pass only gives **possible candidates**.

Count their actual frequencies and return only those appearing **more than n/3 times**.

---

# Dry Run

Input

```text
nums = [1,1,1,3,3,2,2,2]
```

Here,

```text
n = 8

n/3 = 2
```

Candidate after first pass:

```text
Candidate 1 = 1
Candidate 2 = 2
```

Verification:

```text
Frequency of 1 = 3
Frequency of 2 = 3

3 > 2

Answer = [1,2]
```

---

# Why Does It Work?

Every time three different elements meet, one vote from each candidate gets cancelled.

Since an element occurring more than `n/3` times has extra occurrences, it cannot be completely cancelled.

Thus, it survives as one of the final candidates.

---

# Complexity Comparison

| Approach             | Time  | Space  |
| -------------------- | ----- | ------ |
| Brute Force          | O(n²) | O(1)   |
| Hash Map             | O(n)  | O(n)   |
| Extended Boyer-Moore | O(n)  | O(1) ✅ |

---

# Pattern Summary

```text
Frequency > n/3
        ↓
At most 2 candidates
        ↓
Maintain Candidate1 & Candidate2
        ↓
Same candidate → Increase count
Different element → Decrease both counts
Empty count → Select new candidate
        ↓
Verify frequencies
        ↓
Return valid majority elements
```

---

# Interview Trigger

Whenever you see:

* Frequency > `n/3`
* Return all majority elements
* O(1) extra space
* O(n) time

👉 Immediately think **Extended Boyer-Moore Voting Algorithm**.

---

# Quick Revision

```text
Majority Element I
Frequency > n/2
→ One Candidate

Majority Element II
Frequency > n/3
→ Two Candidates

General Rule
Frequency > n/k
→ At most (k-1) Candidates
```
