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
			
		case 'a':printf("�����г�ʼ��\n");         //���г�ʼ������
			InitAQueue(&Q);
			print();
			printf("\n");
			break;
		case'b':if(IsEmptyAQueue(&Q))              //�ж��Ƿ�Ϊ�ն���
					printf("�ǿն���");
			else printf("���ǿն���");
			print();
			printf("\n");
			break;
		case'c':if(IsFullAQueue(&Q))               //�ж��Ƿ�Ϊ������
					printf("��������");
			else printf("����δ��");
			print();
			printf("\n");
			break;
		case'd':ClearAQueue(&Q);              //��ն���
			print();
			printf("\n");
			break;
		case'e':DestoryAQueue(&Q);          //���ٶ���
			print();
			printf("\n");
			break;
		case'f':printf("���г���Ϊ%d",LengthAQueue(&Q));     //����г���
			print();
			printf("\n");
			break;
		case'g':printf("������Ҫ��ӵ�Ԫ��");                 //���
			scanf("%d",i);
			if(EnAQueue(&Q, data))
				printf("��ӳɹ�");
			else
				printf("���ʧ��");
			print();
			printf("\n");
			break;
		case'h':if(DeAQueue(&Q))                          //����
					printf("һ��Ԫ�س��ӳɹ�");
			else printf("����һ���ն���");
			print();
			printf("\n");
			break;
        case 'i':if (!GetHeadAQueue(&Q, &e))                      //�鿴��ͷԪ��
					 printf("����һ���ն���");
			printf("��ͷԪ��Ϊ%d",GetHeadAQueue(&Q, e));
			print();
			break;
		case'j':
			TraverseAQueue(&Q, q); 
			print();
			break;                              //��ӡ���е���
		default: printf("�Ƿ�����");
			print();
		}
	}
}
void print()
{
	printf("-------------------------------\n");
	printf(" �������Ӧ��ĸ��������ز���  \n");
	printf("-------------------------------\n");
	printf("a->���г�ʼ��                  \n");
	printf("b->�ж϶����Ƿ�Ϊ��            \n");
	printf("c->�ж϶����Ƿ�Ϊ��            \n");
	printf("d->��ն���                    \n");
	printf("e->���ٶ���                    \n");
	printf("f->���ջ����                  \n");
	printf("g->����Ԫ����ջ                \n");
	printf("h->ʹջ��Ԫ�س�ջ              \n");
	printf("i->�鿴��ͷԪ��                \n");
	printf("j->���δ�ӡ�����������        \n");
	printf("k->�˳�                        \n");
}
























