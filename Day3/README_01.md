# LeetCode Problem 7: Reverse Integer

## 🧠 Problem Statement

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ - 1], return 0.

---

## 🚀 Approach

We extract each digit of the number by using modulo and divide operations:
- `% 10` gives the last digit.
- `/ 10` removes the last digit.
- We keep building the reversed number.

Before adding a digit, we check if the result would overflow the 32-bit integer range:
- If `reversed > INT_MAX` or `reversed < INT_MIN`, return 0.

---

## 🛠️ Algorithm

1. Initialize a variable `reversed = 0`.
2. Loop until `x` becomes 0:
   - Extract the last digit `digit = x % 10`.
   - Update `reversed = reversed * 10 + digit`.
   - Check for overflow.
   - Divide `x` by 10.
3. Return the reversed number (casted to int).

---

## 🧮 Time and Space Complexity

| Type             | Complexity     |
|------------------|----------------|
| Time Complexity  | O(log₁₀N)      |
| Space Complexity | O(1)           |

We only use constant space and iterate through each digit of the number.

---

## 💻 Example

**Input:** `x = 123`  
**Output:** `321`

**Input:** `x = -456`  
**Output:** `-654`

**Input:** `x = 1534236469`  
**Output:** `0` _(overflow)_

---

## 📁 Files

- `reverse-integer.cpp` - C++ solution file with full code
- `README.md` - Problem explanation, approach, algorithm, and complexity

