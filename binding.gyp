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
                "include",  # 头文件 相当于项目属性配置-c/c++-常规-附加包含目录
            ],
            'link_settings': {
                'libraries': [
                    "libprotobuf.lib",  # lib库名 相当于项目属性配置-链接器-常规-附加库目录
                    "libprotoc.lib",
                ],
                'library_dirs': [
                    # lib库所在路径 相当于项目属性配置-链接器-输入-附加依赖项
                    './static_libs/Release',
                ],
            },

        },

    ]
}
