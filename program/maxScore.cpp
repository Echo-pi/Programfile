#include <stdio.h>
#include <math.h>
int maxScore(int *cardPoints, int cardPointSize, int k)
{
    int windowsize = cardPointSize - k;
    int sum = 0;
    for (int i = 0; i < windowsize; i++)
    {
        sum += cardPoints[i];
    }
    int res = sum;
    int minSum = sum;
    for (int i = windowsize; i < cardPointSize; i++)
    {
        sum += cardPoints[i] - cardPoints[i - windowsize];
        minSum = fmin(minSum, sum);
        res += cardPoints[i];
    }
    return res - minSum;
}
//滑动窗口,leetcode 1423题，转化为求n-k个连续的最小值，用总和减去n-k个连续的最小值
//必然剩下的就是k个连续取出的最大值（此处连续指的是取牌顺序）
int main()
{
    int cardPointSize = 0;
    int k = 0;
    scanf("%d%d", &cardPointSize, &k);
    int *cardPoint = (int *)malloc(cardPointSize * sizeof(int));
    for (int i = 0; i < cardPointSize; i++)
        scanf("%d", &cardPoint[i]);
    printf("%d", maxScore(cardPoint, cardPointSize, k));
    return 0;
}