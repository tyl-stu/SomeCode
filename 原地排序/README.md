作文以记之 ~ 排序-原地交换
=
# 1、算法流程
![在这里插入图片描述](https://img-blog.csdnimg.cn/c37405cf4d5a4e9abd3d772d01b8a160.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)


# 2、图示流程
![在这里插入图片描述](https://img-blog.csdnimg.cn/9a3393c407da4471b45f2c59fbdf2efa.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/e84059abe10b4b1aac7c7e4db71d2284.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)



# 3、程序 & 运行结果
## 3.1 程序：

	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	/* 排序 之 原地交换！！！！ */
	void test()
	{
		vector<int> nums = { 2, 3, 1, 0, 5, 4, 6 };
		std::cout << std::endl << "原数组：";
		for (int &d : nums)
			std::cout << d << " ";
		std::cout << std::endl << std::endl;
		int i = 0;
		while (i < nums.size())
		{
			if (nums[i] == i)
			{
				i++;
				continue;
			}
			swap(nums[nums[i]], nums[i]);
		}
		std::cout << "排序后数组：";
		for (int &d : nums)
			std::cout << d << " ";
		std::cout << std::endl << std::endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


## 3.2 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/c28bf0e489114d17ab1bd7ca1e52b5dd.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
