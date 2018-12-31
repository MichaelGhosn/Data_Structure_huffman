#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Node {
	int frequency;
	std::string txt;
	Node* next;
	Node* left;
	Node* right;
	Node* parent;
};

Node* IncFrequency(Node* Head, char c) {
	// This function searches for the character C in the simply linked list.
	// If it was able to find a node containing this character, it increments it frequency by 1.
	// If no such node exists, it creates a new node and append it to the beginning of the simply linked list, where :
	//		the 'txt' field is equal to the character
	//		the 'frequnecy' field is equal to 1
	//		the 'parent', 'left' and 'right' fields are set to NULL

if(Head==NULL)
{
	cout<<"Head is null so creating LL from scratch..."<<endl;
 
    Node *temp=new Node;
	if(temp==NULL)
	{
		cout<<"Error creating temporary node exit..."<<endl;
		exit(1);
	   }   


   	temp->txt=c;
	temp->next=NULL;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	temp->frequency=1;
	
	Head=temp;
	
	cout<<c<<" added to LL with frequency 1"<<endl;
	return Head;	
	
}


Node *element=new Node;
element=NULL;


for(element=Head;element!=NULL;element=element->next)
{

	if(element->txt[0]==c)
	{
		element->frequency++;
		cout<<c<<" already exists adding 1 to his frequency..."<<endl;
		return Head;
	}
}


	Node *tmp;
	tmp=new Node;
	
	if(tmp==NULL)
    {
    	cout<<"Error with node creation"<<endl;
    	exit(1);
	}
	
	tmp->txt=c;
	tmp->next=NULL;
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->parent=NULL;
	tmp->frequency=1;
	
	
	tmp->next=Head;
	Head=tmp;
	cout<<c<<" is a new element adding it with frequency 1..."<<endl;
	return Head;

}


int main(int argc, char** argv) {

	int i=0;
	Node *x=NULL;
	char c;
	do{
		cout<<"insert element "<<i+1<<endl;
		cin>>c;
		x=IncFrequency(x,c);
		i++;
	}
	while(i<5);
	
	Node *cur=new Node;
	cur=x;
	
	while(cur!=NULL)
	{
		cout<<cur->frequency<<" "<<cur->txt[0]<<endl;
		cur=cur->next;
	}
	return 0;
}

