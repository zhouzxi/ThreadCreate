/**********************************************************************
* 版权所有 (C)2015, Zhou Zhaoxiong。
*
* 文件名称：ThreadCreate.c
* 文件标识：无
* 内容摘要：演示多线程的创建
* 其它说明：无
* 当前版本：V1.0
* 作    者：Zhou Zhaoxiong
* 完成日期：20151029
*
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 重定义数据类型
typedef signed   int    INT32;
typedef unsigned int    UINT32;

// 宏定义
#define THREAD_NUM     5              // 线程个数

// 函数声明
void ScanTask(void *pParam);
void ProcessTask(void *pParam);


/**********************************************************************
* 功能描述：主函数
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期        版本号     修改人            修改内容
* -------------------------------------------------------------------
* 20151029        V1.0     Zhou Zhaoxiong        创建
***********************************************************************/
INT32 main()
{
    pthread_t MultiHandle  = 0;      // 多线程句柄
    pthread_t SingleHandle = 0;     // 单线程句柄
    UINT32    iLoopFlag    = 0;
    INT32     iRetVal      = 0;  // 创建线程函数的返回值

    // 循环创建线程
    for (iLoopFlag = 0; iLoopFlag < THREAD_NUM; iLoopFlag ++)
    {
        iRetVal = pthread_create(&MultiHandle, NULL, (void * (*)(void *))(&ScanTask), (void *)iLoopFlag);
        if (0 != iRetVal)
        {
            printf("Create ScanTask %d failed!\n", iLoopFlag);
            return -1;
        }
    }
    
    // 单独创建线程
    iRetVal = pthread_create(&SingleHandle, NULL, (void * (*)(void *))(&ProcessTask), NULL);
    if (0 != iRetVal)
    {
        printf("Create ProcessTask failed!\n");
        return -1;
    }

    return 0;   
}


/**********************************************************************
 * 功能描述： 扫描线程
 * 输入参数： pParam-线程编号
 * 输出参数： 无
 * 返 回 值： 无
 * 其它说明： 无
 * 修改日期            版本号            修改人           修改内容
 * ----------------------------------------------------------------------
*  20151029             V1.0          Zhou Zhaoxiong        创建
 ************************************************************************/
void ScanTask(void *pParam)
{
    UINT32  iThreadNo   = 0;        // 线程编号

    iThreadNo = (UINT32)pParam;     // 获取线程编号

    printf("Now, into ScanTask[%d].\n", iThreadNo);    // 打印包含线程编号的消息
    
    // 进行后续操作
}


/**********************************************************************
 * 功能描述： 处理线程
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 其它说明： 无
 * 修改日期            版本号            修改人           修改内容
 * ----------------------------------------------------------------------
*  20151029             V1.0          Zhou Zhaoxiong        创建
 ************************************************************************/
void ProcessTask(void *pParam)
{
    printf("Now, into ProcessTask.\n");
    
    // 进行后续操作
}

