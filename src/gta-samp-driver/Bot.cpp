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

		Sleep(800);
		if (!GTA->IsInCar()) {
			printf("Player is not in a car.\n");
			continue;
		}

		float posX = GTA->GetPlayerX();
		float posY = GTA->GetPlayerY();
		float posZ = GTA->GetPlayerZ();
		printf("POS ( %f , %f )\n", posX, posY);

		float rotation = GTA->GetCarRotationAngle();
		printf("ROT ( %f )\n", rotation);

	}

}