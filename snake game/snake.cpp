#include "snake.h"

snake::snake(COORD pos,int vel)
{
	this->pos=pos;
	this->vel=vel;
	len=1;
	direction='n';//snake is not moving initially
	body.push_back(pos);
}

void snake::change_dir(char dir){direction =dir;}

void snake::move_snake()
{
	switch(direction)
	{
		case'u':pos.Y-=vel;break;
		case'd':pos.Y+=vel;break;
		case'l':pos.X-=vel;break;
		case'r':pos.X+=vel;break;		
	}
	body.push_back(pos);
	if(body.size() > len )body.erase(body.begin());
}

COORD snake::get_Pos(){return pos;}

vector<COORD> snake::get_body() {
	return body;
}

bool snake::eaten(COORD food_pos)
{
	if(food_pos.X==pos.X && food_pos.Y ==pos.Y )//ifposition of food and head are same
	{
		return true;
	}
	else
	return false;
}

void snake::grow(){
	len++;
}

bool snake::collided()
{
	if(pos.X<1 || pos.X>width-2  || pos.Y<1 || pos.Y>height-2 )return true;
	
	for(int i=0;i<body.size()-1;i++)
	{
		if(pos.X==body[i].X && pos.Y==body[i].Y)return true;
	}
	return false;
}
