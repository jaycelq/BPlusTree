#include "BPlusTree.hpp"
#include <string>
int main()
{
    BPlusTree bt;
    bt.put(10, "a");
    bt.put(9, "e");
    bt.put(8, "b");
    bt.put(7, "c");
    bt.put(6, "d");
    bt.put(5, "e");
    bt.put(3, "f");
    bt.put(3, "i");
    bt.put(2, "k");
    bt.put(1, "a");
    bt.put(0, "b");
    bt.put(17, "d");
    bt.put(18, "g");
    bt.put(13, "h");
    bt.put(19, "i");
    bt.put(23, "k");
    bt.put(20, "a");
    bt.put(24, "b");
    bt.put(28, "c");
    bt.put(27, "d");
    bt.put(21, "f");
    bt.put(16, "g");
    bt.put(23, "h");
    bt.put(26, "i");
    bt.put(29, "k");
    string r;
    map<int, string> res = bt.getrange(1,16);
    map<int, string>::iterator it;
    for (it = res.begin(); it != res.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    if(bt.get(16, r)) {
        cout << r << endl;
    }
}
