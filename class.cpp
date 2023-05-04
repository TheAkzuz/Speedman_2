#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;

class Texturs{
	public:
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	
	Texturs(String name)
	{
		File = name;
		image.loadFromFile("texture/"+File+".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);	
	}
	
};

class Mus{
	
		public:
		String File; 
 		Music music;

	Mus(String F)
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

