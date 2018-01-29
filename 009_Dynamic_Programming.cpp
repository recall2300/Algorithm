/*
동적 계획법(Dynamic programming)은 복잡한 문제를 풀기위해서 간단한 여러 개의 하위 문제로 나누어 푼 다음, 그것을 결합하여 목적에 도달하는 방법이다

[문제]  
상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 
스티커는 그림 (a)와 같이  2행 n열로 배치되어 있다. 
상냥이는 스티커를 이용해 책상을 꾸미려고 한다. 
상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 
스티커 한 장을 떼면, 그 스티커와 변을  공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다.
즉, 뗀 스티커의 왼쪽, 오른쪽, 위,  아래에 있는 스티커는 사용할 수 없게 된다.

Input
2 
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80

Output
#1 260
#2 290

*/


#include<stdio.h>

int N;
int dp[2][100001];
int board[2][100001];

const int max(const int a, const int b) 
{
    return (a<b) ? b : a;
}

void findSticker() 
{
    dp[0][0] = board[0][0];
    dp[1][0] = board[1][0];
    dp[0][1] = dp[1][0] + board[0][1];
    dp[1][1] = dp[0][0] + board[1][1];

    for (int i = 2; i < N; i++) 
    {
        dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]);
        dp[0][i] = max(dp[1][i - 1], dp[0][i]);
        dp[0][i] += board[0][i];

        dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]);
        dp[1][i] = max(dp[0][i - 1], dp[1][i]);
        dp[1][i] += board[1][i];
    }
}

int main() 
{
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) 
    {
        printf("#%d ", test_case);
        scanf("%d", &N);
        for (int j = 0; j < 2; j++) 
        {
            for (int i = 0; i < N; i++) 
            {
                scanf("%d", &board[j][i]);
            }
        }
        findSticker();
        printf("%d\n", max(dp[0][N - 1], dp[1][N - 1]));
    }

    return 0;
}
