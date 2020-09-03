### 生成build

```shell
node-gyp configure
```

### 生成release

```shell
node-gyp build
```

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
node test.js
```

### 可参考的demo项目

https://github.com/freezer333/nodecpp-demo.git

https://github.com/caoxiemeihao/node-addons-learn.git



### V8

[v8 api](https://v8docs.nodesource.com/)



### node-gyp 子命令

- $ node-gyp configure：通过当前目录的 binding.gyp 生成项目文件，如 Makefile 等；
- $ node-gyp build：将当前项目进行构建编译，前置操作必须先 configure；
- $ node-gyp clean：清理生成的构建文件以及输出目录，说白了就是把目录清理了；
- $ node-gyp rebuild：相当于依次执行了 clean、configure 和 build；
- $ node-gyp install：手动下载当前版本的 Node.js 的头文件和库文件到对应目录。