#include <stdio.h>
#include <string.h>
char *countAndSay(int n)
{
    int end = 0;
    int start = 0;
    char pre[256] = {0};
    char cur[256] = {0};
    cur[0] = '1';
    for (int i = 0; i < n; i++)
    {
        strcpy(pre, cur);
        //cur[256]={0};
        while (end < len(pre))
        {
            end++;
            pre[i + 1] = end - start - '0';
            pre[i + 2] = start - '0';
            strcat(cur, pre);
            start = end;
        }
    }
    return cur;
}
int main()
{
}