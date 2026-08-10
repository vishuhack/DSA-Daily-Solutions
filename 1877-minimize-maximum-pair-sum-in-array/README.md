# Minimize Maximum Pair Sum in Array

## Problem

Given an array `nums` of even length, divide all elements into pairs such that:

* Every element is used exactly once.
* For every pair `(a, b)`, its pair sum is `a + b`.
* Among all the pair sums, find the maximum pair sum.
* We need to arrange the pairs so that this maximum value is as small as possible.

---

## Intuition

The main idea is:

> **The largest element is the biggest threat to creating the maximum pair sum.**

Since the largest element must be paired with some other element, whatever number we add to it will create a relatively large pair sum.

Therefore, to keep this sum as small as possible, we should pair the **largest element with the smallest element**.

### Why Do We Sort?

Sorting allows us to easily identify:

* The smallest remaining element.
* The largest remaining element.

For example:

`[3, 5, 4, 2, 4, 6]`

After sorting:

`[2, 3, 4, 4, 5, 6]`

Now consider the largest element `6`.

If we pair it with:

* `6 + 5 = 11`
* `6 + 4 = 10`
* `6 + 3 = 9`
* `6 + 2 = 8`

Since `6` is already the largest number, pairing it with another large number would make the pair sum unnecessarily large.

So the best choice is:

`6 + 2 = 8`

After using `2` and `6`, consider the next largest element `5`.

Pair it with the next smallest available element:

`5 + 3 = 8`

Finally:

`4 + 4 = 8`

Therefore, the pairs are:

`(2, 6), (3, 5), (4, 4)`

Their sums are:

`8, 8, 8`

Maximum pair sum = `8`.

---

## Greedy Idea

After sorting, always pair:

**Smallest + Largest**

Then:

**Second Smallest + Second Largest**

Then continue moving toward the center.

This balances the pair sums.

If we instead pair:

**Largest + Another Large Element**

we may create a very large pair sum, which is exactly what we are trying to avoid.

So pairing the largest available element with the smallest available element helps control the maximum pair sum.

---

## Two-Pointer Approach

After sorting the array:

* Keep `l` at the beginning of the array.
* Keep `r` at the end of the array.
* `nums[l]` is the smallest remaining element.
* `nums[r]` is the largest remaining element.
* Pair `nums[l]` with `nums[r]`.
* Calculate their pair sum.
* Keep track of the maximum pair sum.
* Move `l` forward and `r` backward.
* Continue until all elements have been paired.

---

## Example

Input:

`nums = [3, 5, 2, 3]`

After sorting:

`[2, 3, 3, 5]`

Pair smallest with largest:

`2 + 5 = 7`

Move both pointers inward:

`3 + 3 = 6`

Pair sums:

`7, 6`

Maximum pair sum:

`max(7, 6) = 7`

Therefore, the answer is:

`7`

---

## Why Does This Work?

Suppose the largest element is `x`.

It must be paired with some element.

Since our goal is to minimize the maximum pair sum, we want the pair containing `x` to be as small as possible.

The smallest available element gives the smallest possible sum with `x`.

Therefore:

**Largest + Smallest**

is the safest pairing for controlling the maximum pair sum.

We repeat the same idea for the remaining elements.

---

## Pattern Recognition

When a problem asks to:

* Form pairs from an array.
* Use every element exactly once.
* Minimize the maximum pair sum.

Think of:

**Sorting + Greedy + Two Pointers**

Key intuition:

> **Pair the largest element with the smallest element because the largest element can create the maximum pair sum. Pairing it with the smallest available element keeps that sum under control.**

---

## Complexity

**Time Complexity:** `O(n log n)`

Sorting takes `O(n log n)`, while the two-pointer traversal takes `O(n)`.

Overall:

`O(n log n)`

**Space Complexity:** `O(1)` auxiliary space, ignoring the internal space used by the sorting implementation.
