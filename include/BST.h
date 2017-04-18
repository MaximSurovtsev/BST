#include <fstream>
#include <iostream>
template <class T> struct Node
{
	T element;
	Node* pLeft;
	Node* pRight;
	Node* pParent;
};

template <class T> class BST
{
private:
	Node<T>* root;
	unsigned int count;
public:
	BST()
  {
	root = nullptr;
	count = 0;
}
~BST()
{
	deleteNode(root);
}

void deleteNode(Node<T>* temp)
{
	if (!temp)
		return;
	if (temp->pLeft)
	{
		deleteNode(temp->pLeft);
		temp->pLeft = nullptr;
	}

	if (temp->pRight)
	{
		deleteNode(temp->pRight);
		temp->pRight = nullptr;
	}
	delete temp;
}
		
	
void insert(const T& added)
{
	if (search_result(added) == 1)
		return;
	else
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
			daughter->pParent = parent;
		}
		count++;
	}
}	
void display(const Node<T>* temp, unsigned int level)const
{
	
	if (temp)
	{
		display(temp->pLeft, level + 1);
		for (int i = 0; i < level; i++) 
			std::cout << "__";
		std::cout << temp->element << std::endl;
		display(temp->pRight, level + 1);
	}
 }
	
int get_count()const
{
	return count;
}
	
Node<T>* get_pointer(const T& value, Node<T>* temp)const
 {
	if (temp == 0 || value == temp->element)
		return temp;
	if (value > temp->element)
		return get_pointer(value, temp->pRight);
	else return get_pointer(value, temp->pLeft);
}

bool search_result(const T& value)const
{
	return get_pointer(value, root);
}

Node<T>* root_()const
{
	return root;
}
	
void reading(const std::string& filename)
{
	std::ifstream fin(filename);
	T temp;
	fin >> count;
	fin >> temp;
	while (fin)
	{	
		insert(temp);
		fin >> temp;
	}
	fin.close();
	count /=2;
}
	
void output(std::ostream& ost,const Node<T>* temp)const
{
	if (temp == nullptr)
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
	
void writing(const std::string& filename)const
{
	std::ofstream fout(filename);
	fout << count;
	output(fout, root);
	fout.close();
}

Node<T>* minValue(Node<T>* cur)
{
	if (cur->pLeft == nullptr)
		return cur;
	else
		return minValue(cur->pLeft);
}
	
Node<T>* remove(Node<T>* delNode)
{
		
	if (delNode->pLeft && delNode->pRight)
	{
			delNode->element = minValue(delNode->pRight)->element;
			delNode = minValue(delNode->pRight);
	}
	else
	{
		if (delNode->pLeft)
		{
			delNode->pLeft->pParent = delNode->pParent;
			delete delNode;
		}
		else if (delNode->pRight)
		{
		delNode->pLeft->pParent = delNode->pParent;
		delete delNode;

		}
			
	}
	try
	{
		if (count == 1)
			throw 12;
		if (!delNode->pLeft && !delNode->pRight && delNode)
		{
			if (delNode->pParent->pLeft == delNode)
			{
				delNode->pParent->pLeft = nullptr;
				delete delNode;
			}
			if (delNode->pParent->pRight == delNode)
			{
			delNode->pParent->pRight = nullptr;
			delete delNode;
			}
		}
		
		--count;
		return delNode;
	}
	catch (int i)
	{
		std::cout << "Error " << i << "There is only one node in the tree!";
	}

		
	
}
};



