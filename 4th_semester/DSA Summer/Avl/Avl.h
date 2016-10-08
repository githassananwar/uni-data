#include "Node.h"
#ifndef AVL_H
#define AVL_H

template<typename T>
class Avl
{
	Node<T>* root;

	void LVR(Node<T>* p)
	{
		if(p->left)
		{
			LVR(p->left);
		}

		cout<<p->info<<" ";

		if(p->right)
		{
			LVR(p->right);
		}
	}

	void removeDecendent(Node<T>* p)
	{
		if(p==0)
			return;

		if(p->left)
		{
			removeDecendent(p->left);
		}
		if(p->right)
		{
			removeDecendent(p->right);
		}

		delete p;
	}

	//---------------------------------Rotations------------------------------------------

	void rotateLL(Node<T>* p, Node<T>* par)
	{
		Node<T>* LP=p->left;
		Node<T>* RLP=LP->right;

		LP->right=p;
		if(root==p) 
		{
			root=LP;
		}
		else if(par->left==p) //In case of par left child p
		{
			par->left=LP;
		}
		else //In case of par right child p
		{
			par->right=LP;
		}

		p->left=RLP;
		updateHeightAndRotate(p, par);
		updateHeightAndRotate(LP, p);
	}

	void rotateRR(Node<T>* p, Node<T>* par)
	{
		Node<T>* RP=p->right, *LRP=RP->left;
		RP->left=p;
		if(root==p)
		{
			root=RP;
		}
		else if(par->left==p)
		{
			par->left=RP;
		}
		else
		{
			par->right=RP;
		}
		p->right=LRP;
		updateHeightAndRotate(p, par);
		updateHeightAndRotate(RP, p);
	}

	void rotateLR(Node<T>* p, Node<T>* par)
	{
		Node<T>* LP=p->left, *RLP=LP ->right, *RRLP=RLP->right, *LRLP=RLP->left;
		RLP->left=LP;
		RLP->right=p;
		p->left=RRLP;
		LP->right=LRLP;
		if(root==p)
		{
			root=RLP;
		}
		else if(par->left==p)
		{
			par->left=RLP;
		}
		else
		{
			par->right=RLP;
		}
		updateHeightAndRotate(p, par);
		updateHeightAndRotate(LP, p);
		updateHeightAndRotate(RLP, p);
	
	}

	void rotateRL(Node<T>* p , Node<T>* par)
	{
		Node<T>* RP=p->right, *LRP=RP->left, *LLRP=LRP->left, *RLRP=LRP->right;
		LRP->left = p;
		LRP->right = RP;
		p->right = LLRP;
		RP->left = RLRP;

		if(root==p)
		{
			root=LRP;
		}
		else if(par->left == p)
		{
			par->left=LRP;
		}
		else
		{
			par->right=LRP;
		}
		updateHeightAndRotate(p, par);
		updateHeightAndRotate(RP, p);
		updateHeightAndRotate(LRP, p);
	}

	//----------------------------------------------------------------------------------

	void rotate(int bf, Node<T>* p, Node<T>* par)
	{
		if(bf==-2)
		{
			Node<T>* RP = p->right;
			if(RP->left && RP->right)
			{
				if(RP->left->height > RP->right->height)
				{
					rotateRL(p, par);
				}
				else
				{
					rotateRR(p, par);
				}
			}
			else if(RP->left)
			{
				rotateRL(p, par);
			}
			else
			{
				rotateRR(p, par);
			}
		}
		else if(bf == 2)
		{
			Node<T>* LP = p->left;
			if(LP->left && LP->right)
			{
				if(LP->left->height > LP->right->height)
				{
					rotateLL(p, par);
				}
				else
				{
					rotateLR(p, par);
				}
			}
			else if(LP->left)
			{
				rotateLL(p, par);
			}
			else
			{
				rotateLR(p, par);
			}
		}
	}

	void updateHeightAndRotate(Node<T>* p, Node<T>* par)
	{
		int lh = 0, rh = 0;
		if(p->left)
		{
			lh=p->left->height;
		}
		if(p->right)
		{
			rh=p->right->height;
		}

		int bf=lh-rh;

		if(bf==2 || bf==-2)
		{
			rotate(bf, p, par);
		}

		else if(lh>rh)
		{
			p->height=lh+1;
		}
		else
		{
			p->height=rh+1;
		}
	}

	void insert(Node<T>* p, T val, Node<T>* par)
	{
		if(p==0)
		{
			if(val<par->info)
			{
				par->left=new Node<T>(val);
			}
			else
			{
				par->right=new Node<T>(val);
			}
			return;
		}

		if(val<p->info)
		{
			insert(p->left, val, p);
		}
		else
		{
			insert(p->right, val, p);
		}
		updateHeightAndRotate(p, par);
	}

	void createCopy(Node<T>* t1, Node<T>* t2)
	{
		if(t1->left)
		{
			t2->left=new Node<T>(t1->left->info);
			createCopy(t1->left, t2->left);
		}

		if(t1->right)
		{
			t2->right=new Node<T>(t1->right->info);
			createCopy(t1->right, t2->right);
		}
		
	}

//----------------------------------------PUBLIC---------------------------------------- 

public:
	Avl()
	{
		root=0;
	}

	Avl(Avl<T> & a)
	{
		root=new Node<T>(a.getRoot());
		createCopy(a.root, root);
	}

	Avl<T>& operator = (Avl<T> & t)
	{
		if(this!=&t)
		{
			this->removeDecendent(root);
			root=new Node<T>(t.getRoot());
			createCopy(t.root, root);
		}

		return *this;
	}

	void insert(T val)
	{
		if(root==0)
		{
			root = new Node<T>(val);
			return;
		}
		insert(root, val, root);		
	}

	void inOrder()
	{
		LVR(root);
	}


	~Avl()
	{
		removeDecendent(root);
	}

};

#endif
