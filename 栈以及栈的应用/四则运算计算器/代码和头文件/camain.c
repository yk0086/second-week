#include <stdio.h>
#include <stdlib.h>
#include "calculatior.h"

int main(int argc, char *argv[]) {
	LinkStack S;
	S.top = NULL;
	char *c;
	
	int choice = 0, flag = 0, CharNum;
	//char *s1,*s2;
	char s1[100]={0};
	char s2[100]={0};
	
	printf("�ò�����Ҫ��ԭ�ȵ�ջ����,�Ƿ���иò���?\n");
	printf("������1/0����YES/NO\n");
	choice = GetNumber();
	if(choice == 1){
		if(flag){
			destroyLStack(&S);
			printf("�Ѿ�����ԭջ\n���ڴ�����ջ\n");
			initLStack(&S);
			flag = 1;
		}
		else{
			printf("���ڴ�����ջ\n");
			initLStack(&S);
			flag = 1;
		}
		system("pause");
		printf("�����ɹ�\n�������������ʽ���ַ�����:");
		CharNum = GetNumber();
		//s1 = (char*)malloc(sizeof(char)*CharNum);
		//s2 = (char*)malloc(sizeof(char)*CharNum);
		printf("��������ʽ:");
		gets(s1);
		//puts(s1);
		StringTrans(s1, s2, &S);
		puts(s2);
	}else if(choice == 0){
		printf("�ѷ��ض�ԭջ�����κθĶ�\n");
	}else{
		printf("����Ƿ�!\n����������Ҫ������!\n");
	}
	return 0;
}

