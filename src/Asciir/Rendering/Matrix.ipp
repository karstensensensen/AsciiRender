#include "Matrix.h"

namespace Asciir
{
	template<typename T>
	Matrix<T>::Matrix(arVertex size)
	{
		resize(size);
	}

	template<typename T>
	T& Matrix<T>::at(arVertex coord)
	{
		return m_data[coord.x + coord.y * m_size.x];
	}

	template<typename T>
	T Matrix<T>::at(arVertex coord) const
	{
		return m_data[coord.x + coord.y * m_size.x];
	}

	template<typename T>
	T& Matrix<T>::at(size_t indx)
	{
		return m_data[indx];
	}

	template<typename T>
	T Matrix<T>::at(size_t indx) const
	{
		return m_data[indx];
	}

	template<typename T>
	arVertex Matrix<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	void Matrix<T>::resize(arVertex size)
	{
		T* tmp_ptr = new T[size.x * size.y];
		memset(tmp_ptr, NULL, size.x * size.y * sizeof(T));

		size_t cpy_amount = std::min(size.x, m_size.x) * sizeof(T);
		size_t loop_amount = std::min(size.y, m_size.y);

		for (size_t i = 0; i < loop_amount; i++)
		{
			memcpy(tmp_ptr + size.x * i, m_data + m_size.x * i, cpy_amount);
		}

		m_size = size;
		std::swap(m_data, tmp_ptr);

		delete[] tmp_ptr;
	}


	template<typename T>
	T& Matrix<T>::operator[](arVertex coord)
	{
		return at(coord);
	}

	template<typename T>
	T Matrix<T>::operator[](arVertex coord) const
	{
		return at(coord);
	}

	template<typename T>
	T& Matrix<T>::operator[](size_t indx)
	{
		return at(indx);
	}

	template<typename T>
	T Matrix<T>::operator[](size_t indx) const
	{
		return at(indx);
	}


	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Matrix<T>& mat)
	{
		for (size_t i = 0; i < mat.size().x * mat.size().y; i++)
		{
			stream << mat.at(i);

			if (i % mat.size().x == mat.size().x - 1)
				stream << '\n';
			else
				stream << ',';
		}

		return stream;
	}
}
