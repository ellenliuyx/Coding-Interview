//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

#include <cstdio>

//********************************************************************************//
//------------------------------求数组逆序对核心函数------------------------------//
//输入：int* data（输入数组）, int* copy（辅助数组）, int start（区间起始）, int end（区间结束）
//返回值：数组的逆序对数目
//********************************************************************************//
int InversePairsCore(int* data, int* copy, int start, int end)
{
    if (start == end)               //当分到最后只有一个元素时，则直接拷贝元素，并返回逆序对数为0
    {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2; //一分为二

    int left = InversePairsCore(copy, data, start, start + length);     //计算左半部分逆序对数量
    int right = InversePairsCore(copy, data, start + length + 1, end);  //计算右半部分逆序对数量

    // i初始化为前半段最后一个数字的下标，即p_1
    int i = start + length;
    // j初始化为后半段最后一个数字的下标，即p_2
    int j = end;
    int indexCopy = end;        //p_3
    int count = 0;
    while (i >= start && j >= start + length + 1)   //当前半部分和后半部分的元素均未遍历完时
    {
        if (data[i] > data[j])                  //若p_1处元素值大于p_2出元素值
        {
            copy[indexCopy--] = data[i--];      //将大数从后往前拷贝到辅助数组中
            count += j - start - length;        //逆序对数为后半部分数组中剩余数字的个数
        }
        else                                    //否则
        {
            copy[indexCopy--] = data[j--];      //直接将大数从后往前拷贝到辅助数组中，没有新的逆序对出现
        }
    }

    for (; i >= start; --i)                 //若p_2已遍历完而p_1中仍有剩余元素，则将p_1的元素从后往前拷贝到p_3
        copy[indexCopy--] = data[i];

    for (; j >= start + length + 1; --j)    //若p_1已遍历完而p_2中仍有剩余元素，则将p_2的元素从后往前拷贝到p_3
        copy[indexCopy--] = data[j];

    return left + right + count;            //最终的逆序对数目
}

//********************************************************************************//
//--------------------------------求数组逆序对函数--------------------------------//
//输入：int* data（输入数组）, int length（区间长度）
//返回值：数组的逆序对数目
//********************************************************************************//
int InversePairs(int* data, int length)
{
    if (data == nullptr || length < 0)      //非法输入
        return 0;

    int* copy = new int[length];            //将输入数组data深拷贝到辅助数组copy
    for (int i = 0; i < length; ++i)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);    //计算逆序对数目
    delete[] copy;

    return count;
}

// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}