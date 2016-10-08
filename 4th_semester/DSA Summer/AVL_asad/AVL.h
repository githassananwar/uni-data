#ifndef AVL_H
#define AVL_H

#include "DECK.h"

template <typename T>
struct Node
{
	T info ;
	int height ;
	Node<T>* right ;
	Node<T>* left ;
	Node()
	{
		height = 1 ;
		info = 0 ;
		right = left = NULL ;
	}
	Node(T info)
	{
		height = 1 ;
		this->info = info ;
		right = left = NULL ;
	}
};

template <typename T>
class AVL
{
	Node<T>* root ;
	void explorerView(Node<T>* node, int index) ;
	int getBalanceFactor(Node<T>* node) ;
	void rotate(Node<T>* node,DECK<Node<T>*> & ancestors) ;
	void updateHeight(Node<T>* node) ;
	void leftLeftRotation(Node<T>* node) ;
	void rightRightRotation(Node<T>* node) ;
	void leftRightRotation(Node<T>* node) ;
public:
	AVL() ;
	void insert(T info) ;
	void remove(T info) ;
	void explorerView() ;
	//~AVL();
};

template <typename T>
AVL<T>::AVL()
{
	this->root = NULL ;
}

template <typename T>
void AVL<T>::insert(T info)
{
	if(root == NULL)
	{
		root = new Node<T>(info) ;
		return ;
	}
	Node<T>* par = root , *ptr = root ;
	DECK<Node<T>*> ancestors ;
	while (ptr != NULL)
	{
		par = ptr ;
		if(info < par->info)
			ptr = par->left ;
		else
			ptr = par->right ;
		ancestors.insertAtHead(par) ;
	}
	if(info < par->info)
		par->left = new Node<T>(info) ;
	else
		par->right = new Node<T>(info) ;
	int balanceFactor ;
	while(!ancestors.isEmpty())
	{
		par = ancestors.deleteAtHead() ;
		balanceFactor = getBalanceFactor(par) ;
		if(balanceFactor == 2 || balanceFactor == -2)
		{
			rotate(par,ancestors) ;
		}
		updateHeight(par) ;
	}
}

template <typename T>
void AVL<T>::remove(T key)
{
	Node<T>* node = root , *par = root ;
	DECK<Node<T>*> ancestors ;
	while(node != NULL)
	{
		if(node->info == key)
		{
			break ;
		}
		par = node ;
		if(key < node->info)
			node = node->left ;
		else
			node = node->right ;
		ancestors.insertAtHead(par) ;
	}
	if(node == NULL)
		return ;
	if(node->left == NULL && node->right == NULL)
	{
		if(par->left == node)
			par->left = NULL ;
		else
			par->right = NULL ;
		delete node ;
	}
	else if((node->left == NULL && node->right != NULL ) || (node->right == NULL && node->left != NULL ))
	{
		if(par->left == node)
		{
			if(node->left)
				par->left = node->left ;
			else
				par->left = node->right ;
			delete node ;
		}
		else
		{
			if(node->left)
				par->right = node->left ;
			else
				par->right = node->right ;
			delete node ;
		}
	}
	else if(node->left != NULL && node->right != NULL)
	{
		Node<T>* min = node->right , *minParent = NULL ;
		while(min->left != NULL)
		{
			minParent = min ;
			min = min->left ;
		}
		if(minParent == 0 )
		{
			node->info = min->info ;
			node->right = min->right ;
			delete min ;
		}
		else
		{
			node->info = min->info ;
			minParent->left = NULL ;
			delete min ;
		}
	}
	// updating the tree structure
	int balanceFactor ;
	while (!ancestors.isEmpty())
	{
		par = ancestors.deleteAtHead() ;
		balanceFactor = getBalanceFactor(par) ;
		if(balanceFactor < -1 || balanceFactor > 1)
			rotate(par,ancestors) ;
	}
}

template <typename T>
void AVL<T>::rotate(Node<T>* node,DECK<Node<T>*> & ancestors)
{
	int bf = getBalanceFactor(node) ;
	Node<T>* temp,*par ;
	if(bf == 2)
	{
		if(getBalanceFactor(node->left) > 0)
		{
			if(!ancestors.isEmpty())
			{
				temp = ancestors.deleteAtHead() ;
				temp->left = node->left ;
			}
			else
				root = node->left ;
			leftLeftRotation(node) ;
		}
		else
		{
			Node<T> *leftChild = node->left, *rightOfLeftChild = node->left->right ;
			temp = rightOfLeftChild->left ;
			rightOfLeftChild->left = leftChild ;
			rightOfLeftChild->left->right = temp ;

			temp = rightOfLeftChild->right ;
			rightOfLeftChild->right = node ;
			rightOfLeftChild->right->left = temp ;
			if(!ancestors.isEmpty())
			{
				par = ancestors.deleteAtHead() ;
				par->left = rightOfLeftChild ;
			}
			else
				root = rightOfLeftChild ;
			updateHeight(leftChild) ;
			updateHeight(node) ;
			updateHeight(rightOfLeftChild) ;
		}
	}
	else if (bf == -2)
	{
		if(getBalanceFactor(node->right) < 0)
		{
			if(!ancestors.isEmpty())
			{
				temp = ancestors.deleteAtHead() ;
				temp->right = node->right ;
			}
			else
				root = node->right ;
			rightRightRotation(node) ;
		}
		else
		{
			Node<T> *rightChild = node->right, *leftOfRightChild = node->right->left ;
			temp = leftOfRightChild->right ;
			leftOfRightChild->right = rightChild ;
			leftOfRightChild->right->left = temp ;

			temp = leftOfRightChild->left ;
			leftOfRightChild->left = node ;
			leftOfRightChild->left->right = temp ;
			if(!ancestors.isEmpty())
			{
				par = ancestors.deleteAtHead() ;
				par->right = leftOfRightChild ;
			}
			else
				root = leftOfRightChild ;
			updateHeight(rightChild) ;
			updateHeight(node) ;
			updateHeight(leftOfRightChild) ;
		}
	}
}


template <typename T>
void AVL<T>::updateHeight(Node<T>* node)
{
	if(node->left && node->right)
		node->height = max(node->left->height,node->right->height) + 1 ;
	else if (node->left)
		node->height = node->left->height + 1 ;
	else if (node->right)
		node->height = node->right->height + 1 ;
	else
		node->height = 1 ;
}

template <typename T>
int AVL<T>::getBalanceFactor(Node<T>* node)
{
	if(!node->left && !node->right)
		return 0 ;
	if(node->left && node->right)
	{
		return (node->left->height - node->right->height) ;
	}
	if(node->right)
	{
		return (node->right->height * -1) ;
	}
	if(node->left)
		return node->left->height ;
}

template <typename T>
void AVL<T>::rightRightRotation(Node<T>* node)
{
	Node<T>* temp = node->right->left ;
	node->right->left = node ;
	node->right = temp ;
}

template <typename T>
void AVL<T>::leftLeftRotation(Node<T>* node)
{
	Node<T>* temp = node->left->right ;
	node->left->right = node ;
	node->left = temp ;
}

template <typename T>
void AVL<T>::explorerView()
{
	if(root)
		this->explorerView(root,0) ;
}

template <typename T>
void AVL<T>::explorerView(Node<T>* node, int index)
{
	for(int i = 0 ; i < index ; i++)
		cout << "  " ;
	cout << node->info << "\theight: " << node->height << "  BF: " << getBalanceFactor(node) << endl ;
	if(node->left)
	{
		//cout << "left " ;
		explorerView(node->left,index+1) ;
	}
	if(node->right)
	{
		//cout << "right " ;
		explorerView(node->right,index+1) ;
	}
}

#endif