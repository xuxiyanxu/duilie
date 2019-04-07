#include "LQueue.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
Q->front=Q->rear=(Node*)malloc(sizeof(Node));   //为头尾指针分配内存
if (!Q->front)
printf("内存分配失败，建议重新操作");
Q->front->next=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
Q->rear=Q->front->next;
free(Q->front);
Q->front=Q->rear;    //释放一块内存要做两点：1.释放指向它的指针。2.将该指针指向空
}
/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
if(Q->front==Q->rear)          //判断队列是否为空
return FALSE;
e=Q->front->data;                   //用e返回队头元素的值
return e;
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
int length=0;
Node *temp;                            //定义一个变量temp
temp=Q->front;                    //temp从头指针一直移动到尾指针，长度加一后移动到下一个结点位置
while (temp!=Q->rear)
{
++length;
temp=temp->next;
}              
return length;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{ 
Node *s=(Node)malloc(sizeof(Node));
if (!s)
return FALSE;
s->data=data;
s->next=0;              //将新结点s赋值给原队尾结点的后继
Q->rear->next=s;
Q->rear=s;
return TRUE;            //将当前的s设置为队尾结点，rear指向s
}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
if (Q->front==Q->rear)
return FALSE;
Node p;
p=Q->front->next;                  //将要被删除的队头结点暂存给p
Q->front->next=p->next;              //将原队头结点后继p->next赋值给头结点后继
if (Q->rear==p)
Q->rear=Q->front;                    //若队头是队尾，则删除后将rear指向头结点
free (p);
return TURE;
}
/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Q->front=Q->rear;    //头指针和尾指针指向一个地方
	Q->front->next=0;           
}
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
if (Q->front==Q->rear)              //判断队列是否为空
printf("该队列为空\n");
Node *temp=Q->front;
printf("队列输出如下\n");
while (temp!=Q->rear)             //依次输出队列中的数
{
temp=temp.next;
printf("%d",temp.data);
}
printf("\n");
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q);



