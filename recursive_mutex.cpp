#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
recursive_mutex rm;

void rec(int i)
{
    rm.lock();
    cout << i << " ";
    if (i <= 1) 
    {
        cout << endl;
        rm.unlock();
        return;
    }
    --i;
    rec(i);
    rm.unlock();
}

int main()
{
    thread th(rec, 10);
    thread th2(rec, 20);
    th.join();
    th2.join();
    return 0;
}