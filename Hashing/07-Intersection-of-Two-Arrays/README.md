# Intersection of Two Arrays

## 📌 Problem

Given two arrays, find the **distinct elements that appear in both arrays**.

### Example

```text
Input:
arr1 = [4, 1, 3, 2]
arr2 = [2, 4, 2, 4]

Output:
[2, 4]
```

The result contains each common element only once.

---

## 🧠 Approach — Hashing

I use an `unordered_set` to store all elements of the first array.

Then I traverse the second array:

1. Insert every element of `arr1` into a set.
2. For every element in `arr2`, check whether it exists in the first set.
3. If it exists, insert it into the result set.
4. Because the result is also an `unordered_set`, duplicate common elements are automatically ignored.

### Core Idea

```text
arr1
 ↓
unordered_set
 ↓
Check each element of arr2
 ↓
Does it exist?
 ↓
YES → insert into result set
```

---

## 💻 Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> intersectionOfArray(
    vector<int>& arr1,
    vector<int>& arr2
) {
    unordered_set<int> us;
    unordered_set<int> res;

    // Store elements of first array
    for (int i = 0; i < arr1.size(); i++) {
        us.insert(arr1[i]);
    }

    // Check elements of second array
    for (int j = 0; j < arr2.size(); j++) {
        if (us.find(arr2[j]) != us.end()) {
            res.insert(arr2[j]);
        }
    }

    return res;
}
```

---

## ⏱️ Complexity

Let:

* `n` = size of `arr1`
* `m` = size of `arr2`

### Time Complexity

```text
O(n + m) average
```

Each element is inserted/searched in an `unordered_set` in average `O(1)` time.

### Space Complexity

```text
O(n + k)
```

where `k` is the number of distinct elements in the intersection.

---

## 🔑 DSA Pattern Learned

### When to use `unordered_set`

Use an `unordered_set` when we mainly need to answer:

> **"Have I seen this element before?"**

For this problem:

```cpp
us.find(x) != us.end()
```

means:

> `x` exists in the set.

```cpp
us.find(x) == us.end()
```

means:

> `x` does not exist in the set.

---

## 🔄 Alternative Approach

A **two-pointer approach** can also solve this problem if both arrays are sorted.

```text
Time: O(n + m)
Space: O(k) for the result
```

However, the hashing approach does **not require the input arrays to be sorted**.

---

## 🧠 Key Takeaway

The important pattern is:

```text
Need to check whether an element exists
        ↓
Use a set
        ↓
Need associated information like frequency/index
        ↓
Use a map
```

For this problem:

```text
unordered_set → existence checking
unordered_set → distinct result
```
