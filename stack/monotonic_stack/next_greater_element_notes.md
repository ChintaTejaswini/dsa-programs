# Next Greater Element — Monotonic Stack

## Problem

For every element in an array, find the first greater element to its right. If none exists, return `-1`.

**Example:**

`arr = {2, 5, 1, 6, 3, 8}`

**Expected output:**

`{5, 6, 6, 8, 8, -1}`

## Logic

1. Traverse the array from right to left.
2. Remove elements from the stack while the top is less than or equal to the current element.
3. If the stack is empty, the answer is `-1`.
4. Otherwise, the stack top is the next greater element.
5. Push the current element onto the stack.

## Dry Run

<img width="500" height="368" alt="image" src="https://github.com/user-attachments/assets/cd1744bf-2fa7-4cc6-8327-2c2e8786489b" />


*The stack is shown from bottom to top, so the rightmost element is the top.*

## Complexity

- Time: O(n)
- Auxiliary space: O(n)

## Key concept

A monotonic stack keeps useful candidates in order. We pop smaller or equal elements because they cannot be the next greater element for the current value.
