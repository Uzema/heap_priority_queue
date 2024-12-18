#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class heap {

	vector<T> tree;

public:

	heap() {
		vector<T> tree;
	}

	heap(int heap_size): tree(heap_size) {
		if (heap_size < 0) {
			throw "Heap size cant be negative";
		}
	}

	void print() {
		for (int i = 0; i < tree.size(); i++) {
			cout << tree[i] << " ";
		}
		cout << endl;
	}

	T top() {
		return tree[0];
	}

	void pop() {
		tree[0] = tree[tree.size() - 1];
		tree.pop_back();
		diving(0);
	}

	void push(int value) {
		tree.push_back(value);
		emersion(tree.size() - 1);
	}

	int leftChild(int i) {
		if (i >= tree.size() || (2 * i + 1 >= tree.size())) {
			return -1;
		}
		else {
			return (2 * i + 1);
		}
		
	}

	int rightChild(int i) {
		if (i >= tree.size() || (2 * i + 2 >= tree.size())) {
			return -1;
		}
		else {
			return (2 * i + 2);
		}
		
	}

	int parent(int i) {
		if (i < 0) {
			throw "no parent for a negative index";
		}
		//if (i == 0) {
		//	return 0;
		//} //unnecessary as (0-1)/2 already is 0
		return ((i - 1) / 2);
	}

	int minChild(int i) {
		if (rightChild(i) == -1) {
			return leftChild(i);
		}

		if (tree[leftChild(i)] > tree[rightChild(i)]) {
			return rightChild(i);
		}
		else {
			return leftChild(i);
		}
	}

	void emersion(int i) { //всплытие - снизу вверх
		while (i != 0 && tree[i] < tree[parent(i)]) {
			swap(tree[i], tree[parent(i)]);
			i = parent(i);
		}
	}

	void diving(int i) { //погружение - сверху вниз
		int min_child = 0;
		while (leftChild(i) != -1) {
			min_child = minChild(i);

			if (tree[i] <= tree[min_child]) {
				break;
			}
			swap(tree[i], tree[min_child]);
			i = min_child;
		}
	}

};

#endif
