#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;


class BinTree
{
public:
	BinTree();

	class Node
	{
	public:
		int data;
		Node* pRight;
		Node* pLeft;

		Node(int data = 0, Node* pRight = nullptr, Node* pLeft = nullptr)
		{
			this->data = data;
			this->pRight = pRight;
			this->pLeft = pLeft;
		}
	};


	Node* head;
	int size;
	void add(int data);
	void print(Node* node, int level, string direction);
	void inOrder(Node* node, vector<int>& sortedArray);
	vector<int> treeSort(BinTree& tree, vector<int> arr);
	void cleart(Node* node);
};

BinTree::BinTree()

{
	head = nullptr;
	size = 0;
}

void BinTree::cleart(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	cleart(node->pLeft);
	cleart(node->pRight);

	delete node;

	node = nullptr;
	size = 0;

}

void BinTree::inOrder(Node* node, vector<int>& sortedArray) {
	if (node == nullptr) {
		return;
	}

	inOrder(node->pLeft, sortedArray);

	sortedArray.push_back(node->data);

	inOrder(node->pRight, sortedArray);
}

vector<int> BinTree::treeSort(BinTree& tree, vector<int> arr) {

	cleart(head);

	for (int i = 0; i < arr.size(); i++) {
		tree.add(arr[i]);
	}

	vector<int> sortedArray;

	inOrder(tree.head, sortedArray);

	return sortedArray;
}

void BinTree::print(Node* node, int level, string direction)
{
	if (node == nullptr) {
		return;
	}
	  
	string leftChild = (node->pLeft != nullptr) ? to_string(node->pLeft->data) : "null";
	string rightChild = (node->pRight != nullptr) ? to_string(node->pRight->data) : "null";

	cout << "Уровень " << level << ": " << node->data << " (" << direction << "), потомки: (left: "
		<< leftChild << ", right: " << rightChild << ")" << endl;

	print(node->pLeft, level + 1, "left");
	print(node->pRight, level + 1, "right");
}

void BinTree::add(int data)
{

	if (size == 0)
	{
		this->head = new Node(data);
		size++;
	}
	else
	{
		Node* curr = this->head;

		while (true)
		{


			if (data >= curr->data)
			{

				if (curr->pRight == nullptr)
				{

					curr->pRight = new Node(data);
					size++;
					return;
				}
				else
				{
					curr = curr->pRight;
				}
			}

			else if (data <= curr->data)
			{

				if (curr->pLeft == nullptr)
				{
					curr->pLeft = new Node(data);;

					size++;
					return;
				}
				else
				{
					curr = curr->pLeft;
				}
			}
		}
	}
}



void clear() {
	cout << "\x1B[2J\x1B[H";
}

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	BinTree bt;
	
	vector <int> arr;
	int value = -2;

	cout << "Введите значения в массив (для остановки введите '-1'):\n";

	while (value != -1)
	{
		cin >> value;
		if (value != -1) {
			arr.push_back(value);
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	for (int i = 0; i < arr.size(); i++)
	{
		bt.add(arr[i]);
	}
	
	cout << endl;

	while (true) {
		string point;
		cout << "1.Просмотреть дерево\n2.Дополнить массив\n3.Отсортировать массив\n4.Посмотреть массив" << endl;
		cin >> point;

		if (point == "1")
		{
			clear();
			string next;
			bt.print(bt.head, 0, "root");
			cout << "Введите любой символ, чтобы продолжить: " << endl;
			cin >> next;
			clear();
		}
		if (point == "2")
		{
			clear();
			string next;
			cout << "Введите число: ";
			cin >> value;
			arr.push_back(value);
			bt.add(value);
			cout << "Введите любой символ, чтобы продолжить: " << endl;
			cin >> next;
			clear();
		}
		if (point == "3")
		{
			clear();
			string next;
			arr = bt.treeSort(bt, arr);
			cout << "Введите любой символ, чтобы продолжить: " << endl;
			cin >> next;
			clear();
		}
		if (point == "4")
		{
			clear();
			string next;
			for (int i = 0; i < arr.size(); i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\nВведите любой символ, чтобы продолжить: " << endl;
			cin >> next;
			clear();
		}
		else {
			clear();
		}
	}

}


