#pragma once
#include <math.h>
#include <iostream>
#include "Matrix.h"

template <typename T>
class Vector3
{
public:
	Vector3();	
	Vector3(T v1, T v2, T v3);
	~Vector3();

	inline T Magnitude() const;
	inline T Dot(const Vector3<T> &a) const;
	inline Vector3<T> Cross(const Vector3<T> &a) const;
	inline Vector3<T> operator+(const Vector3<T>& rhs) const;
	inline void operator=(const Vector3<T>& rhs);
	inline Vector3<T> operator*(T scalar) const;
	template <typename E>
	inline Vector3<E>& operator*(const Matrix<E> &rhs);
	inline bool operator==(const Vector3<T> &rhs);

	template <typename E>
	inline friend bool operator<(const Vector3<E> &lhs, const Vector3<E> &rhs);
	template <typename E>
	inline friend bool operator>(const Vector3<E> &lhs, const Vector3<E>& rhs);	
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
T Vector3<T>::Dot(const Vector3<T> &a) const
{
	return (a.value1 * value1 + a.value2 * value2 + a.value3 * value3);
}

template <typename T>
Vector3<T> Vector3<T>::Cross(const Vector3<T> &a) const
{
	return Vector3<T>(value2 * a.value3 - value3 * a.value2,
					value3 * a.value1 - value1 * a.value3,
					value1 * a.value2 - value2 * a.value1);
}

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &rhs) const
{
	return Vector3<T>(value1 + rhs.value1, value2 + rhs.value2, value3 + rhs.value3);
}

template <typename T>
void Vector3<T>::operator=(const Vector3<T> &rhs)
{
	value1 = rhs.value1;
	value2 = rhs.value2;
	value3 = rhs.value3;
}

template <typename T>
Vector3<T> Vector3<T>::operator*(T scalar) const
{
	return Vector3<T>(value1 * scalar, value2 * scalar, value3 * scalar);
}

template <typename T>
bool Vector3<T>::operator==(const Vector3<T> &rhs)
{
	if (value1 == rhs.value1
		&& value2 == rhs.value2
		&& value3 == rhs.value3)
		return true;

	return false;
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

template<typename T>
template<typename E>
inline Vector3<E>& Vector3<T>::operator*(const Matrix<E>& rhs)
{
	value1 = rhs.get_cells()[0][0] * value1 + rhs.get_cells()[1][0] * value2 + rhs.get_cells()[2][0] * value3;
	value2 = rhs.get_cells()[0][1] * value1 + rhs.get_cells()[1][1] * value2 + rhs.get_cells()[2][1] * value3;
	value3 = rhs.get_cells()[0][2] * value1 + rhs.get_cells()[1][2] * value2 + rhs.get_cells()[2][2] * value3;
	
	return *this;
}
