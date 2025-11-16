#pragma once
#include <stdio.h>
#include "osapi.h"

#define DriveC     0x01    /*0001*/
#define DriveD     0x02    /*0010*/
#define Basepath   $1 "/home/yurongjin/os/drives/disk."

#define Blocksize 512

typedef int8 block[512];

internal packed struct s_disk{
    int32 fd;
    int16 blocks;
    bool drive:2;
};
typedef struct s_disk disk;

internal disk *dattath(int8);
internal void ddetach(disk*);
internal void dshow(disk*);
internal int16 openfiles(disk *);
internal void closeallfiles(disk *);

/*
    bool dread(disk *dd,block *addr,int16 blockno);
    bool dwrite(disk *dd,block *addr,int16 blockno);
*/

#define dio(fun,dsk,addr,blkno) (\
    (dsk) &&\
    (lseek($i (dsk)->fd,$i (Blocksize*(blkno-1)),SEEK_SET)!=-1)&&\
    (((fun)($i (dsk)->fd, $c (addr),Blocksize) == Blocksize))\
)
#define dread(dsk,addr,blkno)   dio(read,dsk,addr,blkno)
#define dwrite(dsk,addr,blkno)  dio(write,dsk,addr,blkno)



