//*********************************************
//循环单链表
typedef struct LNode                //定义单链表结点类型
{
    ElemType data;                  //每个结点存放一个数据元素
    struct LNode *next;             //指针指向下一个结点
}LNode, *LinkList;

//初始化一个循环单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));//分配一个头结点
    if(L==NULL)                     //内存不足，分配失败
        return false;
    L->next = L;                    //头结点的next指向头结点
    return true;
}

//判断循环单链表是否为空
bool Empty(LinkList L)
{
    if(L->next==L)
        return true;
    else
        return false;
}

//判断结点p是否为循环单链表的表尾结点
bool IsTail(LinkList L, LNode *p)
{
    if(p->next==L)
        return true;
    else
        return false;
}



//****************************************************
//循环双链表
typedef struct DNode                //定义双链表结点类型
{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

//初始化空的循环双链表
bool InitList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));//分配一个头结点
    if(L==NULL)                     //内存不足，分配失败
        return false;
    L->prior = L;                   //头结点的prior指向头结点
    L->next = L;                    //头结点的next指向头结点
    return true;
}

//判断循环双链表是否为空
bool Empty(DLinkList L)
{
    if(L->next==L)
        return true;
    else
        return false;
}

//判断结点p是否为循环双链表的表尾结点
bool IsTail(DLinkList L, DNode *p)
{
    if(p->next==L)
        return true;
    else
        return false;
}



//***********************************************
//静态链表的定义（一）
#define MaxSize 10                  //静态链表的最大长度
typedef struct                      //静态链表数据结构的定义
{
    ElemType data;                  //存储数据元素
    int next;                       //下一个元素的数组下标
}SLinkList[MaxSize];

//静态链表的定义（二）
#define MaxSize 10                  //静态链表的最大长度
struct Node                         //静态链表数据结构的定义
{
    ElemType data;                  //存储数据元素
    int next;                       //下一个元素的数组下标
};
typedef struct Node SLinkList[MaxSize];

