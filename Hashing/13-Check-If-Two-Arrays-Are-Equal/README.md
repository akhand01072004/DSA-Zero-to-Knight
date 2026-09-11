```cpp
#include <bits/stdc++.h>
using namespace std;

bool checkIfTwoArraysAreEqual(
    const vector<int>& arr,
    const vector<int>& vec
) {
    if (arr.size() != vec.size()) {
        return false;
    }

    unordered_map<int, int> arrFreq;
    unordered_map<int, int> vecFreq;

    // Count frequencies of both arrays
    for (int i = 0; i < arr.size(); i++) {
        arrFreq[arr[i]]++;
        vecFreq[vec[i]]++;
    }

    // Compare frequency of every value
    for (auto p : arrFreq) {
        int value = p.first;

        if (arrFreq[value] != vecFreq[value]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    vector<int> vec = {2, 3, 2, 1};

    cout << checkIfTwoArraysAreEqual(arr, vec);

    return 0;
}
```

### Output

```text
1
```

Here `1` means `true`.

---

### `README.md`

# Check If Two Arrays Are Equal

## 📌 Problem

Given two arrays, determine whether they contain exactly the same elements with exactly the same frequencies.

The order of elements does **not** matter.

### Example

```text
A = [1, 2, 2, 3]
B = [2, 3, 2, 1]
```

Both arrays contain:

```text
1 → 1 time
2 → 2 times
3 → 1 time
```

Therefore:

```text
Output: true
```

---

## 🧠 Approach — Frequency Hashing

Use two `unordered_map`s to store the frequency of each element in both arrays.

```text
arr → arrFreq
vec → vecFreq
```

Then compare the frequency of every value.

### Steps

1. Check whether both arrays have the same size.
2. Build a frequency map for the first array.
3. Build a frequency map for the second array.
4. Compare the frequency of every value.
5. If any frequency differs, return `false`.
6. If all frequencies match, return `true`.

---

## 💻 Implementation

```cpp
bool checkIfTwoArraysAreEqual(
    const vector<int>& arr,
    const vector<int>& vec
) {
    if (arr.size() != vec.size()) {
        return false;
    }

    unordered_map<int, int> arrFreq;
    unordered_map<int, int> vecFreq;

    for (int i = 0; i < arr.size(); i++) {
        arrFreq[arr[i]]++;
        vecFreq[vec[i]]++;
    }

    for (auto p : arrFreq) {
        int value = p.first;

        if (arrFreq[value] != vecFreq[value]) {
            return false;
        }
    }

    return true;
}
```

---

## 🔍 Dry Run

Consider:

```text
A = [1, 2, 2, 3]
B = [2, 3, 2, 1]
```

Frequency maps:

```text
A:
1 → 1
2 → 2
3 → 1

B:
1 → 1
2 → 2
3 → 1
```

Compare:

```text
1 → 1 == 1 ✓
2 → 2 == 2 ✓
3 → 1 == 1 ✓
```

All frequencies match.

Therefore:

```text
true
```

---

## ❌ Example Where Arrays Are Not Equal

```text
A = [1, 2, 2, 3]
B = [1, 2, 3, 3]
```

Frequencies:

```text
A:
1 → 1
2 → 2
3 → 1

B:
1 → 1
2 → 1
3 → 2
```

For `2`:

```text
A → 2
B → 1
```

The frequencies differ, so:

```text
false
```

---

## ⚠️ Important Concept

We must compare the **same value** in both maps.

Incorrect:

```cpp
arrFreq[arr[i]] == vecFreq[vec[i]]
```

This compares elements at the same index.

But the problem says that **order doesn't matter**.

Correct:

```cpp
arrFreq[value] == vecFreq[value]
```

The same value must have the same frequency in both arrays.

---

## ⏱️ Complexity

Let `n` be the size of the arrays.

### Time Complexity

```text
O(n) average
```

Building both frequency maps takes `O(n)` average time, and comparing the stored frequencies takes `O(n)` in the worst case.

### Space Complexity

```text
O(n)
```

Two frequency maps are used.

---

## 🔑 DSA Pattern Learned

### Frequency Comparison

When the order of elements does not matter but their frequencies do:

```text
Array
 ↓
Frequency Map
 ↓
Compare frequencies
 ↓
Equal → true
Different → false
```

This pattern is useful for problems involving:

* Checking whether arrays are equal
* Anagrams
* Frequency matching
* Multiset comparison
* Rearrangement problems

---

## 🧠 Key Takeaway

> **When order doesn't matter, frequency can become the representation of the array.**

Instead of comparing:

```text
[1, 2, 2, 3]
      vs
[2, 3, 2, 1]
```

directly, compare their frequency representations:

```text
1 → 1
2 → 2
3 → 1
```

If the frequency maps are identical, the arrays contain the same elements with the same frequencies.

🔥 **Hashing #13 complete.**

And this is a very important conceptual progression:

```text
#11 → value → frequency + maximum
#12 → needed value → frequency of previous matches
#13 → value → frequency comparison
```

You're getting much more comfortable with the idea that a hash map isn't "just a map"—it's a way of **compressing useful information about the input**. 🧠💪
