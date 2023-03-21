#include <iostream>
#include <string>
#include "Simd/SimdLib.hpp"
#include "Simd/SimdView.hpp"

using namespace std;
using namespace Simd;

int main() {

    View<Allocator> view1;

    view1.Load("sampleImage2.png");
    
    string msg;
    cout << "Enter a message to embed in the image: " << endl;
    getline(cin, msg);

    
}