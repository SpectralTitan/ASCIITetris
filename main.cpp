#include <iostream>
#include <string>
#include <vector>

//std::vector<int> getRelativePositions();

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

    //board.at(3).insert(board.at(3).begin() + 4, '#');

    struct Point {
        int x;
        int y;
    };

    struct leftL {
        int positions[3][3] = {
            {0, -1, 2},
            {0, 1, 2},
            {-1, 1, 1}
        };
    };

    leftL L;

    char input;
    int flag = 0;

    Point centre;
    centre.x = 3;
    centre.y = 4;

    std::vector<Point> points;
    while (input != 'q') {
        Point currentPoint;

        for (int i = 0; i < points.size(); i++) {
            board[points[i].y][points[i].x] = '.';
        }

        board[centre.y][centre.x] = '#';
        points.push_back(centre);

        // Render piece
        for(int i = 0; i < sizeof(L.positions)/sizeof(L.positions[0]); i++) {
            currentPoint.x = centre.x + L.positions[i][0];
            currentPoint.y = centre.y + L.positions[i][1];

            points.push_back(currentPoint);

            board[currentPoint.y][currentPoint.x] = '#';
        }
       
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                std::cout << board.at(i).at(j) << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n\n\n";

        std::cin >> input;

        if (input == 'a') {
            if (board[centre.y][centre.x - L.positions[1][2]] != '|') {
                centre.x -= 1;
            }
        }

        if (input == 'd') {
            if (board[centre.y][centre.x + L.positions[2][2]] != '|') {
                centre.x += 1;
            }
        }

        // Move down
        if (board[centre.y + L.positions[0][2]][centre.x] != '_') {
            centre.y += 1;
        }
    }
    
    // std::cout << input;
    
    return 0;
}

// std::vector<int> getRelativePositions(int pos[3][3]) {

// }