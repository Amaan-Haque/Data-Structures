	#include<iostream>
	
	using namespace std;

	bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int m,int n){

		//Base Case
		if(i==m && j==n){
			soln[m][n]=1;

			//Print the path
			for(int k=0;k<=m;k++){
				for(int l=0;l<=n;l++){
					cout<<soln[k][l]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;

			return true;
		}
		//Rat should be inside the grid
		if(i>m || j>n){
			return false;
		}

		//Cell should not be blocked
		if(maze[i][j]=='X'){
			return false;
		}

		//Assume solution exists through current cell
		soln[i][j]=1;

		//Recursive Case
		bool right=ratInMaze(maze,soln,i,j+1,m,n);
		bool down=ratInMaze(maze,soln,i+1,j,m,n);

		//Backtracking
		soln[i][j]=0;

		if(right || down){
			return true;
		}
		return false;


	}

	int main(){
		char maze[10][10]={"0000",
						   "00X0",
						   "000X",
						   "0X00"

		};

		int soln[10][10]={0};
		int m=4,n=4;

		bool ans=ratInMaze(maze,soln,0,0,m-1,n-1);

		if(ans==false){
			cout<<"Path does not exist";
		}
	}