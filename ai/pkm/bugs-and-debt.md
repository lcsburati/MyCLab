# Known Bugs and Technical Debt

## Bugs - HIGH Severity

### 1. my_strcmp reads past null terminator
- **File:** `src/string_utils.c:117-171`
- **Problem:** When strings have different lengths, the function continues reading past the shorter string's `\0`, causing undefined behavior
- **Impact:** Invalid memory read, unpredictable results

### 2. my_strcmp has incorrect semantics
- **File:** `src/string_utils.c:117-171`
- **Problem:** Always returns +/-1 based on length, not lexicographic comparison like standard strcmp
- **Example:** "zz" vs "aaa" returns -1 (shorter), but should return positive ('z' > 'a')

### 3. Unchecked malloc in my_strcmp_percent
- **File:** `src/string_utils.c:173-228`
- **Problem:** Neither the outer allocation nor the inner loop allocations check malloc's return for NULL
- **Impact:** If an allocation fails mid-loop, previous allocations leak and the code dereferences NULL (crash)

### 4. my_strlen returns 0 for 256-char strings
- **File:** `src/string_utils.c:10-30`
- **Problem:** Returns 0 for strings with exactly STR_BUFFER (256) characters, indistinguishable from empty string
- **Impact:** Silent data loss

### 5. Unsafe atoi() usage
- **File:** `src/main.c:66`
- **Problem:** atoi() has undefined behavior on overflow and cannot distinguish "0" from non-numeric input like "hello"
- **Fix:** Use `strtol()` with error checking

## Bugs - MEDIUM Severity

### 6. Signed/unsigned mismatch
- Several comparisons between `size_t` (unsigned) and `int` (signed) generate 13+ warnings
- Risk of subtle bugs in comparisons with negative values

### 7. Missing const-correctness
- Input parameters should be `const string` to prevent accidental modification
- Prevents safe API usage

### 8. Missing `<stddef.h>` in string_utils.h
- `size_t` is used without including the header that defines it

### 9. Per-frame allocation in tolower/toupper
- **File:** `src/main.c:39-48`
- At 60 FPS, allocates and frees 256-byte strings 60x/second = unnecessary heap churn

### 10. Non-static global Font
- **File:** `src/ui.c`
- `Font mainFont` is globally visible, should be static

## Technical Debt - LOW Severity

### 11. `typedef char * string` obscures pointer semantics
- Pedagogical decision by the author, but may cause confusion about ownership and mutability

### 12. Code duplication between toupper/tolower
- 40+ identical lines between the two functions; could share a helper function

### 13. Hardcoded font path
- `resources/font.ttf` with no fallback if the file doesn't exist

### 14. No automated test suite
- Only manual testing via GUI

### 15. Unused Section enum
- **File:** `include/ui.h`
- `SECTION_STRING, SECTION_MATH` declared but the sidebar uses hardcoded arrays instead

## From TODO.md

1. Interface breaks with very long strings (even within buffer)
2. Incorrect input handling (atoi) - covered above
3. Matrix allocation failure handling - covered above
4. Automated tests - planned
