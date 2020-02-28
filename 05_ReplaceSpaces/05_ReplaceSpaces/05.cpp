/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <cstdio>
#include <cstring>

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
void ReplaceBlank(char str[], int length)
{
    if (str == nullptr && length <= 0)
        return;

    /*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        ++originalLength;

        if (str[i] == ' ')
            ++numberOfBlank;

        ++i;
    }

    /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (str[indexOfOriginal] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOriginal];
        }

        --indexOfOriginal;
    }
}

// ====================���Դ���====================

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";

    ReplaceBlank(str, length);

}

int main()
{
    Test1();

    return 0;
}