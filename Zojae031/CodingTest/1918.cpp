#include<iostream>
#include <stack>
#include<string>
using namespace std;
#pragma warning (disable:4996)
/*
+,- : 1
*,/ : 2
(,) : 3
*/
int main() {
	stack<pair<char, int>> s;
	string str;
	char ch = '\0';
	/*
	������ �� ���� ������ �״�� Ǫ��
	������ �� ���� ���ų� ������ �ٲ� ����
	*/
	getline(cin, str);
	int idx = 0;
	while (idx!=str.size()) {
		ch = str[idx++];
		if (ch == '(') {//��ȣ
			s.push(pair<char, int>(ch, 0));
		}
		else if (ch == ')') {//�ݴ� ��ȣ5
			while (s.top().first != '(') {
				printf("%c", s.top().first);
				s.pop();
			}
			s.pop();
		}
		else if (ch >= 'A' && ch <= 'Z') {//�ǿ�����
			printf("%c", ch);
		}
		else {//������
			pair<char, int> p;
			switch (ch)
			{
			case '+': p.second = 1; break;
			case '-': p.second = 1; break;
			case '*': p.second = 2; break;
			case '/': p.second = 2; break;
			}
			p.first = ch;


			while (!s.empty() && s.top().second >= p.second) {//�ڱ⺸�� �켱���� ���� ������ ���� �� ����
				printf("%c", s.top().first);
				s.pop();
			}

			s.push(p);
		}
	}


	while (!s.empty()) {
		printf("%c", s.top().first);
		s.pop();
	}
	return 0;
}

/*
A*(B+C)
A+(B*C)*D*E+F
(A+(B*C))-(D/E)
A+B*C+D
*/