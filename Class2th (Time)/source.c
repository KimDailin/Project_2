#include <stdio.h>

void shuffle(int array[], int size)
{
    for (int i = 0;i < size;i++) {
        int seed = rand() % size;
        int temp = array[seed];
        array[seed] = array[i];
        array[i] = temp;
    }
}

int main()
{
#pragma region 의사 난수
    // 0 ~ 32767 사이의 난수 값을 반환하는 함수입니다.

    // UTC 기준으로 1970년 1월 1일 0시 0분 0초부터 경과된
    // 시간을 초(sec)로 반환하는 함수입니다.

    // srand : rand()가 사용할 초기값(seed)을 설정하는 함수

   // srand(time(NULL));
   // int random = rand()%10+1;
   // printf("random : %d\n", random);

#pragma endregion

#pragma region 셔플 함수

    // srand(time(NULL));
    // int list[] = { 1,2,3,4,5,6,7,8,9,10 };
    // int size = sizeof(list) / sizeof(list[0]);
    // shuffle(list, size);
    // 
    // for (int i = 0;i < size;i++) {
    //     printf("list[%d]의 값 : %d\n", i, list[i]);
    // }

#pragma endregion

#pragma region UP - DOWN 게임

    // int answer, guess=0;
    // int life = 5;
    // int min = 1, max = 50;

//     // srand(time(NULL));
    // answer = rand() % 50 + 1;
    // printf("게임 시작!\n숫자 범위는 1~50입니다.\n목숨은 5개♥\n\n");

// 
//     // while (life>0) {
    //     printf("숫자 입력 (%d~%d) = ", min,max);
    //     scanf_s("%d", &guess);

//     //     if (guess < 1 || guess > 50)
    //     {
    //         printf("잘못 입력했습니다. 1~50 사이의 숫자를 입력하세요.\n");
    //         printf("▶Life : %d\n\n", life);
    //         continue;
    //     }

//     //     if (guess < answer) {
    //         life--;
    //         min = guess + 1;
    //         printf("UP↑ ▶Life : %d\n\n", life);
    //     }
    //     else if (guess > answer) {
    //         life--;
    //         max = guess - 1;
    //         printf("DOWN↓ ▶Life : %d\n\n", life);
    //     }
    //     else if (guess == answer) {
    //         printf("☆Victory★\n");
    //         break;
    //     }
    // }
    // printf("Defeat..\n");

#pragma endregion

    return 0;
}