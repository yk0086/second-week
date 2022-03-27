
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
int main()
{
    printf("------------------------\n");
    printf("1. 初始化栈.            \n");
    printf("2. 判断栈是否为空.      \n");
    printf("3. 得到栈顶元素.        \n");
    printf("4. 清空栈.              \n");
    printf("5. 销毁栈.              \n");
    printf("6. 检测栈长度.          \n");
    printf("7. 入栈.                \n");
    printf("8. 出栈.                \n");
    printf("9. 打印栈.              \n");
    printf("10.退出.                \n");
    printf("11.清屏.                \n");
    printf("------------------------\n");
    
	//flag用来判断是否有链表 
	int data, flag = 0, e, length, choice, CharNum;
	char *s1,*s2;
	LinkStack S;
	S.top = NULL;
	
	while(1){
		printf("请输入序号:");
		switch(GetNumber()){
			case 1 :
				if(initLStack(&S) && flag == 0){
					printf("初始化成功\n");
					flag = 1;
				}
				//已存在或无内存 
				else{
					printf("已经存在栈或者动态申请内存失败\n");
				}
				break;
			case 2 :
				if(flag){
					if(isEmptyLStack(&S)){
						printf("栈为空\n");
					}
					else{
						printf("栈不空\n");
					}
				}
				else printf("栈还未初始化无法进行操作\n");
				break;
			case 3 :
				if(flag){
					if(getTopLStack(&S,&e)){
						printf("栈顶元素是%d\n",e);
					}
					else{
						printf("空栈\n");
					}
				}
				else printf("栈还未初始化无法进行操作\n");
				break;
			case 4 :
				if(flag){
					if(clearLStack(&S)){
						printf("清空成功\n");
					}
					else{
						printf("空栈\n"); 
					}
				}
				else{
					printf("栈还未初始化无法进行操作\n");
				}
				break;
			case 5 :
				if(flag){
					if(destroyLStack(&S)){
						printf("销毁成功\n");
						flag = 0;
					}
					else{
						printf("销毁失败\n");
					}
				}
				else{
					printf("栈还未初始化无法进行操作\n");
				}
				break;
			case 6 :
				if(flag){
					if(LStackLength(&S,&length)){
						printf("栈长度为%d\n",length);
					}
					else{
						printf("获取失败\n");
					}
				}
				else{
					printf("栈还未初始化无法进行操作\n");
				}
				break;
			case 7 :
				if(flag){
					printf("请输入入栈元素:");
					data = GetNumber();
					if(pushLStack(&S,data)){
						printf("已入栈\n");
					}
					//可能是无法申请一块新的结点 
					else{
						printf("错误\n");
					}
				}
				else printf("栈还未初始化无法进行操作\n");
				break;
			case 8 :
				if(flag){
					if(popLStack(&S,&data)){
						printf("元素%d已出栈\n",data);
					}
					else{
						printf("错误\n"); 
					} 
				}
				else printf("栈还未初始化无法进行操作\n");
				break;
			case 9 :
				if(flag){
					PrintStack(&S);
				}
				else{
					printf("栈还未初始化或者已经销毁,需要重新初始化\n");
				}
				break;
			case 11 :
				system("cls");
				printf("------------------------\n");
			    printf("1. 初始化栈.            \n");
			    printf("2. 判断栈是否为空.      \n");
			    printf("3. 得到栈顶元素.        \n");
			    printf("4. 清空栈.              \n");
			    printf("5. 销毁栈.              \n");
			    printf("6. 检测栈长度.          \n");
			    printf("7. 入栈.                \n");
			    printf("8. 出栈.                \n");
			    printf("9. 打印栈.              \n");
			    printf("10.退出.                \n");
			    printf("11.清屏.                \n");
			    printf("------------------------\n");
				break;
			case 10 :
				exit (0);
			default :
				printf("输入非法!\n请重新输入要求内容!\n");
				break;
		}
	}
	
	return 0;
}
