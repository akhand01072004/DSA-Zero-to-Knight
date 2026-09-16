Here is the README.md ready to copy and paste, brother! 🔥

Save it at:

```
DSA-Zero-to-Knight/04-Strings/01-Sliding-Window/longest-substring-without-repeating-characters/README.md
```

Markdown

````
# Longest Substring Without Repeating Characters

## 📌 Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

A substring must contain consecutive characters.

---

## 🧪 Examples

### Example 1

#### Input

```text
s = "abcabcbb"
````

#### Output

```
3
```

#### Explanation

The longest substrings without repeating characters include:

```
"abc"
```

Therefore, the answer is:

```
3
```

### Example 2

#### Input

```
s = "bbbbb"
```

#### Output

```
1
```

#### Explanation

The only valid substring is:

```
"b"
```

### Example 3

#### Input

```
s = "pwwkew"
```

#### Output

```
3
```

#### Explanation

The longest valid substring is:

```
"wke"
```

Its length is:

```
3
```

### Example 4

#### Input

```
s = ""
```

#### Output

```
0
```

## 🧠 Approach

We use:

* Sliding Window

* Two Pointers

* Frequency Map

Maintain a window:

```
[left ... right]
```

The window must contain only unique characters.

For every character at index `right`:

1. Add the character to the frequency map.

2. If the character becomes duplicated, move `left` forward.

3. Remove characters from the frequency map while shrinking.

4. Once the window becomes valid, update the maximum length.

The current window length is:

```
right - left + 1
```

## 🔍 Why Do We Remove `s[left]`?

When a duplicate character appears, we move the left pointer forward.

The character leaving the window is:

C++

```
s[left]
```

Therefore, we must decrease:

C++

```
freq[s[left]]--;
```

We should not decrease:

C++

```
freq[s[right]]--;
```

because `right` is the newly added character.

## 💻 C++ Solution

C++

```
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string& s) {

    int left = 0;
    int maxLength = 0;

    unordered_map<char, int> freq;

    for (int right = 0; right < s.size(); right++) {

        // Add the current character
        freq[s[right]]++;

        // Shrink the window while a duplicate exists
        while (freq[s[right]] > 1) {

            freq[s[left]]--;
            left++;
        }

        // Current window contains unique characters
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    string str = "pwwkew";

    cout << lengthOfLongestSubstring(str) << endl;

    return 0;
}
```

## 🧪 Dry Run

For:

```
s = "pwwkew"
```

|
Right Character

|

Valid Window

|

Window Length

|

Maximum

|
| --- | --- | --- | --- |
|

`p`

|

`"p"`

|

1

|

1

|
|

`w`

|

`"pw"`

|

2

|

2

|
|

`w`

|

`"w"`

|

1

|

2

|
|

`k`

|

`"wk"`

|

2

|

2

|
|

`e`

|

`"wke"`

|

3

|

3

|
|

`w`

|

`"kew"`

|

3

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

Each character enters the window once and leaves the window at most once.

Therefore, both pointers move forward at most `n` times.

### Space Complexity

```
O(min(n, character-set-size))
```

The frequency map stores characters currently present in the window.

For a fixed character set such as ASCII, the space complexity is effectively:

```
O(1)
```

## 🎯 Pattern Learned

This problem teaches:

* Sliding Window

* Two Pointers

* Frequency Map

* Handling duplicates

* Shrinking an invalid window

* Maintaining the longest valid window

## ⚠️ Important Rules

For longest substring/subarray problems:

C++

```
right - left + 1
```

is the current window length.

When shrinking the window:

C++

```
freq[s[left]]--;
left++;
```

The general pattern is:

C++

```
for (int right = 0; right < n; right++) {

    // Add the current element

    while (window is invalid) {
        // Remove the leftmost element
        left++;
    }

    // Window is valid
    answer = max(answer, right - left + 1);
}
```

## 🏁 Key Takeaway

Whenever the problem asks:

```
Longest substring without repeating characters
```

Think:

```
Sliding Window + Two Pointers + Frequency Map
```

The window must always remain valid:

```
No character should appear more than once.
```
