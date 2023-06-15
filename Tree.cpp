#include <iostream>
#include "Tree.h"

using namespace std;


template<class T>//                         создание дерева
Tree<T>::Tree()
{
	len = 0;
	this->First = nullptr;
} 

template<class T>//                         добавление элемента
void Tree<T>::Push()
{
	T data;
	cout << "" << endl;
	cin >> data;

	if (First == nullptr)
	{
		Node<T> node = new Node<T>;
		node->data = data;
		First = node;
	}
	else
	{
		Node<T> node = new Node<T>;
		node->data = data;
		Node<T> temp = First;
		while (temp != nullptr)
		{
			if (temp->data > node->data)
			{
				temp = temp->ModeLeft;
			}
			else
			{
				temp = temp->NodeRight;
			}
		}
		temp = node;
	}
	len++;
}
template <class T>//                        удаление элемента
void Tree<T>::Del()
{
	bool f = 1;
	T data;
	cout << "" << endl;
	cin >> data;

	Node<T> temp = First;
	Node<T> temp1;
	while ((temp->data != data) && f)
	{
		if(((temp->data > data) && (temp->NodeLeft->data < data)) || (temp->data < data) && (temp->NodeRight->data > data)) f = 0;
		if (temp->data > data)
		{
			temp1 = temp;
			temp = temp->NodeLeft;
		}
		else
		{
			temp1 = temp;
			temp = temp->NodeRight;
		}
	}
	if (f)
	{
		if (temp1->NodeLeft->data == data)
		{
			if (temp->NodeLeft != nullptr)
			{
				temp1->NodeLeft = temp->NodeLeft;
				Node<T> temp2 = temp->NodeLeft;
				while (temp2->NodeRight != nullptr)
					temp2 = temp2->NodeRight;
				temp2->NodeRight = temp->NodeRight;
				delete temp;

			}
			else
			{
				temp1->NodeLeft = temp->NodeRight;
				delete temp;
			}
		}
		else
		{
			if (temp->NodeLeft != nullptr)
			{
				temp1->NodeRight = temp->NodeLeft;
				Node<T> temp2 = temp->NodeLeft;
				while (temp2->NodeRight != nullptr)
					temp2 = temp2->NodeRight;
				temp2->NodeRight = temp->NodeRight;
				delete temp;
			}
			else
			{
				temp1->NodeRight = temp->NodeRight;
				delete temp;
			}
		}
		len--;
	}
	else
		cout << " " << endl;
}
template <class T>//                        поиск
void Tree<T>::Chek(T data)
{
	bool f = 1;
	Node<T> temp = First;
	while ((temp->data != data) && f)
	{
		if (((temp->data > data) && (temp->NodeLeft->data < data)) || (temp->data < data) && (temp->NodeRight->data > data)) f = 0;
		if (temp->data > data)
		{
			temp = temp->NodeLeft;
		}
		else
		{
			temp = temp->NodeRight;
		}
	}
	if (f)
	{
		cout << "" << endl;
	}
	else
	{
		cout << "" << endl;
	}
}

template<class T>
int Tree<T>::Balns(int n, Node<T>& node)
{
	int KLeft, KRight;
	n++;
	if (node->NodeLeft != nullptr)
		KLeft = Balns(n, node->NodeLeft);
}

template<class T>//                         прямой обход
void Tree<T>::ForwardBypass(Node<T>& node)
{
	cout << node->data << endl;
	if (node->NodeLeft != nullptr) 
		ForwardBypass(node->NodeLeft);

	if (node->NodeRight != nullptr)
		ForwardBypass(node->NodeRight);
}
template<class T>//                         симметричный обход
void Tree<T>::SymmetricBypass(Node<T>& node)
{
	if (node->NodeLeft != nullptr)
		SymmetricBypass(node->NodeLeft);

	if((node->NodeLeft != nullptr)||(node->NodeRight))
	cout << node->data << endl;

	if (node->NodeRight != nullptr)
		SymmetricBypass(node->NodeRight);

	if ((node->NodeLeft == nullptr) && (node->NodeRight == nullptr)) 
		cout << node->data << endl;
}
template<class T>//                         обратный обход
void Tree<T>::ReverseBypass(Node<T>& node)
{
	if (node->NodeLeft != nullptr)
		ReverseBypass(node->NodeLeft);
	if (node->NodeRight != nullptr)
		ReverseBypass(node->NodeRight);
	cout << node->data << endl;
}