# Longest Subarray With Sum Zero

## 📁 Folder Path

```text
DSA-Zero-to-Knight/03-Hashing/19-Longest-Subarray-With-Sum-Zero/
```

## 🧩 Problem Statement

Given an integer array, find the length of the longest contiguous subarray whose sum is equal to `0`.

Return `0` if no such subarray exists.

## Example

### Input

```cpp
{1, 2, -3, 3, -3}
```

### Longest Zero-Sum Subarray

```text
[1, 2, -3, 3, -3]
```

Its sum is:

```text
1 + 2 - 3 + 3 - 3 = 0
```

### Output

```text
5
```

---

## 💡 Core Idea

Use **prefix sum + hashing**.

If the same prefix sum appears at two different indices, the elements between those indices have sum `0`.

For example:

```text
Index:      -1   0   1   2   3   4
PrefixSum:   0   1   3   0   3   0
```

The prefix sum `0` appears at:

```text
-1, 2, 4
```

Using the earliest index `-1` gives the longest subarray ending at index `4`.

Length:

```text
4 - (-1) = 5
```

---

## 🧠 Why Store the Earliest Index?

For the longest subarray, we want:

```text
currentIndex - previousIndex
```

to be as large as possible.

Therefore, for every prefix sum, store only its **first occurrence**.

Do not overwrite it later.

---

## ✅ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumZero(const vector<int>& arr) {
    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLength = 0;

    // Empty prefix before the array starts
    firstIndex[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (firstIndex.find(prefixSum) != firstIndex.end()) {
            int length = i - firstIndex[prefixSum];

            maxLength = max(maxLength, length);
        } else {
            // Store only the earliest occurrence
            firstIndex[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -3};

    cout << longestSubarrayWithSumZero(arr);

    return 0;
}
```

### Output

```text
5
```

---

## 🔍 Dry Run

Input:

```cpp
{1, 2, -3, 3, -3}
```

|        Index | Element | Prefix Sum | First Index | Current Length | Max Length |
| -----------: | ------: | ---------: | ----------: | -------------: | ---------: |
| Before start |       — |        `0` |        `-1` |              — |        `0` |
|          `0` |     `1` |        `1` |         `0` |              — |        `0` |
|          `1` |     `2` |        `3` |         `1` |              — |        `0` |
|          `2` |    `-3` |        `0` |        `-1` |            `3` |        `3` |
|          `3` |     `3` |        `3` |         `1` |            `2` |        `3` |
|          `4` |    `-3` |        `0` |        `-1` |            `5` |        `5` |

Final answer:

```text
5
```

---

## ⚠️ Important Details

### Why initialize `firstIndex[0] = -1`?

It represents the prefix sum before the array starts.

For example:

```cpp
arr = {1, -1}
```

At index `1`, the prefix sum becomes `0`.

The length is:

```text
1 - (-1) = 2
```

This correctly counts the subarray:

```text
[1, -1]
```

### Why do we not overwrite an existing index?

Suppose:

```text
prefixSum = 0
```

was first found at index `-1`.

If we later replace it with index `2`, then we lose the possibility of getting the longer length:

```text
currentIndex - (-1)
```

So we preserve the earliest index.

---

## ⏱️ Complexity

* Average Time: **O(n)**
* Space: **O(n)**

---

## 🔄 Difference From Counting Zero-Sum Subarrays

| Problem                   | HashMap Stores               |
| ------------------------- | ---------------------------- |
| Count zero-sum subarrays  | `prefixSum → frequency`      |
| Longest zero-sum subarray | `prefixSum → earliest index` |

### Counting

```cpp
answer += freq[prefixSum];
freq[prefixSum]++;
```

### Longest Length

```cpp
if (prefixSum exists) {
    length = currentIndex - firstIndex[prefixSum];
} else {
    firstIndex[prefixSum] = currentIndex;
}
```

---

## 🔑 Pattern

```text
Longest subarray
    ↓
Prefix sum
    ↓
Repeated prefix sum
    ↓
Store earliest index
```

### Key Rule

> **Longest valid subarray → store the earliest index of each prefix sum.**
