ifndef SINGLEGAME_H
#define SINGLEGAME_H

#include "Board.h"

class SingleGame : public Board
{
    Q_OBJECT
public:
    explicit SingleGame(QWidget *parent = 0);
    ~SingleGame();

    int _level;
    void click(int id, int row, int col);
    int getStone(int row,int col);
    bool judgesame(int i,killed);
    Step* getBestMove();
    void saveStep(int moveid ,int row,int col,int killed,QVector<Step*>& steps);
    void getAllPossibleMove(QVector<Step*>& steps);
    int score();
    void fakeMove(Step* step);
    void unfakeMove(Step* step);

signals:

public slots:
    void computerMove();
};

#endif // SINGLEGAME_H
