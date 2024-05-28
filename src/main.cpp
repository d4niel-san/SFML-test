#include "sfml-utn-inspt.h"
#include <iostream>


const unsigned int ANCHO_VENT = 800;
const unsigned int ALTO_VENT = 600;
const unsigned int FRAMERATE = 2;

void read_events(RenderWindow &window);

int main()
{
  float ratio = 75;
  int sides = 3;
  bool up = true;
  int starParameter = 20;

  RenderWindow window = RenderWindow{{ANCHO_VENT, ALTO_VENT}, "Unidad 1 - Taller de Videojuegos"};
  window.setFramerateLimit(FRAMERATE);

  CircleShape poligon, aux1, aux2, star;

  aux1 = CircleShape(starParameter*2,5);
    aux2 = CircleShape(starParameter,5);
    aux2.setFillColor(Color::Red);
    aux2.rotate(180);
    aux2.setPosition(starParameter*3,starParameter*3);
    
    for (unsigned int i = 0; i < aux1.getPointCount(); ++i) {
        sf::Vector2f point = aux1.getPoint(i);
        std::cout << "Point " << i << " pentagono exterior: (" << point.x << ", " << point.y << ")\n";
        point = aux2.getPoint(i);
        std::cout << "Point " << i << " pentagono interior: (" << point.x << ", " << point.y << ")\n";
    }

  while (window.isOpen())
  {

    (sides < 15 && up) && sides++;
    if (sides==15) up=false;
    (sides > 3 && !up) && sides--;
    if (sides==3) up=true;

    poligon = CircleShape(ratio, sides);
    poligon.setPosition({ANCHO_VENT / 2 - ratio, ALTO_VENT / 2 - ratio});

    /* aux1 = CircleShape(starParameter*2,5);
    aux2 = CircleShape(starParameter,5);
    aux2.setFillColor(Color::Red);
    aux2.rotate(180);
    aux2.setPosition(starParameter*3,starParameter*3);
    
    for (unsigned int i = 0; i < aux1.getPointCount(); ++i) {
        sf::Vector2f point = aux1.getPoint(i);
        std::cout << "Point " << i << ": (" << point.x << ", " << point.y << ")\n";
    }

    for (unsigned int i = 0; i < aux2.getPointCount(); ++i) {
        sf::Vector2f point = aux1.getPoint(i);
        std::cout << "Point " << i << ": (" << point.x << ", " << point.y << ")\n";
    } */

    read_events(window);
    window.clear();
    window.draw(poligon);
    window.draw(aux1);
    window.draw(aux2);
    window.display();
  }
}

void read_events(RenderWindow &window)
{
  Event event = Event();
  while (window.pollEvent(event))
  {
    if (event.type == Event::Closed)
    {
      window.close();
    }
  }
}
