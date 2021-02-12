#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int left = 0;
    int right = -1;
    int res = numsSize + 1;
    int sum = 0;
    while (left < numsSize)
    {
        if (sum < target && right + 1 < numsSize)
        {
            right++;
            sum += nums[right];
        }
        else
        {
            sum -= nums[left];
            left++;
        }
        if (sum >= target)
            res = fmin(res, right - left + 1);
    }
    if (res > numsSize)
        return 0;
    return res;
}
int main()
{
    int numsize, target;
    scanf("%d%d", &numsize, &target);
    int *nums = (int *)malloc(sizeof(int) * (numsize));
    for (int i = 0; i < numsize; i++)
        scanf("%d", &nums[i]);
    printf("%d", minSubArrayLen(target, nums, numsize));
    return 0;
}