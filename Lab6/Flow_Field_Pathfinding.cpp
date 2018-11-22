//
// C00204076
// Brandon Seah-Dempsey
// Started at 10:47 16 November 2018
// Finished at
// Time Taken:
// Known bugs:

#include "Flow_Field_Pathfinding .h"

//
FlowField::FlowField()
{
	
	
}

//
FlowField::~FlowField()
{

}

//
void FlowField::update(sf::Time deltaTime)
{

}

//
void FlowField::render(sf::RenderWindow& window)
{

	
}

/*
Tile* TileMap::getTile(int x, int y)
{
Tile *t = NULL;
for(int i = 0; i < tilemap.size(); i++)
{
	for(int j = 0; j < tilemap[i].size(); j++)
	{
		if(x > tilemap[i][j].sprite.getPosition().x
		&& x < (tilemap[i][j].sprite.getPosition().x+32))
		{
			if(y > tilemap[i][j].sprite.getPosition().y
			&& y < (tilemap[i][j].sprite.getPosition().y+32))
			{
				t = &tilemap[i][j];
				break;
			}
		}
	}
}

return t;
}
*/

/*
#include "Map.h"

Map::Map()
{
// Initialize the textures that are going to be used
// UPDATE THIS IF-STATEMENT WHEN A NEW TEXTURE IS ADDED
if (
!tFloor.loadFromFile("Assets/Map/floor.png") ||
!tWoodenBox.loadFromFile("Assets/Map/wood.png") ||
!tStoneWall.loadFromFile("Assets/Map/stone.png") ||
!tPinkPath.loadFromFile("Assets/Map/pink_path.png")
)
{
std::cout << "ERROR => could not load the tile textures!" << std::endl;
}
}

void Map::update(sf::RenderWindow &window)
{
/*
The codes with their corresponding texture names
- 0     =>      floor
- 1     =>      stone wall
- 2     =>      wooden box
- 3     =>      pink path


const int rowAmount = 20;
const int columnAmount = 20;

const int map[rowAmount][columnAmount] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // row 1
{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, // row 2
{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, // row 3
{ 1, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 1 }, // row 4
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 5
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 6
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 7
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 8
{ 1, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 1 }, // row 9
{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, // row 10
{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, // row 11
{ 1, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 1 }, // row 12
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 13
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 14
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 15
{ 1, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 2, 3, 3, 1 }, // row 16
{ 1, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 1 }, // row 17
{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, // row 18
{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, // row 19
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // row 20
};

// Loop through the rows
for (int row = 0; row < rowAmount; row++)
{
	// Loop through the columns
	for (int column = 0; column < columnAmount; column++)
	{
		// Temporary place to store the current texture and sprite
		sf::Texture textureToApply;
		sf::Sprite spriteHolder;

		// Apply the corresponding texture
		// To add a new tile, add a new "else if()"-statement
		if (map[row][column] == 0)
		{
			textureToApply = tFloor;
		}
		else if (map[row][column] == 1)
		{
			textureToApply = tStoneWall;
		}
		else if (map[row][column] == 2)
		{
			textureToApply = tWoodenBox;
		}
		else if (map[row][column] == 3)
		{
			textureToApply = tPinkPath;
		}

		// Appy the texture to the sprite placeholder
		spriteHolder.setTexture(textureToApply);

		// Set the correct position
		// The columns represent the X, the rows the Y
		spriteHolder.setPosition(column * tileWidth, row * tileHeight);

		// Draw the sprite to the screen before looping again
		window.draw(spriteHolder);
	}
}
}

*/

