# Count Subarrays With Sum Zero

## 📁 Folder Path

```text
DSA-Zero-to-Knight/03-Hashing/18-Count-Subarrays-With-Sum-Zero/
```

## 🧩 Problem Statement

Given an integer array, count the total number of contiguous subarrays whose sum is equal to `0`.

A subarray must contain consecutive elements from the original array.

## Example

### Input

```cpp
{1, -1, 2, -2}
```

### Valid Subarrays

```text
[1, -1]          → 0
[2, -2]          → 0
[1, -1, 2, -2]   → 0
```

### Output

```text
3
```

---

## 💡 Core Idea

Use **prefix sum + hashing**.

If the same prefix sum appears more than once, the elements between those two positions have sum `0`.

For example:

```text
Prefix sums:
0, 1, 0, 2, 0
```

Every repeated prefix sum creates new zero-sum subarrays.

---

## 🧠 Why Store Frequency?

For this problem, we need to count **all possible subarrays**.

Therefore, store:

```text
prefixSum → frequency
```

If the current prefix sum has already appeared `k` times, then it creates `k` new zero-sum subarrays.

---

## ✅ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

long long countSubarraysWithSumZero(const vector<int>& arr) {
    unordered_map<int, int> freq;

    long long countOfSubarray = 0;
    int prefixSum = 0;

    freq[0] = 1;

    for (int x : arr) {
        prefixSum += x;

        countOfSubarray += freq[prefixSum];

        freq[prefixSum]++;
    }

    return countOfSubarray;
}

int main() {
    vector<int> arr = {0, 0, 0};

    cout << countSubarraysWithSumZero(arr);

    return 0;
}
```

### Output

```text
6
```

---

## 🔍 Dry Run

Input:

```cpp
{0, 0, 0}
```

Initial state:

```text
freq[0] = 1
answer = 0
```

| Element | Prefix Sum | Previous Frequency | New Subarrays | Answer |
| ------- | ---------: | -----------------: | ------------: | -----: |
| `0`     |        `0` |                `1` |           `1` |    `1` |
| `0`     |        `0` |                `2` |           `2` |    `3` |
| `0`     |        `0` |                `3` |           `3` |    `6` |

The six valid subarrays are:

```text
[0]
[0]
[0]
[0, 0]
[0, 0]
[0, 0, 0]
```

---

## ⏱️ Complexity

* Average Time: **O(n)**
* Space: **O(n)**

---

## ⚠️ Important Details

### Why initialize `freq[0] = 1`?

This represents the empty prefix before the array starts.

It allows us to count subarrays beginning at index `0`.

### Why use `long long`?

The number of subarrays can be as large as:

```text
n * (n + 1) / 2
```

For a large array, this may exceed the range of `int`.

---

## 🔑 Pattern

```text
Count subarrays
    ↓
Prefix sum
    ↓
Repeated prefix sum
    ↓
Store frequency
```

### Key Rule

> **Counting valid subarrays → store prefix-sum frequency.**
