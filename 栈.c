//ջ�Ļ���������
/* InitStack(&S):��ʼ��ջ������һ����ջS�������ڴ�ռ�
   DestroyStack(&S):����ջ�����ٲ��ͷ�ջS��ռ�õ��ڴ�ռ�
   Push(&S, x):��ջ����ջSδ������x����ʹ֮��Ϊ��ջ��
   Pop(&S, &x):��ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x����
   GetTop(S, &x):��ջ��Ԫ�ء���ջS�ǿգ�����x����ջ��Ԫ��
   StackEmpty(S):�ж�һ��ջS�Ƿ�Ϊ�ա���SΪ�գ��򷵻�true�����򷵻�false
*/

//************************************************************************
//˳��ջ

//˳��ջ�Ķ���
#define MaxSize 10                          //����ջ��Ԫ�ص�������
typedef struct 
{
    ElemType data[MaxSize];                 //��̬������Ԫ��
    int top;                                //ջ��ָ��
}SqStack;

//****************
//ջ��ָ��ָ��ǰԪ�ش�ĵط�
//��ʼ������
void InitStack(SqStack &S)
{
    S.top = -1;                             //��ʼ��ջ��ָ��
}

//��ջ����
bool Push(SqStack &S, x)
{
    if(S.top == MaxSize-1)                  //ջ��������
        return false;
    S.top = S.top + 1;                      //ָ���ȼ�һ
    S.data[S.top] = x;                      //��Ԫ�ؽ�ջ
    //���������ȼ��� S.data[++S.top] = x;
    return true;
}

//��ջ����
bool Pop(SqStack &S, &x)
{
    if(S.top == -1)                         //ջ�գ�����
        return false;
    x = S.data[S.top];                      //ջ��Ԫ���ȳ�ջ
    S.top = S.top - 1;                      //ָ���ټ�һ
    //���������ȼ��� x = S.data[S.top--];
    return true;
}

//��ջ��Ԫ��
bool GetTop(SqStack S, &x)
{
    if(S.top == -1)                         //ջ�գ�����
        return false;
    x = S.data[S.top];                      //x��¼ջ��Ԫ��
    return true;
}

//�ж�ջ��
bool StackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

//****************
//ջ��ָ��ָ����һ��Ԫ��Ҫ��ĵط�
//��ʼ������
void InitStack(SqStack &S)
{
    S.top = 0;                             //��ʼ��ջ��ָ��
}

//��ջ����
bool Push(SqStack &S, x)
{
    if(S.top == MaxSize-1)                  //ջ��������
        return false;
    S.data[S.top] = x;                      //��Ԫ���Ƚ�ջ
    S.top = S.top + 1;                      //ָ���ټ�һ
    //���������ȼ��� S.data[S.top++] = x;
    return true;
}

//��ջ����
bool Pop(SqStack &S, &x)
{
    if(S.top == -1)                         //ջ�գ�����
        return false;
    S.top = S.top - 1;                      //ָ���ȼ�һ    
    x = S.data[S.top];                      //ջ��Ԫ�غ��ջ
    //���������ȼ��� x = S.data[--S.top];
    return true;
}

//��ջ��Ԫ��
bool GetTop(SqStack S, &x)
{
    if(S.top == 0)                         //ջ�գ�����
        return false;
    x = S.data[S.top];                      //x��¼ջ��Ԫ��
    return true;
}

//�ж�ջ��
bool StackEmpty(SqStack S)
{
    if(S.top == 0)
        return true;
    else
        return false;
}

//����ջ
#define MaxSize 10                          //����ջ��Ԫ�ص�������
typedef struct 
{
    ElemType data[MaxSize];                 //��̬������Ԫ��
    int top0;                               //0��ջջ��ָ��
    int top1;                               //1��ջջ��ָ��
}ShStack;

//��ʼ��ջ
void InitStack(ShStack &S)
{
    S.top0 = -1;                            //��ʼ��ջ��ָ��
    S.top1 = MaxSize;
}

//ջ�������� top0 + 1 == top1;



//************************************************************************
//��ջ
//��ջ�Ķ���
typedef struct Linknode
{
    ElemType data;                          //������
    struct Linknode *next;                  //ָ����
} *LiStack;                                 //ջ���Ͷ���

//��ջ ��Ӧ�� ͷ�巨����������
//��ջ ��Ӧ�� �������ɾ������
