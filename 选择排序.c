//选择排序

//简单选择排序
//每一趟在待排序元素中选取关键字最小的元素加入有序子序列
void SelectSort(int A[], int n)
{
    int i, j, min;
    for(i=0;i<n-1;i++)                                          //一共进行n-1趟
    {
        min = i;                                                //记录最小元素位置
        for(j=i+1;j<n;j++)                                      //在A[i...n-1]中选择最小的元素
        {
            if(A[j]<A[min])                                     //更新最小元素位置
                min = j;
        }
        if(min!=i)
            swap(A[i], A[min]);                                 //封装的swap函数共移动元素3次         
    }
}



//堆排序
//每一趟将堆顶元素加入有序子序列（与待排序序列中的最后一个元素交换）

//建立大根堆
void HeadAdjust(int A[], int k, int len)
{
    //函数HeadAdjust将元素k为根的子树进行调整
    A[0] = A[k];                                                //A[0]暂存子树的根结点
    for(i=2*k;i<=len;i*=2)                                      //沿key较大的子结点向下筛选
    {
        if(i<len&&A[i]<A[i+1])                                  
            i++;                                                //取key较大的子结点的下标
        if(A[0]>A[i])
            break;                                              //筛选结束
        else
        {
            A[k] = A[i];                                        //将A[i]调整到双亲结点上
            k = i;                                              //修改k值，以便继续向下筛选
        }
        A[k] = A[0];                                            //被筛选结点的值放入最终位置
    }
}

void BuildMaxHeap(int A[], int len)
{
    for(int i=len/2;i>0;i--)                                    //从i=[n/2]~1，反复调整堆
        HeadAdjust(A, i, len);
}

//堆排序
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);                                       //初始建堆
    for(i=len;i>1;i--)                                          //n-1趟的交换和建堆过程
    {
        swap(A[i], A[1]);                                       //输出堆顶元素（和堆底元素交换）
        HeadAdjust(A, 1, i-1);                                  //调整，把剩余的i-1个元素整理成堆
    }
}

//插入：先将新结点放在堆的末端，再对这个新结点向上执行调整操作
//删除：用堆底元素代替被删除元素的位置，再执行调整操作