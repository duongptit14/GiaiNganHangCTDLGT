#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;
int a[100][100];
int daxet[100]={0};
int n;
int l;	// so thanh phan lien thong


void BFS(int i){
	queue <int > Q;
	Q.push(i);
	daxet[i]=1;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		for(int j=1; j<=n; j++){
			if(a[s][j] == 1 && !daxet[j]){
				Q.push(j);
				daxet[j] = 1;
			}
		}
	}
}
int soLienthong(){
	int solt=1;
	BFS(1);
	for(int i = 1; i <= n; i++){
		if(!daxet[i]){
			solt++;
			BFS(i);
		}
	}
	return solt;
}


void canhcau(){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j] == 1){
				a[i][j] = 0;
				a[j][i] = 0;
				if(soLienthong() > l){
					cout<<"("<<i<<","<<j<<")"<<"\n"; 
				}
				a[i][j] = 1;
				a[j][i] = 1;
				for(int k=1;k<=n;k++)	daxet[k] = 0;
			}
		}
	}
}

int main() {
	ifstream ifs("canhcau.txt", ios::in);
	ifs >> n;
	char tmp[100];
	ifs.getline(tmp,1);
	int i = 1;
	while(!ifs.eof()) {
		ifs.getline(tmp,100);	
		char *p = strtok(tmp, " ");
		while(p != NULL) {
			string tmp2 = (string)p;
			int num = atoi(tmp2.c_str());
			a[i][num]++;
			p = strtok(NULL, " ");
		}
		i++;
	}
	ifs.close();
	l = soLienthong();
	
	for(int i=1;i<=n;i++)	daxet[i] = 0;
	canhcau();
	
	return 0;
}
