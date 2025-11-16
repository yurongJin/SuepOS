#include"omnistd.h"

internal void zero(int8 *str,int16 size){
    int8 *p;
    int16 n;
    for(p=str,n=size;n;n--,p++){
        *p=(int8)0;
    }
    return;
}

internal void memorycopy(int8* dst,int8* src,int16 len,bool string){
    int16 n;
    int8 *dp,*sp;
    
    for(n=len,dp=dst,sp=src;n;dp++,sp++,n--){
        if(string && !(*sp)){
            break;
        }else
            *dp=*sp;
    }
    
    return;
}