#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
//��ʼ��ջ
Status initLStack(LinkStack *s){
	//malloc���ص���һ��void*���Բ����ܽ������ṹmalloc 
	LinkStackPtr temp;
	if(s->top == NULL){
		//����һ���ڴ���Ϊͷ��� 
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

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->count == 0) return SUCCESS;
	else return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(isEmptyLStack(s)){
		return ERROR;
	}
	*e = s->top->next->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	//�����ȫ������
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

//����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	StackNode* temp = s->top;
	s->top = NULL;
	free(temp);
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	*length = s->count;
	return SUCCESS;
}

//��ջ
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
	//���޷������� 
	else return ERROR;	
}

//��ջ
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

/*�������*/
//������� 
int GetNumber()
{
	int num, judge, flag;

	flag = scanf("%d",&num);
	judge = getchar();
	while(judge != '\n'){ 
		fflush(stdin);
		printf("����Ƿ�!\n����������Ҫ������!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}

//��ӡջ 
void PrintStack(LinkStack *s)
{
	StackNode* temp = s->top->next;
	if(isEmptyLStack(s)){
		printf("������\n");
	}
	else{
		while(temp){
			printf("|%d",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

