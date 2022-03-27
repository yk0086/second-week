
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
int main()
{
    printf("------------------------\n");
    printf("1. ��ʼ��ջ.            \n");
    printf("2. �ж�ջ�Ƿ�Ϊ��.      \n");
    printf("3. �õ�ջ��Ԫ��.        \n");
    printf("4. ���ջ.              \n");
    printf("5. ����ջ.              \n");
    printf("6. ���ջ����.          \n");
    printf("7. ��ջ.                \n");
    printf("8. ��ջ.                \n");
    printf("9. ��ӡջ.              \n");
    printf("10.�˳�.                \n");
    printf("11.����.                \n");
    printf("------------------------\n");
    
	//flag�����ж��Ƿ������� 
	int data, flag = 0, e, length, choice, CharNum;
	char *s1,*s2;
	LinkStack S;
	S.top = NULL;
	
	while(1){
		printf("���������:");
		switch(GetNumber()){
			case 1 :
				if(initLStack(&S) && flag == 0){
					printf("��ʼ���ɹ�\n");
					flag = 1;
				}
				//�Ѵ��ڻ����ڴ� 
				else{
					printf("�Ѿ�����ջ���߶�̬�����ڴ�ʧ��\n");
				}
				break;
			case 2 :
				if(flag){
					if(isEmptyLStack(&S)){
						printf("ջΪ��\n");
					}
					else{
						printf("ջ����\n");
					}
				}
				else printf("ջ��δ��ʼ���޷����в���\n");
				break;
			case 3 :
				if(flag){
					if(getTopLStack(&S,&e)){
						printf("ջ��Ԫ����%d\n",e);
					}
					else{
						printf("��ջ\n");
					}
				}
				else printf("ջ��δ��ʼ���޷����в���\n");
				break;
			case 4 :
				if(flag){
					if(clearLStack(&S)){
						printf("��ճɹ�\n");
					}
					else{
						printf("��ջ\n"); 
					}
				}
				else{
					printf("ջ��δ��ʼ���޷����в���\n");
				}
				break;
			case 5 :
				if(flag){
					if(destroyLStack(&S)){
						printf("���ٳɹ�\n");
						flag = 0;
					}
					else{
						printf("����ʧ��\n");
					}
				}
				else{
					printf("ջ��δ��ʼ���޷����в���\n");
				}
				break;
			case 6 :
				if(flag){
					if(LStackLength(&S,&length)){
						printf("ջ����Ϊ%d\n",length);
					}
					else{
						printf("��ȡʧ��\n");
					}
				}
				else{
					printf("ջ��δ��ʼ���޷����в���\n");
				}
				break;
			case 7 :
				if(flag){
					printf("��������ջԪ��:");
					data = GetNumber();
					if(pushLStack(&S,data)){
						printf("����ջ\n");
					}
					//�������޷�����һ���µĽ�� 
					else{
						printf("����\n");
					}
				}
				else printf("ջ��δ��ʼ���޷����в���\n");
				break;
			case 8 :
				if(flag){
					if(popLStack(&S,&data)){
						printf("Ԫ��%d�ѳ�ջ\n",data);
					}
					else{
						printf("����\n"); 
					} 
				}
				else printf("ջ��δ��ʼ���޷����в���\n");
				break;
			case 9 :
				if(flag){
					PrintStack(&S);
				}
				else{
					printf("ջ��δ��ʼ�������Ѿ�����,��Ҫ���³�ʼ��\n");
				}
				break;
			case 11 :
				system("cls");
				printf("------------------------\n");
			    printf("1. ��ʼ��ջ.            \n");
			    printf("2. �ж�ջ�Ƿ�Ϊ��.      \n");
			    printf("3. �õ�ջ��Ԫ��.        \n");
			    printf("4. ���ջ.              \n");
			    printf("5. ����ջ.              \n");
			    printf("6. ���ջ����.          \n");
			    printf("7. ��ջ.                \n");
			    printf("8. ��ջ.                \n");
			    printf("9. ��ӡջ.              \n");
			    printf("10.�˳�.                \n");
			    printf("11.����.                \n");
			    printf("------------------------\n");
				break;
			case 10 :
				exit (0);
			default :
				printf("����Ƿ�!\n����������Ҫ������!\n");
				break;
		}
	}
	
	return 0;
}
