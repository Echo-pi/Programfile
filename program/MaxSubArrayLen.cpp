#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int atMostKDistinct(int *A, int ASize, int K)
{
    int left = 0;
    int right = 0;
    int count = 0;
    int res = 0;
    int freq[ASize + 1] = {0};
    while (right < ASize)
    {
        if (freq[A[right]] == 0)
        {
            count++;
        }
        freq[A[right]]++;
        right++;
        while (count > K)
        {
            freq[A[left]]--;
            if (freq[A[left]] == 0)
                count--;
            left++;
        }
        res += right - left;
    }
    return res;
}
int subarraysWithKDistinct(int *A, int ASize, int K)
{
    return atMostKDistinct(A, ASize, K) - atMostKDistinct(A, ASize, K - 1);
}
int main()
{
    int Asize, k;
    scanf("%d%d", &Asize, &k);
    int *A = (int *)malloc(Asize * sizeof(int));
    for (int i = 0; i < Asize; i++)
        scanf("%d", &A[i]);
    printf("%d", subarraysWithKDistinct(A, Asize, k));
    return 0;
}
//leetcode第992题，用双指针解决
/*
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
返回 A 中好子数组的数目。

示例 1：
输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

示例 2：
输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
*/
 