#ifndef __BIT_MAP__
#define __BIT_MAP__
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#define DataType size_t

typedef struct BitMap
{
	char* _bits;      //λͼָ��
	size_t _range;    //������
}BitMap;

void BitMapInit(BitMap* bm, size_t range);
void BitMapSet(BitMap* bm, DataType num);      //��1
void BitMapReSet(BitMap* bm, DataType num);		//��0
int BitMapTest(BitMap* bm, DataType num);     //���ڷ���0�������ڷ���-1
void BitMapDestory(BitMap* bm);
#endif