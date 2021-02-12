#include <stdio.h>
#include <math.h>
int trap(int *height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int leftmax = 0;
    int rightmax = 0;
    int res = 0;
    while (left <= right)
    {
        leftmax = fmax(leftmax, height[left]);
        rightmax = fmax(rightmax, height[right]);
        if (leftmax < rightmax)
        {
            res += leftmax - height[left];
            left++;
        }
        else
        {
            res += rightmax - height[right];
            right--;
        }
    }
    return res;
}
int main()
{
    int heightSize = 0;
    scanf("%d", &heightSize);
    int *height = (int *)malloc(heightSize * sizeof(int));
    for (int i = 0; i < heightSize; i++)
        scanf("%d", &height[i]);
    printf("%d", trap(height, heightSize));
    return 0;
}