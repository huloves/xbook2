#ifndef _XBOOK_SYSCALL_H
#define _XBOOK_SYSCALL_H

/*
系统调用的作用是，用户可以通过内核暴露的系统调用
来执行内核提供的部分操作。
对于元内核，至少需要为用户提供进程，内存管理，进程间通信，时间管理，设备管理
相应的系统调用接口。
*/
typedef void * syscall_t;

enum syscall_num {
    SYS_EXIT,
    SYS_FORK,
    SYS_EXECR,
    SYS_EXECF,
    SYS_WAITPID,
    SYS_COEXIST,
    SYS_GETPID,
    SYS_GETPPID,
    SYS_TRIGGER,
    SYS_TRIGGERON,
    SYS_TRIGGERACT,
    SYS_TRIGRET,
    SYS_SLEEP,
    SYS_THREAD_CREATE,
    SYS_THREAD_EXIT,
    SYS_THREAD_JOIN,
    SYS_THREAD_CANCEL,
    SYS_THREAD_DETACH,
    SYS_GETTID,
    SYS_THREAD_TESTCANCEL,
    SYS_THREAD_CANCELSTATE,
    SYS_THREAD_CANCELTYPE,
    SYS_SCHED_YEILD,
    SYS_WAITQUE_CREATE,
    SYS_WAITQUE_DESTROY,
    SYS_WAITQUE_WAIT,
    SYS_WAITQUE_WAKE,
    SYS_PROC_RESERVED = 30,             /* 预留30个接口给进程管理 */
    SYS_HEAP,
    SYS_MUNMAP,
    SYS_VMM_RESERVED = 40,              /* 预留10个接口给内存管理 */
    SYS_GETRES, 
    SYS_PUTRES,
    SYS_READRES, 
    SYS_WRITERES,
    SYS_CTLRES,
    SYS_DEVSCAN, 
    SYS_MMAP, 
    
    SYS_RES_RESERVED = 50,              /* 预留10个接口给资源管理 */
    SYS_ALARM,
    SYS_KTIME,
    SYS_GETTICKS,
    SYS_GETTIMEOFDAY,
    SYS_CLOCK_GETTIME,
    SYS_TIME_RESERVED = 60,             /* 预留10个接口给时间管理 */
    SYS_SRVCALL,
    SYS_SRVCALL_LISTEN,
    SYS_SRVCALL_ACK,
    SYS_SRVCALL_BIND,
    SYS_SRVCALL_UNBIND,
    SYS_SRVCALL_FETCH,
    SYS_UNID,
    SYS_TSTATE,
    SYS_GETVER,
    SYS_MSTATE,
    SYS_USLEEP,
/// 文件系统
    SYS_OPEN,
    SYS_CLOSE,
    SYS_READ,
    SYS_WRITE,
    SYS_LSEEK,
    SYS_ACCESS,
    SYS_UNLINK,
    SYS_FTRUNCATE,
    SYS_FSYNC,
    SYS_IOCTL,
    SYS_FCNTL,
    SYS_TELL,
    SYS_MKDIR,
    SYS_RMDIR,
    SYS_RENAME,
    SYS_GETCWD,
    SYS_CHDIR,
    SYS_EXECVE,
    SYS_STAT,
    SYS_FSTAT,
    SYS_CHMOD,
    SYS_FCHMOD,
    SYS_OPENDIR,
    SYS_CLOSEDIR,
    SYS_READDIR,
    SYS_REWINDDIR,
/// sockets 套接字
    SYS_SOCKET,
    SYS_BIND,
    SYS_CONNECT,
    SYS_LISTEN,
    SYS_ACCEPT,
    SYS_SEND,
    SYS_RECV,
    SYS_SENDTO,
    SYS_RECVFROM,
    SYS_SHUTDOWN,
    SYS_GETPEERNAME,
    SYS_GETSOCKNAME,
    SYS_GETSOCKOPT,
    SYS_SETSOCKOPT,
    SYS_IOCTLSOCKET,
    SYS_SELECT,
    SYS_DUP,
    SYS_DUP2,
    SYS_PIPE,
    SYS_SHMGET,
    SYS_SHMPUT,
    SYS_SHMMAP,
    SYS_SHMUNMAP,
    SYS_SEMGET,
    SYS_SEMPUT,
    SYS_SEMDOWN,
    SYS_SEMUP,
    SYS_MSGGET,
    SYS_MSGPUT,
    SYS_MSGSEND,
    SYS_MSGRECV,
    SYS_TRIGPENDING,
    SYS_TRIGPROCMASK,
    SYS_XCONGET,
    SYS_XCONCLEAR,
    SYS_XCONPUT,
    SYSCALL_NR,
};

/* 属于检测点的系统调用有：
SYS_WAITPID，SYS_SLEEP，SYS_THREAD_JOIN，SYS_GETRES, SYS_PUTRES, SYS_READRES, 
SYS_WRITERES */

void init_syscall();

#endif   /*_XBOOK_SYSCALL_H*/
