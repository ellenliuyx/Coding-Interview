//==================================================================
// ����ָOffer������
//==================================================================

// ������1����ֵ���������
// ��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������

#define _CRT_SECURE_NO_WARNINGS			//���������strcpy_s�滻strcpy�Ĵ�����ʾ
#include <iostream>						//���������������cout���õ���ͷ�ļ�
#include <string>						//�ַ���������strcpy���õ���ͷ�ļ�
using namespace std;					//�����ռ䣬ʡ��str::

//CMyString ��
class CMyString
{
public:
	//������������
	CMyString(char* pData = nullptr);		//���캯��
	CMyString(const CMyString& str);		//���ƹ��캯��
	~CMyString(void);						//��������

	CMyString& operator=(const CMyString& str);
	friend ostream& operator<<(ostream& o, const CMyString& str);

private:
	char* m_pData;
};

//���캯������
CMyString::CMyString(char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0]= '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

//���ƹ��캯������
CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

//������������
CMyString::~CMyString(void)
{
	delete[] m_pData;
}

//��ֵ���������
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;									//��Ϊ����ֵ����ֱ�ӷ���thisָ��

	delete[] m_pData;									//���ͷ��ڴ棬��������ڴ�й¶
	m_pData = new char[strlen(str.m_pData) + 1];		//����str��С����һ���µ��ڴ�ռ�
	strcpy(m_pData, str.m_pData);						//�����ݿ���
	return *this;										//����ʵ�����������
}

//��������������
ostream& operator<<(ostream & o, const CMyString& str)		//�����ͷ���ֵ��Ϊ ostream& ��
{
	o << str.m_pData;
	return o;
}

//���Ժ���
int main()
{
	char* a1 = (char*)"the";
	char* a2 = (char*)"this";
	char* a3 = (char*)"these";

	CMyString s1(a1), s2(a2), s3(a3);		//���ù��캯�����弸�� CMyString ����
	
	cout << "s1=" << s1 << "," << "s2=" << s2 << "," << "s3=" << s3 << endl;
	s1 = s1;			//����ֵ����
	cout << "s1=" << s1 << endl;
	s2 = s1;			//������ֵ����
	cout << "s1=" << s1 << "," << "s2=" << s2 << endl;
	s1 = s2 = s3;		//������ֵ����
	cout << "s1=" << s1 << "," << "s2=" << s2 << "," << "s3=" << s3 << endl;
}