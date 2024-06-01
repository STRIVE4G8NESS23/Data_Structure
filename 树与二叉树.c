//********************************
//�������Ĵ洢�ṹ
//��������˳��洢
#define MaxSize 100
struct TreeNode{
    ElemType value;                         //�ڵ��е�����Ԫ��
    bool isEmpty;                           //����Ƿ�Ϊ��
};

//���մ������£��������ҵ�˳��һ�δ洢��ȫ�������еĸ������
TreeNode t[MaxSize];

//��ʼ��
for(int i=0;i<MaxSize;i++)
{
    t[i].isEmpty = true;                    //��ʼ��ʱ���н����Ϊ��
}

//����������ʽ�洢
//�������Ľ�㣨��ʽ�洢��
typedef struct BiTNode{
    ElemType data;                          //������
    struct BiTNode *lchild, *rchild;         //���Һ��ӽ��
}BiTNode, *BiTree;

//����һ�ſ���
BiTree root = NULL;
//��������
root = (BiTree)malloc(sizeof(BiTNode));
root->data = {1};
root->lchild = NULL;
root->rchild = NULL;
//�����½��
BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
r->lchild = p;                              //��Ϊ���ڵ�����ӽ��




//****************************************************************
//�������ı���
typedef struct BiTNode{
    ElemType data;                          //������
    struct BiTNode *lchild, *rchild;        //���Һ��ӽ��
}BiTNode, *BiTree;

//�ݹ�ʵ��
//�������
void PreOrder(BiTree T)
{
    if(T !== NULL)
    {
        visit(T);                           //���ʸ����
        PreOrder(T->lchild);                //�ݹ����������
        PreOrder(T->rchild);                //�ݹ����������
    }
}

//�������
void InOrder(BiTree T)
{
    if(T != NULL)
    {
        InOrder(T->lchild);                 //�ݹ����������
        visit(T);                           //���ʸ����
        InOrder(T->rchild);                 //�ݹ����������
    }
}

//�������
void PostOrder(BiTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lchild);               //�ݹ����������
        PostOrder(T->rchild);               //�ݹ����������
        visit(T);                           //���ʸ����
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//�ǵݹ�ʵ��
//�������
void PreOrder2(BiTree T)
{
    IniStack(S);                            //��ʼ��ջS
    BiTree p = T;                           //p�Ǳ���ָ�룬��ָ���
    while(p || !IsEmpty(S))                 //��p��ָ��ջ�ջ��Ϊ��ʱ
    {
        if(p)                               //һ·����
        {
            visit(p);                       //���ʵ�ǰ���
            Push(S ,p);                     //�����ʹ��Ľ����ջ
            p = p->lchild;                  //���Ӳ�Ϊ�գ�һֱ������
        }
        else                                //��ջ����ת���ջԪ�ص�������
        {
            Pop(S, p);                      //ջ��Ԫ�س�ջ
            p = p->rchild;                  //���������ߣ�p��ֵΪ��ǰ�����Һ���
        }                                   //����whileѭ����������if-else���
    }
}

//�������
void InOrder2(BiTree T)
{
    IniStack(S);                            //��ʼ��ջS
    BiTree p = T;                           //p�Ǳ���ָ�룬��ָ���
    while(p || !IsEmpty(S))                 //��p��ָ��ջ�ջ��Ϊ��ʱ
    {
        if(p)                               //һ·����
        {
            Push(S ,p);                     //��ǰ�����ջ
            p = p->lchild;                  //���Ӳ�Ϊ�գ�һֱ������
        }
        else                                //��ջ����ת���ջԪ�ص�������
        {
            Pop(S, p);                      //ջ��Ԫ�س�ջ
            visit(p);                       //���ʳ�ջ���
            p = p->rchild;                  //���������ߣ�p��ֵΪ��ǰ�����Һ���
        }                                   //����whileѭ����������if-else���
    }
}

//�������
void PostOrder2(BiTree T)
{
    IniStack(S);
    BiTree p = T;                           //p�Ǳ���ָ�룬��ָ���
    r = NULL;                               //����ָ�룬ָ��������ʹ��Ľ��
    while(p || !IsEmpty(S))                 //��p��ָ��ջ�ջ��Ϊ��ʱ
    {
        if(p)                               //һ·����
        {
            Push(S ,p);                     //��ǰ�����ջ
            p = p->lchild;                  //���Ӳ�Ϊ�գ�һֱ������
        }
        else                                //��ջ����ת���ջԪ�ص�������
        {
            GetTop(S, p);                   //��ջ����㣨�ǳ�ջ��
            if(p->rchild && p->rchild!=r)   //�����������ڣ���δ�����ʹ�
                p = p->rchild;    
            else
            {
                Pop(S, p);                  //ջ��Ԫ�س�ջ
                visit(p->data);             //���ʸý��
                r = p;                      //��¼������ʹ��Ľ��
                p = NULL;                   //�������������pָ��
            }
        }                                  
    }
}

//Ӧ�ã����������
int treeDepth(BiTree T)
{
    if(T == NULL)
        return 0;
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //������� = MAX����������ȣ���������ȣ�+1
        return l>r ? l+1 : r+1;
    }
}

//�������
void LevelOrder(BiTree T)
{
    LinkQueue Q;                            //���������У�������չ
    InitQueue(Q);                           //��ʼ����������
    BiTree T;
    EnQueue(Q, T);                          //����������
    while (!IsEmpty(Q))                     //���в�����ѭ��
    {
        DeQueue(Q, p);                      //��ͷ������
        visit(p);                           //���ʳ��ӽ��
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);          //���������գ�����������������
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);          //���������գ�����������������
    }
}



//********************************************************
//�����������Ĵ洢�ṹ
//�������������
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;     //���Һ���ָ��
    int ltag, rtag;                         //����������־
}ThreadNode, *ThreadTree;

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//����������
//ȫ�ֱ���pre��ָ��ǰ���ʽ���ǰ��
ThreadNode *pre = NULL;

//����������������T
void CreatInThread(ThreadTree T)
{
    pre = NULL;                             //pre��ʼΪNULL
    if(T != NULL)                           //�ǿն���������������
    {
        InThread(T);                        //����������������
        if(pre->rchild == NULL)
            pre->rtag = 1;                  //������������һ�����
    }
}

//���������������һ�߱���һ��������
void InThread(ThreadTree T)
{
    if(T != NULL)
    {
        InThread(T->lchild);                //�������������
        visit(T);                           //���ʸ����
        InThread(T->rchild);                //�������������
    }
}

void visit(ThreadNode *q)
{
    if(q->lchild == NULL)                   //������Ϊ�գ�����ǰ������
    {                       
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)      //����ǰ�����ĺ������
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//����������
ThreadNode *pre = NULL;

//����������������T
void CreatPreThread(ThreadTree T)
{
    pre = NULL;                             //pre��ʼΪNULL
    if(T != NULL)                           //�ǿն���������������
    {
        PreThread(T);                        //����������������
        if(pre->rchild == NULL)
            pre->rtag = 1;                  //������������һ�����
    }
}

//���������������һ�߱���һ��������
void PreThread(ThreadTree T)
{
    if(T != NULL)
    {
        visit(T);                           //�ȴ�������
        if(T->ltag == 0)                    //lchild����ǰ������
            PreThread(T->lchild);                
        PreThread(T->rchild);                
    }
}

void visit(ThreadNode *q)
{
    if(q->lchild == NULL)                   //������Ϊ�գ�����ǰ������
    {                       
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)      //����ǰ�����ĺ������
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//����������
ThreadNode *pre = NULL;

//����������������T
void CreatPostThread(ThreadTree T)
{
    pre = NULL;                             //pre��ʼΪNULL
    if(T != NULL)                           //�ǿն���������������
    {
        PostThread(T);                      //����������������
        if(pre->rchild == NULL)
            pre->rtag = 1;                  //������������һ�����
    }
}

//���������������һ�߱���һ��������
void PostThread(ThreadTree T)
{
    if(T != NULL)
    {
        PostThread(T->lchild);              //�������������  
        PostThread(T->rchild);              //�������������
        visit(T);                           //���ʸ����          
    }
}

void visit(ThreadNode *q)
{
    if(q->lchild == NULL)                   //������Ϊ�գ�����ǰ������
    {                       
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)      //����ǰ�����ĺ������
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//����������������������
//�ҵ���pΪ���������У���һ������������Ľ��
ThreadNode *Firstnode(ThreadNode *p)
{
    //ѭ���ҵ������µ㣨��һ����Ҷ�ڵ㣩
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

//�������������������ҵ����p�ĺ�̽��
ThreadNode *Nextnode(ThreadNode *p)
{
    //�������������½��
    if(p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;                   //rtag==1ֱ�ӷ��غ������
}

//�������������������������������������ʵ�ֵķǵݹ��㷨��
void InOrder(ThreadNode *T)
{
    for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
        visit(p);
}


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//��������������������ǰ��
//�ҵ���pΪ���������У����һ������������Ľ��
ThreadNode *Lastnode(ThreadNode *p)
{
    //ѭ���ҵ������µ㣨��һ����Ҷ�ڵ㣩
    while(p->rtag == 0)
        p = p->rchild;
    return p;
}

//�������������������ҵ����p��ǰ�����
ThreadNode *Prenode(ThreadNode *p)
{
    //�������������½��
    if(p->ltag == 0)
        return Lastnode(p->rchild);
    else
        return p->lchild;                   //ltag==1ֱ�ӷ���ǰ������
}

//�������������������������������
void RevInOrder(ThreadNode *T)
{
    for(ThreadNode *p=Lastnode(T);p!=NULL;p=Prenode(p))
        visit(p);
}



//********************************************************
//���Ĵ洢�ṹ
//˫�ױ�ʾ����˳��洢��
#define MAX_TREE_SIZE 100                   //�����������
typedef struct{                             //���Ľ�㶨��
    ElemType data;                          //����Ԫ��
    int parent;                             //˫��λ����λ���±꣩
}PTNode;
typedef struct{                             //�������Ͷ���
    PTNode nodes[MAX_TREE_SIZE];            //˫�ױ�ʾ
    int n;                                  //�����
}PTree;

//���ӱ�ʾ����˳��+��ʽ�洢��
struct CTNode{
    int child;                              //���ӽ���������е�λ��
    struct CTNode *next;                    //��һ������
};
typedef struct{
    ElemType data;
    struct CTNode *firstchild;              //��һ������
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;                               //������͸���λ��
}CTree;

//�����ֵܱ�ʾ������ʽ�洢��
typedef struct CSNode
{
    ElemType data;                          //������
    struct CSNode *firstchild, *nextsibling;//��һ�����Ӻ����ֵ�ָ��
}CSNode, *CSTree;




//********************************************************
//����ɭ�ֵı���
//�����ȸ�����--���Ӧ�����������������ͬ
void PreOrder(TreeNode *R)
{
    if(R != NULL)
    {
        visit(R);                           //���ʸ����
        while(R������һ������T)
            PreOrder(T);                    //�ȸ�������һ������
    }
}

//���ĺ������--���Ӧ�����������������ͬ
void PostOrder(TreeNode *R)
{
    if(R != NULL)
    {
        while(R������һ������T)
            PostOrder(T);                   //���������һ����
        visit(R);                           //���ʸ����
    }
}

//���Ĳ�α������ö���ʵ�֣�

//ɭ�ֵ��������--��ͬ�����ζԸ����������ȸ�����

//ɭ�ֵ��������--��ͬ�����ζԸ��������к������