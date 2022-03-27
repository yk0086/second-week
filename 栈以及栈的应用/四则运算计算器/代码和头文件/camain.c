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
	
	printf("该操作需要将原先的栈销毁,是否进行该操作?\n");
	printf("请输入1/0代表YES/NO\n");
	choice = GetNumber();
	if(choice == 1){
		if(flag){
			destroyLStack(&S);
			printf("已经销毁原栈\n正在创建新栈\n");
			initLStack(&S);
			flag = 1;
		}
		else{
			printf("正在创建新栈\n");
			initLStack(&S);
			flag = 1;
		}
		system("pause");
		printf("创建成功\n请输入期望表达式的字符个数:");
		CharNum = GetNumber();
		//s1 = (char*)malloc(sizeof(char)*CharNum);
		//s2 = (char*)malloc(sizeof(char)*CharNum);
		printf("请输入表达式:");
		gets(s1);
		//puts(s1);
		StringTrans(s1, s2, &S);
		puts(s2);
	}else if(choice == 0){
		printf("已返回对原栈不作任何改动\n");
	}else{
		printf("输入非法!\n请重新输入要求内容!\n");
	}
	return 0;
}

