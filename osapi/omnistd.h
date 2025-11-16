#pragma once
#include"osapi.h"


#define copy(destination,source,lenth)          memorycopy(destination,source,lenth,false)
#define stringcopy(destination,source,lenth)    memorycopy(destination,source,lenth,true)

internal void zero(int8*,int16);
internal void memorycopy(int8*,int8*,int16,bool);
