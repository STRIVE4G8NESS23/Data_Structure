//��������

//ð������
//�Ӻ���ǰ�����ǰ���������Ƚ�����Ԫ�ص�ֵ����Ϊ�����򽻻����ǣ�ֱ�����бȽ���
//��ĳ����δ�����������������ǰ����
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
        flag = false;                                           //��ʾ����ð���Ƿ��������ı�־
        for(j=n-1;j>i;j--)                                      //һ��ð�ݹ���
        if(A[j-1]>A[j])                                         //��Ϊ����
        {
            swap(A[j-1], A[j]);                                 //����
            flag = true;
        }
        if(flag==false)
            return;                                             //���˱�����û�з���������˵�����Ѿ�����
    }
}



//��������
//��������������Ԫ�عؼ��ֵıȽϽ�����Ի���������¼�������е�λ��
int Partition(int A[], int low, int high)                       //һ�˻���
{
    int pivot = A[low];                                         //����ǰ���е�һ��Ԫ����Ϊ���ᣬ�Ա���л���
    while(low<high)
    {
        while(low<high&&A[high]>=pivot)
            --high;
        A[low] = A[high];                                       //������С��Ԫ���Ƶ����
        while (low<high&&A[low]<=pivot)
            ++low;
        A[high] = A[low];                                       //��������Ԫ���Ƶ��Ҷ�
    }
    A[low] = pivot;                                             //����Ԫ�ش��������λ��
    return low;                                                 //���ش�����������λ��
}

void QuickSort(int A[], int low, int high)
{
    if(low<high)
    {
        //Partition()���ǻ��ֲ���������A[low...high]����Ϊ�������������������ӱ�
        int pivotpos = Partition(A, low, high);                 //����
        QuickSort(A, low, pivotpos-1);                          //�����ӱ���еݹ�����
        QuickSort(A, pivotpos+1, high);                         //�����ӱ���еݹ�����
    }
}