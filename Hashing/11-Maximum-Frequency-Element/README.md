# Maximum Frequency Element

## 📌 Problem

Given an array, find the element that occurs **most frequently**.

If multiple elements have the same maximum frequency, any one of them can be returned unless the problem specifies a tie-breaking rule.

### Example

```text
Input:
[4, 7, 2, 7, 9, 4, 2, 7]

Frequencies:
4 → 2
7 → 3
2 → 2
9 → 1

Output:
7
```

---

## 🧠 Approach — Frequency Hashing

Use an `unordered_map<int, int>` to store the frequency of each element.

While traversing the array:

1. Increase the frequency of the current element.
2. Compare its new frequency with the maximum frequency seen so far.
3. If it becomes the new maximum, update the answer.

### Core Idea

```text
Traverse array
      ↓
Increase frequency of x
      ↓
Is freq[x] > maxFrequency?
      ↓
     YES
      ↓
Update element and maxFrequency
```

The answer is maintained **while building the frequency map**, so a separate traversal of the map is not required.

---

## 💻 Implementation

```cpp
int maximumFrequencyElement(vector<int>& arr) {

    unordered_map<int, int> freq;

    int maxFrequency = 0;
    int element = -1;

    for (int x : arr) {

        freq[x]++;

        if (freq[x] > maxFrequency) {
            maxFrequency = freq[x];
            element = x;
        }
    }

    return element;
}
```

---

## 🔍 Dry Run

For:

```text
[4, 7, 2, 7, 9, 4, 2, 7]
```

The important updates are:

```text
4 → frequency 1 → max = 1 → answer = 4

7 → frequency 1 → no change

2 → frequency 1 → no change

7 → frequency 2 → max = 2 → answer = 7

9 → frequency 1 → no change

4 → frequency 2 → no change

2 → frequency 2 → no change

7 → frequency 3 → max = 3 → answer = 7
```

Final:

```text
maxFrequency = 3
element = 7
```

---

## ⚠️ Tie Handling

Suppose:

```text
[1, 1, 2, 2]
```

Both `1` and `2` have frequency `2`.

The current solution returns `1`.

This is valid when **any maximum-frequency element** is acceptable.

If the problem specifies a tie-breaking rule, such as:

> Return the smallest element among elements with maximum frequency.

then the comparison must be modified accordingly.

---

## ⏱️ Complexity

Let `n` be the size of the array.

### Time Complexity

```text
O(n) average
```

Each insertion/update in `unordered_map` takes `O(1)` average time.

### Space Complexity

```text
O(n)
```

In the worst case, all elements are distinct and the map stores `n` keys.

---

## 🔑 DSA Pattern Learned

### Frequency + Running Maximum

This problem demonstrates an important pattern:

```text
Frequency Map
     +
Running Maximum
```

Instead of:

```text
1. Build frequency map
2. Traverse map
3. Find maximum
```

we can do:

```text
1. Build frequency
2. Update maximum immediately
```

This keeps the solution in one traversal of the input.

---

## 🧠 Key Takeaway

When processing an array, ask:

> **Can I maintain my answer while building my data structure instead of calculating it afterward?**

For maximum frequency:

```cpp
freq[x]++;

if (freq[x] > maxFrequency) {
    maxFrequency = freq[x];
    element = x;
}
```

This is a useful pattern for many frequency-based problems.
