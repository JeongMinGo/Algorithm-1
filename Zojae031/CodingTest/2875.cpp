#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main() {
	int n, m, k;//n :����2, m :����1, k : ���Ͻ�
	int team = 0;
	int cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	//case 1 : ���� n�� m���� k�� ä�� �� �ִ�?
	//else : ��ä��� ����
	//case 2 : ���� ���� ���� �� �ֳ�?
	//else : ������� ����
	while (true) {
		if (n - 2 + m - 1 >= k) { //case 1
			if (n - 2 >= 0 && m - 1 >= 0) {
				n -= 2;
				m -= 1;
				team++;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
		
	}
	printf("%d", team);
	return 0;
}