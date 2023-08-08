#include <iostream>
#include <vector>

// Define a simple block class
class Block {
public:
    std::string name;
    char symbol;

    Block(std::string name, char symbol) {
        this->name = name;
        this->symbol = symbol;
    }
};

// Define a 2D grid for the game world
class World {
public:
    int width;
    int height;
    std::vector<std::vector<Block>> grid;

    World(int width, int height) {
        this->width = width;
        this->height = height;
        grid.resize(height, std::vector<Block>(width, Block("Air", ' ')));
    }

    void setBlock(int x, int y, Block block) {
        grid[y][x] = block;
    }

    void display() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                std::cout << grid[y][x].symbol;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    const int WORLD_WIDTH = 10;
    const int WORLD_HEIGHT = 10;

    World world(WORLD_WIDTH, WORLD_HEIGHT);

    // Set some blocks in the world
    world.setBlock(3, 3, Block("Grass", '#'));
    world.setBlock(5, 5, Block("Stone", '@'));

    // Display the world
    world.display();

    return 0;
}