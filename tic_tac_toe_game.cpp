// Program to implement Tic-Tac-Toe game
#include <iostream>
using namespace std;

int main() 
{
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    char player = 'X';     
    int choice, moves = 0;

    while (true)
    {
        // Display board
        cout << endl;
        cout << "Tic-Tac-Toe Game"<<endl;
        cout<<endl;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                cout << " " << board[i][j] << " ";
                if (j < 2) 
                    cout << "|";
            }
            cout << endl;
            if (i < 2)
                cout << "---|---|---"<<endl;
        }
        
        // Taking input
        cout<<"\nPlayer " << player << ", Please enter position from (1-9): ";
        cin>>choice;

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') 
        {
            cout << "Position already taken! Try again.\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        // Check rows and columns
        for (int i = 0; i < 3; i++) 
        {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
            {
                // Print final board
                cout << "\nFinal Board:\n\n";
                for (int r = 0; r < 3; r++) 
                {
                    for (int c = 0; c < 3; c++) 
                    {
                        cout << " " << board[r][c] << " ";
                        if (c < 2) cout << "|";
                    }
                    cout << endl;
                    if (r < 2) cout << "---|---|---"<<endl;
                }

                cout << "\nHurrey Player " << player << " wins!\n";
                return 0;
            }
        }   

        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
        {
            // Print final board
            cout << "\nFinal Board:\n\n";
            for (int r = 0; r < 3; r++) 
            {
                for (int c = 0; c < 3; c++) 
                {
                    cout << " " << board[r][c] << " ";
                    if (c < 2) cout << "|";
                }
                cout << endl;
                if (r < 2) cout << "---|---|---"<<endl;
            }

            cout << "\nHurrey Player " << player << " wins!\n";
            return 0;
        }

        // Draw condition
        if (moves == 9) 
        {
            cout << "\nFinal Board:\n\n";
            for (int r = 0; r < 3; r++) 
            {
                for (int c = 0; c < 3; c++) 
                {
                    cout << " " << board[r][c] << " ";
                    if (c < 2) cout << "|";
                }
                cout << endl;
                if (r < 2) cout << "---|---|---"<<endl;
            }

            cout << "\nIt's a draw 😩 !\n";
            return 0;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }
}