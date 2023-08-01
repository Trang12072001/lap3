#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int totalLines;
    cin >> totalLines;
    cin.ignore(); // Ignore the newline character after reading the totalLines value

    map<string, int> questionCountByTopic; // Map to store the count of questions for each topic

    // Read data and update the map
    for (int i = 0; i < totalLines; i++) {
        string topic;
        getline(cin, topic);

        // Ignore the empty line between topics
        if (topic.empty()) {
            continue;
        }

        // Read the questions for the current topic and update the map
        while (true) {
            string question;
            getline(cin, question);

            // Stop reading questions when encountering an empty line or reaching the end of input
            if (question.empty() || cin.eof()) {
                break;
            }

            // Increase the count of questions for the corresponding topic in the map
            questionCountByTopic[topic]++;
        }
    }

    // Print the result
    for (const auto& entry : questionCountByTopic) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
