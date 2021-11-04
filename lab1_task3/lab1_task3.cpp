/*
29.	����� ����� ������ 1/(i1, i2, � , im) 
�� ���� ������������� {i1, i2, � , im} ��������� {1, 2, �, n}.
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

    cout << "��� ����������� ����������� ����������� �������������\n";
    cout << "������� ���������� �������� ������ ����� �����������\n\n";

    cout << "������� ���������� �����������:\n  > ";
    int countSubset = inputInt();

    // ���������� ����� �����������
    int sumSubset = 0;
    for (int currentSubset = 1; currentSubset <= countSubset; currentSubset++) {
        sumSubset += currentSubset;
    }
    std::cout << "\n����� �����������: " << sumSubset << "\n\n";

    cout << "������� ���������� ��������:\n  > ";
    int countSet = inputInt();

    // ���������� ����� ��������
    double sumSet = 0;
    for (int currentSet = 1; currentSet <= countSet; currentSet++) {
        sumSet += currentSet/sumSubset;
    }
    std::cout << "\n����� ��������: " << sumSet << "\n";

}