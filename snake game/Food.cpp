#include "Food.h"


void Food::gen_food()
{
	pos.X= ( rand() % width - 2 ) + 1;
	pos.Y=( rand() % height - 2 ) + 1;
}
COORD Food::get_pos(){
return pos;
}