//�鲢����
//���������������ϵ��������ϳ�һ���µ������

int *B = (int *)malloc((n+1)*sizeof(int));                      //��������B
void Merge(int A[], int low, int mid, int high)
{
    //��A������A[low...mid-1]��A[mid+1...high]�������򣬽����Ǻϲ���һ�������
    for(int k=low;k<=high;k++)
        B[k] = A[k];                                            //��A������Ԫ�ظ��Ƶ�B
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
    {
        if(B[i]<=B[j])                                          //�Ƚ�B�����������е�Ԫ��
            A[k] = B[i++];                                      //����Сֵ���Ƶ�A��
        else
            A[k] = B[j++];
    }
    while(i<=mid)
        A[k++] = B[i++];                                        //����һ����δ����꣬����
    while(j<=high)
        A[k++] = B[j++];                                        //���ڶ�����δ����꣬����
}

void MergeSort(int A[], int low, int high)
{
    if(low<high)
    {
        int mid = (low + high) / 2;                             //���м仮������������
        MergeSort(A, low, mid);                                 //����������н��еݹ�����
        MergeSort(A, mid+1, high);                              //���Ҳ������н��еݹ�����
        Merge(A, low, mid, high);                               //�鲢
    }
}