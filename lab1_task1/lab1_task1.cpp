/*
9.	��������� ��� ��������� �������������� ��������� f: [m] -> [n].
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Surjection {

    int countSurjection = 1; // ������� ���������� ���������

    static const int maxSizeSet = 8; // ������������ ������ ��������
    int sizeFirstSet = maxSizeSet;   // ����������� ������� ���������
    int sizeSecondSet = maxSizeSet;  // ����������� ������� ���������

    int numbersFirstSet[maxSizeSet] = { 1, 2, 3, 4, 5, 6, 7, 8 }; // �������� ������� ���������
    char lettersSecondSet[maxSizeSet] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' }; // �������� ������� ���������

    int* firstSet = new int[sizeSecondSet]; // �������� ������� ��������� �� �������� ������� ���������
    int* color = new int[sizeFirstSet];     // ��������������� ������ ��� �������� ���������� �������

public:

    Surjection() {

        // ��������� ������� �������� ��������
        for (int i = 0; i < maxSizeSet; i++)
        {
            color[i] = 0;
            firstSet[i] = 0;
        }
    }

    // ����� ��� �������� ��������� �������� ������� ���������
    int inputInt() {
        int number;

        cout << "  ���������� ����������� ��� ������� ���������:\n  > ";

        // �������� �� ������������ ���� Integer
        while ((!(cin >> number) || (cin.peek() != '\n'))) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  ���������� ����������� ��� ������� ���������:\n  > ";
        }

        // ����� ������ ���� �� 1 �� 8
        if (number < 1 || number > maxSizeSet) number = inputInt();
        return number;
    }

    // ����� ��� �������� ��������� �������� ������� ���������
    int inputInt(int firstNumber) {
        int number;

        cout << "  ���������� ����������� ��� ������� ���������:\n  > ";

        // �������� �� ������������ ���� Integer
        while ((!(cin >> number) || (cin.peek() != '\n'))) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "  ���������� ����������� ��� ������� ���������:\n  > ";
        }

        // ����� ������ ���� �� firstNumber �� 8
        if (number < firstNumber || number > maxSizeSet) number = inputInt(firstNumber);
        return number;
    }

    // �����, � ������� ��������������� ����������� ��������
    void setSizes() {

        cout << "�������: \n";
        cout << "  1. �������� ������ ���� ��������������\n";
        cout << "  2. ����������� ������� ��������� ������ ���� >= �������\n";
        cout << "  3. ������������ ����������� �������� - 8\n\n";

        sizeFirstSet = inputInt();
        sizeSecondSet = inputInt(sizeFirstSet);

        cout << endl;

        const int firstPosition = 0;
        setElementOnPosition(firstPosition);
    }

    // ����� ��� �������� � ������ �������� �������
    void output() {

        // ������� ������ �� �������, ������� �������� ��������� ���������������
        for (int i = 0; i < sizeSecondSet - 1; i++)
        {
            if (firstSet[i] < firstSet[i + 1]) return;
        }

        bool isWrongArray = false; // isWrongArray - ������ �� ������������� ��������

        // ��������� ��������������� ������, � �������
        // 1 - ������ ����� ������� � �������, 0 - �� �������
        for (int i = 0; i < sizeSecondSet; i++)
        {
            for (int j = 0; j < sizeFirstSet; j++)
            {
                if (firstSet[i] == numbersFirstSet[j]) color[j] = true;
            }
        }

        // ������������� ������ ������� ���������������� �������
        for (int i = 0; i < sizeFirstSet; i++)
        {
            // ���� � ������� �� ���� ������� ���� ��������� �� ������� (�������� 0)
            if (color[i] == false) isWrongArray = true;

            // cout << color[i] << " ";

            // ������� ������
            color[i] = false;
        }
        // cout << endl;

        // �� ������� ������ �� �����, ���� � �� �� ��� ��������
        if (isWrongArray) {
            // ���� ����� ��������� �����, �� ������ color[] �� ���������
            return;
        }

        // ������� ����� ������� �� �����
        cout << setw(5) << countSurjection << ") ";
        countSurjection++;

        // ������� ������ �� �����
        for (int i = 0; i < sizeSecondSet; i++)
        {
            cout << firstSet[i] << lettersSecondSet[i] << " ";
        }
        cout << endl;
    }

    // ����������� ����� ��� ���������� �������
    void setElementOnPosition(int position) {

        // ���� �� ���� �������� ����������� ��������
        if (position == sizeSecondSet) {

            output();
            return;
        }

        for (int i = 0; i < sizeFirstSet; i++)
        {
            // ������������� ������� �� �������
            firstSet[position] = numbersFirstSet[i];

            // �������� �������� ��� ����������� �������
            setElementOnPosition(position + 1);

            // ������� ������
            firstSet[position] = 0;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");

    Surjection surjection;
    surjection.setSizes();
}