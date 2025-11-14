#pragma once
#include <stdio.h>
#include "osapi.h"
#include "disk.h"

#define Magic1          (0xdd05)
#define Magic2          (0xaa55)
#define Inodesperblock  (16)
#define PtrPerInode     (8)
#define PtrPerBlock     (256)

internal packed struct s_superblock {
    int8 bootsector[500];
    int16 _;
    int16 blocks;
    int16 inodeblocks;
    int16 inodes;
    int16 magic1;
    int16 magic2;
};

typedef struct s_superblock superblock;

internal packed struct s_filesystem {
    int8 drive;
    disk *dd;
    bool *bitmap;
    superblock matadata;
};
typedef struct s_filesystem filesystem;
