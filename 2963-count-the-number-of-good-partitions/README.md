# Number of Good Partitions

## Intuition

The main condition of a good partition is:

> The same number should not appear in two different partitions.

So before making a partition, we must know whether every number in the current group has completely finished appearing.

---

## Why do we store the last occurrence?

For every number, store its rightmost index.

Example:

```text
nums = [1, 2, 1, 3, 4]

Last occurrence:

1 -> 2
2 -> 1
3 -> 3
4 -> 4
```

For `1`, the last occurrence is index `2`.

Therefore, if our current group contains `1`, we cannot finish that group before index `2`.

Otherwise, `1` would appear in two different partitions.

For example:

```text
[1] | [2,1,3,4]
```

This is invalid because `1` appears on both sides.

Similarly:

```text
[1,2] | [1,3,4]
```

is also invalid.

So we must at least reach index `2`:

```text
[1,2,1] | [3,4]
```

Now `1` and `2` are completely finished.

---

## Why do we keep `j`?

`j` represents:

```text
the rightmost index where the current group must extend
```

Initially:

```text
j = last occurrence of nums[0]
```

For:

```text
nums = [1,2,1,3,4]
```

we get:

```text
j = last occurrence of 1
j = 2
```

As we move through the array, another element may occur even farther in the array.

Therefore we update:

```text
j = max(j, last occurrence of nums[i])
```

This guarantees that `j` always tells us how far the current group must extend.

---

## Why does `i > j` mean we found a partition?

Suppose:

```text
i = 3
j = 2
```

This means all elements belonging to the previous group had their final occurrence at or before index `2`.

So:

```text
[1,2,1] | [3,4]
          ^
          i = 3
```

The previous group is completely finished.

Therefore, we have found a safe partition boundary.

That is why:

```text
if(i > j)
```

means a new independent group has started.

---

## Why do we multiply the answer by 2?

Whenever we find a valid boundary, we have exactly two choices:

```text
1. Make a partition here
2. Do not make a partition here
```

For example:

```text
[1,2,1] | [3] | [4]
```

There are two safe boundaries.

Let:

```text
A = boundary after [1,2,1]
B = boundary after [3]
```

For boundary `A`:

```text
                 Start
                /     \
             Cut       Don't Cut
```

Now boundary `B` again gives two choices:

```text
                     Start
                   /       \
                Cut A      No Cut A
               /   \        /    \
          Cut B   No B   Cut B   No B
```

So we get:

```text
2 × 2 = 4 possibilities
```

The four good partitions are:

```text
1. [1,2,1,3,4]

2. [1,2,1] | [3,4]

3. [1,2,1,3] | [4]

4. [1,2,1] | [3] | [4]
```

So every new valid boundary doubles the number of possible partitions.

That is why we do:

```text
result = result * 2
```

---

## General Pattern

If there are:

```text
k valid boundaries
```

then every boundary has two choices:

```text
Cut
or
Don't Cut
```

Therefore:

```text
Answer = 2^k
```

Instead of calculating `2^k` separately, we multiply the result by `2` whenever we discover a new boundary.

---

## Example

For:

```text
nums = [1,2,1,3,4]
```

Last occurrences:

```text
1 -> 2
2 -> 1
3 -> 3
4 -> 4
```

Start:

```text
i = 0
j = 2
result = 1
```

Indices `0, 1, 2` belong to the same group.

Then:

```text
i = 3
j = 2
```

Since:

```text
i > j
```

we found one valid boundary.

```text
result = 1 × 2 = 2
```

Then `3` finishes at index `3`.

At:

```text
i = 4
j = 3
```

again:

```text
i > j
```

So another valid boundary is found.

```text
result = 2 × 2 = 4
```

Final answer:

```text
4
```

---

## Complexity

Let `n` be the size of the array.

### Time Complexity

```text
O(n)
```

One traversal stores the last occurrences and another traversal finds the valid boundaries.

### Space Complexity

```text
O(n)
```

The hash map stores the last occurrence of each distinct number.

---

## Key Takeaway

Think of `j` as:

```text
"How far must my current group continue so that none
of its elements appear outside the group?"
```

If:

```text
i <= j
```

the current group is still open.

If:

```text
i > j
```

the previous group is completely closed, so we found a safe boundary.

Every safe boundary gives two choices:

```text
Cut
or
Don't Cut
```

Therefore every new boundary doubles the answer.
