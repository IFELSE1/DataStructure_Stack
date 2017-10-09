/**
  ******************************************************************************
  * @file      LinkStack.c
  * @author    青椒san
  * @version   V1.0
  * @date      2017-10-9
  * @brief     栈的链式存储结构相关操作的C语言实现
  *
  ******************************************************************************
  * @attention
  *  参照《大话数据结构》栈和队列 章节
  *
  ******************************************************************************
  */
  
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
 
/* Private define ------------------------------------------------------------*/

/**
  * @brief 
  */
#define  TRUE   1
#define  FALSE  0   
/* Private typedef -----------------------------------------------------------*/

/**
  * @brief 定义 SElem_TypeDef 的类型为int型
  */
typedef int SElem_TypeDef;

/**
  * @brief 定义栈结构的结构体
  */
typedef struct{
	SElem_TypeDef data[MAXSIZE];
	int top;                   /* 用于栈顶指示 */
}SqStack_TypeDef;
/**
  * @brief 定义函数的返回值状态
  */
typedef enum{
	FUN_OK,
	FUN_ERROR
}FUN_Status_TypeDef;
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/




/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/

/**
  * @brief 	建立一个空的栈
  * @param  sqstack:栈指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqStack_Init(SqStack_TypeDef *sqstack)
{
	int i;
	for (i=0;i<MAXSIZE;i++){
		sqstack->data[i] = 0x00;
	}
	/* 空栈时top=-1 */
	sqstack->top = -1;
	return FUN_OK;
}

/**
  * @brief  判断栈是否为空
  * @param  sqstack:栈      
  *            
  * @retval TRUE:栈为空
  *			FALSE：栈为非空
  */
int SqStack_Empty(SqStack_TypeDef sqstack)
{
	if ( sqstack.top == (-1) ){
		return TRUE;
	}
	else if ( sqstack.top >= 0 ){
		return FALSE;
	}
}

/**
  * @brief 	将栈清空
  * @param  sqstack:栈指针       
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqStack_Clean(SqStack_TypeDef *sqstack)
{	
	int i;
	for (i=0;i<MAXSIZE;i++){
		sqstack->data[i] = 0x00;
	}
	sqstack->top = -1;
	return FUN_OK;
}

/**
  * @brief  获取栈的某个元素的值
  * @param  sqstack:栈
  * @param  i:要获取的元素的位置
  * @param  e:获取的元素的值的指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqStack_GetElem(SqStack_TypeDef sqstack,int i,SElem_TypeDef *e)
{
	if ( sqstack.top== (-1) || i<0 || i>sqstack.top ){
		return FUN_ERROR;
	}
	*e = sqstack.data[i-1];
	return FUN_OK;
}


/**
  * @brief 	在栈中查找给定值e的元素，并返回其序号
  * @param  sqstack:栈指针       
  * @param  e:要查找的值       
  * @retval 查找成功： 返回序号
  *			查找失败： 返回 -1
  */
int SqStack_LocateElem(SqStack_TypeDef sqstack,SElem_TypeDef e)
{
	int i=0;
	if (sqstack.top == (-1)){
		return -1;
	}
	for (i=0;i<=sqstack.top;i++){
		if ( sqstack.data[i] == e ){
			return i;
		}
	}
	return -1;
}

/**
  * @brief 	进栈操作
  * @param  sqstack:栈指针   
  * @param  e:新元素的值      
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqStack_Push(SqStack_TypeDef *sqstack,SElem_TypeDef e)
{
	if ( sqstack->top == MAXSIZE-1){
		printf("\n栈满，无法入栈\n");
		return FUN_ERROR;
	}
	sqstack->top++;
	sqstack->data[sqstack->top] = e;
	return FUN_OK;
}

/**
  * @brief 	出栈操作
  * @param  sqstack:栈指针    
  * @param  e:出栈的值    
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqStack_Pop(SqStack_TypeDef *sqstack,SElem_TypeDef *e){
	
	int j;
	if ( sqstack->top == (-1) ){
		printf("\n空栈，无法执行出栈操作\n");
		return FUN_ERROR;
	}
	else {
		*e = sqstack->data[sqstack->top];
		sqstack->top--;
	}
	return FUN_OK;
}

/**
  * @brief 	获取栈的长度
  * @param  sqstack:栈   
  * @retval 栈长度
  *			
  */
int SqStack_Length(SqStack_TypeDef sqstack){
	return (sqstack.top +1);
}
	
/* Exported functions --------------------------------------------------------*/

int main(void)
{
	int i=0;
	SqStack_TypeDef sqstack;
	SElem_TypeDef *e;
	
	if (FUN_OK == SqStack_Init(&sqstack)){
		printf("\n栈初始化成功\n");
	}
	for (i=0;i<MAXSIZE;i++){
		SqStack_Push(&sqstack,i);
	}
	printf("len=%d\n",SqStack_Length(sqstack));
	
	for (i=0;i<SqStack_Length(sqstack);i++){
		printf("%d\n",sqstack.data[i]);
	}
	
	SqStack_Pop(&sqstack,e);
	printf("popnum=%d\n",*e);
	SqStack_Pop(&sqstack,e);
	printf("popnum=%d\n",*e);
	SqStack_Pop(&sqstack,e);
	printf("popnum=%d\n",*e);
	for (i=0;i<SqStack_Length(sqstack);i++){
		printf("%d\n",sqstack.data[i]);
	}	
	
}



/*****************************END OF FILE*******************************/
