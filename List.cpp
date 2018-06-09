#include "List.h"


template<typename T>
List<T>::List() : listSize(0), firstLink(nullptr), lastLink(nullptr) {}

template<typename T>
List<T>::~List() {
	/* Последовательно удаляем каждый элемент листа */
	std::cout << "~List()\n";
	int destroyCount = 0;
	while (firstLink != nullptr) {
		Link<T> *link = firstLink->nextLink;
		delete firstLink;
		firstLink = link;
		++destroyCount;
	}
	std::cout << "Removed links: " << destroyCount << std::endl;
}

template<typename T>
size_t List<T>::Size() const {
	return listSize;
}

template<typename T>
bool List<T>::isEmpty() const {
	return listSize;
}

template<typename T>
T &List<T>::Back() const {
	return *firstLink;
}

template<typename T>
T &List<T>::Front() const {
	return *lastLink;
}

template<typename T>
void List<T>::Insert(size_t index, const T &e) {
	if (index == listSize || firstLink == nullptr) {
		PushBack(e);
		return;
	}
	Link<T> *link;
	if (index < listSize / 2) {
		link = firstLink;
		for (size_t i = 0; i != index; i++, link = link->nextLink);
	}
	else {
		link = lastLink;
		for (size_t i = listSize-1; i != index; --i, link = link->prevLink);
	}
	Link<T> *newLink = new Link<T>(e, link->prevLink, link);
	if (link->prevLink != nullptr)
		link->prevLink->nextLink = newLink;
	else
		firstLink = newLink;
	link->prevLink = newLink;
	++listSize;
}

template<typename T>
T &List<T>::operator[](size_t index) {
	Link<T> *link;
	if (index < listSize / 2) {
		link = firstLink;
		for (size_t i = 0; i != index; ++i, link = link->nextLink);
	}
	else {
		link = lastLink;
		for (size_t i = listSize-1; i != index; --i, link = link->prevLink);
	}
	return link->value;
}

template<typename T>
void List<T>::PushBack(const T &e) {
	if (firstLink == nullptr) {
		firstLink = new Link<T>(e);
		lastLink = firstLink;
		listSize++;
		return;
	}
	Link<T> *link = lastLink;
	lastLink = new Link<T>(e);
	lastLink->prevLink = link;
	link->nextLink = lastLink;
	++listSize;
}

template<typename T>
void List<T>::PushFront(const T &e) {
	Link<T> *link = firstLink;
	firstLink = new Link<T>(e);
	if (link != nullptr) {
		link->prevLink = firstLink;
		firstLink->nextLink = link;
	}
	else {
		lastLink = firstLink;
	}
	++listSize;
}

template<typename T>
void List<T>::RemoveBack() {
	Link<T> *link = lastLink;
	if (listSize == 1) {
		firstLink = nullptr;
		lastLink = nullptr;
	}
	else {
		lastLink = lastLink->prevLink;
		lastLink->nextLink = nullptr;
	}
	delete link;
	--listSize;
}

template<typename T>
void List<T>::RemoveFront() {
	Link<T> *link = firstLink;
	if (listSize == 1) {
		firstLink = nullptr;
		lastLink = nullptr;
	}
	else {
		firstLink = firstLink->nextLink;
		firstLink->prevLink = nullptr;
	}
	delete link;
	--listSize;
}

template<typename T>
void List<T>::Remove(size_t index) {
	if (index == 0)
		RemoveFront();
	else if (index == listSize - 1)
		RemoveBack();
	else {
		Link<T> *link;
		if (index < listSize / 2) {
			link = firstLink;
			for (size_t i = 0; i != index; ++i, link = link->nextLink);
		}
		else {
			link = lastLink;
			for (size_t i = listSize-1; i != index; --i, link = link->prevLink);
		}
		link->prevLink->nextLink = link->nextLink;
		link->nextLink->prevLink = link->prevLink;
		delete link;
		--listSize;
	}
}
