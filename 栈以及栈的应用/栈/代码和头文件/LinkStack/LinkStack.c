#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
//初始化栈
Status initLStack(LinkStack *s){
	//malloc返回的是一个void*所以并不能将整个结构malloc 
	LinkStackPtr temp;
	if(s->top == NULL){
		//申请一块内存作为头结点 
		temp = (LinkStackPtr)malloc(sizeof(struct StackNode));
		if(temp){
			temp->next = NULL;
			s->top = temp;
			s->count = 0;
			return SUCCESS;
		}
		else return ERROR;
	}
	else return ERROR;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->count == 0) return SUCCESS;
	else return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(isEmptyLStack(s)){
		return ERROR;
	}
	*e = s->top->next->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	//将结点全部丢掉
	/*
	if(isEmptyLStack(s)){
		return ERROR;
	}
	else{
		s->top->next = NULL;
		return SUCCESS;
	}
	*/
	StackNode* temp = s->top->next;
	if(isEmptyLStack(s)){
		return ERROR;
	}
	else{
		while(temp){
			s->top->next = temp->next;
			free(temp);
			temp = s->top->next;
		}
		s->count = 0;
		s->top->next = NULL;
		return SUCCESS;
	}
}

//销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	StackNode* temp = s->top;
	s->top = NULL;
	free(temp);
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	StackNode* temp = (StackNode*)malloc(sizeof(struct StackNode));
	if(temp){
		s->count++;
		temp->data = data;
		temp->next = NULL;
		if(isEmptyLStack(s)){
			s->top->next = temp;
		}
		else{
			temp->next = s->top->next;
			s->top->next = temp;
		}
		return SUCCESS;
	}
	//若无法申请结点 
	else return ERROR;	
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	StackNode* temp;
	if(isEmptyLStack(s)){
		return ERROR;
	}
	else{
		s->count--;
		temp = s->top->next;
		*data = temp->data;
		s->top->next = temp->next;
		free(temp);
		return SUCCESS;
	}	
}

/*负数情况*/
//输入序号 
int GetNumber()
{
	int num, judge, flag;

	flag = scanf("%d",&num);
	judge = getchar();
	while(judge != '\n'){ 
		fflush(stdin);
		printf("输入非法!\n请重新输入要求内容!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}

//打印栈 
void PrintStack(LinkStack *s)
{
	StackNode* temp = s->top->next;
	if(isEmptyLStack(s)){
		printf("空链表\n");
	}
	else{
		while(temp){
			printf("|%d",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

