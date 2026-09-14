
# Longest Subarray With Exactly K Distinct Elements

## Problem

Given an array of integers and an integer `K`, find the length of the longest contiguous subarray containing **exactly K distinct elements**.

---

## Example

```text
Input:
arr = [1, 2, 1, 2, 3]
K = 2

Output:
4
```

### Explanation

The longest valid subarray is:

```text
[1, 2, 1, 2]
```

Its distinct elements are:

```text
1 and 2
```

Therefore, it contains exactly `2` distinct elements.

Length:

```text
4
```

---

## Approach: Sliding Window + Frequency Map

We use:

```cpp
unordered_map<int, int> freq;
```

The map stores:

```text
element → frequency inside the current window
```

We maintain two pointers:

```text
left  → beginning of the window
right → end of the window
```

### Window Rules

1. Expand the window by moving `right`.
2. Add `arr[right]` to the frequency map.
3. If the window contains more than `K` distinct elements, shrink it from the left.
4. While shrinking:
   - Decrease the frequency of `arr[left]`.
   - If its frequency becomes zero, erase it from the map.
   - Move `left` forward.
5. When the window contains exactly `K` distinct elements, update the maximum length.

---

## Important Conditions

### Invalid Window

```cpp
freq.size() > K
```

The window contains too many distinct elements, so we shrink it.

### Valid Window

```cpp
freq.size() == K
```

Only then can we update the answer.

Do not use:

```cpp
freq.size() <= K
```

because that would also accept windows containing fewer than `K` distinct elements.

---

## Algorithm

1. Initialize `left = 0`.
2. Initialize `maxLength = 0`.
3. Traverse the array using `right`.
4. Increase the frequency of `arr[right]`.
5. While the number of distinct elements is greater than `K`:
   - Decrease the frequency of `arr[left]`.
   - Erase the element if its frequency becomes zero.
   - Increment `left`.
6. If the number of distinct elements equals `K`, update the maximum length.
7. Return `maxLength`.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithExactlyKDistinct(
    const vector<int>& arr,
    int k
) {
    if (k <= 0 || arr.empty()) {
        return 0;
    }

    unordered_map<int, int> freq;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {

        freq[arr[right]]++;

        while (freq.size() > k) {

            freq[arr[left]]--;

            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }

            left++;
        }

        if (freq.size() == k) {
            maxLength = max(
                maxLength,
                right - left + 1
            );
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << longestSubarrayWithExactlyKDistinct(arr, k);

    return 0;
}
```

---

## Output

```text
4
```

---

## Dry Run

For:

```text
arr = [1, 2, 1, 2, 3]
K = 2
```

| Right | Current Window | Distinct Count | Action | Maximum Length |
|---:|---|---:|---|---:|
| 0 | `[1]` | 1 | Not valid yet | 0 |
| 1 | `[1,2]` | 2 | Valid | 2 |
| 2 | `[1,2,1]` | 2 | Valid | 3 |
| 3 | `[1,2,1,2]` | 2 | Valid | 4 |
| 4 | `[1,2,1,2,3]` | 3 | Shrink from left | 4 |

After adding `3`, the window has three distinct elements:

```text
1, 2, 3
```

Since:

```text
3 > K
```

we shrink the window until only two distinct elements remain.

The final valid window is:

```text
[2, 1, 2, 3]
```

Its distinct elements are:

```text
2, 1, 3
```

Actually, after shrinking correctly, the window becomes:

```text
[2, 3]
```

which contains exactly two distinct elements.

The previous maximum remains:

```text
4
```

---

## Complexity Analysis

### Time Complexity

```text
Average: O(N)
```

Each element:

- Enters the window once.
- Leaves the window at most once.

Hash-map insertion, lookup, and deletion take average `O(1)` time.

Therefore, the total average time complexity is `O(N)`.

### Space Complexity

```text
O(K)
```

The map stores the distinct elements in the current window.

In the worst case, the space can be:

```text
O(N)
```

---

## Edge Cases

### Case 1: K is zero

```text
arr = [1, 2, 3]
K = 0
```

No non-empty subarray contains exactly zero distinct elements.

Output:

```text
0
```

### Case 2: K is greater than the number of distinct elements

```text
arr = [1, 2, 1]
K = 5
```

No valid subarray exists.

Output:

```text
0
```

### Case 3: All elements are identical

```text
arr = [7, 7, 7, 7]
K = 1
```

The entire array is valid.

Output:

```text
4
```

---

## Important Difference

### At Most K Distinct

```cpp
freq.size() <= K
```

### Exactly K Distinct

```cpp
freq.size() == K
```

For both problems, the invalid condition is:

```cpp
freq.size() > K
```

The difference is when we update the answer.

---

## Key Pattern

> Longest subarray with exactly K distinct elements  
> → Sliding Window + Frequency Map

### Recognition Clues

Look for phrases such as:

- Exactly K distinct elements
- Exactly K different numbers
- Longest substring with exactly K unique characters
- Maximum window containing K types

---

## Important Note

For counting subarrays with exactly K distinct elements, a common formula is:

```text
Exactly K =
At Most K - At Most (K - 1)
```

For this problem, which asks for the **longest length**, we can solve directly:

1. Shrink when distinct count exceeds `K`.
2. Update the answer only when distinct count equals `K`.