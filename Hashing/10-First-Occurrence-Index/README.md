# First Occurrence Index

## 📌 Problem

Given an array, create a mapping of each element to its **first occurrence index**.

If an element appears multiple times, only its first index should be stored.

### Example

```text
Input:
[4, 7, 2, 7, 9, 4, 2]

Output:
4 → 0
7 → 1
2 → 2
9 → 4
```

For example, `7` appears at indices `1` and `3`, but we store only:

```text
7 → 1
```

because `1` is its first occurrence.

---

## 🧠 Approach — Hash Map

Use an `unordered_map<int, int>` where:

```text
key   → element
value → first occurrence index
```

Traverse the array from left to right.

For every element:

1. Check whether it already exists in the map.
2. If it exists, skip it.
3. If it does not exist, store the current index.

### Core Idea

```text
Traverse array
      ↓
Have we seen this value?
   ↙          ↘
 YES           NO
  ↓             ↓
skip       store index
```

---

## 💻 Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void firstOccurrenceIndex(vector<int>& arr) {

    unordered_map<int, int> idx_mp;

    for (int i = 0; i < arr.size(); i++) {

        if (idx_mp.find(arr[i]) != idx_mp.end()) {
            continue;
        }

        idx_mp[arr[i]] = i;

        cout << arr[i] << " --> " << i << endl;
    }
}

int main() {
    vector<int> n = {4, 7, 2, 7, 9, 4, 2};

    firstOccurrenceIndex(n);

    return 0;
}
```

### Output

```text
4 --> 0
7 --> 1
2 --> 2
9 --> 4
```

---

## 🔍 Why Do We Check `find()` First?

This condition:

```cpp
idx_mp.find(arr[i]) != idx_mp.end()
```

means:

> The element already exists in the map.

If it already exists, we use:

```cpp
continue;
```

so that we don't overwrite the first index.

For example:

```text
Array:
[4, 7, 2, 7, 9]

First 7:
7 → 1

Second 7:
already exists → skip

Final:
7 → 1
```

---

## ⚠️ Important Difference

For frequency problems, we store:

```cpp
freq[x]++;
```

which represents:

```text
value → frequency
```

For this problem, we store:

```cpp
idx_mp[x] = i;
```

which represents:

```text
value → first index
```

The same `unordered_map` can store different kinds of information depending on the problem.

---

## ⏱️ Complexity

Let `n` be the size of the array.

### Time Complexity

```text
O(n) average
```

Each element is checked and inserted into the `unordered_map` in average `O(1)` time.

### Space Complexity

```text
O(n)
```

In the worst case, every element is unique and the map stores all `n` elements.

---

## 🔑 DSA Pattern Learned

### Value → Information

A powerful hashing pattern is:

```text
What am I looking up?
        ↓
      VALUE
        ↓
What information do I need about it?
        ↓
      STORE
```

Examples:

```text
value → frequency
value → first index
value → last index
value → some other information
```

For this problem:

```text
value → first occurrence index
```

---

## 🧠 Key Takeaway

When the problem asks for information about the **first occurrence** of each value:

```cpp
if (map.find(x) == map.end()) {
    map[x] = index;
}
```

The important part is:

> **Never overwrite the first occurrence.**
