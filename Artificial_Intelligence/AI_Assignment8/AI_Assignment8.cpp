#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Rule {
    string condition1;
    string condition2;
    string conclusion;
};

bool backward_chaining(const string& goal, const vector<string>& facts, const vector<Rule>& rules) {

    for (const string& fact : facts) {
        if (fact == goal) {
            cout << "Goal '" << goal << "' is a known fact. Success!" << endl;
            return true;
        }
    }

    cout << "Goal '" << goal << "' is not a known fact. Trying to prove it..." << endl;

    for (const auto& rule : rules) {
        if (rule.conclusion == goal) {
            cout << "Found a rule: IF " << rule.condition1 << " AND " << rule.condition2 << " THEN " << rule.conclusion << endl;

            if (backward_chaining(rule.condition1, facts, rules) &&
                backward_chaining(rule.condition2, facts, rules)) {
                
                cout << "Successfully proved the conditions for goal '" << goal << "'. Success!" << endl;
                return true; 
            }
        }
    }

    cout << "Could not prove goal '" << goal << "'. Failure." << endl;
    return false;
}

int main() {
   
    vector<string> facts = {"A", "C"};
    vector<Rule> rules = {
        {"A", "C", "E"}, 
        {"E", "C", "D"}, 
        {"D", "C", "B"}  
    };

    string goal_to_prove = "G";

    cout << "Attempting to prove the goal: " << goal_to_prove << endl;
    
    if (backward_chaining(goal_to_prove, facts, rules)) {
        cout << "\nConclusion: The goal '" << goal_to_prove << "' has been proven." << endl;
    } else {
        cout << "\nConclusion: The goal '" << goal_to_prove << "' could not be proven." << endl;
    }

    return 0;
}