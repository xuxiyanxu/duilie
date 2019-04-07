#include "AQueue.h"
#include "AQueue.c"
#include <stdio.h>
#include <stdlib.h>
void main()
{
	void print();
	char choice;
	void *data,*e,*q;
	int *i;
	void APrint(void);
	AQueue Q;
	data=i;
	while (1)
	{
		choice = getchar();
		while (getchar() != '\n')
			continue;
		if (choice == 'k')
			break;
		switch(choice)
		{
			
		case 'a':printf("将队列初始化\n");         //队列初始化操作
			InitAQueue(&Q);
			print();
			printf("\n");
			break;
		case'b':if(IsEmptyAQueue(&Q))              //判断是否为空队列
					printf("是空队列");
			else printf("不是空队列");
			print();
			printf("\n");
			break;
		case'c':if(IsFullAQueue(&Q))               //判断是否为满队列
					printf("队列已满");
			else printf("队列未满");
			print();
			printf("\n");
			break;
		case'd':ClearAQueue(&Q);              //清空队列
			print();
			printf("\n");
			break;
		case'e':DestoryAQueue(&Q);          //销毁队列
			print();
			printf("\n");
			break;
		case'f':printf("队列长度为%d",LengthAQueue(&Q));     //求队列长度
			print();
			printf("\n");
			break;
		case'g':printf("请输入要入队的元素");                 //入队
			scanf("%d",i);
			if(EnAQueue(&Q, data))
				printf("入队成功");
			else
				printf("入队失败");
			print();
			printf("\n");
			break;
		case'h':if(DeAQueue(&Q))                          //出队
					printf("一个元素出队成功");
			else printf("这是一个空队列");
			print();
			printf("\n");
			break;
        case 'i':if (!GetHeadAQueue(&Q, &e))                      //查看队头元素
					 printf("这是一个空队列");
			printf("队头元素为%d",GetHeadAQueue(&Q, e));
			print();
			break;
		case'j':
			TraverseAQueue(&Q, q); 
			print();
			break;                              //打印队列的数
		default: printf("非法输入");
			print();
		}
	}
}
void print()
{
	printf("-------------------------------\n");
	printf(" 请输入对应字母来进行相关操作  \n");
	printf("-------------------------------\n");
	printf("a->队列初始化                  \n");
	printf("b->判断队列是否为空            \n");
	printf("c->判断队列是否为满            \n");
	printf("d->清空队列                    \n");
	printf("e->销毁队列                    \n");
	printf("f->检测栈长度                  \n");
	printf("g->输入元素入栈                \n");
	printf("h->使栈顶元素出栈              \n");
	printf("i->查看队头元素                \n");
	printf("j->依次打印队列里面的数        \n");
	printf("k->退出                        \n");
}
























