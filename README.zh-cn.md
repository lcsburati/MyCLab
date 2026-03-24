# MyCLib

[English Version](README.md) | [Versão em Português](README.pt-br.md)

## 重要提示 (Important Notice)

> **本 README 由 AI 生成，因我仍在学习普通话，尚未达到能够独立撰写的能力。内容已经过我的审核和批准。**
>
> 本项目仅用于学习目的。
>
> **后端代码**（`src/` 中的所有 C 实现）是我**手动编写，未使用 AI 辅助**，这是我从根本上理解 C 语言工作原理的学习之旅的一部分。
>
> **界面**使用 AI 代理创建。其唯一目的是提供更好的视觉体验来演示后端功能——它**不是**本项目的重点。

---

**目标：** 展示我对 C 语言的了解及其特性。

这个项目是我自己实现的库和算法集合，旨在理解底层的工作原理。

## 如何运行

你可以使用 `gcc` 编译项目：

```bash
gcc main.c -I./include -o main.out
./main.out
```

## 函数

### 字符串工具 (String Utils)

*   **my_strlen**: 使用指针运算返回字符串的长度。
*   **my_tolower**: 将字符串转换为小写（返回新分配的字符串）。
*   **my_toupper**: 将字符串转换为大写（返回新分配的字符串）。
*   **my_strcmp**: 字典序比较两个字符串。如果相等返回 `0`，如果 str1 较大返回 `1`，如果 str2 较大返回 `-1`。
*   **my_strcmp_percent**: 使用 Levenshtein 距离算法计算字符串相似度。返回百分比 (0-100)。

### 数学工具 (Math Utils)

*   **min**: 返回三个整数中的最小值（用于 `my_strcmp_percent` 的动态规划）。
