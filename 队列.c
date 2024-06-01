//队列的基本操作
/*  InitQueue(&Q):初始化队列，构造一个空队列Q
    DestroyQueue(&Q):销毁队列。销毁并释放队列Q占用的空间
    EnQueue(&Q, x):入队，若队列Q未满，将x加入，使之成为新的队尾
    DeQueue(&Q, &x):出队，若队列Q非空，删除队头元素，并用x返回
    GetHead(Q, &x):读队头元素，若队列Q非空，则将队头元素赋值给x
    QueueEmpty(Q):判断队空，若队列Q为空返回true，否则返回false
*/

//***********************************************************
//队列的顺序实现
#define MaxSize 10                          //定义队列中元素的最大个数
typedef struct 
{
    ElemType data[MaxSize];                 //用静态数组存放队列元素
    int front, rear;                        //队头指针和队尾指针
}SqQueue;

//初始化操作
void InitQueue(SqQueue &Q)
{
    //初始时，队头和队尾指针都指向0
    Q.front = Q.rear = 0;
}

//循环队列--入队操作
bool EnQueue(SqQueue &Q, ElemType x)
{
    if((Q.rear+1)%MaxSize == Q.front)
        return false;                       //队满则报错
    Q.data[Q.rear] = x;                     //新元素插入队尾
    Q.rear = (Q.rear+1)%MaxSize;            //队尾指针加一取模
    return true;
}

//循环队列--出队操作
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if(Q.rear == Q.front)                   //队空则报错
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;          //队头指针后移
    return true;
}

//获得头元素的值
bool GetTop(SqQueue Q, ElemType &x)
{
    if(Q.front == Q.front)                  //队空则报错
        return false;
    x = Q.data[Q.front];
    return true;
}




//***********************************************************
//队列的链式实现
typedef struct LinkNode                     //链式队列的结点
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{                             //链式队列
    LinkNode *front, *rear;                 //队列的队头和队尾指针
}LinkQueue;

//初始化（带头结点）
void InitQueue(LinkQueue &Q)
{
    //初始时，front和rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front ->next = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

//入队（带头结点）
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;                       //新结点插入到rear之后
    Q.rear = s;                             //修改表尾指针
}

//出队（带头结点）
bool DeQueue(LinkQueue &Q, ElemType &x)
{
    if(IsEmpty(Q))
        return false;                       //空队
    LinkNode *p = Q.front->next;
    x = p->data;                            //用变量x返回队头元素
    Q.front->next = p->next;                //修改头结点的next指针
    if(Q.rear == p)                         //此次是最后一个结点出队
        Q.rear = Q.front;                   //修改rear指针
    free(p);                                //释放结点空间
    return true;
}



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//初始化（不带头结点）
void InitQueue(LinkQueue &Q)
{
    //初始时，front和rear都指向NULL
    Q.front = NULL;
    Q.rear = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
    if(Q.front == NULL)
        return true;
    else
        return false;
}

//入队（不带头结点）
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if(IsEmpty(Q))                          //在空队列中插入第一个元素
        Q.front = s;                        //修改队头队尾指针
        Q.rear = s;
    else
        Q.rear->next = s;                   //新结点插入到rear结点之后
        Q.rear = s;                         //修改rear指针
}

//出队（不带头结点）
void DeQueue(LinkQueue &Q, ElemType &X)
{
    if(IsEmpty(Q))
        return false;                       //队空
    LinkNode *p = Q.front;                  //p指向此次出队的结点
    x = p->data;                            //用变量x返回队头元素
    Q.front = p->next;                      //修改front指针
    if(Q.rear == p)                         //此次是最后一个结点出队
        Q.front = NULL;                     //front指向NULL
        Q.rear = NULL;                      //rear指向NULL
    free(p);                                //释放结点空间
    return true;
}