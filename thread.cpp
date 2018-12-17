#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void Work()
{
    for (int i = 0; i < 10; ++i) {
        cout << "T id " << this_thread::get_id() << ", i = " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
	thread th(Work);

	for(int i = 0; i < 10; ++i)
	{
		cout << "M id " << this_thread::get_id() << ", i = " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();
	cout << "Thread joined!" << endl;
	return 0;
}
