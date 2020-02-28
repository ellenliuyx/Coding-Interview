//==================================================================
// ����ָOffer������
//==================================================================

// ������45���������ų���С����
// ��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ
// �ӳ���������������С��һ����������������{3, 32, 321}�����ӡ����3����
// �����ųɵ���С����321323��

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int g_MaxNumberLength = 10;   //������ÿ��Ԫ�صĳ���

char* g_strCombine1 = new char[2 * g_MaxNumberLength + 1];  //ƴ�����������鳤��
char* g_strCombine2 = new char[2 * g_MaxNumberLength + 1];

//************************************************************************************//
//------------------------------------�µıȽϹ���------------------------------------//
//************************************************************************************//
int compare(const void* strNumber1, const void* strNumber2) {
    char* str1 = (char*)strNumber1;
    char* str2 = (char*)strNumber2;
    sprintf(g_strCombine1, "%s%s", str1, str2);     //��str1, str2ƴ�Ӳ�����g_strCombine1
    sprintf(g_strCombine2, "%s%s", str2, str1);     //��str2, str1ƴ�Ӳ�����g_strCombine2
    return strcmp(g_strCombine1, g_strCombine2);    //�ַ����ıȽ�
}

//************************************************************************************//
//------------------------------------��ӡ��С����------------------------------------//
//************************************************************************************//
void printMinNumber(int* numbers, int length) {
    if (numbers == NULL || length <= 0)         //�Ƿ�����
        return;

    //����һάָ���ַ������飬ÿ��Ԫ����ָ��һ��һά�ַ��������ָ��
    char** strNumbers = new char* [length];
    for (int i = 0; i < length; i++) {
        strNumbers[i] = new char[g_MaxNumberLength + 1];       
        sprintf(strNumbers[i], "%d", numbers[i]);           //��ÿһ���ַ���Ԫ����numbers[i]��ʾ�����ָ�ֵ
    }

    //----------------qsort()����-------------------//
    //�������ܣ�qsort()�����Ĺ����Ƕ������������������nmemb��Ԫ�أ�ÿ��Ԫ�ش�СΪsize��

    //����base - baseָ���������ʼ��ַ��ͨ����λ�ô������һ��������
    //����nmemb - nmemb��ʾ�������Ԫ�ظ���
    //����size - size��ʾ��������ÿ��Ԫ�صĴ�С���ֽ�����
    //����(*compar)(const void*, const void*) - ��Ϊָ��ȽϺ����ĺ���ָ�룬�����������˳��

    //���compar����ֵС��0�� < 0������ôp1��ָ��Ԫ�ػᱻ����p2��ָ��Ԫ�ص�ǰ��
    //���compar����ֵ����0�� = 0������ôp1��ָ��Ԫ����p2��ָ��Ԫ�ص�˳��ȷ��
    //���compar����ֵ����0�� > 0������ôp1��ָ��Ԫ�ػᱻ����p2��ָ��Ԫ�صĺ���

    qsort(strNumbers, length, sizeof(char*), compare);

    for (int i = 0; i < length; i++)
        printf("%s", strNumbers[i]);        //��ӡ��С����
    printf("\n");

    for (int i = 0; i < length; i++)        //�ͷ������ڴ�
        delete[] strNumbers[i];
    delete[] strNumbers;
}

//************************************************************************************//
//---------------------------------------������---------------------------------------//
//************************************************************************************//
int main()
{
    int numbers[] = { 3,32,321 };
    int length = sizeof(numbers) / sizeof(numbers[0]);
    printMinNumber(numbers, length);
    return 0;
}