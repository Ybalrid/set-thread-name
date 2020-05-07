#include <iostream>
#include <thread>
#include <atomic>

#include "set_thread_name.hpp"

using namespace std::chrono_literals;
using std::cin;
using std::cout;
using std::endl;

void pause()
{
	cin.get();
	cin.clear();
}

void interactive_test()
{
	cout << "This program just set the name of a thread, and let it run until you press the RETURN key.\n";
	cout << "Check in your debug tool that the name of the thread has been applied." << endl;

	std::atomic_bool running = true;
	std::thread my_thread{ [&running]
	{
		while (running)
		{
			cout << "hello thread..." << endl;
			std::this_thread::sleep_for(1s);
		}

		cout << "Thread exited!" << endl;
	} };

	yba::set_name(my_thread, "Hello Printer");
	my_thread.detach();

	pause();
	running = false;

	std::this_thread::sleep_for(2s);
}

void automated_test()
{
	
	std::atomic_bool running = true;
	std::thread my_thread{ [&running]
	{
		while (running)
		{
			cout << "hello thread..." << endl;
			std::this_thread::sleep_for(1s);
		}

		cout << "Thread exited!" << endl;
	} };

	yba::set_name(my_thread, "Hello Printer");
	my_thread.detach();
	std::this_thread::sleep_for(3s);
	running = false;
	std::this_thread::sleep_for(1s);
}

int main(int argc, char** argv)
{
	try 
	{
		if (argc < 2)
			interactive_test();
		else
			automated_test();
	}
	catch(const std::exception& e)
	{
		cout << e.what();
		return -1;
	}
	return 0;
}
