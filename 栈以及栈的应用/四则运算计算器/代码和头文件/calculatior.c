    #include <stdio.h>
    #include<malloc.h>
    #include<math.h>
    {
	printf("该操作需要将原先的栈销毁,是否进行该操作?\n");
	printf("请输入1/0代表YES/NO\n");
	choice = GetNumber();
	if(choice == 1){
		if(flag){
			destroyLStack(&S);
			printf("已经销毁原栈\n正在创建新栈\n");
			initLStack(&S);
		}
		else{
			printf("正在创建新栈\n");
			initLStack(&S);
		}
		system("pause");
		printf("创建成功\n请输入期望表达式的字符个数:");
		CharNum = GetNumber();
		s1 = (char*)malloc(sizeof(char)*CharNum);
		s2 = (char*)malloc(sizeof(char)*CharNum);
		printf("请输入表达式:");
		gets(s1);
		puts(s1);
		Status StringTrans(s1, s2, &S);
		puts(s2);
		break;
	}else if(choice == 0){
		printf("已返回对原栈不作任何改动\n");
		break;
	}else{
		printf("输入非法!\n请重新输入要求内容!\n");
		break;
	}
	//将中缀表达式转化为后缀表达式 
Status StringTrans(char *s1, char *s2, LinkStack *s)
{
	int i, j = 0;
	for(i=0;s1[i]!='0';i++){
		if(s[i]>='0'||s[i]<='9')
		{
			s2[j++] = s1[i];
		}
		else if(s[i] == '(')
		{
			pushLStack(&s,s[i]);
		}
		else if(s[i] == ')')
		{
			
		}
	}
}
