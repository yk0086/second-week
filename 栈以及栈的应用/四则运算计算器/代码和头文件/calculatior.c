    #include <stdio.h>
    #include<malloc.h>
    #include<math.h>
    {
	printf("�ò�����Ҫ��ԭ�ȵ�ջ����,�Ƿ���иò���?\n");
	printf("������1/0����YES/NO\n");
	choice = GetNumber();
	if(choice == 1){
		if(flag){
			destroyLStack(&S);
			printf("�Ѿ�����ԭջ\n���ڴ�����ջ\n");
			initLStack(&S);
		}
		else{
			printf("���ڴ�����ջ\n");
			initLStack(&S);
		}
		system("pause");
		printf("�����ɹ�\n�������������ʽ���ַ�����:");
		CharNum = GetNumber();
		s1 = (char*)malloc(sizeof(char)*CharNum);
		s2 = (char*)malloc(sizeof(char)*CharNum);
		printf("��������ʽ:");
		gets(s1);
		puts(s1);
		Status StringTrans(s1, s2, &S);
		puts(s2);
		break;
	}else if(choice == 0){
		printf("�ѷ��ض�ԭջ�����κθĶ�\n");
		break;
	}else{
		printf("����Ƿ�!\n����������Ҫ������!\n");
		break;
	}
	//����׺���ʽת��Ϊ��׺���ʽ 
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
