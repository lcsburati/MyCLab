# API Reference

## Constants

| Name | Value | Header | Description |
|------|-------|--------|-------------|
| `OFFSET` | 32 | string_utils.h | ASCII difference between uppercase and lowercase |
| `STR_BUFFER` | 256 | string_utils.h | Maximum accepted string size |

## Types

```c
typedef char * string;  // Alias for char* (pedagogical decision)
```

## String Utilities (`string_utils.h`)

### `my_strlen`
```c
size_t my_strlen(string str);
```
- **Purpose:** Calculates string length
- **Returns:** String length, or 0 if NULL/overflow
- **Null-safe:** Yes, returns 0
- **Buffer:** Returns 0 if >= STR_BUFFER (256)
- **File:** `src/string_utils.c:10-30`

### `my_toupper`
```c
string my_toupper(string str);
```
- **Purpose:** Converts string to UPPERCASE
- **Returns:** New heap-allocated string (caller must free()), or NULL if invalid input
- **Allocation:** `malloc(len + 1)`
- **Logic:** Subtracts OFFSET (32) from chars between 'a'-'z'
- **File:** `src/string_utils.c:32-71`

### `my_tolower`
```c
string my_tolower(string str);
```
- **Purpose:** Converts string to lowercase
- **Returns:** New heap-allocated string (caller must free()), or NULL if invalid input
- **Allocation:** `malloc(len + 1)`
- **Logic:** Adds OFFSET (32) to chars between 'A'-'Z'
- **File:** `src/string_utils.c:73-115`

### `my_strcmp`
```c
int my_strcmp(string str1, string str2);
```
- **Purpose:** Compares two strings
- **Returns:** 0 = equal, 1 = str1 greater, -1 = str1 smaller
- **Null-safe:** Yes
- **WARNING:** Different semantics from standard strcmp (length-based, not lexicographic)
- **File:** `src/string_utils.c:117-171`

### `my_strcmp_percent`
```c
double my_strcmp_percent(string str1, string str2);
```
- **Purpose:** Calculates similarity percentage between two strings
- **Returns:** 0.0 to 100.0 (similarity percentage)
- **Algorithm:** Levenshtein distance with dynamic programming
- **Matrix:** (len1+1) x (len2+1) with insertion, deletion and substitution costs
- **Formula:** `100 * (1 - distance / max_length)`
- **File:** `src/string_utils.c:173-228`

## Math Utilities (`math_utils.h`)

### `min`
```c
int min(int a, int b, int c);
```
- **Purpose:** Returns the smallest of three integers
- **Logic:** Nested ternary operators
- **Used by:** `my_strcmp_percent` internally
- **File:** `src/math_utils.c:3-7`

## UI (`ui.h`) - AI-generated

| Function | Description |
|----------|-------------|
| `InitUI()` | Initializes Raylib window, loads font |
| `CloseUI()` | Unloads font, closes window |
| `DrawNavButton()` | Sidebar navigation button with hover effect |
| `DrawInputField()` | Input field with placeholder and cursor |
| `DrawResultCard()` | Result panel with label and bar |
| `DrawPercentageBar()` | Percentage bar with colors |
| `HandleTextInput()` | Captures keyboard input |
| `DrawSidebar()` | Sidebar with function buttons |
| `PageHeader()` | Page title and subtitle |
| `RenderStrlenPage()` | my_strlen demo page |
| `RenderToLowerPage()` | my_tolower demo page |
| `RenderToUpperPage()` | my_toupper demo page |
| `RenderStrcmpPage()` | my_strcmp demo page |
| `RenderStrcmpPctPage()` | my_strcmp_percent demo page |
| `RenderMinPage()` | min() demo page |
