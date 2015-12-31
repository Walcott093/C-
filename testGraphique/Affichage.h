#ifndef AFFICHAGE_H
#define AFFICHAGE_H

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

#endif // AFFICHAGE_H
