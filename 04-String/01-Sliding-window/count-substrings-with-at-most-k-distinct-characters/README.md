# README.md

Path: `04-Strings/01-Sliding-Window/count-substrings-with-at-most-k-distinct-characters/README.md`


# Count Substrings With At Most K Distinct Characters

## Problem

Given a string `s` and an integer `k`, count the number of substrings
that contain **at most `k` distinct characters**.

A substring must be continuous.

---

## Example

```text
s = "pqpqs"
k = 2
````

The valid substrings are:

```
"p"
"q"
"p"
"q"
"s"

"pq"
"qp"
"pq"
"qp"

"pqp"
"qpq"
"pqp"

"pqpq"
```

Total:

```
12
```

Therefore, the answer is:

```
12
```

## Why This Approach?

A string of length `n` contains:

```
n * (n + 1) / 2
```

total substrings.

Checking every substring separately would take `O(n²)` or more time.

Instead, we use the Sliding Window + Frequency Map approach.

The sliding window maintains a substring containing at most `k` distinct characters.

We use:

C++

```
unordered_map<char, int> freq;
```

to store the frequency of every character inside the current window.

## Main Idea

We maintain two pointers:

```
left
right
```

The `right` pointer expands the window by adding characters.

If the window contains more than `k` distinct characters, we move the `left` pointer forward until the window becomes valid again.

For every valid window:

```
number of valid substrings ending at right
= right - left + 1
```

Why?

Suppose the current valid window is:

```
s[left ... right]
```

Then all these substrings are also valid:

```
s[right]
s[right-1 ... right]
s[right-2 ... right]
...
s[left ... right]
```

There are exactly:

```
right - left + 1
```

such substrings.

So we add:

C++

```
count += right - left + 1;
```

## Dry Run

```
s = "abc"
k = 2
```

### right = 0

Window:

```
"a"
```

Distinct characters:

```
1
```

Valid substrings ending at index `0`:

```
"a"
```

Count:

```
1
```

### right = 1

Window:

```
"ab"
```

Distinct characters:

```
2
```

Valid substrings ending at index `1`:

```
"b"
"ab"
```

Add:

```
2
```

Total:

```
1 + 2 = 3
```

### right = 2

Window becomes:

```
"abc"
```

Distinct characters:

```
3
```

This is invalid because:

```
3 > k
```

Move `left` forward and remove `'a'`.

New window:

```
"bc"
```

Distinct characters:

```
2
```

Valid substrings ending at index `2`:

```
"c"
"bc"
```

Add:

```
2
```

Final answer:

```
1 + 2 + 2 = 5
```

## C++ Solution

C++

```
#include <bits/stdc++.h>
using namespace std;

long long countSubstringsAtMostKDistinct(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    unordered_map<char, int> freq;

    int left = 0;
    long long count = 0;

    for (int right = 0; right < s.size(); right++) {

        // Add current character
        freq[s[right]]++;

        // Shrink the window if it has more than k
        // distinct characters
        while (freq.size() > k) {

            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }

            left++;
        }

        // Every substring ending at right and
        // starting from left to right is valid
        count += right - left + 1;
    }

    return count;
}
```

## Important Difference

For finding the longest substring:

C++

```
maxLength = max(
    maxLength,
    right - left + 1
);
```

For counting substrings:

C++

```
count += right - left + 1;
```

### Remember

```
Longest problem  → use max
Counting problem → use addition
```

## Complexity

* Time Complexity: `O(n)` average

* Space Complexity: `O(k)` active distinct characters

Each character enters the window once and leaves the window at most once.

Therefore, the two pointers together move at most `2n` times.

## Pattern Recognition

Use this approach when the problem asks:

* Count substrings

* At most `K` distinct characters

* Continuous substring

* Need to count all valid windows

The key formula is:

C++

```
count += right - left + 1;
```

This formula counts all valid substrings ending at the current `right` pointer.
