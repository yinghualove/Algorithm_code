// 使用冒泡排序按从大到小的顺序输出学生成绩分数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 静态的结构体
struct Static_Student
{
    char name[20];
    int score;
};

typedef struct Dynamic_Student
{
    char *name;
    int score;
} mystudent, *Student;

void static_student()
{
    int n;
    struct Static_Student student[100], tmp;
    printf("input n:\n");
    scanf("%d", &n);
    printf("input student name and score:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", student[i].name, &student[i].score);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (student[j].score < student[j + 1].score)
            {
                tmp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("name: %s, score: %d\n", student[i].name, student[i].score);
}

void dynamic_student()
{
    int n;
    printf("input n:\n");
    scanf("%d", &n);
    Student student; 
    student = (Student)malloc((n + 1) * sizeof(mystudent));
    memset(student, 0, (n+1) * sizeof(mystudent));
    for (int i = 0; i < n; i++)
    {
        student[i].name = (char *)malloc(20 * sizeof(char)); // 分配名字的内存空间
    }

    printf("input student name and score:\n");
    for (int i = 0; i < n; i++)
    {
        //first way a
        // char name[5][10] = {"li", "you", "yue", "yuan", "ming"};
        // int score[5] = {10, 20, 15, 35, 30};
        // strcpy(student[i].name, name[i]);
        // student[i].score = score[i];
        //second way
        scanf("%s %d",student[i].name,&student[i].score);
    }
    //for DEBUG
    // for (int i = 0; i < n; i++)
    // {
    //     printf("name: %s,score: %d\n", student[i].name, student[i].score);
    // }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (student[j].score < student[j + 1].score)
            {
                student[n] = student[j];
                student[j] = student[j + 1];
                student[j + 1] = student[n];
            }
        }
    }
    printf("output from big to small:\n");
    for (int i = 0; i < n; i++)
    {
        printf("name: %s, score: %d\n", student[i].name, student[i].score);
    }

    for (int i = 0; i < n; i++)
    {
        free(student[i].name);
    }
    free(student);
}

int main(int argc, char **argv)
{
    // static_student();
    dynamic_student();

    return 0;
}