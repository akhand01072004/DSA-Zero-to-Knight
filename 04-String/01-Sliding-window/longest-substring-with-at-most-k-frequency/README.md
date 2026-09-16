`
# Longest Substring With At Most K Frequency

## Problem

Given a string `s` and an integer `k`, find the length of the longest
substring in which no character appears more than `k` times.

A substring must be continuous.

---

## Example

```text
s = "aabacbebebe"
k = 2
````

One longest valid substring is:

```
"abacbebe"
```

Its character frequencies are:

```
a → 2
b → 2
c → 1
e → 2
```

Every character appears at most `2` times.

Therefore:

```
Answer = 8
```

## Why This Approach?

We use the Sliding Window + Frequency Map approach.

The substring must be continuous, so instead of generating every possible substring, we maintain a window using two pointers:

```
left
right
```

The `right` pointer expands the window by adding a new character.

We use a frequency map to store how many times each character appears inside the current window.

For example:

```
Window = "aaba"
```

The frequency map stores:

```
a → 3
b → 1
```

If:

```
k = 2
```

then this window is invalid because `a` appears `3` times.

## Main Idea

### Step 1: Expand the Window

Move the `right` pointer forward and add the current character to the frequency map.

```
freq[s[right]]++
```

### Step 2: Check Whether the Window Is Invalid

The window becomes invalid when the newly added character appears more than `k` times.

```
freq[s[right]] > k
```

### Step 3: Shrink the Window

Move the `left` pointer forward and decrease the frequency of the characters being removed.

Continue shrinking until the window becomes valid again.

The general rule is:

```
While the window is invalid:
    remove the character at left
    move left forward
```

### Step 4: Update the Answer

Once the window becomes valid, its length is:

```
right - left + 1
```

We update the maximum length:

```
maxLength = max(maxLength, right - left + 1)
```

## Dry Run

```
s = "aab"
k = 2
```

### Window: `"a"`

```
a → 1
```

The window is valid.

Length:

```
1
```

Maximum length:

```
1
```

### Window: `"aa"`

```
a → 2
```

The window is still valid because `a` appears at most `2` times.

Length:

```
2
```

Maximum length:

```
2
```

### Window: `"aab"`

```
a → 2
b → 1
```

Every character appears at most `2` times.

Length:

```
3
```

Maximum length:

```
3
```

Final answer:

```
3
```

## Why Sliding Window Works

When the current window is valid, adding a new character can only increase the frequency of that character.

If its frequency becomes greater than `k`, the window is invalid.

We then remove characters from the left until the frequency becomes valid again.

At every step, the window contains only valid substrings for the current `right` pointer.

Therefore, we only need to track the longest valid window instead of checking every substring separately.

## Important Difference From Other Sliding Window Problems

In many sliding-window problems, we check:

```
number of distinct characters > k
```

Here, we check:

```
frequency of a character > k
```

These are different conditions.

For example:

```
Window = "aabbc"
```

The number of distinct characters is:

```
3
```

But the maximum frequency is:

```
2
```

If `k = 2`, this window is valid for the current problem because no character appears more than `2` times.

## Complexity

Let `n` be the length of the string.

Each character enters the window once and leaves the window at most once.

Therefore:

```
Time Complexity: O(n) average
Space Complexity: O(number of distinct characters)
```

For a fixed character set, the extra space is effectively `O(1)`.

## Pattern Recognition

Use this approach when:

* The problem asks for the longest substring.

* The substring must be continuous.

* A frequency of any character must stay within a limit.

* The condition is based on character frequency.

* We can restore validity by shrinking the window from the left.

The main pattern is:

```
Expand right
Update frequency
Shrink while invalid
Update maximum length
```
