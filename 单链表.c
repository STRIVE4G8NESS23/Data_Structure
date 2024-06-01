//*******************************************//
//������Ķ���ʹ���//
typedef struct LNode{               //���嵥����������
    ElemType data;                  //ÿ�������һ������Ԫ��
    struct LNode *next;             //ָ��ָ����һ���ڵ�
}LNode, *LinkList;                  //LNode����ǿ�����ǽڵ㣬*LinkList����ǿ����������

//����ͷ���ĵ�����
//��ʼ��һ���յ���������ͷ�ڵ㣩
bool InitList(LinkList &L)
{
    L = NULL;                       //�ձ���ʱ��û������
    return true;
}

//�жϵ������Ƿ�Ϊ�գ�����ͷ�ڵ㣩
bool Empty(LinkList L)
{
    return (L == NULL);
}

void test()
{
    LinkList L;                     //����һ��ָ�������ָ��
    //��ʼ��һ���ձ�
    InitList(L);
    //......��������......
}

//&&&&&&&&//

//��ͷ���ĵ�����
//��ʼ��һ���յ�������ͷ�ڵ㣩
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));//����һ��ͷ�ڵ�
    if(L == NULL)                   //�ڴ治�㣬����ʧ��
        return false;
    L->next = NULL;                 //ͷ�ڵ�֮����ʱ��û�нڵ�
    return true;
}

//�жϵ������Ƿ�Ϊ�գ���ͷ�ڵ㣩
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

void test()
{
    LinkList L;                     //����һ��ָ�������ָ��
    //��ʼ��һ���ձ�
    InitList(L);
    //......��������......
}




//*******************************************//
//������Ĳ���������ؼ����ҵ�Ҫ����Ϊ��i��ǰһ��λ��i-1��
typedef struct LNode{               //���嵥����������
    ElemType data;                  //ÿ�������һ������Ԫ��
    struct LNode *next;             //ָ��ָ����һ���ڵ�
}LNode, *LinkList;                  //LNode����ǿ�����ǽڵ㣬*LinkList����ǿ����������

//��λ����루��ͷ��㣩
//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1)
        return false;
    LNode *p;                       //ָ��pָ��ǰɨ�赽�Ľڵ�
    p = L;                          //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ㣨�������ݣ�
    int j = 0;                      //��ǰpָ����ǵڼ����ڵ�
    while(p!=NULL && j<i-1)         //ѭ���ҵ���i-1���ڵ�
    {
        p = p->next;
        j++;
    }
    if(p=NULL)                      //iֵ���Ϸ�
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;              
    p->next = s;                    //���ڵ�s����p֮��
    return true;                    //����ɹ�
}

//��λ����루����ͷ��㣩
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
    LNode *p;                       //ָ��pָ��ǰɨ�赽�Ľڵ�
    p = L;                          //pָ���һ���ڵ������ͷ�ڵ�
    int j = 1;                      //��ǰpָ����ǵڼ����ڵ�
    while(p!=NULL && j<i-1)         //ѭ���ҵ���i-1���ڵ�
    {
        p = p->next;
        j++;
    }
    if(p=NULL)                      //iֵ���Ϸ�
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;              
    p->next = s;                    //���ڵ�s����p֮��
    return true;                    //����ɹ�
}

//ָ���ڵ�ĺ���������ͷ��㣩
//����������p�ڵ�֮�����Ԫ��e
bool InsertNextNode(LNode *p, ElemType e)
{
    if(p==NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL)                     //�ڴ����ʧ��
        return false;
    s->data = e;                    //�ýڵ�s����Ԫ��e
    s->next = p->next;
    p->next = s;                    //���ڵ�s����p֮��
    return true;
}

//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1)
        return false;
    LNode *p;                       //ָ��pָ��ǰɨ�赽�Ľڵ�
    p = L;                          //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ㣨�������ݣ�
    int j = 0;                      //��ǰpָ����ǵڼ����ڵ�
    while(p!=NULL && j<i-1)         //ѭ���ҵ���i-1���ڵ�
    {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

//ָ���ڵ��ǰ���������ͷ��㣩
//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode *p, ElemType e)
{
    if(p=NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL)                     //�ڴ����ʧ��
        return false;
    s->next = p->next;
    p->next = s;                    //�½��s����p֮��
    s->data = p->data;              //��p��Ԫ�ظ��Ƶ�s��
    p->data = e;                    //p��Ԫ�ظ���Ϊe
    return true;
}

//ǰ���������p���֮ǰ����s���
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
//�������ɾ����������ͷ��㣩
typedef struct LNode{               //���嵥����������
    ElemType data;                  //ÿ�������һ������Ԫ��
    struct LNode *next;             //ָ��ָ����һ���ڵ�
}LNode, *LinkList;                  //LNode����ǿ�����ǽڵ㣬*LinkList����ǿ����������

//��λ��ɾ������ͷ��㣩
bool ListDelete(LinkList &L, int i, ElemType e)//�ؼ����ҵ�Ҫɾ��λ���ǰһ��λ��
{
    if(i<1)
        return false;
    LNode *p;                       //ָ��pָ��ǰɨ�赽�Ľڵ�
    p = L;                          //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ㣨�������ݣ�
    int j = 0;                      //��ǰpָ����ǵڼ����ڵ�
    while(p!=NULL && j<i-1)         //ѭ���ҵ���i-1���ڵ�
    {
        p = p->next;
        j++;
    }
    if(p=NULL)                      //iֵ���Ϸ�
        return false;
    if(p->next==NULL)               //��i-1�����֮���Ѿ������������
        return false;
    LNode *q = p->next;             //��qָ��ɾ�����
    e = q->data;                    //��e����Ԫ�ص�ֵ
    p->next = q->next;              //��*q�������С��Ͽ���
    free(q);
    return 0;                       //ɾ���ɹ�
}

//ָ������ɾ��
bool DeleteNode(LNode *p)
{
    if(p=NULL)
        return false;
    LNode *q = p->next;             //��qָ��ɾ�����
    p->data = p->next->data;        //�ͺ�̽�㽻��������
    p->next = q->next;              //��*q�������С��Ͽ���
    free(p)                         //�ͷź�̽��Ĵ洢�ռ�
    return true;
}




//*******************************************//
//������Ĳ��ң���ͷ��㣩
//��λ���ң����ص�i��Ԫ��
LNode *GetElem(LinkList L, int i)
{
    if(i<0)
        return false;
    LNode *p;                       //ָ��pָ��ǰɨ�赽�Ľڵ�
    p = L;                          //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ㣨�������ݣ�
    int j = 0;                      //��ǰpָ����ǵڼ����ڵ�
    while(p!=NULL && j<i)           //ѭ���ҵ���i�����
    {
        p = p->next;
        j++
    }
    return p;
}

//��ֵ����
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    //�ӵ�һ����㿪ʼ����������Ϊe�Ľ��
    while(p!=NULL && p->data!=e)
        p = p->next;
    return p;                       //�ҵ��󷵻ظý��ָ�롣���򷵻�NULL
}

//���ĳ���
int Length(LinkList L)
{
    int len = 0;                    //ͳ�Ʊ�
    LNode *p = L;
    while (p->next!=NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}