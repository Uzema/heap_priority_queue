#include "heap.h"
#include <gtest.h>

TEST(heap, CanCreateHeap) {
	ASSERT_NO_THROW(heap<int> heap);
}

TEST(heap, CanCreateWithSize) {
	ASSERT_NO_THROW(heap<int> heap(5));
}

TEST(heap, CantCreateHeapWithNegativeSize) {
	ASSERT_ANY_THROW(heap<int> heap(-1));
}

TEST(heap, CanTop) {
	heap<int> heap;
	heap.push(1);
	heap.push(2);
	heap.push(3);
	EXPECT_EQ(1, heap.top());
}

TEST(heap, CanPush) {
	heap<int> heap;
	heap.push(1);
	EXPECT_EQ(1, heap.top());
}

TEST(heap, CanPop) {
	heap<int> heap;
	heap.push(2);
	heap.push(1);
	heap.pop();
	EXPECT_EQ(2, heap.top());
}

TEST(heap, CorrectlyReturnsWhenLeftChildDoesntExist) {
	heap<int> heap;
	heap.push(1);
	EXPECT_EQ(-1, heap.leftChild(0));
}

TEST(heap, CorrectlyReturnsWhenRightChildDoesntExist) {
	heap<int> heap;
	heap.push(1);
	EXPECT_EQ(-1, heap.rightChild(0));
}

TEST(heap, CorrectlyReturnsLeftChild) {
	heap<int> heap;
	heap.push(1);//0
	heap.push(2);//1 lchild
	heap.push(3);//2 rchild
	EXPECT_EQ(1, heap.leftChild(0));
}

TEST(heap, CorrectlyReturnsRightChild) {
	heap<int> heap;
	heap.push(1);//0
	heap.push(2);//1 lchild
	heap.push(3);//2 rchild
	EXPECT_EQ(2, heap.rightChild(0));
}

TEST(heap, ThrowsWhenAskedForParentOfANegativeIndex) {
	heap<int> heap;
	ASSERT_ANY_THROW(int par = heap.parent(-2));
}

TEST(heap, CorrectlyReturnsParent) {
	heap<int> heap;
	heap.push(1);//0 - parent of 1 and 2
	heap.push(2);//1 
	heap.push(3);//2 
	EXPECT_EQ(0, heap.parent(1));
	EXPECT_EQ(0, heap.parent(2));
}

TEST(heap, MinChild) {
	heap<int> heap;
	heap.push(1);//0
	heap.push(3);//1 
	heap.push(2);//2 
	EXPECT_EQ(2, heap.minChild(0));
}

TEST(heap, MinChildWhenOnly1Child) {
	heap<int> heap;
	heap.push(1);//0
	heap.push(3);//1
	EXPECT_EQ(1, heap.minChild(0));
}

