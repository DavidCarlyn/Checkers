// component.hpp

#include <SDL2/SDL.h>
#include <iostream>

struct Color {
	Color( uint8_t r, uint8_t g, uint8_t b, uint8_t a) : 
		red( r ),
		green( g ),
		blue( b ),
		alpha( a )
	{}

	Color() : Color(0, 0, 0, 0) {}

	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

class Component {
public:
	Component() : _width( 0 ), _height( 0 ), _x_pos( 0 ), _y_pos( 0 ) {
		Color c( 0xFF, 0xFF, 0xFF, 0xFF );
		_color = c;
	}
	Component( int x, int y, int w, int h ) : _width( w ), _height( h ), _x_pos( x ), _y_pos( y ) {
		Color c( 0xFF, 0xFF, 0xFF, 0xFF );
		_color = c;
	}

	int getWidth() { return _width; }
	int getHeight() { return _height; }
	int getXPos() { return _x_pos; }
	int getYPos() { return _y_pos; }
	Color getColor() { return _color; }

	void setWidth( int w ) { _width = w; }
	void setHeight( int h ) { _height = h; }
	void setXPos( int x ) { _x_pos = x; }
	void setYPos( int y ) { _y_pos = y; }
	void setColor( Color c ) { _color = c; }
	void setColor( uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		Color c(r, g, b, a);
		_color = c;
	}

	void render( SDL_Renderer* gRenderer ) {
		//Set rendering space and render to screen
		SDL_SetRenderDrawColor( gRenderer, _color.red, _color.green, _color.blue, _color.alpha );
		SDL_Rect renderQuad = { _x_pos, _y_pos, _width, _height };
		SDL_RenderFillRect(gRenderer, &renderQuad);
	}

private:
	int _width;
	int _height;

	int _x_pos;
	int _y_pos;

	Color _color;
};