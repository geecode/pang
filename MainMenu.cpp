#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show( sf::RenderWindow &window )
{
	// load menu image from file
	sf::Texture texture;
	texture.loadFromFile( "images/mainmenu.png" );
	sf::Sprite sprite;
	sprite.setTexture( texture );

	/*********************************
	 * setup clickable regions
	 *********************************/

	// play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	// exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.height = 235;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = Exit;

	_menuItems.push_back( playButton );
	_menuItems.push_back( exitButton );

	window.draw( sprite );
	window.display();

	return GetMenuResponse( window );
}

MainMenu::MenuResult MainMenu::HandleClick( int x, int y )
{
	std::list< MenuItem >::iterator it;

	for ( it =_menuItems.begin(); it != _menuItems.end(); ++it )
	{
		sf::Rect< int > menuItemRect  = (*it).rect;
		if ( menuItemRect.top + menuItemRect.height > y && menuItemRect.top < y
			&& menuItemRect.left < x && menuItemRect.width > x )
			return ( *it ).action;
	}
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse( sf::RenderWindow &window )
{
	sf::Event menuEvent;

	while( true )
	{
		while( window.pollEvent( menuEvent ) )
		{
			if ( menuEvent.type == sf::Event::MouseButtonPressed )
				return HandleClick( menuEvent.mouseButton.x, menuEvent.mouseButton.y );
			if ( menuEvent.type == sf::Event::Closed )
				return Exit;
		}
	}
}

