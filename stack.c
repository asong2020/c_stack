/**************************************************
***************************************************
***************************************************
*****************栈学习测试代码*****************
***************************************************
***************************************************/

/*头文件引入*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef enum
 {false = 0, true = 1} bool;


/*结构体定义    
s_Data 栈中数据
s_Top 指针指向栈顶
s_Bottom 指针指向栈底
s_Next 指针指向上一节点
*/
typedef struct StackStur
{
    int s_Data;
    struct StackStur* s_Top;
	struct StackStur* s_Bottom;
	struct StackStur* s_Next;

}NonPointer,*Pointer;

/*********************函数声明******************/

void CreateStack(Pointer variable);
void PushStack(Pointer variable,int value);
void PopStack(Pointer variable,int *value);
bool StackEmpty(Pointer variable);
void StackTraver(Pointer variable);
void StackClear(Pointer variable);

int main(int argc,char * argv[])
{ 
	NonPointer Master;
	int masterVaule=0;
    CreateStack(&Master);
    StackEmpty(&Master);
    PushStack(&Master,1000);
    PushStack(&Master,2000);
	PushStack(&Master,3000);
	PushStack(&Master,4000);
	PushStack(&Master,5000);
	PushStack(&Master,6000);
    StackEmpty(&Master);
    StackTraver(&Master);
    PopStack(&Master,&masterVaule);
	StackTraver(&Master);
	StackClear(&Master);
	StackTraver(&Master);

	return 0;
}

/*创建一个空栈*/
void CreateStack(Pointer variable)
{
	variable->s_Bottom=(Pointer)malloc(sizeof(NonPointer));
    if(NULL==variable->s_Bottom)    //判断内存是否分配成功
	{
		printf("Error in allocating memory!\r\n");
	    exit(-1);
	}
    variable->s_Top=variable->s_Bottom;
    variable->s_Data=0;
    variable->s_Top->s_Next=NULL;   //定义为空 防止出现野指针
	printf("Create the stack sucessful!");
}

/*入栈函数*/
void PushStack(Pointer variable,int value)
{
	Pointer s_storage=(Pointer)malloc(sizeof(NonPointer));
    if(NULL==s_storage)    //判断内存是否分配成功
	{
		printf("Error in allocating memory!\r\n");
	    exit(-1);
	}
	s_storage->s_Next=variable->s_Top; //修改节点的指针域
    s_storage->s_Data=value;
    variable->s_Top=s_storage;   //修改栈顶指针，使其指向栈顶元素
    printf("Push to stack sucessful!\r\n");
	printf("The Value is %d\r\n",s_storage->s_Data);

}


/*出栈函数*/
void PopStack(Pointer variable,int *value)
{

    Pointer s_Popstorage=variable->s_Top;  //    建立一个临时节点指向栈顶节点
	if(variable->s_Bottom==variable->s_Top)//    判断栈是否为空
	{
		printf("Pop Stack Fail Stack is NULL!\r\n");
	}
    *value=s_Popstorage->s_Data;//    把栈顶节点元素弹出，地址放到变量value中
    variable->s_Top=s_Popstorage->s_Next; //    把栈顶指针指向上一个栈节点
    free(s_Popstorage);   //    释放节点内存，防止内存空间泄漏
    s_Popstorage=NULL;   //    防止产生野指针
	printf("The %d Pop stack!\r\n",*value);

}

//    定义判断栈是否为空函数
bool StackEmpty(Pointer variable)
{
	if(variable->s_Top==variable->s_Bottom)
	{
		printf("The stack is empty!\r\n");
		return true;
	}
	else
		return false;
}


/*定义遍历栈 函数*/
void StackTraver(Pointer variable)
{
	Pointer s_Traver=variable->s_Top;  //    建立一个临时节点指针，初始化时指向栈顶
    if(StackEmpty(variable))
	{
		printf("Traversing the stack is fail!\r\n");
		exit(-1);
	}
	while(s_Traver!=variable->s_Bottom)
	{
		printf("Traver result is %d\r\n",s_Traver->s_Data);
		s_Traver=s_Traver->s_Next;
	}
}
/*栈清空函数*/
void StackClear(Pointer variable)
{
    Pointer s_start=variable->s_Top;
    Pointer s_end=NULL;
    if(StackEmpty(variable))
	{
		printf("Clear the stack is fail!\r\n");
		exit(-1);
	}
	while(s_start!=variable->s_Bottom)
	{
		s_end=s_start->s_Next;
		free(s_start);
        s_start=s_end;        
	}
    variable->s_Bottom=variable->s_Top;
	printf("The Stack is clear!\r\n");
}