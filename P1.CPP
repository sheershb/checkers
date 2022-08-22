#include<iostream>
#include<conio.h>
#include<process.h>
#include<math.h>
#include<graphics.h>
using namespace std;
class Board
{
    int B[8][8],rl,wl;
public:
    Board();
    int movechk();
    int endchk();
    void display();
    int turn;
    void play();
    void movep(int,int,int,int);
};

void Board::display()
{
    int i,j;
    for(i=0; i<8; i++)
    {
        cout<<"\t";
        for(j=0; j<8; j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<"\n";
    }
}

Board::Board()
{
    int i,j,k;
    turn =1;
    for (i=0; i<8; i++)
    {
        if(i==3||i==4)
        {
            for(j=0; j<8; j++)
            {
                B[i][j]=0;
            }
        }
        else if(i%2!=0)
        {
            if(i<3)
                k=2;
            else
                k=1;

            for(j=0; j<8; j++)
            {
                if(j%2==0)
                {
                    B[i][j]=k;
                }
                else
                {
                    B[i][j]=0;
                }
            }
        }
        else
        {
            if(i<3)
                k=2;
            else
                k=1;
            for (j=0; j<8; j++)
            {
                if(j%2==0)
                {
                    B[i][j]=0;
                }
                else
                {
                    B[i][j]=k;
                }
            }
        }
    }

    wl=0;
    rl=0;
}

int main()
{
    cout<<"\n"<<"\n"<<"\n";
    Board b;
    b.play();
    getch();
    return 0;
}
int Board::endchk()
{
    if(wl==12)
    {
        cout<<"\n"<<"\n"<<"\n";
        cout<<"WHITE LOST RED WINS!!!! BOOOOSH!"<<"\n";
        getch();
        return 1;
    }
    else if (rl==12)
    {
        cout<<"\n"<<"\n"<<"\n";
        cout<<"RED LOST WHITE WINS!!!! BOOOOSH!"<<"\n";
        getch();
        return 2;
    }
    else
        return 0;
}
int Board::movechk()
{
    int i,j;
    for(i=0; i<8; i++)
    {

        for(j=0; j<8; j++)
        {
            if ((B[i][j]==turn)||(B[i][j]==turn*10))
            {
                if(B[i][j]==1||B[i][j]>10)
                {
                    if(((i-2)>=0)&&((j-2)>=0))
                    {
                        if(B[i-1][j-1]!=turn)
                        {
                            i=(i-2)*10+(j-2);
                            return i;
                        }
                    }
                    else if(((i+2)<=7)&&((j-2)>=0))
                    {
                        if(B[i+1][j-1]!=turn)
                        {
                            i=(i+2)*10+(j-2);
                            return i;
                        }
                    }
                }

                if(B[i][j]==2||B[i][j]>10)
                {
                    if(((i-2)>=0)&&((j+2)<=7))
                    {
                        if(B[i-1][j=1]!=turn)
                        {
                            i=(i-2)*10+(j+2);
                            return i;
                        }
                    }
                    else if(((i+2)<=7)&&((j+2)<=7))
                    {
                        if(B[i+1][j+1]!=turn)
                        {
                            i=(i+2)*10+(j+2);
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
void Board::movep(int Or,int oc,int r,int c)

{
    if(B[r][c]!=0)
    {
        cout<<"Wrong Move! Try again .\n";
        cin>>r>>c;
        play();
    }
    if((B[Or][oc]==1)&& (r>Or))
    {
        cout<<"Invalid Move! Try Again.\n";
        cin>>r>>c;
        play();
    }
    if((B[Or][oc]==2)&& (r<Or))
    {
        cout<<"Invalid Move! Try Again.\n";
        cin>>r>>c;
        play();
    }
    int check = movechk();
    if ((check==-1)&&((fabs(Or-r)==2)&&((fabs(oc-c))==2)))
    {
        B[r][c]=B[Or][oc];
        B[Or][oc]=0;
        if(turn==1)
        {
            turn==2;
        }
        else turn==1;
    }
    else if (check!=(r*10+c))
    {
        cout<<"Perform Killing Move First! \n";
    }
    else if(check==(r*10+c))
    {
        B[r][c]=B[Or][oc];
        B[Or][oc]=0;
        if(B[(Or+r)/2][(oc+c)/2]==1)
        {
            wl++;
            B[(Or+r)/2][(oc+c)/2]=0;
        }
        if(B[(Or+r)/2][(oc+c)/2]==2)
        {
            rl++;
            B[(Or+r)/2][(oc+c)/2]=0;
        }
        if(turn==1)
        {
            turn==2;
        }
        else turn==1;
        endchk();

    }

}
void Board::play()
{
    int Or,oc,r,c;
    display();
    if(turn==1)
    {
        cout<<"\nWhite's Turn!\n";
    }
    else if(turn==2)
    {
        cout<<"\nRed's Turn!\n";
    }
    cout<<"Enter Starting Co-ordinates and end Co-ordinates, make sure to perform killing move if possible \n";
    cin>>Or>>oc>>r>>c;
    movep(Or,oc,r,c);

}

