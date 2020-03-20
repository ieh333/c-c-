#include <iostream>
using namespace std;

int main()
{
    float masiv [4][5];
    int row;
    int col;
    int resultat[4];

    cout<<"This Array have 4row x 5colum"<<endl;
    //Read numbers
    for(int row=0; row<4 ; row++)
    {
        for(int col=0; col<5;col++)
        {
        cout<<" Enter number ["<<row+1<<"].["<<col+1<<"]:";
                             cin>>masiv[row][col];
        }
    }
    //Print numbers
    cout<<endl<<"        ---------  2D Array --------"<<endl<<endl;
    for(int row=0;row <4;row++)
    {
        cout<<" Row  "<<row+1<<":  ";
        for(int col=0;col<5;col++)
        {
            cout<<masiv[row][col]<<" ";
        }
        cout<<endl;
    }
    //Read 2d Array and Save in 1d Array
    float tmp;
    for(row=0;row<4;row++)
    {
        

        for(col=0;col<5;col++)
        {
            if(col==0||tmp>masiv[row][col])
            {
            	tmp=masiv[row][col];
            	resultat[row]=col;
                
            }
        }
    }

    for(row=0; row<4; row++)
    {
        cout<<resultat[row]<<"  ";

    }
    return 0;
}