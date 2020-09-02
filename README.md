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

node test.js