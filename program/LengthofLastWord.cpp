#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char *s)
{
    if (strlen(s) == 0)
        return 0;
    int res = 0;
    int last = strlen(s) - 1;
    for (int i = last; i >= 0; i--)
    {
        if (s[i] != ' ')
            res++;
        else if (res != 0)
            return res;
    }
    return res;
}
int main()
{
    char s[256];
    scanf("%s", s);
    printf("%d", lengthOfLastWord(s));
    return 0;
}
/*leetcode第58题，找最后一个单词的长度
*/