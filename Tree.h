#pragma once

#include <iostream>

using namespace std;

template<class T>
class Tree
{
public:
	template<class T>
	class Node
	{

		Node* NodeLeft = nullptr;
		Node* NodeRight = nullptr;
		T data = 0;
	public:
		Node()
		{
			NodeLeft = nullptr;
			NodeRight = nullptr;
			data = 0;
		}
		Node(T data)
		{
			this->NodeLeft = nullptr;
			this->NodeRight = nullptr;
			this->data = data;
		}
	};

	Tree();

	void Push();
	void Del();
	void Chek(T);

	void ForwardBypass(Node<T>& node);
	void SymmetricBypass(Node<T>& node);
	void ReverseBypass(Node<T>& node);

	int Balns(int, Node<T>&node);
	
private:
	Node<T>* First = nullptr;
	int len = 0;
};