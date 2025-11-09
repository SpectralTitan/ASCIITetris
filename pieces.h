#ifndef PIECES_H
#define PIECES_H

#include <map>
#include <vector>

// Base struct for all pieces to share 
struct PieceBase {
    int currentRotationPointer;

    std::map<int, std::vector<std::vector<int>>> relativePositions;
    std::vector<std::vector<int>> activePosition;

    PieceBase() {
        currentRotationPointer = 0;
    }

    void updateActivePosition() { // Cycle rotation when method is called
        currentRotationPointer += 1;
        currentRotationPointer %= relativePositions.size();
        
        activePosition = relativePositions[currentRotationPointer];
    }
};

struct L_LeftPiece : public PieceBase {

    L_LeftPiece() {
        relativePositions = {
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

        activePosition = relativePositions[currentRotationPointer];
    }
};

struct L_RightPiece : public PieceBase {

    L_RightPiece() {
        relativePositions = {
            {
                0,  {
                        {0, -1, 2},
                        {0, 1, -1},
                        {1, 1, 2}
                    }
            },
            {
                1, {
                        {-1, 0, 2},
                        {1, 0, -2},
                        {-1, 1, 2}
                    }
            },
            {
                2, {
                        {0, -1, 2},
                        {-1, -1, -2},
                        {0, 1, 1}
                    }
            },
            {
                3, {
                        {-1, 0, 1},
                        {1, 0, -2},
                        {1, -1, 2}
                    }
            }
        };

        activePosition = relativePositions[currentRotationPointer];
    }
};

struct Z_LeftPiece : public PieceBase {

    Z_LeftPiece() {
        relativePositions = {
            {
                0,  {
                        {-1, 0, 2},
                        {0, 1, -2},
                        {1, 1, 2}
                    }
            },
            {
                1, {
                        {0, -1, 2},
                        {-1, 0, 1},
                        {-1, 1, 2}
                    }
            }
        };

        activePosition = relativePositions[currentRotationPointer];
    }
};

struct Z_RightPiece : public PieceBase {

    Z_RightPiece() {
        relativePositions = {
            {
                0,  {
                        {-1, 1, 2},
                        {0, 1, -2},
                        {1, 0, 2}
                    }
            },
            {
                1, {
                        {0, -1, 2},
                        {1, 0, -1},
                        {1, 1, 2}
                    }
            }
        };

        activePosition = relativePositions[currentRotationPointer];
    }
};

struct T_Piece : public PieceBase {

    T_Piece() {
        relativePositions = {
            {
                0,  {
                        {-1, 0, 2},
                        {0, 1, -2},
                        {1, 0, 2}
                    }
            },
            {
                1, {
                        {-1, 0, 2},
                        {0, -1, -2},
                        {0, 1, 1}
                    }
            },
            {
                2, {
                        {-1, 0, 1},
                        {0, -1, -2},
                        {1, 0, 2}
                    }
            },
            {
                3, {
                        {0, -1, 2},
                        {1, 0, -1},
                        {0, 1, 2}
                    }
            }
        };

        activePosition = relativePositions[currentRotationPointer];
    }
};

struct Sq_Piece : public PieceBase {

    Sq_Piece() {
        relativePositions = {
            {
                0,  {
                        {-1, -1, 1},
                        {-1, 0, -2},
                        {0, -1, 1}
                    }
            }
        };

        activePosition = relativePositions[currentRotationPointer];
    }
};

struct Line_Piece : public PieceBase {

    Line_Piece() {
        relativePositions = {
            {
                0,  {
                        {-1, 0, 1},
                        {1, 0, -2},
                        {2, 0, 3}
                    }
            },
            {
                1,  {
                        {0, -1, 3},
                        {0, 1, -1},
                        {0, 2, 1}
                    }
            }
        };

        activePosition = relativePositions[currentRotationPointer];
    }
};

#endif