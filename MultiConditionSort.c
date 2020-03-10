/*
 *多条件排序
 *1.按学生成绩 由小到达
 *2.成绩相同 则按学生姓名（ASCII码）排序
 *3.最后，按年龄排序 由小到大
 *使用sort(begin,end,compare)函数
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct student{
    char name[101];
    int age;
    int grade;
}stu;

//比较函数，按条件依次进行比较
int cmp(stu a,stu b){
    if(a.grade!=b.grade){
        return a.grade<b.grade;
    }else if(strcmp(a.name,b.name)!=0){
        return strcmp(a.name,b.name)<0;
    }else{
        return a.age<b.age;
    }
}

int main(void)
{
    int n;
    stu stus[1001];
    while(scanf("%d",&n)==1){
        //录取数据
        for(int i = 0;i<n;i++){
            scanf("%s %d %d",stus[i].name,&stus[i].age,&stus[i].grade);
        }
        //排序
       sort(stus,stus+n,cmp);
        
        //输出
        for(int i = 0;i<n;i++){
            printf("%s %d %d\n",stus[i].name,stus[i].age,stus[i].grade);
        }
    }
    return 0;
}
