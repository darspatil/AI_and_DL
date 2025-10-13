#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>  

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char c){ return tolower(c); });
    return str;
}

int main() {
    cout << "Welcome to the University Help Desk" << endl;
    cout << "I can help with questions about admissions, fees, and campus life." << endl;
    cout << "Type 'exit' to end the chat." << endl;

    string userInput;
    
    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);
        string lowerInput = toLower(userInput);
        if (lowerInput == "exit") {
            cout << "Chatbot: Thank you for visiting. Goodbye! 👋" << endl;
            break;
        }

        if (lowerInput.find("admission") != string::npos || lowerInput.find("apply") != string::npos) {
            cout << "Chatbot: For admissions, please visit our official website at www.university.edu/admissions. The deadline is May 31st. 🎓" << endl;
        } else if (lowerInput.find("fees") != string::npos || lowerInput.find("tuition") != string::npos) {
            cout << "Chatbot: Tuition fees for the academic year are $15,000. You can find a detailed breakdown on our student portal. 💵" << endl;
        } else if (lowerInput.find("campus") != string::npos || lowerInput.find("hostel") != string::npos) {
            cout << "Chatbot: We offer various campus facilities including a library, sports complex, and on-campus hostels. For more details, visit the campus services page. 🏫" << endl;
        } else if (lowerInput.find("hello") != string::npos || lowerInput.find("hi") != string::npos) {
            cout << "Chatbot: Hello! How can I assist you today?" << endl;
        } else {
            cout << "Chatbot: I'm sorry, I don't have information on that. Can you please rephrase your question or ask about admissions, fees, or campus life? 🤔" << endl;
        }
    }

    return 0;
}