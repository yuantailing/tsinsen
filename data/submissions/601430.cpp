#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

#define __DISTURBANCE__ (1e-9)

#ifndef __STRUCT_MATRIX__
#define __STRUCT_MATRIX__

struct _MATRIX{
	int m;
	int n;
	double*p;
};
typedef struct _MATRIX MATRIX;
typedef MATRIX MAT;
typedef MATRIX* MATRIXP;
typedef MATRIX* MATP;
#endif

/**************************************************/
//销毁matp的指针指向的内存 
/**************************************************/

int JudgeMat(MATP matp)
{
	if ((matp->m<1)||(matp->n<1)){
		printf("矩阵验证失败，行数或列数小于1！\n\n");
		system("pause");
		exit(201);
	}
	if (!matp->p){
		printf("矩阵验证失败，矩阵链接无效！\n\n");
		system("pause");
		exit(202);
	}
	return(0);
}
int (*JudgeMatrix)(MATP matp)=JudgeMat;//函数的别称 

int JudgeDet(MATP matp)
{
	if ((matp->m<1)||(matp->n<1)){
		printf("行列式验证失败，行数或列数小于1！\n\n");
		system("pause");
		exit(211);
	}
	if (!matp->p){
		printf("行列式验证失败，矩阵链接无效！\n\n");
		system("pause");
		exit(212);
	}
	if (matp->m!=matp->n){
		printf("行列式验证失败，行数与列数不相等！\n\n");
		system("pause");
		exit(213);
	}
	return(0);
}

double AbsReal(double a)
{
	if (a<0) return(-a);
	return(a);
}

/**************************************************/
//自动比较实数大小，误差精度为文件开头定义的常量字符指针常量 
/**************************************************/
int CompareRealAuto(double a,double b)
{
	double e=__DISTURBANCE__;
	double delta=a*e;
	if (delta<0) delta=-delta;
	if ((a<e)&&(a>-e)&&(b<e)&&(b>-e)) return(0);
	if (((a-b)<delta)&&((a-b)>-delta)) return(0);
	if (a>b) return(1);
	return(-1);
}

/**************************************************/
//创建m*n的矩阵 
/**************************************************/
MATRIX NewMatrix(int m,int n)
{
	int i=0;
	if ((m<1)||(n<1)){
		printf("创建矩阵失败，行数或列数小于1！\n\n");
		system("pause");
		exit(101);
	}
	MATRIX new_matrix;
	new_matrix.m=m;
	new_matrix.n=n;
	new_matrix.p=(double*)malloc(m*n*sizeof(double));
	for (i=0;i<m*n;++i) *(new_matrix.p+i)=0;
	return(new_matrix);
}
MATRIX (*NewMat)(int m,int n)=NewMatrix;//函数名称简写//////////

/**************************************************/
//销毁matp的指针指向的内存 
/**************************************************/
int DestroyMatrix(MATP matp)
{
	JudgeMat(matp);
	free(matp->p);
	matp->p=NULL;
	return(0);
}
int (*DestroyMat)(MATP matp)=DestroyMatrix;//函数名称简写//////////

/**************************************************/
//复制矩阵 
/**************************************************/
MATRIX CopyMatrix(MATP matp)
{
	int i=0; 
	MATRIX copy=NewMatrix(matp->m,matp->n);
	copy.m=matp->m;
	copy.n=matp->n;
	for (i=0;i<copy.m*copy.n;++i){
		*(copy.p+i)=*(matp->p+i);
	}
	return(copy);
}
MATRIX (*CopyMat)(MATP mat)=CopyMatrix;//函数名称简写//////////

/**************************************************/
//提取matp_(i,j)的数值 
/**************************************************/
double NumberInMatrix(MATP matp,int i,int j)
{
	return(*((matp->p)+(i-1)*(matp->n)+j-1));
}
double (*NumInMat)(MATP matp,int i,int j)=NumberInMatrix;//函数名称简写//////////

/**************************************************/
//提取matp_(i,j)的地址 
/**************************************************/
double*AddressInMatrix(MATP matp,int i,int j)
{
	return((matp->p)+(i-1)*(matp->n)+j-1);
}
double*(*AddInMat)(MATP matp,int i,int j)=AddressInMatrix;//函数名称简写//////////

/**************************************************/
//将x赋给matp_(i,j)
/**************************************************/
int PutToMatrix(MATP matp,int i,int j,double x)
{
	*AddressInMatrix(matp,i,j)=x;
	return 0;
}
int (*PutToMat)(MATP matp,int i,int j,double x)=PutToMatrix;//函数名称简写//////////

/**************************************************/
//交换matp的第i、j行 
/**************************************************/
int ExchangeRow(MATP matp,int i,int j)
{
	int k=0;
	double temp;
	//JudgeMat(matp);
	//JudgeRowPosition(matp,i);
	//JudgeRowPosition(matp,j);
	for (k=1;k<=matp->n;++k){
		temp=NumberInMatrix(matp,i,k);
		*AddressInMatrix(matp,i,k)=*AddressInMatrix(matp,j,k);
		*AddressInMatrix(matp,j,k)=temp;        
	}
	return(0);
}

/**************************************************/
//交换matp的第i、j列 
/**************************************************/
int ExchangeColumn(MATP matp,int i,int j)
{
	double temp;
	int k=0;
	//JudgeMat(matp);
	//JudgeColPosition(matp,i);
	//JudgeColPosition(matp,j);
	for (k=1;k<=matp->m;++k){
		temp=NumberInMatrix(matp,k,i);
		*AddressInMatrix(matp,k,i)=*AddressInMatrix(matp,k,j);
		*AddressInMatrix(matp,k,j)=temp;        
	}
	return(0);
}
int (*ExchangeCol)(MATP matp,int i,int j)=ExchangeColumn;//函数名称简写//////////

/**************************************************/
//将第i行的x倍加到第j行 
/**************************************************/
int PlusRowByX(MATP matp,int i,int j,double x)
{
	int k=0;
	//JudgeMat(matp);
	//JudgeRowPosition(matp,i);
	//JudgeRowPosition(matp,j);
	for (k=1;k<=matp->n;++k){
		*AddressInMatrix(matp,j,k)+=x*(*AddressInMatrix(matp,i,k));
	}
	return(0);
}

/**************************************************/
//将第i列的x倍加到第j列 
/**************************************************/
int PlusColByX(MATP matp,int i,int j,double x)
{
	int k=0;
	//JudgeMat(matp);
	//JudgeColPosition(matp,i);
	//JudgeColPosition(matp,j);
	for (k=1;k<=matp->m;++k){
		*AddressInMatrix(matp,k,j)+=x*(*AddressInMatrix(matp,k,i));
	}
	return(0);
}

/**************************************************/
//将第i行变为原来的x倍 
/**************************************************/
int MultiplyRowByX(MATP matp,int i,double x)
{
	int k=0;
	for (k=1;k<=matp->n;++k){
		*AddressInMatrix(matp,i,k)*=x;
	}
	return(0);
}
int (*RowByX)(MATP matp,int i,double x)=MultiplyRowByX;//函数名称简写//////////

/**************************************************/
//将第j列变为原来的x倍 
/**************************************************/
int MultiplyColByX(MATP matp,int j,double x)
{
	int k=0;
	for (k=1;k<=matp->m;++k){
		*AddressInMatrix(matp,k,j)*=x;
	}
	return(0);
}
int (*ColByX)(MATP matp,int i,double x)=MultiplyColByX;//函数名称简写//////////

/**************************************************/
//计算行列式值|A| 
/**************************************************/
double Determinant(MATP matpoint)
{
	int i=0,j=0,k=0;
	double det=1;
	MATRIX matrix=CopyMatrix(matpoint);
	MATP matp=&matrix;
	JudgeDet(matp);
	for (i=1;i<=matp->n;++i){
		k=0;
		for (j=i;j<=matp->m;++j){
			if (CompareRealAuto(NumInMat(matp,i,j),0)!=0){
				k=j;
				break;
			}
		}
		if (k==0){
			DestroyMatrix(matp);
			return(0);
		}
		if (k!=i){
			ExchangeCol(matp,i,k);
			det*=(-1);
		}
		for (j=i+1;j<=matp->m;++j){
			PlusRowByX(matp,i,j,-NumInMat(matp,j,i)/NumInMat(matp,i,i));
		}
	}
	for (i=1;i<=matp->n;++i){
		det*=NumInMat(matp,i,i);
	}
	DestroyMatrix(matp);
	return(det);
}
double (*Det)(MATP matp)=Determinant;//函数名称简写//////////

/**************************************************/
//计算矩阵乘法AB 
/**************************************************/
MATRIX MatMultiplyMat(MATP a,MATP b)
{
	int i=0,j=0,k=0;
	MATRIX C=NewMatrix(a->m,b->n);
	if (a->n!=b->m){
		MATRIX err=NewMatrix(1,1); 
		printf("矩阵乘法验证失败，两个矩阵不能相乘！自动返回一阶零矩阵\n"); 
		return(err);
		exit(301);
	}
	for (i=1;i<=C.m;++i)
		for (j=1;j<=C.n;++j)
			for (k=1;k<=a->n;++k)
				*AddInMat(&C,i,j)+=NumInMat(a,i,k)*NumInMat(b,k,j); 
	return(C);
}
MATRIX (*MatByMat)(MATP a,MATP b)=MatMultiplyMat;//函数名称简写//////////

/**************************************************/
//计算矩阵的数量乘法kA 
/**************************************************/
MATRIX RealMultiplyMat(double k,MATP matp)
{
	int i=0;
	MATRIX C=CopyMatrix(matp);
	for (i=1;i<=C.m;++i){
		RowByX(&C,i,k);
	}
	return(C);
}
MATRIX (*RealByMat)(double k,MATP matp)=RealMultiplyMat;//函数名称简写//////////

/**************************************************/
//计算矩阵A的转置 
/**************************************************/
MATRIX TransposeMatrix(MATP matp)
{
	int i=0,j=0;
	MATRIX AT=NewMatrix(matp->n,matp->m);
	for (i=1;i<=matp->m;++i){
		for (j=1;j<=matp->n;++j){
			*AddInMat(&AT,j,i)=NumInMat(matp,i,j);
		}
	}
	return(AT);
}
MATRIX (*TransMat)(MATP matp)=TransposeMatrix;//函数名称简写//////////

/**************************************************/
//计算行列式A的关于(i,j)的余子式 
/**************************************************/
double ComplementMinor(MATP matp,int i,int j)
{
	int k=0;
	MATRIX C=CopyMatrix(matp); 
	for (k=1;k<=matp->n;++k){
		*AddInMat(&C,i,k)=0;
	}
	for (k=1;k<=matp->m;++k){
		*AddInMat(&C,k,j)=0;
	}
	*AddInMat(&C,i,j)=1;
	return(Det(&C));
}

/**************************************************/
//计算行列式A的关于(i,j)的代数余子式 
/**************************************************/
double AlgebraicComplement(MATP matp,int i,int j)
{
	if ((i+j)%2==0){
		return(ComplementMinor(matp,i,j));
	}
	return(-ComplementMinor(matp,i,j));
}
double (*Algebraic)(MATP matp,int i,int j)=AlgebraicComplement;//函数名称简写//////////

/**************************************************/
//计算伴随矩阵A*
/**************************************************/
MATRIX AdjointMatrix(MATP matp)
{
	int i=0,j=0;
	MATRIX C=NewMatrix(matp->m,matp->n);
	JudgeDet(matp);
	for (i=1;i<=C.m;++i){
		for (j=1;j<=C.n;++j){
			*AddInMat(&C,i,j)=AlgebraicComplement(matp,j,i);
			if ((i+j)%2) *AddInMat(&C,i,j)*=-1;
		}
	}
	return(C);
}
MATRIX (*AdjMat)(MATP matp)=AdjointMatrix;//函数名称简写//////////

/**************************************************/
//计算逆矩阵A^(-1) 
/**************************************************/
MATRIX InverseMatrix(MATP matp)
{
	int i=0,j=0;
	MATRIX C=AdjointMatrix(matp);
	double det=Det(matp);
	//JudgeDet(matp);
	if (!CompareRealAuto(det,0)){
		printf("矩阵求逆失败，矩阵是不可逆的（奇异的）！默认返回单位阵。\n"); 
		for (i=1;i<=C.m;++i){
			for (j=1;j<=C.n;++j){
				*AddInMat(&C,i,j)=0;
			}
		}
		for (i=1;i<=C.m;++i){
			*AddInMat(&C,i,i)=1;
		}
		return(C);
	}
	for (i=1;i<=C.m;++i){
		for (j=1;j<=C.n;++j){
			*AddInMat(&C,i,j)/=det;
		}
	}
	return(C);
}
MATRIX (*Inverse)(MATP matp)=InverseMatrix;//函数名称简写//////////

int main()
{
	int n;
	cin>>n;
	MATRIX A=NewMatrix(n,n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			double x;
			cin>>x;
			PutToMatrix(&A,i,j,x);
		}
	MATRIX D=InverseMatrix(&A);
	MATRIX b=NewMatrix(n,1);
	for (int i=1;i<=n;i++)
	{
		double x;
		cin>>x;
		PutToMatrix(&b,i,1,x);
	}
	MATRIX x=MatMultiplyMat(&D,&b);
	for (int i=1;i<=n;i++)
		printf("%.2lf\n",NumberInMatrix(&x,i,1));
	DestroyMatrix(&A);
	DestroyMatrix(&D);
	DestroyMatrix(&b);
	DestroyMatrix(&x);
	//system("pause");
	return 0;
}
