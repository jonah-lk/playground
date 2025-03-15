// Libraries
#include <conio.h> // kbhit(), getch()
#include <ctype.h> // tolower()
#include <stdio.h>
#include <stdlib.h> // rand()
#include <windows.h> // Sleep()

// Macros
#define HEIGHT 20
#define WIDTH 40

// Snake coordinates
int snakeTailX[100], snakeTailY[100];
// Length of tail
int snakeTailLen;
// Score and flags
int gameover, key, score;
// Head and fruit coordinates
int x, y, fruitX, fruitY;

// Start of game; snake in middle, fruit random inside boundary, gameovere and score to default
void setup() {
    // Gameover signal
    gameover = 0;

    // Initial snake coordinates
    x = WIDTH / 2;
    y = HEIGHT / 2;

    // Initial coordinates of fruit
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    while (fruitX == 0)
        fruitX = rand() % WIDTH;
    while (fruitY == 0)
        fruitY = rand() % HEIGHT;

    // Initial score
    score = 0;
}

// Draw game
void draw() {
    system("cls");
    
    // Top wall
    for(int i = 0; i < WIDTH + 2; i++)
        printf("#");

    printf("\n");

    // Side walls and snake and fruit
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j <= WIDTH; j++) {
            // Side walls
            if(j == 0 || j == WIDTH)
                printf("#");

            // Snake and fruit
            if(i == y && j == x)
                printf("O");
            else if(i == fruitY && j == fruitX)
                printf("*");
            else {
                int prTail = 0;

                for(int k = 0; k < snakeTailLen; k++) {
                    if(snakeTailX[k] == j && snakeTailY[k] == i) {
                        printf("o");
                        prTail = 1;
                    }
                }

                if(!prTail)
                    printf(" ");
            }
        }

        printf("\n");
    }

    // Bottom wall
    for(int i = 0; i < WIDTH + 2; i++)
        printf("#");
    
    printf("\n");

    // Score, and instructions
    printf("Score: %d. \n", score);
    printf("Press w, s, a and d arrows to move.\n");
    printf("Press X to quit game.\n");
}

// Get inputs
void input() {
    if(kbhit()) {
        switch (tolower(getch())) {
        case 'a':
            if(key != 2)
                key = 1;
            break;
        
        case 'd':
            if(key != 1)
                key = 2;
            break;
        
        case 'w':
            if(key != 4)
                key = 3;
            break;
        
        case 's':
            if(key != 3)
                key = 4;
            break;
        
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// Movement logic
void snake() {
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;

    snakeTailX[0] = x;
    snakeTailY[0] = y;

    // Move snake body
    for(int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];

        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move head
    switch (key) {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }

    // Is game over?
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameover = 1;

    // Collision with tail
    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            gameover = 1;
    }

    // Eat fruit
    if(x == fruitX && y == fruitY) {
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        while (fruitX == 0)
            fruitX = rand() % WIDTH;
        while (fruitY == 0)
            fruitY = rand() % HEIGHT;

        score += 10;
        snakeTailLen++;
    }
}

int main() {
    // Setup start
    setup();

    while (!gameover) {
        draw();
        input();
        snake();
    }

    if(gameover) {
        system("cls");
        printf("Score: %d.\n", score);
        getchar();
        Sleep(100);
    }
    
    return 0;
}