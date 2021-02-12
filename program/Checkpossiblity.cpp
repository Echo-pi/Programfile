#include <stdio.h>
#include <stdlib.h>
bool checkpossility(int *nums, int numSize)
{
    int left = 0;
    int right = numSize - 1;
    while (left < numSize - 1)
    {
        if (nums[left] <= nums[left + 1])
        {
            left++;
        }
        else
            break;
    }
    if (left == numSize - 1)
        return true;
    while (right > 0)
    {
        if (nums[right] >= nums[right - 1])
        {
            right--;
        }
        else
            break;
    }
    if (right - left + 1 > 2)
        return false;
    if (left == 0 || right == numSize - 1)
        return true;
    if (nums[left - 1] <= nums[right] || nums[right + 1] >= nums[left])
        return true;
    return false;
}
int main()
{
    int numsize;
    scanf("%d", &numsize);
    int *nums = (int *)malloc(numsize * sizeof(int));
    for (int i = 0; i < numsize; i++)
        scanf("%d", &nums[i]);
    bool flag = checkpossility(nums, numsize);
    if (flag == true)
        printf("true");
    else
        printf("false");
    return 0;
}