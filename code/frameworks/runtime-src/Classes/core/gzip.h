#pragma once


int gzCompress(const char *src, int srcLen, char *dest, int destLen);
int gzDecompress(const char *src, int srcLen, const char *dst, int dstLen);


//static int gzipTest()
//{
//	char* src = "with xzcno nmklxzfa l;madaiklhjadbjkahsgdgkjasdb jkzxhfakl";
//	int size_src = strlen(src);
//	char* compressed = (char*)malloc(size_src * 2);
//	memset(compressed, 0, size_src * 2);
//	CCLOG("to compress src: %s\n", src);
//	CCLOG("to compress src size: %d\n", size_src);
//
//	int gzSize = gzCompress(src, size_src, compressed, size_src * 2);
//	if (gzSize <= 0)
//	{
//		CCLOG("compress error.\n");
//		return -1;
//	}
//	CCLOG("compressed: ");
//	int i = 0;
//	for (; i < gzSize; ++i)
//	{
//		CCLOG("%02x ", compressed[i]);
//	}
//	CCLOG("\ncompressed size: %d\n", gzSize);
//
//	char* uncompressed = (char*)malloc(size_src * 2);
//	memset(uncompressed, 0, size_src * 2);
//	int ret = gzDecompress(compressed, gzSize, uncompressed, size_src * 2);
//	CCLOG("uncompressed: %s\n", uncompressed);
//	CCLOG("uncompressed size: %d\n", strlen(uncompressed));
//
//	free(compressed);
//	free(uncompressed);
//	return 0;
//}