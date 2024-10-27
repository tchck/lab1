#include <iostream>
#include <string>
#include "Keeper.h"
#include "cat.h"
#include "bird.h"
#include "fish.h"
using namespace std;

void showMenu()
{
    std::cout << "\nМеню:\n"
        "1. Добавить животное\n"
        "2. Удалить животное\n"
        "3. Вывести животное на экран\n"
        "4. Сохранить в файл\n"
        "5. Загрузить из файла\n"
        "6. Выход\n";
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Keeper keeper;
    while (true)
    {
        showMenu();
        int choice;
        cout << "\nEnter your choice:\n";
        cin >> choice;
        try {
            switch (choice) {
            case 1: {
                int instrument;
                cout << "\nВыберите тип животного\n"
                    "1. Кошка \n2. Птица \n3. Рыба:\n";
                cin >> instrument;
                switch (instrument) {
                case 1: {
                    string species;
                    string color;
                    string owner;
                    string name;
                    Cat* ca;
                    cout << "Введите породу кошки:\n";
                    cin >> species;
                    cout << "Введите окрас кошки:\n";
                    cin >> color;
                    cout << "Введите ФИО владельца кошки:\n";
                    cin >> owner;
                    cout << "Введите кличку кошки:\n";
                    cin >> name;
                    ca = new Cat(species, color, owner, name);
                    keeper.add(ca);
                    break;
                }
                case 2: {
                    string species;
                    string color;
                    string food;
                    string area;
                    Bird* bir;
                    cout << "Введите породу птицы:\n";
                    cin >> species;
                    cout << "Введите окрас птицы:\n";
                    cin >> color;
                    cout << "Введите, чем птица питается:\n";
                    cin >> food;
                    cout << "Введите, где птица обитает:\n";
                    cin >> area;
                    bir = new Bird(species, color, food, area);
                    keeper.add(bir);
                    break;
                }
                case 3: {
                    string species;
                    string color;
                    string food;
                    Fish* fish;
                    cout << "Введите породу рыбы:\n";
                    cin >> species;
                    cout << "Введите окрас рыбы:\n";
                    cin >> color;
                    cout << "Введите тип питания рыбы:\n";
                    cin >> food;
                    fish = new Fish(species, color, food);
                    keeper.add(fish);
                    break;
                }
                default: {
                    cout << "Invalid type\n";
                    break;
                }
                }
                break;
            }
            case 2: {
                int index;
                cout << "Введите номер животного:\n";
                cin >> index;
                keeper.remove(index);
                break;
            }
            case 3: {
                keeper.print();
                break;
            }
            case 4: {
                keeper.save("output.txt");
                break;
            }
            case 5: {
                keeper.load("input.txt");
                break;
            }
            case 6: {
                cout << "Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice\n";
                break;
            }
            }
        }
        catch (Exception error)
        {
            cout << error;
        }
    }
}

