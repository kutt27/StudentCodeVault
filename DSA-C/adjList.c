#include <stdio.h>
#include <stdlib.h>

struct node {
	int vertex;
	struct node* next;
};

struct node* createnode(int vertex);

struct Graph{
	int numvertices;
	struct node** adjlists;
};

//creating a node
struct node* createnode(int v){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

//creating a graph
struct Graph* creategraph(int vertices){
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numvertices = vertices;

	graph->adjlists = malloc(vertices * sizeof(struct node*));


	//initializing every adjcency list as empty
	int i;
	for(i = 0; i < vertices; i++){
		graph->adjlists[i] = NULL;
	}
	return graph;
}

//adding edge
void addedge(struct Graph* graph, int s, int d){
	// Add edge from source to destination short for s to d
  	struct node* newNode = createnode(d);
  	newNode->next = graph->adjlists[s];
  	graph->adjlists[s] = newNode;

  	// Add edge from d to s
  	newNode = createnode(s);
  	newNode->next = graph->adjlists[d];
  	graph->adjlists[d] = newNode;
}

//print the graph
void printgraph(struct Graph* graph){
	int v;
	for(v = 0; v < graph->numvertices; v++){
		struct node* temp = graph->adjlists[v];
		printf("\n Vertex %d\n: ", v);
		while(temp){
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}
//driver code
int main(){
	struct Graph* graph = creategraph(4);
	addedge(graph, 0, 1);
	addedge(graph, 0, 2);
	addedge(graph, 0, 3);
	addedge(graph, 1, 2);

	printgraph(graph);

	return 0;
}