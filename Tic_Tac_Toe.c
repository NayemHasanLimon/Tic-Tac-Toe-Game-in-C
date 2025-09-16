#include<stdio.h>

void draw(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
}

int logic(char board[3][3]){
    for(int i = 0; i < 3; i++){
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return 1;
        }
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return 1;
        }
    }

    if(board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return 1;
    }
    if(board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return 1;
    }
    return 0;
}

int isDraw(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}

int userInput(char board[3][3], int n, int type){
    char ch = (type == 1) ? 'O' : 'X';
    int i, j;
    switch (n){
    case 1: i = 0; j = 0; break;
    case 2: i = 0; j = 1; break;
    case 3: i = 0; j = 2; break;
    case 4: i = 1; j = 0; break;
    case 5: i = 1; j = 1; break;
    case 6: i = 1; j = 2; break;
    case 7: i = 2; j = 0; break;
    case 8: i = 2; j = 1; break;
    case 9: i = 2; j = 2; break;
    default:
        printf("Choose a correct number (1-9)\n");
        return 1;
    }

    if(board[i][j] == ' '){
        board[i][j] = ch;
    }else{
        printf("Box already taken! Choose again\n");
        return 1;
    }
    return 0;
}

int main(){
    printf("=== Tic-Tac-Toe Game ===\n");
    printf("How to play: boxes numbered 1 to 9\n");
    printf("1 2 3\n4 5 6\n7 8 9\n");

    char board[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';

    int n;
    int player = 1;

    while (1){
        draw(board);
        do{
            if (player == 1){
                printf("Player1 (O) : ");
                scanf("%d", &n);
            }
            else{
                printf("Player2 (X) : ");
                scanf("%d", &n);
            }
        }while (userInput(board, n, player));

        if (logic(board)) {
            draw(board);
            if (player == 1)
                printf("Player 1 (O) wins!\n");
            else 
                printf("Player 2 (X) wins!\n");
            break;
        }      

        if (isDraw(board)) {
            draw(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }
    
    return 0;
}
