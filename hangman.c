#include <stdio.h>
#include <string.h>

#define MAX_LIVES 6

// Function to check player's guess and update the displayed word
int check_guess(char guess, const char secret_word[], char display_word[]) {
    int correct = 0;
    for (int i = 0; secret_word[i] != '\0'; i++) {
        if (secret_word[i] == guess && display_word[i] == '_') {
            display_word[i] = guess;
            correct = 1;
        }
    }
    return correct;
}

// Function to check if the player has won
int has_won(const char display_word[]) {
    for (int i = 0; display_word[i] != '\0'; i++) {
        if (display_word[i] == '_') {
            return 0; // not yet won
        }
    }
    return 1; // all letters guessed
}

int main() {
    const char secret_word[] = "MENTOR"; // Change this word as you like
    char display_word[sizeof(secret_word)];
    int lives = MAX_LIVES;
    char guess;

    // Initialize display_word with underscores
    for (int i = 0; secret_word[i] != '\0'; i++) {
        display_word[i] = '_';
    }
    display_word[strlen(secret_word)] = '\0';

    printf("Welcome to Hangman!\n");

    while (lives > 0 && !has_won(display_word)) {
        printf("\nWord: ");
        for (int i = 0; display_word[i] != '\0'; i++) {
            printf("%c ", display_word[i]);
        }
        printf("\nLives left: %d\n", lives);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        // Convert guess to uppercase if needed
        if (guess >= 'a' && guess <= 'z') {
            guess -= 32;
        }

        if (!check_guess(guess, secret_word, display_word)) {
            printf("Wrong guess!\n");
            lives--;
        } else {
            printf("Correct guess!\n");
        }
    }

    if (has_won(display_word)) {
        printf("\nCongratulations! You won! The word was: %s\n", secret_word);
    } else {
        printf("\nYou lost! The word was: %s\n", secret_word);
    }

    return 0;
}
