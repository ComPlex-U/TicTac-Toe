#include <iostream>
#include <string>

using namespace std;

class game{
    public:
        void run(){
            clearBoard();
            bool isDone = false;
            int turn = 0;
            char player1 = 'x';
            char player2 = 'o';
            string player3 = "Player 1";
            string player4 = "Player 2";
            char currentPlayer = player1;
            string currentPlayer1 = player3;
            while(isDone == false){
                cout << currentPlayer1 << "'s turn" << endl;
                printBoard();
                if(input(getX(),getY(),currentPlayer) == false){
                    cout << "That spot is already taken" << endl;
                    isDone = false;
                }
                else{
                    if(winner(currentPlayer)==true){
                        cout << currentPlayer1 << " Has Won!" <<endl;
                        isDone = true;
                    }
                    else if(turn == 9){
                        cout << "It was A Tie!";
                        isDone = true;
                    }
                    if(currentPlayer == 'x'){
                        currentPlayer = player2;
                        currentPlayer1 = player4;
                    }
                    else{
                        currentPlayer = player1;
                        currentPlayer1 = player3;
                    }
                    turn ++;
                }
            }
            printBoard();
        }
    private:
        bool winner(char currentPlayer){
            for(int i=0;i<3;i++){
                if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == currentPlayer){
                    return true;
                }
                if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == currentPlayer){
                    return true;
                }
            }
            if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer){
                return true;
            }
            if(board[2][0] == currentPlayer && board[1][1] == currentPlayer && board[0][2] == currentPlayer){
                return true;
            }
            return false;
        }
        bool input(int x, int y, char currentPlayer){
            if(board[y][x] != ' '){
                return false;
            }
            else{
                board[y][x] = currentPlayer;
                return true;
            }
        }
        int getX(){
            int x;
            bool istrue = false;
            while(istrue == false){
                cout << "Where do you want it horizontally? ";
                cin >> x;
                if(x<1||x>3){
                    cout << endl <<"That is an invalid input" << endl;
                }
                else{
                    return x-1;
                }
            }
        }
        int getY(){
            int y;
            bool istrue = false;
            while(istrue == false){
                cout << "Where do you want it vertically? ";
                cin >> y;
                if(y<1||y>3){
                    cout << endl <<"That is an invalid input" << endl;
                }
                else{
                    return y-1;
                }
            }
        }
        void clearBoard(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    board[i][j] = ' ';
                }
            }  
        }
        void printBoard(){
            cout << "      1 2 3 " << endl << "     -------" << endl << "    ";
            for(int i=0;i<3;i++){
                    cout << i+1;
                for(int j=0;j<3;j++){
                    cout << "|" << board[i][j];
                }
                cout << "|" << endl << "     -------" << endl << "    ";
            }
        }
        char board[3][3];
};

int main()
{
  game game;
  game.run();
  return 0;
}
