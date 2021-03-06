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
        void update();		        // Update positions of particules
        void render();		        // Draw sprites at updated positions
        void setSprite(sf::Sprite *, int dx, int dy);

        const int xdim = 600;		// X dimension of the window
        const int ydim = 500;		// Y dimension of the window
        sf::RenderWindow window;	// Main window
        sf::Texture backgroundTexture; 	// Texture for the background
        sf::Sprite backgroundSprite;		// background sprite
        sf::Texture pionTexture;	// Texture for the Pion
        sf::Sprite pionSprite;	    // Pion sprite
        int xPion=100;                // position x du pion
        int yPion=90;                // position y du pion
};


#include <iostream>
using namespace std;

Affichage::Affichage()
  : window(sf::VideoMode(xdim, ydim), "Affichage experiment") {

  // Load images in textures and create sprite
  // background sprite
  if (!backgroundTexture.loadFromFile("Images/hex.gif")) {
    cerr << "Error loading Images/hex.gif" << endl;
    exit(0);
  }
  backgroundSprite.setTexture(backgroundTexture);
  // Pion sprite
  if (!pionTexture.loadFromFile("Images/blue.gif")) {
    cerr << "Error loading Images/blue.gif" << endl;
    exit(0);
  }
  pionSprite.setTexture(pionTexture);
}

// Destructor
Affichage::~Affichage() {
}

// Run the main loop of the experiment
void Affichage::run() {
  while (window.isOpen()) {
    //sf::sleep(sf::milliseconds(10)); // Wait 1/100 second
    processEvents();
    render();
    update();
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
void Affichage::update() {
    cout << "entrez une direction (g,d)" << endl;
    string rep;
    cin >> rep;
    if (rep=="g") {
            cout << "gauche" << endl;
            xPion+=43;
    }
    if (rep=="d") {
            cout << "droite" << endl;
            xPion-=43;
    }

}

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

// Update view
void Affichage::render() {
  // Background color
  window.clear(sf::Color::White);
    setSprite(&backgroundSprite,0,0);
    setSprite(&pionSprite,xPion,yPion);
  // Make update visible
  window.display();
}

int main() {
    Affichage aff;
    aff.run();
}
