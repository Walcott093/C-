#include <SFML/Graphics.hpp>

class Affichage
{
public:
  Affichage();
  virtual ~Affichage();
  void run();
protected:
private:
  void processEvents();		// Process events
  void update(int);		        // Update positions of particules
  void render();		        // Draw sprites at updated positions
  void setSprite(sf::Sprite *, int dx, int dy);

  const int xdim = 600;		// X dimension of the window
  const int ydim = 500;		// Y dimension of the window
  sf::RenderWindow window;	// Main window
  sf::CircleShape rouge; //Cercle rouge
  sf::CircleShape bleue; //Cercle bleue
  sf::CircleShape vert;  //Cercle vert
  sf::CircleShape jaune; //Cercle jaune
  //  sf::Texture rougeTexture; //texture for the red circle
  //sf::Sprite rougeSprite; //sprite for the red circle
  
  int xRouge=20;                  //position x du rond rouge
  int yRouge=400;                  //position y du rond rouge
  
  int xBleue=40;                  //position x du rond bleue
  int yBleue=400;                  //position y du rond bleue
  
  int xVert=60;                  //position x du rond vert
  int yVert=400;                  //position y du rond vert
  
  int xJaune=80;                  //position x du rond jaune
  int yJaune=400;                  //position y du rond jaune

};


#include <iostream>
using namespace std;

const float TAILLE = 10.f; //taille des ronds

Affichage::Affichage()
  : window(sf::VideoMode(xdim, ydim), "Affichage experiment") {
}

// Destructor
Affichage::~Affichage() {
}

// Run the main loop of the experiment
void Affichage::run() {
  while (window.isOpen()) {
    //sf::sleep(sf::milliseconds(10)); // Wait 1/100 second
    srand(time(nullptr));
    processEvents();
    render();
    int r = rand() %4 +1;
    cout << "r : " << r << endl;
    update(r); //prend en arg le pion a deplacer et surement de combien de case aussi
  }
}

// Process all pending events
void Affichage::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();
  }
}

// Update data
void Affichage::update(int pion) {
  cout << "entrez une direction (g,d)" << endl;
  string rep;
  cin >> rep;
  switch(pion){
  case 1:
    if (rep=="g") {
      cout << "gauche" << endl;
      xRouge-=43; // ici cest 43 mais on pdoit adapter a la taille des cases
    }
    if (rep=="d") {
      cout << "droite" << endl;
      xRouge+=43;
    }
    break;
  case 2:
    if (rep=="g") {
      cout << "gauche" << endl;
      xBleue-=43;
    }
    if (rep=="d") {
      cout << "droite" << endl;
      xBleue+=43;
    }
    break;
  case 3:
      if (rep=="g") {
	cout << "gauche" << endl;
	xVert-=43;
      }
      if (rep=="d") {
	cout << "droite" << endl;
	xVert+=43;
      }
    
    break;
  case 4:
    
      if (rep=="g") {
	cout << "gauche" << endl;
	xJaune-=43;
      }
      if (rep=="d") {
	cout << "droite" << endl;
	xJaune+=43;
      }
      break;
  }
  
}
/*
void Affichage::setSprite(sf::Sprite *sprite, int dx,int dy){
  // Dimensions of the sprite
  sf::FloatRect rect = sprite->getGlobalBounds();
  // Position of upper-left corner of the sprite
  float xpos = (xdim - rect.width)  - dx;
  float ypos = (ydim - rect.height) - dy;
  // Set position of the sprite
  sprite->setPosition(xpos, ypos);
  // Draw the sprite at the given position
  window.draw(*sprite);
}
*/
// Update view
void Affichage::render() {
  // Background color
  window.clear(sf::Color::White);
  
  rouge = sf::CircleShape(TAILLE);
  bleue = sf::CircleShape(TAILLE);
  vert = sf::CircleShape(TAILLE);
  jaune = sf::CircleShape(TAILLE);

  rouge.setFillColor(sf::Color::Red);
  rouge.setPosition(xRouge,yRouge);
  window.draw(rouge);
  
  bleue.setFillColor(sf::Color::Blue);
  bleue.setPosition(xBleue,yBleue);
  window.draw(bleue);
  
  vert.setFillColor(sf::Color::Green);
  vert.setPosition(xVert,yVert);
  window.draw(vert);
  
  jaune.setFillColor(sf::Color::Yellow);
  jaune.setPosition(xJaune,yJaune);
  window.draw(jaune);
  
  // Make update visible
  window.display();
}

int main() {
  Affichage aff;
  aff.run();
}
