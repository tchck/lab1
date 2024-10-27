#include <iostream>
#include <string>
#include "Keeper.h"
#include "cat.h"
#include "bird.h"
#include "fish.h"
using namespace std;
void showMenu()
{
    std::cout << "\nMenu:\n"
        "1. Add animal\n"
        "2. Remove animal\n"
        "3. Print animal\n"
        "4. Save to File\n"
        "5. Restore from File\n"
        "6. Exit\n";
}
int main()
{
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
                cout << "\nEnter animal type\n"
                    "1. Cat 2. Bird 3. Fish:\n";
                cin >> instrument;
                switch (instrument) {
                case 1: {
                    string species;
                    string color;
                    string owner;
                    string name;
                    Cat* ca;
                    cout << "Enter cat species:\n";
                    cin >> species;
                    cout << "Enter cat color:\n";
                    cin >> color;
                    cout << "Enter cat owner:\n";
                    cin >> owner;
                    cout << "Enter cat name:\n";
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
                    cout << "Enter bird species:\n";
                    cin >> species;
                    cout << "Enter bird color:\n";
                    cin >> color;
                    cout << "Enter bird food:\n";
                    cin >> food;
                    cout << "Enter bird text area:\n";
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
                    cout << "Enter fish species:\n";
                    cin >> species;
                    cout << "Enter fish color:\n";
                    cin >> color;
                    cout << "Enter fish food:\n";
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
                cout << "Enter animal index:\n";
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
                keeper.load("output.txt");
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

