# Two Sum

## Problem

Find two elements whose sum equals the target.

## Approach 1 — Brute Force

Check every possible pair.

Time: O(n²)
Space: O(1)

## Approach 2 — Two Pointers

Works when the array is sorted.

- If sum > target → move right pointer left
- If sum < target → move left pointer right

Time: O(n)
Space: O(1)

If sorting is required:
Overall Time = O(n log n)

## Approach 3 — Hashing

For each element, calculate:

needed = target - current

Check whether `needed` has already been seen.

Average Time: O(n)
Space: O(n)

## Key Learning

Trade extra memory for faster lookup.

Pattern: Hashing / Complement Search