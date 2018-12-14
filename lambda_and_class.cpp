#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class WorkWithThread
{
public:
	void WorkSimple()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID - " << this_thread::get_id() <<
		 " --------------------- Work simple start ---------------------" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID - " << this_thread::get_id() <<
		" --------------------- Work simple end ---------------------" << endl;
	}

	int Work(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID - " << this_thread::get_id() <<
		 " --------------------- Work calc start ---------------------" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID - " << this_thread::get_id() <<
		" --------------------- Work calc end ---------------------" << endl;
		return a*a;
	}

};

int main()
{
	WorkWithThread w;

	thread t1( &WorkWithThread::WorkSimple, w);

	int res;
	thread t2(
		[&]()
		{
			res = w.Work(7);
		}
	);
	

	for(int i = 1; i <= 10; ++i)
	{
		cout << "ID - " << this_thread::get_id() << " " << i << " MAIN" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	
	t1.join();
	t2.join();
	cout << "Result " << res << endl;

	return 0;
}