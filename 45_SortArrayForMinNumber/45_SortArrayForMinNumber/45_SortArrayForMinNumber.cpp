//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int g_MaxNumberLength = 10;   //数组中每个元素的长度

char* g_strCombine1 = new char[2 * g_MaxNumberLength + 1];  //拼接起来的数组长度
char* g_strCombine2 = new char[2 * g_MaxNumberLength + 1];

//************************************************************************************//
//------------------------------------新的比较规则------------------------------------//
//************************************************************************************//
int compare(const void* strNumber1, const void* strNumber2) {
    char* str1 = (char*)strNumber1;
    char* str2 = (char*)strNumber2;
    sprintf(g_strCombine1, "%s%s", str1, str2);     //将str1, str2拼接并存入g_strCombine1
    sprintf(g_strCombine2, "%s%s", str2, str1);     //将str2, str1拼接并存入g_strCombine2
    return strcmp(g_strCombine1, g_strCombine2);    //字符串的比较
}

//************************************************************************************//
//------------------------------------打印最小数字------------------------------------//
//************************************************************************************//
void printMinNumber(int* numbers, int length) {
    if (numbers == NULL || length <= 0)         //非法输入
        return;

    //创建一维指针字符串数组，每个元素是指向一个一维字符串数组的指针
    char** strNumbers = new char* [length];
    for (int i = 0; i < length; i++) {
        strNumbers[i] = new char[g_MaxNumberLength + 1];       
        sprintf(strNumbers[i], "%d", numbers[i]);           //将每一个字符串元素用numbers[i]表示的数字赋值
    }

    //----------------qsort()函数-------------------//
    //函数功能：qsort()函数的功能是对数组进行排序，数组有nmemb个元素，每个元素大小为size。

    //参数base - base指向数组的起始地址，通常该位置传入的是一个数组名
    //参数nmemb - nmemb表示该数组的元素个数
    //参数size - size表示该数组中每个元素的大小（字节数）
    //参数(*compar)(const void*, const void*) - 此为指向比较函数的函数指针，决定了排序的顺序。

    //如果compar返回值小于0（ < 0），那么p1所指向元素会被排在p2所指向元素的前面
    //如果compar返回值等于0（ = 0），那么p1所指向元素与p2所指向元素的顺序不确定
    //如果compar返回值大于0（ > 0），那么p1所指向元素会被排在p2所指向元素的后面

    qsort(strNumbers, length, sizeof(char*), compare);

    for (int i = 0; i < length; i++)
        printf("%s", strNumbers[i]);        //打印最小数字
    printf("\n");

    for (int i = 0; i < length; i++)        //释放数组内存
        delete[] strNumbers[i];
    delete[] strNumbers;
}

//************************************************************************************//
//---------------------------------------主函数---------------------------------------//
//************************************************************************************//
int main()
{
    int numbers[] = { 3,32,321 };
    int length = sizeof(numbers) / sizeof(numbers[0]);
    printMinNumber(numbers, length);
    return 0;
}