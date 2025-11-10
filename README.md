# Hangman – Word Guessing Game (C Capstone)

A clean, well-documented C implementation of the classic Hangman game. The program stores a secret word, tracks player guesses, shows progress with underscores, and cleanly handles win/loss conditions.

> **Why this is a deliverable (not just a demo):**  
> The code is modular (functions), readable (comments & formatting), and robust (input validation, duplicate-guess handling).  
> The README explains the “why” behind design choices and highlights the light data/Maths angle (letter-frequency hinting).

---

## 1) Project Title & Description
**Title:** Hangman – Word Guessing Game (Console)  
**Description:** A terminal-based Hangman. The computer chooses a hard-coded secret word (e.g., `MENTOR`). The player guesses letters with a limited number of lives. The program updates the revealed word and ends with a clear win/loss message.

---

## 2) Concepts Used

### C (Day 1–6)
- **char arrays:** secret word and display word (underscores)  
- **loops:** `while` for main game loop; `for` for array iteration  
- **conditionals:** `if/else` for match checks and end states  
- **functions:** `init_display`, `print_state`, `apply_guess`, `is_complete`, `read_letter`, `show_intro`  
- **pointers:** arrays are passed/handled via pointers; string iteration with indices  
- **stdio/string:** `printf`, `scanf`-free line read via `getchar()` to sanitize input, `strlen`, `toupper`  

### Maths / Data (Day 5–6)
- **Data intuition:** Players perform an implicit **probability-based** search: common English letters (E, T, A, O, …) should be guessed earlier.  
- **Implementation:** A small **letter-frequency** heuristic suggests a next letter among the unguessed ones (`ENGLISH_FREQ = "ETAOINSHRDLCUMWFGYPBVKJXQZ"`).  
- **Why it matters:** This reflects a simple data-driven strategy. In a larger extension, we could learn frequencies from a corpus and compute expected information gain per guess.

---

## 3) How to Compile

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o hangman
