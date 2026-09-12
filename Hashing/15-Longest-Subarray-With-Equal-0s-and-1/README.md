# Longest Subarray With Equal 0s and 1s

## 📌 Problem

Given a binary array containing only `0` and `1`, find the length of the **longest contiguous subarray** containing an equal number of `0s` and `1s`.

### Example

```text
Input:
arr = [0, 1, 1, 0]

Output:
4
```

The complete array contains:

```text
0s = 2
1s = 2
```

Therefore, the answer is:

```text
4
```

---

## 🧠 Main Observation

We need to find a subarray with:

```text
number of 0s == number of 1s
```

Convert the array using this rule:

```text
0 → -1
1 → +1
```

Now equal numbers of `0s` and `1s` will produce a sum of `0`.

### Example

```text
Original:
[0, 1, 1, 0]

Converted:
[-1, +1, +1, -1]
```

Sum:

```text
-1 + 1 + 1 - 1 = 0
```

Therefore:

> The problem becomes finding the longest subarray with sum `0`.

---

# 🔥 Prefix Sum + HashMap Approach

## Key Idea

Maintain a running prefix sum.

If the same prefix sum appears again, the elements between those two indices have a sum of `0`.

For this problem:

```text
0 → -1
1 → +1
```

So:

```text
Equal 0s and 1s
        ↓
Converted sum = 0
        ↓
Repeated prefix sum
        ↓
Valid subarray
```

---

## Example

```text
arr = [0, 1, 1, 0]
```

Converted array:

```text
[-1, +1, +1, -1]
```

Prefix sums:

```text
Index:       0    1    2    3
Converted:  -1   +1   +1   -1
Prefix:     -1    0    1    0
```

Prefix sum `0` appears at:

```text
index 1
index 3
```

The elements between these positions have sum `0`.

There is also a prefix sum of `0` before the array starts:

```text
firstIndex[0] = -1
```

At index `3`:

```text
length = 3 - (-1)
       = 4
```

Therefore, the longest valid subarray has length `4`.

---

# Why Store the Earliest Index?

We want the **longest** subarray.

Suppose the same prefix sum appears at:

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

The earlier index gives the longer subarray.

Therefore:

> Store only the first occurrence of every prefix sum.

Do not overwrite an existing index.

---

# Why Initialize `firstIndex[0] = -1`?

This handles subarrays that begin at index `0`.

Example:

```text
arr = [0, 1]
```

Converted:

```text
[-1, +1]
```

At index `1`:

```text
prefixSum = 0
```

Since prefix sum `0` existed at index `-1`:

```text
length = 1 - (-1)
       = 2
```

So the entire array is correctly counted.

---

# ✅ Optimal Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayEqualZeroOne(const vector<int>& arr) {

    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLen = 0;

    firstIndex[0] = -1;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] == 0) {
            prefixSum -= 1;
        } else {
            prefixSum += 1;
        }

        if(firstIndex.find(prefixSum) != firstIndex.end()) {

            maxLen = max(
                maxLen,
                i - firstIndex[prefixSum]
            );

        } else {

            firstIndex[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {

    vector<int> arr = {0, 1, 1, 0};

    cout << longestSubarrayEqualZeroOne(arr);

    return 0;
}
```

### Output

```text
4
```

---

# ⏱️ Complexity

```text
Time:  O(n) average
Space: O(n)
```

We traverse the array once and use a HashMap to store prefix sums.

---

# 🧠 Pattern Recognition

Whenever you see:

```text
Longest subarray
+
Equal number of 0s and 1s
```

Think:

```text
0 → -1
1 → +1
```

Then:

```text
Equal number of 0s and 1s
        ↓
Sum becomes 0
        ↓
Repeated prefix sum
        ↓
HashMap
```

---

# 🎯 Key Takeaways

* The array contains only `0` and `1`.
* Convert `0` into `-1`.
* Keep `1` as `+1`.
* Equal numbers of `0s` and `1s` produce sum `0`.
* Repeated prefix sums indicate a zero-sum subarray.
* Store `prefixSum → earliest index`.
* Initialize `firstIndex[0] = -1`.
* Never overwrite the earliest index.
* Time complexity is `O(n)` average.
* Space complexity is `O(n)`.

---

## 🔥 Final Pattern

```text
Equal 0s and 1s
        ↓
0 → -1, 1 → +1
        ↓
Find longest zero-sum subarray
        ↓
Prefix Sum + HashMap
        ↓
Repeated prefix sum
        ↓
Maximum index distance
```
