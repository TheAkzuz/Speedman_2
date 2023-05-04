#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
#include <string>
#include "menu.h"
#include "map.h"
#include "class.cpp"
using namespace sf;
using namespace std;

	int gen_tnt = 0;
	int gen_apple = 0;
	float bust_speed = 0;
	int heal = 3;
	float timer = 0;
	float local_record = 0;
	int teh = 0;
	int teh_2 = 0;
	int aktiv_mus_apple=0;
	int aktiv_mus_tnt=0;
	int aktiv_saund =0;
	int aktiv_mus_tp=0;
	int hero_move =0;
	int aktiv_hero = 0;
    int info = 0;
	int pause_navodka =0;
	string test="hero";
	
	
class Player{
	
	private: float x,y;
	
	public: 
	float h, w, dx, dy, speed;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	
	Player(String F, float X, float Y, float W, float H)
	{
		File = F;
		h = H; w = W;
		image.loadFromFile("texture/"+ File +".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = X;
	}
	
	void update()
	{
		switch(dir)
		{
			case 0: dx=speed; dy = 0; break;
			case 1: dx= -speed; dy = 0; break;
			case 2: dx=0; dy = speed; break;
			case 3: dx=0; dy = -speed; break;
		}
		x += dx;
		y += dy;
		sprite.setPosition(x, y);
		vzaimMap();
	}
	
	void vzaimMap()
	{
		
		////////////////----------MAP_1-------------------/////////
		
		

		
		for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32;  j < (x + w) / 32; j++)
		{
		////////////////----------MAP_1-------------------/////////			
					if (lvl ==1)
		{
			
			
			if (map_1[i][j] == '0') {
				x = 224, y = 224;
			}
			
			if(map_1_objekt[i][j] == 'a')
			{	
			   map_1_objekt[i][j] = ' ';
			   gen_apple--;
			   if(bust_speed < 4)
			   {		   
			   bust_speed = bust_speed + 0.05;
		}
				
			   bank=bank+0.1;
			   local_record = local_record + 0.5; 
			   aktiv_mus_apple=1;
			   
			}
			
			
			
				if(map_1_objekt[i][j] == 't')
			{
			   	map_1_objekt[i][j] = ' ';
				x = 224, y = 224;
				gen_tnt--;	
				heal--;
				aktiv_mus_tnt=1;
			}
			
		}
		
				////////////////----------MAP_2-------------------/////////
		
						if (lvl ==2)
		{
				
			
			if (map_2[i][j] == '0') {
				x = 384, y = 448;
			}
			
			if(map_2_objekt[i][j] == 'a')
			{	
			   map_2_objekt[i][j] = ' ';
			   gen_apple--;
			   if(bust_speed < 4)
			   {		   
			   bust_speed = bust_speed + 0.05;
		}
			   bank=bank+0.2;
			   local_record = local_record + 0.5; 
			   aktiv_mus_apple=1;
			   
			}			
				if(map_2_objekt[i][j] == 't')
			{
			   	map_2_objekt[i][j] = ' ';
				x = 384, y = 448;
				gen_tnt--;	
				heal--;
				aktiv_mus_tnt=1;
			}
				
	}		
		
		
		
				////////////////----------MAP_3-------------------/////////
		
						if (lvl ==3)
		{
				
			
			if (map_3[i][j] == '0') {
				x = 320, y = 448;
			}
			
			if(map_3_objekt[i][j] == 'a')
			{	
			   map_3_objekt[i][j] = ' ';
			   gen_apple--;
			   if(bust_speed < 4)
			   {		   
			   bust_speed = bust_speed + 0.05;
		}
			   bank=bank+0.3;
			   local_record = local_record + 0.5; 
			   aktiv_mus_apple=1;
			   
			}			
				if(map_3_objekt[i][j] == 't')
			{
			   	map_3_objekt[i][j] = ' ';
				x = 320, y = 448;
				gen_tnt--;	
				heal--;
				aktiv_mus_tnt=1;
			}
			
			
				if(map_3[i][j] == 'l')
			{
				x = 32, y = 32;
				dir =2;
				aktiv_mus_tp=1;
			}
			
			
				if(map_3_objekt[i][j] == 'l')
			{
				x = 736; y = 540;
				dir =3;
				aktiv_mus_tp=1;
			}
				
	}
	
	
	
	
	
	
	
					////////////////----------MAP_4-------------------/////////
		
						if (lvl ==4)
		{
				
			
			if (map_4[i][j] == '0') {
				x = 128, y = 500;
			}
			
			if(map_4_objekt[i][j] == 'a')
			{	
			   map_4_objekt[i][j] = ' ';
			   gen_apple--;
			   if(bust_speed < 4)
			   {		   
			   bust_speed = bust_speed + 0.05;
		}
			   bank=bank+0.3;
			   local_record = local_record + 0.5; 
			   aktiv_mus_apple=1;
			   
			}			
				if(map_4_objekt[i][j] == 't')
			{
			   	map_4_objekt[i][j] = ' ';
				x = 320, y = 448;
				gen_tnt--;	
				heal--;
				aktiv_mus_tnt=1;
			}
			
			
				if(map_4_objekt[i][j] == 'z')
			{
				x = 128, y = 500;
			//	heal--;
			}
			
			

				
	}			
		
	
	
	
	
	
	
	
	
	
		
	}










	
	
	
	
	}
	
};














void gen_vizov(int a, int b);
void map_restart();

int main(int argc, char** argv) {
	
	RenderWindow window(VideoMode(800, 600), "SpeedMan-2",Style::Close);
	window.setFramerateLimit(120);
	Image icon;
	if (!icon.loadFromFile("hero.png"))
	{
	return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	
	

//////////////////////////////////////////////////////////////////---------------menu-------------////////////////////////
	restart:
	int one = 0;
	teh =0;
	while (vibor != 3)
	{
	menu_1(window);
}
///////////////////////////////////////////////////////////////-----------------------------WWWW--------------------------
	vibor = 0;
	Player p(test, 0, 0, 32, 32);
	
	heal = 3;
	Clock clock;
	
				Texturs menu("menu");
				Texturs back("back");	
				Texturs navodka ("vibor");
		//224
		Mus saund_map_1("saund");
		Mus saund_map_2("map_2");
		Mus saund_map_3("map_3");  
	 	Mus mus_apple("apple_aktiv");
	 	Mus mus_tnt("tnt_aktiv");
	 	Mus mus_tp("teleport");
		saund_map_1.music.setLoop(true);
		saund_map_2.music.setLoop(true);
		saund_map_3.music.setLoop(true);
	 	
	/////////////////////////////////////////////////////////////////////------------------Okno
	while(window.isOpen())
	{
	fstream save ("save\\save.txt");
	if (teh == 0)
	{
		float a;
		int index = -1;
		do{
			index++;
			save>>a;
			if(index==0){best_record=a;}
			if(index==1){bank=a;}
		}while (!save.eof());	
		teh++;
	}
	float time = clock.getElapsedTime().asMilliseconds();
	clock.restart(); 
	time = time/800; 
	timer+=time;

		Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
			window.close();
	}	
		}
		
		
	
		
		////////////////////////////////////---------Keyboard
		
		
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 1; p.speed = 1 + bust_speed;
		}
					if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 0; p.speed = 1+ bust_speed;
		}
					if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p.dir = 3; p.speed = 1+ bust_speed;
		}
					if (Keyboard::isKeyPressed(Keyboard::Down)) {
			p.dir = 2; p.speed = 1+ bust_speed;
		}
	
	
			if((Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Space) )|| info == 1) 
			{
				info = 1;
				aktiv_hero = 1;

				back.sprite.setPosition(300, 100);
				menu.sprite.setPosition(300, 250);
				
				if (IntRect(300, 100, 300, 100).contains(Mouse::getPosition(window))) {pause_navodka = 1; navodka.sprite.setPosition(300, 210);}
				if (IntRect(300, 250, 300, 100).contains(Mouse::getPosition(window))) {pause_navodka = 2; navodka.sprite.setPosition(300, 360);}
				
				if (Mouse::isButtonPressed(Mouse::Left) & pause_navodka ==1){ info = 0;}
				
				if (Mouse::isButtonPressed(Mouse::Left) & pause_navodka ==2){ info = 0; heal = 0;}
			}
			else {aktiv_hero = 0;}
			
	
	////////////////////////////---------------------HEAL_OPTIAN
		if(heal > 0 & aktiv_hero == 0)
		{	
		p.update();
	}
		
			if (heal < 1 & aktiv_mus_tnt==0)
		{		
			
			if(local_record > best_record)
			{		
				best_record = local_record;		
							
			}
			save<<best_record<<endl;
			save<<bank;
			save.close();
			
			
			
			
			 gen_apple=0;
	 		 gen_tnt=0;
			  map_restart();			
			aktiv_saund =0;
			local_record = 0;
			p.speed = 0;
			bust_speed = 0;
			hero_move=0;
			aktiv_mus_menu =0;
			goto restart;
		}
			
		///////////////////////////--------------------------saund--------------	
						
			if(aktiv_mus_apple==1)
		{
			aktiv_mus_apple=0;
			mus_apple.play();
		}
		
			if(aktiv_mus_tnt==1)
		{
			aktiv_mus_tnt=0;
			mus_tnt.play();
		}
			
			
			if(aktiv_saund == 0 && lvl==1)
			{
				saund_map_1.play();
				aktiv_saund=1;
			}

			if(aktiv_saund == 0 && lvl==2)
			{
				saund_map_2.play();
				aktiv_saund=1;
			}
			
			if(aktiv_saund == 0 && lvl==3)
			{
				saund_map_3.play();
				aktiv_saund=1;
			}
						
		
			if(aktiv_mus_tp ==1)
			{
				mus_tp.play();
				aktiv_mus_tp =0;
			}
		
			window.clear();
		
		///////////////////////////////////////////////-------------------------MAP_1------///////////////////
		
		
			if(lvl == 1)
			{
			Texturs stoun("map_1_stena_1");
			Texturs tnt("tnt");
			Texturs trav("map_1_pol_1");
			Texturs apple ("apple");
			Texturs heals ("heal");
			Texturs cup ("cup");
			Texturs point("point");
			Texturs money("money");
			
			if(hero_move==0){	p.sprite.move(224,224); hero_move=1;}
			
		Font font;	
		font.loadFromFile("Comic_CAT.otf");
		ostringstream pokasatel;
		pokasatel<<heal;
		Text text("", font , 30);
		text.setColor(Color::Black);
		text.setString("x" + pokasatel.str());
		text.setPosition(704,30);
		
		
		ostringstream pokasatel_record;
		pokasatel_record<<local_record;
		Text text_record("", font , 30);
		text_record.setColor(Color::Black);
		text_record.setString("x" + pokasatel_record.str());
		text_record.setPosition(288,30);
		
		ostringstream pokasatel_record_best;
		pokasatel_record_best<<best_record;
		Text text_record_best("", font , 30);
		text_record_best.setColor(Color::Black);
		text_record_best.setString("x" + pokasatel_record_best.str());
		text_record_best.setPosition(128,30);
		
		
		
		ostringstream pokasatel_bank;
		pokasatel_bank<<bank;
		Text text_bank("", font , 30);
		text_bank.setColor(Color::Black);
		text_bank.setString("x" + pokasatel_bank.str());
		text_bank.setPosition(450,30);
		
					
		
		
		

			if (timer > 1 || one < 21)
			{	
			gen_vizov(10, 10);
			one++;
			timer = 0;
		}
		int aa = 0;
	//	cout<<timer<<endl;
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			
			//map_stil
			if (aa<1001)
			{
			if (map_1[i][j] == ' '){	trav.sprite.setPosition(j * 32, i * 32); window.draw(trav.sprite);}
			if (map_1[i][j] == '0'){	stoun.sprite.setPosition(j * 32, i * 32); window.draw(stoun.sprite);}
			
			aa++;
		}

			//info
			if (map_1_objekt[i][j] == 'c'){	cup.sprite.setPosition(j * 32, i * 32); window.draw(cup.sprite);}
			if (map_1_objekt[i][j] == 'p'){	point.sprite.setPosition(j * 32, i * 32); window.draw(point.sprite);}
			if (map_1_objekt[i][j] == 'm'){	money.sprite.setPosition(j * 32, i * 32); window.draw(money.sprite);}
			if (map_1_objekt[i][j] == 'h'){	heals.sprite.setPosition(j * 32, i * 32); window.draw(heals.sprite);}
			//objekt
			if (map_1_objekt[i][j] == 'a'){	apple.sprite.setPosition(j * 32, i * 32); window.draw(apple.sprite);}
			if (map_1_objekt[i][j] == 't'){	tnt.sprite.setPosition(j * 32, i * 32); window.draw(tnt.sprite);}
			
			}
				window.draw(text);
				window.draw(text_record);
				window.draw(text_record_best);
				window.draw(text_bank);		
	}
	
		///////////////////////////////////////////////-------------------------MAP_2------///////////////////	
	
		if(lvl==2)
			{

			Texturs stoun("map_2_stena_3");
			Texturs tnt("tnt");
			Texturs trav("map_2_pol_3");
			Texturs trav_2("map_2_trava");			
			Texturs apple ("apple");
			Texturs heals ("heal");
			Texturs cup ("cup");
			Texturs point("point");
			Texturs money("money");	
			if(hero_move==0){	p.sprite.move(384,448); hero_move=1;}
			
			
					
		Font font;	
		font.loadFromFile("Comic_CAT.otf");
		ostringstream pokasatel;
		pokasatel<<heal;
		Text text("", font , 30);
		text.setColor(Color::Black);
		text.setString("x" + pokasatel.str());
		text.setPosition(320,320);
		
		
		ostringstream pokasatel_record;
		pokasatel_record<<local_record;
		Text text_record("", font , 30);
		text_record.setColor(Color::Black);
		text_record.setString("x" + pokasatel_record.str());
		text_record.setPosition(320,256);
		
		ostringstream pokasatel_record_best;
		pokasatel_record_best<<best_record;
		Text text_record_best("", font , 30);
		text_record_best.setColor(Color::Black);
		text_record_best.setString("x" + pokasatel_record_best.str());
		text_record_best.setPosition(320,224);
		
					
		ostringstream pokasatel_bank;
		pokasatel_bank<<bank;
		Text text_bank("", font , 30);
		text_bank.setColor(Color::Black);
		text_bank.setString("x" + pokasatel_bank.str());
		text_bank.setPosition(320,288);
		
		

			if (timer > 1 || one < 21)
			{	
			gen_vizov(10, 10);
			one++;
			timer = 0;
		}
		int aa = 0;
	//	cout<<timer<<endl;
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			
			//map_stil
			if (aa<1001)
			{
			if (map_2[i][j] == ' '){	trav.sprite.setPosition(j * 32, i * 32); window.draw(trav.sprite);}
			if (map_2[i][j] == '0'){	stoun.sprite.setPosition(j * 32, i * 32); window.draw(stoun.sprite);}
			if (map_2[i][j] == 's'){	trav_2.sprite.setPosition(j * 32, i * 32); window.draw(trav_2.sprite);}		
			aa++;
		}

			//info
			if (map_2_objekt[i][j] == 'c'){	cup.sprite.setPosition(j * 32, i * 32); window.draw(cup.sprite);}
			if (map_2_objekt[i][j] == 'p'){	point.sprite.setPosition(j * 32, i * 32); window.draw(point.sprite);}
			if (map_2_objekt[i][j] == 'm'){	money.sprite.setPosition(j * 32, i * 32); window.draw(money.sprite);}
			if (map_2_objekt[i][j] == 'h'){	heals.sprite.setPosition(j * 32, i * 32); window.draw(heals.sprite);}
			//objekt
			if (map_2_objekt[i][j] == 'a'){	apple.sprite.setPosition(j * 32, i * 32); window.draw(apple.sprite);}
			if (map_2_objekt[i][j] == 't'){	tnt.sprite.setPosition(j * 32, i * 32); window.draw(tnt.sprite);}
			
			}
				window.draw(text);
				window.draw(text_record);
				window.draw(text_record_best);
				window.draw(text_bank);	
	}
	
	
	
	
	
	
	
	
	
	
	
		///////////////////////////////////////////////-------------------------MAP_3------///////////////////	
	
		if(lvl==3)
			{

			Texturs stoun("stena_3");
			Texturs tnt("tnt");
			Texturs trav("pol_3");
			Texturs trav_2("pol_3_1");			
			Texturs apple ("apple");
			Texturs heals ("heal");
			Texturs cup ("cup");
			Texturs point("point");
			Texturs money("money");
			Texturs teleport ("teleport");
			Texturs teleport_p ("teleport_p");	
			if(hero_move==0){	p.sprite.move(384,448); hero_move=1;}
			
			
					
		Font font;	
		font.loadFromFile("Comic_CAT.otf");
		ostringstream pokasatel;
		pokasatel<<heal;
		Text text("", font , 30);
		text.setColor(Color::Black);
		text.setString("x" + pokasatel.str());
		text.setPosition(320,320);
		
		
		ostringstream pokasatel_record;
		pokasatel_record<<local_record;
		Text text_record("", font , 30);
		text_record.setColor(Color::Black);
		text_record.setString("x" + pokasatel_record.str());
		text_record.setPosition(320,256);
		
		ostringstream pokasatel_record_best;
		pokasatel_record_best<<best_record;
		Text text_record_best("", font , 30);
		text_record_best.setColor(Color::Black);
		text_record_best.setString("x" + pokasatel_record_best.str());
		text_record_best.setPosition(320,224);
		
					
		ostringstream pokasatel_bank;
		pokasatel_bank<<bank;
		Text text_bank("", font , 30);
		text_bank.setColor(Color::Black);
		text_bank.setString("x" + pokasatel_bank.str());
		text_bank.setPosition(320,288);
		
		

			if (timer > 1 || one < 21)
			{	
			gen_vizov(10, 10);
			one++;
			timer = 0;
		}
		int aa = 0;
	//	cout<<timer<<endl;
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			
			//map_stil
			if (aa<1001)
			{
			if (map_3[i][j] == ' '){	trav.sprite.setPosition(j * 32, i * 32); window.draw(trav.sprite);}
			if (map_3[i][j] == '0'){	stoun.sprite.setPosition(j * 32, i * 32); window.draw(stoun.sprite);}
			if (map_3[i][j] == 's'){	trav_2.sprite.setPosition(j * 32, i * 32); window.draw(trav_2.sprite);}
			if (map_3[i][j] == 'l'){	teleport.sprite.setPosition(j * 32, i * 32); window.draw(teleport.sprite);}	
			if (map_3[i][j] == 'b'){	teleport_p.sprite.setPosition(j * 32, i * 32); window.draw(teleport_p.sprite);}			
			aa++;
		}

			//info
			if (map_3_objekt[i][j] == 'c'){	cup.sprite.setPosition(j * 32, i * 32); window.draw(cup.sprite);}
			if (map_3_objekt[i][j] == 'p'){	point.sprite.setPosition(j * 32, i * 32); window.draw(point.sprite);}
			if (map_3_objekt[i][j] == 'm'){	money.sprite.setPosition(j * 32, i * 32); window.draw(money.sprite);}
			if (map_3_objekt[i][j] == 'h'){	heals.sprite.setPosition(j * 32, i * 32); window.draw(heals.sprite);}
			//objekt
			if (map_3_objekt[i][j] == 'a'){	apple.sprite.setPosition(j * 32, i * 32); window.draw(apple.sprite);}
			if (map_3_objekt[i][j] == 't'){	tnt.sprite.setPosition(j * 32, i * 32); window.draw(tnt.sprite);}
			if (map_3_objekt[i][j] == 'l'){	teleport.sprite.setPosition(j * 32, i * 32); window.draw(teleport.sprite);}	
			if (map_3_objekt[i][j] == 'b'){	teleport_p.sprite.setPosition(j * 32, i * 32); window.draw(teleport_p.sprite);}	
			
			}
				window.draw(text);
				window.draw(text_record);
				window.draw(text_record_best);
				window.draw(text_bank);	
	}
	
		
		
		
		
		
		///////////////////////////////////////////////-------------------------MAP_4------///////////////////	
	
		if(lvl==4)
			{

			Texturs stoun("stena_3");
			Texturs tnt("tnt");
			Texturs trav("pol_3");
			Texturs trav_2("pol_3_1");			
			Texturs apple ("apple");
			Texturs heals ("heal");
			Texturs cup ("cup");
			Texturs point("point");
			Texturs money("money");
			Texturs ocean ("teleport");
			Texturs most ("teleport_p");	
			if(hero_move==0){	p.sprite.move(128,500); hero_move=1;}
			
			
					
		Font font;	
		font.loadFromFile("Comic_CAT.otf");
		ostringstream pokasatel;
		pokasatel<<heal;
		Text text("", font , 30);
		text.setColor(Color::Black);
		text.setString("x" + pokasatel.str());
		text.setPosition(704,30);
		
		
		ostringstream pokasatel_record;
		pokasatel_record<<local_record;
		Text text_record("", font , 30);
		text_record.setColor(Color::Black);
		text_record.setString("x" + pokasatel_record.str());
		text_record.setPosition(288,30);
		
		ostringstream pokasatel_record_best;
		pokasatel_record_best<<best_record;
		Text text_record_best("", font , 30);
		text_record_best.setColor(Color::Black);
		text_record_best.setString("x" + pokasatel_record_best.str());
		text_record_best.setPosition(128,30);
		
		
		
		ostringstream pokasatel_bank;
		pokasatel_bank<<bank;
		Text text_bank("", font , 30);
		text_bank.setColor(Color::Black);
		text_bank.setString("x" + pokasatel_bank.str());
		text_bank.setPosition(450,30);
		
		

			if (timer > 1 || one < 21)
			{	
			gen_vizov(10, 10);
			one++;
			timer = 0;
		}
		int aa = 0;
	//	cout<<timer<<endl;
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			
			//map_stil
			if (aa<1001)
			{
			if (map_4[i][j] == ' '){	trav.sprite.setPosition(j * 32, i * 32); window.draw(trav.sprite);}
			if (map_4[i][j] == '0'){	stoun.sprite.setPosition(j * 32, i * 32); window.draw(stoun.sprite);}
			if (map_4[i][j] == 's'){	trav_2.sprite.setPosition(j * 32, i * 32); window.draw(trav_2.sprite);}
			if (map_4[i][j] == 'z'){	ocean.sprite.setPosition(j * 32, i * 32); window.draw(ocean.sprite);}	
			if (map_4[i][j] == 'w'){	most.sprite.setPosition(j * 32, i * 32); window.draw(most.sprite);}			
			aa++;
		}

			//info
			if (map_4_objekt[i][j] == 'c'){	cup.sprite.setPosition(j * 32, i * 32); window.draw(cup.sprite);}
			if (map_4_objekt[i][j] == 'p'){	point.sprite.setPosition(j * 32, i * 32); window.draw(point.sprite);}
			if (map_4_objekt[i][j] == 'm'){	money.sprite.setPosition(j * 32, i * 32); window.draw(money.sprite);}
			if (map_4_objekt[i][j] == 'h'){	heals.sprite.setPosition(j * 32, i * 32); window.draw(heals.sprite);}
			//objekt
			if (map_4_objekt[i][j] == 'a'){	apple.sprite.setPosition(j * 32, i * 32); window.draw(apple.sprite);}
			if (map_4_objekt[i][j] == 't'){	tnt.sprite.setPosition(j * 32, i * 32); window.draw(tnt.sprite);}	
			
			}
				window.draw(text);
				window.draw(text_record);
				window.draw(text_record_best);
				window.draw(text_bank);	
	}		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		//////////////////////////////////////////////-----------------------DRAW------------------////////////////////////
		
		window.draw(p.sprite);
		
		if(info ==1)
		{
			window.draw(menu.sprite);
			window.draw(back.sprite);
			if(pause_navodka >0){ window.draw(navodka.sprite);}
	}
		
			window.display();
	}
	
	return 0;
}






















		void gen_vizov(int a, int b)
{
		
		if(lvl==1)
	{
	
		if (gen_tnt < a){generator_tnt();gen_tnt++;}
	
		if (gen_apple < b){	generator_apple();gen_apple++;}
		
		}
		
		
		if(lvl==2)
	{
	
		if (gen_tnt < a){generator_tnt_map_2(); gen_tnt++;}
	
		if (gen_apple < b){	generator_apple_map_2(); gen_apple++;}
		
		}	
			if(lvl==3)
	{
	
		if (gen_tnt < a){generator_tnt_map_3(); gen_tnt++;}
	
		if (gen_apple < b){	generator_apple_map_3(); gen_apple++;}
		
		}
		
				if(lvl==4)
	{
	
		if (gen_tnt < a){generator_tnt_map_4(); gen_tnt++;}
	
		if (gen_apple < b){	generator_apple_map_4(); gen_apple++;}
		
		}		
}






		void map_restart()
	{
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if(map_4_objekt[i][j] == 'a') {map_4_objekt[i][j] = ' ';}
			if(map_4_objekt[i][j] == 't') {map_4_objekt[i][j] = ' ';}
			if(map_3_objekt[i][j] == 'a') {map_3_objekt[i][j] = ' ';}
			if(map_3_objekt[i][j] == 't') {map_3_objekt[i][j] = ' ';}
			if(map_2_objekt[i][j] == 'a') {map_2_objekt[i][j] = ' ';}
			if(map_2_objekt[i][j] == 't') {map_2_objekt[i][j] = ' ';}
	        if(map_1_objekt[i][j] == 'a') {map_1_objekt[i][j] = ' ';}
		    if(map_1_objekt[i][j] == 't') {map_1_objekt[i][j] = ' ';}
	}
		
	}






//cout<<j * 32<<" "<<i * 32;
