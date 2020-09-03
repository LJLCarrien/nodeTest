#include <nan.h>
#include <windows.h>
#define BUF_SIZE 4096

void Method(const Nan::FunctionCallbackInfo<v8::Value> &info)
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
        "ShareMemorySZHC"     // �����ڴ�����
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
    // cout << "����" << (char *)lpBase << endl;
    printf((char *)lpBase);

    // �̹߳���������̶߳�ȡ����
    Sleep(20000);

    // ����ļ�ӳ��
    UnmapViewOfFile(lpBase);
    // �ر��ڴ�ӳ���ļ�������
    CloseHandle(hMapFile);

    info.GetReturnValue().Set(Nan::New("End").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports)
{
    v8::Local<v8::Context> context = exports->CreationContext();
    exports->Set(context,
                 Nan::New("hello").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(Method)
                     ->GetFunction(context)
                     .ToLocalChecked());
}

NODE_MODULE(hello, Init)
