#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int arr[2];
	double result = 0.0;
	int cnt = 0;
	for(int i=0 ;i <2 ; i++)
	scanf("%d", &arr[i]);
	//��
	if (arr[0] == arr[1]) {
		result = (143 + arr[0])/ 153.0 ; //�Ϲ��� �����ع���
	}
	else {//��
		int g = (arr[0] + arr[1]) % 10;
		for (int i = 1; i <= 10; i++) {
			if (i == arr[0] || i == arr[1]) continue; //���� �����̰� �̹� ���� ī��� ��ŵ
			for (int j = 1; j <= 10; j++) {
				if ((i != j) && ((i + j) % 10 < g)) {// ���� �ƴϰ� && ������ ���� ���
					cnt++;
				}
			}
		}
		cnt*= 2;
		/*
		1 2 3 4 5 6 7 8 9 10 : i
		1 2 3 4 5 6 7 8 9 10 : j
		-> (2i,8j), (8i,2j) �� ��������� �����δ� (2i,8i), (2j,8j)�� �����ϱ� ������ cnt x 2�� ���ش�
		*/
		result = cnt / 153.0;
	

	}
	printf("%.3lf", result);
	return 0;
}
