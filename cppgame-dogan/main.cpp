#include "SetView.h"
#include <boost/log/trivial.hpp>
#include <windows.h>

int main()
{
	BOOST_LOG_TRIVIAL(info) << "Application started";
	sf::Thread thread1{[](){
		SetView{};
		}
	};
	sf::Thread thread2{[](){
		SetView::setDefaultHeight(200);
		SetView::setDefaultWidth(800);
		SetView{};
		}
	};
	thread1.launch();
	thread2.launch();
	return 0;
}