//���鼯�Ľṹ����
#define SIZE 100
int UFSets[SIZE];                           //����Ԫ�����飨˫��ָ�����飩

//���鼯�ĳ�ʼ��������S��Ϊ���鼯��
void Initial(int S[])
{
    for(int i=0;i<size;i++)                 //ÿ���Գɵ�Ԫ�ؼ���
        S[i] = -1;
}

//Find�����������ڲ��鼯S�в��Ҳ����ذ���Ԫ��x�����ĸ���
int Find(int S[], int x)
{
    while(S[x]>0)                           //ѭ��Ѱ��x�ĸ�
        x = S[x];
    return x;                               //����S[]<0
}

//Union�������������������ཻ�Ӽ��ϵĲ�����
void Union(int S[], int Root1, int Root2)
{
    //Ҫ��Root1��Root2�ǲ�ͬ�ģ��ұ�ʾ�Ӽ��ϵ�����
    S[Root2] = Root1;                       //����Root2���ӵ���һ����Root1����
}