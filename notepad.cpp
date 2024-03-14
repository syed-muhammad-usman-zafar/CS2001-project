#include <iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;


class Node
{
public:
	char value;
	Node* next;
	Node* prev;
	Node* above;
	Node* below;
	Node(char& value)
	{
		this->value = value;
		next = nullptr;
		prev = nullptr;
		above = nullptr;
		below = nullptr;
	}
};

class LL
{
public:
	Node* head;

	LL()
	{
		head = nullptr;
	}

	Node* FormNode(char newvalue)
	{
		Node* newnode = new Node(newvalue);
		newnode->next = nullptr;
		newnode->prev = nullptr;
		newnode->above = nullptr;
		newnode->below = nullptr;
		return newnode;
	}
	void insertAtTail(char  newvalue)
	{
		Node* newnode = new Node(newvalue);
		if (head == nullptr)
		{
			head = newnode;
			return;
		}
		Node* curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newnode;
	}
	void insertinNotepad(Node* node, Node* newnode)
	{

		if (node == nullptr || newnode == nullptr)
		{
			return;
		}
		newnode->next = node->next;
		newnode->prev = node;
		if (node->next != nullptr)
		{
			node->next->prev = newnode;
		}
		node->next = newnode;
	}
	void Enter(Node* node)
	{
		Node* enter = FormNode('\n');
		insertinNotepad(node, enter);
	}


	void displayNotepad(int c_row, int c_col, Node* start)
	{
		Node* curr_row = start;
		int row = 0;
		while (curr_row != nullptr)
		{
			Node* curr_col = curr_row;
			int col = 0;
			while (curr_col != nullptr)
			{
				if (row == c_row && col == c_col)
				{
					cout << "|";
				}
				cout << curr_col->value;
				curr_col = curr_col->next;
				col++;
			}
			if (row == c_row && col == c_col)
			{
				cout << "|";
			}
			cout << endl;
			curr_row = curr_row->below;
			row++;
		}

	}



	void displaylist()
	{
		if (head == nullptr)
		{
			cout << "list is empty" << endl;
			return;
		}
		Node* curr = head;
		cout << endl << endl;
		cout << "file text in linked list" << endl;
		while (curr != nullptr)
		{
			cout << "[" << curr->value << "]" << "->";
			curr = curr->next;
		}
		cout << "nullptr" << endl;
	}
	void load()
	{

		ifstream inputFile("Data.txt");
		if (inputFile.is_open())
		{
			char word;
			cout << "text read from file: " << endl;
			while (inputFile >> word)    //reads each character and store it in  word  then added it to tail of list
			{
				insertAtTail(word);
				cout << word << " ";

			}
			inputFile.close();
		}
		else
		{
			cout << "error :unable to open file " << endl;
		}

	}

	void save(const string& filename)
	{
		ofstream outputFile(filename, ios::app);
		if (outputFile.is_open())
		{
			Node* curr = head;

			while (curr != nullptr)
			{

				outputFile << curr->value << " ";
				curr = curr->next;
			}
			outputFile << '\n';
			outputFile.close();
			cout << "Data has been saved to file: " << filename << endl;

		}
		else
		{
			cout << "error :unable to open file " << endl;
		}

	}
};


int main()
{
	LL  l1;
	char choice;
	char s_word;
	cout << "S to save , L to load  and I to input data on notepad" << endl;
	cin >> choice;

	if (choice == 'L' || choice == 'l')
	{
		l1.load();
		l1.displaylist();

	}
	else if (choice == 'S' || choice == 's')
	{
		cout << "enter shift s to save data" << endl;
		while (1)
		{
			cin >> s_word;
			if (s_word == 'S')
			{
				break;
			}
			l1.insertAtTail(s_word);
			cout << endl;

		}
		cout << endl;
		l1.displaylist();
		l1.save("Data.txt");

	}
	else if (choice == 'I' || choice == 'i')
	{
		Node* editor = l1.FormNode('\n'); // Start with an empty editor with a newline
		Node* cursor = editor; // Start the cursor at the beginning


		int cursorRow = 0;
		int cursorCol = 0;

		char ch;


		while (1)
		{
			Node* newNode;

			system("cls");
			l1.displayNotepad(cursorRow, cursorCol, editor);

			ch = _getch(); // Get user input

			switch (ch)
			{

			case 75:  //left key
				if (cursor->prev != nullptr) {
					cursor = cursor->prev;
					cursorCol--;
				}
				break;
			case 77:  //right key
				if (cursor->next != nullptr) {
					cursor = cursor->next;
					cursorCol++;
				}
				break;
			case 72:  //up key
				if (cursor->above != nullptr) {
					cursor = cursor->above;
					cursorRow--;
				}
				break;
			case 80: //down key
				if (cursor->below != nullptr) {
					cursor = cursor->below;
					cursorRow++;
				}
				break;

			case 13: //enter key
				char c_word;
				cout << ":";
				cin >> c_word;
				newNode = l1.FormNode(c_word);
				l1.insertinNotepad(cursor, newNode);
				cursor = newNode;
				cursorCol++;
				break;


			case 8:// backspace
				if (cursor->next != nullptr) {
					Node* temp = cursor->next;
					cursor->next = temp->next;
					if (temp->next != nullptr) {
						temp->next->prev = cursor;
					}
					delete temp;
				}
				break;

			}

		}

	}

	else
		cout << "wrong entry" << endl;
	system("pause");
	return 0;
}




