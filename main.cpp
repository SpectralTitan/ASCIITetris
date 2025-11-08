#include <iostream>
#include <string>
#include <vector>
#include <map>

// Bottom, Left, Right. - Collision in position data.


// Store rotational position of the left 'L' block and allow cycling through those rotations
struct leftL {
    int currentRotationPointer = 0;
    int lockRotationRow = 9;

    // Store relative coordinates from a global 'centre' point to define the L shape.
    std::map<int, std::vector<std::vector<int>>> relativePositions = { // All we need is a centre point and we can construct the shape from this data.
        {
            0,  {
                    {0, -1, 2},
                    {0, 1, -2},
                    {-1, 1, 1}
                }
        },
        {
            1, {
                    {-1, -1, 1},
                    {-1, 0, -2},
                    {1, 0, 2}
                }
        },
        {
            2, {
                    {0, -1, 2},
                    {1, -1, -1},
                    {0, 1, 2}
                }
        },
        {
            3, {
                    {-1, 0, 2},
                    {1, 0, -2},
                    {1, 1, 2}
                }
        }
    };

    std::vector<std::vector<int>> activePosition = relativePositions[currentRotationPointer]; // Keep track of currently active position (rotation)

    void updateActivePosition() { // Cycle rotation when method is called
        currentRotationPointer += 1;
        currentRotationPointer %= relativePositions.size();
        
        activePosition = relativePositions[currentRotationPointer];
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'}
    };

    struct Point {
        int x;
        int y;
    };

    leftL L; // Initialse 'L' piece (will be random)

    char input;

    Point centre; // Temporary hardcoded centre point. (Will be random)
    centre.x = 3;
    centre.y = 4;
    
    std::vector<Point> points; // Keep track of piece points
    while (input != 'q') {
        Point currentPoint;

        // Constantly moving down so set previous position back to '.' (clears board).
        for (int i = 0; i < points.size(); i++) {
            board[points[i].y][points[i].x] = '.';
        }

        board[centre.y][centre.x] = '#';
        points.push_back(centre);

        // Render piece using the relative coordinates
        for(int i = 0; i < L.activePosition.size(); i++) {
            currentPoint.x = centre.x + L.activePosition[i][0];
            currentPoint.y = centre.y + L.activePosition[i][1];

            points.push_back(currentPoint);

            board[currentPoint.y][currentPoint.x] = '#';
        }
       
        // Render entire board /w updated piece on it
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                std::cout << board.at(i).at(j) << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n\n\n";

        // Handle input 'a', 'd', 'w' and check collisions
        std::cin >> input;

        if (input == 'a') {
            if (board[centre.y][centre.x + L.activePosition[1][2]] != '|') {
                centre.x -= 1;
            }
        }

        if (input == 'd') {
            if (board[centre.y][centre.x + L.activePosition[2][2]] != '|') {
                centre.x += 1;
            }
        }

        // Rotate when 'w' key is entered
        if (input == 'w') {
            L.updateActivePosition();
        }

        // Move down as long as we are not at the bottom
        if (board[centre.y + L.activePosition[0][2]][centre.x] != '_') {
            centre.y += 1;
        }
    }

    return 0;
}

// Current bugs:
// Rotation at the bottom of the board will crash. (Piece will move out of vector bounds)
// Can rotate at sides, which will elminate side tile hence eliminating side collision


// TODO 
// Add every other piece to the game (tedious process)
// Improve collision (no clue how to do this yet)
// Check for rotation validity (maybe move centre if new rotation point is out of bounds)
// Multithread rendering loop and input loop. This will allow input to be typed without blocking rendering.