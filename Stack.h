#pragma once
#include <string>


class Stack {
public:
	//Конструктор класс

	virtual void push(const std::string new_element) = 0;

	virtual void pop() = 0;

	virtual bool isEmpty() = 0;

	virtual std::string back() = 0;



	virtual ~Stack() {}
	
};