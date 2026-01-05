#include <iostream>
#include <windows.h>
using namespace std;

// function declarations
void setcl(int text, int background = 0);
void gotoxy(int x, int y);
void drawBoard();
void sample();





int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    char winner = ' ';

    // screen positions of cells
int cellX[3][3] = {
    {5,  9, 13},
    {5,  9, 13},
    {5,  9, 13}
};

int cellY[3][3] = {
    {1, 1, 1},
    {4, 4, 4},
    {7, 7, 7}
};

    system("cls");
    drawBoard();
    sample();

    // main game loop 
    for (int turn = 0; turn < 9; turn++) {
        setcl(14);
        gotoxy(0, 9);
        cout << "Current Player: " << currentPlayer << "   ";

        int move;
        while (true) {
            gotoxy(0, 10);
            cout << "Enter move (0-8):   ";
            gotoxy(18, 10);
            cin >> move;

            if (cin.fail() || move < 0 || move > 8) {
                cin.clear();
                cin.ignore(10000, '\n');
            gotoxy(0, 11);

                cout << "Invalid input. Try again.   ";
                continue;
            }

            int r = move / 3;
            int c = move % 3;

            if (board[r][c] != ' ') {
                gotoxy(0, 11);
                cout << "Cell already taken.         ";
                continue;
            }

            board[r][c] = currentPlayer;

            setcl(currentPlayer == 'X' ? 4 : 1);
            gotoxy(cellX[r][c], cellY[r][c]);
            cout << currentPlayer;
            setcl(14);

            break;
        }

        // check rows
        for (int r = 0; r < 3; r++) {
            if (board[r][0] != ' ' &&
                board[r][0] == board[r][1] &&
                board[r][1] == board[r][2]) {
                winner = board[r][0];
            }
        }

        // check columns
        for (int c = 0; c < 3; c++) {
            if (board[0][c] != ' ' &&
                board[0][c] == board[1][c] &&
                board[1][c] == board[2][c]) {
                winner = board[0][c];
            }
        }

        // check diagonals
        if (board[0][0] != ' ' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2]) {
            winner = board[0][0];
        }

        if (board[0][2] != ' ' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0]) {
            winner = board[0][2];
        }

        if (winner != ' ')
            break;

        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

    gotoxy(0, 13);
    setcl(10);
    if (winner != ' ')
        cout << "Player " << winner << " wins!";
    else
        cout << "It's a Tie!";

    setcl(7);
    gotoxy(0, 15);
    return 0;
}

// functions
// function that prints the board
void drawBoard() {
    cout << "       |   |   " << endl;
    cout << "       |   |   " << endl;
    cout << "    ___|___|___" << endl;
    cout << "       |   |   " << endl;
    cout << "       |   |   " << endl;
    cout << "    ___|___|___" << endl;
    cout << "       |   |   " << endl;
    cout << "       |   |   " << endl;
    cout << "       |   |   " << endl;
}
// function that moves the cursor
void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// function that sets colour
void setcl(int text, int background) {
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        text | (background << 4)
    );
}
// function that prints the sample board
void sample()
{
    int x = 35; 
    int y = 0;    
    setcl(4);

    gotoxy(x, y);
    cout << " 0 | 1 | 2 ";

    gotoxy(x, y + 1);
    cout << "-----------";

    gotoxy(x, y + 2);
    cout << " 3 | 4 | 5 ";

    gotoxy(x, y + 3);
    cout << "-----------";

    gotoxy(x, y + 4);
    cout << " 6 | 7 | 8 ";
    setcl(7);
}
