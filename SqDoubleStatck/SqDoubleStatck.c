/**
  ******************************************************************************
  * @file      SqDoubleStatck.c
  * @author    青椒san
  * @version   V1.0
  * @date      2017-1-20
  * @brief     栈的顺序存储结构 --两栈共享空间的 C语言实现。
  *
  ******************************************************************************
  * @attention
  *  参照《大话数据结构》栈和队列  4.5章节
  *
  ******************************************************************************
  */
  
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
 
/* Private define ------------------------------------------------------------*/

/**
  * @brief 存储空间初始分配量
  */
#define  MAXSIZE 100     

#define  TRUE   1
#define  FALSE  0   
/* Private typedef -----------------------------------------------------------*/

/**
  * @brief 定义 SElem_TypeDef 的类型为int型
  */
typedef int SElem_TypeDef;

/**
  * @brief 定义栈共享空间结构的结构体
  */
typedef struct{
	SElem_TypeDef data[MAXSIZE];
	int top1;                   /* 栈1栈顶指针 */
	int top2;                   /* 栈2栈顶指针 */
}SqDblStack_TypeDef;
/**
  * @brief 定义 SElem_TypeDef 的类型为int型
  */
typedef enum{
	stackNum1=1,
	stackNum2,
	stackAll
}StackNum_TypeDef;
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
  * @param  sqdblstack:栈指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqDblStack_Init(SqDblStack_TypeDef *sqdblstack)
{
	int i;
	for (i=0;i<MAXSIZE;i++){
		sqdblstack->data[i] = 0x00;
	}
	/* 空栈时top=-1 */
	sqdblstack->top1 = -1;
	sqdblstack->top2 = MAXSIZE;
	return FUN_OK;
}

/**
  * @brief  判断栈是否为空
  * @param  sqdblstack:栈      
  * @param  stackNum:栈的编号
  *            
  * @retval TRUE:栈为空
  *			FALSE：栈为非空
  */
int SqDblStack_Empty(SqDblStack_TypeDef sqdblstack,StackNum_TypeDef stackNum)
{
	switch(stackNum){
		case stackNum1:
			if ( sqdblstack.top1 == (-1) ){
				return TRUE;
			}
			else {
				return FALSE;
			}
			break;
		case stackNum2:
			if ( sqdblstack.top2 == MAXSIZE ){
				return TRUE;
			}
			else {
				return FALSE;
			}
			break;
		case stackAll:
			if (( sqdblstack.top1 == (-1) )&&( sqdblstack.top2 == MAXSIZE )){
				return TRUE;
			}
			else {
				return FALSE;
			}
		default:break;
	}

}

/**
  * @brief 	将栈清空
  * @param  sqdblstack:栈指针       
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqDblStack_Clean(SqDblStack_TypeDef *sqdblstack,StackNum_TypeDef stackNum)
{	
	int i;
	if (sqdblstack == NULL ){
		printf("栈不存在，清空失败");
		return FUN_ERROR;
	}
	switch(stackNum){
		case stackNum1:
			for (i=0;i<(SqDblStack_GetLength(*sqdblstack,stackNum));i++){
				sqdblstack->data[i] = 0x00;
			}
			sqdblstack->top1 = -1;
			break;
		case stackNum2:
			for (i=1;i<=(SqDblStack_GetLength(*sqdblstack,stackNum));i++){
				sqdblstack->data[MAXSIZE-i] = 0x00;
			}
			sqdblstack->top2 = MAXSIZE;	
			break;
		case stackAll:
			for (i=0;i<MAXSIZE;i++){
				sqdblstack->data[i] = 0x00;
			}
			sqdblstack->top1 = -1;
			sqdblstack->top2 = MAXSIZE;
			break;
		default:break;
	}
	return FUN_OK;
}

/**
  * @brief  获取栈的某个元素的值
  * @param  sqdblstack:栈
  * @param  stackNum:栈的编号1/2
  * @param  i:要获取的元素的位置,从栈底开始数
  * @param  e:获取的元素的值的指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqDblStack_GetElem(SqDblStack_TypeDef sqdblstack,StackNum_TypeDef stackNum,int i,SElem_TypeDef *e)
{
	if ( (sqdblstack.top1== (-1) && stackNum == stackNum1) 
		||(sqdblstack.top2== (MAXSIZE) && stackNum == stackNum2) 
		|| i<0 
	    || i>SqDblStack_GetLength(sqdblstack,stackNum) ){
		return FUN_ERROR;
	}
	switch(stackNum){
		case stackNum1:
			*e = sqdblstack.data[i-1];
			break;
		case stackNum2:
			*e = sqdblstack.data[MAXSIZE-1-i];
			break;
		default:break;
	}
	return FUN_OK;
}


/**
  * @brief 	在栈中查找给定值e的元素，并返回其序号
  * @param  sqdblstack:栈指针       
  * @param  e:要查找的值       
  * @retval 查找成功： 返回序号
  *			查找失败： 返回 -1
  */
  /*
int SqDblStack_LocateElem(SqDblStack_TypeDef sqdblstack,SElem_TypeDef e)
{
	int i=0;
	if (sqdblstack.top == (-1)){
		return -1;
	}
	for (i=0;i<=sqdblstack.top;i++){
		if ( sqdblstack.data[i] == e ){
			return i;
		}
	}
	return -1;
}
*/

/**
  * @brief 	进栈操作
  * @param  sqdblstack:栈指针   
  * @param  stackNum:编号
  * @param  e:新元素的值      
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqDblStack_Push(SqDblStack_TypeDef *sqdblstack,StackNum_TypeDef stackNum,SElem_TypeDef e)
{
	if ( sqdblstack->top1 == sqdblstack->top2-1 ){
		printf("\n栈满，无法入栈\n");
		return FUN_ERROR;
	}
	switch(stackNum){
		case stackNum1:
			sqdblstack->top1++;
			sqdblstack->data[sqdblstack->top1] = e;
			break;
		case stackNum2:
			sqdblstack->top2--;
			sqdblstack->data[sqdblstack->top2] = e;
			break;
		default:break;
	}
	return FUN_OK;
}

/**
  * @brief 	出栈操作
  * @param  sqdblstack:栈指针    
  * @param  stackNum:编号
  * @param  e:出栈的值    
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef SqDblStack_Pop(SqDblStack_TypeDef *sqdblstack,StackNum_TypeDef stackNum,SElem_TypeDef *e){
	
	int j;
	if ( (sqdblstack->top1 == (-1) && stackNum == stackNum1) || ((sqdblstack->top2 == MAXSIZE && stackNum == stackNum2))){
		printf("\n空栈，无法执行出栈操作\n");
		return FUN_ERROR;
	}
	switch(stackNum){
		case stackNum1:
			*e = sqdblstack->data[sqdblstack->top1];
			sqdblstack->top1--;
			break;
		case stackNum2:
			*e = sqdblstack->data[sqdblstack->top2];
			sqdblstack->top2++;
			break;			
		default:break;
	} 
	return FUN_OK;
}

/**
  * @brief 	获取栈的长度
  * @param  sqdblstack:栈   
  * @retval 栈长度
  *			
  */
int SqDblStack_GetLength(SqDblStack_TypeDef sqdblstack,StackNum_TypeDef stackNum){
	switch(stackNum){
		case stackNum1:
			return (sqdblstack.top1 +1);
			break;
		case stackNum2:
			return (sqdblstack.top2 -1);
			break;
		default:break;
	}
	
}
	
/* Exported functions --------------------------------------------------------*/

int main(void)
{
	int i=0;
	SqDblStack_TypeDef sqdblstack;
	SElem_TypeDef *e;
	
	if (FUN_OK == SqDblStack_Init(&sqdblstack)){
		printf("\n栈初始化成功\n");
	}
	for (i=0;i<20;i++){
		SqDblStack_Push(&sqdblstack,1,i);
	}
	printf("len=%d\n",SqDblStack_GetLength(sqdblstack,1));
	for (i=0;i<SqDblStack_GetLength(sqdblstack,1);i++){
		printf("%d\n",sqdblstack.data[i]);
	}
	SqDblStack_Pop(&sqdblstack,1,e);
	printf("POP_NUM1=%d\n",*e);
	SqDblStack_Pop(&sqdblstack,1,e);
	printf("POP_NUM2=%d\n",*e);
	for (i=0;i<SqDblStack_GetLength(sqdblstack,1);i++){
		printf("%d\n",sqdblstack.data[i]);
	}
	SqDblStack_Clean(&sqdblstack,1);
	for (i=0;i<10;i++){
		printf("%d\n",sqdblstack.data[i]);
	}
}



/*****************************END OF FILE*******************************/
