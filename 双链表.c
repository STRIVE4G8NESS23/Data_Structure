//****************************************************//
//双链表中结点类型的描述
typedef struct DNode
{
    ElemType data;                      //数据域
    struct DNode *next, *prior;         //前驱和后继指针
}DNode, *DLinkList;

//双链表的插入
//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if(p==NULL || s==NULL)              //非法参数
        return false;
    s->next = p->next;                  //第一步
    if(p->next!=NULL)                   //如果p结点有后续结点
        p->next->prior = s;             //第二步
    s->prior = p;                       //第三步
    p->next = s;                        //第四步
    return true;
}


//****************************************************//
//双链表的删除
//删除p结点的后继结点
bool DeleteNextDNode(DNode *p)
{
    if(p==NULL)
        return false;
    DNode *q = p->next;                 //找到p的后继结点q
    if(q==NULL)
        return false;                   //p没有后继结点
    p->next = q->next;
    if(q->next!=NULL)                   //q结点不是最后一个结点
        q->next->prior = p;
    free(q);                            //释放结点空间
}




//****************************************************//
//双链表的遍历

//后向遍历
while(p!=NULL)
{
    //对结点p做相应处理，如打印
    p = p->next;
}

//前向遍历
while(p!=NULL)
{
    //对结点p做相应处理
    p = p->prior;
}

//前向遍历（跳过头结点）
while(p->prior!=NULL)
{
    //对结点p做相应处理
    p = p->prior;
}