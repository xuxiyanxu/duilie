#include "LQueue.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
Q->front=Q->rear=(Node*)malloc(sizeof(Node));   //Ϊͷβָ������ڴ�
if (!Q->front)
printf("�ڴ����ʧ�ܣ��������²���");
Q->front->next=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
Q->rear=Q->front->next;
free(Q->front);
Q->front=Q->rear;    //�ͷ�һ���ڴ�Ҫ�����㣺1.�ͷ�ָ������ָ�롣2.����ָ��ָ���
}
/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
if(Q->front==Q->rear)
return TRUE;
else 
return FALSE;
}
/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
if(Q->front==Q->rear)          //�ж϶����Ƿ�Ϊ��
return FALSE;
e=Q->front->data;                   //��e���ض�ͷԪ�ص�ֵ
return e;
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
int length=0;
Node *temp;                            //����һ������temp
temp=Q->front;                    //temp��ͷָ��һֱ�ƶ���βָ�룬���ȼ�һ���ƶ�����һ�����λ��
while (temp!=Q->rear)
{
++length;
temp=temp->next;
}              
return length;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{ 
Node *s=(Node)malloc(sizeof(Node));
if (!s)
return FALSE;
s->data=data;
s->next=0;              //���½��s��ֵ��ԭ��β���ĺ��
Q->rear->next=s;
Q->rear=s;
return TRUE;            //����ǰ��s����Ϊ��β��㣬rearָ��s
}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
if (Q->front==Q->rear)
return FALSE;
Node p;
p=Q->front->next;                  //��Ҫ��ɾ���Ķ�ͷ����ݴ��p
Q->front->next=p->next;              //��ԭ��ͷ�����p->next��ֵ��ͷ�����
if (Q->rear==p)
Q->rear=Q->front;                    //����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
free (p);
return TURE;
}
/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Q->front=Q->rear;    //ͷָ���βָ��ָ��һ���ط�
	Q->front->next=0;           
}
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
if (Q->front==Q->rear)              //�ж϶����Ƿ�Ϊ��
printf("�ö���Ϊ��\n");
Node *temp=Q->front;
printf("�����������\n");
while (temp!=Q->rear)             //������������е���
{
temp=temp.next;
printf("%d",temp.data);
}
printf("\n");
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q);



