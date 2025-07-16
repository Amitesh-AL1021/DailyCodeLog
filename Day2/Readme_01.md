# LeetCode 137: Single Number II 🔢

## 🧠 Problem Statement

Given an integer array `nums` where every element appears **three times** except for **one**, which appears **exactly once**, find that single one.

You must implement a solution with **O(n)** runtime and **O(1)** space.

---

## 💡 Example


---

## ✅ Approach: Bit Manipulation

We use two variables:
- `ones` to track bits that have appeared once.
- `twos` to track bits that have appeared twice.

### Logic:
- When a bit appears the first time, it's added to `ones`.
- When it appears the second time, it goes to `twos`.
- When it appears the third time, it's cleared from both.

This way, only the unique number remains in `ones`.

---

## 🧾 Code Explanation

```cpp
ones = (ones ^ num) & ~twos;
twos = (twos ^ num) & ~ones;
