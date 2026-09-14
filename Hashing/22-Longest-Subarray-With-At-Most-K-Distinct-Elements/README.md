
# Longest Subarray With At Most K Distinct Elements

## Problem

Given an array of integers and an integer `K`, find the length of the longest contiguous subarray containing **at most K distinct elements**.

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

It contains only two distinct elements:

```text
1 and 2
```

Its length is:

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
2. Add the current element to the frequency map.
3. If the number of distinct elements becomes greater than `K`, shrink the window.
4. While shrinking:
   - Decrease the frequency of `arr[left]`.
   - If its frequency becomes zero, erase it from the map.
   - Move `left` forward.
5. Once the window becomes valid, update the maximum length.

The window is invalid when:

```cpp
freq.size() > K
```

---

## Algorithm

1. Initialize `left = 0`.
2. Initialize `maxLength = 0`.
3. Traverse the array using `right`.
4. Increase the frequency of `arr[right]`.
5. While the window contains more than `K` distinct elements:
   - Decrease the frequency of `arr[left]`.
   - Erase the element if its frequency becomes zero.
   - Increment `left`.
6. Calculate the current window length:

```cpp
right - left + 1
```

7. Update `maxLength`.
8. Return `maxLength`.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayAtMostKDistinct(
    const vector<int>& arr,
    int k
) {
    unordered_map<int, int> freq;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {

        // Add current element to the window
        freq[arr[right]]++;

        // Shrink while distinct elements exceed k
        while (freq.size() > k) {

            freq[arr[left]]--;

            // Remove element when its frequency becomes zero
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }

            left++;
        }

        // Window is valid
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << longestSubarrayAtMostKDistinct(arr, k);

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

| Right | Current Window | Distinct Elements | Action | Maximum Length |
|---:|---|---:|---|---:|
| 0 | `[1]` | 1 | Valid | 1 |
| 1 | `[1,2]` | 2 | Valid | 2 |
| 2 | `[1,2,1]` | 2 | Valid | 3 |
| 3 | `[1,2,1,2]` | 2 | Valid | 4 |
| 4 | `[1,2,1,2,3]` | 3 | Shrink from left | 4 |

When `3` is added, the window contains three distinct elements:

```text
1, 2, 3
```

Since:

```text
3 > K
```

we shrink from the left until only two distinct elements remain.

The final answer is:

```text
4
```

---

## Why Do We Need Frequencies?

A simple set is not enough because an element may occur multiple times inside the window.

Example:

```text
Window = [1, 2, 1]
```

Frequencies:

```text
1 → 2
2 → 1
```

If we remove one `1`, the frequency becomes:

```text
1 → 1
```

The element `1` is still present, so we must not erase it.

Only when its frequency becomes zero do we remove it from the map.

```cpp
if (freq[arr[left]] == 0) {
    freq.erase(arr[left]);
}
```

---

## Complexity Analysis

### Time Complexity

```text
Average: O(N)
```

Each element is:

- Added to the window once.
- Removed from the window at most once.

Therefore, the total work is linear on average.

### Space Complexity

```text
O(K)
```

The map stores the distinct elements in the current window.

In the worst case:

```text
O(N)
```

if the window contains many distinct elements.

---

## Important Edge Cases

### Case 1: K is zero

```text
arr = [1, 2, 3]
K = 0
```

No non-empty subarray is valid.

Answer:

```text
0
```

### Case 2: K is greater than or equal to the number of distinct elements

```text
arr = [1, 2, 1, 3]
K = 5
```

The entire array is valid.

Answer:

```text
4
```

### Case 3: All elements are the same

```text
arr = [7, 7, 7, 7]
K = 1
```

The entire array is valid.

Answer:

```text
4
```

---

## Key Pattern

> Longest contiguous subarray with at most K distinct elements  
> → Sliding Window + Frequency Map

### Recognition Clues

Look for phrases such as:

- At most K distinct elements
- Longest substring with K different characters
- Longest window containing limited unique values
- Maximum length with no more than K types

---

## Important Limitation

This technique is naturally suited to the **at most K** condition.

For exactly K distinct elements, a common technique is:

```text
Exactly K distinct
=
At most K distinct
-
At most K - 1 distinct
```

That is a useful pattern for future problems.