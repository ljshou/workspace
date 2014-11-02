// orienteering.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<time.h>
using namespace std;
#define MAXNUM 0x3fffffff
#define MAXLINE 100
#define MAXAT 20
static int  dx[4] = {-1,1,0,0};
static int dy[4] = {0,0,-1,1};
int state[18][1<<18];   //save all state at each @, the first Dimension => each @, the second Dimension =>each state(records which @ already being visited)
class Orienteering {
	int sx,sy,gx,gy;  //start position(sx,sy) and  goal position(gx,gy)
	int height,width;   // height and width in map
	int Dist[20][20];   // distance between each point in map, only keep points which is '@' or 'S' or 'G'
	int total;
	char map[MAXLINE][MAXLINE];  
	vector<pair<int,int> > vecmap; 
	/*!
	*   \fn int Getdist(int x1,int y1,int x2,int y2)
	*   \brief  return shortest distance between (x1,y1) and (x2,y2)
	*   \param  [in] int x1 
	*   \param  [in] int y1
	*   \param  [in] int x2
	*   \param  [in] int y2
	*   \return int distance
	*/
	int Getdist(int x1,int y1,int x2,int y2);  
	/*!
	*   \fn int DpSearch()
	*   \brief  Calculate the minimum distance from the start to the goal with passing all checkpoints,
	*   \return int the minimum distance
	*/
	int DpSearch();
public:
	void main();
	void test();
};
int Orienteering::Getdist(int x1,int y1,int x2,int y2){
	if(x1 == x2 && y1 == y2)
		return 0;
	queue<pair<int,int> > Q;
	Q.push(make_pair(x1,y1));
	bool visit[MAXLINE][MAXLINE];
	memset(visit,0,sizeof(visit));
	int temp[MAXLINE][MAXLINE];
	memset(temp,0,sizeof(temp));
	while(!Q.empty()){
		pair<int,int> curr = Q.front();Q.pop();
		for(int i = 0 ; i < 4; ++i){
			int xx = curr.first + dx[i];
			int yy = curr.second + dy[i];
			if(xx<0 || xx>=height||yy<0||yy>=width||map[xx][yy] == '#'||visit[xx][yy])
				continue;
			temp[xx][yy] = temp[curr.first][curr.second]+1;
			if(xx == x2 && yy == y2)
				return temp[xx][yy];
			visit[xx][yy] = true;
			Q.push(make_pair(xx,yy));
		}
	}
	return MAXNUM;
}

int Orienteering::DpSearch(){
	int numat = vecmap.size()-2;  // num of @ + S + G
	if(numat == 0)
		return Dist[0][1];
	total = (1<<numat) -1;
	for(int i = 0; i < numat; ++i)  //initialize each @ node , the minimum distance of each @ point is the minimum distance from S to current @ point
		state[i][1<<i] = Dist[0][i+1];

	for(int pstate = 1; pstate < total; ++pstate){
		for(int i = 0 ; i < numat; ++i){
			if((pstate & (1<<i))){
				for( int j =  0 ; j < numat; ++j){
					if(i == j || pstate & (1 << j))
						continue;
					if(state[i][pstate]+Dist[i+1][j+1] < state[j][pstate|(1<<j)])
						state[j][pstate|(1<<j)] = state[i][pstate] + Dist[i+1][j+1];
				}
			}
		}
	}
	int res = MAXNUM;
	for(int j = 0 ; j <numat; ++j){
		res = std::min(res,state[j][total] + Dist[j+1][vecmap.size()-1]);
	}
	return res;
}
void Orienteering::main(){
	//TODO:Implement this function
    scanf("%d %d\n", &width, &height);
    //cin >> width >> height;
	memset(map,0,sizeof(map));
	vecmap.clear();
	sx=sy=gx=gy=-1;
	total = 0;
	vecmap.push_back(make_pair(0,0));
	for(int r = 0 ; r < height;++r){
		getchar();
		for(int c = 0 ; c < width; ++c){
			map[r][c] = getchar();
            //cin >> map[r][c];
			if(map[r][c] == 'S'){
				sx = r;sy = c;
			}else if(map[r][c] == 'G'){
				gx = r;gy = c;
			}else if(map[r][c] == '@'){
				vecmap.push_back(make_pair(r,c));
			}else if(map[r][c] !='#' && map[r][c]!='.'){
				cout<<-1<<endl;
				return;
			}
		}
	}
	vecmap[0] = make_pair(sx,sy);
	vecmap.push_back(make_pair(gx,gy));
	memset(state,0x3f,sizeof(state));
	if(vecmap.size() > 20 || width >100 || height >100
		||sx<0||sx>height||sy<0||sy>width||gx<0||gx>height||gy<0||gy>width){
			cout<<-1<<endl;
			return;
	}
	memset(Dist,0x3f,sizeof(Dist));
	for(size_t  i = 0 ; i < vecmap.size(); ++i){
		for(size_t j = i ; j < vecmap.size(); ++j){
			Dist[i][j] = Getdist(vecmap[i].first,vecmap[i].second,vecmap[j].first,vecmap[j].second);
			Dist[j][i] = Dist[i][j];
			if(Dist[i][j] == MAXNUM){
				cout<<-1<<endl;
				return;
			}
		}
	}
	cout<<DpSearch()<<endl;
}
void Orienteering::test(){
	FILE* myfile = fopen("ex1_examples.txt","r");
	if(NULL == myfile) {
        cout << "file not open" << endl;
		return ;
    }
again:
	while(myfile){
		fscanf(myfile,"%d%d",&width,&height);
		memset(map,0,sizeof(map));
		vecmap.clear();
		sx=sy=gx=gy=-1;
		vecmap.push_back(make_pair(0,0));
		for(int r = 0 ; r < height;++r){
			fgetc(myfile);
			for(int c = 0 ; c < width; ++c){
				map[r][c] = fgetc(myfile);
				if(map[r][c] == 'S'){
					sx = r;sy = c;
				}else if(map[r][c] == 'G'){
					gx = r;gy = c;
				}else if(map[r][c] == '@'){
					vecmap.push_back(make_pair(r,c));
				}else if(map[r][c] !='#' && map[r][c]!='.')
					return;
			}
		}
		vecmap[0] = make_pair(sx,sy);
		vecmap.push_back(make_pair(gx,gy));
		memset(state,0x3f,sizeof(state));
		if(vecmap.size() > 20 || width >100 || height >100
			||sx<0||sx>height||sy<0||sy>width||gx<0||gx>height||gy<0||gy>width){
				cout<<"-1"<<endl;
				continue;
		}
		memset(Dist,0x3f,sizeof(Dist));
		for(size_t  i = 0 ; i < vecmap.size(); ++i){
			for(size_t j = i ; j < vecmap.size(); ++j){
				Dist[i][j] = Getdist(vecmap[i].first,vecmap[i].second,vecmap[j].first,vecmap[j].second);
				Dist[j][i] = Dist[i][j];
				if(Dist[i][j] == MAXNUM){
					cout<<-1<<endl;
					goto again;
				}
			}
		}
		int oneresult = DpSearch();
		cout<<oneresult<<endl;
	}	
	fclose(myfile);
}
int main(int argc, char* argv[])
{
	Orienteering o;

    clock_t start = clock();
    
    o.test();

    clock_t end = clock();
    std::cout << static_cast<double>(end - start)/CLOCKS_PER_SEC << std::endl;
	return 0;
}

