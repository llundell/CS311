//  tvsarray.h
//  Laura Lundell & Khan Howe
//  Started: 10/27/18
// Updated: 10/27/18
// Header for class Templated Very Smart Array Class
/* Sources used:
* Project 2 Code, Dr. Chappell's vsarray.cpp, vsarray.h,
* and slides on Project 5.
*/

#ifndef FILE_TVSARRAY_H_INCLUDED
#define FILE_TVSARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
using std::copy;
// For std::max; std::swap;

// *********************************************************************
// Template class TVSArray
// *********************************************************************
//
// Invariants:
// 	0 <= _size <= _capacity
// ValType must be valid C++ type
template <typename ValType>
class TVSArray {


	// TVSArray: Types
public:

	// size_type: type of sizes & indices
	using size_type = std::size_t;
	// value_type: type of data items
	using value_type = ValType;

	// iterator, const_iterator: random-access iterator types
	using iterator = value_type *;
	using const_iterator = const value_type *;

	// ***** TVSArray: internal-use constants *****
private:

	// Capacity of default-constructed object
	enum { DEFAULT_CAP = 16 };

	// ***** TVSArray: ctors, dctor, op= *****
public:

	//Default constructor
	// Strong Guarantee
	// Post-condition: creates new 0 item array of type ValType
	TVSArray()
	: _capacity(DEFAULT_CAP),
	_size(0),
	_data(new value_type[_capacity])
	{}

	explicit TVSArray(size_type size) :
	_size(size),
	_capacity(std::max(size, size_type(DEFAULT_CAP))),
	_data(new value_type[_capacity])
	{}

	// Copy ctor
	// Strong Guarantee
	TVSArray(const TVSArray & other)
				:_capacity(other._capacity),
				_size(other._size),
				_data(new value_type[other._capacity])
	{
		try
		{
			copy(other.begin(), other.end(), begin());
		}
		catch (...)
		{
			delete [] _data;
			throw;
		}
	}
	// Move ctor
	// No-Throw Guarantee

	TVSArray(TVSArray && other) noexcept
				:_capacity(other._capacity),
				_size(other._size),
				_data(other._data)
	{
		other._capacity = 0;
		other._size = 0;
		other._data = nullptr;
	}

	// Copy assignment operator
	// ??? Guarantee
	TVSArray & operator=(const TVSArray & other)
	{
		TVSArray temp(other);
		swap(temp);
		return *this;
	}

	// Move assignment operator
	// No-Throw Guarantee
	// ?? DO we need to create a new array?
	TVSArray & operator=(TVSArray && other) noexcept
	{
		swap(other);
		return *this;
	}

	// Dctor
	// No-Throw Guarantee
	~TVSArray()
	{
		delete [] _data;
	}

	// ***** TVSArray: general public operators *****
public:
	// operator[] - non-const & const
	// No-Throw Guarantee
	value_type & operator[](size_type index)
	{
		return _data[index];
	}
	const value_type & operator[](size_type index) const
	{
		return _data[index];
	}

	// ***** TVSArray: general public functions *****
public:

	// size
	// No-Throw Guarantee
	size_type size() const
	{
		return _size;
	}

	// empty
	// No-Throw Guarantee
	bool empty() const
	{
		return size() == 0;
	}

	// begin - non-const & const
	// No-Throw Guarantee
	iterator begin()
	{
		return _data;
	}
	const_iterator begin() const
	{
		return _data;
	}

	// end - non-const & const
	// No-Throw Guarantee
	iterator end()
	{
		return begin() + size();
	}
	const_iterator end() const
	{
		return begin() + size();
	}

	// resize
	// ??? Guarantee
	void resize(size_type newSize)
	{
		if (newSize <= _capacity) {
			_size = newSize;
		}
		else {
			size_type newCapacity = _size * 2;

			if (newCapacity <= newSize) {
				newCapacity = newSize;
			}
			if (newCapacity < DEFAULT_CAP) {
				newCapacity = DEFAULT_CAP;
			}

			auto newData = new value_type[newCapacity];

			try {
				std::copy(begin(), end(), newData);
			}
			catch(...)
			{
			delete [] newData;
			throw;
			}
			std::swap(_data, newData);
			_size = newSize;
			_capacity = newCapacity;
			delete [] newData;

		}
}

	// insert
	// ??? Guarantee
	iterator insert(iterator pos,
	const value_type & item)
	{
		size_type index = pos - begin();
		resize(size()+1);
		pos = begin() + index;
		std::rotate(pos, end()-1, end());
		*pos = item;
		return pos;  // Dummy return
	}

	// erase
	// ??? Guarantee
	iterator erase(iterator pos)
	{



		return pos;  // Dummy return
		// TODO: Write this!!!
	}

	// push_back
	// InsertEnd operation.
	// ??? Guarantee
	void push_back(const value_type & item)
	{
		insert(end(), item);
	}

	// pop_back
	// RemoveEnd operation.
	// ??? Guarantee
	void pop_back()
	{
		erase(end()-1);
	}

	// swap
	// No-Throw Guarantee
	void swap(TVSArray & other) noexcept
	{
		using std::swap;
		swap(_capacity, other._capacity);
		swap(_size, other._size);
		swap(_data, other._data);
	}

	// ***** TVSArray: data members *****
private:

	size_type    _capacity;  // Size of our allocated array
	size_type    _size;      // Size of client's data
	value_type * _data;      // Pointer to array

};  // End class TVSArray


#endif //#ifndef FILE_TVSARRAY_H_INCLUDED
