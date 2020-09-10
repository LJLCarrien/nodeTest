### 根据指定版本重编

```
node-gyp rebuild --target=4.2.12 --arch= --dist-url=https://npm.taobao.org/mirrors/atom-shell
```

--arch=ia32 是32位

--arch=x64 是64位

--target指定electron版本号

--dist-url指定头文件下载地址，原答案这个值写的是https://atom.io/download/electron，国内的话不管用


### 测试js里使用addon.node

```
node test\test.js
```



### V8

[v8 api](https://v8docs.nodesource.com/)



### node-gyp 子命令

- $ node-gyp configure：通过当前目录的 binding.gyp 生成项目文件，如 Makefile 等；
- $ node-gyp build：将当前项目进行构建编译，前置操作必须先 configure；
- $ node-gyp clean：清理生成的构建文件以及输出目录，说白了就是把目录清理了；
- $ node-gyp rebuild：相当于依次执行了 clean、configure 和 build；
- $ node-gyp install：手动下载当前版本的 Node.js 的头文件和库文件到对应目录。

### binding.gyp 参考
[gyp 文件输入格式参考](https://itbilu.com/nodejs/npm/By7L5p3ff.html#Primitive-Types)
参考 https://github.com/nodejs/node-v0.x-archive/blob/f39e608c6eb11c91839ea4661caece1f89f1b12f/common.gypi#L42

### protoc 命令 生成.pb.cc .pb.h
protoc --cpp_out=./ Account.proto

### >100m文件上传失败
```
git lfs install
```

Git LFS 管理lib文件
```
git lfs track "*.lib"
```