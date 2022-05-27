#ifndef TURING_MACHINE
#define TURING_MACHINE

#include <iostream>
#include <vector>
#include "boost/tuple/tuple.hpp"

namespace machines {
    using namespace std;

    class MachineState {
    private:
        // ogni stato e' composto da un vettore contenente ogni possibile carattere in lettura
        // per ciascuno di essi, ha segnato con quale carattere va sostituito, in che direzione muoversi e a quale stato commutare
        // nullptr indica la fine della computazione
        vector<tuple<char, char, int, MachineState*>> transitions;
    public:
        void addTransition(char, char, int, MachineState*);
        MachineState* performTransition(vector<char>&, int&);
    };

    class TuringMachine{
    public:
        void input_symbols(vector<char>);
        void add_state(MachineState);
        void run();
        void input_tape(vector<char>);
        vector<char> get_tape();
        MachineState* get_state_pointer(int);

    private:
        vector<MachineState> states;
        MachineState* current_state;
        vector<char> tape;
    };
}

#endif