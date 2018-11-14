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

    // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS, BUT IT DOES
    // NOT MEET THE REQUIREMENTS OF THE PROJECT.
    vector<ValType> buff(distance(first, last));
    move(first, last, buff.begin());
    stable_sort(buff.begin(), buff.end());
    move(buff.begin(), buff.end(), first);
}

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

template <typename ValType>
class BSTree
{
    using DATA_TYPE = std::shared_ptr<BSTreeNode<ValType>>;
private:
    DATA_TYPE _root;

public:
    BSTree() :_root()
    {}

    /*** Remaining 4 Constructors deleted ***/
  //Copy-Constructor
  BSTree(const BSTree & other) = delete;
  //Move-Constructor
  BSTree(BSTree && other) = delete;
  //Copy-Assignment
  BSTree & operator=(const BSTree & other) = delete;
  //Move-Assignment
  BSTree & operator=(const BSTree && other) = delete;


  void insert(ValType val)
  {
      //TODO Write function
  }


  //Needs to be an inorder traversal
  template <typename func>
  void traverse()
  {
      //TODO Write function
  }



};


#endif //#ifndef FILE_TREESORT_H_INCLUDED
