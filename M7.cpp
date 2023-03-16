#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    while (true)
    {
        try
        {
            setlocale(LC_ALL, "RU");
            int size;
            cout << "Введите размер контейнера " << endl;
            cin >> size;
            IntArray array(size);

            for (int i{ 0 }; i < size; ++i)
                array[i] = i + 1;

            while (true)
            {
                try 
                {
                    system("cls");
                    for (int i{ 0 }; i < array.getLength(); ++i)
                        cout << array[i] << ' ';
                    cout << '\n';
                    int VE, RM;

                    cout << "Выберите действие:\n1-изменить размер\n2-изменить число ячейки\n3-удалить ячейку\n4-узнать размер контейнера\n5-изменить первое число\n6-изменить последнее число" << endl;
                    cin >> VE;
                    switch (VE)
                    {
                    case 1:
                        cout << "Введите новый размер" << endl;
                        cin >> RM;
                        array.resize(RM);
                        break;
                    case 2:
                        cout << "Введите номер ячейки" << endl;
                        cin >> RM;
                        array.insertBefore(RM - 1);
                        break;
                    case 3:
                        cout << "Введите номер ячейки" << endl;
                        cin >> RM;
                        array.remove(RM - 1);
                        break;
                    case 4:
                        array.getSize();
                        system("pause");
                        break;
                    case 5:
                        cout << "Введите число" << endl;
                        cin >> RM;
                        array.insertAtBeginning(RM);
                        break;
                    case 6:
                        cout << "Введите число" << endl;
                        cin >> RM;
                        array.insertAtEnd(RM);
                        break;
                    default:
                        break;
                    }
                }
                catch (const char* ex)
                {
                    cout << ex << endl;
                    system("pause");
                }
            }
            return 0;
        }
        catch (const char* ex)
        {
            cout << ex << endl;
        }
    }
}