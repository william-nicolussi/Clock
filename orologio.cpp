#include <stdio.h>
#include <math.h>
#include "DataOra.h"
#include <SFML/Graphics.hpp>

#define PI 3.14159265
#define NOME_APP "Orologio"
#define WIDTH 500
#define TEXTURE_SFONDO "sfondo.jpg"
#define COLORE_INTERNO 230,230,230
#define COLORE_PERNO 0,0,0
#define COLORE_LINEA_SECONDI 180,180,220
#define COLORE_LINEA_MINUTI 255,10,10
#define COLORE_LINEA_ORE 150,150,150
#define COLORE_TACCA 0,0,0

using namespace sf;

int main()
{	
	//---Variabili---
	int angolo;
	DataOra dt;
	//---Oggetti sullo schermo---
    RenderWindow window(VideoMode(WIDTH, WIDTH), NOME_APP);
    Texture textureSfondo;
    textureSfondo.loadFromFile(TEXTURE_SFONDO);
    RectangleShape sfondo(Vector2f(WIDTH,WIDTH));
    CircleShape interno(220/500.0*WIDTH);
    CircleShape perno(10/500.0*WIDTH);
    RectangleShape lineaSecondi(Vector2f(200/500.0*WIDTH, 5/500.0*WIDTH));
    RectangleShape lineaMinuti(Vector2f(180/500.0*WIDTH, 5/500.0*WIDTH));
    RectangleShape lineaOre(Vector2f(150/500.0*WIDTH,10/500.0*WIDTH));
    RectangleShape tacca(Vector2f(50/500.0*WIDTH,5/500.0*WIDTH));
    //---Posizioni iniziali---
    sfondo.setPosition(0,0);
    interno.setPosition(30/500.0*WIDTH, 30/500.0*WIDTH);
    perno.setPosition(240/500.0*WIDTH, 240/500.0*WIDTH);
    lineaSecondi.setPosition(250/500.0*WIDTH, 250/500.0*WIDTH);
    lineaMinuti.setPosition(250/500.0*WIDTH, 250/500.0*WIDTH);
    lineaOre.setPosition(250/500.0*WIDTH,250/500.0*WIDTH);
    //---Inizializzazioni degli oggetti---
    sfondo.setTexture(&textureSfondo);
    interno.setFillColor(Color(COLORE_INTERNO));
    perno.setFillColor(Color(COLORE_PERNO));
    lineaSecondi.setFillColor(Color(COLORE_LINEA_SECONDI));
    lineaMinuti.setFillColor(Color(COLORE_LINEA_MINUTI));
    lineaOre.setFillColor(Color(COLORE_LINEA_ORE));
    tacca.setFillColor(Color(COLORE_TACCA));

    while (window.isOpen())
    {
    	//---Questo serve sennò crasha appena tocchi la finestra---
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
		//---Ruota le lancette a seconda del tempo letto---
		lineaSecondi.setRotation(dt.getSecond()*360/60.0-90);
		lineaMinuti.setRotation(dt.getMinute()*360/60.0-90);
		lineaOre.setRotation(dt.getHour()*360/60.0-90);
		//---Disegna l'orologio e le lancette---
        window.clear();
        window.draw(sfondo);
        window.draw(interno);
        window.draw(lineaSecondi);
        window.draw(lineaMinuti);
        window.draw(lineaOre);
        window.draw(perno);
        //---disegna le tacche---
        for(angolo=0; angolo<360; angolo+=6)
        {
        	if (angolo%15==0)
        	{
        		tacca.setSize(Vector2f(50/500.0*WIDTH,5/500.0*WIDTH));
			}
			else
			{
				tacca.setSize(Vector2f(25/500.0*WIDTH,2/500.0*WIDTH));
			}
        	tacca.setPosition((250+220*cos((angolo)*PI/180))/500.0*WIDTH, (250+220*sin((angolo)*PI/180))/500.0*WIDTH);
			tacca.setRotation(angolo);
			window.draw(tacca);
		}
        //---Visualizza sulla finestra---
        window.display();
    }
    return 0;
}
