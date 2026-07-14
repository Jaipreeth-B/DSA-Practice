//header files
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tree<
    Key, // data type stored like int , pair<int,int> etc
    Mapped, //like a map , for ordered set we write null_tpye(since no mapped value)
    Compare,// sorting order ; less<int> for Ascending ; greater<int> for Descending
    Tag,//implementation type , most commonly used is red-black tree "rb_tree_tag" , rarely used is Splay tree(for faster access of repeated same values)
    Node_Update 
// For Node Update
// Magic feature.

// Usually

// tree_order_statistics_node_update

// This enables

// find_by_order()
// order_of_key()
>

