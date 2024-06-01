//*********************************************
//ѭ��������
typedef struct LNode                //���嵥����������
{
    ElemType data;                  //ÿ�������һ������Ԫ��
    struct LNode *next;             //ָ��ָ����һ�����
}LNode, *LinkList;

//��ʼ��һ��ѭ��������
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));//����һ��ͷ���
    if(L==NULL)                     //�ڴ治�㣬����ʧ��
        return false;
    L->next = L;                    //ͷ����nextָ��ͷ���
    return true;
}

//�ж�ѭ���������Ƿ�Ϊ��
bool Empty(LinkList L)
{
    if(L->next==L)
        return true;
    else
        return false;
}

//�жϽ��p�Ƿ�Ϊѭ��������ı�β���
bool IsTail(LinkList L, LNode *p)
{
    if(p->next==L)
        return true;
    else
        return false;
}



//****************************************************
//ѭ��˫����
typedef struct DNode                //����˫����������
{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

//��ʼ���յ�ѭ��˫����
bool InitList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));//����һ��ͷ���
    if(L==NULL)                     //�ڴ治�㣬����ʧ��
        return false;
    L->prior = L;                   //ͷ����priorָ��ͷ���
    L->next = L;                    //ͷ����nextָ��ͷ���
    return true;
}

//�ж�ѭ��˫�����Ƿ�Ϊ��
bool Empty(DLinkList L)
{
    if(L->next==L)
        return true;
    else
        return false;
}

//�жϽ��p�Ƿ�Ϊѭ��˫����ı�β���
bool IsTail(DLinkList L, DNode *p)
{
    if(p->next==L)
        return true;
    else
        return false;
}



//***********************************************
//��̬����Ķ��壨һ��
#define MaxSize 10                  //��̬�������󳤶�
typedef struct                      //��̬�������ݽṹ�Ķ���
{
    ElemType data;                  //�洢����Ԫ��
    int next;                       //��һ��Ԫ�ص������±�
}SLinkList[MaxSize];

//��̬����Ķ��壨����
#define MaxSize 10                  //��̬�������󳤶�
struct Node                         //��̬�������ݽṹ�Ķ���
{
    ElemType data;                  //�洢����Ԫ��
    int next;                       //��һ��Ԫ�ص������±�
};
typedef struct Node SLinkList[MaxSize];

