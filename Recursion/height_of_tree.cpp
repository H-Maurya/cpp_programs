//Height of a binary tree

#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	node* left;
	node* right;
};

struct node* newNode(int val) {
	node* n = new node;
	n->key = val;
	n->left = NULL;
	n->right = NULL;
	return n;
};

int height(node* n) {
	if(n==NULL){
		return 0;
	}
	int l = height(n->left);
	int r = height(n->right);
	return 1+max(l,r);
}

int main(){
	struct node *a, *b, *c, *d, *e, *f;
	a=newNode(1);
	b=newNode(2);
	c=newNode(3);
	d=newNode(4);
	e=newNode(5);
	f=newNode(6);
	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	d->left = f;

	cout<<height(a);

	return 0;
}


/*
			1
		  /	  \
		 2     3
	    /     / 
	   4     5   
	  /
	 6

*/