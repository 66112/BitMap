#ifndef __BIT_MAP__
#define __BIT_MAP__
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#define DataType size_t

typedef struct BitMap
{
	char* _bits;      //位图指针
	size_t _range;    //最大的数
}BitMap;

void BitMapInit(BitMap* bm, size_t range);
void BitMapSet(BitMap* bm, DataType num);      //置1
void BitMapReSet(BitMap* bm, DataType num);		//置0
int BitMapTest(BitMap* bm, DataType num);     //存在返回0，不存在返回-1
void BitMapDestory(BitMap* bm);
#endif