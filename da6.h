//	da6.h
//	Laura Lundell & Khan Howe
//	Started: 11/3/18
//	Updated: 11/8/18
//	Header for class da6.h
//	Exercise A: Reversing a linked list2
//	Exercise B: Associative Dataset Class Template
/*	Sources used:
*			Dr. Chappell's slides on Project 6
*			& assignment instructions for post-conditions
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

		while(head)
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


//	*********************************************************************
//	Template class ListMap
//	*********************************************************************
//	Exercise B
//	Templated class
//	Invariants:
//	Requirements on types:
// 	ValType and KeyType must be valid C++ types
template<typename KeyType, typename ValType>
class ListMap
{
	public:

		using DATA_TYPE = std::shared_ptr<LLNode2<std::pair<KeyType,ValType>>>;

// ***** ListMap: ctors, dctor, op= *****
	public:
// Default ctor. Creates an empty dataset.
// Strong guarantee
// Pre-conditions: none
// Post-condition: sets _head pointer to nullptr
	ListMap() : _head()
	{}

// Destructor
// No-throw guarantee
// No pre- or post-conditions
  ~ListMap()
  {}

	/*** Remaining 4 Constructors deleted ***/
  //Copy-Constructor
  ListMap(const ListMap & other) = delete;
  //Move-Constructor
  ListMap(ListMap && other) = delete;
  //Copy-Assignment
  ListMap & operator=(const ListMap & other) = delete;
  //Move-Assignment
  ListMap & operator=(const ListMap && other) = delete;

// ***** ListMap: general public functions *****
public:
	//	size(). No parameters. Returns an integer of an appropriate type g
	//	Pre-conditions: none
	//	Post-condition: returns integer of an appropriate
	//		type giving the number of key-value pairs in the dataset.
	//	Strong Guarantee
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
//	empty()
//	Pre-conditions: none
//	Post-conditions: Returns a bool indicating
//		whether there are no key-value pairs in the dataset.
//	Strong Guarantee
	bool empty() const
	{
		if (size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
//	find() const
//	Pre-conditions: none
//	Post-conditions: Returns const pointer to the value, given the input KeyType
//		If key is not found, nullptr is returned
//	Strong Guarantee
	const ValType * find(KeyType key) const
	{
		auto p = _head;
		while(p)
		{
			KeyType currentKey = p->_data.first;
			if (currentKey == key) {
				return &(p->_data.second);
			}
			else {
				p = p->_next;
			}
		}
		return nullptr;
	}

//	find() non-const
// (same as above)
	ValType * find(KeyType key)
	{
		auto p = _head;
		while(p)
		{
			KeyType currentKey = p->_data.first;
			if (currentKey == key) {
				return &(p->_data.second);
			}
			else {
				p = p->_next;
			}
		}
		return nullptr;

	}

//	insert()
//	Pre-conditions: none
//	Post-conditions:
//		Insert key-value pair if equal key doesn't lie in dataset
//		Replaces existing key-value pair with
//		given pair if an equal key does lie in the dataset
//	Strong Guarantee
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

//	erase()
//	Pre-conditions: none
//	Post-conditions: If an equal key lies in the dataset,
//		then that key-value pair is removed by deleting the link
//		The previous node points to the node after the input
//		Otherwise, the function does nothing.
//	Strong Guarantee
	void erase(KeyType key)
	{
		auto p = _head;
		auto previous = &_head;
		bool found = false;
		while(not found)
		{
			KeyType currentKey = p->_data.first;
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

// traverse()
// Pre-conditions: must meet pre-conditions of function passed
// Post-conditions: completes passed operation on given values in linked list
// Basic-Guarantee (function could throw)
	template<typename Func>
	void traverse(Func f)
	{
		auto p = _head;
		while(p) {
			f(p->_data.first, p->_data.second);
			p = p->_next;
		}
	}

	// ***** ListMap: data members *****
private:
	DATA_TYPE _head;
}; // End class ListMap

#endif //#ifndef FILE_DA6_H_INCLUDED
