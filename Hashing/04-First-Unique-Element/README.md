## What I Learned

"First" means the original array order.

A map sorts keys, so iterating over a map does not
preserve the order in which elements appeared.

Solution:
1. Build a frequency map.
2. Traverse the original array again.
3. Return the first element whose frequency is 1.

Time: O(n) average
Space: O(n)