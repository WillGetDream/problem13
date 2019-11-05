#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
void checkBySet(int* arr,int size) ;
int main() {
    srand((time(0)));
    int ary1[10]={4,2,3,1,5,6,7,8,9,10};
    int ary2[10]={3,2,3,2,5,6,7,8,9,2};
    int ary3[10]={4,2,3,4,2,6,7,8,10,10};

    // O(n) only!!! just use 2 for loop and less memory
    checkBySet(ary1,10);
    checkBySet(ary2,10);
    checkBySet(ary3,10);

    return 0;
}

void checkBySet(int* arr,int size) {

    set<int> myset(arr+0,arr+10);
    sort(arr,arr+10);
    int max,count=0;
    map<int,int> rs;

    //no mode
    if (myset.size() == size) {
        cout << "no mode in the array " << endl;
    }else { //other mode, just get the O(n) only!!!
        int max = 0;
        for (int i = 0; i < size; i++) {
            set<int>::iterator it = myset.begin();
            int p = 1;
            //if we can insert O(1), remove, if next one can insert, then insert and update map, and remove,go to next one
            if (myset.insert(arr[i]).second == false) {
                it = myset.insert(arr[i]).first;
                myset.erase(arr[i]);
                if (*it == arr[size]) { //last of set should be same as the last of array
                    it++;
                }
            } else {
                p++;
                if (p > max) max = p;
                rs.insert(pair<int, int>(arr[i], p));
                myset.erase(arr[i]);
                if (it != myset.end()) {
                    it++;
                }
            }

        }

        for (auto it = rs.begin(); it != rs.end(); ++it) {
            if (it->second == max) {
                count++;
            }
        }
        if(count>2){
            cout << "Multiple mode in the array " << endl;
        }else{
            cout << "1 mode in the array " << endl;
        }
    }
}


