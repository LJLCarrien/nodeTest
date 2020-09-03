{
    "targets": [
        {
            "target_name": "addon",
            "sources": ["src/hello.cpp"],
            "include_dirs": ["<!(node -e \"require('nan')\")"]
        },
        {
            "target_name": "call_dll",
            "sources": ["src/call-dll.c"],
        },
    ]
}
