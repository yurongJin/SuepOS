#include"disk.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

disk *DiskDescriptor[2];
internal int8 attached;

internal void dshow(disk *dd){
    if(dd)
        printf(
            "drive 0x%.02hhx\n"
            " fd=%d\n"
            " blocks=%d\n\n",
                (char)dd->drive, $i dd->fd,$i dd->blocks

        );
    
    return;
}


internal void ddetach(disk *dd){
    int8 x;

    if(!dd){
        return;
    }
    close($i dd->fd);
    x = ~(dd->drive) & attached;
    attached = x;
    destroy(dd);

    return;
}

internal disk *dattach(int8 drive){
    
    disk *dd;
    int16 size;
    int8 *file;
    signed int tmp;
    struct stat sbuf;

    if((drive==1)||(drive==2));
    else
        return (disk *)0;

    if(attached & drive){
        return (disk *)0;
    }


    size=sizeof(struct s_disk);
    dd=(disk *)malloc($i size);
    if(!dd){
        return (disk *)0;
    }
    zero($1 dd,size);

    file=strnum(Basepath,drive);
    tmp = open($c file,O_RDWR);
    if(tmp<3){
        free(dd);
        return (disk *)0;
    }

    dd->fd = $4 tmp;

    tmp = fstat($i dd->fd,&sbuf);

    if(tmp || !sbuf.st_blocks){
        close(dd->fd);
        free(dd);

        return (disk *)0;
    }
    dd->blocks = $2 (sbuf.st_blocks-1);
    dd->drive = drive;
    attached |= drive;

    return dd;
}

public void dinit(){
    block bl={0};
    bool x;

    attached=0;
    *DiskDescriptor = dattach(1);
    *(DiskDescriptor+1) = dattach(2);

    // dshow(*DiskDescriptor);
    // dshow(DiskDescriptor[1]);

    // x = dread(*DiskDescriptor,&bl,2);
    // printf("x = %s\n",(x)?"true":"false");
    // printf("0x%.02hhx\n",(char)bl[500]);

    // ddetach(*DiskDescriptor);
    // ddetach(DiskDescriptor[1]);

    return;
}

internal int16 openfiles(disk *dd){
    return 0;
}

internal void closeallfiles(disk *dd){
    return;
}