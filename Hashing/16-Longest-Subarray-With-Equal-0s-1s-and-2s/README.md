# Longest Subarray With Equal 0s, 1s and 2s

## 📌 Problem

Given an array containing only `0`, `1`, and `2`, find the length of the **longest contiguous subarray** containing an equal number of:

* `0s`
* `1s`
* `2s`

### Example

```text
Input:
arr = [0, 1, 2, 0, 1, 2]

Output:
6
```

The complete array contains:

```text
0s = 2
1s = 2
2s = 2
```

Therefore, the answer is:

```text
6
```

---

## 🧠 Important Observation

For a valid subarray:

```text
count0 == count1 == count2
```

This is equivalent to:

```text
count0 - count1 == 0
count1 - count2 == 0
```

Therefore, we need to track **two independent differences**:

```text
difference01 = count0 - count1
difference12 = count1 - count2
```

The state of the array becomes:

```text
(difference01, difference12)
```

---

# Why One Prefix Sum Is Not Enough

A single numerical encoding can produce false matches.

For example, if we use:

```text
0 → -3
1 → +1
2 → +2
```

then:

```text
[0, 1, 2]
```

has sum:

```text
-3 + 1 + 2 = 0
```

But:

```text
[0, 1, 1, 1]
```

also has sum:

```text
-3 + 1 + 1 + 1 = 0
```

However, its counts are:

```text
0s = 1
1s = 3
2s = 0
```

The counts are not equal.

Therefore, one scalar prefix sum cannot represent both independent equality conditions.

---

# 🔥 Correct Approach — Prefix State + HashMap

Maintain:

```cpp
count0
count1
count2
```

At every index, calculate:

```cpp
difference01 = count0 - count1;
difference12 = count1 - count2;
```

Store the pair:

```text
(difference01, difference12) → earliest index
```

If the same pair appears again, the subarray between those two positions has equal numbers of `0s`, `1s`, and `2s`.

---

## Example

```text
arr = [0, 1, 2]
```

Track the counts and differences:

| Index | Value | `count0` | `count1` | `count2` | State    |
| ----: | ----: | -------: | -------: | -------: | -------- |
|    -1 |     — |        0 |        0 |        0 | `(0, 0)` |
|     0 |     0 |        1 |        0 |        0 | `(1, 0)` |
|     1 |     1 |        1 |        1 |        0 | `(0, 1)` |
|     2 |     2 |        1 |        1 |        1 | `(0, 0)` |

The state `(0, 0)` appears at:

```text
index -1
index 2
```

Therefore:

```text
length = 2 - (-1)
       = 3
```

The complete array contains equal numbers of all three values.

---

# Why Store the Earliest Index?

We want the **longest** valid subarray.

Suppose the same state appears at:

```text
index 2
index 6
```

and we are currently at index `10`.

Using index `2`:

```text
length = 10 - 2
       = 8
```

Using index `6`:

```text
length = 10 - 6
       = 4
```

The earliest index gives the longest subarray.

Therefore:

> Store only the first occurrence of every state.

Never overwrite an existing state index.

---

# Why Initialize `(0, 0)` at Index `-1`?

This handles subarrays that begin at index `0`.

```cpp
firstIndex[{0, 0}] = -1;
```

For:

```text
arr = [0, 1, 2]
```

after index `2`:

```text
count0 = 1
count1 = 1
count2 = 1
```

So:

```text
state = (0, 0)
```

The length becomes:

```text
2 - (-1) = 3
```

---

# ✅ Solution Using `map`

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithEqual0s1sand2s(
    const vector<int>& arr
) {
    map<pair<int, int>, int> firstIndex;

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    int maxLen = 0;

    firstIndex[{0, 0}] = -1;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] == 0) {
            count0++;
        }
        else if(arr[i] == 1) {
            count1++;
        }
        else {
            count2++;
        }

        int difference01 = count0 - count1;
        int difference12 = count1 - count2;

        pair<int, int> state = {
            difference01,
            difference12
        };

        if(firstIndex.find(state) != firstIndex.end()) {

            maxLen = max(
                maxLen,
                i - firstIndex[state]
            );

        }
        else {
            firstIndex[state] = i;
        }
    }

    return maxLen;
}

int main() {

    vector<int> arr = {
        0, 1, 2, 0, 1, 2,
        1, 1, 2, 2, 0, 0
    };

    cout << longestSubarrayWithEqual0s1sand2s(arr);

    return 0;
}
```

---

# ⏱️ Complexity

Because `map` stores keys in sorted order:

```text
Time:  O(n log n)
Space: O(n)
```

The algorithm performs one traversal, but each `map` operation takes `O(log n)`.

A custom pair hash with `unordered_map` can reduce the average time to:

```text
Time: O(n) average
Space: O(n)
```

---

# 🧠 Pattern Recognition

Whenever you see:

```text
Longest subarray
+
Equal frequency of 3 different values
```

think:

```text
Track two independent differences
```

For values `0`, `1`, and `2`:

```text
difference01 = count0 - count1
difference12 = count1 - count2
```

Then:

```text
State pair
    ↓
Prefix state
    ↓
HashMap
    ↓
Repeated state
    ↓
Calculate maximum distance
```

---

# 🎯 Key Takeaways

* The subarray must be contiguous.
* Equal counts of three values require two independent conditions.
* One prefix sum is not enough.
* Track:

  * `count0 - count1`
  * `count1 - count2`
* Store the pair of differences as the state.
* Repeated states indicate a valid subarray.
* Store the earliest index of every state.
* Initialize `(0, 0)` at index `-1`.
* Using `map` gives `O(n log n)` time.
* Using `unordered_map` with a custom pair hash gives average `O(n)` time.

---

## 🔥 Final Pattern

```text
Equal 0s, 1s and 2s
          ↓
Track two count differences
          ↓
Create a pair state
          ↓
Store state → earliest index
          ↓
Repeated state
          ↓
Equal counts in between
          ↓
Maximum index distance
```
