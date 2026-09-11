# Common Elements With Frequencies

## 📌 Problem

Given two **unsorted arrays**, find their intersection while preserving the frequency of common elements.

An element should appear in the result as many times as it appears in **both arrays**.

### Example

```text
arr1 = [1, 2, 2, 3, 4]
arr2 = [2, 2, 2, 4, 4, 5]

Output:
[2, 2, 4]
```

### Why?

```text
2 → arr1 has 2 occurrences, arr2 has 3
  → common frequency = 2

4 → arr1 has 1 occurrence, arr2 has 2
  → common frequency = 1
```

Therefore:

```text
[2, 2, 4]
```

---

## 🧠 Approach — Frequency Hashing

Use an `unordered_map<int, int>` to store the frequency of every element in the first array.

Then traverse the second array.

For every element:

1. Check whether its remaining frequency is greater than `0`.
2. If yes, add it to the result.
3. Decrease its frequency by `1`.
4. If its frequency becomes `0`, no more occurrences can be added.

### Core Idea

```text
arr1
 ↓
Build frequency map
 ↓
Scan arr2
 ↓
freq[x] > 0 ?
 ↙          ↘
YES          NO
 ↓            ↓
add x       skip x
 ↓
freq[x]--
```

---

## 💻 Implementation

```cpp
vector<int> intersectionOfArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    vector<int> result;

    for (int x : arr1) {
        freq[x]++;
    }

    for (int x : arr2) {
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }

    return result;
}
```

---

## 🔍 Important Concept

The frequency stored in the map represents the **remaining available occurrences**.

For example:

```text
arr1 = [2, 2, 4]

Initial:
2 → 2
4 → 1
```

When processing `2` from the second array:

```text
2 → 2
↓
take one 2
↓
2 → 1
```

After taking another:

```text
2 → 1
↓
take one 2
↓
2 → 0
```

Any further `2` must be skipped because there are no occurrences left.

---

## ⚠️ Why `find()` Alone Is Not Enough

This condition:

```cpp
freq.find(x) != freq.end()
```

only tells us that the **key exists**.

It does not tell us whether its frequency is still available.

For example:

```text
2 → 0
```

The key `2` still exists in the map, so `find(2)` succeeds.

But:

```cpp
freq[2] > 0
```

correctly tells us that no `2` is available anymore.

---

## ⏱️ Complexity

Let:

* `n` = size of `arr1`
* `m` = size of `arr2`

### Time Complexity

```text
O(n + m) average
```

Building the frequency map takes `O(n)` average time and processing the second array takes `O(m)` average time.

### Space Complexity

```text
O(n)
```

The frequency map can contain up to `n` distinct elements.

The result vector requires additional space for the output.

---

## 🔑 DSA Pattern Learned

### Frequency + Decrement

When an element can be used only a limited number of times:

```text
Store frequency
      ↓
Use element
      ↓
Decrease frequency
      ↓
Skip when frequency reaches 0
```

This is a powerful hashing pattern for problems involving:

* Array intersections
* Multisets
* Available occurrences
* Matching elements
* Frequency constraints

---

## 🧠 Key Takeaway

```text
Need to know if an element exists
        → unordered_set

Need to know how many times it occurs
        → unordered_map

Need to consume occurrences
        → unordered_map + decrement
```

### Pattern

```cpp
if (freq[x] > 0) {
    result.push_back(x);
    freq[x]--;
}
```

This pattern is the main lesson from this problem.
