#include <iostream>
#include "./models/turing_machine.h"

using namespace std;
using namespace machines;

int main(int argc, char* argv[]) {
    TuringMachine tm;
    MachineState state_1;
    state_1.addTransition('0', '1', 1, &state_1);
    tm.add_state(state_1);
    vector<char> tape;
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('0');
    tape.push_back('_');
    tm.input_tape(tape);
    tm.run();
    vector<char> tape_result = tm.get_tape();
    for(auto c : tape_result) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}