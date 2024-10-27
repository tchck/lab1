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
