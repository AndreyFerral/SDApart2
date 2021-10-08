/*
19.	������������ ������� ������������������� ����� ����� 
    n >= x1 >= � >= xm >= 0.
*/

#include <iostream>
using namespace std;

// ������� ��� �������� ��������� ��������
int inputInt() {
    int number;

    cout << "������� ������ ��������:\n  > ";

    // �������� �� ������������ ���� Integer
    while ((!(cin >> number) || (cin.peek() != '\n'))) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "������� ������ ��������:\n  > ";
    }

    // �������� ����� �� ���������������
    if (number < 0) number = inputInt();
    return number;
}

// ������� ��� �������� ��������� ��������
int inputInt(int firstNumber) {
    int number;

    cout << "������� ������ ��������:\n  > ";

    // �������� �� ������������ ���� Integer
    while ((!(cin >> number) || (cin.peek() != '\n'))) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "������� ������ ��������:\n  > ";
    }

    // �������� ����� - ������ �� �������
    if (number <= firstNumber) number = inputInt(firstNumber);
    return number;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "�������: \n";
    cout << "  1. ������ �������� ������ ���� ������ �������\n";
    cout << "  2. �������� ������ ���� ��������������\n\n";

    int m = inputInt();
    int n = inputInt(m);

    cout << "\n�������� �����: " << m << " " << n << "\n\n";

    // ����� �����
    for (int number = m; number <= n; number++) {
        cout << number << " ";
    } cout << "\n";
}