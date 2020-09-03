{
    "targets": [
        {
            "target_name": "addon",
            "sources": ["src/hello.cpp"],
        }, 
         {
            "target_name": "test",
            "sources": ["src/test.cpp"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ],
        },
        {
            "target_name": "callDll",
            "sources": ["src/callDll.c"],
        },
        {
            "target_name": "cppCallDll",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["src/cppCallDll.cpp"],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
            ],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
        },
    ]
}
