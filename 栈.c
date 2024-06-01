//栈的基本操作：
/* InitStack(&S):初始化栈。构造一个空栈S，分配内存空间
   DestroyStack(&S):销毁栈。销毁并释放栈S所占用的内存空间
   Push(&S, x):进栈，若栈S未满，则将x加入使之成为新栈顶
   Pop(&S, &x):出栈，若栈S非空，则弹出栈顶元素，并用x返回
   GetTop(S, &x):读栈顶元素。若栈S非空，则用x返回栈顶元素
   StackEmpty(S):判断一个栈S是否为空。若S为空，则返回true，否则返回false
*/

//************************************************************************
//顺序栈

//顺序栈的定义
#define MaxSize 10                          //定义栈中元素的最大个数
typedef struct 
{
    ElemType data[MaxSize];                 //静态数组存放元素
    int top;                                //栈顶指针
}SqStack;

//****************
//栈顶指针指向当前元素存的地方
//初始化操作
void InitStack(SqStack &S)
{
    S.top = -1;                             //初始化栈顶指针
}

//进栈操作
bool Push(SqStack &S, x)
{
    if(S.top == MaxSize-1)                  //栈满，报错
        return false;
    S.top = S.top + 1;                      //指针先加一
    S.data[S.top] = x;                      //新元素进栈
    //以上两步等价于 S.data[++S.top] = x;
    return true;
}

//出栈操作
bool Pop(SqStack &S, &x)
{
    if(S.top == -1)                         //栈空，报错
        return false;
    x = S.data[S.top];                      //栈顶元素先出栈
    S.top = S.top - 1;                      //指针再减一
    //以上两步等价于 x = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, &x)
{
    if(S.top == -1)                         //栈空，报错
        return false;
    x = S.data[S.top];                      //x记录栈顶元素
    return true;
}

//判断栈空
bool StackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

//****************
//栈顶指针指向下一个元素要存的地方
//初始化操作
void InitStack(SqStack &S)
{
    S.top = 0;                             //初始化栈顶指针
}

//进栈操作
bool Push(SqStack &S, x)
{
    if(S.top == MaxSize-1)                  //栈满，报错
        return false;
    S.data[S.top] = x;                      //新元素先进栈
    S.top = S.top + 1;                      //指针再加一
    //以上两步等价于 S.data[S.top++] = x;
    return true;
}

//出栈操作
bool Pop(SqStack &S, &x)
{
    if(S.top == -1)                         //栈空，报错
        return false;
    S.top = S.top - 1;                      //指针先减一    
    x = S.data[S.top];                      //栈顶元素后出栈
    //以上两步等价于 x = S.data[--S.top];
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, &x)
{
    if(S.top == 0)                         //栈空，报错
        return false;
    x = S.data[S.top];                      //x记录栈顶元素
    return true;
}

//判断栈空
bool StackEmpty(SqStack S)
{
    if(S.top == 0)
        return true;
    else
        return false;
}

//共享栈
#define MaxSize 10                          //定义栈中元素的最大个数
typedef struct 
{
    ElemType data[MaxSize];                 //静态数组存放元素
    int top0;                               //0号栈栈顶指针
    int top1;                               //1号栈栈顶指针
}ShStack;

//初始化栈
void InitStack(ShStack &S)
{
    S.top0 = -1;                            //初始化栈顶指针
    S.top1 = MaxSize;
}

//栈满条件： top0 + 1 == top1;



//************************************************************************
//链栈
//链栈的定义
typedef struct Linknode
{
    ElemType data;                          //数据域
    struct Linknode *next;                  //指针域
} *LiStack;                                 //栈类型定义

//进栈 对应于 头插法建立单链表
//出栈 对应于 单链表的删除操作
