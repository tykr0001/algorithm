#include<iostream>

using namespace std;

bool determine_star(int N_size, int i_vec, int j_vec, int current_i, int current_j);
void print_star(int N_size);

int main(void){
	int N;
	cin >> N;
	print_star(N);
	return 0;
}

bool determine_star(int N_size, int i_vec, int j_vec, int current_i, int current_j){
	if(N_size==1) return true;
	
	for(int i=current_i+N_size/3; i<current_i+2*N_size/3; ++i)
		for(int j=current_j+N_size/3; j<current_j+2*N_size/3; ++j)
			if(i==i_vec && j==j_vec) return false;
	
	bool recursive_truth=true;
	int i=current_i;
	int j=current_j;
	for(int i=current_i; i<current_i+N_size; i+=N_size/3)
		for(int j=current_j; j<current_j+N_size; j+=N_size/3)	
			recursive_truth = recursive_truth && determine_star(N_size/3,i_vec,j_vec,i,j);
	/*recursive_truth = recursive_truth && determine_star(N_size/3,i_vec,j_vec,i,j) && determine_star(N_size/3,i_vec,j_vec,i,j+N_size/3)
	 && determine_star(N_size/3,i_vec,j_vec,i,j+2*N_size/3) && determine_star(N_size/3,i_vec,j_vec,i+N_size/3,j) && determine_star(N_size/3,i_vec,j_vec,i+N_size/3,j+2*N_size/3)
	  && determine_star(N_size/3,i_vec,j_vec,i+2*N_size/3,j) && determine_star(N_size/3,i_vec,j_vec,i+2*N_size/3,j+N_size/3) && determine_star(N_size/3,i_vec,j_vec,i+2*N_size/3,j+2*N_size/3);
	*/
	return recursive_truth;
}

void print_star(int N_size){
	for(int i=0; i<N_size; ++i){
		for(int j=0; j<N_size; ++j){
			if(determine_star(N_size,i,j,0,0)) printf("*");
			else printf(" ");
		}
		cout << endl;
	}
}

