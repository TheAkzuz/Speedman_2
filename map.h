#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

const int HEIGHT_MAP =19;
const int WIDTH_MAP = 25;


String map_1[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"0                       0",
	"0000000000000000000000000",
	"0                      00",
	"0                     000",
	"0                    00 0",
	"0                   00  0",
	"0          00      00   0",
	"0         00      00    0",
	"0        00      00     0",
	"0       00      00      0",
	"0      00      00       0",
	"0     00      00        0",
	"0    00      00         0",
	"0   00                  0",
	"0  00                   0",
	"0 00                    0",
	"000                     0",
	"0000000000000000000000000",
};

String map_1_objekt[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"000c0000p0000m0000000h000",
	"0000000000000000000000000",
	"0bb                   000",
	"0bbbbbbbbbbbbbbbbbbbbb000",
	"0 b        bb      b 0000",
	"0 b       b   b   b 00bb0",
	"0 b    s b 00 bbbb 00bbb0",
	"0 b     b 00 bbbb 00 bb 0",
	"0 b    b 00 bbbb 00 b b 0",
	"0 b   b 00 bbbb 00 b  b 0",
	"0 b  b 00 bbbb 00 b   b 0",
	"0 b b 00 bbbb 00 b    b 0",
	"0 bb 00 bbbb 00 b     b 0",
	"0 b 00 b  b    b      b 0",
	"0 b00 b      bb       b 0",
	"0000 bbbbbbbbbbbbbbbbbbb0",
	"0000bb                bb0",
	"0000000000000000000000000",
};

void generator_tnt()
{
	int G_TnT = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(G_TnT>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_1_objekt[ElementY][ElementX] == ' ') 
		  {
			map_1_objekt[ElementY][ElementX] = 't'; 
			
			G_TnT--;
		}

		
	}
	
}



void generator_apple()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
	
		if (map_1_objekt[ElementY][ElementX] == ' ' || map_1_objekt[ElementY][ElementX] == 'b') 
		  {
			map_1_objekt[ElementY][ElementX] = 'a'; 
			apple--;

		}

		
	}
	
}


//////////////////////////////////////////////////--------------------------------MAP_2-------------------------




String map_2[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"0                       0",
	"0                       0",
	"0              0000     0",
	"0              0        0",
	"0              0        0",
	"0       00000000        0",
	"0       0ssssss0        0",
	"0       0ssssss0        0",
	"0       0ssssss0        0",
	"0       0ssssss0        0",
	"0       00000000        0",
	"0       0               0",
	"0       0               0",
	"0    0000               0",
	"0                       0",
	"0                       0",
	"0                       0",
	"0000000000000000000000000",
};

String map_2_objekt[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"0 b                   b 0",
	"0 bbbbbbbbbbbbbbbbbbbbb 0",
	"0 b            0000   b 0",
	"0 b     bbbbbbb0      b 0",
	"0 b            0 bb   b 0",
	"0 b   b 00000000 b    b 0",
	"0 b   b 0csssss0 b    b 0",
	"0 b   b 0psssss0 b    b 0",
	"0 b   b 0msssss0 b    b 0",
	"0 b   b 0hsssss0 b    b 0",
	"0 b   b 00000000 b    b 0",
	"0 b  bb 0 b           b 0",
	"0 b     0bbbbbbb      b 0",
	"0 b  0000  s          b 0",
	"0 b                   b 0",
	"0bbbbbbbbbbbbbbbbbbbbbbb0",
	"0 b                  b  0",
	"0000000000000000000000000",
};


// 15 12










void generator_tnt_map_2()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_2_objekt[ElementY][ElementX] == ' ' ) 
		  {
			map_2_objekt[ElementY][ElementX] = 't'; 
			apple--;

		}

		
	}
}



void generator_apple_map_2()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_2_objekt[ElementY][ElementX] == ' ' || map_2_objekt[ElementY][ElementX] == 'b') 
		  {
			map_2_objekt[ElementY][ElementX] = 'a'; 
			apple--;

		}

		
	}
}





//////////////////////////////////////////////////////////////////////------------MAP_3-----------//////////////////////////





String map_3[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"0b          0           0",
	"0                       0",
	"0                       0",
	"0           0           0",
	"0           0           0",
	"0       00000000        0",
	"0       0ssssss0        0",
	"0       0ssssss0        0",
	"000000000ssssss0000000000",
	"0       0ssssss0        0",
	"0       00000000        0",
	"0           0           0",
	"0           0           0",
	"0                       0",
	"0                       0",
	"0           0           0",
	"0l          0           0",
	"0000000000000000000000000",
};

String map_3_objekt[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"00w       w 0 w       w 0",
	"0wwwwwwwwwwwwwwwwwwwwww 0",
	"0 w       wwwww       w 0",
	"0 w     www 0 ww      w 0",
	"0 w       w 0 w       w 0",
	"0 w   w 00000000 w    w 0",
	"0 wwwww 0csssss0 wwwwww 0",
	"0 w   w 0psssss0 w    w 0",
	"000000000msssss0000000000",
	"0 w   w 0hsssss0 w    w 0",
	"0 wwwww 00000000 wwwwww 0",
	"0 w       w 0 w       w 0",
	"0 w       w 0 w       w 0",
	"0 w       swwww       w 0",
	"0 w       wwwww       w 0",
	"0wwwwwwwwww 0 wwwwwwwww 0",
	"00w         0         w 0",
	"0000000000000000000000000",
};

void generator_tnt_map_3()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_3_objekt[ElementY][ElementX] == ' ' ) 
		  {
			map_3_objekt[ElementY][ElementX] = 't'; 
			apple--;

		}

		
	}
}



void generator_apple_map_3()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_3_objekt[ElementY][ElementX] == ' ' || map_3_objekt[ElementY][ElementX] == 'w') 
		  {
			map_3_objekt[ElementY][ElementX] = 'a'; 
			apple--;

		}

		
	}
}


/////////////////////////////////////////////////////////////////////////////--------------------------------------MAP-4---------------------////////////////////////////




String map_4[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"0                       0",
	"0000000000000000000000000",
	"0                       0",
	"0                       0",
	"0                       0",
	"0                       0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0                       0",
	"0                       0",
	"0                       0",
	"0                       0",
	"0000000000000000000000000",
};

String map_4_objekt[HEIGHT_MAP] = {

    "0000000000000000000000000",
	"000c0000p0000m0000000h000",
	"0000000000000000000000000",
	"0 w                   w 0",
	"0wwwwwwwwwwwwwwwwwwwwwww0",
	"0 w        ww         w 0",
	"0 w        ww         w 0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0zzzzzzzzzzwwzzzzzzzzzzz0",
	"0 w        ww         w 0",
	"0 w        ww         w 0",
	"0wwwwwwwwwwwwwwwwwwwwwww0",
	"0 w                   w 0",
	"0000000000000000000000000",
};



void generator_tnt_map_4()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_4_objekt[ElementY][ElementX] == ' ' ) 
		  {
			map_4_objekt[ElementY][ElementX] = 't'; 
			apple--;

		}

		
	}
}



void generator_apple_map_4()
{
	int apple = 1;
	int ElementX = 0;
	int ElementY = 0;
	srand(time(0));
		
	while(apple>0)
	{
		ElementX = 1 + rand() % (WIDTH_MAP - 1);
		ElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if (map_4_objekt[ElementY][ElementX] == ' ' || map_4_objekt[ElementY][ElementX] == 'w') 
		  {
			map_4_objekt[ElementY][ElementX] = 'a'; 
			apple--;

		}

		
	}
}
