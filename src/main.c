/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * Blog		 : rebelice.github.io
 * ************************************************************************/
#include "des.h"
#include <stdio.h>
#include <ctype.h>

#define LEN 100
int TR;
static int A[64], B[64], C[64];

int read(FILE *f)
{
	char c;
	c = getc(f);
	while (c < '0' || c > '1') c = getc(f);
	return c-'0';
}

void main()
{
	int i, mode;
	char s1[LEN], s2[LEN];
	FILE *f1, *f2, *f3;
	TR = 8;
	printf("当前为%d轮DES算法！\n", TR);
	printf("请输入单个数字 0 表示加密模式，或者输入单个数字 1 表示解密模式:\n");
	scanf("%d", &mode);
	fflush(stdin);
	printf("请输入完整秘钥文件名:\n");
	scanf("%s", s2);
	fflush(stdin);
	while ((f2=fopen(s2, "r"))==NULL)
	{
		printf("无法打开该文件，请保证秘钥文件与可执行文件在同一目录下并检查文件名后重新输入:\n");
		scanf("%s", s2);
		fflush(stdin);
	}
	for (i = 0; i < 64; i++)
		B[i] = read(f2);
	fclose(f2);	
	if (mode == 0)
	{
		printf("当前为加密模式！\n请输入完整明文文件名:\n");
		scanf("%s", s1);
		fflush(stdin);
		while ((f1=fopen(s1, "r"))==NULL)
		{
			printf("无法打开该文件，请保证明文文件与可执行文件在同一目录下并检查文件名后重新输入:\n");
			scanf("%s", s1);
			fflush(stdin);
		}
		for (i = 0; i < 64; i++)
			A[i] = read(f1);
		fclose(f1);
		desEncrypt(A, B, C);
		f3 = fopen("Ans.txt", "w");
		for (i = 0; i < 64; i++)
			fprintf(f3, "%d", C[i]);
		fclose(f3);
		printf("密文已放入Ans.txt中!\n");
	}
	else
	{
		printf("当前为解密模式！\n请输入完整密文文件名:\n");
		scanf("%s", s1);
		fflush(stdin);
		while ((f1=fopen(s1, "r"))==NULL)
		{
			printf("无法打开该文件，请保证明文文件与可执行文件在同一目录下并检查文件名后重新输入:\n");
			scanf("%s", s1);
			fflush(stdin);
		}
		for (i = 0; i < 64; i++)
			A[i] = read(f1);
		fclose(f1);
		desDecrypt(A, B, C);
		f3 = fopen("Ans.txt", "w");
		for (i = 0; i < 64; i++)
			fprintf(f3, "%d", C[i]);
		fclose(f3);
		printf("明文已放入Ans.txt中!\n");
	}
}
