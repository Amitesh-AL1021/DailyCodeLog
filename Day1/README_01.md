# 🧮 Fibonacci Number – C++ Recursive Solution

## 📌 Problem Statement

Write a function to compute the `n`th Fibonacci number.  
The Fibonacci sequence is defined as:

- `fib(0) = 0`
- `fib(1) = 1`
- For `n > 1`: `fib(n) = fib(n - 1) + fib(n - 2)`

---

## ✅ Approach

We use **recursion** to solve the problem. The base cases are:

- Return `n` if `n` is 0 or 1.
- For any other `n`, recursively call `fib(n-1)` and `fib(n-2)` and return their sum.

---

## 🧠 Algorithm

1. If `n <= 1`, return `n`.
2. Else, return `fib(n-1) + fib(n-2)`.

---

## ⏱️ Time Complexity

- **O(2^n)** — Exponential time due to repeated subproblems.

---

## 💾 Space Complexity

- **O(n)** — Due to the recursive call stack (height of recursion tree is `n`).

---

## 🚀 Sample Run

### Input:
