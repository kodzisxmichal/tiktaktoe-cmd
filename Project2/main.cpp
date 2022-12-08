#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void CreateGrid(char *arr);
void gotoxy(int x,int y);
void cursorLimit(int &x,int &y);
bool CheckWin(char *arr);

int main(){

    bool exit=false, win=false;
    int turn_number=0;
    char input;
    int x=1, y=1;
    
    char arr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

    while(!exit){
        system("CLS");

        CreateGrid(arr);
        cursorLimit(x,y);
        gotoxy(x,y);

        if(turn_number==9){
            gotoxy(7,3);
            cout << "Remis";

            getch();
            system("CLS");
            exit = true;
            break;
        }

        if(CheckWin(arr)){
            gotoxy(7,3);

            cout << "wygrywa ";
            if(turn_number%2==0){ cout << "O";}
            else{ cout << "X";}

            getch();
            system("CLS");
            exit = true;
            break;
        }

        input = getch();

        switch (input)
        {
            //control buttons
            case 97:
                x-=2;
                break;
            
            case 100:
                x+=2;
                break;

            case 119:
                y-=2;
                break;

            case 115:
                y+=2;
                break;
            // X and O buttons
            case 120:
                if(arr[(y/2)*3+(x/2)]!='O'&& turn_number%2==0){
                    arr[(y/2)*3+(x/2)]='X';
                    turn_number++;
                }
                break;

            case 111:
                if(arr[(y/2)*3+(x/2)]!='X'&& turn_number%2==1){
                    arr[(y/2)*3+(x/2)]='O';
                    turn_number++;
                }
                break;
            //exit on q
            case 113:
                exit=true;
                break;
            
            default:
                break;
        }
    }

        system("CLS");
        return 0;
}

void CreateGrid(char *arr){

    int arr_number=0;
    for(int row=0;row<5;row++){
        for(int column=0;column<5;column++){
            if(column%2==1 && row%2==1){
                printf("%C",206);
            }
            else if(column==1 || column==3){
                printf("%C",186);
            }
            else if(row==1 || row == 3){
                printf("%C",205);
            }
            else{
                cout << arr[arr_number];
                arr_number++;
            } 
        }
        cout << endl;
    }

}

void gotoxy(int x,int y)    
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
}

void cursorLimit(int &x,int &y){
    if(x>5) x=5;
    else if(y>5) y=5;
    else if(x<1) x=1;
    else if(y<1) y=1;
}

bool CheckWin(char *arr){
    for(int i=0;i<3;i++){
        if(((arr[i*3]==arr[i*3+1]&&arr[i*3+1]==arr[i*3+2])&&arr[i*3]!=' ')||((arr[i]==arr[i+3]&&arr[i+3]==arr[i+6])&&arr[i]!=' ')){
            return true;
        }
        else if((arr[4]!=' '&&((arr[0]==arr[4]&&arr[4]==arr[8])||(arr[2]==arr[4]&&arr[4]==arr[6])))){
            return true;
        }
    }
    return false; 
}
