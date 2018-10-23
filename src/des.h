/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * Blog		 : rebelice.github.io
 * ************************************************************************/
#ifndef _DES_H_
#define _DES_H_
extern int TR;
extern void desEncrypt(int* M, int* K, int* C);
extern void desDecrypt(int* C, int* K, int* M);
#endif
