#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Function to simulate time passing
void wait(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int main() {
    // Display welcome message
    cout << "Welcome to a day in your life simulation!\n";

    // Simulate waking up
    cout << "You wake up.\n";
    wait(2);

    // Simulate having breakfast
    cout << "You have breakfast.\n";
    wait(3);

    // Simulate going to work/school
    cout << "You go to work/school.\n";
    wait(5);

    // Simulate having lunch
    cout << "You have lunch.\n";
    wait(3);

    // Simulate doing hobbies
    cout << "You spend some time doing your hobbies.\n";
    wait(4);

    // Simulate having dinner
    cout << "You have dinner.\n";
    wait(3);

    // Simulate going to bed
    cout << "You go to bed. Good night!\n";

    return 0;
}
