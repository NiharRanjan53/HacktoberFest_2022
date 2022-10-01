/*
     ContestName     =   Shinchu_itachi
   " Walking on the road not taken with my own gutts.. "
*/


#include <bits/stdc++.h>
using namespace std ;

class Tree {
  public:
	int val ;
	Tree *left , *right;

	Tree( int data) {
		this-> val = data;
		left = right = NULL;
	}

	void inorderBST ( Tree* root , vector<int> & a ) {
		if ( !root ) return ;

		inorderBST( root -> left , a );
		cout << root -> val << " ";
		a.push_back(root -> val );
		inorderBST( root -> right , a );

	}

	vector<Tree*> ab;

	Tree* insert( Tree* root , int data) {
		if ( root == NULL) return new Tree(data);

		if ( data < root -> val ) root -> left = insert ( root -> left , data);
		if ( data >= root -> val ) root -> right = insert ( root -> right , data);

		return root ;
	}

	int i = 0 , j = 0;
	Tree* merge ( vector<int> &a , vector<int> &b , vector<Tree*> &ab) {
		Tree* dum = new Tree(-1);
		Tree* temp = dum  , *list = dum;
		if ( i >= a.size() or j >= b.size()) return dum;

		while ( i < a.size() and j < b.size()) {
			if ( a[i] <= b[j]) {
				Tree* root = new Tree(a[i++]);
				ab.push_back(root);
				dum -> right = root;
				dum = dum -> right;
				dum -> left = temp;
				temp = dum;


			}

			else {

				Tree* root = new Tree(b[j++]);
				ab.pb(root);
				dum -> right = root;
				dum = dum -> right;
				dum -> left = temp;
				temp = dum;

			}
		}
		while ( i < a.size() ) {
			Tree* root = new Tree(a.at(i));
			i++;
			ab.pb(root);
			dum -> right = root;
			dum = dum -> right;
			dum -> left = temp;
			temp = dum;
		}

		while ( j < b.size() ) {
			Tree* root = new Tree(b.at(j));
			j++;
			ab.pb(root);
			dum -> right = root;
			dum = dum -> right;
			dum -> left = temp;
			temp = dum;
		}

		return list->right;
	}

	void inorder( Tree* root) {
		if (! root) return;

		inorder ( root -> left );
		cout << root -> val << " ";
		inorder ( root -> right);
	}

};

void solve() {
	Tree* root = new Tree(6) , *root1 = new Tree(9);
	Tree bst = NULL;
	Tree bst1 = NULL;
	Tree b = NULL;

	bst.insert(root , 4);
	bst.insert( root, 5);
	bst.insert( root, 3);
	bst.insert( root, 2);
	bst.insert( root, 8);
	bst.insert( root, 7);
	bst.insert( root, 9);


	bst1.insert(root1 , 4);
	bst1.insert( root1, 5);
	bst1.insert( root1, 3);
	bst1.insert( root1, 12);
	bst1.insert( root1, 18);
	bst1.insert( root1, 17);
	bst1.insert( root1, 19);

	vector<int> in1 , in2 ;
	cout << "Tree1 is : " << nline;
	bst.inorderBST ( root , in1);
	cout << endl;

	cout << "Tree2 is : " << nline;
	bst1.inorderBST ( root1 , in2);


	cout << endl;
	debug(in1)
	debug(in2)
	cout << nline;
	vector<Tree*> ab;
	root = b.merge( in1, in2 , ab );

	for ( auto i : ab) cout << i -> val << " ";

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
