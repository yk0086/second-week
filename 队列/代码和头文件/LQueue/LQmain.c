#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("------------------------\n");
    printf("1. 初始化队列.          \n");
    printf("2. 销毁队列.            \n");
    printf("3. 检查队列是否为空.    \n");
    printf("4. 查看队头元素.        \n");
    printf("5. 确定队列长度.        \n");
    printf("6. 入队操作.            \n");
    printf("7. 出队操作.            \n");
    printf("8. 清空队列.            \n");
    printf("9. 遍历队列.            \n");
    printf("10.退出                 \n");
    printf("------------------------\n");
    
	//flag用来判断是否有链表 
	int flag = 0, length;
	LQueue Q;
	void *e, *data;
	Q.front = Q.rear = NULL;
	
	while(1){
		printf("请输入序号:");
		switch(GetNumber()){
			case 1 :
				if(flag == 0){
					InitLQueue(&Q);
					printf("初始化成功\n");
					flag = 1;
				}
				else{
					printf("初始化失败\n");
				}
				break;
			case 2 :
				if(flag){
					DestoryLQueue(&Q);
					flag = 0;
				}
				else{
					printf("队列未初始化\n");
				}
				break;
			case 3 :
				if(flag){
					if(IsEmptyLQueue(&Q)){
						printf("队列为空\n");
					}
					else{
						printf("队列不空\n");
					}
				}
				else{
					printf("队列未初始化\n");
				}
				break;
			case 4 :
				if(flag){
					if(GetHeadLQueue(&Q, e));
					else{
						printf("队列为空\n");
					}
				}
				else{
					printf("队列未初始化\n");
				}
				break;
			case 5 :
				if(flag){
					length = LengthLQueue(&Q);
					printf("队列的长度是%d\n",length);
				}
				else{
					printf("队列未初始化\n");
				}
			case 6 :
				if(flag){
					//void *GetData(LQueue *Q)
					{
						type t;
						printf("你想入队哪种类型？:\n");
					    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
					    t = GetNumber();
					    while(t<1 || t>4)
					    {
					     	printf("应输入在[1,4]之间的整数！\n请重输：");
					      	scanf("%d", &t);
					    }
						printf("想入队的数据 :");
					    switch(t)
					    {
					     	case INT:{
								int a;
								scanf("%d", &a);
								//Q->type[Q->rear]=t;
								EnLQueue(&Q, &a);
								break;
							}
							case CHAR: {
								char a ;
								scanf("%c", &a);
								//Q->type[Q->rear]=t;
								EnLQueue(&Q, &a);
								break;
							}
					        case DOUBLE:{
								double a ;
								scanf("%lf", &a);
								//Q->type[Q->rear]=t;
								EnLQueue(&Q, &a);
								break;
							}
					        case STRING:{
								char a[20];
								printf("最大长度为20哦！\n");
								scanf("%s", a);
								Q->type[Q->rear]=t;
								EnLQueue(&Q, a);
								break;
							} 
						}
					}
				}
				else{
					printf("队列未初始化\n");
				}
				break;
			case 7 :
				if(flag){
					if(DeLQueue(&Q)){
						printf("元素已出队\n");
					}
					else{
						printf("空栈\n");
					}
				} 
				else{
					printf("队列未初始化\n");
				}
				break;
			case 9 :
				if(flag){
					TraverseLQueue(&Q, foo);
				}
				else{
					printf("队列未初始化\n");
				}
				break;
			case 10 :
				exit(0);
			default :
				printf("输入非法!\n请重新输入要求内容!\n");	
				break;
		}
	}
}
