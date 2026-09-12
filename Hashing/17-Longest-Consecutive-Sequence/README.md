# Longest Consecutive Sequence

## 📁 Folder Path

```text
DSA-Zero-to-Knight/03-Hashing/17-Longest-Consecutive-Sequence/
```

## 🧩 Problem Statement

Given an unsorted array of integers, find the length of the longest sequence of consecutive numbers.

The array may contain duplicate values.

### Example 1

**Input:**

```cpp
{100, 4, 200, 1, 3, 2}
```

**Output:**

```text
4
```

**Explanation:**

The longest consecutive sequence is:

```text
1, 2, 3, 4
```

Its length is `4`.

### Example 2

**Input:**

```cpp
{9, 1, 4, 7, 3, 2, 6, 8}
```

**Output:**

```text
4
```

One longest consecutive sequence is:

```text
1, 2, 3, 4
```

Another is:

```text
6, 7, 8, 9
```

### Example 3

**Input:**

```cpp
{1, 2, 2, 3}
```

**Output:**

```text
3
```

Duplicates do not increase the length.

---

## 🎯 Objective

Find the longest consecutive sequence in the array with:

* Average time complexity of **O(n)**
* Auxiliary space complexity of **O(n)**

---

## 💡 Key Idea

Use an `unordered_set` to store all numbers.

For every number `x`, check whether:

```cpp
x - 1
```

exists in the set.

### Case 1: `x - 1` exists

Then `x` is not the beginning of a sequence.

Skip it.

### Case 2: `x - 1` does not exist

Then `x` is the beginning of a consecutive sequence.

Start counting:

```text
x, x + 1, x + 2, x + 3, ...
```

Continue while the next number exists in the set.

---

## 🧠 Why Do We Check `x - 1`?

Consider:

```text
1, 2, 3, 4
```

If we start counting from every number:

* Starting from `1` → count `1,2,3,4`
* Starting from `2` → count `2,3,4`
* Starting from `3` → count `3,4`
* Starting from `4` → count `4`

This repeats unnecessary work.

Instead, we only start from `1` because:

```text
0 does not exist
```

For `2`, `1` exists, so `2` is not a starting point.

This prevents repeated counting.

---

## ✅ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(const vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    unordered_set<int> s;

    // Store all numbers for O(1) average lookup
    for (int x : arr) {
        s.insert(x);
    }

    int maxLength = 0;

    for (int x : arr) {
        // x is the beginning of a sequence
        if (s.find(x - 1) == s.end()) {
            int current = x;
            int length = 1;

            // Count consecutive numbers
            while (s.find(current + 1) != s.end()) {
                current++;
                length++;
            }

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutiveSequence(arr) << endl;

    return 0;
}
```

### Output

```text
4
```

---

## 🔍 Dry Run

Input:

```cpp
{100, 4, 200, 1, 3, 2}
```

Set:

```text
{100, 4, 200, 1, 3, 2}
```

| Number | Is `x - 1` present? | Action                      |
| ------ | ------------------: | --------------------------- |
| `100`  |                  No | Start sequence, length = 1  |
| `4`    |     Yes, `3` exists | Skip                        |
| `200`  |                  No | Start sequence, length = 1  |
| `1`    |      No, `0` absent | Count `1,2,3,4`, length = 4 |
| `3`    |     Yes, `2` exists | Skip                        |
| `2`    |     Yes, `1` exists | Skip                        |

Final answer:

```text
4
```

---

## ⚠️ Important Edge Cases

### Empty array

```cpp
{}
```

Output:

```text
0
```

### Single element

```cpp
{7}
```

Output:

```text
1
```

### All duplicates

```cpp
{5, 5, 5, 5}
```

Output:

```text
1
```

### Already consecutive

```cpp
{1, 2, 3, 4, 5}
```

Output:

```text
5
```

### Negative numbers

```cpp
{-3, -2, -1, 0, 1}
```

Output:

```text
5
```

---

## ⏱️ Complexity Analysis

Let `n` be the number of elements in the array.

### Time Complexity

* Inserting all elements into the set: average **O(n)**
* Checking sequence starts: average **O(n)**
* Expanding sequences: average **O(n)** overall

Therefore:

```text
Average Time: O(n)
```

### Space Complexity

The set stores up to `n` distinct numbers:

```text
Space: O(n)
```

---

## 🧠 Pattern Recognition

This problem teaches the pattern:

```text
Hashing
    ↓
Detect sequence starting point
    ↓
Expand forward
    ↓
Track maximum length
```

### Recognition Rule

Whenever a problem asks for:

* Longest consecutive numbers
* Unsorted array
* Fast existence checking
* No need to preserve order

Think:

```cpp
unordered_set
```

---

## 🔁 Alternative Approach

### Sorting

We can also solve the problem by:

1. Sorting the array.
2. Traversing it.
3. Counting consecutive numbers.

But sorting takes:

```text
O(n log n)
```

The hashing solution improves the average time to:

```text
O(n)
```

Therefore, hashing is the preferred solution when average O(n) time is expected.

---

## 🏆 Key Takeaway

> Do not start counting from every number.
> Start counting only when `x - 1` is absent.

That single observation converts a repeated-search problem into an efficient hashing solution.
