# Count Pairs With Given Sum

## 📌 Problem

Given an array and a target sum, count the number of pairs of indices `(i, j)` such that:

```text
i < j
arr[i] + arr[j] = target
```

Every valid index pair is counted.

Duplicate values at different indices are treated as different elements.

---

## 🧪 Example

```text
Input:
arr = [1, 5, 7, -1, 5]
target = 6

Output:
3
```

The valid pairs are:

```text
1 + 5 = 6
7 + (-1) = 6
1 + 5 = 6
```

There are two different `5`s, so both pairs involving `1` are counted.

---

## 🧠 Approach — Frequency Hashing

Use an `unordered_map<int, int>` to store the frequency of elements that have already been processed.

For every current element `x`:

```text
needed = target - x
```

Then:

```text
freq[needed]
```

tells us how many previous elements can form a valid pair with `x`.

Add that frequency to the answer.

After counting, store the current element:

```text
freq[x]++
```

### Core Pattern

```text
Current element = x
        ↓
needed = target - x
        ↓
How many "needed" appeared before?
        ↓
answer += freq[needed]
        ↓
freq[x]++
```

---

## 💻 Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int countPairsWithGivenSum(vector<int>& arr, int target) {

    unordered_map<int, int> freq;
    int occurrence = 0;

    for (int x : arr) {

        int needed = target - x;

        occurrence += freq[needed];

        freq[x]++;
    }

    return occurrence;
}

int main() {

    vector<int> arr = {1, 5, 7, -1, 5};

    cout << countPairsWithGivenSum(arr, 6);

    return 0;
}
```

---

## 🔍 Dry Run

For:

```text
arr = [1, 5, 7, -1, 5]
target = 6
```

### `x = 1`

```text
needed = 5
freq[5] = 0

answer = 0

freq[1]++
```

### `x = 5`

```text
needed = 1
freq[1] = 1

answer = 0 + 1 = 1

freq[5]++
```

### `x = 7`

```text
needed = -1
freq[-1] = 0

answer = 1

freq[7]++
```

### `x = -1`

```text
needed = 7
freq[7] = 1

answer = 1 + 1 = 2

freq[-1]++
```

### `x = 5`

```text
needed = 1
freq[1] = 1

answer = 2 + 1 = 3

freq[5]++
```

Final answer:

```text
3
```

---

## ⚠️ Why Frequency Is Added

Suppose:

```text
arr = [1, 1, 1, 5]
target = 6
```

When we reach `5`:

```text
needed = 1
freq[1] = 3
```

Therefore:

```cpp
answer += freq[1];
```

adds:

```text
3
```

because the current `5` can form a pair with all three previous `1`s.

---

## ⚠️ Order Matters

The correct order is:

```cpp
answer += freq[needed];
freq[x]++;
```

We must count pairs **before** adding the current element to the frequency map.

Otherwise, an element could incorrectly pair with itself.

For example:

```text
arr = [5]
target = 10
```

Correct answer:

```text
0
```

There is only one `5`, so it cannot form a pair with itself.

---

## 🔑 Important DSA Pattern

### Two Sum → Count Two Sum

Normal Two Sum asks:

```text
Does the needed value exist?
```

We can use:

```cpp
freq.find(needed)
```

or a map lookup.

This problem asks:

```text
How many needed values have appeared?
```

So we use:

```cpp
freq[needed]
```

and add that frequency to the answer.

### Pattern

```cpp
int needed = target - x;

answer += freq[needed];

freq[x]++;
```

---

## ⏱️ Complexity

Let `n` be the size of the array.

### Time Complexity

```text
O(n) average
```

Each hash-map operation takes `O(1)` average time.

### Space Complexity

```text
O(n)
```

In the worst case, all elements are distinct and the frequency map stores `n` elements.

---

## 🧠 Key Takeaway

The important idea is:

> **Don't just ask whether a matching value exists. Ask how many matching values have already appeared.**

This converts the Two Sum existence pattern into an efficient **pair-counting pattern**.

```text
needed = target - current
        ↓
frequency of needed
        ↓
add frequency to answer
        ↓
store current element
```
