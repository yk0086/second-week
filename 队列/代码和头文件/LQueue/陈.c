#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sb.h"
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	/*����һ���ڴ���Ϊ�ս��*/
	Node* head = (Node*)malloc(sizeof(Node));
	/*��ʼ����ָ�붼ָ��ս��*/
	Q->front = Q->rear = head;
	/*��ʼ���ս��*/
	Q->front->next = NULL;
	/*���г���Ϊ0*/
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node* p;
	/*�����ƻ�ÿһ�����*/
	for(p=Q->front;p;p = Q->front ) {
		Q->front = Q->front->next;
		free(p);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	/*��βָ��ָ��ͬһ����㼴ͷ������Ϊ��*/
	if(Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	/*����Ϊ�վͲ����к������,���漸�������ͺ���������ͬ*/
	if (IsEmptyLQueue(Q)) {
		return FALSE;
	}
	/*�������ʱ��ÿ�����Ԫ�����͵ļ�¼�ж϶���Ԫ������,�����ʹ�С��ֵ������typeSize���ں��溯��ʹ��*/
	unsigned int typeSize;
	if(datatype[0] == 'i') {
		typeSize = sizeof(int);
		memcpy(e,Q->front->next->data,typeSize);
		printf("%d",*(int*)e);
	} else if(datatype[0] == 'd') {
		typeSize = sizeof(double);
		memcpy(e,Q->front->next->data,typeSize);
		printf("%lf",*(double*)e);
	} else if(datatype[0] == 'c') {
		typeSize = sizeof(char);
		memcpy(e,Q->front->next->data,typeSize);
		printf("%c",*(char*)e);
	} else {
		typeSize = sizeof(Q->front->next->data);
		memcpy(e,Q->front->next->data,typeSize);
		printf("%s",(char*)e);
	}
	/*���ڶ������������ݸ����ڵ�һ���������ڴ���*/
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	/*���ض��г���(������ͷ���)*/
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	/*Ԫ�����ǰ���ж��Ƿ����ڴ�����������Ϊ���*/
	Node *p = (Node*)malloc(sizeof(Node));
	if(!p){ 
		return FALSE;
	}
	/*Ϊ����е�Ԫ�ص�ָ������һ���ڴ�*/
	p->data = (void*)malloc(21);
	/*��Ҫ����Ԫ��ָ��ԭ�ⲻ�����Ƹ����Ԫ��ָ��*/
	memcpy(p->data, data, 20);
	/*��ʼ��*/
	p->next = NULL;
	/*���*/
	Q->rear->next = p;
	/*βָ���ƶ�*/
	Q->rear = p;
	/*�ӳ���1*/
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node* p;
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	/*ͷ��ɾ���ſ����ҵ���һ�����*/
	p = Q->front->next;
	/*��ָ���ƶ�*/
	Q->front->next = p->next;
	/*����ɾ�����Ƕ�������һ�����*/
	if(Q->rear == p){
		/*��Ҫ��β���ָ���ָ��*/
		Q->rear = Q->front;
	}
	/*datatype���е�λ����*/
	/*
	int i;
	for(i = 29; i; i--){
		datatype[i-1] = datatype[i];
	}
	*/
	free(p);
	/*�ӳ���1*/
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node* p;
	/*����������ɾ����һ��ͷ���*/
	for(p=Q->front->next;p;p = p->next ) {
		free(p);
		Q->length--;
	}
	/*��ɳ�ʼ����տ�ʼ������*/
	Q->rear = Q->front;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	Node* p; 
	if (IsEmptyLQueue(Q)) {
		return FALSE;
	}
	
	for(p=Q->front->next;p;p = p->next){
		foo(p->data);
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	static pprint = 0;
	if(datatype[pprint] == 'i') {
		printf("%d  ",*(int*)q);
		pprint++;
	} else if(datatype[pprint] == 'd') {
		printf("%.2f  ",*(double*)q);
		pprint++;
	} else if(datatype[pprint] == 'c') {
		printf("%c  ",*(char*)q);
		pprint++;
	}
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
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED

