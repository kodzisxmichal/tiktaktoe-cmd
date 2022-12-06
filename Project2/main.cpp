#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cstdlib>

using namespace std;

void CreateGrid();
void gotoxy(int x,int y);
int cursorLimit(int cordinates);

int main(){

    bool exit;
    char input;

    int x=0;
    int y=0;

    while(!exit){
        CreateGrid();

        //naprawic granice (musza sie wykonywac przed przesunieciem)
        if(x>5) x=5;
        if(y>5) y=5;
        if(x<0) x=0;
        if(y<0) y=0;
        gotoxy(x,y);

        input = getch();
        switch (input)
        {
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

            case 113:
                exit=true;
                break;

            default:
                break;
        }

        system("CLS");
        }


    return 0;
}

void CreateGrid(){

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
                printf(" ");
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

int cursorLimit(int cordinates){
    if(cordinates<0){
        return 0;
    }
    else if(cordinates>5){
         return 5;
    }
    else{
        return cordinates;
    }
}
