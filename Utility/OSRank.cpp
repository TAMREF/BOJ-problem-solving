#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace __gnu_pbds;

typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set X;

int main(){
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    std::cout << *X.find_by_order(3) << '\n'; //8
    std::cout << X.order_of_key(2) << '\n'; //1
    std::cout << X.order_of_key(9) << '\n'; //4
}
