#include "BPlusTree.hpp"
#include <string>
int main()
{
    BPlusTree bt;
    bt.put(10, "a");
    bt.put(9, "b");
    bt.put(8, "c");
    bt.put(7, "d");
	bt.put(6, "e");
	bt.put(5, "f");
	bt.put(4, "g");
	bt.put(3, "h");
	bt.put(2, "i");
	bt.put(1, "k");
    string res;
    if(bt.get(10, res)) {
        cout << res << endl;
    }
}
