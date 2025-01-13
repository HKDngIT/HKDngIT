#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define MAX_ATTEMPTS 6
#define DICTIONARY_FILE "/Users/vanni/CLionProjects/ProjektAbgabe/wortliste.txt"

// Deklaration von wichtigen Attributen
void human_as_Player();
void human_as_guesser();
void display_hangman(int attempts);
char* select_random_word();
void initialize_guessed_word(char* guessed_word, int length);
int update_hangman_status(char guess, const char* word, char* guessed_word);


int main() {
    int choice;

    printf("Herzlich Willkommen zum Galgenmännchen-Spiel! :) \n\n");
    while (1) {
        printf("Wählen Sie bitte einen Spielmodus aus...:\n");
        printf("1. Mensch gegen Computer (Computer rät)\n");
        printf("2. Computer gegen Mensch (Mensch rät)\n");
        printf("3. Beenden\n");
        printf("Ihre Wahl: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            human_as_Player();
                break;
            case 2:
                human_as_guesser();
                break;
            case 3:
                printf("Vielen Dank für das Mitspielen! :) \n");
                exit(0);
            default:
                printf("Ungültige Wahl. Bitte erneut versuchen.\n");
        }
    }
    return 0;
}

void human_as_Player() {
    char secret_word[MAX_WORD_LENGTH];
    char guessed_word[MAX_WORD_LENGTH];
    char guessed_letters[26] = {0};
    int attempts = 0;
    int correct_guesses = 0;

    printf("Geben Sie ein geheimes Wort ein (bitte mindestens 5 Buchstaben): ");
    scanf("%s", secret_word);

    if (strlen(secret_word) < 5) {
        printf("Erneuter Versuch, bitte mindestens 5 Buchstaben eingeben!\n");
        return;
    }

    int word_length = strlen(secret_word);
    initialize_guessed_word(guessed_word, word_length);

    while (attempts < MAX_ATTEMPTS && correct_guesses < word_length) {
        printf("\nIhr aktueller Stand: %s\n", guessed_word);
        printf("Bereits verwendete Buchstaben: %s\n", guessed_letters);

        char guess = 'a' + (rand() % 26);
        while (strchr(guessed_letters, guess)) {
            guess = 'a' + (rand() % 26);
        }

        if (strlen(guessed_letters) < sizeof(guessed_letters) - 1) {
            guessed_letters[strlen(guessed_letters)] = guess;
            guessed_letters[strlen(guessed_letters) + 1] = '\0';
        } else {
            printf("Fehler: Maximale Anzahl an Buchstaben erreicht.\n");
            return;
        }

        printf("Computer rät: %c\n", guess);

        int found = update_hangman_status(guess, secret_word, guessed_word);
        correct_guesses += found;

        if (found) {
            printf("Richtig! Der Buchstabe '%c' ist im Wort enthalten!\n", guess);
        } else {
            printf("Falsch! Der Buchstabe '%c' ist nicht im Wort enthalten...\n", guess);
            attempts++;
            display_hangman(attempts);
        }
    }

    if (correct_guesses == word_length) {
        printf("\nDer Computer hat das Wort erraten: %s\n", guessed_word);
    } else {
        printf("\nDer Computer hat verloren! Das geheime Wort war: %s\n", secret_word);
    }
}

void human_as_guesser() {
    char* word = select_random_word();
    if (!word) {
        printf("Wörterbuchdatei konnte nicht geladen werden.\n");
        return;
    }

    int word_length = strlen(word);
    char guessed_word[MAX_WORD_LENGTH];
    char guessed_letters[26] = {0};
    int attempts = 0;
    int correct_guesses = 0;

    initialize_guessed_word(guessed_word, word_length);

    printf("Das Wort hat %d Buchstaben.\n", word_length);

    while (attempts < MAX_ATTEMPTS && correct_guesses < word_length) {
        printf("\nAktueller Stand: %s\n", guessed_word);
        printf("Verwendete Buchstaben: %s\n", guessed_letters);
        printf("Geben Sie einen Buchstaben ein: ");

        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (strchr(guessed_letters, guess)) {
            printf("Bereits verwendeter Buchstabe. Bitte erneut versuchen.\n");
            continue;
        }

        if (strlen(guessed_letters) < sizeof(guessed_letters) - 1) {
            guessed_letters[strlen(guessed_letters)] = guess;
            guessed_letters[strlen(guessed_letters) + 1] = '\0';
        } else {
            printf("Fehler: Maximale Anzahl an Buchstaben erreicht.\n");
            return;
        }

        int found = update_hangman_status(guess, word, guessed_word);
        correct_guesses += found;

        if (found) {
            printf("Richtig! Der Buchstabe '%c' ist im Wort.\n", guess);
        } else {
            printf("Falsch! Der Buchstabe '%c' ist nicht im Wort.\n", guess);
            attempts++;
            display_hangman(attempts);
        }
    }

    if (correct_guesses == word_length) {
        printf("\nSuper gelöst! Das Wort war: %s\n", word);
    } else {
        printf("\nLeider verloren! Das Wort war: %s\n", word);
        printf("Das Spiel ist beendet. Versuchen Sie es erneut!\n");
    }

    free(word);
}

void display_hangman(int attempts) {
    const char* hangman[] = {
            "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=======\n",
            "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=======\n",
            "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=======\n",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=======\n",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=======\n"
    };
    if (attempts > 0 && attempts <= MAX_ATTEMPTS) {
        printf("%s", hangman[attempts - 1]);
    }
}

void initialize_guessed_word(char* guessed_word, int length) {
    for (int i = 0; i < length; i++) {
        guessed_word[i] = '_';
    }
    guessed_word[length] = '\0';
}

int update_hangman_status(char guess, const char* word, char* guessed_word) {
    int found = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == guess) {
            guessed_word[i] = guess;
            found = 1;
        }
    }
    return found;
}

char* select_random_word() {
    FILE* file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        perror("Fehler beim Öffnen der Wörterbuchdatei");
        return NULL;
    }

    char buffer[MAX_WORD_LENGTH];
    char* selected_word = NULL;
    int count = 0;

    while (fgets(buffer, MAX_WORD_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Entfernt das Newline-Zeichen
        if (strlen(buffer) >= 5) {
            if (rand() % (++count) == 0) {
                if (selected_word) free(selected_word);
                selected_word = strdup(buffer);
            }
        }
    }

    fclose(file);
    return selected_word;
}
