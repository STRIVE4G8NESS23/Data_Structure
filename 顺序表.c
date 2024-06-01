
//**********************************************************//
//顺序表的实现--静态分配
#include<stdio.h>
#define MaxSize 10              //定义最大长度
typedef struct{
    ElemType data[MaxSize];     //用静态的“数组”存放数据元素
    int length;                 //顺序表的当前长度  
}SqList;                        //顺序表的类型定义（静态分配方式）

//基本操作--初始化一个顺序表
void InitList(Sqlist &L)
{
    for(int i=0; i<MaxSize; i++)
    {
        L.data[i] = 0;          //将所有数据元素设置为默认初始值
    }
    L.length = 0;               //顺序表初始长度为0
}

int main()
{
    SqList L;                   //声名一个顺序表
    InitList(L);                //初始化一个顺序表
    //...未完待续，后续操作
    return 0;
}




//**********************************************************//
//顺序表的实现--动态分配
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10             //默认的最大的长度
typedef struct{
    int *data;                  //指示动态分配数组的指针
    int MaxSize;                //顺序表的最大容量
    int length;                 //顺序表的当前长度
}SeqList;

void InitList(SeqList &L)
{
    //用malloc函数申请一片连续的内存空间
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;            //建立一个指针指向原数组基址
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0; i<L.length; i++){
        L.data[i] = p[i];       //将原来的数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;//顺序表最大长度增加len
    free(p);                    //释放原来的内存空间
}

int main()
{
    SeqList L;                  //声明一个顺序表
    InitList(L);                //初始化一个顺序表
    //...往顺序表中插入元素...
    IncreaseSize(L, 5);
    return 0;
}




//**********************************************************//
#define MaxSize 10              //定义最大长度
typedef struct{
    ElemType data[MaxSize];     //用静态的“数组”存放数据元素
    int length;                 //顺序表的当前长度  
}SqList;                        //顺序表的类型定义

//顺序表的基本操作--插入
bool ListInsert(SqList &L, int i, int e)
{
    if(i<1 || i>L.length+1)     //判断i的范围是否有效
        return false;
    if(L.length >= MaxSize)     //当前存储已满，不能插入
        return false;
    for(int j=L.length;j>=i;j--)//将第i个元素及之后的元素后移
        L.data[j] = L.data[j-1];
    L.data[i] = e;              //在位置i处放入i
    L.length++;                 //长度加1
    return true;
}

//顺序表的基本操作--删除
bool ListDelete(SqList &L, int i, int &e)//注意这里引用参数e
{
    if(i<1 || i>L.length+1)     //判断i的范围是否有效
        return false;
    e = L.data[i-1];            //将被删除的值赋值给e
    for(int j=i;j<L.length;j++) //将第i个位置后面的元素前移
        L.data[j-1] = L.data[j];
    L.length--;                 //线性表长度减1
    return true;
}

int main()
{
    SqList L;                   //声明一个顺序表
    InitList(L);                //初始化一个顺序表
    //...往顺序表中插入元素... 
    int e = -1;                 //用变量e把删除的元素“带回来”
    if(ListDelete(L, 3, e))
        printf("已删除第3个元素，删除的元素值为%d\n", e);
    else
        printf("位序i不合法，删除失败\n");
    return 0;
}



//**********************************************************//
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10             //默认的最大的长度
typedef struct{
    ElemType *data;                  //指示动态分配数组的指针
    int MaxSize;                //顺序表的最大容量
    int length;                 //顺序表的当前长度
}SeqList;

//顺序表的按位查找
ElemType GetElem(SeqList L, int i)//和访问普通数组一样
{
    return L.data[i-1];
}

//顺序表的按值查找
int LocateElem(SeqList L, ElemType e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}