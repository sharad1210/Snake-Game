#ifndef SNAKE_H
#define SNAKE_H

#include<windows.h>//to use COORD data structure
#include<vector>
#define width 50
#define height 25

using namespace std;
/*
      features of snake:
      1.position of its head
      2.length  to define how long the snake is
      3.direction
      4.velocity(in terms of number of characters
*/
class snake
{
	private:
		COORD pos;
		int len;
		int vel;
		char direction;
		vector<COORD> body;
		public:
			snake(COORD pos,int vel);//constructor
			void change_dir(char dir);//function to change direction of snake
		    void move_snake();
		    COORD get_Pos();
		    vector<COORD> get_body();
		    bool eaten(COORD food_pos);
		    void grow();
		    bool collided();
};

#endif 




