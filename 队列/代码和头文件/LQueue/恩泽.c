#include<stdio.h>
#include<stdlib.h>
#include"sb.h"
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
	Q.front = Q.rear = NULL;
	void *e = malloc(21);
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
					printf("���ٳɹ�\n");
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
					if(GetHeadLQueue(&Q, e))
						;
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
	printf("��������������ͣ�����������ĸСд:\n");
    printf("int char double string\n");
    scanf("%c", &type);
    /*
    while(type!='i'&&type!='c'&&type!='d'&&type!='s')
    {
     	printf("�������\n�����䣺");
      	scanf("%c", &type);
    }*/
	printf("����ӵ����� :");
    switch(type)
    {
    	static i; 
     	case 'i':{
			int data;
			scanf("%d", &data);
			datatype[i++]=type;
			EnLQueue(&Q, &data);
			break;
		}
		case 'c': {
			char data;
			fflush(stdin);
			scanf("%c", &data);
			datatype[i++]=type;
			EnLQueue(&Q, &data);
			break;
		}
        case 'd':{
			double data ;
			scanf("%lf", &data);
			datatype[i++]=type;
			EnLQueue(&Q, &data);
			break;
		}
        case 's':{
			char data[20];
			printf("��󳤶�Ϊ20Ŷ��\n");
			scanf("%s", data);
			datatype[i++]=type;
			EnLQueue(&Q, data);
			break;
		}
}
//					if(EnLQueue(&Q, &data)){
//						printf("��ӳɹ�\n");
//					}
//					else{
//						printf("�޷������½ڵ�,���ʧ��\n");
//					}
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
						printf("����Ϊ��\n");
					}
				} 
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 8 :
				if(flag){
						printf("���������\n");
				}
				else{
					printf("����δ��ʼ��\n");
				}
				break;
			case 9 :
				if(flag){
					if(TraverseLQueue(&Q, LPrint))
						;
					else{
						printf("����Ϊ��\n");
					}
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
