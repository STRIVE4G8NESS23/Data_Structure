/********************************************************/
//ͼ�Ĵ洢
//�ڽӾ��󷨣�����Ȩͼ��
#define MaxVertexNum 100                                        //������Ŀ�����ֵ
typedef struct{                                     
    char Vex[MaxVertexNum];                                     //�����
    //������bool�ͻ�ö���ͱ�����ʾ��
    int Edge[MaxVertexNum][MaxVertexNum];                       //�ڽӾ��󣬱߱�
    int vexnum, arcnum;                                         //ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;

//�ڽӾ��󷨣���Ȩͼ��
#define MaxVertexNum 100                                        //������Ŀ�����ֵ
typedef char VertexType;                                        //�������������
typedef int EdgeType;                                           //��Ȩͼ�б���Ȩֵ����������
typedef struct{
    VertexType Vex[MaxVertexNum];                               //�����
    EdgeType Edge[MaxVertexNum][MaxVertexNum];                  //�ڽӾ��󣬱߱�
    int vexnum, arcnum;                                         //ͼ�ĵ�ǰ�������ͻ���
}MGraph;


//�ڽӱ�
#define MaxVertexNum 100                                        //������Ŀ�����ֵ
typedef struct ArcNode{                                         //�߱���
    int adjvex;                                                 //�û���ָ��Ķ����λ��
    struct ArcNode *next;                                       //ָ����һ������ָ��
    //InfoType info;                                            //���ı�Ȩֵ
}ArcNode;
typedef struct VNode{                                           //�������
    VertexType data;                                            //������Ϣ
    ArcNode *first;                                             //ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;                                           //�ڽӱ�
    int vexnum, arcnum;                                         //ͼ�Ķ������ͻ���
}ALGraph;                                                       //ALGraph�����ڽӱ�洢��ͼ����

//ʮ������������ͼ��
//�ٽ���ر�������ͼ��

//ͼ�Ļ�������
Adjacent(G, x, y);                                              //�ж�ͼG�Ƿ���ڱ�(x,y)��<x,y>
Neighbors(G, x);                                                //�г�ͼG������x�ڽӵı�
InsertVertex(G, x);                                             //��ͼG�в��붥��x
DeleteVertex(G, x);                                             //��ͼG��ɾ������x
AddEdge(G, x, y);                                               //��(x,y)��<x,y>�����ڣ�����ͼG����Ӹñ�
RemoveEdge(G, x, y);                                            //��(x,y)��<x,y>���ڣ����ͼG��ɾ���ñ�
FirstNeighbor(G, x);                                            //��ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ����򷵻�-1
NextNeighbor(G, x, y);                                          //����ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1
Get_edge_value(G, x, y);                                        //��ȡͼG�б�(x,y)��<x,y>��Ӧ��Ȩֵ
Set_edge_value(G, x, y, v);                                     //����ͼG�б�(x,y)��<x,y>��Ӧ��ȨֵΪv



/**********************************************************/
//ͼ�ı���
//�������������BFS��  �ǵݹ�
bool visited[MAX_VERTEX_NUM];                                   //���ʱ������
void BFSTraverse(Graph G)                                       //��ͼG���й�����ȱ���
{
    for(i=0;i<G.vexnum;++i)
        visited[i] = FALSE;                                     //���ʱ�������ʼ��
    InitQueue(Q);                                               //��ʼ����������Q
    for(i=0;i<G.vexnum;++i)                                     //��0�Ŷ��㿪ʼ�������ҵ���һ��δ�����ʵĶ���
        if(!visited[i])                                         //��ÿ����ͨ��������һ��BFS
            BFS(G, i);                                          //viδ���ʹ�����vi��ʼBFS
}
void BFS(Graph G, int v)                                        //�Ӷ���v������������ȱ���ͼG
{
    visit(v);                                                   //���ʳ�ʼ����
    visited[v] = TRUE;                                          //��v���Է��ʱ��
    EnQueue(Q, v);                                              //����v�����Q
    while(!isEmpty(Q))      
    {   
        DeQueue(Q, v);                                          //����v������
        for(w=FirstNeighbor(Q, v);w>=0;w=NextNeighbor(Q, v, w)) //���v�����ڽӵ�
        {
            if(!visited[w])                                     //wΪv����δ���ʵ��ڽӶ���
            {
                visit(w);                                       //���ʶ���w
                visited[w] = TRUE;                              //��w���Է��ʼ�¼
                EnQueue(Q, w);                                  //����w�����
            }
        }
    }
}

//�������������DFS��  �ݹ�
bool visited[MAX_VERTEX_NUM];                                   //���ʱ������
void DFSTraverse(Graph G)                                       //��ͼG����������ȱ���
{
    for(v=0;v<G.vexnum;++v)
        visited[v] = FALSE;                                     //���ʱ�������ʼ��
    for(v=0;v<G.vexnum;++v)                                     //��0�Ŷ��㿪ʼ����
        if(!visited[v])                                         
            DFS(G, v);                                          
}
void DFS(Grasph G, int v)                                       //�Ӷ���v������������ȱ���ͼG
{
    visit(v);                                                   //���ʳ�ʼ����
    visited[v] = TRUE;                                          //��v���Է��ʱ�� 
    for(w=FirstNeighbor(Q, v);w>=0;w=NextNeighbor(Q, v, w)) //���v�����ڽӵ�
        {
            if(!visited[w])                                     //wΪv����δ���ʵ��ڽӶ���
            {
                DFS(G, w);                                      //�ݹ����
            }
        }
}


/*****************************************************************/
//ͼ��Ӧ��
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//��С������
GENERIC_MST(G)
{
    T = NULL;
    while Tδ�γ�һ��������;
        do �ҵ�һ����С���۱�(u,v)���Ҽ���T�󲻻������·;
            T = T��(u,v);
}

//Prim�㷨
void Prim(G, T)
{
    T = NULL;                                                   //��ʼ������
    u = {w};                                                    //�����һ����w
    while((V-U)!=NULL)                                          //�����в���ȫ������
    {
        ��(u,v)��ʹu����U��v����V-U,��Ȩֵ��С�ı�;
        T = T��{(u,v)};                                         //�߹�����
        U = U��{v};                                             //���������
    }
}

#define N 110                                                   //��ඥ����
#define MAX 0x3f3f3f3f                                          //ģ�������
int map[N][N];                                                  //�洢��������Ȩֵ
int flag[N];                                                    //����Ƿ���������
int dis[N];                                                     //������������������СȨֵ
int prim(int n)                                                 //����ķ����
{
    int i, j;
    int now;                                                    //��¼������ĵ�
    int min;                                                    //��¼������ĵ㵽����������ĵ����СȨֵ
    int sum = 0;                                                //��С������Ȩֵ��
    memset(dis, MAX, sizeof(dis));                              //��ʼ��dis����Ϊ�����
    memset(flag, 0, sizeof(flag));                              //��ʼ��flag���飬0��ʾ�˵�δ������
    /*�������ѡȡ��1�ŵ�Ϊ��ʼʱ������Ķ���*/
    for(i = 1; i <= n; i++)
        dis[i] = map[1][i];                                     //��1�ŵ����������Ȩֵ����dis����
    dis[1] = 0;                                                 //һ�ŵ㵽�䱾���ȨֵΪ0
    flag[1] = 1;                                                //���Ϊ������

    for(i = 1; i < n; i++){                                     //��ȥ��ʼʱ�������ĵ㻹��n-1����Ӧ������
        now = min = MAX;                                        //��ʼΪ������ʾ�������ͨ·
        for(j = 1; j <= n; j++){                                //����
            if(flag[j] == 0){
                if(dis[j] < min){                               //Ѱ�������������Ȩֵ��С�ĵ�
                    now = j;
                    min = dis[j];
                }
            }
        }
        if(now == MAX)                                          //��now����max����֤���������ʼʱ����ĵ���ͨ�ĵ���ȫ������
            break;
        sum += min;                                             //���ҵ��ĵ����벢���
        flag[now] = 1;
        for(j = 1; j <= n; j++){
            /*
                �����Ƚ�֮ǰ����㵽δ������Ȩֵ����Сֵ
                �������㵽δ������Ȩֵ
                ����dis[j]�洢�µ���Сֵ
            */
            if(flag[j] == 0)
                if(dis[j] > map[now][j])
                    dis[j] = map[now][j];
        }
    }
    if(i == n)                                                  //��i����n��֤���Ѿ�������С������
        return sum;
    else
        return -1;
}

//Kruskal�㷨
void Kruskal(V, T)
{
    T = V;                                                      //��ʼ����T����������
    numS = n;                                                   //��ͨ������
    while(numS>1)                                               //����ͨ����������1
    {
        ��E��ȡ��Ȩֵ��С�ı�(u,v);
        if(v��u����T�в�ͬ����ͨ����)
        {
            T = T��{(u,v)};                                     //���α߼�����������
            numS--;                                             //��ͨ��������һ
        }
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//���·��
//1.��Դ���·��
//1.1 BFS����Ȩͼ��
#define 10000 MAX 
void BFS_Min_Distance(Graph G, int u)
{
    //d[i]��ʾ��u��i�������·��
    for(i=0;i<G.vexnum;++i)
        d[i] = MAX;                                             //��ʼ��·������
    visited[u] = TRUE;
    d[u] = 0;
    EnQueue(Q, u);
    while(!isEmpty(Q))                                          //BFS�㷨������
    {
        DeQueue(Q, u);                                          //��ͷԪ��u����
        for(w=FirstNeighbor(Q, v);w>=0;w=NextNeighbor(Q, v, w))
        {                                                       //wΪu����δ���ʵ��ڽӶ���
            if(!visited[w])
            {
                visited[w] = TRUE;                              //���Է��ʱ��
                d[w] = d[u] + 1;                                //·�����ȼ�һ
                EnQueue(Q, w);                                  //����w���
            }
        }
    }
}

//1.2 Dijikstra����Ȩͼ����Ȩͼ��

int map[SIZE][SIZE];  //�ڽӾ���洢 
int len[SIZE];  	//d[i]��ʾԴ�㵽i�����ľ��� 
int visit[SIZE];  //�ڵ��Ƿ񱻷��� 
int n,m;  

int dijkstra(int from, int to){	//��Դ�㵽Ŀ��� 
    int i;  
    for(i = 1 ; i <= n ; i ++){	//��ʼ�� 
        visit[i] = 0;	//һ��ʼÿ���㶼û������ 
        len[i] = map[from][i];	//�ȼ���Դ�㵽������ľ��� 
    }  
    int j;  
    for(i = 1 ; i < n ; ++i){	//�Գ�Դ���ÿһ���������̼��� 
        int min = INF;  //��¼��Сlen[i] 
        int pos;  //��¼Сlen[i] �ĵ� 
        for(j = 1 ; j <= n ; ++j){	
            if(!visit[j] && min > len[j]){  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j]))){ //���j�ڵ�û�б����ʹ�&&j�ڵ㵽Դ�ڵ�����·��>pos�ڵ㵽Դ�ڵ�����·��+pos�ڵ㵽j�ڵ��·��  
                len[j] = len[pos] + map[pos][j];	//����j�ڵ㵽Դ�ڵ�����·��	
            }  
        }  
    }  
    return len[to];
}


//2.�����������·��
//Floyd�㷨
void Floyd(int n,int Graph[][SIZE],int path[][SIZE])//�����·������path[][]
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
//�����޻�ͼ�������ʽ

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//��������
bool TopologicalSort(Graph G)
{
    //�����ڽӱ�洢
    InitStack(S);                                               //��ʼ��ջ���洢���Ϊ0�Ķ���
    for(int i=0;i<G.nexnum;i++)
        if(indegree[i] == 0)                                    //��ǰ�������Ϊ0
            Push(S, i);                                          //���������Ϊ0�Ķ����ջ
    int count = 0;                                              //��������¼��ǰ�Ѿ�����Ķ�����
    while(!isEmpty(S))                                          //ջ���գ���������Ϊ0�Ķ���
    {
        Pop(S, i);                                              //ջ��Ԫ�س�ջ
        print[count++] = i;                                     //�������i
        for(p=G.vertices[i].firststarc;p;p=p->nextarc)
        {
            //������iָ��Ķ������ȼ�һ�����ҽ���ȼ�Ϊ0�Ķ���ѹ��ջS
            v = p->adjvex;
            if(!(--indegree;v))
                Push(S, v);                                     //���Ϊ0������ջ
        }
    }
    if(count<G.vexnum)
        return false;                                           //����ʧ�ܣ�����ͼ���л�·
    else
        return true;                                            //��������ɹ�
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//�ؼ�·��