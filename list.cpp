#include <iostream>


using namespace std;

struct node {
	int value;
	node* left, * rigth;
	node(int value, node* left, node* rigth) {
		this->value = value;
		this->rigth = rigth;
		this->left = left;
	}
};


struct List {
	node* first, * end = new node(0, NULL, NULL), * last;
private:
	int size = 0;
public:
	List() {
		first = end;
		last = end;
	}
	void add_l(int a, node* el) {
		size++;
		if (first == end) {
			first = new node(a, end, end);
			last = first;
			return;
		}
		if (first == el) {
			first = new node(a, end, el);
			el->left = first;
			return;
		}
		node* t = new node(a, el->left, el);
		el->left = t;
		t->left->rigth = t;
	}
	void add(int a, node* el) {
		size++;
		if (last == end) {
			first = new node(a, end, end);
			last = first;
			return;
		}
		if (last == el) {
			last = new node(a, el, end);
			el->rigth = last;
			return;
		}
		node* t = new node(a, el, el->rigth);
		el->rigth = t;
		t->rigth->left = t;
	}
	void del(node* el) {
		if (el == end) {
			throw exception("end can't be delted");
		}
		size--;
		if (el == last && el == first) {
			delete el;
			first = end;
			last = end;
			return;
		}
		if (el == first) {
			first = el->rigth;
			el->rigth->left = end;
			delete el;
			return;
		}
		if (el == last) {
			last = el->left;
			el->left->rigth = end;
			delete el;
			return;
		}
		el->left->rigth = el->rigth;
		el->rigth->left = el->left;
		delete el;
	}
	int len() {
		return size;
	}
	void print() {
		for (auto it = first; it != end; it = it->rigth) {
			cout << it->value << ' ';
		}
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;
	List s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.add(a, s.last);
	}
	s.print();
	int a, b;
	cin >> a >> b;
	s.add_l(b, s.first->rigth->rigth->rigth);
	s.print();
	s.del(s.first->rigth->rigth->rigth);
	for (auto it = s.last; it != s.end; it = it->left) {
		cout << it->value << ' ';
	}
	cout << endl;
	s.del(s.first);
	s.del(s.first);
	s.del(s.last);
	s.del(s.last);
	s.del(s.last);
	//s.del(s.last);

	//s.add_l(a, s.first);
	//s.add_l(a, s.last);
	//s.add(b, s.first);
	s.print();
}
