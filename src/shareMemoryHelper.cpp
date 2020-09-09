#include <iostream>
#include <windows.h>
#define BUF_SIZE 4096
#include "test.h"
using namespace std;

void ShareMemoryHelper::test()
{
    // ���干������
    char szBuffer[] = "�ҷ���˰���������������������������������";

    // ���������ļ����
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE, // �����ļ����
        NULL,                 // Ĭ�ϰ�ȫ����
        PAGE_READWRITE,       // �ɶ���д
        0,                    // ��λ�ļ���С
        BUF_SIZE,             // ��λ�ļ���С
        "ShareMemorySZHC"    // �����ڴ�����
    );

    // ӳ�仺������ͼ , �õ�ָ�����ڴ��ָ��
    LPVOID lpBase = MapViewOfFile(
        hMapFile,            // �����ڴ�ľ��
        FILE_MAP_ALL_ACCESS, // �ɶ�д���
        0,
        0,
        BUF_SIZE);

    // �����ݿ����������ڴ�
    strcpy((char *)lpBase, szBuffer);
    cout << "����" << (char *)lpBase << endl;

    // �̹߳���������̶߳�ȡ����
    Sleep(20000);

    // ����ļ�ӳ��
    UnmapViewOfFile(lpBase);
    // �ر��ڴ�ӳ���ļ�������
    CloseHandle(hMapFile);
}