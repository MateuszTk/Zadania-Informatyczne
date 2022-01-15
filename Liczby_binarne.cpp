#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


//Windows - 0
//Linux - 1
#define eol 0

int main(){
	ifstream input("./Dane_PR2/liczby.txt");
	string line;
	
	int p1 = 0, p22 = 0, p28 = 0;
	int minline = 1;
	int maxline = 1;
	string minv = "", maxv = "";
	int nline = 0;
	
	while(getline(input, line, '\n')){
		////////////p1/////////////////////////
		int ones = 0, zeros = 0;
		
		//for(int i = 0; i < line.length() - eol; i++){
			//if(line[i] == '0') zeros++;
			//if(line[i] == '1') ones++;		
		//}
		
		zeros = count(line.begin(), line.end(), '0');
		ones = count(line.begin(), line.end(), '1');
		
		if (zeros > ones) p1++;
		
		///////////ex2//////////////////////////		
		if(line[line.length() - 1 - eol] == '0'){
			p22++;
			if(line[line.length() - 2 - eol] == '0' && line[line.length() - 3 - eol] == '0')
				p28++;
		}
		
		//////////ex3///////////////////////////
		nline++;
		if(nline == 1) minv = line;
		
		if(minv.length() >= line.length()){
			if(minv.length() > line.length()){
				minline = nline;
				minv = line;
			}
			else{
				for(int i = 0; i < line.length() - eol; i++){
					if(line[i] < minv[i]){
						minline = nline;
						minv = line;
					}
					if(line[i] > minv[i]) break;
				}
			}
		}
		if(maxv.length() <= line.length()){
			if(maxv.length() < line.length()){
				maxline = nline;
				maxv = line;
			}
			else{
				for(int i = 0; i < line.length() - eol; i++){
					if(line[i] > maxv[i]){
						maxline = nline;
						maxv = line;
					}
					if(line[i] < maxv[i]) break;
				}
			}
		}
		
	}
	input.close();
	cout << "P1: " << p1 << '\n';
	cout << "P22: " << p22 << " P28: " << p28 << '\n';
	cout << "min: " << minline << " max: " << maxline << '\n';
	return 0;
}

