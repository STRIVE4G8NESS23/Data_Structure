
//**********************************************************//
//˳����ʵ��--��̬����
#include<stdio.h>
#define MaxSize 10              //������󳤶�
typedef struct{
    ElemType data[MaxSize];     //�þ�̬�ġ����顱�������Ԫ��
    int length;                 //˳���ĵ�ǰ����  
}SqList;                        //˳�������Ͷ��壨��̬���䷽ʽ��

//��������--��ʼ��һ��˳���
void InitList(Sqlist &L)
{
    for(int i=0; i<MaxSize; i++)
    {
        L.data[i] = 0;          //����������Ԫ������ΪĬ�ϳ�ʼֵ
    }
    L.length = 0;               //˳����ʼ����Ϊ0
}

int main()
{
    SqList L;                   //����һ��˳���
    InitList(L);                //��ʼ��һ��˳���
    //...δ���������������
    return 0;
}




//**********************************************************//
//˳����ʵ��--��̬����
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10             //Ĭ�ϵ����ĳ���
typedef struct{
    int *data;                  //ָʾ��̬���������ָ��
    int MaxSize;                //˳�����������
    int length;                 //˳���ĵ�ǰ����
}SeqList;

void InitList(SeqList &L)
{
    //��malloc��������һƬ�������ڴ�ռ�
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//���Ӷ�̬����ĳ���
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;            //����һ��ָ��ָ��ԭ�����ַ
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0; i<L.length; i++){
        L.data[i] = p[i];       //��ԭ�������ݸ��Ƶ�������
    }
    L.MaxSize = L.MaxSize + len;//˳�����󳤶�����len
    free(p);                    //�ͷ�ԭ�����ڴ�ռ�
}

int main()
{
    SeqList L;                  //����һ��˳���
    InitList(L);                //��ʼ��һ��˳���
    //...��˳����в���Ԫ��...
    IncreaseSize(L, 5);
    return 0;
}




//**********************************************************//
#define MaxSize 10              //������󳤶�
typedef struct{
    ElemType data[MaxSize];     //�þ�̬�ġ����顱�������Ԫ��
    int length;                 //˳���ĵ�ǰ����  
}SqList;                        //˳�������Ͷ���

//˳���Ļ�������--����
bool ListInsert(SqList &L, int i, int e)
{
    if(i<1 || i>L.length+1)     //�ж�i�ķ�Χ�Ƿ���Ч
        return false;
    if(L.length >= MaxSize)     //��ǰ�洢���������ܲ���
        return false;
    for(int j=L.length;j>=i;j--)//����i��Ԫ�ؼ�֮���Ԫ�غ���
        L.data[j] = L.data[j-1];
    L.data[i] = e;              //��λ��i������i
    L.length++;                 //���ȼ�1
    return true;
}

//˳���Ļ�������--ɾ��
bool ListDelete(SqList &L, int i, int &e)//ע���������ò���e
{
    if(i<1 || i>L.length+1)     //�ж�i�ķ�Χ�Ƿ���Ч
        return false;
    e = L.data[i-1];            //����ɾ����ֵ��ֵ��e
    for(int j=i;j<L.length;j++) //����i��λ�ú����Ԫ��ǰ��
        L.data[j-1] = L.data[j];
    L.length--;                 //���Ա��ȼ�1
    return true;
}

int main()
{
    SqList L;                   //����һ��˳���
    InitList(L);                //��ʼ��һ��˳���
    //...��˳����в���Ԫ��... 
    int e = -1;                 //�ñ���e��ɾ����Ԫ�ء���������
    if(ListDelete(L, 3, e))
        printf("��ɾ����3��Ԫ�أ�ɾ����Ԫ��ֵΪ%d\n", e);
    else
        printf("λ��i���Ϸ���ɾ��ʧ��\n");
    return 0;
}



//**********************************************************//
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10             //Ĭ�ϵ����ĳ���
typedef struct{
    ElemType *data;                  //ָʾ��̬���������ָ��
    int MaxSize;                //˳�����������
    int length;                 //˳���ĵ�ǰ����
}SeqList;

//˳���İ�λ����
ElemType GetElem(SeqList L, int i)//�ͷ�����ͨ����һ��
{
    return L.data[i-1];
}

//˳���İ�ֵ����
int LocateElem(SeqList L, ElemType e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}