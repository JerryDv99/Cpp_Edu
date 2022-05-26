#pragma once

struct Vector3
{
	float x = 0, y = 0, z = 0;

	Vector3() {};

	Vector3(float _x, float _y)
		: x(_x), y(_y), z(0) { };
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Player
{
	char* Name = { nullptr };
	char* Texture[4] = { (char*)"��", (char*)"��", (char*)"��ǡ�", (char*)"������" };
	
	int Color[4] = { 11, 11, 11, 12 };

};

struct Enemy
{
	char* Texture[4] = { (char*)"��", (char*)"�ءԢ�", (char*)"�գա�", (char*)"������" };
	int Color[4] = { 4, 12, 12, 12 };
	ULONGLONG ETime;
};

struct Bullet
{
	char* Texture = (char*)"��";
};

struct Missile
{
	char* Texture = (char*)"��";
};

struct Explosion
{
	char* Texture[3] = { (char*)"!BOOM!", (char*)"SCORE+", (char*)" 500 !" };
	int Color = 4;		
};

struct Object
{
	Player Player;
	Enemy Enemy;
	Bullet Bullet;
	Missile Missile;
	Explosion Expl;
	Transform TransInfo;
};