#include <stdio.h>
#include <string.h>
bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    if (strlen(s) == 0 && strlen(t) == 0)
        return true;
    int table[26];
    memset(table, 0, sizeof(table));
    for (int i = 0; i < strlen(s); i++)
    {
        table[s[i] - 'a']++;
    }
    for (int j = 0; j < strlen(t); j++)
    {
        table[t[j] - 'a']--;
        if (table[t[j] - 'a'] < 0)
            return false;
    }
    return true;
}
int main()
{
    char s[256], t[256];
    scanf("%s%s", s, t);
    bool flag = isAnagram(s, t);
    if (flag == true)
        printf("true");
    else
        printf("false");
    return 0;
}
//leetcode第242题，有效的字母异位词，采用hash表，降低时间复杂度