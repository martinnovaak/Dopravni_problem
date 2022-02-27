#pragma once

class DP 
{
private:
	//zadani
    int M, N;
	int** C;
	/*int* a;
	int* b;*/

	// pomocne
	int* A;
	int* u;
	int* v;
	int** Gamma;
	int** D;

    bool feasible;

	int psi;

	int** X; // reseni
	void calcObjective();
public:
    DP(int M, int N,int* c, int* a, int* b);
	~DP();
	void solve();
	int minInRow(int column);
	int indexMin(int column);
    int operator()(unsigned int, unsigned int);
    int getRows(){return M;};
    int getColumns(){return N;};
    int getRes(){return psi;};
    bool getFeasible(){return feasible;};

	void print();
};
