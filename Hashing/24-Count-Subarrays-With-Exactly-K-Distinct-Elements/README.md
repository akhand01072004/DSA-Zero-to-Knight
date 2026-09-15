

````
# Count Subarrays With Exactly K Distinct Elements

## 📌 Problem Statement

Given an integer array `arr` and an integer `k`, count the number of contiguous subarrays containing exactly `k` distinct elements.

A subarray must contain consecutive elements.

---

## 🧪 Example

### Input

```text
arr = [1, 2, 1, 2, 3]
k = 2
````

### Output

```
6
```

### Explanation

The valid subarrays are:

```
[1, 2]
[2, 1]
[1, 2]
[1, 2, 1]
[2, 1, 2]
[1, 2, 1, 2]
```

Therefore, the answer is:

```
6
```

## 🧠 Approach

Directly counting subarrays with exactly `k` distinct elements is difficult.

We use the identity:

```
Exactly K
=
At Most K - At Most (K - 1)
```

Therefore:

```
countExactlyK(arr, k)
=
countAtMostK(arr, k)
-
countAtMostK(arr, k - 1)
```

## 🔍 Counting At Most K Distinct Elements

We use:

* Sliding Window

* Two Pointers

* Frequency Map

For every `right` index:

1. Add `arr[right]` to the frequency map.

2. If the number of distinct elements becomes greater than `k`, move `left` forward.

3. Decrease the frequency of `arr[left]`.

4. If its frequency becomes zero, erase it from the map.

5. Once the window becomes valid, add:

   right - left + 1

This counts all valid subarrays ending at the current `right` index.

## 💻 C++ Solution

C++

```
#include <bits/stdc++.h>
using namespace std;

long long countAtMostKDistinct(
    const vector<int>& arr,
    int k
) {
    if (k <= 0) {
        return 0;
    }

    unordered_map<int, int> freq;

    int left = 0;
    long long count = 0;

    for (int right = 0; right < arr.size(); right++) {

        // Add the current element
        freq[arr[right]]++;

        // Shrink the window if distinct count exceeds k
        while (freq.size() > k) {

            freq[arr[left]]--;

            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }

            left++;
        }

        // Count all valid subarrays ending at right
        count += right - left + 1;
    }

    return count;
}

long long countSubarraysWithExactlyKDistinct(
    const vector<int>& arr,
    int k
) {
    return countAtMostKDistinct(arr, k)
         - countAtMostKDistinct(arr, k - 1);
}

int main() {

    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << countSubarraysWithExactlyKDistinct(arr, k)
         << endl;

    return 0;
}
```

## ⏱️ Complexity Analysis

Let:

```
n = arr.size()
```

### Time Complexity

```
Average: O(n)
```

The helper function is called twice, but each call takes linear time.

Therefore:

```
O(n) + O(n) = O(n)
```

### Space Complexity

```
O(k)
```

The frequency map stores the distinct elements currently present in the sliding window.

## 🎯 Pattern Learned

This problem teaches:

* Sliding Window

* Two Pointers

* Frequency Map

* Counting subarrays ending at an index

* At Most K versus Exactly K

* The formula:

  Exactly K = At Most K - At Most (K - 1)

## ⚠️ Important Difference

For counting subarrays:

```
Exactly K
=
At Most K - At Most (K - 1)
```

For finding the longest subarray, this subtraction formula should not be applied directly.

## 🏁 Key Takeaway

Whenever a problem asks:

```
Count subarrays with exactly K distinct elements
```

Think:

```
At Most K - At Most (K - 1)
```

And while counting subarrays with at most `k` distinct elements, use:

```
right - left + 1
```

because every subarray starting from `left` through `right` is valid.

```
**Small correction:** The example’s correct answer is **6**, not 5.
```
