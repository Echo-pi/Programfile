#include <stdio.h>
#include <math.h>
int jump(int *nums, int numSize)
{
    int step = 0;
    int maxstep = 0;
    int end = 0;
    for (int i = 0; i < numSize - 1; i++)
    {
        maxstep = fmax(maxstep, i + nums[i]);
        if (i == end)
        {
            end = maxstep;
            step++;
        }
    }
    return step;
}
int main()
{
    int numSize = 0;
    scanf("%d", &numSize);
    int *nums = (int *)malloc(numSize * sizeof(int));
    for (int i = 0; i < numSize; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("%d", jump(nums, numSize));
    return 0;
}

/*
方法二：正向查找可到达的最大位置
如果我们「贪心」地进行正向查找，每次找到可到达的最远位置，
就可以在线性时间内得到最少的跳跃次数。
例如，对于数组 [2,3,1,2,4,2,3]，初始位置是下标 0，从下标 0 出发，
最远可到达下标 2。下标 0 可到达的位置中，下标 1 的值是 3，
从下标 1 出发可以达到更远的位置，因此第一步到达下标 1。
从下标 1 出发，最远可到达下标 4。下标 1 可到达的位置中，
下标 4 的值是 4 ，从下标 4 出发可以达到更远的位置，因此第二步到达下标 4。

在具体的实现中，我们维护当前能够到达的最大下标位置，
记为边界。我们从左到右遍历数组，到达边界时，更新边界并将跳跃次数增加 1。
在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，
我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。
如果访问最后一个元素，在边界正好为最后一个位置的情况下，
我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。

详情见：https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
*/