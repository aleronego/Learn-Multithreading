#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx;
void PrintBox(char ch)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    {
        lock_guard<mutex> guard(mtx);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout << endl;
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
    thread th1(PrintBox, '*');
    thread th2(PrintBox, '#');

    th1.join();
    th2.join();
}
