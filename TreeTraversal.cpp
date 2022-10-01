/*
     ContestName     =   Shinchu_itachi
   " Walking on the road not taken with my own gutts.. "
*/


#include <bits/stdc++.h>
using namespace std ;

// construtcting the tree

class Tree {
  public :
	int val ;
	Tree *left ;
	Tree *right;

	Tree ( int data) {
		val = data;
		left = right = NULL;
	}
};

// basically while doing an itereative version of inorder preorder and postorder we must require ADT stack
void inorder( Tree * root) {
	// In the inorder traversal we will use stack
	// inorder is in the pattern left , root ,right , but in stack we will store it in position right root left since
	// stack is lifo hence to maintain the pattern we will do so

	stack<Tree*> st;

	Tree * head = root;

	while ( !st.empty() || head != NULL) {

		if ( head != NULL) {
			st.push( head );
			head = head ->left;
		}

		else {
			head = st.top();
			st.pop();
			cout << head -> val << " ";
			head = head -> right;
		}
	}
}

void solve() {
	// creating the tree
	Tree * root = new Tree (1);
	root -> left = new Tree(2);
	root -> left -> left = new Tree(3);
	root -> left -> right = new Tree(4);
	root -> right = new Tree(5);
	root -> right -> left = new Tree(6);


	// inorder traversal of the tree
	inorder ( root );
}



inline void testcases() {
	int test = 1, testcase = 1 ;
	// cin >> test ;

	cout << setprecision(12) ;
	cerr << setprecision(8) ;
	while (test --) {
		// cout << "Case #" << testcase++ << ": ";
		solve () ;
	}
}





int main () {
	fastio();

#ifndef ONLINE_JUDGE
	// freopen("output.txt", "w", stdout);
	// freopen("input.txt", "r", stdin);
	//freopen("error.txt", "w", stderr);
#endif

	auto start = high_resolution_clock::now();

	testcases();

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);

	cerr << "Time : " << duration.count() / 1000 ;
}
