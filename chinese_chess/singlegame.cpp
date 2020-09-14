#include "singlegame.h"
#include <step.h>
singleGame::singleGame()
{

}
void SingleGame::computerMove()
{
    Step *step=new Step;
    step=getBestMove();
    movestone(step->moveid,step->row,step->);
    delete step;
}
void getAllPossibleMove(QVector<Step*>& steps)
{
    int killed;
    for(int i=16;i<32;i++)
    {
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<8;col++)
            {
                killed=getStone(row,col);//判断所选择位置是否有棋子
                if(judgesame(i,killed)==1)
                continue;
                if(Board::CanMove(moveid,row,col,killed))
                    saveStep(moveid,row,col,killed,steps);
            }
        }
    }
}
int SingleGame::getStone(int row, int col)
{
    int i;
    for(i=16;i<32;i++)
    {
        if(s[i]._row==row&&s[i]._col==col)
            break;
    }
    if(i<32)
        return i;
    else
        return -1;
}
bool SingleGame::judgesame(int i, killed)
{
    if(killed==-1) return 0;
    if(s[killed].type==s[i].type) return 1;
    return 0;
}
void SingleGame::saveStep(int moveid, int row, int col, int killed,QVector<Step*>& steps)
{
    Step *step=new Step;
    step->_rowFrom=s[moveid].row;
    step->_colFrom=s[moveid].col;
    step->_rowTo=row;
    step->_colTo=col;
    step->_killid=killed
    step->_moveid=moveid;
    steps.append(step);
}
Step* SingleGame::getBestMove()
{
    QVector<Step*>& steps;
    getAllPossibleMove(steps);
    Step *step;
    Step *ret=NULL;
    int s,max;
    max=-100000;
    for(QVector<step*>::iterator it=steps.begin();it!=steps.end();it++)
    {
        step=*it;
        fakeMove(step);
        s=score();
        unfakeMove(step);
        if(score>max)
        {
            max=score;
            ret=NULL;
        }
    }
    return ret;
}
void SingleGame::fakeMove(Step *step)
{
    if(step->_killid!=-1)
        s[step->_killid]._dead=true;
    s[step->_moveid]._row=step->_rowTo;
    s[step->_moveid]._col=step->_colTo;
}
void SingleGame::unfakeMove(Step *step)
{
    s[step->_moveid]._row=step->_rowFrom;
    s[step->_moveid]._col=step->_colFrom;
    if(step->_killid!=-1)
        s[step->_killid]._dead=false;
}
int SingleGame::score()
{
    //JIANG,CHE,PAO,MA,BING,SHI,XIANG
    static int t[]={10000,1000,500,500,100,100,100};
    int i,sumblack,sumred;
    for(i=16,sumblack=0;i<32;i++)
    {
        sumblack+=t[s[i].type];
    }
    for(i=0,sumred=0;i<16;i++)
    {
        sumred+=t[s[i].type];
    }
    return sumblack-sunred;
}
void SingleGame::click(int id, int row, int col)
{

}
