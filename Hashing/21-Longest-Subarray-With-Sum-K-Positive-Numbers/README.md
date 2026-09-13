
# Longest Subarray With Sum K — Positive Numbers

## Problem

Given an array containing only positive integers and an integer `K`, find the length of the longest contiguous subarray whose sum is exactly `K`.

### Example

```text
Input:
arr = [1, 2, 2, 3, 1, 2, 3, 1, 3, 3]
K = 5

Output:
3
```

### Explanation

The longest valid subarray is:

```text
[1, 2, 2]
```

Its sum is:

```text
1 + 2 + 2 = 5
```

Its length is:

```text
3
```

---

## Approach: Sliding Window / Two Pointers

Because every element is positive:

- Expanding the window increases the sum.
- Shrinking the window decreases the sum.
- If the current sum is greater than `K`, remove elements from the left.
- If the current sum equals `K`, calculate the window length.

We maintain two pointers:

```text
left  → beginning of the window
right → end of the window
```

---

## Algorithm

1. Initialize:
   - `left = 0`
   - `sum = 0`
   - `maxLength = 0`
2. Move `right` from `0` to `n - 1`.
3. Add `arr[right]` to `sum`.
4. While `sum > K`:
   - Subtract `arr[left]`.
   - Move `left` forward.
5. If `sum == K`, update the maximum length.
6. Return `maxLength`.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumKPositiveNumbers(
    const vector<int>& arr,
    int k
) {
    int n = arr.size();

    int left = 0;
    int sum = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > k) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLength = max(
                maxLength,
                right - left + 1
            );
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {
        1, 2, 2, 3, 1,
        2, 3, 1, 3, 3
    };

    int k = 5;

    cout << longestSubarrayWithSumKPositiveNumbers(
        arr,
        k
    );

    return 0;
}
```

---

## Output

```text
3
```

---

## Dry Run

For:

```text
arr = [1, 2, 2, 3, 1, 2, 3, 1, 3, 3]
K = 5
```

| `left` | `right` | Window | Sum | Maximum Length |
|---:|---:|---|---:|---:|
| 0 | 0 | `[1]` | 1 | 0 |
| 0 | 1 | `[1,2]` | 3 | 0 |
| 0 | 2 | `[1,2,2]` | 5 | 3 |
| 2 | 3 | `[2,3]` | 5 | 3 |
| 3 | 4 | `[3,1]` | 4 | 3 |
| 4 | 5 | `[1,2]` | 3 | 3 |
| 5 | 6 | `[2,3]` | 5 | 3 |
| 6 | 7 | `[3,1]` | 4 | 3 |
| 7 | 8 | `[1,3]` | 4 | 3 |
| 8 | 9 | `[3]` after shrinking | 3 | 3 |

Final answer:

```text
3
```

---

## Complexity Analysis

### Time Complexity

```text
O(N)
```

Although there is a nested `while` loop, each element:

- Enters the window once.
- Leaves the window at most once.

Therefore, the total work is linear.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## Important Limitation

This sliding-window approach works because all array elements are positive.

It is not generally valid when negative numbers are present.

For arrays containing negative numbers, use:

```text
Prefix Sum + HashMap
```

### Comparison

| Array Type | Recommended Approach |
|---|---|
| Positive numbers only | Sliding Window |
| Positive and negative numbers | Prefix Sum + HashMap |
| Zeroes and positive numbers | Sliding Window, with care |
| Arbitrary integers | Prefix Sum + HashMap |

---

## Key Pattern

> Positive numbers + longest subarray with exact sum K  
> → Sliding Window / Two Pointers