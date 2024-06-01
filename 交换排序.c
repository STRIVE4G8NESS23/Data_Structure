//交换排序

//冒泡排序
//从后往前（或从前往后）两两比较相邻元素的值，若为逆序，则交换它们，直到序列比较完
//若某趟中未发生交换，则可以提前结束
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int A[], int n)
{
    for(i=0;i<n-1;i++)
    {
        flag = false;                                           //表示本趟冒泡是否发生交换的标志
        for(j=n-1;j>i;j--)                                      //一趟冒泡过程
        if(A[j-1]>A[j])                                         //若为逆序
        {
            swap(A[j-1], A[j]);                                 //交换
            flag = true;
        }
        if(flag==false)
            return;                                             //本趟遍历后没有发生交换，说明表已经有序
    }
}



//快速排序
//根据序列中两个元素关键字的比较结果来对换这两个记录在序列中的位置
int Partition(int A[], int low, int high)                       //一趟划分
{
    int pivot = A[low];                                         //将当前表中第一个元素设为枢轴，对表进行划分
    while(low<high)
    {
        while(low<high&&A[high]>=pivot)
            --high;
        A[low] = A[high];                                       //比枢轴小的元素移到左端
        while (low<high&&A[low]<=pivot)
            ++low;
        A[high] = A[low];                                       //比枢轴大的元素移到右端
    }
    A[low] = pivot;                                             //枢轴元素存放在最终位置
    return low;                                                 //返回存放枢轴的最终位置
}

void QuickSort(int A[], int low, int high)
{
    if(low<high)
    {
        //Partition()就是划分操作，将表A[low...high]划分为满足上述条件的两个子表
        int pivotpos = Partition(A, low, high);                 //划分
        QuickSort(A, low, pivotpos-1);                          //对左子表进行递归排序
        QuickSort(A, pivotpos+1, high);                         //对右子表进行递归排序
    }
}