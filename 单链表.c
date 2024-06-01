//*******************************************//
//单链表的定义和创建//
typedef struct LNode{               //定义单链表结点类型
    ElemType data;                  //每个结点存放一个数据元素
    struct LNode *next;             //指针指向下一个节点
}LNode, *LinkList;                  //LNode用于强调这是节点，*LinkList用于强调这是链表

//不带头结点的单链表
//初始化一个空的链表（不带头节点）
bool InitList(LinkList &L)
{
    L = NULL;                       //空表，暂时还没有数据
    return true;
}

//判断单链表是否为空（不带头节点）
bool Empty(LinkList L)
{
    return (L == NULL);
}

void test()
{
    LinkList L;                     //声名一个指向单链表的指针
    //初始化一个空表
    InitList(L);
    //......后续代码......
}

//&&&&&&&&//

//带头结点的单链表
//初始化一个空的链表（带头节点）
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));//分配一个头节点
    if(L == NULL)                   //内存不足，分配失败
        return false;
    L->next = NULL;                 //头节点之后暂时还没有节点
    return true;
}

//判断单链表是否为空（带头节点）
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

void test()
{
    LinkList L;                     //声名一个指向单链表的指针
    //初始化一个空表
    InitList(L);
    //......后续代码......
}




//*******************************************//
//单链表的插入操作（关键是找到要插入为序i的前一个位置i-1）
typedef struct LNode{               //定义单链表结点类型
    ElemType data;                  //每个结点存放一个数据元素
    struct LNode *next;             //指针指向下一个节点
}LNode, *LinkList;                  //LNode用于强调这是节点，*LinkList用于强调这是链表

//按位序插入（带头结点）
//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1)
        return false;
    LNode *p;                       //指针p指向当前扫描到的节点
    p = L;                          //L指向头节点，头节点是第0个节点（不含数据）
    int j = 0;                      //当前p指向的是第几个节点
    while(p!=NULL && j<i-1)         //循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    if(p=NULL)                      //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;              
    p->next = s;                    //将节点s连到p之后
    return true;                    //插入成功
}

//按位序插入（不带头结点）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1)
        return false;
    if(i==1)
    {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data =  e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;                       //指针p指向当前扫描到的节点
    p = L;                          //p指向第一个节点而不是头节点
    int j = 1;                      //当前p指向的是第几个节点
    while(p!=NULL && j<i-1)         //循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    if(p=NULL)                      //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;              
    p->next = s;                    //将节点s连到p之后
    return true;                    //插入成功
}

//指定节点的后插操作（带头结点）
//后插操作：在p节点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e)
{
    if(p==NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL)                     //内存分配失败
        return false;
    s->data = e;                    //用节点s保存元素e
    s->next = p->next;
    p->next = s;                    //将节点s连到p之后
    return true;
}

//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1)
        return false;
    LNode *p;                       //指针p指向当前扫描到的节点
    p = L;                          //L指向头节点，头节点是第0个节点（不含数据）
    int j = 0;                      //当前p指向的是第几个节点
    while(p!=NULL && j<i-1)         //循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

//指定节点的前插操作（带头结点）
//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p, ElemType e)
{
    if(p=NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL)                     //内存分配失败
        return false;
    s->next = p->next;
    p->next = s;                    //新结点s连到p之后
    s->data = p->data;              //将p中元素复制到s中
    p->data = e;                    //p中元素覆盖为e
    return true;
}

//前插操作：在p结点之前插入s结点
bool InsertPriorNode(LNode *p, LNode *s)
{
    if(p=NULL || s=NULL)
        return false;
    s->next = p->next;
    p->next =  s;
    ElemType temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}




//*******************************************//
//单链表的删除操作（带头结点）
typedef struct LNode{               //定义单链表结点类型
    ElemType data;                  //每个结点存放一个数据元素
    struct LNode *next;             //指针指向下一个节点
}LNode, *LinkList;                  //LNode用于强调这是节点，*LinkList用于强调这是链表

//按位序删除（带头结点）
bool ListDelete(LinkList &L, int i, ElemType e)//关键是找到要删除位序的前一个位置
{
    if(i<1)
        return false;
    LNode *p;                       //指针p指向当前扫描到的节点
    p = L;                          //L指向头节点，头节点是第0个节点（不含数据）
    int j = 0;                      //当前p指向的是第几个节点
    while(p!=NULL && j<i-1)         //循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    if(p=NULL)                      //i值不合法
        return false;
    if(p->next==NULL)               //第i-1个结点之后已经、无其他结点
        return false;
    LNode *q = p->next;             //令q指向被删除结点
    e = q->data;                    //用e返回元素的值
    p->next = q->next;              //将*q结点从链中“断开”
    free(q);
    return 0;                       //删除成功
}

//指定结点的删除
bool DeleteNode(LNode *p)
{
    if(p=NULL)
        return false;
    LNode *q = p->next;             //令q指向被删除结点
    p->data = p->next->data;        //和后继结点交换数据域
    p->next = q->next;              //将*q结点从链中“断开”
    free(p)                         //释放后继结点的存储空间
    return true;
}




//*******************************************//
//单链表的查找（带头结点）
//按位查找，返回第i个元素
LNode *GetElem(LinkList L, int i)
{
    if(i<0)
        return false;
    LNode *p;                       //指针p指向当前扫描到的节点
    p = L;                          //L指向头节点，头节点是第0个节点（不含数据）
    int j = 0;                      //当前p指向的是第几个节点
    while(p!=NULL && j<i)           //循环找到第i个结点
    {
        p = p->next;
        j++
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    //从第一个结点开始查找数据域为e的结点
    while(p!=NULL && p->data!=e)
        p = p->next;
    return p;                       //找到后返回该结点指针。否则返回NULL
}

//求表的长度
int Length(LinkList L)
{
    int len = 0;                    //统计表长
    LNode *p = L;
    while (p->next!=NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}