//插入排序


//直接插入排序
//每次将一个待排序的记录按其关键字大小插入到前面已经排好序的子序列中，直到全部记录插入完成

void InsertSort(int A[], int n)
{
    int i, j, temp;
    for(i=1;i<n;i++)
    {
        if(A[i]<A[i-1])                                         //若A[i]关键字小于前驱
        {
            temp = A[i];                                        //用temp暂存A[i]
            for(j=i-1;j>=0&&A[j]>temp;j--)                      //检查所有的前面已经排好序的元素
            {
                A[j+1] = A[j];                                  //所有大于temp的元素都向后挪位
            }
            A[j+1] = temp;                                      //复制到插入元素
        }
    }
}

//带哨兵
void InsertSort(int A[], int n)
{
    int i, j;
    for(i=2;i<n;i++)                                            //依次将A[2]~A[n]插入前面已排序序列
    {
        if(A[i]<A[i-1])                                         //若A[i]关键字小于前驱，将A[i]插入有序表
        {
            A[0] = A[i];                                        //复制为哨兵，A[0]不存放元素
            for(j=i-1;A[0]<A[j];j--)                            //从后往前查找待插入元素，所有大于的数后移
            {
                A[j+1] = A[j];                                  //向后挪位
            }
            A[j+1] = A[0];                                      //复制到插入元素
        }
    }
}




//折半插入排序
//先用折半查找找到应该插入的位置，再移动元素
void InsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for(i=2;i<=n;i++)                                           //依次将A[2]~A[n]插入前面已排序序列
    {
        A[0] = A[i];                                            //将A[i]暂存到A[0]
        low = 1; high = i-1;                                    //设置折半查找的范围
        while(low<high)                                         //折半查找（默认递增有序）
        {
            mid = (low + high) / 2;                             //取中间点
            if(A[mid]>A[0])
                high = mid - 1;                                 //查找左半子表
            else
                low = mid + 1;                                  //查找右半子表（若相等，为保证稳定性仍插入到右边）
        }
        for(j=i-1;j>high+1;j--)
            A[j+1] = A[j];                                      //统一后移元素，空出插入位置
        A[high+1] = A[0];                                       //插入操作
    }
}




//希尔排序
//先追求表中元素部分有序，再逐渐逼近全局有序
//设置增量，对各个子表分别进行直接插入排序。缩小增量d，重复上述操作，直至d=1为止
void ShellSort(int A[], int n)
{
    //A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
    int dk, i, j;                                               //dk为增量
    for(dk=n/2;dk>=1;dk=dk/2)                                   //步长变化
    {
        for(i=dk+1;i<=n;i++)
        {
            if(A[i]<A[i-dk])                                    //需将A[i]插入有序增量子表
            {
                A[0] = A[i];                                    //暂存在A[0]
                for(j=i-dk;j>0&&A[0]<A[j];j=j-dk)
                    A[j+dk] = A[j];                             //记录后移，查找插入的位置
                A[j+dk] = A[j];                                 //插入
            }
        }
    }
}