#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void Allstackelement(stack<int> p);


void Allstackelement(stack<int> p) {
    if (p.empty()) {
        return;
    }

    int x = p.top();

    p.pop();

    Allstackelement(p);

    cout << x << " ";

    p.push(x);
}




int main() {
    string command;
    stack<int> fwb;
    int value;

    while (true){

        getline(cin, command);
        if(command.empty()) continue;

        istringstream iss(command);
        char command;
        iss >> command;
        

        if(command == 'U') {
            if (iss >> value) {
                fwb.push(value);
                Allstackelement(fwb);
            }
        }

        if(command == 'O') {
            if(fwb.empty()) {
                cout << "-1" << endl;
            }
            else {

                if (!fwb.empty()) {
                int temp_val = fwb.top();
                fwb.pop();
                cout << "Popped : " << temp_val << endl;
                }

            }
        }

        if(command == 'T') {
            cout << "Top : " << fwb.top();
        }

        if(command == 'P') {
            Allstackelement(fwb);
        }

        if(command == 'N') {
            cout << "Stack Size : " << fwb.size();
        }
    }
    return 0;
}
