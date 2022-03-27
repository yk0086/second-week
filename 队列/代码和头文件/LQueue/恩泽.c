#include<stdio.h>
#include<stdlib.h>
#include"sb.h"
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
	Q.front = Q.rear = NULL;
	void *e = malloc(21);
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
					printf("销毁成功\n");
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
					if(GetHeadLQueue(&Q, e))
						;
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
	printf("你想入队哪种类型？请输入首字母小写:\n");
    printf("int char double string\n");
    scanf("%c", &type);
    /*
    while(type!='i'&&type!='c'&&type!='d'&&type!='s')
    {
     	printf("输入错误\n请重输：");
      	scanf("%c", &type);
    }*/
	printf("想入队的数据 :");
    switch(type)
    {
    	static i; 
     	case 'i':{
			int data;
			scanf("%d", &data);
			datatype[i++]=type;
			EnLQueue(&Q, &data);
			break;
		}
		case 'c': {
			char data;
			fflush(stdin);
			scanf("%c", &data);
			datatype[i++]=type;
			EnLQueue(&Q, &data);
			break;
		}
        case 'd':{
			double data ;
			scanf("%lf", &data);
			datatype[i++]=type;
			EnLQueue(&Q, &data);
			break;
		}
        case 's':{
			char data[20];
			printf("最大长度为20哦！\n");
			scanf("%s", data);
			datatype[i++]=type;
			EnLQueue(&Q, data);
			break;
		}
}
//					if(EnLQueue(&Q, &data)){
//						printf("入队成功\n");
//					}
//					else{
//						printf("无法申请新节点,入队失败\n");
//					}
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
						printf("队列为空\n");
					}
				} 
				else{
					printf("队列未初始化\n");
				}
				break;
			case 8 :
				if(flag){
						printf("队列已清空\n");
				}
				else{
					printf("队列未初始化\n");
				}
				break;
			case 9 :
				if(flag){
					if(TraverseLQueue(&Q, LPrint))
						;
					else{
						printf("队列为空\n");
					}
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
