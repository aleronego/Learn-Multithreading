#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;
void PrintBox(char ch)
{
	mtx.lock();
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			cout << ch;
			this_thread:: sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl << endl;
	mtx.unlock();
}

int main()
{
	thread th1(PrintBox, '*');
	thread th2(PrintBox, '#');

	th1.join();
	th2.join();
}
