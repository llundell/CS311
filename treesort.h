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


#endif //#ifndef FILE_TREESORT_H_INCLUDED
