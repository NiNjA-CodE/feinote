StandardIO VS. mmap
====================

### Problem description

![problem](https://raw.github.com/Universefei/feinote/master/curriculum/driverProg/shm/figure/problem.png)

### SRC hierarchy

```
.
├── figure/            (misc)
├── mmap.c             (source file of reading bigfile via mmap)
├── README.md          (documentation)
├── statistic.sh*
├── stdio.c            (source file of readming bigfile via standard io)
├── testReport         (statistic data result of testing)
└── tools.sh*          (tools to compile/ run test etc.)

```
### tools.sh specification

![tools.sh]()


### Note board


## DEMO

1. create bigfile
2. compile source code file

![toolsUsage](https://raw.github.com/Universefei/feinote/master/curriculum/driverProg/shm/figure/toolsUsage.png)

3. test

![test](https://raw.github.com/Universefei/feinote/master/curriculum/driverProg/shm/figure/testResult.png)


## Analysis & Conclusion

### 1.标准IO过程

1. 数据从外存到内核缓冲区
2. 数据从内核缓冲区拷贝到用户空间
3. 用户程序在用户空间读写访问数据

### 2.内存映射过程

1. 系统调用为外存映射文件分配页表
2. 用户程序直接操作映射到的用户地址空间数据
3. 当用户访问页表发现未调入内存时，IO从外存调如到内存页

### 比较
* 标准IO比内存映射多一个从内核空间到用户空间的拷贝过程
* 标准IO每次读写都要一次系统调用`read()` `write()`等,需要保存上下文，跳转，
  恢复上下文等过程, 内存映射只需分配好页表后，直接操作 用户空间内存既可.
