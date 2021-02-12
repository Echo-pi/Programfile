#include <stdio.h>
#include <math.h>
int maxTurbulenceSize(int *arr, int arrSize)
{
    int left = 0;
    int right = 0;
    int res = 1;
    while (right < arrSize - 1)
    {
        if (left == right)
        {
            if (arr[left] == arr[left + 1])
            { //跳过相同的
                left++;
            }
            right++; //不同则移动右进行判断
        }
        else
        {
            if (arr[right] > arr[right - 1] && arr[right] > arr[right + 1]) //要么比两边都大
                right++;
            else if (arr[right] < arr[right - 1] && arr[right] < arr[right + 1]) //要么比两边都小
                right++;
            else
                left = right; //不满足移动两指针到同一位置
        }
        res = fmax(res, right - left + 1); //储存最大值
    }
    return res;
}
int main()
{
    int arrSize = 0;
    scanf("%d", &arrSize);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);
    printf("%d", maxTurbulenceSize(arr, arrSize));
    return 0;
}
//leetcode 978题最长涡流子数组，双指针解法