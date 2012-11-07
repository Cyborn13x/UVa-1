#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INFINITY 100
#define UNPROCESSED 0
#define WAITING 1
#define PROCESSED 2

/*problem id-439
 *
 *language-ANSI C
 *
 */
typedef struct abc
{
    int Distance,State,column,row;

}vertex;

void Initialize(vertex *a)
{
    int i,j;
    for(i=0;i<8;i++)
    {
    	for(j=0;j<8;j++)
    	{
    		(a+i*8+j)->Distance=INFINITY;
    		(a+i*8+j)->State=UNPROCESSED;
    		(a+i*8+j)->row=i;
    		(a+i*8+j)->column=j;
    	}
    }
    return;
}
int IsValid(int a,int b)
{
    if((a>=0 && a<=7) && (b>=0 && b<=7)) return 1;
    return 0;
}

int main()
{
	int i,j,SourceX,SourceY,TargetX,TargetY,VertexQueueIterator,NeighbourX,NeighbourY,Front;
	vertex ChessBoard[8][8],VertexQueue[70],temp;
	char Source[3],Target[3];
    while(scanf("%s %s",Source,Target)==2)
    {
    	Initialize(ChessBoard);
        Front=0;
        VertexQueueIterator=0;
        SourceX=Source[1]-49;
        SourceY=Source[0]-97;
        TargetX=Target[1]-49;
        TargetY=Target[0]-97;
        ChessBoard[SourceX][SourceY].Distance=0;
        VertexQueue[VertexQueueIterator]=ChessBoard[SourceX][SourceY];
        VertexQueueIterator++;
        while(ChessBoard[TargetX][TargetY].State!=PROCESSED)
        {
            temp=VertexQueue[Front];
            if(IsValid(temp.row+1,temp.column+2))
            {
                if(ChessBoard[temp.row+1][temp.column+2].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row+1][temp.column+2];
                        ChessBoard[temp.row+1][temp.column+2].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row+1][temp.column+2].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row+1,temp.column-2))
            {
                if(ChessBoard[temp.row+1][temp.column-2].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row+1][temp.column-2];
                        ChessBoard[temp.row+1][temp.column-2].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row+1][temp.column-2].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row-1,temp.column+2))
            {
                if(ChessBoard[temp.row-1][temp.column+2].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row-1][temp.column+2];
                        ChessBoard[temp.row-1][temp.column+2].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row-1][temp.column+2].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row-1,temp.column-2))
            {
                if(ChessBoard[temp.row-1][temp.column-2].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row-1][temp.column-2];
                        ChessBoard[temp.row-1][temp.column-2].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row-1][temp.column-2].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row+2,temp.column+1))
            {
                if(ChessBoard[temp.row+2][temp.column+1].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row+2][temp.column+1];
                        ChessBoard[temp.row+2][temp.column+1].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row+2][temp.column+1].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row+2,temp.column-1))
            {
                if(ChessBoard[temp.row+2][temp.column-1].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row+2][temp.column-1];
                        ChessBoard[temp.row+2][temp.column-1].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row+2][temp.column-1].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row-2,temp.column+1))
            {
                if(ChessBoard[temp.row-2][temp.column+1].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row-2][temp.column+1];
                        ChessBoard[temp.row-2][temp.column+1].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row-2][temp.column+1].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            if(IsValid(temp.row-2,temp.column-1))
            {
                if(ChessBoard[temp.row-2][temp.column-1].State==UNPROCESSED)
                {
                        VertexQueue[VertexQueueIterator]=ChessBoard[temp.row-2][temp.column-1];
                        ChessBoard[temp.row-2][temp.column-1].State=WAITING;
                        VertexQueueIterator++;
                        ChessBoard[temp.row-2][temp.column-1].Distance=ChessBoard[temp.row][temp.column].Distance+1;
                }
            }
            ChessBoard[temp.row][temp.column].State=PROCESSED;
            Front++;
        }
        printf("To get from %s to %s takes %d knight moves.\n",Source,Target,ChessBoard[TargetX][TargetY].Distance);
        fflush(stdin);
    }
	return 0;
}
