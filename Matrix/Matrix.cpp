#include <iostream>
#include <iomanip>

using namespace std;

// Functsia za initsializirane na vhodnata matritsa
void initialMatrix(int **A, int r, int c)
{
     int i,j;
     for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
          A[i][j]=0;
       }
    }
}

//Functsia za popalvane na matritsata
void fillMatrix(int **A, int n)
{
     int i,j;
     int r,c;
     r=n;
     c=2*n;
     for(j=0;j<c/2;j++)
     {
        for(i=j;i<r;i++)
        {
           A[i][j]=n-j;
        }
     }
     for(j=c-1;j>=c/2;j--)
     {
        for(i=c-(j+1);i<r;i++)
        {
           A[i][j]=j-(n-1);
        }
     }
     
}

// Functsia za otpechatvane na novata matritsa
void printMatrix(int **A, int r, int c)
{
     int i,j;
     for(i=0;i<r;i++)
     {
        for(j=0;j<c;j++)
        {
           cout<<setw(5)<<A[i][j];
        }
        cout<<endl;
     }
}
int main()
{
    int** Matrix;
    int i, j, count;
    int N;
    int row, col;
    cout<<"Vavedete chisloto N:";
    cin>>N;
    row=N;
    col=2*N;
    Matrix=new int*[2*N];
    for (count=0;count<row;count++)
    {
        Matrix[count]=new int[col]; 
    }
    initialMatrix(Matrix, row, col);
    fillMatrix(Matrix, N);
    printMatrix(Matrix, row, col);
    for(count=0;count<row;count++)
    {
       delete[] Matrix[count];
    }
    delete[] Matrix;
    system("PAUSE");
    return EXIT_SUCCESS;
}
