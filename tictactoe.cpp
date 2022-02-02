#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define player1move 'X'
#define player2move 'O'
void showBoard1(){
    printf("\n\n");
    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");
    return;
}
void showBoard(char board[3][3]){
    printf("\n\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],board[2][1], board[2][2]);
    return;
}
bool row(char board[3][3]){
    for(int i=0;i<3;i++){
        if (board[i][0] == board[i][1] &&board[i][1] == board[i][2] && board[i][0] != ' ') return (true);
    }
    return(false);
}
bool column(char board[3][3]){
    for (int i=0; i<3; i++){
        if (board[0][i] == board[1][i] &&board[1][i] == board[2][i] && board[0][i] != ' ') return (true);
    }
    return(false);
}
bool diagonal(char board[3][3]){
    if (board[0][0] == board[1][1] &&board[1][1] == board[2][2] && board[0][0] != ' ') return(true);
    if (board[0][2] == board[1][1] &&board[1][1] == board[2][0] &&board[0][2] != ' ') return(true);
    return(false);
}
bool gameOver(char board[3][3]){
    return(row(board) || column(board)|| diagonal(board));
}
void move(char playermove,char board[3][3]){
    int mv;
    cout<<"Enter the box number to play your move: ";
    cin>>mv;
    if(mv>9 || mv<1) cout<<"Number should be less than 10 and greater than 0";
    else 
    switch(mv){
        case 1:  board[0][0]= playermove;
        break;
        case 2:  board[0][1]= playermove;
        break;
        case 3:  board[0][2]= playermove;
        break;
        case 4:  board[1][0]= playermove;
        break;
        case 5:  board[1][1]= playermove;
        break;
        case 6:  board[1][2]= playermove;
        break;
        case 7:  board[2][0]= playermove;
        break;
        case 8:  board[2][1]= playermove;
        break;
        case 9:  board[2][2]= playermove;
        break;
    }
}
void whoseMove(char playermove,char board[3][3]){
    int wm = 1;
    while(wm < 10 && gameOver(board)==false){
        if(wm%2!=0){
            playermove = player1move;
            move(playermove,board);
            showBoard(board);
        }else{
            playermove = player2move;
            move(playermove,board);
            showBoard(board);
        }
        wm++;
    }
    if(wm%2==0 && wm<10){
        cout<<"Player 1(X) has won ";
    }else if(wm==10){
        cout<<"Game Drawn ";
    }if(wm%2!=0&&wm<10){
        cout<<"Player 2(O) has won ";
    }
}
int main(){
    cout<<"Player 1 is X and Player 2 is O"<<endl;
    char board[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
    showBoard1();
    char playermove=' ';
    whoseMove(playermove,board);
} 