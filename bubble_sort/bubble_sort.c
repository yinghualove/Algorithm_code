// 冒泡排序算法
// 输入n个数字，按从小到大或从大到小的顺序排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_NUM 100

//功能:将数字从小到大排序或从大到小排序
//parameters:
//num:输入的数字，sort_order:排序顺序，0表示从大到小，1表示从小到大，count:数组大小
//return: int *
int *bubble_sort(int *num, int sort_order, int count)
{ 

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i; j++)
        {
            int tmp;
            // 从大到小排序
            if (sort_order == 0)
            {
                if (num[j] < num[j + 1])
                {
                    tmp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = tmp;
                }
                else if (num[j] >= num[j + 1])
                {
                    continue;
                }
            }
            //从小到大排序
            else if (sort_order == 1)
            {
                if (num[j] > num[j + 1])
                {
                    tmp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = tmp;
                }
                else if (num[j] <= num[j + 1])
                {
                    continue;
                }
            }
        }
    }
    printf("num sort: ");
    for (int i = 0; i < count; i++)
        printf("%d ", num[i]);
    printf("\n");

    return num;

}

int main(int argc, char **argv)
{
    int *num;
    int count = 1;
    int sort_order = 0;
    num = (int *)malloc(MAX_NUM);
    memset(num, 0, sizeof(num));

    // 输入数字
    printf("input num:\n");
    while (scanf("%d", &num[count - 1]) && getchar() != '\n')    //当输入回车时，结束跳出循环
    {
        ++count;
    }

    // 输入排序的顺序，0为从大到小，1为从小到大
    printf("input sort order:\n");
    scanf("%d", &sort_order);

    bubble_sort(num, sort_order, count);

    printf("ret num sort: ");
    for (int i = 0; i < count; i++)
        printf("%d ", num[i]);
    printf("\n");

    free(num);

    return 0;
}
