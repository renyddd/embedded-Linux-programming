## 克隆仓库

首先要确保你的 Ubuntu 系统能正常访问网络，链接网络后，在你想存储的路径下进行 clone 操作：
```shell
git clone https://github.com/renyddd/embedded-Linux-programming.git
```

## 电脑上执行的编译操作
切换至 processDir 目录。
```shell
cd processDir
```
接下来的编译操作：
```shell
make
```
用以生成 a.out 程序文件。

## 执行程序
```shell
./a.out    --help
```
即会显示该程序的帮助信息。
## 清除文件
```shell
make clean
```

## arm 系统上的运行
操作目的：将 Makefile 文件中的 cc 命令，替换为 arm-linux-gcc 命令。
我们在替换前，先进行备份操作：
```shell
cp  Makefile  Makefile.bak;

sed -i 's/cc/arm-linux-gcc/' Makefile
```
