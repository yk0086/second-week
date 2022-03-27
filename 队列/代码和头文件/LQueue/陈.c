#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sb.h"
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	/*申请一块内存作为空结点*/
	Node* head = (Node*)malloc(sizeof(Node));
	/*开始两个指针都指向空结点*/
	Q->front = Q->rear = head;
	/*初始化空结点*/
	Q->front->next = NULL;
	/*队列长度为0*/
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node* p;
	/*遍历破坏每一个结点*/
	for(p=Q->front;p;p = Q->front ) {
		Q->front = Q->front->next;
		free(p);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	/*首尾指针指向同一个结点即头结点队列为空*/
	if(Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	/*队列为空就不进行后面操作,后面几个操作型函数道理相同*/
	if (IsEmptyLQueue(Q)) {
		return FALSE;
	}
	/*根据入队时对每个结点元素类型的记录判断队首元素类型,将类型大小赋值给变量typeSize用于后面函数使用*/
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
	/*将第二个参数的内容复制在第一个参数的内存里*/
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	/*返回队列长度(不包括头结点)*/
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	/*元素入队前先判断是否有内存容许申请作为结点*/
	Node *p = (Node*)malloc(sizeof(Node));
	if(!p){ 
		return FALSE;
	}
	/*为结点中的元素的指针申请一块内存*/
	p->data = (void*)malloc(21);
	/*将要插入元素指针原封不动复制给结点元素指针*/
	memcpy(p->data, data, 20);
	/*初始化*/
	p->next = NULL;
	/*入队*/
	Q->rear->next = p;
	/*尾指针移动*/
	Q->rear = p;
	/*队长加1*/
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node* p;
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	/*头部删除才可以找到下一个结点*/
	p = Q->front->next;
	/*首指针移动*/
	Q->front->next = p->next;
	/*假设删除的是队里的最后一个结点*/
	if(Q->rear == p){
		/*就要让尾结点指向空指针*/
		Q->rear = Q->front;
	}
	/*datatype所有单位左移*/
	/*
	int i;
	for(i = 29; i; i--){
		datatype[i-1] = datatype[i];
	}
	*/
	free(p);
	/*队长减1*/
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node* p;
	/*比起销毁少删除了一个头结点*/
	for(p=Q->front->next;p;p = p->next ) {
		free(p);
		Q->length--;
	}
	/*变成初始化后刚开始的样子*/
	Q->rear = Q->front;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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
		printf("输入非法!\n请重新输入要求内容!\n");
		scanf("%d",&num);
		judge = getchar();
	}
	return num;
}
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED

