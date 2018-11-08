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


// Exercise A reverseList
// Reversing a Linked List
// Pre-conditions: valid shared pointer to a Linked List
// No-throw Guarantee
template<typename ValType>
void reverseList(std::shared_ptr<LLNode2<ValType>> & head)
{
	if(head != nullptr)
	{
		std::shared_ptr<LLNode2<ValType>> oldHead;
		std::shared_ptr<LLNode2<ValType>> newHead;

		while(head != nullptr)
		{
			oldHead = head->_next;
			head->_next = newHead;
			newHead = head;
			head = oldHead;
		}
		head = newHead;

	}
	return;
}


// Exercise B class ListMap
// 
template<typename KeyType, typename ValType>
class ListMap
{
	public:

		using DATA_TYPE = std::shared_ptr<LLNode2<std::pair<KeyType,ValType>>>;





// 	Default ctor. Creates an empty dataset.
	ListMap() : _head()
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


	// Function size. No parameters. Returns an integer of an appropriate type giving the number of key-value pairs in the dataset.
	size_t size() const
	{
		auto p = _head;  // Iterates through list
	    size_t n = 0;   // Number of nodes so far
	    while (p)
	    {
	        p = p->_next;
	        ++n;
	    }
	    return n;
	}
// Function empty. No parameters. Returns a bool indicating whether there are no key-value pairs in the dataset.
	bool empty() const
	{
		if (size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
/* Function find. One parameter: a key. Returns const DATA_TYPE * for a c
onst ListMap and DATA_TYPE * for a non-const ListMap. If the key lies in the dataset,
then the returned pointer points to the associated value. Otherwise, the returned pointer is nullptr.
*/
	const ValType * find(KeyType key) const
	{
		auto p = _head;
		while(p)
		{
			KeyType currentKey = std::get<0>(p->_data);
			if (currentKey == key) {
				return &(std::get<1>(p->_data));
			}
			else {
				p = p->_next;
			}
		}
		return nullptr;

	}

	ValType * find(KeyType key)
	{
		auto p = _head;
		while(p)
		{
			KeyType currentKey = std::get<0>(p->_data);
			if (currentKey == key) {
				return &(std::get<1>(p->_data));
			}
			else {
				p = p->_next;
			}
		}
		return nullptr;

	}

/* Function insert. Two parameters: a key and an associated value. Returns nothing.
If an equal key does not lie in the dataset, then the key-value pair is inserted.
If an equal key does lie in the dataset, then the existing key-value pair is replaced with that given.

*/
	void insert(KeyType key, ValType val)
	{
		auto pos = find(key);
		if (pos) {
			(*pos)= val;
		}
		else {

			_head = std::make_shared<LLNode2<std::pair<KeyType,ValType>>>(std::make_pair(key, val), _head);
		}
	}
// Function erase. One parameter: a key. Returns nothing. If an equal key lies in the dataset,
//then that key-value pair is removed. If an equal key does not lie in the dataset, then the function does nothing.
	void erase(KeyType key)
	{
		//TODO try some debugging using cout.
		auto p = _head;
		auto previous = &_head;
		bool found = false;
		// cout << "Calling While Loop" << endl;
		while(not found)
		{
			// cout << "Iteration in while Loop" << endl;

			KeyType currentKey = std::get<0>(p->_data);
			if (currentKey == key) {
				found = true;
				*previous = p->_next;
				p->_next = nullptr;
			}
			else {
				previous = &((*previous)->_next);
				p = *previous;
			}
		}
	}

/* Function traverse. One parameter: a function or function object (its type can simply be a template parameter).
Returns nothing. The passed function is expected to take two parameters, key type and data type, and return nothing.
The passed function is called on each key-value pair in the dataset.
*/
	template<typename Func>
	void traverse(Func f)
	{
		auto p = _head;
		while(p) {
			f(p->_data.first, p->_data.second);
			p = p->_next;
		}
	}


private:
	DATA_TYPE _head;
}; // End class ListMap

#endif //#ifndef FILE_DA6_H_INCLUDED
