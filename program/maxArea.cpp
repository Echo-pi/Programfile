#include <stdio.h>
#include <math.h>
int maxArea(int *height, int heightSize)
{
    int resource = 0;
    int last = heightSize - 1;
    int res = 0;
    while (resource < last)
    {
        if (height[resource] >= height[last])
        {
            res = fmax(res, height[last] * (last - resource));
            last--;
        }
        else
        {
            res = fmax(res, height[resource] * (last - resource));
            resource++;
        }
    }
    return res;
}
int main()
{
    int height_size = 0;
    scanf("%d", &height_size);
    int *height = (int *)malloc(height_size * sizeof(int));
    for (int i = 0; i < height_size; i++)
    {
        scanf("%d", &height[i]);
    }
    printf("%d", maxArea(height, height_size));
    return 0;
}
/*
思路：使用两个指针（resource和last）分别指向数组的第一个元素和最后一个元素，
然后我们计算这两条“线”之间能容纳的水的容量，并更新最大容量（初始值为0）；
接着我们需要将指向元素值小的那个指针前移一步，然后重复上面的步骤，
直到resource = last循环截止。
*/
