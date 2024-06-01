//****************************************************//
//˫�����н�����͵�����
typedef struct DNode
{
    ElemType data;                      //������
    struct DNode *next, *prior;         //ǰ���ͺ��ָ��
}DNode, *DLinkList;

//˫����Ĳ���
//��p���֮�����s���
bool InsertNextDNode(DNode *p, DNode *s)
{
    if(p==NULL || s==NULL)              //�Ƿ�����
        return false;
    s->next = p->next;                  //��һ��
    if(p->next!=NULL)                   //���p����к������
        p->next->prior = s;             //�ڶ���
    s->prior = p;                       //������
    p->next = s;                        //���Ĳ�
    return true;
}


//****************************************************//
//˫�����ɾ��
//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode *p)
{
    if(p==NULL)
        return false;
    DNode *q = p->next;                 //�ҵ�p�ĺ�̽��q
    if(q==NULL)
        return false;                   //pû�к�̽��
    p->next = q->next;
    if(q->next!=NULL)                   //q��㲻�����һ�����
        q->next->prior = p;
    free(q);                            //�ͷŽ��ռ�
}




//****************************************************//
//˫����ı���

//�������
while(p!=NULL)
{
    //�Խ��p����Ӧ�������ӡ
    p = p->next;
}

//ǰ�����
while(p!=NULL)
{
    //�Խ��p����Ӧ����
    p = p->prior;
}

//ǰ�����������ͷ��㣩
while(p->prior!=NULL)
{
    //�Խ��p����Ӧ����
    p = p->prior;
}