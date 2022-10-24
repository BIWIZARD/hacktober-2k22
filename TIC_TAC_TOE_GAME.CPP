#include<iostream>
#include<iomanip>

using namespace std;

void drawGameBoard(char Gameboard[][3]);
char checkGameWinner3by3(char Gameboard[][3]);

int main()
{
    char Gameboard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char Gameplayer = 'X';
    char Gamewinner = ' ';
    int Boardrow;
    int Boardcolumn;
    bool is_Validmove;
    bool is_Boardrow;
    bool is_Boardcolumn;

    cout<<"************ TIC TAC TOE Game ************\n";
    while(Gamewinner == ' ')
    {
        is_Validmove = false;
        is_Boardrow = false;
        is_Boardcolumn = false;
        drawGameBoard(Gameboard);
        cout << "GamePlayer ";
        if(Gameplayer == 'X')
        {
            cout << 'X';
        }
        else
        {
            cout << 'O';
        }
        cout << "'s turn:" << endl;
        is_Validmove = false;
        while(!is_Validmove)
        {
            is_Boardrow = false;
            while(!is_Boardrow)
            {
                cout << "BoardRow: ";
                cin >> Boardrow;
                if(Boardrow == 1 || Boardrow == 2 || Boardrow == 3)
                {
                    is_Boardrow = true;
                }
                else
                {
                    cout << endl << "Invalid Boardrow!" << endl;
                }
            }
            is_Boardcolumn = false;
            while(!is_Boardcolumn)
            {
                cout << "BoardColumn: ";
                cin >> Boardcolumn;
                if(Boardcolumn == 1 || Boardcolumn == 2 || Boardcolumn == 3)
                {
                    is_Boardcolumn = true;
                }
                else
                {
                    cout << endl << "Invalid Boardcolumn!" << endl;
                }
            }
            if(Gameboard[Boardrow-1][Boardcolumn-1] == ' ')
            {
                Gameboard[Boardrow-1][Boardcolumn-1] = Gameplayer;
                is_Validmove = true;
                if(Gameplayer == 'X')
                {
                    Gameplayer = 'O';
                }
                else
                {
                    Gameplayer = 'X';
                }
            }
            else
            {
                cout<<"The selected space is occupied!" << endl;
                cout << "Select a different space:" << endl << endl;
                drawGameBoard(Gameboard);
            }
        }
        cout << endl;
        Gamewinner = checkGameWinner3by3(Gameboard);
        if(Gamewinner == 'X' || Gamewinner == 'O')
        {
            drawGameBoard(Gameboard);
            cout<<"Congratulations! GamePlayer ";
            if(Gamewinner == 'X')
            {
                cout << 'X';
            }
            else
            {
                cout << 'O';
            }
            cout<<" is the Gamewinner!"<<endl;
        }
        else if(Gamewinner == 'T')
        {
            drawGameBoard(Gameboard);
            cout << "It's a tie!" << endl;
        }

    }

    system("pause");
    return 0;
}

void drawGameBoard(char Gameboard[][3])
{
    cout << "     1   2   3" << endl;
    cout << "   -------------" << endl;

    cout << " 1" << " | " << Gameboard[0][0] << " | " << Gameboard[0][1] << " | " << Gameboard[0][2] << " | " << endl;
    cout << "   -------------" << endl;

    cout << " 2" << " | " << Gameboard[1][0] << " | " << Gameboard[1][1] << " | " << Gameboard[1][2] << " | " << endl;
    cout << "   -------------" << endl;

    cout << " 3" << " | " << Gameboard[2][0] << " | " << Gameboard[2][1] << " | " << Gameboard[2][2] << " | " << endl;
    cout << "   -------------" << endl;

}
char checkGameWinner3by3(char Gameboard[][3])
{


    for(int i=0; i<3; i++)
    {
        if(Gameboard[i][0]==Gameboard[i][1] && Gameboard[i][0]==Gameboard[i][2])
        {
            return Gameboard[i][0];
        }
    }

    for(int i=0; i<3; i++)
    {
        if(Gameboard[0][i]==Gameboard[1][i] && Gameboard[0][i]==Gameboard[2][i])
        {
            return Gameboard[0][i];
        }
    }

    if(Gameboard[0][0]==Gameboard[1][1] && Gameboard[1][1]==Gameboard[2][2])
    {
        return Gameboard[0][0];
    }

    if(Gameboard[0][2]==Gameboard[1][1] && Gameboard[1][1]==Gameboard[2][0])
    {
       return Gameboard[0][2];
    }

    return ' ';
}
