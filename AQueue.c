#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>
/**
*  @name        : void InitAQueue(AQueue *Q)
*    @description : 初始化队列
*    @param         Q 队列指针Q
*  @notice      : None
*/
void InitAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;   //头指针和尾指针指向同一个单元，且都为0
}
/**
*  @name        : void DestoryAQueue(AQueue *Q)
*    @description : 销毁队列
*    @param         Q 队列指针Q
*  @notice      : None
*/
void DestoryAQueue(AQueue *Q)
{
	while(Q->front!=Q->rear)
	{
		free(&Q->data[Q->front]);                 //结点依次释放
		Q->front=(Q->front+1)%MAXQUEUE;           //头结点向后移一个单位
	}		
}
/**
*  @name        : Status IsFullAQueue(const AQueue *Q)
*    @description : 检查队列是否已满
*    @param         Q 队列指针Q
*    @return         : 满-TRUE; 未满-FALSE
*  @notice      : None
*/
Status IsFullAQueue(const AQueue *Q)
{
	if ( (Q->rear+1+MAXQUEUE)%MAXQUEUE==Q->front )   //尾指针指向的单元是否为头指针指向的前一个，若是则满
		return TRUE;
	else return FALSE;
}

/**
*  @name        : Status IsEmptyAQueue(const AQueue *Q)
*    @description : 检查队列是否为空
*    @param         Q 队列指针Q
*    @return         : 空-TRUE; 未空-FALSE
*  @notice      : None
*/
Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->front==Q->rear)         //头尾指针是否指向同一个单元
		return TRUE;
	else return FALSE;
}
/**
*  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
*    @description : 查看队头元素
*    @param         Q 队列指针Q，存放元素e
*    @return         : 成功-TRUE; 失败-FALSE
*  @notice      : 队列是否空
*/
Status GetHeadAQueue(AQueue *Q, void *e)
{
	int *b;
	if (Q->front==Q->rear)          //先判断队列是否为空
		return FALSE;
	b=Q->data[Q->front]; 
	e=b;                               //队列不为空，用e返回队头元素
	return e;
}
/**
*  @name        : int LengthAQueue(AQueue *Q)
*    @description : 确定队列长度
*    @param         Q 队列指针Q
*    @return         : 队列长度count
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
*    @description : 入队操作
*    @param         Q 队列指针Q,入队数据指针data
*    @return         : 成功-TRUE; 失败-FALSE
*  @notice      : 队列是否满了或为空
*/
Status EnAQueue(AQueue *Q, void *data)
{
	if ((Q->rear+1)%MAXQUEUE==Q->front)    //判断队列是否满了
		return FALSE;
	Q->data[Q->rear]=data;                     //将data的值赋给尾指针指向的单元
	Q->rear=(Q->rear+1)%MAXQUEUE;          //将尾指针向后移一个单位
	return TRUE;
}
/**
*  @name        : Status DeAQueue(AQueue *Q)
*    @description : 出队操作
*    @param         Q 队列指针Q
*    @return         : 成功-TRUE; 失败-FALSE
*  @notice      : None
*/
Status DeAQueue(AQueue *Q)
{
	if (Q->front==Q->rear)               //判断是否为空
		return FALSE;
	Q->front=(Q->front+1)%MAXQUEUE;     //将头指针指向原来单元的下一个位置
	return TRUE;
}
/**
*  @name        : void ClearAQueue(Queue *Q)
*    @description : 清空队列
*    @param         Q 队列指针Q
*  @notice      : None
*/
void ClearAQueue(AQueue *Q)
{
	int i=Q->front;
	while (i!=Q->rear)
	{
		Q->data[i]=0;           //依次使数值清零
		i++;
	}
	Q->front=Q->rear=0;        
}
/**
*  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
*    @description : 遍历函数操作
*    @param         Q 队列指针Q，操作函数指针foo
*    @return         : None
*  @notice      : None
*/
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	void APrint(void *q);
			int q;
		if (Q->front==Q->rear)
		{
			printf("该队列为空");
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
*    @description : 操作函数
*    @param         q 指针q
*  @notice      : None
*/
void APrint(void *q)
{
	printf("%d",q);
}

