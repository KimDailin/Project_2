#include <stdio.h>
#include <windows.h>

enum state
{
	IDLE = 99,
	ATTACK,
	DIE

	// 열거형은 값을 따로 설정할 수 있으며, 따로 설정된 다음의 값은 그 전의 값에서
	// 하나 증가된 값으로 설정됩니다.
};

enum Color
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKSKYBLUE,
	DARKRED,
	DARKVIOLET,
	DARKYELLOW,
	GRAY,
	DARKGRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void set(enum state state) {
	switch (state)
	{
	case IDLE:	printf("IDLE\n");
		break;
	case ATTACK: printf("ATTACK\n");
		break;
	case DIE: printf("DIE\n");
		break;
	default: printf("Ex..\n");
		break;
	}
}

int main()
{
#pragma region 열거형
	// 관련된 상수의 값을 이름으로 정의한 정의한 자료형입니다.

	// enum state state;
	// scanf_s("%d", &state);
	// set(state);

#pragma endregion

	for (int i = 0; i <= 15; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		if (i != 0 && i % 3 == 0) {
			system("pause");
		}
		printf("color index :%d\n", i);
	}

	return 0;
}