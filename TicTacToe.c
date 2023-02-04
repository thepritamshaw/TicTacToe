#include <stdio.h>
#include <stdlib.h>
#define N 3
int A[N][N];
int rowCheck()
{
        int count=1, i=0, j=0;
        for (i=0;i<N;i++)
        {
                count=1;
                for(j=0; j<N-1; j++)
                {
                        if((A[i][j]==A[i][j+1])&&(A[i][j+1]!=0))
                                count++;
                }
                if (count==N)
                        return A[i][j];
        }
        return 0;
}
int coloumnCheck()
{
        int count=1, i=0, j=0;
        for (i=0;i<N;i++)
        {
                count=1;
                for(j=0; j<N-1; j++)
                {
                        if((A[j][i]==A[j+1][i])&&(A[j+1][i]!=0))
                                count++;
                }
                if (count==N)
                        return A[j][i];
        }
        return 0;
}
int diagonalCheck()
{
        int count=1, i=0, j=0;
        for (i=0;i<N-1;i++)
        {
                if((A[i][i]==A[i+1][i+1])&&(A[i+1][i+1]!=0))
                        count++;
        }
        if (count==N)
                return A[i][i];
        count=1;
        for (i=0;i<N-1;i++)
        {
                if((A[i][N-i-1]==A[i+1][N-i-2])&&(A[i][N-i-1]!=0))
                        count++;
        }
        return (count==N)?A[i][N-i-1]:0;
}
int check()
{
        return (rowCheck()!=0)?rowCheck():(coloumnCheck()!=0)?coloumnCheck():(diagonalCheck()!=0)?diagonalCheck():0;
}
void showBoard()
{
        system("cls");
        printf("\n==================\n  CURRENT BOARD\n\n");
        for (int i=0;i<N;i++)
        {
                for (int j=0;j<N;j++)
                {
                        printf((A[i][j]==1)?"  X  ":(A[i][j]==2)?"  O  ":(A[i][j]==0)?"     ":"");
                        if(j<N-1)
                                printf("|");
                }
                printf("\n");
                if (i<N-1)
                {
                        for(int l=0;l<N;l++)
                        {
                                printf("-----");
                                if (l<N-1)
                                        printf("|");
                        }
                        printf("\n");
                }
        }
}
int input(int position, int whoseTurn)
{
        while (1)
        {
                if ((A[(position-1)/N][(position-1)%N]==0)&&(position>0)&&(position<=N*N))
                {
                        A[(position-1)/N][(position-1)%N]=whoseTurn;
                        break;
                }
                else
                {
                        printf("\nEnter Valid Position!!\n\nPlayer %d turn\nEnter the position: ",whoseTurn);
                        scanf("%d",&position);
                }
        }
}
void showInstructions()
{
        printf("\n==================\n   INSTRUCTIONS\n\n",N*N);
        for (int i=1; i<=N*N;i++)
        {
                if(i<10)
                        printf("  %d  ",i);
                else if(i<100)
                        printf("  %d ",i);
                else if (i<1000)
                        printf(" %d ",i);
                else if (i<10000)
                        printf(" %d",i);
                else
                        printf("%d",i);
                if (i%N!=0)
                        printf("|");
                else if(i==N*N)
                        break;
                else
                {
                        printf("\n");
                        for(int l=0;l<N;l++)
                        {
                                printf("-----");
                                if (l<N-1)
                                        printf("|");
                        }
                        printf("\n");
                }
        }
}
int main()
{
        system("cls");
        char choice='0';
        while (choice=='0')
        {
                system("cls");
                showInstructions();
                int whoseTurn=1, position, flag;
                for(int i=0;i<N*N;i++)
                {
                        printf("\nPlayer %d turn\nEnter the position: ",whoseTurn);
                        scanf("%d",&position);
                        input(position,whoseTurn);
                        flag=check();
                        showBoard();
                        if (flag!=0)
                        {
                                printf("\n\nPlayer %d Won!\n\n",flag);
                                break;
                        } 
                        whoseTurn=(whoseTurn%2)+1;
                }
                if (flag==0)
                        printf("\n\nMatch Draw!\n\n");
                printf("Enter '0' to Play Again or any other key to EXIT : ");
                scanf(" %c",&choice);
                for (int i=0;i<N;i++)
                        for (int j=0;j<N;j++)
                                A[i][j]=0;
        }
}