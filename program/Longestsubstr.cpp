#include <stdio.h>
#include <string.h>
#include <math.h>
int LengthofLongsetsubstring(char *string)
{
    int freq[256] = {0}; //滑动窗口string[l...r]
    int l = 0, r = -1;   //左边界右边界
    int res = 0;         //储存最大窗口宽度
    while (l < strlen(string))
    {
        if (r + 1 < strlen(string) && freq[string[r + 1]] == 0)
        {
            r++;
            freq[string[r]]++;
        }
        else
        { //r已经到头||freq[string[r+1]]!=0
            freq[string[l]]--;
            l++;
        }
        res = fmax(res, r - l + 1);
    }
    return res;
}
int main()
{
    char string[256];
    scanf("%s", string);
    printf("%d", LengthofLongsetsubstring(string));
    return 0;
}
/*
建立一个256位大小的整型数组 freg ，用来建立字符和其出现位置之间的映射。

维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。

（1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；
（2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
（3）重复（1）（2），直到左边索引无法再移动；
（4）维护一个结果res，每次用出现过的窗口大小来更新结果 res，最后返回 res 获取结果。
*/