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

template <typename FDIter>
struct BSTreeNode
{
    FDIter _ptrToData;
    std::shared_ptr<BSTreeNode> _leftChild;
    std::shared_ptr<BSTreeNode> _rightChild;

		explicit BSTreeNode(FDIter iter,
                        std::shared_ptr<BSTreeNode> leftChild = nullptr,
                        std::shared_ptr<BSTreeNode> rightChild = nullptr)
        :_ptrToData(*iter),
        _leftChild(leftChild),
        _rightChild(rightChild)
    {}

    // explicit BSTreeNode(const ValType & data,
    //                     std::shared_ptr<BSTreeNode> leftChild = nullptr,
    //                     std::shared_ptr<BSTreeNode> rightChild = nullptr)
    //     :_data(data),
    //     _leftChild(leftChild),
    //     _rightChild(rightChild)
    // {}
    ~BSTreeNode() = default;

    BSTreeNode & operator<(const BSTreeNode & other)
    {
        //TODO Write function
    }
};


template <typename FDIter>
class BSTree
{
    using DATA_TYPE = std::shared_ptr<BSTreeNode<FDIter>>;
private:
    DATA_TYPE _root;
public:
	BSTree() :_root()
  {}

	// Create new binary tree with nullptr at head
	BSTree(FDIter first, FDIter last) :_root()
	{
		for (FDIter itemToInsert = first; itemToInsert != last; ++itemToInsert)
		{
			insert(*itemToInsert);
		}
	}

     /*** Remaining 4 Constructors deleted ***/
  //Copy-Constructor
  BSTree(const BSTree & other) = delete;
  //Move-Constructor
  BSTree(BSTree && other) = delete;
  //Copy-Assignment
  BSTree & operator=(const BSTree & other) = delete;
  //Move-Assignment
  BSTree & operator=(const BSTree && other) = delete;


	// Insert()
	// Takes a smart pointer by reference and the item to be inserted
	void insert(DATA_TYPE leaf, FDIter iter)
	{
		// if pointer is empty, set it to point to a new node
		if (leaf == nullptr)
		{
			leaf = std::make_shared<BSTreeNode<FDIter>>(*iter);
		}

		if (*iter < *(leaf->_ptrToData))
		{
			insert(leaf->_leftChild, *iter);
		}
		else
		{
			insert(leaf->_rightChild, *iter);
		}

  }
	 //Needs to be an inorder traversal
	 // Takes a pointer to a tree and an iterator by reference
	 // If the pointer is null, return.
	 //
	void traverse(DATA_TYPE leaf, FDIter & iter)
	{
			if (leaf != nullptr)
			{
				traverse(leaf ->_leftChild, iter);
				*iter++ = *(leaf->_ptrToData);
				traverse(leaf->_rightChild, iter);
			}
	}
};





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
		BSTree<FDIter> tree = BSTree(first, last);
		tree.traverse(first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED
