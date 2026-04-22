# Design Decisions

## 1. Reimplement stdlib functions instead of using existing ones
- **Reason:** Educational purpose - understand how things work under the hood
- **Trade-off:** Functions may have bugs/inefficiencies vs battle-tested libc functions

## 2. `typedef char * string`
- **Reason:** Pedagogical simplification to make code more readable for beginners
- **Trade-off:** Hides pointer semantics, may cause confusion about memory ownership

## 3. Heap allocation for toupper/tolower
- **Reason:** Return a new string without modifying the original (immutability)
- **Trade-off:** Caller must remember to call free(); risk of memory leaks

## 4. Levenshtein Distance for strcmp_percent
- **Reason:** Robust and well-known algorithm for string similarity
- **Trade-off:** O(n*m) complexity in both space and time; dynamically allocates a matrix

## 5. Raylib for UI (AI-generated)
- **Reason:** Interactive visual demonstration of backend functions
- **Trade-off:** Heavy dependency for an educational project; the UI is AI-generated, not by the author

## 6. Backend/UI separation
- **Reason:** Core logic independent from presentation; allows testing backend in isolation
- **Accepted trade-off:** Correct approach - easier maintenance and future testing

## 7. STR_BUFFER = 256 as a global limit
- **Reason:** Prevent buffer overflow; simple and predictable limit
- **Trade-off:** Limits functionality; larger strings are silently rejected

## 8. my_strlen returning 0 as error sentinel
- **Reason:** Simplicity - no result structs or elaborate error codes
- **Trade-off:** Ambiguity - 0 can mean empty string OR error (NULL, overflow)

## 9. CMake as build system
- **Reason:** Replaced Makefile for better cross-platform portability
- **Migrated in:** commit e8008f8

## 10. README in 3 languages
- **Reason:** Accessibility; international portfolio
- **Languages:** English (main), Portuguese BR, Simplified Chinese
