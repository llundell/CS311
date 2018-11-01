//	tvsarray.h
//	Laura Lundell & Khan Howe
//	Started: 10/27/18
//	Updated: 11/1/18
//	Header for class Templated Very Smart Array Class
/*	Sources used:
* 		Project 2 Code, Dr. Chappell's vsarray.cpp, vsarray.h,
*			slides on Project 5, and ssarray.h from Project 2
*/

#ifndef FILE_TVSARRAY_H_INCLUDED
#define FILE_TVSARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
using std::copy;
// For std::max; std::swap; std::rotate

// *********************************************************************
// Template class TVSArray
// *********************************************************************
//
// Invariants:
// 	0 <= _size <= _capacity
// Requirements on types:
// 	ValType must be valid C++ type
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

	// Default constructor & constructor from size
	// Strong Guarantee
	// Pre-conditions: none
	// Post-condition: creates new array of type ValType with size
	explicit TVSArray(size_type size = 0) :
				_capacity(std::max(size * 2, size_type(DEFAULT_CAP))),
				_size(size),
				// dynamic allocation will not happen if memory isn't available
				_data(new value_type[_capacity])
	{}

	// Copy constructor
	// Strong Guarantee
	// Pre-condition: valid TVSArray object passed in
	// Post-condition: new TVSArray object is created
	TVSArray(const TVSArray & other):
				_capacity(other._capacity),
				_size(other._size),
				_data(new value_type[other._capacity])
	{
		try
		{
			copy(other.begin(), other.end(), begin());
		}
		// catches all exceptions, deletes data if copy fails,
		// rethrows exception
		catch (...)
		{
			delete [] _data;
			throw;
		}
	}

	// Move constructor
	// No-Throw Guarantee
	// Pre-condition: valid TVSArray object passed in
	// Post-condition: the old object is no longer usable
	TVSArray(TVSArray && other) noexcept:
				_capacity(other._capacity),
				_size(other._size),
				_data(other._data)
	{
		other._capacity = 0;
		other._size = 0;
		other._data = nullptr;
	}

	// Copy assignment operator
	// Strong Guarantee
	// Pre-condition: valid TVSArray object pass in
	// Post-condition: If the TVSArray Objects are not equal,
	// 	then swap values
	TVSArray & operator=(const TVSArray & other)
	{
		// check for self-assignment
		if (this != & other)
		{
			TVSArray temp(other);
			swap(temp);
		}
		return *this;
	}

	// Move assignment operator
	// Pre-condition: valid TVSArray object pass in
	// Post-condition: swaps all values from old object to new object
	// No-Throw Guarantee
	TVSArray & operator=(TVSArray && other) noexcept
	{
		swap(other);
		return *this;
	}

	// Destructor
	// No-Throw Guarantee
	// No pre- or post-conditions
	~TVSArray()
	{
		delete [] _data;
	}

	// ***** TVSArray: general public operators *****
public:

	// operator[] - non-const & const
	// No-Throw Guarantee
	// Pre-condition: index is in valid range for array and non-negative
	// Post-condition: returns data from that index
	value_type & operator[](size_type index)
	{
		return _data[index];
	}
	// const version cannot change _data value
	const value_type & operator[](size_type index) const
	{
		return _data[index];
	}

	// ***** TVSArray: general public functions *****
public:

	// size()
	// No-Throw Guarantee
	// Pre-condition: none
	// Post-condition: returns _size of array
	size_type size() const
	{
		return _size;
	}

	// empty()
	// No-Throw Guarantee
	// Pre-condition: none
	// Post-condition: returns boolean value indicating whether
	// or not the array is size 0
	bool empty() const
	{
		return size() == 0;
	}

	// begin() - non-const & const
	// No-Throw Guarantee
	// Pre-condition: valid TVSArray object pass in
	// Post-condition: returns pointer to array[0]
	iterator begin()
	{
		return _data;
	}
	// const begin() cannot change value of _data
	const_iterator begin() const
	{
		return _data;
	}

	// end() - non-const & const
	// No-Throw Guarantee
	// Pre-condition: none
	// Post-condition: returns pointer to end of the array
	iterator end()
	{
		return begin() + size();
	}
	// const begin() cannot change value of _data at the iterator
	const_iterator end() const
	{
		return begin() + size();
	}

	// resize()
	// Strong Guarantee
	// Pre-condition: none
	// Post-condition: resizes TVSArray to new given size
	void resize(size_type newSize)
	{
		if (newSize <= _capacity) {
			_size = newSize;
		}
		else {
			// Create new temporary with new size
			// if this throws, nothing happens
			TVSArray temp(newSize);

			// if copy fails, data isn't modified so can still offer Strong Guarantee
			std::copy(begin(), end(), temp.begin());
			swap(temp);
		}
}

	// insert()
	// Basic Guarantee: rotate() could throw
	// Pre-condition: valid item & position
	// Post-condition: inserts item at given position,
	// 	resizes the array accordingly
	iterator insert(iterator pos,
	const value_type & item)
	{
		size_type index = pos - begin();
		// resize to create empty space at the end of array
		resize(size()+1);
		pos = begin() + index;
		std::rotate(pos, end()-1, end());
		*pos = item;
		return pos;

	}

	// erase()
	// Basic guarantee: rotate could throw
	// Pre-condition: valid iterator passed in
	// Post-condition: erases item at given position,
	// 	resizes the array by one
	iterator erase(iterator pos)
	{
		std::rotate(pos, pos+1, end());
		resize(size()-1);
		return pos;
	}

	// push_back
	// InsertEnd operation.
	// BasicGuarantee
	// Pre-condition: valid item reference
	// Post-condition: inserts item at the end of the array
	void push_back(const value_type & item)
	{
		insert(end(), item);
	}

	// pop_back()
	// RemoveEnd operation.
	// Basic Guarantee
	// Pre-condition: none
	// Post-condition: erases item at the end of the array
	void pop_back()
	{
		erase(end()-1);
	}

	// swap()
	// No-Throw Guarantee (will terminate if it throws with noexcept)
	// Pre-condition: valid TVSArray object passed in
	// Post-condition: swaps all private data member values
	void swap(TVSArray & other) noexcept
	{
		std::swap(_capacity, other._capacity);
		std::swap(_size, other._size);
		std::swap(_data, other._data);
	}

	// ***** TVSArray: data members *****
private:
	size_type    _capacity;  // Size of our allocated array
	size_type    _size;      // Size of client's data
	value_type * _data;      // Pointer to array

};  // End class TVSArray


#endif //#ifndef FILE_TVSARRAY_H_INCLUDED
