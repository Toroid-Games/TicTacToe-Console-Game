#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include<conio.h>
using namespace std;

// FUNCTION PROTOTYEPS
void PlayerChoice();
char checkCoulumn(char symbol1, char symbol2);
char checkRow(char symbol1, char symbol2);
void goBoard();
char diagonal(char symbol1, char symbol2);
void player_turn();
const int gred = 3;
int player = 0;
char symbol1, symbol2;
char board[gred][gred] = {{'_', '_', '_'},
                          {'_', '_', '_'},
                          {'_', '_', '_'}};



// main functionn
main()
{
    char dia;
    char rw;
    char col;
    char take_row;
    char take_colum;
    int roww = 0;
    int coll = 0;

    goBoard();
    cout << "Note to play this game: " << endl;
    cout << "PLEASE ENTER THE ROW FIRST THEN ENTER THE COLUMN" << endl;
    cout<<"Example in order to occupy top left Box enter: '0A' "<<endl;
    cout << "YOU CANNOT CHANGE THE ROW AND COLUMN ORDER " << endl;
    cout<<"Press any key to contiue"<<endl;
    getch();
    system("cls");
    PlayerChoice();
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   goBoard();
            player_turn();
            while (true)
            {
               cout<<endl;
                cout << "enter position" << endl;
                cin >> take_row >> take_colum;
                roww = int(take_row);
                coll = int(take_colum);
                roww = roww - 48;
                coll = coll - 65;
                if ((roww >= 0 && roww <= 2) && (coll >= 0 && coll <= 2))
                {
                    if (board[roww][coll] != '_')
                    {
                        cout << "postion  is filled already" << endl;
                    }
                    else
                        break;
                }
                else
                    cout << "please enter correct option" << endl;
            }
            if (player % 2 != 0)
            {
                board[roww][coll] = symbol1;
            }
            else
                board[roww][coll] = symbol2;

            dia = diagonal(symbol1, symbol2);
  
            rw = checkRow(symbol1, symbol2);

            col = checkCoulumn(symbol1, symbol2);
       system("cls");
            if (dia == '1' || rw == '1' || col == '1')
            {
                cout << "player 1 win" << endl;
                cout << "CONGRATES";
                return 0;
            }
            else if (dia == '2' || rw == '2' || col == '2')
            {
                cout << "player 2 win" << endl;
                cout << "CONGRATES";
                return 0;
            }
        }
    }

    cout << "draw";
} //  END OF MAIN FUCTION


// FUNCTION DEFINTIONS
void goBoard()
{
    cout << " \t\t\t        A      B      C" << endl;
  
      
    for (int i = 0; i < gred; i++)
    {   cout << " \t\t\t      _ ___ __ __ __ __" << endl;
        cout <<"\t\t\t"<< i << "    |";
        for (int j = 0; j < gred; j++)
        {
            cout<<"_";
            cout << board[i][j] << " __|";
        }
        cout << endl;
    }
}

void PlayerChoice()
{
    int a = 0;
    while (a == 0)
    {

        cout << "Please Enter Player 1 Symbol: " << endl;
        cin >> symbol1;
        if (symbol1 == '_')
        {
            cout << "you cannot choose '_'  as player sign please enter another option" << endl;
        }
        else
            a = a + 1;
    }
    while (a == 1)
    {
        cout << "Please Enter Player 2 Symbol: " << endl;
        cin >> symbol2;
        if (symbol2 == '_')
        {
            cout << "you cannot choose '_'  as player sign please enter another option" << endl;
        }
        else if (symbol2 == symbol1)
        {
            cout << "This symbol is taken by Player 1 ....Choose another option" << endl;
        }
        else
            a = a + 1;
    }
}

char checkRow(char symbol1, char symbol2)
{
    for (int row = 0; row < gred; row++)
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
char checkCoulumn(char symbol1, char symbol2)
{

    for (int row = 0; row < gred; row++)
    {
        int p1 = 0;
        int p2 = 0;
        for (int col = 0; col < gred; col++)
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
        if (p1 == 3)
            return '1';
        else if (p2 == 3)
            return '2';
    }
    return '3';
}
void player_turn()
{
    if (player % 2 == 0)
    {
        cout << "Player 1 turn :";
    }
    else
        cout << "player 2 turn :";
    player = player + 1;
}

char diagonal(char symbol1, char symbol2)
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
