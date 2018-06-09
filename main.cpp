#include <iostream>
#include "List.h"
#include "List.cpp"

struct TestClass {
	int value;

	TestClass() : value(0) {
		std::cout << "TestClass()\n";
	}
	TestClass(int value) : value(value) {
		std::cout << "TestClass()\n";
	}
	~TestClass() {
		std::cout << "~TestClass()\n";
	}
	TestClass(const TestClass& obj) {
		std::cout << "TestClass Copy\n";
		value = obj.value;
	}
};

void Foo() {

	List<TestClass> list;
	list.PushFront(TestClass(1 + std::rand() % 13));
	list.Insert(0, TestClass(1 + std::rand() % 13));
	list.PushBack(TestClass(1 + std::rand() % 13));
	list.Insert(0, TestClass(1 + std::rand() % 13));
	list.PushFront(TestClass(1 + std::rand() % 13));

	list.RemoveBack();
	list.RemoveFront();

	for (int i = 0; i < list.Size(); i++) {
		std::cout << list[i].value << std::endl;
	}
}

int main() {
	Foo();
	std::cout << "Hello, World!" << std::endl;
	return 0;
}