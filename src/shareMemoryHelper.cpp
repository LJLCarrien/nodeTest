#include <iostream>
#include <windows.h>
#define BUF_SIZE 4096
#include "test.h"
using namespace std;

void ShareMemoryHelper::test()
{
    // 定义共享数据
    char szBuffer[] = "我服务端啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊。";

    // 创建共享文件句柄
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE, // 物理文件句柄
        NULL,                 // 默认安全级别
        PAGE_READWRITE,       // 可读可写
        0,                    // 高位文件大小
        BUF_SIZE,             // 低位文件大小
        "ShareMemorySZHC"    // 共享内存名称
    );

    // 映射缓存区视图 , 得到指向共享内存的指针
    LPVOID lpBase = MapViewOfFile(
        hMapFile,            // 共享内存的句柄
        FILE_MAP_ALL_ACCESS, // 可读写许可
        0,
        0,
        BUF_SIZE);

    // 将数据拷贝到共享内存
    strcpy((char *)lpBase, szBuffer);
    cout << "服务：" << (char *)lpBase << endl;

    // 线程挂起等其他线程读取数据
    Sleep(20000);

    // 解除文件映射
    UnmapViewOfFile(lpBase);
    // 关闭内存映射文件对象句柄
    CloseHandle(hMapFile);
}