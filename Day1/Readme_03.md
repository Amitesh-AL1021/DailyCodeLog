# 🧮 Euclidean Algorithm – GCD Finder (C++)

## 📌 Problem Statement
Given two integers `a` and `b`, find their **Greatest Common Divisor (GCD)** — the largest integer that divides both `a` and `b` without leaving a remainder.

---

## 💡 Approach: Euclidean Algorithm
The Euclidean Algorithm is based on the principle:
Repeat the process until `b` becomes 0. At that point, `a` will be the GCD.

---

## 🔁 Example
**Input:** `a = 48`, `b = 18`  
**Steps:**


---

## 🧠 Algorithm Steps
1. While `b` is not 0:
   - Calculate `a % b`
   - Update `a = b`
   - Update `b = a % b`
2. When `b = 0`, return `a` as the GCD.

---

## ⏱️ Time and Space Complexity
- **Time Complexity:** O(log(min(a, b)))
- **Space Complexity:** O(1)

---

## 📂 Files
- `gcd.cpp` – C++ implementation using the Euclidean Algorithm
- `README.md` – Explanation and usage

---

## 📥 Sample Input/Output
