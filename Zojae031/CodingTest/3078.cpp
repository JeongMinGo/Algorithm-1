#include<iostream>
#include <string>
#include<vector>
#include<list>
using namespace std;
int main() {
	int n, k;
	long long cnt = 0;
	int deleteIndex = 0;
	cin >> n>> k;
	getchar();
	
	vector<int>v;
	vector<int> windows(21);
	string data;
	for (int i = 0; i < n; i++) {
		getline(cin, data);
		v.push_back(data.length());
	}

	
	for(int i=0 ; i<n ; i++){
		deleteIndex = i - k - 1;//������ ������ i:���� �ε���, k:������ũ��, 1:���κ��� ����ĭ���� ����
		//�ڿ��� ����
		if (deleteIndex >= 0 && windows[v[deleteIndex]] > 0) {
			windows[v[deleteIndex]]--;
		}
		//���� ������ϱ�
		int compare = v[i];
		//���� �ش� �����ȿ� �����ϸ� ī����
		if (windows[compare] > 0) {
			cnt+=windows[compare];
		}
		//������ ����
		windows[compare]++;
	}
	
	cout << cnt;
	return 0;
}
