# ✅ Problem 26 Solution

```
DSA-Zero-to-Knight/04-Strings/01-Sliding-Window/longest-substring-with-at-most-k-distinct-characters/
```

## `solution.cpp`

C++

```
#include <bits/stdc++.h>
using namespace std;

int longestSubstringAtMostKDistinct(
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

        // Current window contains at most k distinct characters
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    string s = "eceba";
    int k = 2;

    cout << longestSubstringAtMostKDistinct(s, k)
         << endl;

    return 0;
}
```

### Output

```
3
```

## 🧠 Explanation

For:

```
s = "eceba"
k = 2
```

The longest valid substring is:

```
"ece"
```

It contains only:

```
e, c
```

So the answer is:

```
3
```

### Main logic

C++

```
while (freq.size() > k)
```

This means the current window has too many distinct characters, so we move `left` forward.

When removing a character:

C++

```
freq[s[left]]--;
```

If its frequency becomes zero:

C++

```
freq.erase(s[left]);
```

Finally, calculate the current window length:

C++

```
right - left + 1
```

# 📄 README.md — Copy and Paste

Save it here:

```
DSA-Zero-to-Knight/04-Strings/01-Sliding-Window/longest-substring-with-at-most-k-distinct-characters/README.md
```

Markdown

````
# Longest Substring With At Most K Distinct Characters

## 📌 Problem Statement

Given a string `s` and an integer `k`, find the length of the longest substring containing at most `k` distinct characters.

A substring must contain consecutive characters.

---

## 🧪 Examples

### Example 1

```text
Input:
s = "eceba"
k = 2

Output:
3
````

Explanation:

```
"ece"
```

contains only two distinct characters:

```
e, c
```

Therefore, the answer is:

```
3
```

### Example 2

```
Input:
s = "aaabb"
k = 2

Output:
5
```

Explanation:

```
"aaabb"
```

contains only two distinct characters:

```
a, b
```

Therefore, the entire string is valid.

### Example 3

```
Input:
s = "aabbcc"
k = 1

Output:
2
```

Explanation:

The longest valid substrings are:

```
"aa"
"bb"
"cc"
```

Each substring contains only one distinct character.

### Example 4

```
Input:
s = "abc"
k = 0

Output:
0
```

A substring cannot contain at most zero distinct characters unless it is empty.

## 🧠 Approach

We use:

* Sliding Window

* Two Pointers

* Frequency Map

Maintain a window:

```
[left ... right]
```

The window must contain at most `k` distinct characters.

For every character at index `right`:

1. Add the character to the frequency map.

2. If the number of distinct characters becomes greater than `k`, shrink the window.

3. Remove characters from the left side.

4. If a character's frequency becomes zero, erase it from the map.

5. Update the maximum window length.

The invalid condition is:

C++

```
freq.size() > k
```

The current window length is:

C++

```
right - left + 1
```

## 💻 C++ Solution

C++

```
#include <bits/stdc++.h>
using namespace std;

int longestSubstringAtMostKDistinct(
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

        // Shrink the window if distinct count exceeds k
        while (freq.size() > k) {

            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }

            left++;
        }

        // Current window contains at most k distinct characters
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    string s = "eceba";
    int k = 2;

    cout << longestSubstringAtMostKDistinct(s, k)
         << endl;

    return 0;
}
```

## 🔍 Dry Run

For:

```
s = "eceba"
k = 2
```

|
Right Character

|

Current Valid Window

|

Distinct Characters

|

Maximum Length

|
| --- | --- | --- | --- |
|

`e`

|

`"e"`

|

1

|

1

|
|

`c`

|

`"ec"`

|

2

|

2

|
|

`e`

|

`"ece"`

|

2

|

3

|
|

`b`

|

`"ceb"`

|

3 → shrink

|

3

|
|

`a`

|

`"ba"`

|

2

|

3

|

Final answer:

```
3
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

Each character enters the sliding window once and leaves the window at most once.

Therefore, both pointers move forward at most `n` times.

### Space Complexity

```
O(min(n, character-set-size))
```

The frequency map stores the distinct characters present in the current window.

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

* Handling a maximum number of distinct characters

* Finding the longest valid substring

## ⚠️ Important Rules

### Add the right character

C++

```
freq[s[right]]++;
```

### Remove the left character

C++

```
freq[s[left]]--;
left++;
```

### Erase a character when its frequency becomes zero

C++

```
if (freq[s[left]] == 0) {
    freq.erase(s[left]);
}
```

### Shrink while the window is invalid

C++

```
while (freq.size() > k)
```

### Calculate window length

C++

```
right - left + 1
```

## 🏁 Key Takeaway

Whenever a problem asks for the:

```
Longest substring with at most K distinct characters
```

Think:

```
Sliding Window + Two Pointers + Frequency Map
```

The main condition is:

```
Number of distinct characters <= K
```

If the condition becomes invalid:

```
Number of distinct characters > K
```

move the left pointer forward until the window becomes valid again.

```
## ⏱️ Complexity

- **Average Time:** `O(n)`
- **Space:** `O(min(n, character-set-size))`

Great work, brother! This is the same sliding-window pattern you learned for arrays, now applied to strings. 💪
```
