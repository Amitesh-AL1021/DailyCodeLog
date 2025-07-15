# 🧗‍♂️ Leetcode 70 - Climbing Stairs

## 📌 Problem Statement
You are climbing a staircase. It takes `n` steps to reach the top.  
Each time you can either climb 1 or 2 steps.  
Return how many distinct ways you can climb to the top.

---

## 💡 Approach: Iterative (Bottom-Up DP)

We observe that:
- Ways to reach step `n` = ways to reach `n-1` + `n-2`
- This is a Fibonacci pattern.

We use a **loop with two variables** to store the last two results and build the answer.

---

## 🧠 Algorithm in 5 Steps

1. If `n <= 1`, return 1.
2. Initialize `first = 1`, `second = 1`
3. Loop from `i = 2` to `n`:
    - `result = first + second`
    - update `first = second`, `second = result`
4. Return `result` as the answer.

---

## 🕒 Time and Space Complexity

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

## 📂 Files

- `climb_stairs.cpp` – main code
- `README.md` – explanation

---

## ✅ Sample Input/Output

### Input:
