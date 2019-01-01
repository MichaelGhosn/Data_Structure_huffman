#include "StdFunctions.h"

#include "Functions.h"
#include "Stack.h"

using namespace std;
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

Node* ReadFile(const char* fileName) {
	// This function reads a file given by its name.
	// It creates a simply linked list containing the letters present in the file along with their frequency of occurence.
	// You can use the previous function : Node* IncFrequency(Node* Head, char c)
	
ifstream myfile;
myfile.open("E://Uni year 2//Data Structure//Huffman Code-20181226//file.txt");
string line;
if(myfile.is_open())
{
	cout<<"Reading from file..."<<endl;
	getline(myfile,line);
	
}
if(myfile.fail())
{
	cout<<"Unable to open file"<<endl;
}

	myfile.close();

Node *head=new Node;
head=Initialize();

int i=0;

while(line[i]!='\0')
{
	//if(line[i]==' ')
	//{
	//	i++;
	//}
	//hayde bass eza ma badna l space w ma3 hayde l if byotla3 l tree metel ma badoun
	head=IncFrequency(head,line[i]);
	i++;
}

return head;

}





void Sort(Node* Head) {
	// This function sorts the simply linked list in ascending order using the Selection Sort algorithm.
	// For this purpose, you may use the already defined function : int compare(Node* First, Node* Second)
	// The compare function compares two nodes according to their frequencies and lexicographic order.
	// The compare function returns -1 if the first node is smaller than the second node.
	// The compare function returns +1 if the first node is larger than the second node.
	// The compare function returns 0 if both nodes are equal.

Node *cur=new Node;
cur=Initialize();
Node *min=new Node;
min=Initialize();
Node *cur1=new Node;
cur1=Initialize();

for(cur=Head;cur->next!=NULL;cur=cur->next)
{
	min=cur;
	for(cur1=cur->next;cur1!=NULL;cur1=cur1->next)
	{
		if(compare(cur1,min)==-1)
		{
			min=cur1;
		}
	}
	
	if(compare(cur,min)==1)
	{
	  int x=min->frequency;
	  min->frequency=cur->frequency;
	  cur->frequency=x;
	  
	  char s=min->txt[0];
	  min->txt[0]=cur->txt[0];
	  cur->txt=s;
	}
	
}

DisplayList(Head);

}




Node* InsertSorted(Node* Head, Node* elt) {
	// This function inserts the node elt in the simply linked list while keeping the list
	// sorted according to the frequencies of occurrence and the lexicographic order. 
	// For this purpose, you may use the already defined function : int compare(Node* First, Node* Second)

Node *tmp=new Node;
tmp=elt;

if(Head==NULL)
{
	cout<<"Head is null so creating a new LL with "<<tmp->txt<<" as it's first node..."<<endl;
	Head=tmp;
	return tmp;
}




Node *cur=new Node;
cur=Head;

for(cur=Head;cur->next!=NULL;cur=cur->next)
{
	if(cur->txt==tmp->txt)
	{
		cout<<"Element found adding 1 to it's frequency..."<<endl;
		cur->frequency++;
		Sort(Head);
		return Head;
	}
}

for(cur=Head;cur->next!=NULL&&compare(cur->next,tmp)==-1;cur=cur->next);

cout<<"Adding "<<tmp->txt<<" in the LL..."<<endl;
tmp->next=cur->next;
cur->next=tmp;
Sort(Head);
return Head;

}



Node* SearchTree(Node* Tree, string C) {
	// This function searchs the binary tree for the node containing the character C.
	// It returns the a pointer to the node if such node exists
	// or NULL if the character does not occur in the text
	Node *temp=new Node;
	temp=NULL;
	if(Tree==NULL)
	{
		return NULL;
	}
	
	if(Tree->txt==C)
	{
		return Tree;
	}
	
	temp=SearchTree(Tree->right,C);
	if(temp)
	{
		return temp;
	}
	
	temp=SearchTree(Tree->left,C);
	if(temp)
	{
		return temp;
	}
	
	return NULL;

}


