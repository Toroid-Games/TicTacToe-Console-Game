#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

// Global Vars
const int gridSize = 3;
int player = 0;
int lastPlayer = 0;
char symbol1 = 'X';
char symbol2 = 'O';
char dia;
char rw;
char col;
char take_row;
char take_colum;
int roww = 0;
int coll = 0;
char board[gridSize][gridSize] = {{'_', '_', '_'},
                                  {'_', '_', '_'},
                                  {'_', '_', '_'}};
bool gameRunning = true;
int p1Score = 0;
int p2Score = 0;

// FUNCTION DECLARATIONS
void gameloop();
char checkColumn();
char checkRow();
void showBoard();
char checkDiagonal();
void playerTurn();
bool playAgainCheck();
void clearVars();
void checkCoords(char a, char b, int& r, int& c);

// MAIN FUNCTION
int main()
{    
    while(gameRunning){
        showBoard(); // prints board
        cout << "To play this game:" << endl;
        cout << "PLEASE ENTER THE ROW AND COLUMN" << endl;
        cout << "In ANY order: Example '0a' or 'C2' "<< endl;
        cout << "Press any key to contiue" << endl;
        getch(); // gets a char from keyboard without displaying it
        system("cls"); // clears screen
        gameloop(); // runs game inner loop
        gameRunning = playAgainCheck(); // checks if players want to play again
    }    
    return 0;
}
// END OF MAIN FUNCTION

// FUNCTION DEFINTIONS
bool playAgainCheck(){
    char choice;
    cout << "Play again? y/n" << endl;
    cin >> choice;
    if(choice == 'y'){
        clearVars();
        system("cls");
        return true;
    } else {
        return false;
    }
}

void checkCoords(char a, char b, int& r, int& c){
    int ia = int(a);
    int ib = int(b);
    // check to make sure they are different types 
    if((ia >= 48 && ia <= 50) && (ib >= 48 && ib <= 50)){ r = 3; c = 3; return;} // both numbers
    if((ia >= 65 && ia <= 67) && (ib >= 65 && ib <= 67)){ r = 3; c = 3; return;} // both uppercase
    if((ia >= 97 && ia <= 99) && (ib >= 97 && ib <= 99)){ r = 3; c = 3; return;} // both lowercase
    if((ia >= 65 && ia <= 67) && (ib >= 97 && ib <= 99)){ r = 3; c = 3; return;} // first uppercase, second lowercase
    if((ia >= 97 && ia <= 99) && (ib >= 65 && ib <= 67)){ r = 3; c = 3; return;} // second lowercase, first uppercase

    if(ia >= 48 && ia <= 50){
        // this is a number from 0 - 2
        r = ia - 48;
    } else if (ia >= 65 && ia <= 67){
        // this is an upper case letter from A - C
        c = ia - 65;
    } else if (ia >= 97 && ia <= 99){
        // this is small case letter from a - c
        c = ia - 97;
    } else { c = 3; }// bad input = 0

    // now do that for other char
    if(ib >= 48 && ib <= 50){
        // this is a number from 0 - 2
        r = ib - 48;
    } else if (ib >= 65 && ib <= 67){
        // this is an upper case letter from A - C
        c = ib - 65;
    } else if (ib >= 97 && ib <= 99){
        // this is small case letter from a - c
        c = ib - 97;
    } else { c = 3; } // bad input = 0
}

void gameloop (){
    bool winner = false;
    for (int i = 0; i < 9; i++)
    {
        showBoard();
        playerTurn();
        while (true)
        {
            cout << endl;
            cout << "Enter position: " << endl;
            cin >> take_row >> take_colum;
            checkCoords(take_row, take_colum, roww, coll);
            if ((roww >= 0 && roww <= 2) && (coll >= 0 && coll <= 2))
            {
                if (board[roww][coll] != '_')
                {
                    cout << "Postion already is filled." << endl;
                } else {
                    break;
                }                        
            } else {
                cout << "Please enter correct option. eg. 0A" << endl;
            }                    
        }
        if (player % 2 != 0)
        {
            board[roww][coll] = symbol1;
        } else {
            board[roww][coll] = symbol2;
        }                

        dia = checkDiagonal();

        rw = checkRow();

        col = checkColumn();
        system("cls");            
        if (dia == '1' || rw == '1' || col == '1')
        {
            p1Score++;
            showBoard();
            cout << "Player 1 (X) won!" << endl;
            cout << "CONGRATS!\n";
            winner = true;
            break; // break out of for loop if game ends before 9 moves
        }
        else if (dia == '2' || rw == '2' || col == '2')
        {
            p2Score++;
            showBoard();
            cout << "Player 2 (O) won!" << endl;
            cout << "CONGRATS!\n";
            winner = true;
            break; // break out of for loop if game ends before 9 moves
        }
    }
    if(!winner){
        showBoard();
        cout << "It's a Draw!!" << endl;
    }
    lastPlayer += 1;
    player = lastPlayer; // ensures players flip each game
}

void showBoard()
{
    cout << " \t\t\t      ---TIC-TAC-TOE---\n \t\t\tScore: P1(X): " << p1Score << " --- P2(O): " << p2Score << endl;
    cout << " \t\t\t        A     B     C" << endl;
    for (int i = 0; i < gridSize; i++)
    {   cout << " \t\t\t      _____ _____ _____" << endl;
        cout <<"\t\t\t"<< i << "    |";
        for (int j = 0; j < gridSize; j++)
        {
            cout << "__" << board[i][j] << "__|";
        }
        cout << endl;
    }
}

char checkRow()
{
    for (int row = 0; row < gridSize; row++)
    {
        int p1 = 0;
        int p2 = 0;

        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == symbol1)
            {
                p1 = p1 + 1;
            }
            else if (board[row][col] == symbol2)
            {
                p2 += 1;
            }
        }
        if (p1 == 3)
        {
            return '1';
        }
        else if (p2 == 3)
        {
            return '2';
        }
    }
    return '3';
}
char checkColumn()
{
    for (int row = 0; row < gridSize; row++)
    {
        int p1 = 0;
        int p2 = 0;
        for (int col = 0; col < gridSize; col++)
        {
            if (board[col][row] == symbol1)
            {
                p1 = p1 + 1;
            }
            else if (board[col][row] == symbol2)
            {
                p2 = p2 + 1;
            }
        }
        if (p1 == 3) { return '1'; } else if (p2 == 3) { return '2'; }
    }
    return '3';
}
void playerTurn()
{
    if (player % 2 == 0)
    {
        cout << "Player 1 (X) turn :";
    }
    else
        cout << "Player 2 (O) turn :";
    player = player + 1;
}

char checkDiagonal()
{
    int p1 = 0;
    int p2 = 0;
    int p12 = 0;
    int p22 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == symbol1)
        {
            p1 = p1 + 1;
        }
        else if (board[i][i] == symbol2)
        {
            p2 = p2 + 1;
        }
    }
    int l=0;
    for (int j = 2; j >=0; j--)
    {
        
        if (board[l][j] == symbol1)
        {
            p12 = p12 + 1;
        }
        else if (board[l][j] == symbol2)
        {
            p22 = p22 + 1;
        }
        l=l+1;
    }

    if (p1 == 3 || p12 == 3)
    {
        return '1';
    }
    else if (p2 == 3 || p22 == 3)
    {
        return '2';
    }
    else
        return '3';
}

void clearVars(){
    // clear game vars
    dia = '\0';
    rw = '\0';
    col = '\0';
    take_row = 0;
    take_colum = 0;
    roww = 0;
    coll = 0;
    // clear board
    for (size_t i = 0; i < gridSize; i++)
    {
        for (size_t j = 0; j < gridSize; j++)
        {
            board[i][j] = '_';            
        }        
    }
}
// END OF FUNCTION DEFINITIONS
