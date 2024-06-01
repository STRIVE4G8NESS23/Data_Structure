//并查集的结构定义
#define SIZE 100
int UFSets[SIZE];                           //集合元素数组（双亲指针数组）

//并查集的初始化操作（S即为并查集）
void Initial(int S[])
{
    for(int i=0;i<size;i++)                 //每个自成单元素集合
        S[i] = -1;
}

//Find操作（函数在并查集S中查找并返回包含元素x的树的根）
int Find(int S[], int x)
{
    while(S[x]>0)                           //循环寻找x的根
        x = S[x];
    return x;                               //根的S[]<0
}

//Union操作（函数求两个不相交子集合的并集）
void Union(int S[], int Root1, int Root2)
{
    //要求Root1与Root2是不同的，且表示子集合的名字
    S[Root2] = Root1;                       //将根Root2连接到另一个根Root1下面
}