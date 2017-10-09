#####################################################################
#make  ：生成$(TARGET)可执行目标文件
#make clean  :删除中间文件（也将删除目标文件），为重新编译做好准备
#
#
#####################################################################
#VPATH = 111;../;222

#编译器定义
CC=gcc
#中间文件定义
OBJECT=SqDoubleStatck.o  
#目标定义
TARGET=SqDoubleStatck


$(TARGET):$(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT)

	$(CC) -MM SqDoubleStatck.c  
	
#显示地说明clean是一个伪目标
.PHNOY:clean 

clean:
	@rm $(TARGET)  $(OBJECT)
	@echo "Cleaned up"



