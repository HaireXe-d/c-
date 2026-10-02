#pragma once
#include<iostream>
using namespace std;

template<class T>
class Myarray
{
public:
	Myarray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}

	Myarray(const Myarray& arr)
	{
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	Myarray& operator=(const Myarray & arr)
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	
	}

	void push_back(const T& val)
	{
		if (this->m_capacity == this->m_size)
		{
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}

	void pop_back()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	int getcapacity()
	{
		return this->m_capacity;
	}

	int getsize()
	{
		return this->m_size;
	}

	~Myarray()
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

private:

	T* pAddress;
	int m_capacity;
	int m_size;
};