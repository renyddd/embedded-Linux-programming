## 克隆仓库
首先你在想要存储本仓库的位置上进行克隆操作
```
git clone https://github.com/renyddd/embedded-Linux-programming.git
```

## 电脑上执行的编译操作
切换至 fileIO 的目录
```shell
cd embedded-Linux-programming/fileIO
```
接下来的编译操作
```shell
make
```
用以生成``` a.out``` 程序文件

### 程序执行
- 传入参数 1：将要操作的文件名
- 传入参数 2：要向文件中添加的字符串
```shell
./a.out hello.txt "This is my school number: 17407110216."
```
程序成功执行后，可自行查看文件内容
```shell
cat hello.txt
```
### 清除文件
```shell
make clean
```

## arm 系统上的运行
操作目的：将 Makefile 文件中的 gcc 命令，替换为 arm-linux-gcc 命令
