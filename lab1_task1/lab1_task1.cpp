/*
9.	��������� ��� ��������� �������������� ��������� f: [m] -> [n].
*/

#include <iostream>
using namespace std;

// ������� ��� �������� ��������� ��������
int inputInt() {
    int number;

    // �������� �� ������������ ���� Integer
    while ((!(cin >> number) || (cin.peek() != '\n'))) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "��������� ����:\n  > ";
    }

    // �������� ����� �� ���������������
    if (number <= 0) {
        cout << "��������� ����:\n  > ";
        number = inputInt();
    }

    return number;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "�������: \n";
    cout << "  1. �������� ������ ���� ��������������\n\n";

    /*
    cout << "������� ���������� �������� � ������ ���������:\n  > ";
    int firstCountNumbers = inputInt();

    cout << "������� ���������� �������� �� ������ ���������:\n  > ";
    int secondCountNumbers = inputInt();
    */

    int firstSetNumbers[3] = { 5, 8, 9 };
    int secondSetNumbers[4] = { 5, 10, 12, 15 };

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            int f = i % 3;
            cout << "{" << firstSetNumbers[f] << ", " << secondSetNumbers[j] << "}" << " ";
        }
        cout << "\n";
    }

    //std::cout << "������� 9\n";
    //std::cout << firstSet << " " << secondSet;
}