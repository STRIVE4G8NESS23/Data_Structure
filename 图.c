/********************************************************/
//图的存储
//邻接矩阵法（不带权图）
#define MaxVertexNum 100                                        //顶点数目的最大值
typedef struct{                                     
    char Vex[MaxVertexNum];                                     //顶点表
    //可以用bool型或枚举型变量表示边
    int Edge[MaxVertexNum][MaxVertexNum];                       //邻接矩阵，边表
    int vexnum, arcnum;                                         //图的当前顶点数和边数/弧数
}MGraph;

//邻接矩阵法（带权图）
#define MaxVertexNum 100                                        //顶点数目的最大值
typedef char VertexType;                                        //顶点的数据类型
typedef int EdgeType;                                           //带权图中边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];                               //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];                  //邻接矩阵，边表
    int vexnum, arcnum;                                         //图的当前顶点数和弧数
}MGraph;


//邻接表法
#define MaxVertexNum 100                                        //顶点数目的最大值
typedef struct ArcNode{                                         //边表结点
    int adjvex;                                                 //该弧所指向的顶点的位置
    struct ArcNode *next;                                       //指向下一条弧的指针
    //InfoType info;                                            //网的边权值
}ArcNode;
typedef struct VNode{                                           //顶点表结点
    VertexType data;                                            //顶点信息
    ArcNode *first;                                             //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;                                           //邻接表
    int vexnum, arcnum;                                         //图的顶点数和弧数
}ALGraph;                                                       //ALGraph是以邻接表存储的图类型

//十字链表法（有向图）
//临界多重表法（无向图）

//图的基本操作
Adjacent(G, x, y);                                              //判断图G是否存在边(x,y)或<x,y>
Neighbors(G, x);                                                //列出图G中与结点x邻接的边
InsertVertex(G, x);                                             //从图G中插入顶点x
DeleteVertex(G, x);                                             //从图G中删除顶点x
AddEdge(G, x, y);                                               //若(x,y)或<x,y>不存在，则向图G中添加该边
RemoveEdge(G, x, y);                                            //若(x,y)或<x,y>存在，则从图G中删除该边
FirstNeighbor(G, x);                                            //求图G中顶点x的第一个邻接点，若有则返回顶点号；否则返回-1
NextNeighbor(G, x, y);                                          //假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号；若y是x的最后一个邻接点，则返回-1
Get_edge_value(G, x, y);                                        //获取图G中边(x,y)或<x,y>对应的权值
Set_edge_value(G, x, y, v);                                     //设置图G中边(x,y)或<x,y>对应的权值为v



/**********************************************************/
//图的遍历
//广度优先搜索（BFS）  非递归
bool visited[MAX_VERTEX_NUM];                                   //访问标记数组
void BFSTraverse(Graph G)                                       //对图G进行广度优先遍历
{
    for(i=0;i<G.vexnum;++i)
        visited[i] = FALSE;                                     //访问标记数组初始化
    InitQueue(Q);                                               //初始化辅助队列Q
    for(i=0;i<G.vexnum;++i)                                     //从0号顶点开始遍历，找到第一个未被访问的顶点
        if(!visited[i])                                         //对每个连通分量调用一次BFS
            BFS(G, i);                                          //vi未访问过，从vi开始BFS
}
void BFS(Graph G, int v)                                        //从顶点v出发，广度优先遍历图G
{
    visit(v);                                                   //访问初始顶点
    visited[v] = TRUE;                                          //对v做以访问标记
    EnQueue(Q, v);                                              //顶点v入队列Q
    while(!isEmpty(Q))      
    {   
        DeQueue(Q, v);                                          //顶点v出队列
        for(w=FirstNeighbor(Q, v);w>=0;w=NextNeighbor(Q, v, w)) //检测v所有邻接点
        {
            if(!visited[w])                                     //w为v的尚未访问的邻接顶点
            {
                visit(w);                                       //访问顶点w
                visited[w] = TRUE;                              //对w做以访问记录
                EnQueue(Q, w);                                  //顶点w入队列
            }
        }
    }
}

//深度优先搜索（DFS）  递归
bool visited[MAX_VERTEX_NUM];                                   //访问标记数组
void DFSTraverse(Graph G)                                       //对图G进行深度优先遍历
{
    for(v=0;v<G.vexnum;++v)
        visited[v] = FALSE;                                     //访问标记数组初始化
    for(v=0;v<G.vexnum;++v)                                     //从0号顶点开始遍历
        if(!visited[v])                                         
            DFS(G, v);                                          
}
void DFS(Grasph G, int v)                                       //从顶点v出发，深度优先遍历图G
{
    visit(v);                                                   //访问初始顶点
    visited[v] = TRUE;                                          //对v做以访问标记 
    for(w=FirstNeighbor(Q, v);w>=0;w=NextNeighbor(Q, v, w)) //检测v所有邻接点
        {
            if(!visited[w])                                     //w为v的尚未访问的邻接顶点
            {
                DFS(G, w);                                      //递归调用
            }
        }
}


/*****************************************************************/
//图的应用
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//最小生成树
GENERIC_MST(G)
{
    T = NULL;
    while T未形成一颗生成树;
        do 找到一条最小代价边(u,v)并且加入T后不会产生回路;
            T = T并(u,v);
}

//Prim算法
void Prim(G, T)
{
    T = NULL;                                                   //初始化空树
    u = {w};                                                    //添加任一顶点w
    while((V-U)!=NULL)                                          //若树中不含全部顶点
    {
        设(u,v)是使u属于U与v属于V-U,且权值最小的边;
        T = T并{(u,v)};                                         //边归入树
        U = U并{v};                                             //顶点归入树
    }
}

#define N 110                                                   //最多顶点数
#define MAX 0x3f3f3f3f                                          //模拟无穷大
int map[N][N];                                                  //存储各顶点间的权值
int flag[N];                                                    //标记是否已纳入树
int dis[N];                                                     //已纳入点和其余各点的最小权值
int prim(int n)                                                 //普利姆函数
{
    int i, j;
    int now;                                                    //记录新纳入的点
    int min;                                                    //记录新纳入的点到其余已纳入的点的最小权值
    int sum = 0;                                                //最小生成树权值和
    memset(dis, MAX, sizeof(dis));                              //初始化dis数组为无穷大
    memset(flag, 0, sizeof(flag));                              //初始化flag数组，0表示此点未被纳入
    /*这里随机选取了1号点为初始时被纳入的顶点*/
    for(i = 1; i <= n; i++)
        dis[i] = map[1][i];                                     //与1号点与其他点的权值存入dis数组
    dis[1] = 0;                                                 //一号点到其本身的权值为0
    flag[1] = 1;                                                //标记为已纳入

    for(i = 1; i < n; i++){                                     //除去初始时随机纳入的点还有n-1个点应被纳入
        now = min = MAX;                                        //初始为无穷大表示两点间无通路
        for(j = 1; j <= n; j++){                                //遍历
            if(flag[j] == 0){
                if(dis[j] < min){                               //寻找与已纳入各点权值最小的点
                    now = j;
                    min = dis[j];
                }
            }
        }
        if(now == MAX)                                          //若now等于max，则证明所有与初始时纳入的点连通的点已全被纳入
            break;
        sum += min;                                             //将找到的点纳入并标记
        flag[now] = 1;
        for(j = 1; j <= n; j++){
            /*
                遍历比较之前纳入点到未纳入点的权值的最小值
                与刚纳入点到未纳入点的权值
                并用dis[j]存储新的最小值
            */
            if(flag[j] == 0)
                if(dis[j] > map[now][j])
                    dis[j] = map[now][j];
        }
    }
    if(i == n)                                                  //若i等于n则证明已经建立最小生成树
        return sum;
    else
        return -1;
}

//Kruskal算法
void Kruskal(V, T)
{
    T = V;                                                      //初始化树T，仅含顶点
    numS = n;                                                   //连通分量数
    while(numS>1)                                               //若连通分量数大于1
    {
        从E中取出权值最小的边(u,v);
        if(v和u属于T中不同的连通分量)
        {
            T = T并{(u,v)};                                     //将次边加入生成树中
            numS--;                                             //连通分量数减一
        }
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//最短路径
//1.单源最短路径
//1.1 BFS（无权图）
#define 10000 MAX 
void BFS_Min_Distance(Graph G, int u)
{
    //d[i]表示从u到i结点的最短路径
    for(i=0;i<G.vexnum;++i)
        d[i] = MAX;                                             //初始化路径长度
    visited[u] = TRUE;
    d[u] = 0;
    EnQueue(Q, u);
    while(!isEmpty(Q))                                          //BFS算法主过程
    {
        DeQueue(Q, u);                                          //队头元素u出队
        for(w=FirstNeighbor(Q, v);w>=0;w=NextNeighbor(Q, v, w))
        {                                                       //w为u的尚未访问的邻接顶点
            if(!visited[w])
            {
                visited[w] = TRUE;                              //设以访问标记
                d[w] = d[u] + 1;                                //路径长度加一
                EnQueue(Q, w);                                  //顶点w入队
            }
        }
    }
}

//1.2 Dijikstra（有权图，无权图）

int map[SIZE][SIZE];  //邻接矩阵存储 
int len[SIZE];  	//d[i]表示源点到i这个点的距离 
int visit[SIZE];  //节点是否被访问 
int n,m;  

int dijkstra(int from, int to){	//从源点到目标点 
    int i;  
    for(i = 1 ; i <= n ; i ++){	//初始化 
        visit[i] = 0;	//一开始每个点都没被访问 
        len[i] = map[from][i];	//先假设源点到其他点的距离 
    }  
    int j;  
    for(i = 1 ; i < n ; ++i){	//对除源点的每一个点进行最短计算 
        int min = INF;  //记录最小len[i] 
        int pos;  //记录小len[i] 的点 
        for(j = 1 ; j <= n ; ++j){	
            if(!visit[j] && min > len[j]){  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j]))){ //如果j节点没有被访问过&&j节点到源节点的最短路径>pos节点到源节点的最短路径+pos节点到j节点的路径  
                len[j] = len[pos] + map[pos][j];	//更新j节点到源节点的最短路径	
            }  
        }  
    }  
    return len[to];
}


//2.各顶点间的最短路径
//Floyd算法
void Floyd(int n,int Graph[][SIZE],int path[][SIZE])//求最短路径矩阵path[][]
{ 
    int i,j,k;
    int A[SIZE][SIZE];
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            A[i][j] = Graph[i][j];
            path[i][j] = -1;
        }
    }
    for(k = 0;k < n;k++)
    {
        for(i=0;i < n;i++)
        {
            for(j=0;j < n;j++)
            {
                if(A[i][j]>A[i][k]+A[k][j])
                 {
                     A[i][j] = A[i][k]+A[k][j];
                     path[i][j] = k;
                 }
            }
        }
    }
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//有向无环图描述表达式

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//拓扑排序
bool TopologicalSort(Graph G)
{
    //采用邻接表存储
    InitStack(S);                                               //初始化栈，存储入度为0的顶点
    for(int i=0;i<G.nexnum;i++)
        if(indegree[i] == 0)                                    //当前结点的入度为0
            Push(S, i);                                          //将所有入度为0的顶点进栈
    int count = 0;                                              //计数，记录当前已经输出的顶点数
    while(!isEmpty(S))                                          //栈不空，则存在入度为0的顶点
    {
        Pop(S, i);                                              //栈顶元素出栈
        print[count++] = i;                                     //输出顶点i
        for(p=G.vertices[i].firststarc;p;p=p->nextarc)
        {
            //将所有i指向的顶点的入度减一，并且将入度减为0的顶点压入栈S
            v = p->adjvex;
            if(!(--indegree;v))
                Push(S, v);                                     //入度为0，则入栈
        }
    }
    if(count<G.vexnum)
        return false;                                           //排序失败，有向图中有回路
    else
        return true;                                            //拓扑排序成功
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//关键路径