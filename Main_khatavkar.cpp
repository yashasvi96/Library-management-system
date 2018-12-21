#include<iostream>
#include "Booklist_khatavkar.h" // Incuding the header file
using namespace std;
#include<string>


int main()
{
	
	library <string>book; //class object
	int choice, x;
	int at_position;
	int r = 1;
	int flag;  // Variable to store if the list is sorted or not
	
	if (book.num_of_books == 0)
	{
		cout << "\n Welcome to the Book list program\n\n";
		cout << "\n Since list is EMPTY, Please type in the FIRST element\n";//prompts to enter starting element since list is empty
		cin >> book.new_book;													//reads new element
		book.insert(book.num_of_books, book.new_book);								//function call to insert element in list
		book.num_of_books++;															//increases the number of books by 1 in list
		book.print(book.num_of_books);
	}
	while (r == 1)
	{
		cout << "What would you like to do ?" << endl;
		cout << "1. add an element to end of list" << endl;
		cout << "2. add an element at a location" << endl;
		cout << "3. find a book by book name(linear search)" << endl;
		cout << "4. find a book by book name(binary search)" << endl;
		cout << "5. delete an element at position" << endl;
		cout << "6. delete an element by book name" << endl;
		cout << "7. sort the list(using selection sort)" << endl;
		cout << "8. sort the list(using bubble sort)" << endl;
		cout << "9. print the list" << endl;
		cout << "0. exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://Add element to end of list
			if (book.num_of_books < 20)   //Check if the list is full or not
			{
				cout << "Enter the book name" << endl;
				cin >> book.new_book;
				if (book.find_linear(book.num_of_books, book.new_book) != -1)   //checks if the new element entered already exist
				{
					book.delete_item_isbn(book.num_of_books, book.new_book);   // delete that element if it exists
					book.num_of_books--;											//decrease the list size
				}


				book.insert(book.num_of_books, book.new_book);  //Add new element to end of list and update list size
				book.num_of_books++;
				book.print(book.num_of_books);  //print the list
				flag = 0;
			}
			else
			{
				cout << "Book is full" << endl;
			}
			break;
		case 2: //Insert at a position
			if (book.num_of_books < 20)    //Check if book is full or not
			{
				cout << "which book you want to insert ?" << endl;
				cin >> book.new_book;
				if (book.find_linear(book.num_of_books, book.new_book) != -1)   //checks if the new element entered already exist
				{
					book.delete_item_isbn(book.num_of_books, book.new_book);   // delete that element if it exists
					book.num_of_books--;											//decrease the list size
				}
				cout << "At What position?" << endl;
				cin >> at_position;
				if (at_position <= book.num_of_books && at_position > 0)                //Check if the position is valid
				{
					book.insert_at(book.num_of_books, at_position - 1, book.new_book);
					book.num_of_books++;
					book.print(book.num_of_books);
					flag = 0;

				}
				else
				{
					cout << "Position is out of bound of exsisting list" << endl;
				}
			}
			else
			{
				cout << "Book list is full" << endl;
			}
			break;
		case 3: //Find element using linear search
			if (book.num_of_books > 0)
			{
				cout << "Enter the element to be searched" << endl;
				cin >> book.new_book;
				x = book.find_linear(book.num_of_books, book.new_book);
				if (x != -1)												//CHECKs if element found or not
					cout << "\n Book with name " << book.new_book << " is at position : " << x << endl;		//if found 
				else
					cout << "\n Element not found\n";
			}
			else
			{
				cout << "Cannot perform this operation now list is empty" << endl;
			}
			flag = 0;
			break;
		case 4: //Find element using binary
			if (book.num_of_books > 0)  //check if list is not empty
			{
				if (flag == 0) //Check if list is sorted
				{
					cout << "The list is not sorted. Please sort the list before using this function" << endl;
				}
				else
				{
					int y = book.find_binary(book.num_of_books, book.new_book);
					cout << y << endl;
				}
			}
			else
			{
				cout << "Cannot perform this operation now list is empty" << endl;
			}
			break;
		case 5: //Delete item using position
			int position;
			if (book.num_of_books > 0) //Check if list is not empty
			{
				cout << "Enter the position of element you want to delete" << endl;
				cin >> position;
				while (position > book.num_of_books || position <= 0) //Check if the postion is valid
				{
					cout << "Enter a valid position" << endl;
					cin >> position;
				}
				book.delete_item_position(book.num_of_books, position);//Function call
				book.num_of_books--;  //Decrease the number of books
				book.print(book.num_of_books);// Print the list
			}
			else
			{
				cout << "Cannot perform this operation now" << endl;
			}
			break;
		case 6: //Delte by isbn
			if (book.num_of_books > 0)   //Check if list is not empty
			{
				cout << "Enter book name. to delete" << endl;
				cin >> book.new_book;
				position = book.find_linear(book.num_of_books, book.new_book);
				if (position != -1)
				{
					book.delete_item_isbn(book.num_of_books, book.new_book);
					book.num_of_books--;
					book.print(book.num_of_books);//Function call
				}
				else
				{
					cout << "not found" << endl;
				}
			}
			else
			{
				cout << "Cannot delete. List is empty" << endl;
			}
			break;



		case 7:  //Sort list using selection sort
			if (book.num_of_books > 1)  //Check if list is not empty
			{
				cout << "Sorted list : " << endl;
				book.sort_list_selection(book.num_of_books); //function call
				book.print(book.num_of_books);
				flag = 1; //Variable to store that list is sorted
			}
			else
			{
				cout << "Cannot perform this operation now" << endl;
			}
			break;
			
		case 8: //Sort list using bubble sort
			if (book.num_of_books > 1)
			{
				cout << "Sorted list : " << endl;
				book.sort_list_bubble(book.num_of_books); //function call
				book.print(book.num_of_books);
				flag = 1;  //variable to store that list is sorted
			}
			else
			{
				cout << "Cannot perform this operation now" << endl;
			}
			break;
			
		case 9:
			book.print(book.num_of_books);                    //print the list

			break;

		case 0:
			r = 0;									//successfull termination of program
			break;
		default:
			cout << "Please enter a valid option" << endl;
			break;


		}
	}
	
	return 0;
}