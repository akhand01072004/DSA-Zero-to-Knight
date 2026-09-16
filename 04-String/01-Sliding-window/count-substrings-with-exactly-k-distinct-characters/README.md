# README.md

📁 Path:

```
04-Strings/01-Sliding-Window/count-substrings-with-exactly-k-distinct-characters/README.md
```

Markdown

````
# Count Substrings With Exactly K Distinct Characters

## Problem

Given a string `s` and an integer `k`, count the number of substrings
that contain **exactly `k` distinct characters**.

A substring must be continuous.

---

## Example

```text
s = "pqpqs"
k = 2
````

The substrings having exactly `2` distinct characters are:

```
"pq"
"pqp"
"qp"
"qpq"
"pqpq"
"qs"
"pqs"
```

Therefore:

```
Answer = 7
```

## Why This Approach?

Directly counting substrings with exactly `k` distinct characters is slightly difficult because a window can contain:

```
1 distinct character
2 distinct characters
3 distinct characters
...
```

Instead, we use a useful mathematical trick:

```
Exactly K
=
At Most K - At Most (K - 1)
```

### Why does this work?

`At Most K` contains substrings with:

```
1, 2, 3, ..., K distinct characters
```

`At Most K - 1` contains substrings with:

```
1, 2, 3, ..., K - 1 distinct characters
```

When we subtract them, all smaller cases cancel out.

Only substrings with exactly `K` distinct characters remain.

## Example of the Formula

Suppose:

```
At Most 2 = 12
At Most 1 = 5
```

Then:

```
Exactly 2 = At Most 2 - At Most 1
Exactly 2 = 12 - 5
Exactly 2 = 7
```

Therefore, the answer is:

```
7
```

## Sliding Window Helper

We create a helper function that counts substrings with at most `k` distinct characters.

We use:

C++

```
unordered_map<char, int> freq;
```

This stores the frequency of each character inside the current window.

The `right` pointer expands the window.

If the window contains more than `k` distinct characters, we move the `left` pointer forward until the window becomes valid.

For every valid window:

```
Number of valid substrings ending at right
= right - left + 1
```

So we add:

C++

```
count += right - left + 1;
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

        freq[s[right]]++;

        while (freq.size() > k) {

            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }

            left++;
        }

        count += right - left + 1;
    }

    return count;
}

long long countSubstringsExactlyKDistinct(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    return countSubstringsAtMostKDistinct(s, k)
         - countSubstringsAtMostKDistinct(s, k - 1);
}
```

## Complexity

The helper function takes average `O(n)` time.

We call it twice:

```
At Most K
At Most K - 1
```

Therefore:

```
Time Complexity:  O(n) average
Space Complexity: O(k) active distinct characters
```

## Important Difference

### Longest Substring With Exactly K Distinct Characters

For the longest substring problem, we can directly maintain a window with at most `k` distinct characters and update the answer when the window contains exactly `k`.

We use:

C++

```
maxLength = max(
    maxLength,
    right - left + 1
);
```

### Count Substrings With Exactly K Distinct Characters

For counting, we use:

C++

```
exactlyK = atMostK - atMostKMinusOne;
```

And inside the helper:

C++

```
count += right - left + 1;
```

Remember:

```
Longest problem  → use max
Counting problem → use addition
Exactly counting → At Most K - At Most (K - 1)
```

## Pattern Recognition

Use this approach when:

* The problem asks to count substrings.

* The substring must contain exactly `K` distinct characters.

* A sliding-window solution for at most `K` is possible.

* The formula `Exactly K = At Most K - At Most (K - 1)` applies.

This is a very important sliding-window pattern.
