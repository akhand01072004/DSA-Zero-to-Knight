# Count Subarrays With Sum K

## 📁 Folder Path

```text id="a8r4z1"
DSA-Zero-to-Knight/03-Hashing/20-Subarray-Sum-Equals-K/
```

## 🧩 Problem Statement

Given an integer array and an integer `K`, count the total number of contiguous subarrays whose sum is exactly equal to `K`.

A subarray must contain consecutive elements from the original array.

---

## Example 1

### Input

```cpp id="h1c6p9"
arr = {1, 2, 3}
K = 3
```

### Valid Subarrays

```text id="v5t8s2"
[1, 2] → 3
[3]    → 3
```

### Output

```text id="m8q3x1"
2
```

---

## Example 2

### Input

```cpp id="k2r9v4"
arr = {1, 1, 1}
K = 2
```

### Valid Subarrays

```text id="p3w7n5"
[1, 1]
[1, 1]
```

### Output

```text id="e6y1u8"
2
```

---

## Example 3

### Input

```cpp id="c4z8q2"
arr = {1, -1, 0}
K = 0
```

### Output

```text id="s7m2d9"
4
```

---

## 💡 Core Idea

Use:

```text id="n5k1x7"
Prefix Sum + HashMap
```

Let:

```text id="g8r3p2"
currentPrefixSum = P
previousPrefixSum = X
```

The sum of the subarray between the two prefix sums is:

$$
P - X
$$

We want that sum to be `K`:

$$
P - X = K
$$

Rearranging:

$$
X = P - K
$$

Therefore, for every current prefix sum, we search for:

```cpp id="z4v8m1"
needed = prefixSum - K;
```

---

## 🧠 Why Does `prefixSum - K` Work?

Suppose:

```cpp id="r6q2t9"
arr = {2, 3, 4}
K = 7
```

Prefix sums:

```text id="b7n3x5"
0, 2, 5, 9
```

At the end:

```text id="y1p8k4"
currentPrefixSum = 9
needed = 9 - 7 = 2
```

The previous prefix sum `2` exists.

Therefore:

```text id="d5m9q2"
9 - 2 = 7
```

The subarray is:

```text id="f8r2w6"
[3, 4]
```

Its sum is `7`.

---

## ✅ Solution

```cpp id="j4v8p2"
#include <bits/stdc++.h>
using namespace std;

long long countSubarraysWithSumK(
    const vector<int>& arr,
    int K
) {
    unordered_map<long long, int> freq;

    long long countOfSubarrays = 0;
    long long prefixSum = 0;

    // Empty prefix before the array starts
    freq[0] = 1;

    for (int x : arr) {
        prefixSum += x;

        long long needed = prefixSum - K;

        countOfSubarrays += freq[needed];

        freq[prefixSum]++;
    }

    return countOfSubarrays;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int K = 3;

    cout << countSubarraysWithSumK(arr, K);

    return 0;
}
```

### Output

```text id="t3k8m1"
2
```

---

## 🔍 Dry Run

Input:

```cpp id="u6p2r9"
arr = {1, 2, 3}
K = 3
```

Initial state:

```text id="w8q4n6"
prefixSum = 0
answer = 0
freq[0] = 1
```

| Index | Element | Prefix Sum | Needed | Previous Frequency | Answer |
| ----: | ------: | ---------: | -----: | -----------------: | -----: |
|   `0` |     `1` |        `1` |   `-2` |                `0` |    `0` |
|   `1` |     `2` |        `3` |    `0` |                `1` |    `1` |
|   `2` |     `3` |        `6` |    `3` |                `1` |    `2` |

Valid subarrays:

```text id="n3q7w2"
[1, 2]
[3]
```

Final answer:

```text id="c9m5v1"
2
```

---

## ⚠️ Important Details

### Why initialize `freq[0] = 1`?

It represents the empty prefix before the array begins.

This allows us to count subarrays that start at index `0`.

Example:

```cpp id="z5r8p3"
arr = {3, 2}
K = 5
```

At index `1`:

```text id="h7m2q9"
prefixSum = 5
needed = 5 - 5 = 0
```

Because `freq[0] = 1`, we count:

```text id="k4x8n6"
[3, 2]
```

---

## ⏱️ Complexity

Let `n` be the number of elements.

* Average Time Complexity: **O(n)**
* Space Complexity: **O(n)**

The `unordered_map` provides average constant-time lookup and insertion.

---

## 🔄 Difference From Zero-Sum Subarrays

For zero-sum subarrays:

```cpp id="u8r3p5"
needed = prefixSum;
```

Because:

```text id="d6m1q9"
K = 0
```

For sum-`K` subarrays:

```cpp id="w2v7n4"
needed = prefixSum - K;
```

The zero-sum problem is simply a special case of this general problem.

---

## 🔑 Pattern Recognition

```text id="q4m8x2"
Count subarrays with target sum
            ↓
      Prefix sum
            ↓
Current prefix - target
            ↓
  Search previous prefix
            ↓
   Add its frequency
```

### Key Rule

> **For counting subarrays with sum K, store prefix-sum frequencies and search for `prefixSum - K`.**

---

## 🏆 Important Comparison

| Goal                               | Store                        |
| ---------------------------------- | ---------------------------- |
| Count subarrays with sum `K`       | `prefixSum → frequency`      |
| Find longest subarray with sum `K` | `prefixSum → earliest index` |
| Count zero-sum subarrays           | `prefixSum → frequency`      |
| Find longest zero-sum subarray     | `prefixSum → earliest index` |

---

## Final Takeaway

Never memorize the formula blindly.

Start from:

$$
\text{current prefix} - \text{previous prefix} = K
$$

Then derive:

$$
\boxed{\text{previous prefix} = \text{current prefix} - K}
$$

That is the foundation of this entire hashing pattern.
