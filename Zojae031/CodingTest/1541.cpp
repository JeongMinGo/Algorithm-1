#include<iostream>
#include <string.h>
#include<string>
#include <stack>
using namespace std;
int main() {
	int start = 0;
	string input;
	string oper;
	stack<string> s;
	int result = 0;
	getline(cin, input);
	//���ÿ� �о�ֱ�
	for (int i = 0; i < input.size(); i++) {
		if (!(input[i] >= '0' &&input[i] <= '9')) {
			string tmp = input.substr(start, i - start);
			string oper = input.substr(i, 1);
			s.push(tmp);
			s.push(oper);
			start = i + 1;
		}
	}
	s.push(input.substr(start, input.size() - start));

	//Algorithm
	int mid=0;
	
	while (!s.empty()) {
		string tmp = s.top();
		s.pop();
		if (strcmp(tmp.c_str(), "-") && strcmp(tmp.c_str(), "+")) {//���� Ǫ��
			mid = atoi(tmp.c_str());
		}
		else {
			if (!strcmp(tmp.c_str(), "-")) { // -
				result += -mid;
			}
			else {// +
				mid += atoi(s.top().c_str());
				s.pop();
			}
		}
		
		// - ���ö����� ��
		// + �� ���ÿ��ִ°� ����
		// - ������ ���� ���°��� -�� �ٿ�
		//�״��� �Ѱ��� �������
	}
	result += mid;
	cout << result;
	return 0;
}