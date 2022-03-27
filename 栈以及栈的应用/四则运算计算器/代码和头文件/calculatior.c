#include <stdio.h>
#include <stdlib.h>
#include "calculatior.h"
//����׺���ʽת��Ϊ��׺���ʽ 
//û��С��û�и��� 
Status StringTrans(char *s1, char *s2, LinkStack *s)
{
	int i, j = 0;
	char *laji;
	
	for(i=0;s1[i]!='\0';i++){
		/*����������ֱ�����*/
		if(s1[i]>='0'&&s1[i]<='9')
		{
			s2[j++] = s1[i];
		}
		/*������ѹջ*/
		else if(s1[i] == '(')
		{
			pushLStack(s,s1[i]);
		}
		/*�����Ž�������֮ǰ�İ���������ȫ����ջ*/
		else if(s1[i] == ')')
		{
			while(s1[i]!='('){
				/*�����Ų����*/
				i++;
				popLStack(s,&s2[j++]);
			}
			/*�����Ų����*/
			popLStack(s,laji);
		}
		/*������Ƚ����ȼ�*/
		else if(s1[i] == '+'||s1[i] == '-'||s1[i] == '*'||s1[i] == '/'){
			char *e;
			getTopLStack(s,e);
			printf("%c",*e);
			/*���ȼ�С��ջ��,���������,ֱ�����������ջ��*/
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
		//����һ���ڴ���Ϊͷ��� 
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
	//���޷������� 
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
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	StackNode* temp = s->top;
	s->top = NULL;
	free(temp);
}
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
Status getTopLStack(LinkStack *s,char *e){
	if(isEmptyLStack(s)){
		return ERROR;
	}
	*e = s->top->next->data;
	return SUCCESS;
}
int judgePriority(char a, char b)                  //�жϷ������ȼ�
{
    if((( a == '+'|| a == '-')&&(  b == '+'|| b == '-'))||((a == '*'||a == '/')&&(b == '*'||b == '/')))
        return 1;                                 //����������ȼ����
    else if((a == '+'||a == '-')&&(b == '*'||b == '/'))
        return 0;                                 //�����ұ����ȼ���
    else
        return -1;                                 //����������ȼ���
}

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
