#include <iostream>
#include <limits>

using namespace std;

#include "Stats.cpp"


void displayMenu();
int validateInput(int userSelection);

int main()
{
	// Instantiate Stat to create our list of numbers object. 
	Stats numberList;
	int userSelection = 0;
	int num = 0;
	int found; 

	cout << "\n~Welcome to dataset statistics. Please choose a menu option.~\n";
	do
	{
		displayMenu();
		cin >> userSelection;
		userSelection = validateInput(userSelection);

		switch (userSelection)
		{
		case 0:
			return 0;
		case 1:
			cout << "\nEnter the number you would like to add to dataset: ";
			cin >> num;
			num = validateInput(num);
			numberList.addNumber(num);
			break;

		case 2:
			cout << "\nEnter the number you would like to remove from dataset: ";
			cin >> num;
			num = validateInput(num);
			numberList.removeNumber(num);
			break;

		case 3:
			numberList.removeAll();
			break;

		case 4:
			numberList.display();
			break;

		case 5:
			cout << "\n\n[Statistics]";
			if (numberList.empty())
			{
				cout << "\n\t(!) Please populate dataset first.";
				break; 
			}
			cout << "\n- Minimum: " << numberList.minimum();
			cout << "\n- Maximum: " << numberList.maximum();
			cout << "\n- Sum: " << numberList.sum();
			cout << "\n- Mean: " << numberList.mean();
			cout << "\n- Median: " << numberList.median();
			break;

		default:
			cout << "\n\t(!) Invalid input, please enter a numerical choice from the menu";
			break; 
		}
		
	} while (userSelection != 0);
	

	return 0;
}

void displayMenu()
{
	// Welcome message.
	cout << "\n\n\n[Menu]";
	cout << "\n1. Enter a new number.";
	cout << "\n2. Remove a number.";
	cout << "\n3. Clear entire dataset.";
	cout << "\n4. Display all numbers in dataset.";
	cout << "\n5. Display dataset statistics.";
	cout << "\n0. Exit.\n";
	cout << "***********************************";
	cout << "\nSelection > ";
}

// Ensure all menu input is int. 
int validateInput(int input)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "(!)Please enter a valid number > ";
			cin >> input;
		}
		if (!cin.fail())
			break;
	}
	return input; 
}