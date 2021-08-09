#include <iostream>

using namespace std;

// 坐标或向量的结构
struct pointer {
	int x;
	int y;
};

// 将A坐标按B向量平移，结果保存在C坐标中。
void move(pointer *C, pointer *A, pointer *B)
{
C->x = A->x + B->x;
C->y = A->y + B->y;
}

int main()
{
	pointer A, B, C;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	move(&C, &A, &B);
	cout << C.x << " " << C.y;
	return 0;
}
