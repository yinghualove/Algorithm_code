// 冒泡排序算法
// 输入n个数字，按从小到大或从大到小的顺序排序
/***********************************************************************************
算法实现步骤：
1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
3.针对所有的元素重复以上的步骤，除了最后一个。
4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较.
算法时间复杂度：
最好的时间复杂度:o(n)
平均时间复杂度:o(n^2)
优化版本：
对冒泡排序常见的改进方法是加入标志性变量exchanged，用于标志某一趟排序过程中是否有数据交换。
如果进行某一趟排序时并没有进行数据交换，则说明所有数据已经有序，可立即结束排序，避免不必要的比较过程。
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bubble_sort.h"

#define MAX_NUM 100

//function name:bubble_sort
// 功能:将数字从小到大排序或从大到小排序
//如何调用:bubble_sort(num,sort_order,count)
// parameters:
// num:输入的数字，sort_order:排序顺序，0表示从大到小，1表示从小到大，count:数组大小
// return: int *
int *bubble_sort(int *num, int sort_order, int count)
{
    bool exchanged = false;

    for (int i = 0; i < count - 1; i++)
    {  
        for (int j = 0; j < count - 1 - i; j++)
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
            }
            // 从小到大排序
            else if (sort_order == 1)
            {
                if (num[j] > num[j + 1])
                {
                    tmp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = tmp; 
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

//function name:bubble_sort_improve_v1
// 功能:将数字从小到大排序或从大到小排序
//如何调用:bubble_sort_improve_v1(num,sort_order,count)
// parameters:
// num:输入的数字，sort_order:排序顺序，0表示从大到小，1表示从小到大，count:数组大小
// return: int *
int *bubble_sort_improve_v1(int *num, int sort_order, int count)
{
    bool exchanged = false;

    for (int i = 0; i < count - 1; i++)
    {
        exchanged = false;
        for (int j = 0; j < count - 1 - i; j++)
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
                    exchanged = true;
                }
            }
            // 从小到大排序
            else if (sort_order == 1)
            {
                if (num[j] > num[j + 1])
                {
                    tmp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = tmp;
                    exchanged = true;
                }
            }
        }
        if (!exchanged)
        {
            break;
        }
    }

    // printf("num sort: ");
    // for (int i = 0; i < count; i++)
    //     printf("%d ", num[i]);
    // printf("\n");

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
    while (scanf("%d", &num[count - 1]) && getchar() != '\n') // 当输入回车时，结束跳出循环
    {
        ++count;
    }

    // 输入排序的顺序，0为从大到小，1为从小到大
    printf("input sort order:\n");
    scanf("%d", &sort_order);

    int mode = 1;
    printf("please input your mode:\
        mode eg: 0 is origin and 1 is improve\n");
    scanf("%d",&mode);
    
    if(mode == 0)
        bubble_sort(num, sort_order, count);
    else
        bubble_sort_improve_v1(num,sort_order,count);

    printf("num sort: ");
    for (int i = 0; i < count; i++)
        printf("%d ", num[i]);
    printf("\n");

    free(num);

    return 0;
}
