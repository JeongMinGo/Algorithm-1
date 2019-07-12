#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int * arr;
	int n;
	int input;

	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	int max = n; //������ ���簢�� ���̸� �ϴ� �ְ�� ��Ƶд�.

	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		arr[i] = input;
	}


	int cnt = 1;
	int i = 0, j = 0;
	while (i < n) {// n
		int base = arr[i++];
		if (max < base) { //���� ���簢�� ���� ��
			max = base;
		}
		j = i;
		while (j < n) { //n
			if (base - arr[j] <= 0) {//���� �� ���� - ���� ���� < 0
				j++;
				cnt++;
				if (max < base * cnt) {
					max = base * cnt;
				}
			}
			else { // �� ���� - ���� ���� >0
				base--;//�� �ڽ��� �ϳ� �� ������ �����
			}

		}
		cnt = 1;
	}

	//	O(n^2)
	printf("%d",max);

	return 0;
}

