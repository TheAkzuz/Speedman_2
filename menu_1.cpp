#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
using namespace sf;
using namespace std;

int menuNum = 0;
int vibor = 0;
float pos = 0;
int vizov = 0;


class Textur{
	public:
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	
	Textur(String name)
	{
		File = name;
		image.loadFromFile("texture/"+ File + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);	
	}
	
	void position(float x, float y)
	{
		sprite.setPosition(x, y);
		
	}
	void colors()
	{
		sprite.setColor(Color(107,189,210));
		
	}
	
	void map_position(int a)
	{
		int b = 0;
		if( a > 0)
		{
			b = 10;
		}
		int c =25 + (350*a)+b;
		sprite.setPosition(c, 120);
		
		
		
		
	}
	
};

void menu_1(RenderWindow & window)
{
	bool isMenu = 1;
	// Objekt
	Textur main_menu("Main_Menu");
		Textur lvl("lvl");
	lvl.position(230, 130);
		Textur shop("shop");
	shop.position(230, 230);
		Textur option("option");
	option.position(230, 330);
		Textur exit("exit");
	exit.position(230, 430);
	
	
	while (isMenu)
	{	
		window.draw(main_menu.sprite);			
		Event event;
  		while (window.pollEvent(event)) 
  		{
   			if (event.type == Event::Closed)
    		window.close();
		}
		
		
		
		if (IntRect(230, 130, 300, 100).contains(Mouse::getPosition(window))) {lvl.sprite.setColor(Color::Blue); menuNum = 1; }
				else{
			 lvl.colors();
		}
				if (IntRect(230, 230, 300, 100).contains(Mouse::getPosition(window))) { shop.sprite.setColor(Color::Blue); menuNum = 2; }
				else{
			 shop.colors();
		}
				if (IntRect(230, 330, 300, 100).contains(Mouse::getPosition(window))) { option.sprite.setColor(Color::Blue); menuNum = 3; }
				else{
			option.colors();
		}
				if (IntRect(230, 430, 300, 100).contains(Mouse::getPosition(window))) { exit.sprite.setColor(Color::Blue); menuNum = 4; }
				else{
			 exit.colors();
		}
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				menuNum = 0;
				vibor = 1;
				isMenu = false;
			}
			if (menuNum == 4)  { window.close(); isMenu = false; }
 
		}
	// draw	
	window.draw(lvl.sprite);
	window.draw(shop.sprite);
	window.draw(option.sprite);	
	window.draw(exit.sprite);		
	
	
	window.display();		
	}
}









void map_menu(RenderWindow & window)
{
	window.setFramerateLimit(120);

	

	int mov = 0.1;
	bool isMenu = 1;
	// Objekt
		Textur main_menu("Main_Menu");
		Textur back("back");
	back.position(500, 480);
	
	Textur test_map_1("test_map");
	Textur test_map_2("test_map");
	Textur test_map_3("test_map");
	test_map_1.map_position(0);
	test_map_2.map_position(1);
	test_map_3.map_position(2);
	
	while (isMenu)
	{				
		window.draw(main_menu.sprite);			
		Event event;
  		while (window.pollEvent(event)) 
  		{
   			if (event.type == Event::Closed)
    		window.close();
		}
			
				if (IntRect(500, 480, 300, 100).contains(Mouse::getPosition(window))) { back.sprite.setColor(Color::Blue); menuNum = 4; }
				else{
			 back.colors();
		}
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 4)  { vibor = 1; isMenu = false;}
 
		}
		
		
		if(Keyboard::isKeyPressed(Keyboard::Left) & pos > -300)
		{
			test_map_1.sprite.move(-0.8, 0);
			test_map_2.sprite.move(-0.8 , 0);
			test_map_3.sprite.move(-0.8, 0);
			pos = pos - 0.8;
			
		}
		
			if(Keyboard::isKeyPressed(Keyboard::Right) & pos < 150)
		{
			test_map_1.sprite.move(0.8, 0);
			test_map_2.sprite.move(0.8, 0);
			test_map_3.sprite.move(0.8, 0);
						pos = pos + 0.8;
		}
		
	// draw	
	window.draw(back.sprite);		
	window.draw(test_map_1.sprite);
	window.draw(test_map_2.sprite);
	window.draw(test_map_3.sprite);
	
	window.display();		
	}
}



