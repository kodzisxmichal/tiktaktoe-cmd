#include <iostream>
#include <cstdlib>

using namespace std;

void CreateGrid();
int main(){

    bool exit;
    
    while(!exit){
        CreateGrid();

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