#include<bits/stdc++.h>
#include<cmath>
using namespace std;

print(int a[][9]){

    char aa=201, b=187, c=200, d=188, l=205, s=186;
    for(int j=0;j<9;++j){
            int n=0;
            for(int i=0;i<9;++i){
                cout<<aa<<l<<l<<l<<b;
                if(i%3==2) cout<<"  ";
            }
            cout<<endl;
            for(int i=0;i<9;++i){
                cout<<s<<" "<<a[j][n]<<" "<<s;
                ++n;
                if(i%3==2) cout<<"  ";
            }
            cout<<endl;
            for(int i=0;i<9;++i){
                cout<<c<<l<<l<<l<<d;
                if(i%3==2) cout<<"  ";
            }
            cout<<endl;
            if(j%3==2) cout<<endl;
    }
}

bool canplace(int a[][9],int i,int j,int n,int no){
	for(int x=0;x<n;++x){
		if(a[i][x]==no || a[x][j]==no) return false;
	}
	int rn=sqrt(n);
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;
	for(int x=sx;x<sx+rn;++x){
		for(int y=sy;y<sy+rn;++y){
			if(a[x][y]==no) return false;
		}
	}
	return true;
}

bool solvesudoku(int a[][9],int i,int j,int n){
	if(i==n){
	    system("CLS");
        cout<<"\t*******Sudoku solved*******"<<endl<<endl;
		print(a);
		return true;
	}

	if(j==n) return solvesudoku(a,i+1,0,n);

	if(a[i][j]!=0) return solvesudoku(a,i,j+1,n);

	for(int no=1;no<=n;++no){
		if(canplace(a,i,j,n,no)){
			a[i][j]=no;
			if(solvesudoku(a,i,j+1,n)) return true;
		}
	}

	a[i][j]=0;
	return false;
}

int main() {

	int a[9][9];
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			cin>>a[i][j];
		}
	}

	if(solvesudoku(a,0,0,9)==false)
        cout<<"Can't be solved!!"<<endl;
	return 0;
}
