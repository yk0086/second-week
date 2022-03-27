#ifndef CALCULATIOR_H
#define CALCULATIOR_H
// ����ֵ�ṹ��
typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

// ջ�ڵ�ṹ��
typedef  struct StackNode
{
	char cData;
	double data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

// ��ջ
typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;

Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ
void PrintStack(LinkStack *s);
int GetNumber();
void inputCheck(int *val);  //�������
Status checkString(char s[]); //����ַ�������ȷ
Status convertString(char s1[],char s2[],LinkStack *s); //����׺���ʽת��Ϊ��׺���ʽ
int judgePriority(char a, char b);// �жϷ������ȼ�
double computeString(LinkStack *s1,char s[]);// ������
#endif
