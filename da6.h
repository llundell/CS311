//	da6.h
//	Laura Lundell & Khan Howe
//	Started: 11/3/18
//	Updated: 11/8/18
//	Header for class da6.h
//	Exercise A: Reversing a linked list2
//	Exercise B: Associative Dataset Class Template
/*	Sources used:
*
*/

#ifndef FILE_DA6_H_INCLUDED
#define FILE_DA6_H_INCLUDED
#include "llnode2.h"
#include <memory> // for shared_pointer
#include <utility> // for std::pair


// Exercise A
template<typename ValType>
void reverseList(std::shared_ptr<LLNode2<ValType>> & head)
{



}


// Exercise B
template<typename KeyType, typename ValType>
class ListMap
{
	public:

		std::pair <KeyType,ValType> KVTYPE;

		// std::pair KVTYPE = pair(auto T1, auto T2);

		using DATA_TYPE = std::shared_ptr<LLNode2<KVTYPE>>;





// 	Default ctor. Creates an empty dataset.
	explicit ListMap()
	    {}

  ~ListMap()
  {
  }

  //Copy-Constructor
  ListMap(const ListMap & other) = delete;
  //Move-Constructor
  ListMap(ListMap && other) = delete;
  //Copy-Assignment
  ListMap & operator=(const ListMap & other) = delete;
  //Move-Assignment
  ListMap & operator=(const ListMap && other) = delete;



	// Dctor. As usual.
	// Function size. No parameters. Returns an integer of an appropriate type giving the number of key-value pairs in the dataset.
	int size()
	{
		return 0;
	}
// Function empty. No parameters. Returns a bool indicating whether there are no key-value pairs in the dataset.
	bool empty()
	{
		return true;
	}
/* Function find. One parameter: a key. Returns const DATA_TYPE * for a c
onst ListMap and DATA_TYPE * for a non-const ListMap. If the key lies in the dataset,
then the returned pointer points to the associated value. Otherwise, the returned pointer is nullptr.
*/
	const ValType * find(KeyType key)
	{
		return 0;
	}

/* Function insert. Two parameters: a key and an associated value. Returns nothing.
If an equal key does not lie in the dataset, then the key-value pair is inserted.
If an equal key does lie in the dataset, then the existing key-value pair is replaced with that given.

*/
	void insert(KeyType key, ValType val)
	{
	}
// Function erase. One parameter: a key. Returns nothing. If an equal key lies in the dataset,
//then that key-value pair is removed. If an equal key does not lie in the dataset, then the function does nothing.
	void erase(KeyType key)
	{
	}

/* Function traverse. One parameter: a function or function object (its type can simply be a template parameter).
Returns nothing. The passed function is expected to take two parameters, key type and data type, and return nothing.
The passed function is called on each key-value pair in the dataset.
*/
	template<typename Func>
	void traverse(Func f)
	{
	}
}; // End class ListMap

#endif //#ifndef FILE_DA6_H_INCLUDED
