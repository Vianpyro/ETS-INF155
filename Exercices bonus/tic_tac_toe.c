/*
    Tic tac toe terminal game
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define FFLUSH while(getchar() != '\n') {} // A inserer devant tous les scanf()!

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void reset();
void print_board();
int check_free_spaces();
void player_move();
void computer_move();
char check_winner();
void print_winner(char winner);

int main(void) {
    char winner;
    char response;

    do {
        reset();
        winner = ' ';
        
        while (winner == ' ' && check_free_spaces() != 0) {
            print_board();
            player_move();
            winner = check_winner();
            if (winner != ' ' || check_free_spaces() == 0) break;
            computer_move();
            winner = check_winner();
        }
        print_board();
        print_winner(winner);

        printf("Would you like to play again? (Y/N): ");
        FFLUSH;
        scanf("%c", &response);
        response = tolower(response);
    } while (response == 'y');

    printf("Thanks for playing!\n");
    system("pause");
    return EXIT_SUCCESS;
}

void reset() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
}

void print_board() {
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_free_spaces() {
    int free_spaces = 9;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] != ' ') free_spaces--;
        }
    }

    return free_spaces;
}

void player_move() {
    int x, y;

    do {
        printf("Enter row and column number you want to play #(1-3): ");
        scanf("%d%d", &x, &y);

        x--; y--;

        if (board[x][y] != ' ')
            printf("Invalid move!\n");
        else {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computer_move() {
    srand(time(NULL));
    int x, y;

    if (check_free_spaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    } else print_winner(' ');
    
}

char check_winner() {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            return board[row][0];
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col]) {
            return board[0][col];
        }
    }

    // Check diagonals
    if ((board[1][1] == board[0][0] && board[1][1] == board[2][2]) || (board[1][1] == board[0][2] && board[1][1] == board[2][0])) {
        return board[1][1];
    }
    
    return ' ';
}

void print_winner(char winner) {
    if (winner == PLAYER) printf("YOU WIN!\n");
    else if (winner == COMPUTER) printf("YOU LOSE :(\n");
    else printf("It's a tie...\n");
}
