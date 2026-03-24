# MyCLib

[Read in Portuguese](README.pt-br.md) | [中文版](README.zh-cn.md)

## Important Notice

> **This project is for learning purposes only.**
> 
> The **backend code** (all C implementations in `src/`) was written **manually without AI assistance**, as part of my journey to deeply understand how C works under the hood.
> 
> The **interface** (frontend layer for visualizing and interacting with the backend) was created using AI agents. Its sole purpose is to provide a better visual experience for demonstrating backend functionality - it is **not** the focus of this project.

---

**Objective:** To show my knowledge about the C language and its particularities.

This project is a collection of my own implementations of libraries and algorithms, aiming to understand how things work under the hood.

## How to Run

You can compile the project using `gcc`:

```bash
gcc main.c -I./include -o main.out
./main.out
```

## Functions

### String Utils

*   **my_strlen**: Returns the length of a string using pointer arithmetic.
*   **my_tolower**: Converts a string to lowercase (returns a new allocated string).
*   **my_toupper**: Converts a string to uppercase (returns a new allocated string).
*   **my_strcmp**: Compares two strings lexicographically. Returns `0` if equal, `1` if str1 is larger, `-1` if str2 is larger.
*   **my_strcmp_percent**: Calculates string similarity using Levenshtein distance algorithm. Returns a percentage (0-100).

### Math Utils

*   **min**: Returns the minimum of three integers (used by `my_strcmp_percent` for dynamic programming).
