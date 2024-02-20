//STILL NEED TO WRITE: SORT()

#include "Stats.h"

// Constructor.
Stats::Stats()
{
	current = 0;
	counter = 0;
}


// Returns lowest value of dataset. 
int Stats::minimum()
{
	// Fail if dataset is empty.
	if (counter == 0)
		return 0;

	sort();
	return numberList[0];
}


// Returns highest value of dataset. 
int Stats::maximum()
{
	// Fail if dataset is empty. 
	if (counter == 0)
		return 0;
	sort();
	return numberList[counter - 1];
}


// Returns sum of dataset items. 
int Stats::sum()
{
	// Fail if dataset is empty. 
	if (counter == 0)
		return 0;

	int sum = 0;
	for (int i = 0; i < counter; i++)
		sum += numberList[i];
	return sum;
}


// Returns mean of dataset. 
double Stats::mean()
{
	// Fail if dataset is empty.
	if (counter == 0)
		return 0;

	double sum = 0;
	double average = 0;
	for (int i = 0; i < counter; i++)
		sum += numberList[i];
	average = sum / counter;
	return average;
}


// Returns median of dataset. 
int Stats::median()
{
	// Fail if dataset is empty.
	if (counter == 0)
		return 0; 

	// If counter is odd, we can return middle.
	sort();
	if (counter % 2 != 0)
		return numberList[counter / 2];

	int midRight = numberList[counter / 2];
	int midLeft = numberList[midRight - 2];
	static_cast<double>(midLeft);
	static_cast<double>(midRight);
	return (midRight + midLeft) / 2;
}


// List all items in dataset. 
void Stats::display()
{
	if (counter == 0)
		std::cout << "\n\t(!) Dataset is empty.";
	else
	{
		sort();
		cout << "\n\n[Current dataset]";
		for (int i = 0; i < counter; i++)
			cout << "\n" << numberList[i];
	}
		
}


// Sort implementation - swaps two indices in dataset. 
void Stats::swap(int index1, int index2)
{
	int temp = numberList[index1];
	numberList[index1] = numberList[index2];
	numberList[index2] = temp;
}
// Sort implementation - takes a dataset index from sort() 
void Stats::insert(int index)
{
	if (index < 1)
		return;
	if (numberList[index] > numberList[index - 1])
		return;
	swap(index, (index - 1));
	insert(index - 1);
}

void Stats::sort()
{
	// Insertion sort. 
	for (int i = 1; i < counter; i++)
		insert(i); 
}


// Search implementation.
int Stats::search(int num)
{
	return binarySearch(num, 0, counter);
}


// Search implementation, internal use only. 
int Stats::binarySearch(int num, int min, int max)
{
	if (max >= 1)
	{
		// Set middle of the list. 
		int mid = min + (max - min) / 2; 
		
		// Return index of num early if we get lucky and find num is at the midpoint.
		if (numberList[mid] == num)
		{
			return mid;
		}

		// If num is smaller than what's currently at the middle, it has to be on the left half.
		if (numberList[mid] > num)
		{
			return binarySearch(num, min, mid - min);
		}

		// If not, then num is larger; meaning it has to be on the right half.
		// Max is set by the value of counter, which will always be one higher than our index;
		// so subtract one to prevent accessing out of bounds. 
		return binarySearch(num, mid + 1, max - 1);
	}
	// Fail if number not in dataset.
	return -1; 
}


// Add number to end of dataset. 
bool Stats::addNumber(int num)
{
	numberList[counter++] = num; 
	cout << "(You added " << num << " to the dataset)";
	return true;
}

// Remove item from dataset, keeps sorted integrity. 
bool Stats::removeNumber(int num)
{

	if (empty())
	{
		cout << "\n\t(!) Please populate dataset first.";
		return false; 
	}

	int location = 0;
	for (int i = 0; i < counter; i++)
		if (numberList[i] == num)
			location = i;

	cout << "(Removing " << num << " from dataset)";
	for (location; location < counter - 1; location++)
		numberList[location] = numberList[location + 1];
	counter--;
	return true;
}

// Resets all data. 
bool Stats::removeAll()
{
	if (empty())
	{
		cout << "\n\t(!) Please populate dataset first.";
		return false;
	}

	current = 0;
	counter = 0;
	cout << "(Dataset cleared)";
	return true;

}

// Error handling.  
bool Stats::empty() 
{
	if (current == counter)
		return true; 
	return false; 
}
