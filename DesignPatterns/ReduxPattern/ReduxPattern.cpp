/**
 * Used to manage state in centralized manner
 * It has 3 Principles 
 * Single source of truth: State of app is stored in object tree with in single store
 * State is read-only: only way to change state is action, which is an object describing what happend
 * Changes are made with pure functions: Reducers (state, action)
 * State - app state , Action - describe change in state, Reducer (state, action) perform action to get new state,
 * Store - Holds all states, allows dispatching actions to trigger state changes using reducers.
*/

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

enum ActionType {
    INCREMENT,
    DECREMENT
};

struct Action {
    ActionType type;
    int payload;
};

struct State {
    int counter;
};

State reducer(const State& state, const Action& action) {
    switch(action.type) {
        case INCREMENT:
            return { state.counter + action.payload };
        case DECREMENT:
            return { state.counter - action.payload };
        default:
            return state;
    }
}

using ListnerType = std::function<void()>;
using ReducerType = std::function<State(const State&, const Action&)>;

class Store {

public:

    Store(State initialState, ReducerType reducer): m_state(initialState), m_reducer(reducer) {}

    void dispatch(const Action& action) {
        m_state = m_reducer(m_state, action);
        notifyListeners();
    }

    State getState() {
        return m_state;
    }

    void subscribe(ListnerType listener) {
        m_listeners.push_back(listener);
    }

private:
    void notifyListeners() {
        for (const auto& listenerCallback: m_listeners) {
            listenerCallback();
        }
    }

    State m_state;
    ReducerType m_reducer;
    vector<ListnerType> m_listeners; 
};


int main() {
    State initialState = { 0 };
    Store store {initialState, reducer};

    store.subscribe([&](){
        cout << "State changed " << store.getState().counter << endl;
    });

    store.dispatch({INCREMENT, 1});
    store.dispatch({DECREMENT, 34});
    store.dispatch({INCREMENT, 122});

    return 0;

}





























