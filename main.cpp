// #include "GLScene.hpp"
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[]){
    // GLScene(argc, argv);
    // glutMainLoop();

    // Test //
    list<char> lc;
    for(int i=0; i<26; i++){
        char ch = 'a' + i;
        lc.push_back(ch);
    }
    list<char>::iterator itr;
    for(itr = lc.begin(); itr != lc.end(); itr++){
        cout << *itr << endl;
    }
    //
}