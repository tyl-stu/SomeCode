温故而知新 ~ C指针 之 杂记
=

注：具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/125274700) 进行查看！

本文主要记载了学习指针时的一些有意思的知识，有些乱~

# 函数指针数组
## 1 区分
### 1）指针数组
数组是一个存放相同类型数据的存储空间，而指针数组便为保存指针的数组，如下


	int *arr[10]; //数组的每个元素是int*

### 2）数组指针
数组指针本质依然是指针，即其为可指向数组的指针，如下


	int (*arr)[10];

**注意**：上述代码中，`arr`先和`*`结合，说明`arr`是一个指针变量，然后指向一个大小为10个整型的数组。即`arr`是一个指针，指向一个数组，是为数组指针。
其中，`[]`的优先级高于`*`号，所以必须加上`()`来保证`arr`先和`*`结合。

### 3）函数指针数组
将函数的地址存到一个数组中，则这个数组就叫**函数指针数组**。如下


	int (*parr[10]])();

上行代码中，`parr` 先和`[]` 结合，即`parr`是数组，该数组的内容是`int (*)()` 类型的函数指针。
函数指针数组的用途：**转移表**

*一个辨别小技巧，优先级高的名词放后面，低的放前面，优先级排序：`() > [] > *`~*

## 2 案例
此处将以实现简单计算器为案例对函数指针数组进行说明！
### 1）常规实现


	#include <stdio.h>
	int add(int a, int b)
	{
		return a + b;
	}
	int sub(int a, int b)
	{
		return a - b;
	}
	int mul(int a, int b)
	{
		return a*b;
	}
	int div(int a, int b)
	{
		return a / b;
	}
	int main()
	{
		int x, y;
		int input = 1;
		int ret = 0;
		do
		{
			printf( "*************************\n" );
			printf( " 1:add 2:sub \n" );
			printf( " 3:mul 4:div \n" );
			printf( "*************************\n" );
			printf( "请选择：" );
			scanf( "%d", &input);
			switch (input)
			{
			case 1:
				printf( "输入操作数：" );
				scanf( "%d %d", &x, &y);
				ret = add(x, y);
				printf( "ret = %d\n", ret);
				break;
			case 2:
				printf( "输入操作数：" );
				scanf( "%d %d", &x, &y);
				ret = sub(x, y);
				printf( "ret = %d\n", ret);
				break;
			case 3:
				printf( "输入操作数：" );
				scanf( "%d %d", &x, &y);
				ret = mul(x, y);
				printf( "ret = %d\n", ret);
				break;
			case 4:
				printf( "输入操作数：" );
				scanf( "%d %d", &x, &y);
				ret = div(x, y);
				printf( "ret = %d\n", ret);
				break;
			case 0:
				printf("退出程序\n");
				breark;
			default:
				printf( "选择错误\n" );
				break;
			}
		} while (input);
		return 0;
	}

### 2）使用函数指针数组


	#include <stdio.h>
	int add(int a, int b)
	{
		return a + b;
	}
	int sub(int a, int b)
	{
		return a - b;
	}
	int mul(int a, int b)
	{
		return a*b;
	}
	int div(int a, int b)
	{
		return a / b;
	}
	int main()
	{
		int x, y;
		int input = 1;
		int ret = 0;
		int(*p[5])(int x, int y) = { 0, add, sub, mul, div };
		 //转移表，此代码相当于p[5]中包含了等式右边中的0和各函数的地址，其中的参数x和y在调用p中函数时将为对应函数的输入参数！
		while (input)
		{
			printf( "*************************\n" );
			printf( " 1:add 2:sub \n" );
			printf( " 3:mul 4:div \n" );
			printf( "*************************\n" );
			printf( "请选择：" );
			scanf( "%d", &input);
			if ((input <= 4 && input >= 1))
			{
				printf( "输入操作数：" );
				scanf( "%d %d", &x, &y);
				ret = (*p[input])(x, y);//即指向p中对应的第input+1的地址，即指向目标函数的地址，调用对应函数进行运算！ 
			}
			else
				printf( "输入有误\n" );
			printf( "ret = %d\n", ret);
		}
		return 0;
	}

## 3 补充
### 指向函数指针数组的指针
顾名思义，即一个指针指向一个数组，数组的元素都是函数指针，此即为指向函数指针数组的指针。如下


	//test是一个函数
	void (*pfun)(const char*) = test;  函数指针pfun
	void (*pfunArr[5])(const char* str);  函数指针数组pfunArr
	void (*(*ppfunArr)[10])(const char*) = &pfunArr;  指向函数指针数组pfunArr的指针ppfunArr,如果看不清楚，建议从外向里一层层的读

