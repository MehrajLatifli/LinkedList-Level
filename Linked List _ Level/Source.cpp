#include <iostream>
#include <assert.h>
#include <string>
#include <string.h>

using namespace std;



template <typename T, typename T2>
class LinkedList {


public:
	class Level {
		string name;
		int degree_of_difficult;
	public:

		T data;
		T2 numberdata;
		Level* next = nullptr;


	};


	static void printList(Level* n) {
		cout << "\n Printing new list " << endl;
		while (n != NULL) {
			cout << " " << n->data << " ";
			cout << " " << n->numberdata << " " << endl;;
			n = n->next;
		}
	}

	void pushlast(Level* head, T new_data, T2 new_numberdata) {
		Level* new_node = new Level();

		new_node->data = new_data;
		new_node->numberdata = new_numberdata;
		new_node->next = NULL;

		Level* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new_node;
	}

	void pushfirst(Level** head, T new_data, T2 new_numberdata) {
		Level* new_node = new Level;
		new_node->data = new_data;
		new_node->numberdata = new_numberdata;
		new_node->next = *(head);
		*head = new_node;
	}

	void insertAfter(Level* prev_node, T new_data, T2 new_numberdata) {
		if (prev_node == NULL) {
			cout << " Error " << endl;
			return;
		}
		Level* new_node = new Level;
		new_node->data = new_data;
		new_node->numberdata = new_numberdata;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
	}

	void deleteAfterwithNode(Level* head, Level* temp)
	{

		if (head == temp)
		{
			if (head->next == NULL)
			{
				cout << "There is only one node." <<
					" The list can't be made empty ";
				return;
			}


			head->data = head->next->data;
			head->numberdata = head->next->numberdata;


			temp = head->next;


			head->next = head->next->next;


			free(temp);

			return;
		}

		Level* prev_node = head;
		while (prev_node->next != NULL && prev_node->next != temp) {
			prev_node = prev_node->next;
		}


		if (prev_node->next == NULL)
		{
			cout << "\nGiven node is not present in Linked List";
			return;
		}


		prev_node->next = prev_node->next->next;


		free(temp);

		return;
	}



	void deleteAfterwithKey(Level** head_ref, T key, T2 n_key)
	{


		Level* temp = *head_ref;
		Level* prev_node = NULL;


		if (temp != NULL && temp->data == key && temp->numberdata == n_key)
		{
			*head_ref = temp->next;
			delete temp;
			return;
		}


		while (temp != NULL && temp->data != key && temp->numberdata != n_key)
		{
			prev_node = temp;
			temp = temp->next;
		}


		if (temp == NULL)
			return;


		prev_node->next = temp->next;


		delete temp;
	}
};





void main() {



	LinkedList<string, int>::Level* easy = NULL;
	LinkedList<string, int>::Level* medium = NULL;
	LinkedList<string, int>::Level* difficult = NULL;

	easy = new LinkedList<string, int>::Level();
	medium = new LinkedList<string, int>::Level();
	difficult = new LinkedList<string, int>::Level();

	easy->data = "asan: \t\t\t";
	easy->numberdata = 1;
	easy->next = medium;

	medium->data = "orta: \t\t\t";
	medium->numberdata = 5;
	medium->next = difficult;

	difficult->data = "cetin: \t\t";
	difficult->numberdata = 10;
	difficult->next = NULL;

	LinkedList<string, int>::printList(easy);
	LinkedList<string, int>* linked = new LinkedList<string, int>();
	cout << "\n =========================== \n ";
	linked->pushlast(easy, "orta asanliqda: \t", 3);
	LinkedList<string, int>::printList(easy);
	cout << "\n =========================== \n ";
	linked->pushfirst(&easy, "olduqca asan: \t\t", 0);
	LinkedList<string, int>::printList(easy);
	cout << "\n =========================== \n ";
	linked->insertAfter(medium, "orta cetin: \t\t", 7);
	LinkedList<string, int>::printList(easy);
	cout << "\n =========================== \n ";
	linked->deleteAfterwithNode(medium, difficult);
	LinkedList<string, int>::printList(easy);
	cout << "\n =========================== \n ";
	linked->deleteAfterwithKey(&medium, "orta asanliqda: \t", 3);
	LinkedList<string, int>::printList(easy);
	cout << "\n =========================== \n ";




}