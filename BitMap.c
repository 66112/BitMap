#include "BitMap.h"
void BitMapInit(BitMap* bm, size_t range)
{
	assert(bm);
	bm->_bits = (char*)malloc((range >> 3) + 1);
	memset(bm->_bits, 0, (range >> 3) + 1);
}

void BitMapSet(BitMap* bm, DataType num)
{
	assert(bm);
	size_t i = -1;                      //最大的正整数
	int index1, index2, index3;         //3个映射
	int max = i >> 3;                   //max为最后一个组
	int bit = num % 8;
	index1 = num >> 3;
	if (index1 > 0 && index1 < max)     //位置在中间
	{
		index2 = index1 - 1;
		index3 = index1 + 1;
	}
	else if (index1 == max)             //位置在最后
	{
		index2 = index1 - 1;
		index3 = index1 - 2;
	}
	else                                //在第一个字节处
	{
		index2 = index1 + 1;
		index3 = index1 + 2;
	}
	(bm->_bits[index1]) |= (1 << bit);
	(bm->_bits[index2]) |= (1 << bit);
	(bm->_bits[index3]) |= (1 << bit);
	printf("置1成功！\n");
}
void BitMapReSet(BitMap* bm, DataType num)
{
	assert(bm);
	int panduan = BitMapTest(bm, num);
	if (panduan == -1)
	{
		printf("该数不存在！\n");
		return;
	}
	else
	{
		size_t i = -1;                      //最大的正整数
		int index1, index2, index3;         //3个映射
		int max = i >> 3;                   //max为最后一个组
		int bit = num % 8;
		index1 = num >> 3;
		if (index1 > 0 && index1 < max)     //位置在中间
		{
			index2 = index1 - 1;
			index3 = index1 + 1;
		}
		else if (index1 == max)             //位置在最后
		{
			index2 = index1 - 1;
			index3 = index1 - 2;
		}
		else                                //在第一个字节处
		{
			index2 = index1 + 1;
			index3 = index1 + 2;
		}
		bm->_bits[index1] ^= (1 << bit);              //将映射的位置置0
		bm->_bits[index2] ^= (1 << bit);
		bm->_bits[index3] ^= (1 << bit);
		printf("置0成功！\n");
	}
}
int BitMapTest(BitMap* bm, DataType num)
{
	assert(bm);
	size_t i = -1;                      //最大的正整数
	int index1, index2, index3;         //3个映射
	int max = i >> 3;                   //max为最后一个组
	int bit = num % 8;
	index1 = num >> 3;
	if (index1 > 0 && index1 < max)     //位置在中间
	{
		index2 = index1 - 1;
		index3 = index1 + 1;
	}
	else if (index1 == max)             //位置在最后
	{
		index2 = index1 - 1;
		index3 = index1 - 2;
	}
	else                                //在第一个字节处
	{
		index2 = index1 + 1;
		index3 = index1 + 2;
	}
	return (bm->_bits[index1] == ((1 << bit) | (bm->_bits[index1])))&&
		   (bm->_bits[index2] == ((1 << bit) | (bm->_bits[index2])))&&
		   (bm->_bits[index3] == ((1 << bit) | (bm->_bits[index3]))) ? 0 : -1;  //判断映射位置是否为1
}

void BitMapDestory(BitMap* bm)
{
	assert(bm);
	free(bm->_bits);
	bm->_bits = NULL;
}

void test()
{
	BitMap bm;
	BitMapInit(&bm, -1);
	BitMapSet(&bm, -1);
	BitMapSet(&bm, 7);
	BitMapSet(&bm, 8);
	BitMapReSet(&bm, 8);
	BitMapReSet(&bm, 8);
	BitMapDestory(&bm);
}
int main()
{
	test();
	return 0;
}