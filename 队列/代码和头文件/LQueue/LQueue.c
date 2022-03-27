#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *temp;
	if(Q->front == NULL && Q->rear == NULL ){
		//申请一块内存作为头结点 
		temp = (Node*)malloc(sizeof(struct node));
		//申请到了 
		if(temp){
			temp->data = NULL;
			temp->next = NULL;
			Q->front = Q->rear = temp;
			Q->length = 0;
		}
		else printf("内存不足\n");
	}
	else printf("已经存在队列\n");
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
	//删掉头结点 
	free(Q->front);
	printf("销毁成功\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->rear - Q->front == 0) return TRUE;
	else return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
//将元素的指针赋值给结点中指向存储元素的指针是不可取的,
//因为元素指针是会变的,导致全部结点中存储元素的指针都指向同一个值 
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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
		printf("输入非法!\n请重新输入要求内容!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
