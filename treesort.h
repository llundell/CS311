//	treesort.h
//	Laura Lundell & Khan Howe
//	Started: 11/13/18
//	Updated: 11/20/18
//	Header for class treesort.h
//	Exercise A: Treesort
//	Exercise B: Associative Dataset Class Template
/*	Sources used:
*			Dr. Chappell's slides treesort.h skeleton
*/

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <iterator>
using std::iterator_traits;
#include <algorithm>
using std::stable_sort;
using std::move;
#include <vector>
using std::vector;
#include <iterator>
using std::distance;

template <typename ValType>
struct BSTreeNode
{
    ValType _data;
    std::shared_ptr<BSTreeNode> _leftChild;
    std::shared_ptr<BSTreeNode> _rightChild;

    explicit BSTreeNode(const ValType & data,
                        std::shared_ptr<BSTreeNode> leftChild = nullptr,
                        std::shared_ptr<BSTreeNode> rightChild = nullptr)
        :_data(data),
        _leftChild(leftChild),
        _rightChild(rightChild)
    {}
    ~BSTreeNode() = default;

    BSTreeNode & operator<(const BSTreeNode & other)
    {
        //TODO Write function
    }
};

// Insert()
// Takes a smart pointer by reference and the item to be inserted
template<typename ValType>
void insert(std::shared_ptr<BSTreeNode<ValType>> & head, ValType val)
{
	// if pointer is empty, set it to point to a new node
	if (head == nullptr)
	{
		head = std::make_shared<BSTreeNode<ValType>>(val);
		return;
	}

	if (val < head->_data)
	{
		insert(head->_leftChild, val);
	}
	else
	{
		insert(head->_rightChild, val);
	}

}

//Needs to be an inorder traversal
// Takes a pointer to a tree and an iterator by reference
// If the pointer is null, return.
//
template<typename ValType, typename FDIter>
void traverse(std::shared_ptr<BSTreeNode<ValType>> & head,
					FDIter & iter)
{
		if (head == nullptr)
			return;

		traverse(head->_leftChild, iter);
		*iter++ = head->_data;
		traverse(head->_rightChild, iter);
}

// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // ValType is the type that FDIter points to
    using ValType = typename iterator_traits<FDIter>::value_type;

		// Create new binary tree with nullptr at head
		std::shared_ptr<BSTreeNode<ValType>> head = nullptr;
		for (FDIter itemToInsert = first; itemToInsert != last; ++itemToInsert)
		{
			insert(head, *itemToInsert);
		}

		traverse(head, first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED
