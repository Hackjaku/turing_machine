#include "./turing_machine.h"

using namespace machines;

void MachineState::addTransition(char read, char write, int direction, MachineState* next_state) {
    transitions.push_back(make_tuple(read, write, direction, next_state));
}

void TuringMachine::run() {
    current_state = &states[0];
    int position = 0;
    while(current_state != nullptr) {
        current_state = current_state->performTransition(tape, position);
    }
}

MachineState* MachineState::performTransition(vector<char> &tape, int &position) {
    for(auto transition : transitions) {
        if(get<0>(transition) == tape[position]) { // trovo la transizione corrispondente
            tape[position] = get<1>(transition); // scrivo sul nastro
            position += get<2>(transition); // sposto il cursore
            return get<3>(transition); // ritorno il nuovo stato
        }
    }
    return nullptr; // questo stato non accetta l'input, vado nello stato terminale
}

vector<char> TuringMachine::get_tape() {
    return tape;
}

void TuringMachine::input_tape(vector<char> tape) {
    this->tape = tape;
}

void TuringMachine::add_state(MachineState state) {
    states.push_back(state);
}

MachineState* TuringMachine::get_state_pointer(int index) {
    if (this->states.size() >= index) {
        return &this->states[index];
    }
    return nullptr;
}