/*
The classic tic tac toe game.
User input is based on pattern of keys that represent the position of the play.
The computer's play is decided based on the user's input.
The 'X' and 'O' are drawn using standard graphic library functions.
Code tested using Turbo C++ version 3.0

*/

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int count=0;

void draws()
{
	rectangle(80,80,130,130);
	rectangle(130,80,180,130);
	rectangle(180,80,230,130);
	
	rectangle(80,130,130,180);
	rectangle(130,130,180,180);
	rectangle(180,130,230,180);
	
	
	rectangle(80,180,130,230);
	rectangle(130,180,180,230);
	rectangle(180,180,230,230);
}

char sum()
{
	int d[8]={0,0,0,0,0,0,0,0};
	for(int i=0;i<3;i++)
	{
		d[0]=d[0]+a[0][i];
		d[1]=d[1]+a[1][i];
		d[2]=d[2]+a[2][i];
		d[3]=d[3]+a[i][0];
		d[4]=d[4]+a[i][1];
		d[5]=d[5]+a[i][2];
	}
	d[6]=a[0][0]+a[1][1]+a[2][2];
	d[7]=a[0][2]+a[1][1]+a[2][0];
	for(i=0;i<8;i++)
	{
		if(d[i]==3)
			return 'x';
		if(d[i]==12)
			return 'o';
	}
	if(count==9)
		return 'v';

		return 'a';
}
int decide()
{
	int d[8]={0,0,0,0,0,0,0,0};
	int de=0;
	for(int k=0;k<3;k++)
	{
		d[0]=d[0]+a[0][k];
		d[1]=d[1]+a[1][k];
		d[2]=d[2]+a[2][k];
		d[3]=d[3]+a[k][0];
		d[4]=d[4]+a[k][1];
		d[5]=d[5]+a[k][2];
	}
	d[6]=a[0][0]+a[1][1]+a[2][2];
	d[7]=a[0][2]+a[1][1]+a[2][0];

	for(int i=0;i<8;i++)
	{
		if(d[i]==2)
		{
			de=1;
			break;
		}
	}

	int r=0;
	if(de==1)
	{
		if(i==6)
		{
			if(a[0][0]==0)
			{
				r=49;
			}
			else if(a[1][1]==0)
			{
				r=53;
			}
			else if(a[2][2]==0)
			{
				r=57;
			}
		}
		else if(i==7)
		{
			if(a[0][2]==0)
			{
				r=51;
			}
			else if(a[1][1]==0)
			{
				r=53;
			}
			else if(a[2][0]==0)
			{
				r=55;
			}
		}

		else if(i<3)
		{
			for(int j=0;j<3;j++)
				if(a[i][j]==0)
				{
					r=3*(i)+j+1;
					r=r+48;
					break;
				}
		}
		else
		{
			i=i-3;
			for(int j=0;j<3;j++)
				if(a[j][i]==0)
				{
					r=3*(j)+i+1;
					r=r+48;
					break;
				}
		}
	}
	return r;
}
void marking(int c,int key)
{
	switch(key)
	{
		case 49:
		{
			if(c==0)
			{
				line(95,95,115,115);
				line(95,115,115,95);
				a[0][0]=1;
			}
			else if(c==1)
			{
				circle(105,105,15);
				a[0][0]=4;
			}
			break;
		}
		case 50:
		{
			if(c==0)
			{
				line(145,95,165,115);
				line(145,115,165,95);
				a[0][1]=1;
			}
			else if(c==1)
			{
				circle(155,105,15);
				a[0][1]=4;
			}
			break;
		}
		case 51:
		{
			if(c==0)
			{
				line(195,95,215,115);
				line(195,115,215,95);
				a[0][2]=1;
			}
			else if(c==1)
			{
				circle(205,105,15);
				a[0][2]=4;
			}
			break;
		}
		case 52:
		{
			if(c==0)
			{
				line(95,145,115,165);
				line(95,165,115,145);
				a[1][0]=1;
			}
			else if(c==1)
			{
				circle(105,155,15);
				a[1][0]=4;
			}
			break;
		}
		case 53:
		{
			if(c==0)
			{
				line(145,145,165,165);
				line(165,145,145,165);
				a[1][1]=1;
			}
			else if(c==1)
			{
				circle(155,155,15);
				a[1][1]=4;
			}
			break;
		}
		case 54:
		{
			if(c==0)
			{
				line(195,145,215,165);
				line(195,165,215,145);
				a[1][2]=1;
			}
			else if(c==1)
			{
				circle(205,155,15);
				a[1][2]=4;
			}
			break;
		}
		case 55:
		{
			if(c==0)
			{
				line(95,195,115,215);
				line(115,195,95,215);
				a[2][0]=1;
			}
			else if(c==1)
			{
				circle(105,205,15);
				a[2][0]=4;
			}
			break;
		}
		case 56:
		{
			if(c==0)
			{
				line(145,195,165,215);
				line(165,195,145,215);
				a[2][1]=1;
			}
			else if(c==1)
			{
				circle(155,205,15);
				a[2][1]=4;
			}
			break;
		}
		case 57:
		{
			if(c==0)
			{
				line(195,195,215,215);
				line(195,215,215,195);
				a[2][2]=1;
			}
			else if(c==1)
			{
				circle(205,205,15);
				a[2][2]=4;
			}
			break;
		}
	}
}
int check(int r)
{
	int pro=0;
	switch(r)
	{
		case 49:
		{
			if(a[0][0]==0)
				pro=1;
			break;
		}
		case 50:
		{
			if(a[0][1]==0)
				pro=1;
			break;
		}
		case 51:
		{
			if(a[0][2]==0)
				pro=1;
			break;
		}
		case 52:
		{
			if(a[1][0]==0)
				pro=1;
			break;
		}
		case 53:
		{
			if(a[1][1]==0)
				pro=1;
			break;
		}
		case 54:
		{
			if(a[1][2]==0)
				pro=1;
			break;
		}
		case 55:
		{
			if(a[2][0]==0)
				pro=1;
			break;
		}
		case 56:
		{
			if(a[2][1]==0)
				pro=1;
			break;
		}
		case 57:
		{
			if(a[2][2]==0)
				pro=1;
			break;
		}
	}
	return pro;
}

int undefeatable()
{
        if(a[1][1]==1)
        {
                label:
                int r=random(10);
                if(r!=1||r!=3||r!=7||r!=9)
                    goto label;
                else
                {
                    int pro=check(r+48);
                    if(pro==0)
                        goto label;
                }
	   }
	   return 0;
}
void intel()
{
	int de=decide();
	if(de==0)
	{
		lab:int r=random(10);
		int pro=0;
		r=r+48;
		pro=check(r);
		if(pro==1)
			marking(1,r);
		else
			goto lab;
	}
	else
		marking(1,de);
}
void main()
{
	int gd=DETECT,gm,key=0,flag=10;
	char ch[3][3];
	int c=0;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setbkcolor(RED);
	cout<<"Enter according to pattern"<<endl;
	for(int x=1;x<=9;x++)
	{
		cout<<x<<"\t";
		if(x%3==0)
		cout<<endl;
	}
	cout<<endl;
	draws();
	while(key!=27&&flag==10)
	{
		count++;
		delay(500);
		if(c==1)
		{
			cout<<"Computer"<<endl;
			intel();
		}
		else
		{
			cout<<"Player"<<endl;
			labl:key=getch();
			int ck=check(key);
			if(ck==1)
				marking(c,key);
			else
			{
				cout<<"Error!!!\n";
				goto labl;
			}
		}
		c=(c+1)%2;
		char ch=sum();
		if(ch=='x')
		{
			cout<<"Player 1 wins"<<endl;
			break;
		}
		else if(ch=='o')
		{
			cout<<"Computer wins"<<endl;
			break;
		}
		else if(ch=='v'||count==9)
		{
			cout<<"Match draw"<<endl;
			break;
		}
	}
	getch();
}
