
class Stats
{
	private:
		// Create our array of numbers. 
		int numberList[20];
		int current;
		int counter;

		// Sort and search implementation. 
		void swap(int i1, int i2); 
		void insert(int index);
		void sort();
		int binarySearch(int num, int min, int max);

	public:
		// Constructor. 
		Stats();

		// Generate information about collection.
		int minimum();
		int maximum();
		int sum();
		double mean();
		int median();
		void display();
		
		// Manipulate collection, unsanitary class methods.
		// Note that the only reason these aren't private is because the calling code in main() needs to be able to manipulate data. 
		bool addNumber(int num);
		bool removeNumber(int num);
		bool removeAll();

		// Search returns index of int; this is basically a getter/accessor for private binarySearch() class method.
		int search(int num);

		// Helper functions. 
		bool empty();

};

