#include<iostream>
#include "Booklist_khatavkar.h"
using namespace std;

library::library()
{
	num_of_books = 0;  //intializing the private variable
}

void library<string>::insert(list num_of_books, list new_num)  //insering a new element
{

	booklist[num_of_books] = new_num;

}
void library::print(int num_of_books)
{

	cout << "The current Book List is :\n\n";
	for (int i = 0; i < num_of_books; i++)
	{
		cout << i + 1 << ")  " << booklist[i] << endl;					//Print the current list
	}

}
int library::find_linear(int num_of_books, int new_num)
{
	for (int i = 0; i < num_of_books; i++)
	{
		if (booklist[i] == new_num)   //Check if elemnt is found
		{

			return i + 1;  //Return the postion at which element is found
		}
	}



	return -1;
}
void library::delete_item_position(int num_of_books, int position)
{


	for (int i = position; i <= num_of_books; i++)
	{

		booklist[i - 1] = booklist[i];

	}

}
void library::delete_item_isbn(int num_of_books, int new_num)
{
	int position;
	position = find_linear(num_of_books, new_num);	//element is found sotre the position
	if (position != -1)
	{
		delete_item_position(num_of_books, position);//call the above function

	}

}
void library::insert_at(int num_of_books, int at_position, int new_num)
{
	for (int i = num_of_books - 1; i >= at_position; i--)
	{
		booklist[i + 1] = booklist[i];
		//Shift the elements to the left by 1 from the index of position
	}
	booklist[at_position] = new_num;




}
int library::find_binary(int num_of_books, int new_num)
{
	cout << "Enter the lement you are searching for" << endl;
	cin >> new_num;
	int start = 0;
	int end = num_of_books - 1;

	while (start <= end)  //Finding algorithim
	{
		int mid = (start + end) / 2;
		if (new_num == booklist[mid])
		{
			cout << "Found at :";
			return mid + 1;
		}

		else if (new_num < booklist[mid])
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
void library::sort_list_selection(int num_of_books)
{
	int smallest;
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
		int swap = *(booklist + i);
		*(booklist + i) = smallest;
		*(booklist + swap_index) = swap;
	}

}
void library::sort_list_bubble(int num_of_books)   //sorting algorithim
{
	int hold;									// temporary location used to swap array elements
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
