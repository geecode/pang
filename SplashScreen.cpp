#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show( sf::RenderWindow &window )
{
	sf::Texture texture;
	
	if ( texture.loadFromFile( "images/SplashScreen.png" ) != true )
		return;

	sf::Sprite sprite;
	sprite.setTexture( texture );

	window.draw( sprite );
	window.display();

	sf::Event lEvent;
	while( true )
	{
		while( window.pollEvent( lEvent ) )
		{
			if ( lEvent.type == sf::Event::EventType::KeyPressed
				|| lEvent.type == sf::Event::EventType::MouseButtonPressed
				|| lEvent.type == sf::Event::EventType::Closed )
				return;
		}
	}
}



	


