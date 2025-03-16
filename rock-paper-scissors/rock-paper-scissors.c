#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char player, char computer);

int main() {
    int random;

    char player, computer, input;

    int result, end = 0, playerScore = 0, computerScore = 0;
    
    while(!end) {
        system("cls");

        srand(time(NULL)); // This seeds the pseudo-random number generator used by rand() with the current timestamp in seconds. If you don't seed it, rand() will produce the same sequence of numbers each time your program runs.
    
        random = rand() % 100; // 0 - 99
    
        if(random < 33)
            computer = 's';
        else if(random < 66)
            computer = 'p';
        else
            computer = 'r';
        
        printf("\n\n\n\n\t\t\t\tEnter r for ROCK, p for PAPER and s for SCISSORS\n\t\t\t\t\t\t\t");
        scanf(" %c", &player);

        result = game(player, computer);

        if(result == -1) 
            printf("\n\n\t\t\t\tGame Draw!\n");
        else if (result == 1) {
            playerScore++;
            printf("\n\n\t\t\t\tWow! You have won the game!\n");
        }
        else {
            computerScore++;
            printf("\n\n\t\t\t\tOh! You have lost the game!\n");
        }

        printf("\t\t\t\tYou choose : %c and Computer choose : %c\n", player, computer);
        printf("\t\t\t\tYou won : %d and Computer won : %d\n", playerScore, computerScore);
        
        printf("\t\t\t\tClick on keyboard to replay, or on 'x' to exit.\n\t\t\t\t\t\t\t");
        scanf(" %c", &input);

        if(input == 'x')
            end = 1;
    }
    

    return 0;
}

int game(char player, char computer) {
    // Tie
    if(player == computer)
        return -1;

    if(
        player == 's' && computer == 'p' ||
        player == 'r' && computer == 's' ||
        player == 'p' && computer == 'r'
    )
        return 0; // Player wins (scissors beats paper, rock beats scissors, paper beats rock)
    else if (
        player == 'p' && computer == 's' ||
        player == 's' && computer == 'r' ||
        player == 'r' && computer == 'p'
    )
        return 1; // Computer wins
}