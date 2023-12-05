#include <iostream>
using namespace std;

template<class T>
struct TreeNode {
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* parent;
};

template<class T>
void print(T& data) {
	cout << data << "  ";
}

template<class T>
class BinTree {
public:
	BinTree();
	BinTree(TreeNode<T>* root);
	const TreeNode<T>* GetRoot()const;
	bool Empty()const;
	bool GetElem(const TreeNode<T>* cur, T& e)const;
	bool SetElem(TreeNode<T>* cur, const T& e);
	void InOrder(void(*visit)(const T& e))const;
	void InOrder(void(*visit)(const T& e),TreeNode<T>* p)const;

	void PreOrder(void(*visit)(const T& e))const;
	void PreOrder(void(*visit)(const T& e),TreeNode<T>* p)const;

	void PostOrder(void(*visit)(const T& e))const;
	void PostOrder(void(*visit)(const T& e),TreeNode<T>*p)const;

	void LeverOrder(void(*visit)(const T& e))const;
	int NodeCount()const;
	int NodeCount(TreeNode<T>* p)const;

	const TreeNode<T>* LeftChild(const TreeNode<T>* cur)const;
	const TreeNode<T>* RightChild(const TreeNode<T>* cur)const;
	const TreeNode<T>* Parent(const TreeNode<T>* cur)const;
	void InsertLeftChild(TreeNode<T>* cur, const T& e);
	void InsertRightChild(TreeNode<T>* cur, const T& e);
	void DeleteLeftChild(TreeNode<T>* cur);
	void DeleteRightChild(TreeNode<T>* cur);
	int Height()const;
	int Height(TreeNode<T>* p)const;

private:
	TreeNode<T>* root;
};

template<class T>
const TreeNode<T>*  BinTree<T>::LeftChild(const TreeNode<T>* cur)const {
	return cur->left;
}

template<class T>
const TreeNode<T>* BinTree<T>::RightChild(const TreeNode<T>* cur)const {
	return cur->right;
}

template<class T>
const TreeNode<T>* BinTree<T>::Parent(const TreeNode<T>* cur)const {
	return cur->parent;
}

template<class T>
void BinTree<T>::InsertLeftChild(TreeNode<T>* cur, const T& e) {
	if (cur->left == NULL) {
		cur->left = new TreeNode<T>;
		cur->left->data = e;
		cur->left->left = cur->left->right = NULL;
	}
	TreeNode<T>* temp = cur->left;
	cur->left = new TreeNode<T>;
	cur->left->data = e;
	cur->left->left = temp;
	cur->left->right = NULL;
}

template<class T>
void BinTree<T>::InsertRightChild(TreeNode<T>* cur, const T& e) {
	if (cur->right == NULL) {
		cur->right = new TreeNode<T>;
		cur->right->data = e;
		cur->right->left = cur->right->right = NULL;
	}
	TreeNode<T>* temp = cur->right;
	cur->right = new TreeNode<T>;
	cur->right->data = e;
	cur->right->right = temp;
	cur->right->left = NULL;
}

template<class T>
void BinTree<T>::DeleteLeftChild(TreeNode<T>* cur) {
	delete cur->left;
}

template<class T>
void BinTree<T>::DeleteRightChild(TreeNode<T>* cur) {
	delete cur->right;
}

template<class T>
int BinTree<T>::Height()const {
	return this->Height(this->root);
}

template<class T>
int BinTree<T>::Height(TreeNode<T>* p)const {
	if (p == NULL)return -1;
	return max(this->Height(p->left), this->Height(p->right)) + 1;
}

template<class T>
BinTree<T>::BinTree() {
	this->root = NULL;
}

template<class T>
BinTree<T>::BinTree(TreeNode<T>* root) {
	this->root = root;
}

template<class T>
const TreeNode<T>* BinTree<T>::GetRoot()const {
	return this->root;
}

template<class T>
bool BinTree<T>::Empty()const {
	return this->root == NULL;
}

template<class T>
bool BinTree<T>::GetElem(const TreeNode<T>* cur, T& e)const {
	if (cur == NULL)return false;
	e = cur->data;
	return true;
}

template<class T>
bool BinTree<T>::SetElem(TreeNode<T>* cur, const T& e) {
	if (cur == NULL)return false;
	cur->data = e;
	return true;
}

template<class T>
void BinTree<T>::InOrder(void(*visit)(const T& e),TreeNode<T>* p)const {
	if (p != NULL) {
		this->InOrder(visit,p->left);
		visit(p->data);
		this->InOrder(visit,p->right);
	}
}

template<class T>
void BinTree<T>::InOrder(void(*visit)(const T& e))const {
	this->InOrder(visit, this->root);
}

template<class T>
void BinTree<T>::PreOrder(void(*visit)(const T& e), TreeNode<T>* p)const {
	if (p != NULL) {
		visit(p->data);
		this->PreOrder(visit, p->left);
		this->PreOrder(visit, p->right);
	}
}

template<class T>
void BinTree<T>::PreOrder(void(*visit)(const T& e))const {
	this->PreOrder(visit, this->root);
}

template<class T>
void BinTree<T>::PostOrder(void(*visit)(const T& e), TreeNode<T>* p)const {
	if (p != NULL) {
		this->PostOrder(visit, p->left);
		this->PostOrder(visit, p->right);
		visit(p->data);
	}
}

template<class T>
void BinTree<T>::PostOrder(void(*visit)(const T& e))const {
	this->PostOrder(visit, this->root);
}

template<class T>
void BinTree<T>::LeverOrder(void(*visit)(const T& e))const {
	TreeNode<T>* queue[999];
	int head, tail;
	head = tail = 1;
	queue[tail++] = this->root;
	while (head < tail) {
		if (queue[head] != NULL) {
			visit(queue[head]->data);
			queue[tail++] = queue[head]->left;
			queue[tail++] = queue[head]->right;
		}
		head++;
	}
}

template<class T>
int BinTree<T>::NodeCount()const {
	return this->NodeCount(this->root);
}


template<class T>
int BinTree<T>::NodeCount(TreeNode<T>* p)const {
	if (p == NULL)return 0;
	int count = 1;
	count += this->NodeCount(p->left);
	count += this->NodeCount(p->right);
	return count;
}

int main() {
	TreeNode<int>* t8 = new TreeNode<int>;t8->data = 8;t8->left = NULL;t8->right = NULL;
	TreeNode<int>* t7 = new TreeNode<int>;t7->data = 7;t7->left = NULL;t7->right = NULL;
	TreeNode<int>* t6 = new TreeNode<int>;t6->data = 6;t6->left = NULL;t6->right = NULL;
	TreeNode<int>* t3 = new TreeNode<int>;t3->data = 3;t3->left = t6;t3->right = t7;
	TreeNode<int>* t5 = new TreeNode<int>;t5->data = 5;t5->left = t5->right = NULL;
	TreeNode<int>* t4 = new TreeNode<int>;t4->data = 4;t4->left = t8,t4->right = NULL;
	TreeNode<int>* t2 = new TreeNode<int>;t2->data = 2;t2->left = t4;t2->right = t5;

	TreeNode<int>* root = new TreeNode<int>;root->data = 1;root->left = t2;root->right = t3;
	t2->parent = t3->parent = root;t4->parent = t5->parent = t2;t6->parent = t7->parent = t3;t8->parent = t4;
	BinTree<int> bt(root);

	bt.InOrder(print);
	cout << endl << "-------------------------------" << endl;
	bt.PreOrder(print);
	cout << endl << "-------------------------------" << endl;
	bt.PostOrder(print);
	cout << endl << "-------------------------------" << endl;
	bt.LeverOrder(print);
	cout << endl << "-------------------------------" << endl;
	cout << "树高:" << bt.Height() << "  " << "节点个数:" << bt.NodeCount() << endl;

	return 0;
}