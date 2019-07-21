/**************************************************
***************************************************
***************************************************
*****************ջѧϰ���Դ���*****************
***************************************************
***************************************************/

/*ͷ�ļ�����*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef enum
 {false = 0, true = 1} bool;


/*�ṹ�嶨��    
s_Data ջ������
s_Top ָ��ָ��ջ��
s_Bottom ָ��ָ��ջ��
s_Next ָ��ָ����һ�ڵ�
*/
typedef struct StackStur
{
    int s_Data;
    struct StackStur* s_Top;
	struct StackStur* s_Bottom;
	struct StackStur* s_Next;

}NonPointer,*Pointer;

/*********************��������******************/

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

/*����һ����ջ*/
void CreateStack(Pointer variable)
{
	variable->s_Bottom=(Pointer)malloc(sizeof(NonPointer));
    if(NULL==variable->s_Bottom)    //�ж��ڴ��Ƿ����ɹ�
	{
		printf("Error in allocating memory!\r\n");
	    exit(-1);
	}
    variable->s_Top=variable->s_Bottom;
    variable->s_Data=0;
    variable->s_Top->s_Next=NULL;   //����Ϊ�� ��ֹ����Ұָ��
	printf("Create the stack sucessful!");
}

/*��ջ����*/
void PushStack(Pointer variable,int value)
{
	Pointer s_storage=(Pointer)malloc(sizeof(NonPointer));
    if(NULL==s_storage)    //�ж��ڴ��Ƿ����ɹ�
	{
		printf("Error in allocating memory!\r\n");
	    exit(-1);
	}
	s_storage->s_Next=variable->s_Top; //�޸Ľڵ��ָ����
    s_storage->s_Data=value;
    variable->s_Top=s_storage;   //�޸�ջ��ָ�룬ʹ��ָ��ջ��Ԫ��
    printf("Push to stack sucessful!\r\n");
	printf("The Value is %d\r\n",s_storage->s_Data);

}


/*��ջ����*/
void PopStack(Pointer variable,int *value)
{

    Pointer s_Popstorage=variable->s_Top;  //    ����һ����ʱ�ڵ�ָ��ջ���ڵ�
	if(variable->s_Bottom==variable->s_Top)//    �ж�ջ�Ƿ�Ϊ��
	{
		printf("Pop Stack Fail Stack is NULL!\r\n");
	}
    *value=s_Popstorage->s_Data;//    ��ջ���ڵ�Ԫ�ص�������ַ�ŵ�����value��
    variable->s_Top=s_Popstorage->s_Next; //    ��ջ��ָ��ָ����һ��ջ�ڵ�
    free(s_Popstorage);   //    �ͷŽڵ��ڴ棬��ֹ�ڴ�ռ�й©
    s_Popstorage=NULL;   //    ��ֹ����Ұָ��
	printf("The %d Pop stack!\r\n",*value);

}

//    �����ж�ջ�Ƿ�Ϊ�պ���
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


/*�������ջ ����*/
void StackTraver(Pointer variable)
{
	Pointer s_Traver=variable->s_Top;  //    ����һ����ʱ�ڵ�ָ�룬��ʼ��ʱָ��ջ��
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
/*ջ��պ���*/
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