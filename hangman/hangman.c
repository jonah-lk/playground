#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct GameWord {
    char word[24];
    char hint[64];
};

struct GameWord words[] = {
    {"jonah", "Fish boy!"},
    {"caesar", "Beware the ides of March!"},
    {"belisarius", "The GOAT!"},
    {"saka", "Star boy!"}
};

int main() {
    int gameOn = 1;

    while(gameOn) {
        srand(time(NULL));
        int secretWordIndex = rand() % (sizeof(words) / sizeof(words[0]));
    
        const char* secretWord = words[secretWordIndex].word;
        const char* secretHint = words[secretWordIndex].hint;
        int attempts = strlen(secretWord);
    
        char playerGuessed[attempts];
        memset(playerGuessed, 0, sizeof(playerGuessed));
        int guessedLetters[26] = { 0 };
        
        while(attempts >= 0) {
        system("cls");
    
            int guessLen = 0;
    
            printf("\n\n\n\n\t\t\t\t\t\tWelcome to hangman!");
            
            printf("\n\n\t\t\t\t\t\tHint: %s", secretHint);
            printf("\n\n\t\t\t\t\t\tWord: ");
            for (int i = 0; i < strlen(secretWord); i++) {
                if(secretWord[i] == playerGuessed[i]) {
                    printf("%c", secretWord[i]);
                    guessLen++;
                }
                else
                    printf("*");
            }
    
            if(guessLen == strlen(secretWord)) {
                printf("\n\n\n\n\t\t\t\t\t\tYou have guessed the word.\n\t\t\t\t\t\t");
                printf("\n\n\n\n\t\t\t\t\t\t'%c'\n\t\t\t\t\t\t", playerGuessed);
                printf("\n\n\n\n\t\t\t\t\t\tYou still had %d attempts.\n\t\t\t\t\t\t", attempts);
                printf("\n\n\n\n\t\t\t\t\t\tPress x to exit, or anywhere else to start over.\n\t\t\t\t\t\t");
                char input;
                scanf(" %c", &input);
    
                if(input == 'x')
                    gameOn = 0;

                break;;
            }
    
            printf("\n\n\n\n\t\t\t\t\t\tWhat's your guess?\n\t\t\t\t\t\t");
            char guess;
            scanf(" %c", &guess);
    
            if(guessedLetters[guess - 'a']) {
                printf("\n\n\n\n\t\t\t\t\t\tYou have already guessed that letter?");
                printf("\n\n\t\t\t\t\t\tPress anywhere to continue!\n\t\t\t\t\t\t");
                scanf(" %c", &guess);
                continue;
            }
    
            for (int i = 0; i < strlen(secretWord); i++) {
                if(guess == secretWord[i]) {
                    playerGuessed[i] = guess;
                    guessedLetters[guess - 'a'] = 1;
                }
            }
            
            attempts--;
        }
    }

    return 0;
}