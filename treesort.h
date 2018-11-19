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


template <typename ValType>
struct BSTreeNode
{
    ValType _data;
    std::shared_ptr<BSTreeNode> _leftChild;
    std::shared_ptr<BSTreeNode> _rightChild;

    BSTreeNode() :_data(), _leftChild(nullptr), _rightChild(nullptr)
    {}


	explicit BSTreeNode(const ValType & data,
                    std::shared_ptr<BSTreeNode> leftChild = nullptr,
                    std::shared_ptr<BSTreeNode> rightChild = nullptr)
    :_data(data),
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
};



// Insert()
// Takes a smart pointer by reference and the item to be inserted
template <typename ValType>
void insert(std::shared_ptr<BSTreeNode<ValType>> & treeNode, const ValType & item)
{
    // // if pointer is empty, set it to point to a new node
    // if (treeNode == nullptr)
    // {
    //     treeNode = std::make_shared<BSTreeNode<ValType>>(item);
    // }
    // if (item < (treeNode->_data))
    // {
    //     insert(treeNode->_leftChild, item);
    // }
    // else
    // {
    //     insert(treeNode->_rightChild, item);
    // }

}

//Needs to be an inorder traversal
// Takes a pointer to a tree and an iterator by reference
// If the pointer is null, return.
//
template <typename FDIter, typename ValType>
void traverse(std::shared_ptr<BSTreeNode<ValType>> treeNode, FDIter & iter)
{
       // if (treeNode != nullptr)
       // {
       //     traverse(treeNode->_leftChild, iter);
       //     *iter++ = (treeNode->_data);
       //     traverse(treeNode->_rightChild, iter);
       // }
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
    std::shared_ptr<BSTreeNode<ValType>> root;
    for (FDIter itemToInsert = first; itemToInsert != last; ++itemToInsert)
    {
        insert(root, *itemToInsert);
    }
    traverse(root, first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED
