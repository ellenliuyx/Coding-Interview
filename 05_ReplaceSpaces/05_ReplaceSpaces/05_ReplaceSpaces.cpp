//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <stdio.h>			//printf函数的头文件

//输入：String(输入原字符串)， SpaceLen(可用的内存空间)
void ReplaceSpaces(char String[], int SpaceLen)
{
	int length = 0;		//原字符串长度
	int length_after = 0;	//新字符串长度
	int blank_num = 0;	//空格数量
	int i = 0;

	while(String[i] != '\0')
	{
		if (String[i] == ' ')
		{
			blank_num++;	//计算原字符串中的空格数量
		}
		i++;
		length++;			//计算原字符串的长度
	}
	length_after = length + blank_num * 2;	//计算新字符串的长度

	if (length_after > SpaceLen)	//若新字符串长度大于可用的内存空间，则直接退出函数
		return;

	int index = length_after;			//在新字符串末尾设置指针
	for (int j = length; j >= 0; j--)	//从尾至头遍历原字符串
	{
		if (String[j] != ' ')			//若非空格，则完成赋值操作
		{
			String[index] = String[j];
			index--;
		}
		else							//若为空格，则完成替换操作
		{
			String[index--] = '0';
			String[index--] = '2';
			String[index--] = '%';
		}
	}
	printf("%s\n", String);
}

int main()
{
	const int length = 100;					//新字符串最多可以用的空间

	char str1[length] = "Hello world";		//只有一个空格
	ReplaceSpaces(str1,length);

	char str2[length] = "We are happy!";		//含有多个空格
	ReplaceSpaces(str2, length);

	char str3[length] = "     ";				//只有多个空格
	ReplaceSpaces(str3, length);

	char str4[length] = "Interesting!";		//没有空格
	ReplaceSpaces(str4, length);

	char str5[length] = "";					//空字符串
	ReplaceSpaces(str5, length);

	return 0;
}