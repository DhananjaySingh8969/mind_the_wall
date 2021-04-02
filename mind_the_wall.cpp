#include<bits/stdc++.h>
#include <windows.h>
#include<conio.h>
using namespace std;
bool gameOver=false;
int height=15;
int widht=30;
int score=0;
bool hit=false;
int x,y;
int food_x,food_y;
enum {LEFT=75,RIGHT=77,UP=72,DOWN=80};
int del=-1;
vector<pair<int,int>> cord;
void start()
{
	gameOver=false;
	hit=false;
	x=widht/2;
	y=height/2;	
	cord.push_back({x,y});
	food_x=rand()%widht;
	food_y=rand()%height;
	del=LEFT;
}
void ShowConsoleCursor(bool showFlag);
bool create_snake(int h,int w)
{
	for(int i=0;i<cord.size();i++)
	{
		if(w==cord[i].first && h==cord[i].second)
		{
			if(i==0)
			{
				cout<<"0";
			}else{
				cout<<"x";
			}
			return true;
		}
	}
	return false;
}
bool isGameOver()
{
	int head_x=cord[0].first;
	int head_y=cord[0].second;
	if(head_x<=0 || head_y<=0 || head_x>=widht || head_y>=height)
	{
		return true;
	}
	return false;
}
void canvas()
{     
    
    system("cls");
    cout<<"SCORE: "<<score<<endl;
	for(int h=0;h<=height;h++)
	{    
		for(int w=0;w<=widht;w++)
		{   
		    
		    
			if(h==0 || h==height)
			{
				cout<<"#";
			}
			else if(w==0 || w==widht)
			{
				cout<<"*";
				
			}else if(create_snake(h,w))
			{  
//               cout<<"X";
			}
			else if(w==food_x && h==food_y)
			{
				cout<<"O";
			}
			else{
				  cout<<" ";
			}
		}
		cout<<endl;
	}
	
}

int keyInput()
{
	if(_kbhit())
	{    
	    char ch=_getch();
	    del=ch;
	}
}
void check_cord(int x,int y)
{
	if(x<=0)
	{
		food_x=1;
	}
	if(x>=widht)
	{
		food_y=widht-1;
	}
	if(y<=0)
	{
		food_y=1;
	}
	if(y>=height)
	{
		food_y=height-1;
	}
}
int movement()
{   
    
	if(del==LEFT)
	{
		x--;
		if(x<=0)
		  x=widht;
	}else if(del==RIGHT)
	{
		x++;
		if(x>=widht)
		  x=0;
	}else if(del==UP)
	{
		y--;
		if(y<=0)
		   y=height;
	}else if(del==DOWN)
	{
		y++;
		if(y>=height)
		  y=0;
	}
	if(food_x==x && food_y==y)
	{
		hit=true;
		score+=5;
		food_x=rand()%widht;
	    food_y=rand()%height;
	    check_cord(food_x,food_y);
	}
	if(hit)
	{
		hit=false;
		cord.push_back({cord.back().first,cord.back().second});
	}
	for(int i=cord.size()-1;i>=1;i--)
	{
		cord[i].first=cord[i-1].first;
		cord[i].second=cord[i-1].second;
	}
	cord[0].first=x;
	cord[0].second=y;
	if(isGameOver())gameOver=true;
}

int main()
{    
    start();
    while(!gameOver)
    {    
        
    	canvas();
    	keyInput();
    	movement();
    	ShowConsoleCursor(false);
    	
//    system("pause");
//    	sleep(10);
	}
	cout<<"GAME OVER"<<endl;
	cout<<"FINAL SCORE: "<<score<<endl;
	return 0;
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

