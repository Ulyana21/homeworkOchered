#ifndef __IQUEUE_H
#define __IQUEUE_H	

const int deff = 10;

template <class T> class IQueue {
public:
	// добавить в хвост
	virtual void put(const T& elem) = 0;
	// взять из головы
	virtual T take() = 0;
	// получить элемент по номеру 0...size-1,
	// 0 это голова, size-1 это хвост
	virtual T get(int i) const = 0;
	// узнать размер очереди
	virtual int size() const = 0;
};

class massExp {};

template <class T> class MyQueue
{
private:
	T* mass;
	int SizeMass;
	int a;
public:
	MyQueue();
	MyQueue(int i);
	~MyQueue();

	virtual void put(const T& elem);

	virtual T take();

	virtual T get(int i) const;

	virtual int size() const;
};

template <class T> MyQueue<T>::MyQueue()
{
	SizeMass = 0;
	a = deff;
	mass = new T[a];
}

template <class T> MyQueue<T>::MyQueue(int i)
{
	if (i <= 0)
		a = deff;
	else
		a = i;
	mass = new T[a];
	SizeMass = 0;
}

template <class T> MyQueue<T>::~MyQueue()
{
	delete[] mass;
}

template <class T> void MyQueue<T>::put(const T& elem)
{
	SizeMass++;
	if (SizeMass >= a)
	{
		T* Newmass;
		a = SizeMass + 1;
		Newmass = new T[a];
		for (int i = 0; i < SizeMass; i++)
		{
			Newmass[i] = mass[i];
		}
		delete[] mass;
		mass = Newmass;
	}
	mass[SizeMass - 1] = elem;
	return;
}

template <class T> T MyQueue<T>::take()
{
	if (SizeMass == 0)
	{
		throw massExp();
	}
	T elem = mass[0];
	SizeMass--;
	for (int i = 0; i < SizeMass; i++)
	{
		mass[i] = mass[i + 1];
	}
	return elem;
}

template <class T> T MyQueue<T>::get(int i) const
{
	if (SizeMass == 0 || i >= SizeMass)
	{
		throw massExp();
	}
	return mass[i];
}

template <class T> int MyQueue<T>::size() const
{
	return SizeMass;
}
#endif