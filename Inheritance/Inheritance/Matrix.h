#pragma once
template <typename T>
class Matrix
{
public:
	Matrix(int x = default_x, int y = default_y);
	~Matrix();
	Matrix(const Matrix<T>& src);
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	T get_element(int x, int y) const;
	void set_element(int x, int y, const T elem) const;
	// constant elements
	static const int default_x = 3;
	static const int default_y = 3;
		
	Matrix<T>& operator=(const Matrix<T>& rhs);
	Matrix<T>& operator+(const Matrix<T> &rhs);
	Matrix<T>& operator-(const Matrix<T> &rhs);

protected:
	T** cells;
	int x_size;
	int y_size;
};

template <typename T>
Matrix<T>::Matrix(int x, int y) :
	x_size(x), y_size(y) {
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new T[y_size];
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& src) :
	x_size(src.x_size), y_size(src.y_size)
{
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i)
	{
		cells[i] = new T[y_size];
		memcpy_s(cells[i], (y_size * sizeof(T)), src.cells[i], (y_size * sizeof(T)));
		//memcpy(cells[i], src.cells[i], y_size * sizeof(T)); // same but less safe than memcpy_s
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

template <typename T>
T Matrix<T>::get_element(int x, int y) const {
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::set_element(int x, int y, T elem) const {
	cells[x][y] = elem;
}


template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	if (this == &rhs) return (*this);

	// release old memory
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;

	// allocate new memory
	cells = new T*[rhs.x_size];
	for (int i = 0; i < rhs.x_size; ++i) {
		cells[i] = new T[rhs.y_size];
		memset(cells[i], 0, (rhs.y_size * sizeof(T)));
	}

	// copy values
	for (int i = 0; i < rhs.x_size; ++i) {
		for (int j = 0; j < rhs.y_size; ++j) {
			cells[i][j] = rhs.cells[i][j];
		}
	}
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T> &rhs)
{
	for (int x = 0; x < x_size; ++x)
	{
		for (int y = 0; y < y_size; ++y)
		{
			set_element(x, y, cells[x][y] + rhs.cells[x][y]);
		}
	}

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-(const Matrix<T> &rhs)
{
	for (int x = 0; x < x_size; ++x)
	{
		for (int y = 0; y < y_size; ++y)
		{
			set_element(x, y, cells[x][y] - rhs.cells[x][y]);
		}
	}

	return *this;
}
