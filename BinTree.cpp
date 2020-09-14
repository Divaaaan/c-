#include<iostream>

using namespace std;

struct Node {
	int Val;
	Node* Left;
	Node* Right;
	Node* Prev;
	Node(int val, Node* prev = NULL, Node* right = NULL, Node* left = NULL)
	{
		Val = val;
		Right = right;
		Left = left;
		Prev = prev;
	}
};

struct Tree {
private:
	Node* root = NULL;
	Node* find(int val)
	{
		Node* cur = root;
		while (cur != NULL)
		{
			while (cur != NULL && val > cur->Val)
				cur = cur->Right;
			while (cur != NULL && val < cur->Val)
				cur = cur->Left;
			if (cur != NULL && cur->Val == val)
				return cur;
		}
		return NULL;
	}
public:
	void AddNode(int val)
	{
		if (root == NULL)
			root = new Node(val);
		else
		{
			Node* cur = root;
			while (true)
			{
				while (val > cur->Val)
				{
					if (cur->Right == NULL)
					{
						cur->Right = new Node(val, cur);
						return;
					}
					cur = cur->Right;
				}
				while (val <= cur->Val)
				{

					if (cur->Left == NULL)
					{
						cur->Left = new Node(val, cur);
						return;
					}
					cur = cur->Left;
				}
			}
		}
	}

	bool Find(int val)
	{
		return find(val);
	}

	bool Remove(int val)
	{
		auto tmp = find(val);
		if (tmp)
		{
			Node* inp = NULL;
			if (tmp->Right)
			{
				inp = tmp->Right;
				if (tmp->Left)
				{
					auto left = inp;
					while (left->Left)
						left = left->Left;
					left->Left = tmp->Left;
					tmp->Left->Prev = inp;
				}
				inp->Prev = tmp->Prev;
			}
			else if (tmp->Left)
			{
				inp = tmp->Left;
				inp->Prev = tmp->Prev;
			}
			if (tmp->Prev)
				if (tmp->Prev->Left == tmp)
					tmp->Prev->Left = inp;
				else
					tmp->Prev->Right = inp;
			if (root == tmp)
				root = inp;
			delete tmp;
			return true;
		}
		return false;
	}
};

int main()
{
	Tree tr;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			cin >> x;
			tr.Remove(x);
		}
		else if (tr.Find(x))
			cout << "Povtor" << endl;
		else

			tr.AddNode(x);

	}
}
