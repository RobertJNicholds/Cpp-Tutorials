#pragma once
#include <math.h>
#include <iostream>

template <typename T>
class Vector3
{
public:
	Vector3();	
	Vector3(T v1, T v2, T v3);
	~Vector3();

	T Magnitude() const;
	
	Vector3<T>& operator=(const Vector3<T>& rhs);	
	template <typename E>
	friend bool operator<(const Vector3<E> &lhs, const Vector3<E> &rhs);
	template <typename E>
	friend bool operator>(const Vector3<E>& lhs, const Vector3<E>& rhs);
	template <typename E>
	friend Vector3<E> operator*(const Vector3<E>& a, const Vector3<E>& b);	

	template <typename E>
	friend ostream& operator<<(ostream& ostr, const Vector3<E> &vec);

private:
	T value1;
	T value2;
	T value3;
};


template <typename T>
Vector3<T>::Vector3() : value1(0), value2(0), value3(0)
{

}

template <typename T>
Vector3<T>::Vector3(T v1, T v2, T v3) : value1(v1), value2(v2), value3(v3)
{

}

template <typename T>
Vector3<T>::~Vector3()
{

}

template <typename T>
T Vector3<T>::Magnitude() const
{
	return (T)sqrt((value1 * value1) + (value2 * value2) + (value3 + value3));
}

template <typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T> & rhs)
{
	value1 = rhs.value1;
	value2 = rhs.value2;
	value3 = rhs.value3;
}

template <typename E>
bool operator<(const Vector3<E> &lhs, const Vector3<E> &rhs)
{
	return lhs.Magnitude() < rhs.Magnitude();
}

template <typename E>
bool operator>(const Vector3<E> &lhs, const Vector3<E> &rhs)
{
	return lhs < rhs;
}

template <typename E>
ostream& operator<<(ostream& ostr, const Vector3<E> &vec)
{
	ostr << "( " << vec.value1 << ", " << vec.value2 << ", " << vec.value3 << " )";
	return ostr;
}

template <typename E>
Vector3<E> operator*(const Vector3<E>& a, const Vector3<E>& b)
{

}


