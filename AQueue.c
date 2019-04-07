#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>
/**
*  @name        : void InitAQueue(AQueue *Q)
*    @description : ��ʼ������
*    @param         Q ����ָ��Q
*  @notice      : None
*/
void InitAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;   //ͷָ���βָ��ָ��ͬһ����Ԫ���Ҷ�Ϊ0
}
/**
*  @name        : void DestoryAQueue(AQueue *Q)
*    @description : ���ٶ���
*    @param         Q ����ָ��Q
*  @notice      : None
*/
void DestoryAQueue(AQueue *Q)
{
	while(Q->front!=Q->rear)
	{
		free(&Q->data[Q->front]);                 //��������ͷ�
		Q->front=(Q->front+1)%MAXQUEUE;           //ͷ��������һ����λ
	}		
}
/**
*  @name        : Status IsFullAQueue(const AQueue *Q)
*    @description : �������Ƿ�����
*    @param         Q ����ָ��Q
*    @return         : ��-TRUE; δ��-FALSE
*  @notice      : None
*/
Status IsFullAQueue(const AQueue *Q)
{
	if ( (Q->rear+1+MAXQUEUE)%MAXQUEUE==Q->front )   //βָ��ָ��ĵ�Ԫ�Ƿ�Ϊͷָ��ָ���ǰһ������������
		return TRUE;
	else return FALSE;
}

/**
*  @name        : Status IsEmptyAQueue(const AQueue *Q)
*    @description : �������Ƿ�Ϊ��
*    @param         Q ����ָ��Q
*    @return         : ��-TRUE; δ��-FALSE
*  @notice      : None
*/
Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->front==Q->rear)         //ͷβָ���Ƿ�ָ��ͬһ����Ԫ
		return TRUE;
	else return FALSE;
}
/**
*  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
*    @description : �鿴��ͷԪ��
*    @param         Q ����ָ��Q�����Ԫ��e
*    @return         : �ɹ�-TRUE; ʧ��-FALSE
*  @notice      : �����Ƿ��
*/
Status GetHeadAQueue(AQueue *Q, void *e)
{
	int *b;
	if (Q->front==Q->rear)          //���ж϶����Ƿ�Ϊ��
		return FALSE;
	b=Q->data[Q->front]; 
	e=b;                               //���в�Ϊ�գ���e���ض�ͷԪ��
	return e;
}
/**
*  @name        : int LengthAQueue(AQueue *Q)
*    @description : ȷ�����г���
*    @param         Q ����ָ��Q
*    @return         : ���г���count
*  @notice      : None
*/
int LengthAQueue(AQueue *Q)
{
	int count;
	count=Q->length;
return count;
}
/**
*  @name        : Status EnAQueue(AQueue *Q, void *data)
*    @description : ��Ӳ���
*    @param         Q ����ָ��Q,�������ָ��data
*    @return         : �ɹ�-TRUE; ʧ��-FALSE
*  @notice      : �����Ƿ����˻�Ϊ��
*/
Status EnAQueue(AQueue *Q, void *data)
{
	if ((Q->rear+1)%MAXQUEUE==Q->front)    //�ж϶����Ƿ�����
		return FALSE;
	Q->data[Q->rear]=data;                     //��data��ֵ����βָ��ָ��ĵ�Ԫ
	Q->rear=(Q->rear+1)%MAXQUEUE;          //��βָ�������һ����λ
	return TRUE;
}
/**
*  @name        : Status DeAQueue(AQueue *Q)
*    @description : ���Ӳ���
*    @param         Q ����ָ��Q
*    @return         : �ɹ�-TRUE; ʧ��-FALSE
*  @notice      : None
*/
Status DeAQueue(AQueue *Q)
{
	if (Q->front==Q->rear)               //�ж��Ƿ�Ϊ��
		return FALSE;
	Q->front=(Q->front+1)%MAXQUEUE;     //��ͷָ��ָ��ԭ����Ԫ����һ��λ��
	return TRUE;
}
/**
*  @name        : void ClearAQueue(Queue *Q)
*    @description : ��ն���
*    @param         Q ����ָ��Q
*  @notice      : None
*/
void ClearAQueue(AQueue *Q)
{
	int i=Q->front;
	while (i!=Q->rear)
	{
		Q->data[i]=0;           //����ʹ��ֵ����
		i++;
	}
	Q->front=Q->rear=0;        
}
/**
*  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
*    @description : ������������
*    @param         Q ����ָ��Q����������ָ��foo
*    @return         : None
*  @notice      : None
*/
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	void APrint(void *q);
			int q;
		if (Q->front==Q->rear)
		{
			printf("�ö���Ϊ��");
				return FALSE;
		}
		else 
			while(q!=Q->rear)
			{
				Aprint(q);
					q++;
			}
			return TRUE;
}
/**
*  @name        : void APrint(void *q)
*    @description : ��������
*    @param         q ָ��q
*  @notice      : None
*/
void APrint(void *q)
{
	printf("%d",q);
}

