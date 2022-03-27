#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("------------------------\n");
    printf("1. ��ʼ������.          \n");
    printf("2. ���ٶ���.            \n");
    printf("3. �������Ƿ�Ϊ��.    \n");
    printf("4. �鿴��ͷԪ��.        \n");
    printf("5. ȷ�����г���.        \n");
    printf("6. ��Ӳ���.            \n");
    printf("7. ���Ӳ���.            \n");
    printf("8. ��ն���.            \n");
    printf("9. ��������.            \n");
    printf("10.�˳�                 \n");
    printf("------------------------\n");
    
	//flag�����ж��Ƿ������� 
	int flag = 0, length;
	LQueue Q;
	void *e, *data;
	Q.front = Q.rear = NULL;
	
	while(1){
		printf("���������:");
		switch(GetNumber()){
			case 1 :
				if(flag == 0){
					InitLQueue(&Q);
					printf("��ʼ���ɹ�\n");
					flag = 1;
				}
				else{
					printf("��ʼ��ʧ��\n");
				}
				break;
			case 2 :
				if(flag){
					DestoryLQueue(&Q);
					flag = 0;
				}
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 3 :
				if(flag){
					if(IsEmptyLQueue(&Q)){
						printf("����Ϊ��\n");
					}
					else{
						printf("���в���\n");
					}
				}
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 4 :
				if(flag){
					if(GetHeadLQueue(&Q, e));
					else{
						printf("����Ϊ��\n");
					}
				}
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 5 :
				if(flag){
					length = LengthLQueue(&Q);
					printf("���еĳ�����%d\n",length);
				}
				else{
					printf("����δ��ʼ��\n");
				}
			case 6 :
				if(flag){
					//void *GetData(LQueue *Q)
					{
						type t;
						printf("��������������ͣ�:\n");
					    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
					    t = GetNumber();
					    while(t<1 || t>4)
					    {
					     	printf("Ӧ������[1,4]֮���������\n�����䣺");
					      	scanf("%d", &t);
					    }
						printf("����ӵ����� :");
					    switch(t)
					    {
					     	case INT:{
								int a;
								scanf("%d", &a);
								//Q->type[Q->rear]=t;
								EnLQueue(&Q, &a);
								break;
							}
							case CHAR: {
								char a ;
								scanf("%c", &a);
								//Q->type[Q->rear]=t;
								EnLQueue(&Q, &a);
								break;
							}
					        case DOUBLE:{
								double a ;
								scanf("%lf", &a);
								//Q->type[Q->rear]=t;
								EnLQueue(&Q, &a);
								break;
							}
					        case STRING:{
								char a[20];
								printf("��󳤶�Ϊ20Ŷ��\n");
								scanf("%s", a);
								Q->type[Q->rear]=t;
								EnLQueue(&Q, a);
								break;
							} 
						}
					}
				}
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 7 :
				if(flag){
					if(DeLQueue(&Q)){
						printf("Ԫ���ѳ���\n");
					}
					else{
						printf("��ջ\n");
					}
				} 
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 9 :
				if(flag){
					TraverseLQueue(&Q, foo);
				}
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 10 :
				exit(0);
			default :
				printf("����Ƿ�!\n����������Ҫ������!\n");	
				break;
		}
	}
}
