# Deep Dive into C.

[Read in Portuguese](README.pt-br.md)

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

*   **my_strlen**:
    *   **Args:** char array (String).
    *   **Return:** integer (String length).
    *   **Process:** I start by declaring a `length` variable outside the loop to prevent it from resetting. A `while` loop was chosen because I prefer to work with pointer arithmetic. (But a `for` loop with a control variable `i` could also be used).
        Inside the `while` loop, we increment both the `length` counter and the pointer itself. Since `*str` starts by pointing to the first element (`str[0]`), incrementing the pointer allows us to step through each memory address until we hit the `\0` which has a value of 0 (`false`). Finally, we return the length.

*   **my_tolower**:
    *   **Args:** char array (String).
    *   **Return:** char array (String).
    *   **Process:** I start by declaring the variable that will serve to define the size of the string (using the previously created function) and allocating a new string with `malloc`. Although characters are always 1 byte, I chose to make `sizeof(char)` explicit for better readability. Then, I ensure that the allocation was successful (otherwise, the function returns NULL). Next, I declare the pointer `*current`, which will serve as a cursor, while `*result` will function as our anchor. After that, I define the distance between 'a' and 'A' to facilitate the conversion, since this value is constant in the ASCII table. I then start the `while` loop, chosen to work with pointer arithmetic. The first step of the conversion is to know if the element of `*str` is in uppercase; to do this, we just need to check if it is within the range ['A', 'Z'] (which the compiler will understand as integers due to ASCII encoding). If it is, I define that the cursor pointer `*current` will receive the value of `*str` plus the calculated distance (defined as static const OFFSET = 'a' - 'A' -> I chose to use the direct difference to improve readability and prevent issues in case the system is switched from ASCII or UTF-8 to other character encodings.), converting the character to lowercase. Then, we increment the cursor pointer and the base array to move to the next character in both. We don't do this increment in `*result`, as we need this pointer to continue pointing to the first element of the array for the final return. If the character is already lowercase or a symbol, `*current` simply receives the original value of `*str`. Finally, we point the last element of `*current` as the null terminator `\0` and return `result`.

*   **my_toupper**:
    *   **Args:** char array (String).
    *   **Return:** char array (String).
    *   **Process:** We follow the same process as `my_tolower`, changing only the `if (*str >= 'A' && *str <= 'Z')` to `if (*str >= 'a' && *str <= 'z')`, since we now want to update lowercase values.

*   **my_strcmp**:
    *   **Args:** const char *st1, const char *str2
    *   **Return:** Integer (If the strings are the same size it returns 0, if string 2 is larger it returns 1, and if string 1 is smaller it returns -1).
    *   **Process:** I start by declaring the variables that will receive the sizes of the strings, and using my own `my_strlen` I check the size of each string. After that, I start the first layer of verification which is about the sizes of each string and begin the process of verification character by character with the same logic of pointer arithmetic (here it wasn't necessary to create an anchor because the word itself wouldn't be necessary for the function).

*   **my_strcmp_percent**:
    *   **Args:** const char *str1, const char *str2
    *   **Return:** Double (Percentage of similarity between strings).
    *   **Process:** I start by calculating the length of each string using `my_strlen`. Then, I dynamically allocate a 2D matrix of size `(str1_length + 1) x (str2_length + 1)` using `malloc` to compute the Levenshtein distance. The first row and column of the matrix are initialized with incremental values representing the cost of inserting or deleting characters. Next, I fill the matrix using the classic dynamic programming approach: for each pair of characters, I calculate the cost (0 if they match, 1 otherwise) and take the minimum between insertion, deletion, and substitution using my own `min` function from `math_utils.h`. Once the matrix is fully computed, the Levenshtein distance is found at `matrix[str1_length][str2_length]`. I then convert this distance into a similarity percentage based on the maximum length of the two strings. If both strings are empty, the function returns 100.0. Finally, I free all dynamically allocated memory row by row, and then the matrix itself, to avoid memory leaks.

### Math Utils

(Coming soon...)
