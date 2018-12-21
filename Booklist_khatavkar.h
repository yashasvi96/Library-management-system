#ifndef Booklist_khatavkar_h
#define Booklist_khatavkar_h
using namespace std;
template<class book>
class library  //defining the class library
{
private:

	book booklist[20];
public:
	library()
	{
		num_of_books = 0;
	}//constructor
	book new_book;
	int num_of_books;
	void insert(int num_of_books, book new_book)
	{
		booklist[num_of_books] = new_book;
		
	}

	void print(int num_of_books)
	{
		cout << "The current Book List is :\n\n";
		for (int i = 0; i < num_of_books; i++)
		{
			cout << i + 1 << ")  " << booklist[i] << endl;					//Print the current list
		}

	}
	
	int find_linear(int num_of_books, book new_book)
	{
		for (int i = 0; i < num_of_books; i++)
		{
			if (booklist[i] == new_book)   //Check if elemnt is found
			{

				return i + 1;  //Return the postion at which element is found
			}
		}



		return -1;
	}
	
	void insert_at(int num_of_books, int at_position, book new_book)
	{
		for (int i = num_of_books - 1; i >= at_position; i--)
		{
			booklist[i + 1] = booklist[i];
			//Shift the elements to the left by 1 from the index of position
		}
		booklist[at_position] = new_book;
	}
	int find_binary(int num_of_books, book new_book)
	{
		cout << "Enter the lement you are searching for" << endl;
		cin >> new_book;
		int start = 0;
		int end = num_of_books - 1;

		while (start <= end)  //Finding algorithim
		{
			int mid = (start + end) / 2;
			if (new_book == booklist[mid])
			{
				cout << "Found at :";
				return mid + 1;
			}

			else if (new_book< booklist[mid])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		cout << "Not found" << endl;
		return -1;
	}
	void sort_list_selection(int num_of_books)
	{
		book smallest;
		int swap_index;
		for (int i = 0; i < num_of_books - 1; i++) //sorting algorithim
		{
			smallest = *(booklist + i);
			swap_index = i;
			for (int k = i + 1; k < num_of_books; k++)
			{
				if (*(booklist + k) < smallest)
				{
					smallest = *(booklist + k);
					swap_index = k;
				}
			}
			book swap = *(booklist + i);
			*(booklist + i) = smallest;
			*(booklist + swap_index) = swap;
		}
	}
	
	//Function to sort list using selection sort
	void sort_list_bubble(int num_of_books)
	{
		book hold;									// temporary location used to swap array elements
												// loop to control number of total swapping loop 
		for (int i = 0; i < num_of_books - 1; i++)
			for (int j = 0; j < num_of_books - 1 - i; j++)   // compare side-by-side elements and swap them if
				if (*(booklist + j) > *(booklist + (j + 1))) //previous no. is greater than next no.
				{
					hold = *(booklist + j);
					*(booklist + j) = *(booklist + (j + 1));
					*(booklist + (j + 1)) = hold;
				}
	}
	void delete_item_position(int num_of_books, int position)
	{
		for (int i = position; i <= num_of_books; i++)
		{

			booklist[i - 1] = booklist[i];

		}
	}
	void delete_item_isbn(int num_of_books,book new_book)
	{
		int position;
		position = find_linear(num_of_books, new_book);	//element is found sotre the position
		if (position != -1)
		{
			delete_item_position(num_of_books, position);//call the above function

		}
	}
	
};
#endif