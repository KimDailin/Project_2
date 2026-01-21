#include <stdio.h>
#include <conio.h>
#include	<windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int screenIndex;
HANDLE screen[2];

void Initialize() {
	CONSOLE_CURSOR_INFO cursor;

	// 화면 버퍼를 2개 생성합니다.
	screen[0] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	screen[1] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);
}

void Flip()
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);
	screenIndex = !screenIndex;
}

void Clear() 
{
	COORD position = { 0,0 };
	DWORD dword;
	CONSOLE_SCREEN_BUFFER_INFO buffer;
	HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(console, &buffer);

	int width = buffer.srWindow.Right - buffer.srWindow.Left + 1;
	int height = buffer.srWindow.Bottom - buffer.srWindow.Top + 1;

	FillConsoleOutputCharacter(
		screen[screenIndex], ' ', width * height, position, &dword
	);
}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

void Render(int x,int y,const char *character)
{
	DWORD dword;
	COORD position = { x,y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], character, strlen(character), &dword, NULL);
}

int main()
{
	char key = 0;
	int x = 0, y = 0;
	
	Initialize();

	while (1)
	{
		Flip();
		Clear();
		key = _getch();

		if (key == -32 || key == 0) {
			key = _getch();
		}

		switch (key) {
		case UP: if (y > 0) { y--; }
			break;
		case LEFT: if (x > 0) { x -= 2; }
			break;
		case RIGHT : x+=2;
			break;
		case DOWN : y++;
			break;
		default : printf("exception\n");
			break;
		}
		CONSOLE_SCREEN_BUFFER_INFO console;
		GetConsoleScreenBufferInfo(screen[screenIndex], &console);

		int L = console.srWindow.Left;
		int R = console.srWindow.Right-2;
		int T = console.srWindow.Top;
		int B = console.srWindow.Bottom;

		if (x < L) x = L;
		if (x > R) x = R;
		if (y < T) y = T;
		if (y > B) y = B;
		Render(x, y, "☆");
	}
	return 0;
}