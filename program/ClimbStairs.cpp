#include <stdio.h>
int climbStairs(int n)
{
    if (n <= 2)
        return n;
    int first = 1;
    int second = 2;
    int step = 0;
    for (int i = 3; i < n + 1; i++)
    {
        step = first + second;
        first = second;
        second = step;
    }
    return step;
}
/*
int climbStairs(int n){
    if(n==1)
        return 1;
    int *res=(int *)malloc((n+1)*sizeof(int));
    res[1]=1;
    res[2]=2;
    for(int i=3;i<n+1;i++){
        res[i]=res[i-1]+res[i-2];
    }
    return res[n];
}
*/
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", climbStairs(n));
    return 0;
}
//动态规划，也可以直接写出递推公式求解