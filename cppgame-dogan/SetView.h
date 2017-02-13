/*
 * SetView.h
 *
 *  Created on: 13.02.2017
 *      Author: Zmote
 */

#ifndef SETVIEW_H_
#define SETVIEW_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcpt.h>
#include <boost/log/trivial.hpp>

class SetView {
	static int defaultHeight;
	static int defaultWidth;
	int height;
	int width;
public:
	SetView() :
			height { SetView::getDefaultHeight() }, width { SetView::getDefaultWidth() } {
		init();
	}
	SetView(sf::Texture texture,int pHeight, int pWidth) :
			height { pHeight }, width { pWidth } {
		//TODO: Implement constructor, creaint a setview with one texture and height and width measurements
	}
	static int getDefaultHeight();
	static int getDefaultWidth();
	static void setDefaultHeight(int pHeight);
	static void setDefaultWidth(int pWidth);
private:
	void init() {
		sf::ContextSettings settings{};
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(SetView::getDefaultWidth(), SetView::getDefaultHeight()), "SetView!",sf::Style::Default,settings);
		runSetWindowMainLoop(window);
	}

	void runSetWindowMainLoop(sf::RenderWindow & window){
		while (window.isOpen())
		{
			sf::Event event{};
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear();
			window.display();
		}
	}

	bool configureShaderIfSupported(){
		if(sf::Shader::isAvailable()){
			//some shader related settings
			return true;
		}
		return false;
	}
};

int SetView::defaultHeight{400};
int SetView::defaultWidth{800};

int SetView::getDefaultHeight(){
	return SetView::defaultHeight;
}

int SetView::getDefaultWidth(){
	return SetView::defaultWidth;
}

void SetView::setDefaultHeight(int pHeight){
	SetView::defaultHeight = pHeight;
}

void SetView::setDefaultWidth(int pWidth){
	SetView::defaultWidth = pWidth;
}

#endif /* SETVIEW_H_ */
