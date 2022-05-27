#include <iostream>
#include "./models/turing_machine.h"

using namespace std;
using namespace machines;

int main(int argc, char* argv[]) {
    TuringMachine tm;
    MachineState state_1;
    MachineState state_2;

    state_1.addTransition('+', '+', 1, &state_1);
    state_1.addTransition('0', '0', 1, &state_1);
    state_1.addTransition('1', '1', 1, &state_1);
    state_1.addTransition('2', '2', 1, &state_1);
    state_1.addTransition('3', '3', 1, &state_1);
    state_1.addTransition('4', '4', 1, &state_1);
    state_1.addTransition('5', '5', 1, &state_1);
    state_1.addTransition('6', '6', 1, &state_1);
    state_1.addTransition('7', '7', 1, &state_1);
    state_1.addTransition('8', '8', 1, &state_1);
    state_1.addTransition('9', '9', 1, &state_1);
    state_1.addTransition('_', '_', -1, &state_2);


    state_2.addTransition('+', '+', 0, nullptr);
    state_2.addTransition('0', '1', 0, nullptr);
    state_2.addTransition('1', '2', 0, nullptr);
    state_2.addTransition('2', '3', 0, nullptr);
    state_2.addTransition('3', '4', 0, nullptr);
    state_2.addTransition('4', '5', 0, nullptr);
    state_2.addTransition('5', '6', 0, nullptr);
    state_2.addTransition('6', '7', 0, nullptr);
    state_2.addTransition('7', '8', 0, nullptr);
    state_2.addTransition('8', '9', 0, nullptr);
    state_2.addTransition('9', '0', -1, &state_2);


    tm.add_state(state_1);
    tm.add_state(state_2);

    vector<char> tape;
    tape.push_back('+');
    tape.push_back('+');
    tape.push_back('+');
    tape.push_back('1');
    tape.push_back('9');
    tape.push_back('9');
    tape.push_back('_');
    tape.push_back('_');
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