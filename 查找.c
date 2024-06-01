/*************************************************************/
//顺序查找（一般线性表）
typedef struct{                                             //查找表的数据结构
    ElemType *elem;                                         //元素存储空间基址，建表时按实际长度分配，0号单元留空                
    int TableLen;                                           //表的长度                                   
}SSTable;
int Search_Seq(SSTable ST, ElemType key)
{
    ST.elem[0] - key;                                       //哨兵
    for(i=ST.Table;ST.elem[i]!=key;--i);                    //从后往前找
    return i;                                               //若表中不存在关键字为key的元素，将查找到i为0时退出for循环
}



//折半查找--非递归（仅适用于有序的顺序表）
int Binary_Search(SeqList L, ElemType key)
{
    int low = 0, high = L.TableLen-1, mid;
    while(low<=high)
    {
        mid = (low + high) / 2;                             //取中间位置
        if(L.elem[mid]==key)
            return mid;                                     //查找成功则返回所在位置
        else if(L.elem[mid]>key)
            high = mid - 1;                                 //从前半部分继续查找
        else 
            low = mid + 1;                                  //从后半部分继续查找
    }
    return -1;                                              //查找失败，返回-1
}

//折半查找--递归
typedef struct{                                             //查找表的数据结构
    ElemType *elem;                                         //元素存储空间基址，建表时按实际长度分配，0号单元留空                
    int Length;                                             //表的长度                                   
}SSTable;
int BinSearchRec(SSTable ST, ElemType key, int low, int high)
{
    //在有序表中递归折半查找其关键字为key的元素，返回其在表中序号
    if(low>high)
        return 0;
    mid = (low + high) / 2;                                 //取中间位置
    if(key>ST.elem[mid])                                    //向后半部分查找
        Search(ST, key, mid+1, high);
    else if(key<ST.elem[mid])                               //向前半部分查找
        Search(ST, key, low, mid-1);
    else                                                    //查找成功
        return mid;
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//树型查找
//二叉排序树的查找（非递归）
BSTNode *BST_Search(BiTree T, ElemType key)
{
    while(T!=NULL&&key!=T->data)                            //若树空或等于根结点值，则结束循环
    {
        if(key<T->data)
            T = T->lchild;                                  //小于，则在左子树上查找
        else
            T = T->rchild;                                  //大于，则在右子树上查找
    }
    return T;
}

//二叉排序树的插入
int BST_Insert(BinTree &T, KeyType k)
{
    if(T==NULL)                                             //原树为空，新插入的记录为空结点
    {
        T = (BinTree)malloc(sizeof(BSTNode));
        T->data = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if(k==T->data)                                     //树中存在相同关键字的结点，插入失败
        return 0;
    else if(k<T->data)                                      //插入到T的左子树
        return BST_Insert(T->lchild, k);
    else                                                    //插入到T的右子树
        return BST_Insert(T->rchild, k);
}


//二叉排序树的构造
void Create_BST(BiTree &T, KeyType str[], int n)
{
    T = NULL;                                               //初始时T为空树
    int i = 0;
    while(i<n)                                              //依次将每个关键字插入到二叉排序树中
    {
        BST_Insert(T, str[i]);
        i++;
    }
}