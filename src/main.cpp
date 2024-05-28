#include "sfml-utn-inspt.h"

const unsigned int ANCHO_VENT = 800;
const unsigned int ALTO_VENT = 600;
const unsigned int FRAMERATE = 60;

void read_events(RenderWindow &window);

int main() {
  float ratio = 15;
  int sides = 3;

  RenderWindow window = RenderWindow{{ANCHO_VENT, ALTO_VENT}, "Unidad 1 - Taller de Videojuegos"};
  window.setFramerateLimit(FRAMERATE);

  CircleShape poligon = CircleShape(ratio, sides);
  poligon.setPosition({ANCHO_VENT/2-ratio, ALTO_VENT/2-ratio});

  while (window.isOpen()) {
    read_events(window);
    window.clear();
    window.draw(poligon);
    window.display();
  }
}

void read_events(RenderWindow &window) {
  Event event = Event();
  while (window.pollEvent(event)) {
    if (event.type == Event::Closed) {
      window.close();
    }

  }
}


