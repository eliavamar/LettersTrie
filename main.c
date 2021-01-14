#include<stdio.h>
#define NUM_LETTERS ((int)26)
#include <stdlib.h>
#include<string.h>
typedef enum{FALSE=0,TRUE=1}bollean;
typedef struct node{
	int flag;
	int index;
	char * letters;
	char letter;
	int count;
	struct node* children[NUM_LETTERS];
}node;
char lower(char c){
	 if(c>='A'&&c<='Z')
		  return c+32;
	  return c;
}

node* Init(){
	node* temp=(node*)(malloc(sizeof(node)));
	if(temp!=NULL){
		temp->letters=NULL;
		temp->count=0;
		temp->flag=0;
		temp->index=0;
		for(int i=0;i<NUM_LETTERS;i++)
			temp->children[i]=NULL;
		return temp;
	}
	exit(1);
}
node* newNode(char c){
	node*temp=(node*)(malloc(sizeof(node)));
	if(temp!=NULL){
		temp->count=0;
		temp->letter=c;
		temp->flag=0;
		temp->index=1;
		for(int i=0;i<NUM_LETTERS;i++)
			temp->children[i]=NULL;
		return temp;
	}
	 exit(1);
}
node* add(node** p,char c){
if((*p)->children[c-'a']){    
return (*p)->children[c-'a'];    
}
else if((*p)->letters!=NULL){
(*p)->children[c-'a']=newNode(c);
(*p)->children[c-'a']->letters=(char*)(malloc(strlen((*p)->letters)+2));
if(!((*p)->children[c-'a']->letters))
exit(1);
strcpy((*p)->children[c-'a']->letters,(*p)->letters);
(*p)->children[c-'a']->letters[strlen((*p)->letters)]=c;
(*p)->children[c-'a']->letters[strlen((*p)->letters)+1]='\0';
return (*p)->children[c-'a'];
}
else{
(*p)->children[c-'a']=newNode(c); 
 (*p)->children[c-'a']->letters=(char*)(malloc(2));
if(!((*p)->children[c-'a']->letters))
exit(1);
(*p)->children[c-'a']->letters[0]=c;
(*p)->children[c-'a']->letters[1]='\0';
return (*p)->children[c-'a'];
	}
	    
}
node * buildTrie(){
	char c;
	node *p;
	node* n=Init();
	p=n;
	
while(scanf("%c",&c)!=EOF){
while(c==' '||c=='\n'||c=='\t'||c=='\r'){
scanf("%c",&c);
}
p=n;
int counter=0;
while(c!=' '&&c!='\n'&&c!='\t'&&c!='\r'){
if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
c=lower(c);
p=add(&p,c);
counter++;
}
scanf("%c",&c);
}
if(counter)
p->count++;
p->flag=1;
}
return n;
}
void printTrie_d(node** root){
if(!root)
return;
node *temp=*root;
for(int i=0;i<NUM_LETTERS;i++){
   if((temp)->children[i]){
 if((temp)->children[i]->flag){
  printf("%s %d\n",(temp)->children[i]->letters, (temp)->children[i]->count);
 }

 printTrie_d(&(temp->children[i]));
   }
}
free((*root)->letters);
free(*root);
}
void printTrie_u(node**root){
if(!root)
return;
node* temp=*root;
for(int i=25;i>-1;i--){
if((temp)->children[i]){
if((temp)->children[i]->flag){
printf("%s %d\n",(temp)->children[i]->letters, (temp)->children[i]->count);
}
printTrie_u(&(temp->children[i]));
}
}
free((*root)->letters);
free(*root);
}
int main(int argc,char*argv[]){
node*root=buildTrie();
if(argc>1){
if(*argv[1]=='r'){
printTrie_u(&root);
}else{

printTrie_d(&root);
}}else{
	printTrie_d(&root);
}
return 0;

}

