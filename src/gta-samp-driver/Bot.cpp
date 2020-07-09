#include <iostream>
#include <Windows.h>
#include "Movement.cpp"
#include "GameResources.cpp"

Movement* BOT = new Movement();
GameResources* GTA = new GameResources();

int main()
{
	int destX = -360;
	int destY = 2150;

	while (true) {
		
		float posX = GTA->GetX();
		float posY = GTA->GetY();
		float posZ = GTA->GetZ();
		printf("POS ( %f , %f , %f )\n", posX, posY, posZ);

		float diffX = posX - destX;
		float diffY = posY - destY;
		printf("DIFF ( %f , %f )\n", diffX, diffY);

		if (diffX <= 1 || diffY <= 1) {
			BOT->StopMovingForward();
		}
		else
		{
			BOT->MoveForward();
		}

		Sleep(200);
	}

}