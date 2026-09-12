# Longest Subarray With Sum K

## 📌 Problem

Given an array of integers and an integer `K`, find the **length of the longest contiguous subarray** whose sum is exactly `K`.

### Example

```text
Input:
arr = [10, 5, 2, 4, 3, 1, 9]
K = 15

Output:
5
```

The longest valid subarray is:

```text
[5, 2, 4, 3, 1]
```

Its sum is:

```text
5 + 2 + 4 + 3 + 1 = 15
```

Its length is `5`.

---

## 🧠 Important Concept: Contiguous Subarray

A subarray must contain **continuous elements**.

For:

```text
[10, 5, 2, 4]
```

Valid subarrays include:

```text
[10]
[5, 2]
[2, 4]
[5, 2, 4]
```

But:

```text
[10, 2]
```

is NOT a subarray because we skipped `5`.

---

# Approach 1 — Brute Force

## Idea

Start from every possible index and expand the subarray toward the right.

For every starting index `i`:

1. Set `sum = 0`.
2. Move `j` from `i` to the end.
3. Keep adding `arr[j]`.
4. Whenever `sum == K`, calculate the length.
5. Keep the maximum length.

### Code

```cpp
int longestSubarrayWithSumK(vector<int> arr, int k) {

    int n = arr.size();
    int longest = 0;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += arr[j];

            if(sum == k) {
                longest = max(longest, j - i + 1);
            }
        }
    }

    return longest;
}
```

## Complexity

```text
Time:  O(n²)
Space: O(1)
```

### Important

Do NOT `break` immediately after finding `sum == K`.

For example:

```text
[1, 2, 0, 0]
K = 3
```

Starting from index `0`:

```text
[1, 2]       → sum 3 → length 2
[1, 2, 0]    → sum 3 → length 3
[1, 2, 0, 0] → sum 3 → length 4
```

We need the longest one.

---

# Approach 2 — Prefix Sum + HashMap

## 🔥 Main Pattern

The key equation is:

```text
currentPrefixSum - previousPrefixSum = K
```

Therefore:

```text
previousPrefixSum = currentPrefixSum - K
```

So at every index we ask:

> Have I seen the prefix sum `currentPrefixSum - K` before?

If yes, we have found a subarray whose sum is `K`.

---

## Example

```text
arr = [1, 2, 3, 1, 2]
K = 6
```

Prefix sums:

```text
Index:       0   1   2   3   4
Array:       1   2   3   1   2
Prefix:      1   3   6   7   9
```

At index `4`:

```text
currentPrefixSum = 9

needed = 9 - 6
       = 3
```

Prefix sum `3` was previously seen at index `1`.

Therefore:

```text
length = 4 - 1
       = 3
```

The subarray is:

```text
[3, 1, 2]
```

and:

```text
3 + 1 + 2 = 6
```

---

# Why Store the Earliest Index?

We store:

```text
prefixSum → earliest index
```

Suppose prefix sum `5` occurs at:

```text
index 2
index 6
```

and we're currently at index `10`.

Using index `2`:

```text
10 - 2 = 8
```

Using index `6`:

```text
10 - 6 = 4
```

Since we want the **longest** subarray, we must keep the earliest index.

Therefore:

> If a prefix sum already exists in the map, DO NOT overwrite its index.

---

# Why `firstIndex[0] = -1`?

This handles subarrays that start from index `0`.

Example:

```text
arr = [5, 5]
K = 10
```

At index `1`:

```text
prefixSum = 10
needed = 10 - 10
       = 0
```

We need prefix sum `0` before the array starts.

So we initialize:

```cpp
firstIndex[0] = -1;
```

Then:

```text
length = 1 - (-1)
       = 2
```

Correct!

---

# Optimal Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, int k) {

    unordered_map<long long, int> firstIndex;

    long long prefixSum = 0;
    int maxLen = 0;

    firstIndex[0] = -1;

    for(int i = 0; i < arr.size(); i++) {

        prefixSum += arr[i];

        long long needed = prefixSum - k;

        if(firstIndex.find(needed) != firstIndex.end()) {

            maxLen = max(
                maxLen,
                i - firstIndex[needed]
            );
        }

        // Store only the earliest occurrence
        if(firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {

    vector<int> arr = {
        10, 5, 2, 4, 3, 1, 9
    };

    cout << longestSubarrayWithSumK(arr, 15);

    return 0;
}
```

---

# ⏱️ Complexity

### Brute Force

```text
Time:  O(n²)
Space: O(1)
```

### Prefix Sum + HashMap

```text
Time:  O(n) average
Space: O(n)
```

The optimal approach processes the array only once.

---

# 🧠 Pattern Recognition

Whenever you see:

```text
"subarray"
+
"sum equals K"
+
"longest/shortest/count"
```

immediately consider:

```text
Prefix Sum
     +
HashMap
```

The fundamental equation is:

```text
currentPrefixSum - previousPrefixSum = K
```

which gives:

```text
previousPrefixSum = currentPrefixSum - K
```

---

# 🎯 Key Takeaways

* A subarray must be contiguous.
* Brute force checks every possible starting point and ending point.
* Running sum prevents repeatedly calculating subarray sums.
* Prefix sums allow us to convert a subarray-sum problem into a lookup problem.
* `currentPrefixSum - K` tells us which previous prefix sum we need.
* Store `prefixSum → earliest index`.
* Keep the earliest occurrence because we want the longest subarray.
* Initialize `firstIndex[0] = -1` to handle subarrays beginning at index `0`.
* Use `long long` for prefix sums when values can be large.
* Average optimal complexity: `O(n)` time and `O(n)` space.

---

# 🚀 Pattern to Remember

```text
Subarray Sum K
      ↓
Prefix Sum
      ↓
Current Prefix - K
      ↓
Search in HashMap
      ↓
Previous Prefix Index
      ↓
Calculate Length
      ↓
Update Maximum
```

This is one of the most important HashMap + Prefix Sum patterns in DSA.
