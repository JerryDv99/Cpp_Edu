#pragma once

void Initialize(Object* _Object, float _PosX, float _PosY);

void PInitialize(Object* _Player, float _PosX = 0, float _PosY = 0, float _PosZ = 0);

void EInitialize(Object* _Enemy, float _PosX = 0, float _PosY = 0, float _PosZ = 0);

void ItemInit(Object* _Item, int _rand);

char* SetName();

void SetCursorPosition(const float _x, const float _y);

void SetTextColor(const int _Color);

BackGround* CreateBackGround(const int _rand);

void OnDrawBG(BackGround* _BG);

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);

void HideCursor(const bool _Visible);

void LogoScene(sLogo* _logo, ULONGLONG _t, ULONGLONG _load);

void MainScene(Object* _icon, int _arr[], char _name[][4]);

void ScoreBoard(int _arr[], char _name[][4]);

void Tutorial(Object* _Player, ULONGLONG _time, ULONGLONG _tuto);

Object* CreateEnemy(const float _x, const float _y, ULONGLONG _time);

void EnemyMove(Object* _Enemy, Vector3 _Direction, int _x);

Object* CreateAlly(const float _x, const float _y, const int _i);

float GetDistance(const Object* _ObjectA, const Object* _ObjectB);

Vector3 GetDirection(const Object* _ObjectA, const Object* _ObjectB);

Object* CreateBullet(const float _x, const float _y);

bool ECollision(const Object* _Object, const Object* _Enemy);

bool PCollision(const Object* _Object, const Object* _Player);

void UpdateInput(Object* _Object);

void UpdateInput1(Object* _Object);

void ScoreP(const int _i);

Object* CreateItem(const int _rand);

void Warning(const int _x, const int _y);

void BossScene();


Vector3 Direction;

ULONGLONG Time = GetTickCount64();
ULONGLONG Logo = GetTickCount64();
ULONGLONG Loading = GetTickCount64();
ULONGLONG BG = GetTickCount64();
ULONGLONG GameTime = GetTickCount64();
ULONGLONG EnemyTime1 = GetTickCount64();
ULONGLONG Cooling1 = GetTickCount64();
ULONGLONG ERR1 = GetTickCount64();
ULONGLONG Loaded1 = GetTickCount64();
ULONGLONG DropItem1 = GetTickCount64();
ULONGLONG BuffTime1 = GetTickCount64();

Object* Bullet[256] = { nullptr };
Object* EBullet[128] = { nullptr };
Object* Missile[8] = { nullptr };
Object* Item[2] = { nullptr };

bool first = true;
bool Story1 = false;
bool loop = true;
bool Story = false;
bool Check = false;
bool OHeat = false;
bool Load = false;
bool Buff = false;
bool Exit = false;

bool RCheck = false;
bool LCheck = false;
bool Main = true;

bool tuto1 = false;
bool tuto2 = false;
bool tuto3 = false;
bool tuto4 = false;
bool tuto5 = false;
bool tuto6 = false;

int Score = 0;
int Kill = 0;
int ECount = 0;
int Life = 2;	// 營紫瞪 晦��
int T;

float Heat = 0.0f;


void Initialize(Object* _Object, float _PosX, float _PosY) 
{
	_Object->TransInfo.Position = Vector3(_PosX, _PosY);

	_Object->TransInfo.Rotation = Vector3(0.0f, 0.0f);

	_Object->TransInfo.Scale = Vector3(2.0f, 1.0f);
}

void PInitialize(Object* _Player, float _PosX , float _PosY, float _PosZ)
{
	_Player->TransInfo.Position = Vector3(_PosX, _PosY);

	_Player->TransInfo.Rotation = Vector3(0.0f, 0.0f);

	_Player->TransInfo.Scale = Vector3((float)strlen(_Player->Player.Texture[3]), 4.0f);
} 

void EInitialize(Object* _Enemy, float _PosX , float _PosY, float _PosZ)
{
	_Enemy->TransInfo.Position = Vector3(_PosX, _PosY);
	
	_Enemy->TransInfo.Rotation = Vector3(0.0f, 0.0f);

	_Enemy->TransInfo.Scale = Vector3((float)strlen(_Enemy->Enemy.Texture[0]), 4.0f);

	_Enemy->Enemy.ETime = 0;
}  

// 衛除 陴戲賊 嘐餌橾 撮嫦 嬴檜蠱 虜菟晦
void ItemInit(Object* _Item, int _rand)
{
	if (_rand % 2 == 0)
	{
		_Item->Item.Option = 1;
		_Item->Item.Texture[0] = (char*)" x2 ";
		_Item->Item.Texture[1] = (char*)"‵‵";
	}
	if (_rand % 2 == 1)
	{
		_Item->Item.Option = 2;
		_Item->Item.Texture[0] = (char*)" +1 ";
		_Item->Item.Texture[1] = (char*)" HP ";
	}

	_Item->TransInfo.Position = Vector3((_rand % 30 * 2) + 20 , 1.0f);
	_Item->TransInfo.Rotation = Vector3(0.0f, 0.0f);
	_Item->TransInfo.Scale = Vector3((float)strlen(_Item->Item.Texture[0]), 2.0f);
}

void SetCursorPosition(const float _x, const float _y)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

char* SetName()
{
	char Buffer[128] = "";

	cout << " : "; cin >> Buffer;

	char* pName = new char[strlen(Buffer) + 1];

	strcpy(pName, Buffer);

	return pName;
}

void SetTextColor(const int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

BackGround* CreateBackGround(const int _rand)
{
	BackGround* _BG = new BackGround;
	_BG->Texture = (char*)"*";

	_BG->TransInfo.Position.x = _rand % 120;
	_BG->TransInfo.Position.y = 1;
	_BG->Color = _rand % 9 + 5;

	return _BG;
}



void OnDrawBG(BackGround* _BG)
{
	OnDrawText(_BG->Texture,
		_BG->TransInfo.Position.x,
		_BG->TransInfo.Position.y,
		_BG->Color);
}

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	char* pText = new char[4];
	_itoa(_Value, pText, 10);

	cout << _Value;
}

void OnDrawObj(Object* _Object, const float _x, const float _y)
{
	
	if (_Object->Player.Name != nullptr)
	{
		OnDrawText(_Object->Player.Texture[0],
			_Object->TransInfo.Position.x,
			_Object->TransInfo.Position.y,
			_Object->Player.Color[0]);
		OnDrawText(_Object->Player.Texture[1],
			_Object->TransInfo.Position.x,
			_Object->TransInfo.Position.y + 1,
			_Object->Player.Color[1]);
		OnDrawText(_Object->Player.Texture[2],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y + 2,
			_Object->Player.Color[2]);
		OnDrawText(_Object->Player.Texture[3],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y + 3,
			_Object->Player.Color[3]);

	}
	else if (_Object->Item.Option == 1 || _Object->Item.Option == 2)
	{
		OnDrawText(_Object->Item.Texture[0],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y,
			_Object->Item.Color);
		OnDrawText(_Object->Item.Texture[1],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y - 1,
			_Object->Item.Color);
	}
	else if (_Object->Enemy.ETime != 0)
	{
		OnDrawText(_Object->Enemy.Texture[0],
			_Object->TransInfo.Position.x,
			_Object->TransInfo.Position.y,
			_Object->Enemy.Color[0]);
		OnDrawText(_Object->Enemy.Texture[1],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y - 1,
			_Object->Enemy.Color[1]);
		OnDrawText(_Object->Enemy.Texture[2],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y - 2,
			_Object->Enemy.Color[2]);
		OnDrawText(_Object->Enemy.Texture[3],
			_Object->TransInfo.Position.x - 2,
			_Object->TransInfo.Position.y - 3,
			_Object->Enemy.Color[3]);
	}	
}

void HideCursor(const bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}

void LogoScene(sLogo* _logo, ULONGLONG _t, ULONGLONG _load)
{
	int count = 0;
	for (int i = 0; i < 40; ++i)
	{
		OnDrawText(_logo->Texture[i], 0, 0 + i);
	}

	
	while (_t + 2500 > GetTickCount64())
	{
		if (_load + 50 < GetTickCount64())
		{
			_load = GetTickCount64();
			for (int i = 0; count < 40; ++i)
			{
				OnDrawText("〧", 20.0f + count * 2, 56, 10);
				count++;

				break;
			}
		}
	}
	
}                                

void MainScene(Object* _icon, int _arr[], char _name[][4])
{
	system("cls");

	int Width = 12;
	int Height = 7;

	OnDrawText((char*)"                                             *N*                                                ", Width, Height ,9);
	OnDrawText((char*)"                                             MNN*                                               ", Width, Height + 1,9);
	OnDrawText((char*)"                                            *NNNF                                               ", Width, Height + 2,9);
	OnDrawText((char*)"                                            VNNNN*                                              ", Width, Height + 3,9);
	OnDrawText((char*)"                                            MNNNNV                                              ", Width, Height + 4,9);
	OnDrawText((char*)"                                           *NFVFNF                                              ", Width, Height + 5,9);
	OnDrawText((char*)"                                           *N   VM                                              ", Width, Height + 6,9);
	OnDrawText((char*)"                                           *N***VN                                              ", Width, Height + 7,9);
	OnDrawText((char*)"                                           *N   *N                                              ", Width, Height + 8,9);
	OnDrawText((char*)"                                           *N   VN                                              ", Width, Height + 9,9);
	OnDrawText((char*)"                                           *N***VN                                              ", Width, Height + 10,9);
	OnDrawText((char*)"                                           *N   VN                                              ", Width, Height + 11,9);
	OnDrawText((char*)"                                        IMVVN   *NVMM*                                          ", Width, Height + 12,9);
	OnDrawText((char*)"                                       *NNNNN   *$NNNV                                          ", Width, Height + 13,9);
	OnDrawText((char*)"                                     *INNNNNN***INNNNNN*                                        ", Width, Height + 14,9);
	OnDrawText((char*)"                                    VNNNNNNNNNNNNNNNNNNNV                                       ", Width, Height + 15,9);
	OnDrawText((char*)"                                   VNNNNNNNNNNNNNNNNNNNNNM*                                     ", Width, Height + 16,9);
	OnDrawText((char*)"                                  *INNNNNNNNNNNNNNNNNNNNNMV                                     ", Width, Height + 17,9);
	OnDrawText((char*)"                                    VVVVVVVVINNNMFVVVVVVV*                                      ", Width, Height + 18,9);
	OnDrawText((char*)"FNMMMMMMMMMMMMMMMMMMMM                        VV                        MMMMMMMMMMMMMMMMMMMMMMM*", Width, Height + 19,9);
	OnDrawText((char*)" *VVVVVVVVVVVVVVVVVVVV                                                   VVVVVVVVVVVVVVVVVVVVV* ", Width, Height + 20,12);
	OnDrawText((char*)"  *INNNNNNNNNNNNNNNNNM                                                   VNNNNNNNNNNNNNNNNNMV   ", Width, Height + 21,12);
	OnDrawText((char*)"    *VFFFFFFFFFFFFFFFV                                                   VFFFFFFFFFFFFFFFFV     ", Width, Height + 22,12);
	OnDrawText((char*)"     *FMMIMMIIIIIMMMMI                                                   VMIIIMMMMMIIIIIIV      ", Width, Height + 23,12);
	OnDrawText((char*)"       *FFFFFFFFFFFFFF                                                   VFFFFFFFFFFFFIV        ", Width, Height + 24,12);
	OnDrawText((char*)"        *VFFFFVVVVFVFV                                                   VFFFFFFFFVFFV*         ", Width, Height + 25,12);
	OnDrawText((char*)"          VM$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$N*M*F$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$I*          ", Width, Height + 26,9);
	OnDrawText((char*)"            ****************VVVVVVVVVVVV*VVVVMNI*VV***VVVVVVVVVVVV******************            ", Width, Height + 27,9);
	OnDrawText((char*)"                          *MNNNNNNNNNINNFVVFNNNNNMVVFNNIMNNNNNNNNM*                             ", Width, Height + 28,9);
	OnDrawText((char*)"                          NNNNNNNNNF VNNNNM*IMINN*MNNNNV *MNNNNNNNN*                            ", Width, Height + 29,9);
	OnDrawText((char*)"                         FNNNNNNNI* VNNNNN**V*VVVVVNNNNNV  INNNNNNNN*                           ", Width, Height + 30,9);
	OnDrawText((char*)"                        FNNNNNNM*  VNNNNNF *FNNNMV*INNNNNM* *MNNNNNNN                           ", Width, Height + 31,9);
	OnDrawText((char*)"                       VNNNNNNV  VNNNNNNNMNNNNNNNNNMNNNNNNNF  *INNNNNI                          ", Width, Height + 32,9);
	OnDrawText((char*)"                       VNNNNF* *MNNNNNNNNNNNNNNNNNNNNNNNNNNNM*  VNNNNV                          ", Width, Height + 33,9);
	OnDrawText((char*)"                        VNI*  *NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNI* *FNN                           ", Width, Height + 34,9);
	OnDrawText((char*)"                         V  *FNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN*  **                           ", Width, Height + 35,9);
	OnDrawText((char*)"                           FNNNNNNNNNI*VMVVVNNNNNMVVMFVFNNNNNNNNNI                              ", Width, Height + 36,9);
	OnDrawText((char*)"                           MNNNNNNMIV*  V    V$F    V   VIMNNNNNNM*                             ", Width, Height + 37,9);
	OnDrawText((char*)"                            *VV**       *    *V*    *       ***VV                               ", Width, Height + 38,9);

	OnDrawText((char*)"MMMMMN  VNNMF  VMMNNIV  ", Width + 22, Height + 19, 9);
	OnDrawText((char*)"VINNV  MNV VN$ VNM  INF ", Width + 22, Height + 20, 9);
	OnDrawText((char*)" V$N   N$  *N$ FNI  FNI ", Width + 22, Height + 21, 9);
	OnDrawText((char*)" V$N   N$  *N$ VNNMMNI* ", Width + 22, Height + 22, 9);
	OnDrawText((char*)" V$N   N$  *N$ VNM      ", Width + 22, Height + 23, 9);
	OnDrawText((char*)" V$N   FNVVFNM VNI      ", Width + 22, Height + 24, 9);
	OnDrawText((char*)" VVV     VVV   VFV      ", Width + 22, Height + 25, 9);
	OnDrawText((char*)"  VFNNMV  MNV  MNN NMV  NM", Width + 48, Height + 19, 12);
	OnDrawText((char*)" V$N  F$M N$V  N$N $NN  $N ", Width + 48, Height + 20, 12);
	OnDrawText((char*)" V$N      N$V  N$M NNNNV$$ ", Width + 48, Height + 21, 12);
	OnDrawText((char*)" V$N VMMF N$V  N$V $MVNMNN ", Width + 48, Height + 22, 12);
	OnDrawText((char*)" V$N  FNM NNV  N$V NM VNNN ", Width + 48, Height + 23, 12);
	OnDrawText((char*)"  MNVVMNV FNMVFNMN $M  NNN ", Width + 48, Height + 24, 12);
	OnDrawText((char*)"   VFFV     VVVV   FV  VVV ", Width + 48, Height + 25, 12);
		
	OnDrawText((char*)"1 . START", 26, 52);
	OnDrawText((char*)"2 . RANK", 56, 52);
	OnDrawText((char*)"3 . EXIT", 86, 52);

	if (_icon->TransInfo.Position.x == 20 || _icon->TransInfo.Position.x == 50)
	{
		if (!RCheck && GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			RCheck = true;
		}

		if (RCheck && !(GetAsyncKeyState(VK_RIGHT) & 0x8000))
		{
			_icon->TransInfo.Position.x += 30;
			RCheck = false;
		}			
	}
	if (_icon->TransInfo.Position.x == 50 || _icon->TransInfo.Position.x == 80)
	{
		if (!LCheck && GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			LCheck = true;
		}		
		if (LCheck && !(GetAsyncKeyState(VK_LEFT) & 0x8000))
		{
			_icon->TransInfo.Position.x -= 30;
			LCheck = false;
		}	
		
	}

	if (_icon->TransInfo.Position.x == 20)
		OnDrawText((char*)"1 . START", 26, 52, 10);
	if (_icon->TransInfo.Position.x == 50)
		OnDrawText((char*)"2 . RANK", 56, 52, 10);
	if (_icon->TransInfo.Position.x == 80)
		OnDrawText((char*)"3 . EXIT", 86, 52, 10);

	OnDrawText(_icon->Icon.Texture, _icon->TransInfo.Position.x, _icon->TransInfo.Position.y, 11);

	if (GetAsyncKeyState(VK_RETURN))
	{
		if (_icon->TransInfo.Position.x == 20)
			Main = false;
		if (_icon->TransInfo.Position.x == 50)
			ScoreBoard(_arr, _name);
		if (_icon->TransInfo.Position.x == 80)
			exit(NULL);

	}

}

void ScoreBoard(int _arr[], char _name[][4])
{
	system("cls");
	HideCursor(false);

	int Width = 60 - strlen("灰天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天汐") / 2;
	int Height = 16;
	OnDrawText((char*)".-. .-. .-. .-. .-. .-. .-. .-. .-. .-.", 40.0f, 5.0f, 14);
	OnDrawText((char*)"`-. |   | | |(  |-  |(  | | |-| |(  |  )", 40.0f, 6.0f, 14);
	OnDrawText((char*)"`-' `-' `-' ' ' `-' `-' `-' ` ' ' ' `-'", 40.0f, 7.0f, 14);

	OnDrawText((char*)"灰天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天汐", Width, Height, 15);
	OnDrawText((char*)"太                            RANK  :           1st                                          太", Width, Height + 1, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 2, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 3, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 4, 15);
	OnDrawText((char*)"太                            RANK  :           2nd                                          太", Width, Height + 5, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 6, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 7, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 8, 15);
	OnDrawText((char*)"太                            RANK  :           3rd                                          太", Width, Height + 9, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 10, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 11, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 12, 15);
	OnDrawText((char*)"太                            RANK  :           4th                                          太", Width, Height + 13, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 14, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 15, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 16, 15);
	OnDrawText((char*)"太                            RANK  :           5th                                          太", Width, Height + 17, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 18, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 19, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 20, 15);
	OnDrawText((char*)"太                            RANK  :           6th                                          太", Width, Height + 21, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 22, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 23, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 24, 15);
	OnDrawText((char*)"太                            RANK  :           7th                                          太", Width, Height + 25, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 26, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 27, 15);
	OnDrawText((char*)"太                   天天天天天天天天天天天天天天天天天天天天天天天天天天                    太", Width, Height + 28, 15);
	OnDrawText((char*)"太                            RANK  :           8th                                          太", Width, Height + 29, 15);
	OnDrawText((char*)"太                            SCORE :                                                        太", Width, Height + 30, 15);
	OnDrawText((char*)"太                            NAME  :                                                        太", Width, Height + 31, 15);
	OnDrawText((char*)"汍天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天污", Width, Height + 32, 15);

	OnDrawText((char*)" . ", Width + 22, Height + 1, 14);
	OnDrawText((char*)"'| ", Width + 22, Height + 2, 14);
	OnDrawText((char*)"'-'", Width + 22, Height + 3, 14);
	OnDrawText((char*)",-.", Width + 22, Height + 5, 8);
	OnDrawText((char*)" / ", Width + 22, Height + 6, 8);
	OnDrawText((char*)"'--", Width + 22, Height + 7, 8);
	OnDrawText((char*)"--.", Width + 22, Height + 9, 6);
	OnDrawText((char*)"--|", Width + 22, Height + 10, 6);
	OnDrawText((char*)"--'", Width + 22, Height + 11, 6);
	OnDrawText((char*)" ,.", Width + 22, Height + 13, 11);
	OnDrawText((char*)"'-|", Width + 22, Height + 14, 11);
	OnDrawText((char*)"  '", Width + 22, Height + 15, 11);
	OnDrawText((char*)".--", Width + 22, Height + 17, 11);
	OnDrawText((char*)"'-.", Width + 22, Height + 18, 11);
	OnDrawText((char*)"`-'", Width + 22, Height + 19, 11);
	OnDrawText((char*)" ,-", Width + 22, Height + 21, 11);
	OnDrawText((char*)":-.", Width + 22, Height + 22, 11);
	OnDrawText((char*)"`-'", Width + 22, Height + 23, 11);
	OnDrawText((char*)"--,", Width + 22, Height + 25, 11);
	OnDrawText((char*)" / ", Width + 22, Height + 26, 11);
	OnDrawText((char*)"'  ", Width + 22, Height + 27, 11);
	OnDrawText((char*)",-.", Width + 22, Height + 29, 11);
	OnDrawText((char*)":-:", Width + 22, Height + 30, 11);
	OnDrawText((char*)"`-'", Width + 22, Height + 31, 11);

	OnDrawText((char*)_name[0], 60, Height + 2, 14);
	OnDrawText(_arr[0], 60, Height + 3, 14);
	OnDrawText((char*)_name[1], 60, Height + 6, 14);
	OnDrawText(_arr[1], 60, Height + 7, 14);
	OnDrawText((char*)_name[2], 60, Height + 10, 14);
	OnDrawText(_arr[2], 60, Height + 11, 14);
	OnDrawText((char*)_name[3], 60, Height + 14, 14);
	OnDrawText(_arr[3], 60, Height + 15, 14);
	OnDrawText((char*)_name[4], 60, Height + 18, 14);
	OnDrawText(_arr[4], 60, Height + 19, 14);
	OnDrawText((char*)_name[5], 60, Height + 22, 14);
	OnDrawText(_arr[5], 60, Height + 23, 14);
	OnDrawText((char*)_name[6], 60, Height + 26, 14);
	OnDrawText(_arr[6], 60, Height + 27, 14);
	OnDrawText((char*)_name[7], 60, Height + 30, 14);
	OnDrawText(_arr[7], 60, Height + 31, 14);

	OnDrawText("Exit [X]", 56, 56, 10);
	
	while (true)
	{
		if (GetAsyncKeyState(0x58))
		{
			
			break;
		}
	}   
	HideCursor(true);
}

void Tutorial(Object* _Player, ULONGLONG _time, ULONGLONG _tuto)
{
	int Height = 50;
	Object* Enemy = new Object;
	EInitialize(Enemy, 60, 10);
	Enemy->Enemy.ETime = 1;

	Object* Enemy1 = CreateEnemy(100, 10, 1);
	Object* Enemy2 = CreateEnemy(100, 20, 1);

	Story = true;
	OHeat = true;

	if (_time + 20 < GetTickCount64())
	{
		_time = GetTickCount64();
		system("cls");

		OnDrawText((char*)"灰天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天汐", 2, Height);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 1);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 2);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 3);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 4);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 5);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 6);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 7);
		OnDrawText((char*)"太                                                                                                                 太", 2, Height + 8);
		OnDrawText((char*)"汍天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天污", 2, Height + 9);

		if (_tuto + 100 < GetTickCount64() && tuto1)
		{
			OnDrawText((char*)"寰喟ж褐陛 褐霤, 釭朝 檜 л渠曖 雖�眥� 煎盪蝶 薯絮橾撮. 濠啻 檜葷擎 劃陛?", 60 - strlen("寰喟ж褐陛 褐霤, 釭朝 檜 л渠曖 雖�眥� 煎盪蝶 薯絮橾撮. 濠啻 檜葷擎 劃陛?") / 2, Height + 3);
			OnDrawText((char*)"檜葷 ", 52, Height + 6);
			_Player->Player.Name = SetName();
			_tuto = GetTickCount64();
			tuto1 = false;
		}

		if (!tuto1 && tuto2)
		{
			if (_tuto + 3000 > GetTickCount64())
			{
				if (_tuto + 2000 > GetTickCount64())
				{
					OnDrawText((char*)"", 60 - strlen("") / 2, Height + 3);
					OnDrawText((char*)"旨天天天天天汕", _Player->TransInfo.Position.x - 5, _Player->TransInfo.Position.y - 1, 12);
					OnDrawText((char*)"太         太", _Player->TransInfo.Position.x - 5, _Player->TransInfo.Position.y, 12);
					OnDrawText((char*)"太         太", _Player->TransInfo.Position.x - 5, _Player->TransInfo.Position.y + 1, 12);
					OnDrawText((char*)"太         太", _Player->TransInfo.Position.x - 5, _Player->TransInfo.Position.y + 2, 12);
					OnDrawText((char*)"太         太", _Player->TransInfo.Position.x - 5, _Player->TransInfo.Position.y + 3, 12);
					OnDrawText((char*)"汍天天天天天污", _Player->TransInfo.Position.x - 5, _Player->TransInfo.Position.y + 4, 12);
				}
				OnDrawText((char*)"說假啪 ル衛脹 晦羹陛 濠啻橾撮", 60 - strlen("說假啪 ル衛脹 晦羹陛 濠啻橾撮") / 2, Height + 3);
				OnDrawText((char*)"寞щ酈煎 檜翕й 熱 氈雖", 60 - strlen("寞щ酈煎 檜翕й 熱 氈雖") / 2, Height + 6);		
			}
			if (_tuto + 3000 < GetTickCount64())
			{
				Story = false;
				_tuto = GetTickCount64();
				tuto2 = false;
			}
			
		}

		if (!tuto2 && tuto3)
		{
			if (_tuto + 5000 > GetTickCount64())
			{
				if (_tuto + 2000 > GetTickCount64())
				{
					OnDrawText((char*)"", 60 - strlen("") / 2, Height + 3);
					OnDrawText((char*)"旨天天天天天天汕", Enemy->TransInfo.Position.x - 6, Enemy->TransInfo.Position.y - 4, 12);
					OnDrawText((char*)"太           太", Enemy->TransInfo.Position.x - 6, Enemy->TransInfo.Position.y - 3, 12);
					OnDrawText((char*)"太           太", Enemy->TransInfo.Position.x - 6, Enemy->TransInfo.Position.y - 2, 12);
					OnDrawText((char*)"太           太", Enemy->TransInfo.Position.x - 6, Enemy->TransInfo.Position.y - 1, 12);
					OnDrawText((char*)"太           太", Enemy->TransInfo.Position.x - 6, Enemy->TransInfo.Position.y, 12);
					OnDrawText((char*)"汍天天天天天天污", Enemy->TransInfo.Position.x - 6, Enemy->TransInfo.Position.y + 1, 12);
				}
				OnDrawText((char*)"賅曖 瞳晦蒂 蹺陛ц啻", 60 - strlen("賅曖 瞳晦蒂 蹺陛ц啻") / 2, Height + 3);
				OnDrawText((char*)"蝶む檜蝶 夥蒂 揚楝 橾奩 鼠濰擊 嫦餌п爾啪", 60 - strlen("蝶む檜蝶 夥蒂 揚楝 橾奩 鼠濰擊 嫦餌п爾啪") / 2, Height + 6);
				OHeat = false;
			}
			if (_tuto + 3000 < GetTickCount64())
			{
				_tuto = GetTickCount64();
				tuto3 = false;
			}
		}

		if (!tuto3 && tuto4 && !Enemy)
		{
			if (_tuto + 7000 > GetTickCount64())
			{
				OnDrawText((char*)"澀ц啻, ж雖虜 褐霤菟 渠睡碟檜 ъ奢縑 識韓擊 ж雖", 60 - strlen("澀ц啻, ж雖虜 褐霤菟 渠睡碟檜 ъ奢縑 識韓擊 ж雖") / 2, Height + 2);
				OnDrawText((char*)"橾奩 鼠濰擎 嫦餌 醞橾陽 啗樓 嗑剪錶雖堅 婁翮腎賊 5蟾 翕寰 傢陝縑 菟橫陛 嫦餌陛 碳陛棟ж棻", 60 - strlen("橾奩 鼠濰擎 嫦餌 醞橾陽 啗樓 嗑剪錶雖堅 婁翮腎賊 5蟾 翕寰 傢陝縑 菟橫陛 嫦餌陛 碳陛棟ж棻") / 2, Height + 4, 12);
				OnDrawText((char*)"嫦餌 醞檜 嬴棍隆 傢陝濰纂陛 濛翕腎橫 翮 熱纂陛 薄薄 雲橫雖棲 霤堅ж紫煙", 60 - strlen("嫦餌 醞檜 嬴棍隆 傢陝濰纂陛 濛翕腎橫 翮 熱纂陛 薄薄 雲橫雖棲 霤堅ж紫煙") / 2, Height + 6);
			}
			if (_tuto + 7000 < GetTickCount64())
			{
				_tuto = GetTickCount64();
				tuto4 = false;
			}
		}

		if (!tuto4 && tuto5)
		{
			if (_tuto + 8000 > GetTickCount64())
			{
				OnDrawText((char*)"棻擠擎 嘐餌橾 餌辨徹縑 渠п 憲溥輿雖", 60 - strlen("棻擠擎 嘐餌橾 餌辨徹縑 渠п 憲溥輿雖") / 2, Height + 1);
				OnDrawText((char*)"瞳菟紫 渡翱�� 鼠濰檜 氈堅 奢問擊 п螞棻啻", 60 - strlen("瞳菟紫 渡翱�� 鼠濰檜 氈堅 奢問擊 п螞棻啻") / 2, Height + 3);
				OnDrawText((char*)"檜 陽 [ x ] 酈蒂 揚楝 嘐餌橾擊 嫦餌ж賊, 瞳 癱餌羹蒂 だ惚ж貊 釭嬴陛 唳煎 鼻曖 瞳擊 譆渠 3晦梱雖 だ惚 陛棟ж雖", 60 - strlen("檜 陽 [ x ] 酈蒂 揚楝 嘐餌橾擊 嫦餌ж賊, 瞳 癱餌羹蒂 だ惚ж貊 釭嬴陛 唳煎 鼻曖 瞳擊 譆渠 3晦梱雖 だ惚 陛棟ж雖") / 2, Height + 5);
				OnDrawText((char*)"嘐餌橾煎 瞳擊 籀纂ж賊 爾傘蝶 薄熱陛 觼棲 瞳營瞳模縑 餌辨ж紫煙", 60 - strlen("嘐餌橾煎 瞳擊 籀纂ж賊 爾傘蝶 薄熱陛 觼棲 瞳營瞳模縑 餌辨ж紫煙") / 2, Height + 7);
			}
			if (_tuto + 7000 < GetTickCount64())
			{
				_tuto = GetTickCount64();
				tuto5 = false;
			}
		}
		if (!Story)
			UpdateInput1(_Player);

		if (!OHeat)
		{
			if (!Check && GetAsyncKeyState(VK_SPACE) & 0x0001)
			{
				Check = true;
			}
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				if (Heat < 10)
					Heat += 0.25f;
				for (int i = 0; i < 128; ++i)
				{
					if (Bullet[i] == nullptr)
					{
						if (!Buff)
						{
							Bullet[i] = CreateBullet(
								_Player->TransInfo.Position.x - 2,
								_Player->TransInfo.Position.y + 1);
							Bullet[i + 1] = CreateBullet(
								_Player->TransInfo.Position.x + 2,
								_Player->TransInfo.Position.y + 1);
						}
						else if (Buff)
						{
							Bullet[i] = CreateBullet(
								_Player->TransInfo.Position.x - 4,
								_Player->TransInfo.Position.y + 1);
							Bullet[i + 1] = CreateBullet(
								_Player->TransInfo.Position.x + 4,
								_Player->TransInfo.Position.y + 1);
							Bullet[i + 2] = CreateBullet(
								_Player->TransInfo.Position.x - 2,
								_Player->TransInfo.Position.y + 1);
							Bullet[i + 3] = CreateBullet(
								_Player->TransInfo.Position.x + 2,
								_Player->TransInfo.Position.y + 1);
						}

						break;
					}
				}
			}

			if (Check && !(GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				Check = false;
			}

			if (!Check)
			{
				if (Cooling1 + 500 < GetTickCount64())
				{
					Cooling1 = GetTickCount64();
					if (Heat > 0)
						Heat -= 1.0f;
					if (Heat < 0)
						Heat = 0;
				}
			}
		}
		for (int i = 0; i < 128; ++i)
		{
			if (Bullet[i] != nullptr)
			{
				for (int j = 0; j < 64; ++j)
				{
					if (Enemy)
					{
						if (ECollision(Bullet[i], Enemy))
						{
							ScoreP(500);
							Kill++;
							Score += 500;

							delete Enemy;
							Enemy = nullptr;

							delete Bullet[i];
							Bullet[i] = nullptr;

							break;
						}
					}
				}
				if (Bullet[i] != nullptr)
				{
					if (Bullet[i]->TransInfo.Position.y <= 0)
					{
						delete Bullet[i];
						Bullet[i] = nullptr;
					}
				}
			}
		}

		if (Load)
		{
			if (GetAsyncKeyState(0x58))
			{
				for (int i = 0; i < 8; ++i)
				{
					if (Missile[i] == nullptr)
					{
						Load = false;
						Missile[i] = CreateBullet(
							_Player->TransInfo.Position.x,
							_Player->TransInfo.Position.y - 1);
						Missile[i]->Missile.MTime = GetTickCount64();
						Missile[i]->Speed = 0;
						Missile[i]->HP = 2;
						Loaded1 = GetTickCount64();
						break;
					}
				}
			}
		}

		for (int i = 0; i < 8; ++i)
		{
			if (Missile[i] != nullptr)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (Enemy[j] != nullptr)
					{
						if (ECollision(Missile[i], Enemy[j]))
						{
							ScoreP(2000);
							Score += 2000;
							Kill++;

							if (Missile[i]->HP > 1)
							{
								Missile[i]->HP -= 1;
							}

							else if (Missile[i]->HP == 1)
							{
								delete Missile[i];
								Missile[i] = nullptr;
							}


							delete Enemy[j];
							Enemy[j] = nullptr;

							break;
						}
					}
				}
				if (Missile[i] != nullptr)
				{
					if (Missile[i]->TransInfo.Position.y <= 0)
					{
						delete Missile[i];
						Missile[i] = nullptr;
					}
				}

			}
		}
		OnDrawObj(_Player, _Player->TransInfo.Position.x, _Player->TransInfo.Position.y);
		OnDrawObj(Enemy, Enemy->TransInfo.Position.x, Enemy->TransInfo.Position.y);
	}
	
}

Object* CreateEnemy(const float _x, const float _y, ULONGLONG _time)
{
	Object* _Enemy = new Object;

	PInitialize(_Enemy, _x, _y);

	_Enemy->Enemy.ETime = _time;

	return _Enemy;
}

void EnemyMove(Object* _Enemy, Vector3 _Direction , int _x)
{
	switch(_x)
	{
	case 1:
		if (_Enemy->TransInfo.Position.x > 4)
			_Enemy->TransInfo.Position.x--;
	case 2:
		if (_Enemy->TransInfo.Position.x < 116)
			_Enemy->TransInfo.Position.x++;
	case 3:
		if (_Enemy->TransInfo.Position.y < 56)
			_Enemy->TransInfo.Position.y++;
	case 4:
		if (_Enemy->TransInfo.Position.y > 40)
			_Enemy->TransInfo.Position.y--;
	case 5:
		if (_Enemy->TransInfo.Position.x > 4 &&
			_Enemy->TransInfo.Position.x < 116 &&
			_Enemy->TransInfo.Position.y < 56 &&
			_Enemy->TransInfo.Position.y > 40)
		{
			_Enemy->TransInfo.Position.x += _Direction.x;
			_Enemy->TransInfo.Position.y += _Direction.y;			
		}
			
	}
		
}

Object* CreateAlly(const float _x, const float _y, const int _i)
{
	Object* _Ally = new Object;

	PInitialize(_Ally, _x, _y);

	_Ally->Player.Name = (char*)"a";

	return _Ally;
}

float GetDistance(const Object* _ObjectA, const Object* _ObjectB)
{
	float x = _ObjectA->TransInfo.Position.x - _ObjectB->TransInfo.Position.x;
	float y = _ObjectA->TransInfo.Position.y - _ObjectB->TransInfo.Position.y;

	return sqrt((x * x) + (y * y));
}

Vector3 GetDirection(const Object* _ObjectA, const Object* _ObjectB)
{
	float x = _ObjectA->TransInfo.Position.x - _ObjectB->TransInfo.Position.x;
	float y = _ObjectA->TransInfo.Position.y - _ObjectB->TransInfo.Position.y;

	float Distance = sqrt((x * x) + (y * y));

	return Vector3(x / Distance, y / Distance);
}

Object* CreateBullet(const float _x, const float _y)
{
	Object* _Object = new Object;

	Initialize(_Object, _x, _y);

	return _Object;
}

bool ECollision(const Object* _Object, const Object* _Enemy)
{
	if (_Object->TransInfo.Position.y <= _Enemy->TransInfo.Position.y &&
		_Object->TransInfo.Position.y >= (_Enemy->TransInfo.Position.y - 2) &&
		_Object->TransInfo.Position.x >= (_Enemy->TransInfo.Position.x - 3) &&
		_Object->TransInfo.Position.x <= (_Enemy->TransInfo.Position.x + 3))
		return true;
	return false;
}

bool PCollision(const Object* _Object, const Object* _Player)
{
	if (_Object->TransInfo.Position.y >= _Player->TransInfo.Position.y &&
		_Object->TransInfo.Position.y <= (_Player->TransInfo.Position.y + 3) && 
		_Object->TransInfo.Position.x == _Player->TransInfo.Position.x)
		return true;
	return false;
}

void UpdateInput(Object* _Object)
{
	if (_Object->TransInfo.Position.y >= 20)
	{
		if (GetAsyncKeyState(VK_UP))
			_Object->TransInfo.Position.y -= 1;
	}
	
	if (_Object->TransInfo.Position.y < 56)
	{
		if (GetAsyncKeyState(VK_DOWN))
			_Object->TransInfo.Position.y += 1;
	}
		  
	if (_Object->TransInfo.Position.x > 2)
	{
		if (GetAsyncKeyState(VK_LEFT))
			_Object->TransInfo.Position.x -= 2;
	}

	if (_Object->TransInfo.Position.x < 116)
	{
		if (GetAsyncKeyState(VK_RIGHT))
			_Object->TransInfo.Position.x += 2;
	}	
}

void UpdateInput1(Object* _Object)
{
	if (_Object->TransInfo.Position.y >= 20)
	{
		if (GetAsyncKeyState(VK_UP))
			_Object->TransInfo.Position.y -= 1;
	}
	
	if (_Object->TransInfo.Position.y < 45)
	{
		if (GetAsyncKeyState(VK_DOWN))
			_Object->TransInfo.Position.y += 1;
	}
		  
	if (_Object->TransInfo.Position.x > 2)
	{
		if (GetAsyncKeyState(VK_LEFT))
			_Object->TransInfo.Position.x -= 2;
	}

	if (_Object->TransInfo.Position.x < 116)
	{
		if (GetAsyncKeyState(VK_RIGHT))
			_Object->TransInfo.Position.x += 2;
	}	
}

void ScoreP(const int _i)
{
	OnDrawText((char*)"+", 12.0f, 1.0f, 14);
	OnDrawText(_i, 14.0f , 1.0f, 14);
}

Object* CreateItem(const int _rand)
{
	Object* _Item = new Object;

	ItemInit(_Item, _rand);

	return _Item;
}

// 堅纂晦
void Warning(const int _x, const int _y)
{
	for (int i = 0; i + _y < 60; ++i)
	{
		switch (i % 9)
		{
		case 0:
			OnDrawText((char*)"/", _x, _y + i, 12);
			break;
		case 1:
			OnDrawText((char*)"W", _x, _y + i, 12);
			break;
		case 2:
			OnDrawText((char*)"A", _x, _y + i, 12);
			break;
		case 3:
			OnDrawText((char*)"R", _x, _y + i, 12);
			break;
		case 4:
			OnDrawText((char*)"N", _x, _y + i, 12);
			break;
		case 5:
			OnDrawText((char*)"I", _x, _y + i, 12);
			break;
		case 6:
			OnDrawText((char*)"N", _x, _y + i, 12);
			break;
		case 7:
			OnDrawText((char*)"G", _x, _y + i, 12);
			break;
		case 8:
			OnDrawText((char*)"!", _x, _y + i, 12);
			break;
		}
	}
}

void BossScene()
{
	float Width = 6.0f;
	float Height = 0.0f;
	OnDrawText((char*)"MMMMFVVVVFVVIMMMMMMMMMMNMNNMNNMMMFFNNNNNMVVVVV**VV*V*VV*IFFVVVVVVVFIMMMMMIFIMMMIFFFIIIIVVVVFVVVVVVV*****VMNN", Width, Height);
	OnDrawText((char*)"MMM::.:.::.:::::.:::..:****:::..:****:::**VVVVV*V**V:*F*VFV***VFF*::::*::*:::::*****:::**::*********:****MMM", Width, Height + 1);
	OnDrawText((char*)"MMM::*********::::::.:::***:::..:**:::*:VVVV**VV*.:VVFV**FV***VFII:..::**::::******:::::::**:***********VMMM", Width, Height + 2);
	OnDrawText((char*)" MMMVM*::**::*****::::::*****:..::***:**VFVV**VV**::VV**VIFV**VFII**:****::::*******:::*******:******NNVMNM ", Width, Height + 3);
	OnDrawText((char*)"  VV  NN************:******V**:::********VV**VVVV*******VMF**VVVIV********:::*VVV**************VVFFIIM  VV  ", Width, Height + 4);
	OnDrawText((char*)"        NMMMFVVVV***::******************VIVVVFVFVV******FMIVVVVVIM:.*V*******V*********VVVFIIIMMMNNN        ", Width, Height + 5);
	OnDrawText((char*)"          VV  NNNM*VVVVVVV**************VFFVVFFFVV******VIFVVIVFII**VV********VVVVFVVVVV:MNNNN  VV          ", Width, Height + 6);
	OnDrawText((char*)"                  VFNNMFIMIIVVVVVV**VVV**VFVVVVFFV*VVVFVVIFFVVVFMI*VVVVVVVFVV*VMIIMFIN M*N                  ", Width, Height + 7);
	OnDrawText((char*)"                  VV  NVFVVI*:MMMIIVVFFV*VMFVVVFFVVVVFVFVVFFVVVFMVVFFFVIMMMMM*VIVVFVIN  VV                  ", Width, Height + 8);
	OnDrawText((char*)"                      NVVVVFFM VV MFIFVVVFIVVFIII**VVVVVV**IIFVVFVFFVVMFMN VV NMV*FVVN                      ", Width, Height + 9);
	OnDrawText((char*)"                      NVVVVVIN    M*VVVFN   IFVVV***VVVV***VVFFN   NV*FVIN    MM*VFVVN                      ", Width, Height + 10);
	OnDrawText((char*)"                      NFVVVVIN    M*VVVFN   VVVVVV**V::V**VVVMVV   NVVIVVN    NMVVVFVN                      ", Width, Height + 11);
	OnDrawText((char*)"                       VVVVVV     M*VFVFN     MVVVV**::**VVVMM     NVVVVFN     VVVVVV                       ", Width, Height + 12);
	OnDrawText((char*)"                        VVVV       VVVVV       MFVVN****NVFNM       VVVVV       VVVV                        ", Width, Height + 13);
	OnDrawText((char*)"                                    VVV         MIVVV**VVVIM         VVV                                    ", Width, Height + 14);
	OnDrawText((char*)"                                                 NMVVVVVIMN                                                 ", Width, Height + 15);
	OnDrawText((char*)"                                                   MFVVIM                                                   ", Width, Height + 16);
	OnDrawText((char*)"                                                    NNNN                                                    ", Width, Height + 17);
}
