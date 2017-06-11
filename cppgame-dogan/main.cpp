#include "SetView.h"
#include <boost/log/trivial.hpp>
#include <windows.h>

int main() {
	BOOST_LOG_TRIVIAL(info)<< "Application started";
	SetView::setDefaultHeight(500);
	SetView::setDefaultWidth(800);
	SetView {};
	return 0;
}