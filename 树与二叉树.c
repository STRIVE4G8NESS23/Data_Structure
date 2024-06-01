//********************************
//二叉树的存储结构
//二叉树的顺序存储
#define MaxSize 100
struct TreeNode{
    ElemType value;                         //节点中的数据元素
    bool isEmpty;                           //结点是否为空
};

//按照从上至下，从左至右的顺序一次存储完全二叉树中的各个结点
TreeNode t[MaxSize];

//初始化
for(int i=0;i<MaxSize;i++)
{
    t[i].isEmpty = true;                    //初始化时所有结点标记为空
}

//二叉树的链式存储
//二叉树的结点（链式存储）
typedef struct BiTNode{
    ElemType data;                          //数据域
    struct BiTNode *lchild, *rchild;         //左、右孩子结点
}BiTNode, *BiTree;

//定义一颗空树
BiTree root = NULL;
//插入根结点
root = (BiTree)malloc(sizeof(BiTNode));
root->data = {1};
root->lchild = NULL;
root->rchild = NULL;
//插入新结点
BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
r->lchild = p;                              //作为根节点的左孩子结点




//****************************************************************
//二叉树的遍历
typedef struct BiTNode{
    ElemType data;                          //数据域
    struct BiTNode *lchild, *rchild;        //左、右孩子结点
}BiTNode, *BiTree;

//递归实现
//先序遍历
void PreOrder(BiTree T)
{
    if(T !== NULL)
    {
        visit(T);                           //访问根结点
        PreOrder(T->lchild);                //递归遍历左子树
        PreOrder(T->rchild);                //递归遍历右子树
    }
}

//中序遍历
void InOrder(BiTree T)
{
    if(T != NULL)
    {
        InOrder(T->lchild);                 //递归遍历左子树
        visit(T);                           //访问根结点
        InOrder(T->rchild);                 //递归遍历右子树
    }
}

//后序遍历
void PostOrder(BiTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lchild);               //递归遍历左子树
        PostOrder(T->rchild);               //递归遍历右子树
        visit(T);                           //访问根结点
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//非递归实现
//先序遍历
void PreOrder2(BiTree T)
{
    IniStack(S);                            //初始化栈S
    BiTree p = T;                           //p是遍历指针，先指向根
    while(p || !IsEmpty(S))                 //当p不指向空或栈不为空时
    {
        if(p)                               //一路向左
        {
            visit(p);                       //访问当前结点
            Push(S ,p);                     //将访问过的结点入栈
            p = p->lchild;                  //左孩子不为空，一直向左走
        }
        else                                //出栈，并转向出栈元素的右子树
        {
            Pop(S, p);                      //栈顶元素出栈
            p = p->rchild;                  //向右子树走，p赋值为当前结点的右孩子
        }                                   //返回while循环继续进入if-else语句
    }
}

//中序遍历
void InOrder2(BiTree T)
{
    IniStack(S);                            //初始化栈S
    BiTree p = T;                           //p是遍历指针，先指向根
    while(p || !IsEmpty(S))                 //当p不指向空或栈不为空时
    {
        if(p)                               //一路向左
        {
            Push(S ,p);                     //当前结点入栈
            p = p->lchild;                  //左孩子不为空，一直向左走
        }
        else                                //出栈，并转向出栈元素的右子树
        {
            Pop(S, p);                      //栈顶元素出栈
            visit(p);                       //访问出栈结点
            p = p->rchild;                  //向右子树走，p赋值为当前结点的右孩子
        }                                   //返回while循环继续进入if-else语句
    }
}

//后序遍历
void PostOrder2(BiTree T)
{
    IniStack(S);
    BiTree p = T;                           //p是遍历指针，先指向根
    r = NULL;                               //辅助指针，指向最近访问过的结点
    while(p || !IsEmpty(S))                 //当p不指向空或栈不为空时
    {
        if(p)                               //一路向左
        {
            Push(S ,p);                     //当前结点入栈
            p = p->lchild;                  //左孩子不为空，一直向左走
        }
        else                                //出栈，并转向出栈元素的右子树
        {
            GetTop(S, p);                   //读栈顶结点（非出栈）
            if(p->rchild && p->rchild!=r)   //若右子树存在，且未被访问过
                p = p->rchild;    
            else
            {
                Pop(S, p);                  //栈顶元素出栈
                visit(p->data);             //访问该结点
                r = p;                      //记录最近访问过的结点
                p = NULL;                   //结点访问完后，重置p指针
            }
        }                                  
    }
}

//应用：求树的深度
int treeDepth(BiTree T)
{
    if(T == NULL)
        return 0;
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //树的深度 = MAX（左子树深度，右子树深度）+1
        return l>r ? l+1 : r+1;
    }
}

//层序遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;                            //采用链队列，方便拓展
    InitQueue(Q);                           //初始化辅助队列
    BiTree T;
    EnQueue(Q, T);                          //将根结点入队
    while (!IsEmpty(Q))                     //队列不空则循环
    {
        DeQueue(Q, p);                      //队头结点出队
        visit(p);                           //访问出队结点
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);          //左子树不空，则左子树根结点入队
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);          //右子树不空，则右子树根结点入队
    }
}



//********************************************************
//线索二叉树的存储结构
//线索二叉树结点
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;     //左、右孩子指针
    int ltag, rtag;                         //左、右线索标志
}ThreadNode, *ThreadTree;

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//中序线索化
//全局变量pre，指向当前访问结点的前驱
ThreadNode *pre = NULL;

//中序线索化二叉树T
void CreatInThread(ThreadTree T)
{
    pre = NULL;                             //pre初始为NULL
    if(T != NULL)                           //非空二叉树才能线索化
    {
        InThread(T);                        //中序线索化二叉树
        if(pre->rchild == NULL)
            pre->rtag = 1;                  //处理遍历的最后一个结点
    }
}

//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T)
{
    if(T != NULL)
    {
        InThread(T->lchild);                //中序遍历左子树
        visit(T);                           //访问根结点
        InThread(T->rchild);                //中序遍历右子树
    }
}

void visit(ThreadNode *q)
{
    if(q->lchild == NULL)                   //左子树为空，建立前驱线索
    {                       
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)      //建立前驱结点的后继线索
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//先序线索化
ThreadNode *pre = NULL;

//先序线索化二叉树T
void CreatPreThread(ThreadTree T)
{
    pre = NULL;                             //pre初始为NULL
    if(T != NULL)                           //非空二叉树才能线索化
    {
        PreThread(T);                        //先序线索化二叉树
        if(pre->rchild == NULL)
            pre->rtag = 1;                  //处理遍历的最后一个结点
    }
}

//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T)
{
    if(T != NULL)
    {
        visit(T);                           //先处理根结点
        if(T->ltag == 0)                    //lchild不是前驱线索
            PreThread(T->lchild);                
        PreThread(T->rchild);                
    }
}

void visit(ThreadNode *q)
{
    if(q->lchild == NULL)                   //左子树为空，建立前驱线索
    {                       
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)      //建立前驱结点的后继线索
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//后序线索化
ThreadNode *pre = NULL;

//后序线索化二叉树T
void CreatPostThread(ThreadTree T)
{
    pre = NULL;                             //pre初始为NULL
    if(T != NULL)                           //非空二叉树才能线索化
    {
        PostThread(T);                      //后序线索化二叉树
        if(pre->rchild == NULL)
            pre->rtag = 1;                  //处理遍历的最后一个结点
    }
}

//后序遍历二叉树，一边遍历一边线索化
void PostThread(ThreadTree T)
{
    if(T != NULL)
    {
        PostThread(T->lchild);              //后序遍历左子树  
        PostThread(T->rchild);              //后序遍历右子树
        visit(T);                           //访问根结点          
    }
}

void visit(ThreadNode *q)
{
    if(q->lchild == NULL)                   //左子树为空，建立前驱线索
    {                       
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)      //建立前驱结点的后继线索
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//中序线索二叉树找中序后继
//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
    //循环找到最左下点（不一定是叶节点）
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p)
{
    //右子树中最左下结点
    if(p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;                   //rtag==1直接返回后继线索
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void InOrder(ThreadNode *T)
{
    for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
        visit(p);
}


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//中序线索二叉树找中序前驱
//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p)
{
    //循环找到最右下点（不一定是叶节点）
    while(p->rtag == 0)
        p = p->rchild;
    return p;
}

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *Prenode(ThreadNode *p)
{
    //右子树中最左下结点
    if(p->ltag == 0)
        return Lastnode(p->rchild);
    else
        return p->lchild;                   //ltag==1直接返回前驱线索
}

//对中序线索二叉树进行逆向中序遍历
void RevInOrder(ThreadNode *T)
{
    for(ThreadNode *p=Lastnode(T);p!=NULL;p=Prenode(p))
        visit(p);
}



//********************************************************
//树的存储结构
//双亲表示法（顺序存储）
#define MAX_TREE_SIZE 100                   //树中最多结点数
typedef struct{                             //树的结点定义
    ElemType data;                          //数据元素
    int parent;                             //双亲位置域（位置下标）
}PTNode;
typedef struct{                             //树的类型定义
    PTNode nodes[MAX_TREE_SIZE];            //双亲表示
    int n;                                  //结点数
}PTree;

//孩子表示法（顺序+链式存储）
struct CTNode{
    int child;                              //孩子结点在数组中的位置
    struct CTNode *next;                    //下一个孩子
};
typedef struct{
    ElemType data;
    struct CTNode *firstchild;              //第一个孩子
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;                               //结点数和根的位置
}CTree;

//孩子兄弟表示法（链式存储）
typedef struct CSNode
{
    ElemType data;                          //数据域
    struct CSNode *firstchild, *nextsibling;//第一个孩子和右兄弟指针
}CSNode, *CSTree;




//********************************************************
//树、森林的遍历
//树的先根遍历--与对应二叉树的先序遍历相同
void PreOrder(TreeNode *R)
{
    if(R != NULL)
    {
        visit(R);                           //访问根结点
        while(R还有下一个子树T)
            PreOrder(T);                    //先根遍历下一颗子树
    }
}

//树的后根遍历--与对应二叉树的中序遍历相同
void PostOrder(TreeNode *R)
{
    if(R != NULL)
    {
        while(R还有下一个子树T)
            PostOrder(T);                   //后根遍历下一颗树
        visit(R);                           //访问根结点
    }
}

//树的层次遍历（用队列实现）

//森林的先序遍历--等同于依次对各个树进行先根遍历

//森林的中序遍历--等同于依次对各个树进行后根遍历