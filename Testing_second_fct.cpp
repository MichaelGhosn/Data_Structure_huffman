#include <iostream>
#include <fstream>
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


Node* Initialize() {
	return NULL;
}



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


   	temp->txt[0]=c;
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
	
	tmp->txt[0]=c;
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
	head=IncFrequency(head,line[i]);
	i++;
}

return head;

}




int main(int argc, char** argv) {
	
	/*cout<<"Give file name:"<<endl;
	char *d;
	cin>>*d;*/
	const char * c;
	
	Node *test=ReadFile(c);
	
	Node *cur=new Node;
	cur=test;
	
	while(cur!=NULL)
	{
		cout<<cur->frequency<<" "<<cur->txt[0]<<endl;
		cur=cur->next;
	}
	
	
	return 0;
}
