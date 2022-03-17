//x axis in computer graphics remains same while the y axis is reversed
#include<iostream>
#include<cstdlib>//library shell command or console command (system command used here)
#include<windows.h>//helps to control cursor's position on your console
#include<conio.h>//to get input (console input/output)
#include<ctime>
#define width 50
#define height 25
#include "snake.h"
#include "Food.h"
using namespace std;

snake snakee({width/2,height/2},1);
Food food;

int score=0;

void board()
{
	COORD snake_pos=snakee.get_Pos();
	COORD food_pos=food.get_pos();
	
	vector<COORD> snake_body=snakee.get_body();
	
	cout<<"SCORE : "<<score <<"\n";
	
	for(int i=0;i<height;i++)
	{
		cout<<"\t";
		for(int j=0;j<width;j++)
		{
			if(i==0 || i==height-1 || j==0 || j == width-1 )
			cout<<"*";
			else if(i==snake_pos.Y && j==snake_pos.X)cout<<'o';
			else if(i==food_pos.Y && j==food_pos.X) cout<<"*";
			else
			{
				bool isBodyPart=false;
				for(int k=0;k<snake_body.size()-1;k++)
				{
					if(i == snake_body[k].Y && j==snake_body[k].X)
					{
						cout<<'o';
						isBodyPart=true;
						break;
					}
				}
				if(!isBodyPart) cout<<" ";
			}
		}
		cout<<endl;
	}
	
}
int main()
{
    score=0;
    
	srand(time(NULL));
	
	food.gen_food();
	
	bool game_over=false;
	
	while(!game_over){
		board(); 
		if(kbhit())
		{
			switch(getch()){
				case 'w':snakee.change_dir('u');break;
				case 'a':snakee.change_dir('l');break;
				case 's':snakee.change_dir('d');break;
				case 'd':snakee.change_dir('r');break;
			}
		}
		
		
		if(snakee.eaten(food.get_pos()))
		{
			food.gen_food();
			snakee.grow();
			score++;
		}
		
		if(snakee.collided())game_over=true;
		
		snakee.move_snake();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0}); //pick up the cursor and put it back to origion
	}
	 
	return 0;
}
