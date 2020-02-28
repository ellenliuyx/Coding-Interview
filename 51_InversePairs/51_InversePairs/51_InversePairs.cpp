//==================================================================
// ����ָOffer������
//==================================================================

// ������51�������е������
// ��Ŀ���������е������������ǰ��һ�����ִ��ں�������֣���������������
// ��һ������ԡ�����һ�����飬�����������е�����Ե�������

#include <cstdio>

//********************************************************************************//
//------------------------------����������Ժ��ĺ���------------------------------//
//���룺int* data���������飩, int* copy���������飩, int start��������ʼ��, int end�����������
//����ֵ��������������Ŀ
//********************************************************************************//
int InversePairsCore(int* data, int* copy, int start, int end)
{
    if (start == end)               //���ֵ����ֻ��һ��Ԫ��ʱ����ֱ�ӿ���Ԫ�أ��������������Ϊ0
    {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2; //һ��Ϊ��

    int left = InversePairsCore(copy, data, start, start + length);     //������벿�����������
    int right = InversePairsCore(copy, data, start + length + 1, end);  //�����Ұ벿�����������

    // i��ʼ��Ϊǰ������һ�����ֵ��±꣬��p_1
    int i = start + length;
    // j��ʼ��Ϊ�������һ�����ֵ��±꣬��p_2
    int j = end;
    int indexCopy = end;        //p_3
    int count = 0;
    while (i >= start && j >= start + length + 1)   //��ǰ�벿�ֺͺ�벿�ֵ�Ԫ�ؾ�δ������ʱ
    {
        if (data[i] > data[j])                  //��p_1��Ԫ��ֵ����p_2��Ԫ��ֵ
        {
            copy[indexCopy--] = data[i--];      //�������Ӻ���ǰ����������������
            count += j - start - length;        //�������Ϊ��벿��������ʣ�����ֵĸ���
        }
        else                                    //����
        {
            copy[indexCopy--] = data[j--];      //ֱ�ӽ������Ӻ���ǰ���������������У�û���µ�����Գ���
        }
    }

    for (; i >= start; --i)                 //��p_2�ѱ������p_1������ʣ��Ԫ�أ���p_1��Ԫ�شӺ���ǰ������p_3
        copy[indexCopy--] = data[i];

    for (; j >= start + length + 1; --j)    //��p_1�ѱ������p_2������ʣ��Ԫ�أ���p_2��Ԫ�شӺ���ǰ������p_3
        copy[indexCopy--] = data[j];

    return left + right + count;            //���յ��������Ŀ
}

//********************************************************************************//
//--------------------------------����������Ժ���--------------------------------//
//���룺int* data���������飩, int length�����䳤�ȣ�
//����ֵ��������������Ŀ
//********************************************************************************//
int InversePairs(int* data, int length)
{
    if (data == nullptr || length < 0)      //�Ƿ�����
        return 0;

    int* copy = new int[length];            //����������data�������������copy
    for (int i = 0; i < length; ++i)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);    //�����������Ŀ
    delete[] copy;

    return count;
}

// ====================���Դ���====================
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

// �ݼ���������
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// ������������
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ��һ������
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// ������ֻ���������֣���������
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ���������֣��ݼ�����
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// ����������ȵ�����
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