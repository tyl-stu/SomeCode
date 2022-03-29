作文以记之~二维数组中查找数据
=
其他内容可点击 [同款博客](https://blog.csdn.net/m0_51961114/article/details/123760812?spm=1001.2014.3001.5502) 进行查看！

# 1、算法流程
![在这里插入图片描述](https://img-blog.csdnimg.cn/bf2613eea87147b7acf14beff18a2896.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、案例图示
![在这里插入图片描述](https://img-blog.csdnimg.cn/40f9834a98e241908c18320813b8d96c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/7e044ad253b149a69622113409f4d357.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)


# 3、程序 & 运行结果
## 3.1 程序


	/* 二维数组中查找对应数据 */
	
	#include<iostream>
	#include<vector>
	using namespace std;
	
	void InsertData(vector<vector<int>> &mat) //插入数据
	{
		mat.push_back(vector<int>()); mat[0].push_back(1); mat[0].push_back(5); mat[0].push_back(9); mat[0].push_back(13);
		mat.push_back(vector<int>()); mat[1].push_back(2); mat[1].push_back(6); mat[1].push_back(10); mat[1].push_back(14);
		mat.push_back(vector<int>()); mat[2].push_back(3); mat[2].push_back(7); mat[2].push_back(11); mat[2].push_back(15);
		mat.push_back(vector<int>()); mat[3].push_back(4); mat[3].push_back(8); mat[3].push_back(12); mat[3].push_back(16);
	}
	
	void ShowData(vector<vector<int>> &mat) //显示数据
	{
		int row = mat.size();
		int col = mat[0].size();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				std::cout << mat[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	bool FindNumber(vector<vector<int>> &mat, int obj)
	{
		int n = mat.size() - 1;
		int m = 0;
		while (n >= 0 && m < mat[0].size())
		{
			if (mat[n][m] > obj)
				n--;
			else if (mat[n][m] < obj)
				m++;
			else
				return true;
		}
		return false;
	}
	
	void test()
	{
		vector<vector<int>> matrix;
		InsertData(matrix);
		std::cout << "原始二维数组：" << std::endl; ShowData(matrix);
		int target = 8;
		std::cout << target << " 是否存在于目标数组：" << std::boolalpha << FindNumber(matrix, target) << std::endl;
		target = 0;
		std::cout << target << " 是否存在于目标数组：" << std::boolalpha << FindNumber(matrix, target) << std::endl;
		std::cout << std::endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 3.2 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/434475f8c9e34fd3bcdd0da9447d1588.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
