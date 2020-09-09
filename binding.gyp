{
    "targets": [
        {
            "target_name": "test",
            "sources": ["src/test.cpp",
                        "src/protobufHelper.cpp",
                        "Account.pb.cc",
                        "src/shareMemoryHelper.cpp", ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "include",  # ͷ�ļ� �൱����Ŀ��������-c/c++-����-���Ӱ���Ŀ¼
            ],
            'link_settings': {
                'libraries': [
                    "libprotobuf.lib",  # lib���� �൱����Ŀ��������-������-����-���ӿ�Ŀ¼
                    "libprotoc.lib",
                ],
                'library_dirs': [
                    # lib������·�� �൱����Ŀ��������-������-����-����������
                    './static_libs/Release',
                ],
            },

        },

    ]
}
