#pragma once

#include <iostream>

/* Примечания:
 * template <typename T> - это синтаксис объявления шаблонного класса
 * const после объявления метода запрещяет изменение полей класса
 * внутри этого метода
 * */

/* Говорим, что дальше в программе будет
 * определение для шаблонного класса List
 * */
template <typename T> class List;

/* Link - это вспомогательный класс, который используется
 * как котейнер для указателей на предыдущий и следующий
 * элементы, а также как хранилище данных для каждого
 * элемента, который мы добавили в лист.
 * */
template <class T>
class Link
{
	friend class List<T>;
private:
	Link(const T &e)
		: value(e), nextLink(nullptr), prevLink(nullptr) {}
	Link(const T &e, Link *prevLink, Link *nextLink)
		: value(e), nextLink(nextLink), prevLink(prevLink) {}

	T value;
	Link<T> *nextLink;
	Link<T> *prevLink;
};

/* List - это класс, содержащий в себе указатели на первый и
 * последний элементы последовательности объектов типа Link.
 * Основной его задачей является предоставление интерфейса
 * для взаимодействия с этой последовательностью.
 * */
template <typename T>
class List {
public:
	List();
	~List();

	T &operator [] (size_t index);

	bool isEmpty() const;
	size_t Size() const;
	T &Back() const;
	T &Front() const;

	void Insert(size_t index, const T &e);
	void PushFront(const T &e);
	void PushBack(const T &e);
	void Remove(size_t index);
	void RemoveFront();
	void RemoveBack();
	//iterator begin() const;
	//iterator end() const;
	//void Insert(iterator pos, const T &e);

private:
	Link<T> *firstLink;
	Link<T> *lastLink;
	size_t listSize;
};
