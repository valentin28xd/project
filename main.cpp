//
//  main.cpp
//  project
//
//  Created by valentin student on 16.10.2023.
//

#include <iostream>

using namespace std;

int main()
{
    int nr;
    int i, j;

    cout << "Introduceti numarul: ";
    cin >> nr;

    for (i = 1; i < nr; i++) {
        for (j = 1; j < nr; j++) {
            if (i*i + j*j == nr) {
                cout << "Numarul poate fi decompus in patratele: " << i << " " << j;
                return 0;
            }
        }
    }

    cout << "Numarul nu poate fi decompus\n";

    return 0;
}
