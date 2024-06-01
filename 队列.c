//���еĻ�������
/*  InitQueue(&Q):��ʼ�����У�����һ���ն���Q
    DestroyQueue(&Q):���ٶ��С����ٲ��ͷŶ���Qռ�õĿռ�
    EnQueue(&Q, x):��ӣ�������Qδ������x���룬ʹ֮��Ϊ�µĶ�β
    DeQueue(&Q, &x):���ӣ�������Q�ǿգ�ɾ����ͷԪ�أ�����x����
    GetHead(Q, &x):����ͷԪ�أ�������Q�ǿգ��򽫶�ͷԪ�ظ�ֵ��x
    QueueEmpty(Q):�ж϶ӿգ�������QΪ�շ���true�����򷵻�false
*/

//***********************************************************
//���е�˳��ʵ��
#define MaxSize 10                          //���������Ԫ�ص�������
typedef struct 
{
    ElemType data[MaxSize];                 //�þ�̬�����Ŷ���Ԫ��
    int front, rear;                        //��ͷָ��Ͷ�βָ��
}SqQueue;

//��ʼ������
void InitQueue(SqQueue &Q)
{
    //��ʼʱ����ͷ�Ͷ�βָ�붼ָ��0
    Q.front = Q.rear = 0;
}

//ѭ������--��Ӳ���
bool EnQueue(SqQueue &Q, ElemType x)
{
    if((Q.rear+1)%MaxSize == Q.front)
        return false;                       //�����򱨴�
    Q.data[Q.rear] = x;                     //��Ԫ�ز����β
    Q.rear = (Q.rear+1)%MaxSize;            //��βָ���һȡģ
    return true;
}

//ѭ������--���Ӳ���
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if(Q.rear == Q.front)                   //�ӿ��򱨴�
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;          //��ͷָ�����
    return true;
}

//���ͷԪ�ص�ֵ
bool GetTop(SqQueue Q, ElemType &x)
{
    if(Q.front == Q.front)                  //�ӿ��򱨴�
        return false;
    x = Q.data[Q.front];
    return true;
}




//***********************************************************
//���е���ʽʵ��
typedef struct LinkNode                     //��ʽ���еĽ��
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{                             //��ʽ����
    LinkNode *front, *rear;                 //���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;

//��ʼ������ͷ��㣩
void InitQueue(LinkQueue &Q)
{
    //��ʼʱ��front��rear��ָ��ͷ���
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front ->next = NULL;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

//��ӣ���ͷ��㣩
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;                       //�½����뵽rear֮��
    Q.rear = s;                             //�޸ı�βָ��
}

//���ӣ���ͷ��㣩
bool DeQueue(LinkQueue &Q, ElemType &x)
{
    if(IsEmpty(Q))
        return false;                       //�ն�
    LinkNode *p = Q.front->next;
    x = p->data;                            //�ñ���x���ض�ͷԪ��
    Q.front->next = p->next;                //�޸�ͷ����nextָ��
    if(Q.rear == p)                         //�˴������һ��������
        Q.rear = Q.front;                   //�޸�rearָ��
    free(p);                                //�ͷŽ��ռ�
    return true;
}



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//��ʼ��������ͷ��㣩
void InitQueue(LinkQueue &Q)
{
    //��ʼʱ��front��rear��ָ��NULL
    Q.front = NULL;
    Q.rear = NULL;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
    if(Q.front == NULL)
        return true;
    else
        return false;
}

//��ӣ�����ͷ��㣩
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if(IsEmpty(Q))                          //�ڿն����в����һ��Ԫ��
        Q.front = s;                        //�޸Ķ�ͷ��βָ��
        Q.rear = s;
    else
        Q.rear->next = s;                   //�½����뵽rear���֮��
        Q.rear = s;                         //�޸�rearָ��
}

//���ӣ�����ͷ��㣩
void DeQueue(LinkQueue &Q, ElemType &X)
{
    if(IsEmpty(Q))
        return false;                       //�ӿ�
    LinkNode *p = Q.front;                  //pָ��˴γ��ӵĽ��
    x = p->data;                            //�ñ���x���ض�ͷԪ��
    Q.front = p->next;                      //�޸�frontָ��
    if(Q.rear == p)                         //�˴������һ��������
        Q.front = NULL;                     //frontָ��NULL
        Q.rear = NULL;                      //rearָ��NULL
    free(p);                                //�ͷŽ��ռ�
    return true;
}