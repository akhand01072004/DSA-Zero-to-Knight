`
# Longest Substring With Exactly K Distinct Characters

## 📌 Problem Statement

Given a string `s` and an integer `k`, find the length of the longest substring containing exactly `k` distinct characters.

A substring must contain consecutive characters.

If no valid substring exists, return `0`.

---

## 🧪 Examples

### Example 1

```text
Input:
s = "aabacbebebe"
k = 3

Output:
7
````

Explanation:

```
"cbebebe"
```

contains exactly three distinct characters:

```
c, b, e
```

Therefore, the answer is:

```
7
```

### Example 2

```
Input:
s = "aaaa"
k = 2

Output:
0
```

There is no substring containing exactly two distinct characters.

### Example 3

```
Input:
s = "aabbcc"
k = 2

Output:
4
```

Possible longest valid substrings are:

```
"aabb"
"bbcc"
```

Each substring contains exactly two distinct characters.

### Example 4

```
Input:
s = "abc"
k = 1

Output:
1
```

Every single character is a valid substring.

## 🧠 Approach

We use:

* Sliding Window

* Two Pointers

* Frequency Map

Maintain a window:

```
[left ... right]
```

The window must contain exactly `k` distinct characters.

For every character at index `right`:

1. Add the character to the frequency map.

2. If the number of distinct characters becomes greater than `k`, shrink the window.

3. Remove characters from the left side.

4. If a character's frequency becomes zero, erase it from the map.

5. If the window contains exactly `k` distinct characters, update the maximum length.

## 🔍 Window Conditions

### Invalid Window

The window is invalid when:

C++

```
freq.size() > k
```

In this case, move the left pointer forward.

### Valid Window

The window is valid when:

C++

```
freq.size() == k
```

Only then should we update the answer.

### Current Window Length

C++

```
right - left + 1
```

## 💻 C++ Solution

C++

```
#include <bits/stdc++.h>
using namespace std;

int longestSubstringExactlyKDistinct(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    unordered_map<char, int> freq;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++) {

        // Add the current character
        freq[s[right]]++;

        // Shrink the window if distinct characters exceed k
        while (freq.size() > k) {

            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }

            left++;
        }

        // Update answer only for exactly k distinct characters
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

    string s = "aabacbebebe";
    int k = 2;

    cout << longestSubstringExactlyKDistinct(
        s,
        k
    ) << endl;

    return 0;
}
```

## 🧪 Test Case

### Input

```
s = "aabacbebebe"
k = 2
```

### Output

```
6
```

### Explanation

The longest substring containing exactly two distinct characters is:

```
"bebebe"
```

The distinct characters are:

```
b, e
```

Therefore, the answer is:

```
6
```

## ⏱️ Complexity Analysis

Let:

```
n = s.size()
```

### Time Complexity

```
Average: O(n)
```

Each character enters the window once and leaves the window at most once.

Therefore, both pointers move forward at most `n` times.

### Space Complexity

```
O(min(n, character-set-size))
```

The frequency map stores the characters present in the current window.

For a fixed character set such as ASCII, the space complexity is effectively:

```
O(1)
```

## 🎯 Pattern Learned

This problem teaches:

* Sliding Window

* Two Pointers

* Frequency Map

* Maintaining a valid window

* Handling exactly `k` distinct characters

* Finding the longest valid substring

## ⚠️ Important Difference

### At Most K Distinct

C++

```
freq.size() <= k
```

### Exactly K Distinct

C++

```
freq.size() == k
```

For this problem, do not update the answer when the window contains fewer than `k` distinct characters.

## 🏁 Key Takeaway

Whenever a problem asks for:

```
Longest substring with exactly K distinct characters
```

Think:

```
Sliding Window + Two Pointers + Frequency Map
```

The main rules are:

```
If distinct characters > K:
    Shrink the window

If distinct characters == K:
    Update the answer
```

The current window length is always:

C++

```
right - left + 1
```
