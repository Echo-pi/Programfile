#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));
    result[2] = {-1, -1};
    int left = 0, right = numsSize - 1;
    int l = left, r = right;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
            right = mid;
    }
    if (left > right || nums[left] != target)
    {
        return result;
    }
    while (l < r)
    {
        int mid = (r + l) / 2 + 1;
        if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else
            l = mid;
    }
    if (left > right || left > r)
        return result;
    else
    {
        result[0] = left;
        result[1] = r;
        *returnSize = 2;
        return result;
    }
}
/*
首先定义两个指针变量，分别存储左右两个位置的索引。
首先去找目标值的最左面的索引,通过循环为了防止元素丢失,
每次保留最右面的元素,左侧的指针移动时+1。
在循环结束的时候判断一下数组中是否包括目标值,不包括的话直接退出。 
右面的跟左侧相同，只不过正好相反。
*/