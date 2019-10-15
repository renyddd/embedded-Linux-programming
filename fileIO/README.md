## 克隆仓库
```
git clone 
```

## 电脑上的执行
```
make
```
生成 ./a.out 程序文件

### 程序执行
传入参数 1：将要操作的文件名
传入参数 2：向文件中添加的字符串
```
./a.out hello.txt "This is my school number: 17407110216."
```
程序成功执行后，自行查看文件内容
```
cat hello.txt
```
### 清除文件
```
make clean
```

## arm 系统上的运行
操作目的：将 Makefile 文件中的 gcc 命令，替换为 arm-linux-gcc 命令
