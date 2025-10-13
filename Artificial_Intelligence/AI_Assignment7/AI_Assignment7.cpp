#include <iostream>
#include <vector>

using namespace std;

struct Rule {
    int condition1;
    int condition2; 
    int conclusion;
};

void forward_chaining(vector<bool>& facts, const vector<Rule>& rules) {
    bool new_fact_deduced = true;

    while (new_fact_deduced) {
        new_fact_deduced = false;

        for (const auto& rule : rules) {
            if (facts[rule.condition1] && facts[rule.condition2]) {
                if (!facts[rule.conclusion]) {
                    facts[rule.conclusion] = true;
                    new_fact_deduced = true;
                    cout << "Rule fired! A new fact at index " << rule.conclusion << " is now true." << endl;
                }
            }
        }
    }
}

int main() {
    vector<bool> facts = {true, false, true, false, false};

    vector<Rule> rules = {
        {0, 2, 4},
        {4, 2, 3},
        {3, 2, 1} 
    };

    cout << "Initial facts:" << endl;
    for (int i = 0; i < facts.size(); ++i) {
        cout << "Fact " << (char)('A' + i) << ": " << (facts[i] ? "True" : "False") << endl;
    }
    cout << "\nStarting forward chaining...\n" << endl;

    forward_chaining(facts, rules);

    cout << "\nFinal facts after forward chaining:" << endl;
    for (int i = 0; i < facts.size(); ++i) {
        cout << "Fact " << (char)('A' + i) << ": " << (facts[i] ? "True" : "False") << endl;
    }
    
    return 0;
}