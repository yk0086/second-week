#include <stdio.h>
#include <stdlib.h>
#include "calculatior.h"
//将中缀表达式转化为后缀表达式 
//没有小数没有负数 
Status StringTrans(char *s1, char *s2, LinkStack *s)
{
	int i, j = 0;
	char *laji;
	
	for(i=0;s1[i]!='\0';i++){
		/*遇到运算数直接输出*/
		if(s1[i]>='0'&&s1[i]<='9')
		{
			s2[j++] = s1[i];
		}
		/*左括号压栈*/
		else if(s1[i] == '(')
		{
			pushLStack(s,s1[i]);
		}
		/*右括号将左括号之前的包括左括号全部出栈*/
		else if(s1[i] == ')')
		{
			while(s1[i]!='('){
				/*右括号不输出*/
				i++;
				popLStack(s,&s2[j++]);
			}
			/*左括号不输出*/
			popLStack(s,laji);
		}
		/*运算符比较优先级*/
		else if(s1[i] == '+'||s1[i] == '-'||s1[i] == '*'||s1[i] == '/'){
			char *e;
			getTopLStack(s,e);
			printf("%c",*e);
			/*优先级小于栈顶,弹出并输出,直到运算符大于栈顶*/
			if(!isEmptyLStack(s)){
				while(judgePriority(*e,s1[i])==-1){
					popLStack(s,&s2[j++]);
				}
			}
			pushLStack(s,s1[i]);
		}
		else {
			;
		}
	}
	while(!isEmptyLStack(s)){
		popLStack(s,&s2[j++]);
	}
}
Status initLStack(LinkStack *s)
{
	LinkStackPtr temp;
	if(s->top == NULL){
		//申请一块内存作为头结点 
		temp = (LinkStackPtr)malloc(sizeof(struct StackNode));
		if(temp){
			temp->next = NULL;
			s->top = temp;
			s->top->cData = 0;
			s->count = 0;
			return SUCCESS;
		}
		else return ERROR;
	}
	else return ERROR;
}
Status isEmptyLStack(LinkStack *s)
{
	if(s->count == 0) return SUCCESS;
	else return ERROR;
}
Status pushLStack(LinkStack *s,char data)
{
	StackNode* temp = (StackNode*)malloc(sizeof(struct StackNode));
	if(temp){
		s->count++;
		temp->cData = data;
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
Status popLStack(LinkStack *s,char *data)
{
	StackNode* temp;
	if(isEmptyLStack(s)){
		return ERROR;
	}
	else{
		s->count--;
		temp = s->top->next;
		*data = temp->cData;
		s->top->next = temp->next;
		free(temp);
		return SUCCESS;
	}
}
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
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	StackNode* temp = s->top;
	s->top = NULL;
	free(temp);
}
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
Status getTopLStack(LinkStack *s,char *e){
	if(isEmptyLStack(s)){
		return ERROR;
	}
	*e = s->top->next->data;
	return SUCCESS;
}
int judgePriority(char a, char b)                  //判断符号优先级
{
    if((( a == '+'|| a == '-')&&(  b == '+'|| b == '-'))||((a == '*'||a == '/')&&(b == '*'||b == '/')))
        return 1;                                 //代表二者优先级相等
    else if((a == '+'||a == '-')&&(b == '*'||b == '/'))
        return 0;                                 //代表右边优先级高
    else
        return -1;                                 //代表左边优先级高
}

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
