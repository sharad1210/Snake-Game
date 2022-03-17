#ifndef FOOD_H
#define FOOD_H

#include<windows.h>//for position of food
#define width 50
#define height 25
class Food
{
	private:
		COORD pos;
		public:
			void gen_food();
			COORD get_pos();
};

#endif