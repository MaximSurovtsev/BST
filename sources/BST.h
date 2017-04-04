#include <fstream>
#include <iostream>
template <class T> struct Node
{
	T element;
	Node* pLeft;
	Node* pRight;
};

template <class T> class BST
{
private:
	Node<T>* root;
	 int count;
public:
	BST();
	~BST();
	void insert(const T&);
	void inorder_walk(Node<T>* temp)const;
	
	int get_count()const;
	Node<T>* get_pointer(const T& value, Node<T>* temp)const;
	bool search_result(const T& value)const;
	Node<T>* root_()const;
	void reading(const std::string filename);
	void output(std::ostream& ost, Node<T>* temp);
	void writing(const std::string filename);
};

template <class T> BST<T>::BST()
{
	root = NULL;
	count = 0;
}

template <class T> BST<T>::~BST()
{
	delete root;
}


template <class T> void BST<T>::insert(const T& added)
{
	Node<T>* daughter = new Node<T>;
	daughter->element = added;
	daughter->pLeft = daughter->pRight = 0;
	Node<T>* parent = root;
	Node<T>* temp = root;
	while (temp)                    
	{
		parent = temp;                 
		if (added < temp->element)  
			temp = temp->pLeft;
		else
			temp = temp->pRight;   
	}
	if (!parent)
		root = daughter;
	else
	{
		if (added < parent->element)
			parent->pLeft = daughter;
		else
			parent->pRight = daughter;
	}
	count++;
}

template<class T> void BST<T>::inorder_walk(Node<T>* temp)const
{
	if (temp)
	{
		inorder_walk(temp->pLeft);
		std::cout << temp->element << "	";
		inorder_walk(temp->pRight);
	}
}

template<class T> Node<T>* BST<T>::get_pointer(const T& value, Node<T>* temp)const
{
	if (temp == 0 || value == temp->element)
		return temp;
	if (value > temp->element)
		return get_pointer(value, temp->pRight);
	else return get_pointer(value, temp->pLeft);
}

template<class T> bool BST<T>::search_result(const T& value)const
{
	return get_pointer(value, root);
}

template<class T> Node<T>* BST<T>::root_()const
{
	return root;
}

template<class T> int BST<T>::get_count()const
{
	return count;
}

template<class T> void BST<T>::reading(const std::string filename)
{
	std::ifstream fin(filename);
	T temp;
	fin >> temp;
	while (fin)
	{	
		insert(temp);
		fin >> temp;
	}
	fin.close();
}

template<class T> void BST<T>::output(std::ostream& ost, Node<T>* temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{	
		ost << temp->element << "	";
		output(ost, temp->pLeft);
		output(ost, temp->pRight);
	}
}

template<class T> void BST<T>::writing(const std::string filename)
{
	std::ofstream fout(filename);
	output(fout, root);
	fout.close();
}


