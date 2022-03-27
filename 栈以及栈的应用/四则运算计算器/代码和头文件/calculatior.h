#ifndef CALCULATIOR_H
#define CALCULATIOR_H
// 返回值结构体
typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

// 栈节点结构体
typedef  struct StackNode
{
	char cData;
	double data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

// 链栈
typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;

Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
void PrintStack(LinkStack *s);
int GetNumber();
void inputCheck(int *val);  //检查输入
Status checkString(char s[]); //检查字符串的正确
Status convertString(char s1[],char s2[],LinkStack *s); //将中缀表达式转化为后缀表达式
int judgePriority(char a, char b);// 判断符号优先级
double computeString(LinkStack *s1,char s[]);// 计算结果
#endif
