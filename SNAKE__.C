#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int x,y,fruitx,fruity,score,Gameover,flag;
int height=20,width=20;
int counttail=0;
int tailx[100],taily[100];
void draw()
{
	int i,j,k;
	clrscr();
	for(i=0;i<=height;i++)
	{
	    for(j=0;j<=width;j++)
	    {
		if(i==0 || i==height || j==0 || j==width)
		{
		  printf("*");
		}
		else
		{
		  if(i==x && j==y)
		  printf("o");
		  else if(i==fruitx && j==fruity)
		  printf("F");
		  else
		  {
		     //for printing increasing size of snake
		     int ch=0;  // to avoid printing space and snake at one time
		     for(k=0;k<=counttail;k++)
		     {
			if(i==tailx[k] && j==taily[k])
			{
			   printf("o");
			   ch=1;

			}
		     }
		     if(ch==0)
		     printf(" ");

		  }

		}


	    }
	    printf ("\n");
	}
	printf("SCORE:%d",score);
}
void setup()
{

	x=width/2;
	y=height/2;
	label1:
	fruitx=rand()%20;
	if(fruitx==0)
	goto label1;
	label2:
	fruity=rand()%20;
	if(fruity==0)
	goto label2;
	score=0;
}
void input()
{

	  if(kbhit())
	  {
		switch(getch())
		{
		   case 'a':
			flag=1;
			break;
		   case 's':
			flag=2;
			break;
		   case 'w':
			flag=3;
			break;
		   case 'z':
			flag=4;
			break;
		   case 'x':
			Gameover=1;


		}
	  }




}
void Logic()
{
	int i;
	int prev2x,prev2y;
	int prevx= tailx[0];
	int prevy=taily[0];
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<=counttail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;


	}



	switch(flag)
	{
	   case 1:
	   y--;      //left shift
	   break;
	   case 2:
	   y++;     //Right shift
	   break;
	   case 3:
	   x--;    //up shift
	   break;
	   case 4:
	   x++;     //down shift
	   break;

	}
	if(x<0||x>width||y<0||y>height)
	  Gameover=1;
	if(x==fruitx && y==fruity)
	{
	label3:
	fruitx=rand()%20;
	if(fruitx==0)
	goto label3;
	label4:
	fruity=rand()%20;
	if(fruity==0)
	goto label4;
	score+=10;
	counttail++;



	}



}

int main()
{
	int m,n;
	char p;
	label5:
	setup();
	while(!Gameover)
	{
	  draw();
	  input();
	  Logic();
	  for(m=0;m<=10000;m++)
	  {
		for(n=0;n<=10000;n++)
		{
		}
	  }

	}
	printf("  \n press Y to Continue Again:");
	scanf("%c",&p);
	if(p=='y'|| p=='Y')
	goto label5;

}
