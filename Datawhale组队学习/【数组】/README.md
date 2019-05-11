## C语言中动态分配内存 malloc()、calloc()、realloc()用法详解

### malloc()：

```c++
    int *pNumber = (int*)malloc(100);          　　　　 // 分配100字节内存
    int *pNumber = (int*)malloc(25*sizeof(int));        //存储25个int值得内存
```

类型转换 `(int*)` 将函数返回的地址转换成 `int` 类型的指针。因为`malloc()`返回 `void` 类型的指针，`void*` 可以指向任何类型的数据，不能取消对 `void` 指针的引用，因为它指向未具体说明的对象。

如果因某种原因而不能分配请求的内存，`malloc()`会返回一个 `NULL` 指针。可以依此判断是否成功分配内存。

**用 if 语句检查是否分配：**
```c++
    int *pNumber = (int*)malloc(25*sizeof(int));
    if (!pNumber)
    {
        // 内存分配失败的处理代码
    }
```

**释放动态分配的内存：**
```c++
    free(pNumber);
    pNumber = NULL;
```

### calloc() ：

与 `malloc()` 相比有两个优点：
  
1. 它把内存分配为给定大小的数组；
  
2. 它初始化了所分配的内存，所有位都是 0。（因此我们常用改方法而不用 `malloc()`）

```c++
    int *pNumber = (int*)calloc(75, sizeof(int));    // 分配了包含75个int元素的数组
    
    //可以让编译器执行类型转换：　　
    int *pNumber = calloc(75, sizeof(int));
```

### realloc() ：

`realloc()` 函数可以重用或扩展以前用 `malloc()` 或 `calloc()`（或者 `realloc()`）分配的内存。
    
`realloc()` 的两个参数：

1. 一个是包含地址的指针，该地址以前由 `malloc()`、`calloc()` 或 `realloc()` 返回。

2. 要分配的新内存的字节数。

```c++
    int *pNumber = (int*)calloc(25, sizeof(int));    // 分配了包含25个int元素的数组
    
    int *pNumber = realloc(pNumber, 75*sizeof(int));  // 重新分配了包含75个int元素的数组
```



