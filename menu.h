#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
using namespace sf;
using namespace std;

int vibor = 0;
float pos = 0;
int vizov = 0;
int lvl = 0;
float timmm = 0;
int aktiv_mus_menu =0;
float bank;
float best_record;


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
		sprite.setPosition(c, 200);
		
		
		
		
	}
	
};


class M{
	
		public:
		String File; 
 		Music music;

	M(String F)
	{
		
		File = F;
 
 		music.openFromFile("mus/" + File+".ogg");
	}
	
	void play()
	{
		
		music.play();
	}
	void stop()
	{
			
		music.stop();
	}

};











void menu_1(RenderWindow & window)
{
	int menuNum = 0;
	int menu_vibor_2 = 0;
	bool isMenu = 1;
	// Objekt
	Textur main_menu("Main_Menu");
		Textur lvl_1("lvl");
	lvl_1.position(230, 130);
		Textur shop("shop");
	shop.position(230, 230);
		Textur option("option");
	option.position(230, 330);
		Textur exit("exit");
	exit.position(230, 430);


//////////////////////////////--------------VIBO_2-----------///////////////
	Clock tim;
	Textur back("back");
	back.position(500, 480);	
	Textur map_1("map_1");
	Textur map_2("map_2");
	Textur map_3("map_3");
	Textur map_4("map_3");
	Textur vibors("vibor");
	vibors.sprite.setPosition(35,120);
	map_1.map_position(0);
	map_2.map_position(1);
	map_3.map_position(2);
	map_4.map_position(3);
	int mov = 0.1;

	
		M main_theme("main_theme_2");
		main_theme.music.setLoop(true);
	
	
	while (isMenu)
	{	
		fstream save ("save\\save.txt");
		window.draw(main_menu.sprite);			
		Event event;
  		while (window.pollEvent(event)) 
  		{
   			if (event.type == Event::Closed)
    		window.close();
		}
		
				float timm = tim.getElapsedTime().asMilliseconds();
				tim.restart();
		
		
		
				if(aktiv_mus_menu==0)
		{
			main_theme.music.play();
			aktiv_mus_menu=1;
		}
		
		///////////////////////////////////////--------------------------Main menu----------///////////////
		if (vibor==0)
		{
		timmm = 0;
		pos =0;
		
			vibors.sprite.setPosition(35,150);
	map_1.map_position(0);
	map_2.map_position(1);
	map_3.map_position(2);
	map_4.map_position(3);
		
		if (IntRect(230, 130, 300, 100).contains(Mouse::getPosition(window))) {lvl_1.sprite.setColor(Color::Blue); menuNum = 1; }
				else{
			 lvl_1.colors();
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
				
			}
			if (menuNum == 4)  { window.close();}
 
		}
	// draw	
	window.draw(lvl_1.sprite);
	window.draw(shop.sprite);
	window.draw(option.sprite);	
	window.draw(exit.sprite);		
}
	
			///////////////////////////////////////--------------------------Menu Map----------///////////////
			if(vibor==1)
	{
				if(timmm < 4)
				{				
				timm=timm/800;			
				timmm = timmm+timm;
			}
			if (IntRect(500, 480, 300, 100).contains(Mouse::getPosition(window))) { back.sprite.setColor(Color::Blue); menu_vibor_2 = 4; }
			else{
				 back.colors();				
		}
	
				if (IntRect(pos+30, 200, 300, 200).contains(Mouse::getPosition(window))) { vibors.position(pos+30,440); window.draw(vibors.sprite); menu_vibor_2 = 1;  }
				else{
						vibors.position(pos+3000,200);

						}
						
				if (IntRect(pos+385, 200, 300, 200).contains(Mouse::getPosition(window))) { vibors.position(pos+385,440);window.draw(vibors.sprite); menu_vibor_2 = 2;   }
				else{				
						}
                if (IntRect(pos+725, 200, 300, 200).contains(Mouse::getPosition(window))) { vibors.position(pos+735,440);window.draw(vibors.sprite); menu_vibor_2 = 3;   }
				else{				
						}
				if (IntRect(pos+1065, 200, 300, 200).contains(Mouse::getPosition(window))) { vibors.position(pos+1075,440);window.draw(vibors.sprite); menu_vibor_2 = 5;   }
				else{				
						}		
	

			if (Mouse::isButtonPressed(Mouse::Left) & timmm> 0.5)
		{
			if (menu_vibor_2 == 4)  { timmm = 0 ; vibor = 0;}
			if (menu_vibor_2 == 1)  {  vibor = 3; lvl = 1; timmm = 0 ; save.close(); isMenu = false;}
			if (menu_vibor_2 == 2)  {  vibor = 3;lvl = 2; timmm = 0 ; save.close(); isMenu = false;}
			if (menu_vibor_2 == 3)  {  vibor = 3;lvl = 3; timmm = 0 ; save.close(); isMenu = false;}
			if (menu_vibor_2 == 5)  {  vibor = 3;lvl = 4; timmm = 0 ; save.close(); isMenu = false;}
		}
	
	
	
		
		if(Keyboard::isKeyPressed(Keyboard::Left) & pos > -300)
		{
			map_1.sprite.move(-4, 0);
			map_2.sprite.move(-4 , 0);
			map_3.sprite.move(-4, 0);
			pos = pos - 4;
			
		}
		
			if(Keyboard::isKeyPressed(Keyboard::Right) & pos < 150)
		{
			map_1.sprite.move(4, 0);
			map_2.sprite.move(4, 0);
			map_3.sprite.move(4, 0);
						pos = pos + 4;
		}
		
		
		
		
		
		
		
		
		
	// draw	
	window.draw(back.sprite);		
	window.draw(map_1.sprite);
	window.draw(map_2.sprite);
	window.draw(map_3.sprite);
	window.draw(map_4.sprite);
		
	}
	
	window.display();		
	}
}





