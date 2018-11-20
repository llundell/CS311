//	treesort.h
//	Laura Lundell & Khan Howe
//	Started: 11/13/18
//	Updated: 11/20/18
//	Header for function template treesort.h
//	Exercise A: Treesort
/*	Sources used:
*			Dr. Chappell's slides treesort.h skeleton
*			Charles helped eliminate checking for nullptr in insert() and traverse()
*			and instead checking if left/right children exist before inserting/traversing
*/

#ifndef FILE_TREESORTNOBSTREE_H_INCLUDED
#define FILE_TREESORTNOBSTREE_H_INCLUDED

#include <iterator>
using std::iterator_traits;
#include <algorithm>
using std::stable_sort;
using std::move;
#include <vector>
using std::vector;
#include <iterator>
using std::distance;
#include <memory>
// For std::shared_ptr and std::make_shared

// struct BSTreeNode
// Takes client-specified value type
// Invariants:
//	_data = data
//  _left = left in the node or a nullptr
//  _right = right in the node or a nullptr
// Requrements on types:
//		ValType needs a copy constructor,
//			destructor that doesn't throw, and
//				operator < for insert() function
template <typename ValType>
struct BSTreeNode
{
    ValType _data;
    std::shared_ptr<BSTreeNode<ValType>> _leftChild;
    std::shared_ptr<BSTreeNode<ValType>> _rightChild;

    BSTreeNode() :_data(), _leftChild(nullptr), _rightChild(nullptr)
    {}

	// 	BSTreeNode Constructor
	// 	Pre-conditions:
	//		Data must be valid, non-empty
	//	Post-conditions:
	//		Creates Binary Search Tree node with no children
	//	Strong guarantee, exception neutral but
	//		exception may throw if ValType throws
	explicit BSTreeNode(const ValType & data,
                    	std::shared_ptr<BSTreeNode<ValType>> leftChild = nullptr,
                    	std::shared_ptr<BSTreeNode<ValType>> rightChild = nullptr)
    									:_data(data),
									    _leftChild(leftChild),
									    _rightChild(rightChild)
    {}
		// Destructor
    ~BSTreeNode() = default;
};

//	Insert()
//	Pre-condition:
//		Takes a pointer to a tree and a data item
//			by reference
//	Post-condition:
//		Inserts data item uses recursive calls to
//			place item in sorted place
//	Requrements on types:
//		ValType needs a copy constructor,
//			destructor that doesn't throw, and
//				operator < for insert() function
//	Exceptions:
//		Throws if ValType operation throws
template <typename ValType>
void insert(std::shared_ptr<BSTreeNode<ValType>> & treeNode,
						ValType & item)
{
    if (item < treeNode-> _data)
    {
				// Check if there is a left node exists.
				// Otherwise, create new node to insert data.
        if (treeNode-> _leftChild) {
            insert(treeNode-> _leftChild, item);
        } else {
            treeNode-> _leftChild = std::make_shared<BSTreeNode<ValType>>(item);
        }
    }
		else
    {
				// If right child exists, insert data.
				// Otherwise, create new node to insert data.
        if (treeNode-> _rightChild) {
            insert(treeNode-> _rightChild, item);
        } else {
            treeNode-> _rightChild = std::make_shared<BSTreeNode<ValType>>(item);
        }
    }
}

//	traverse()
//	Pre-conditions:
//		Takes valid pointer
//	Post-condition:
//		Traverses a binary tree
//	Completes inorder traversal of binary search tree using recursion
//	Takes a pointer to a tree and an iterator by reference
//	Requrements on types:
//		ValType needs a copy constructor,
//			destructor that doesn't throw, and
//				operator < for insert() function
//	Exceptions: May throw if ValType operation throws
//	No-throw guarantee, exception neutral
//	Part of the FDIter type, not its own type
template <typename FDIter>
FDIter traverse(std::shared_ptr<BSTreeNode<typename std::iterator_traits<FDIter>::value_type>> & treeNode,
							FDIter iter)
{
				// check if left child exists instead of checking for nullptr
        if (treeNode-> _leftChild)
				{
            iter = traverse(treeNode-> _leftChild, iter);
        }
        *iter = (treeNode-> _data);
        ++iter;
        if (treeNode-> _rightChild)
				{
             iter = traverse(treeNode-> _rightChild, iter);
        }
        return iter;
}

//	treesort()
//	Pre-conditions:
//		Iterators first, last must be in the same range
//		FDIter last must be greater than or equal to first
//	Post-condition:
//		Sort a given range using Treesort
//	Requrements on types:
//		ValType needs a copy constructor,
//			destructor that doesn't throw, and
//				operator < for insert() function
//	Exceptions: May throw if ValType operation throws
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // ValType is the type that FDIter points to
    using ValType = typename iterator_traits<FDIter>::value_type;

    // Do nothing for an empty range
    if (first == last) return;
		// Root node using first value
    auto root = std::make_shared<BSTreeNode<ValType>>(*first);
		//current is first plus 1
		auto current = first;
    ++current;

    // Iterate from [first + 1, end)
  for ( ; current != last; ++current)
	{
		insert(root, *current);
	}
    traverse(root, first);
}

#endif //#ifndef FILE_TREESORT_H_INCLUDED
