#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *temp;
	if(Q->front == NULL && Q->rear == NULL ){
		//����һ���ڴ���Ϊͷ��� 
		temp = (Node*)malloc(sizeof(struct node));
		//���뵽�� 
		if(temp){
			temp->data = NULL;
			temp->next = NULL;
			Q->front = Q->rear = temp;
			Q->length = 0;
		}
		else printf("�ڴ治��\n");
	}
	else printf("�Ѿ����ڶ���\n");
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *temp;
	void *data;
	temp = Q->front;
	while(!IsEmptyLQueue(&Q)){
		temp = Q->front->next;
		data = temp->data;
		Q->front->next = temp->next;
		free(data);
		free(temp);
	}
	//ɾ��ͷ��� 
	free(Q->front);
	printf("���ٳɹ�\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->rear - Q->front == 0) return TRUE;
	else return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(IsEmptyLQueue(&Q)){
		return FALSE;
	}
	else{
		printf("%s",Q->front->next->data);
		return TRUE;
	}
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	int length = 0;
	Node *temp = Q->front->next;
	while(temp){
		length++;
		temp = temp->next;
	}
	return length;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
//��Ԫ�ص�ָ�븳ֵ�������ָ��洢Ԫ�ص�ָ���ǲ���ȡ��,
//��ΪԪ��ָ���ǻ���,����ȫ������д洢Ԫ�ص�ָ�붼ָ��ͬһ��ֵ 
Status EnLQueue(LQueue *Q, void *data)
{
	Node *temp = (Node*)malloc(sizeof(struct node));
	if(temp)
	{
		memcpy(temp->data, data, 20);
		//temp->data = data;
		//Q->rear = (Q->rear + 1) % Q->length;
		Q->rear->next = temp;
		Q->rear = temp;
		return TRUE;
	}
    //memcpy(Q->data[Q->rear], data, 20);
	//Q->rear = (Q->rear + 1) % Q->length;
    return FALSE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *temp = Q->front->next;
	if(IsEmptyLQueue(&Q)){
		return FALSE; 
	}
	else{
		Q->front->next = temp->next;
		free(temp);
		return TRUE;
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	Node *temp = Q->front->next;
	if(IsEmptyLQueue(&Q)){
		return FALSE;
	}
	else{
		while(temp){
			foo(temp->data);
			temp = temp->next;
		}
		return TRUE;
	}
}
/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	void APrint(void *q, int typeData)
    {
        if(cflag)
            printf("--> %.2lf", *(double*)q);
        if(bflag)
            printf("--> %c", *(char*)q);
        if(aflag)
            printf("--> %d ", *(int*)q);
        if(dflag)
            printf("--> %s ", (char*)q);
    }
}
void foo(void *q){
	printf("%s<-",q);
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
