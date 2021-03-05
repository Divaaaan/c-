#include <iostream>


using namespace std;

struct node {
	int value;
	node* left, * rigth, * perent;
	node(int value, node* perent = NULL, node* left = NULL, node* rigth = NULL) {
		this->value = value;
		this->rigth = rigth;
		this->left = left;
		this->perent = perent;
	}
	void add(int value) {
		/*Если K>X, рекурсивно добавить (K, V) в правое поддерево Т.
		Если K<X, рекурсивно добавить (K, V) в левое поддерево Т.
		Если K=X, заменить V текущего узла новым значением.*/
		if (value < this->value) {
			if (this -> left == NULL) {
				this->left = new node(value, this);
				return;
			}
			this->left->add(value);
		}
		else if ((value > this->value)) {
			if (this -> rigth == NULL) {
				this->rigth = new node(value, this);
				return;
			}
			this->rigth->add(value);
		}
		else if (value == this->value) {
			return;
		}
	}
	node* find(int value) {
		/*Если K=X, выдать ссылку на этот узел и остановиться.
		Если K>X, рекурсивно искать ключ K в правом поддереве Т.
		Если K<X, рекурсивно искать ключ K в левом поддереве Т.*/
		if (this->value == value) {
			return this;
		}
		if (this->value > value) {
			if (this->left == NULL) {
				return NULL;
			}
			this->left->find(value);
		}
		if (this->value < value) {
			if (this->rigth == NULL) {
				return NULL;
			}
			this->rigth->find(value);
		}
	}
	node* remove() {
		if (this->left == NULL && this->rigth == NULL) {
			if (this->perent == NULL) {
				delete this;
				return NULL;
			}
			if (this->perent->value > this->value) {
				this->perent->left = NULL;
			}
			else
				this->perent->rigth = NULL;
			delete this;
			return NULL;
		}
		if (this->left == NULL) {
			if (this->perent != NULL) {
				if (this->perent->value > this->value) {
					this->perent->left = this->rigth;
				}
				else {
					this->perent->rigth = this->rigth;
				}
			}
			this->rigth->perent = this->perent;
			node* e = this->rigth;
			delete this;
			return e;
		}
		if (this->rigth == NULL) {
			if (this->perent != NULL) {
				if (this->perent->value > this->value) {
					this->perent->left = this->left;
				}
				else {
					this->perent->rigth = this->left;
				}
			}
			this->left->perent = this->perent;
			node* e = this->left;
			delete this;
			return e;
		}
		node* e = this->rigth;
		while (e->left != NULL) {
			e = e->left;
		}
		this->left->perent = e;
		e->left = this -> left;
		node* n = this->rigth;
		delete this;
		return n;

	}
};


int main(){
	
}
