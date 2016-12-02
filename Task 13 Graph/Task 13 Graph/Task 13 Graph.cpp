// Task 13 Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

class Node
{	
public:
	int label;
	vector<Node*> neighbours = {};
	Node(int label)
	{
		this->label = label;
		cout << "Node Created" << endl;
	}
};

class Graph
{
public:
	vector<Node*> nodes = {};

	void addNode(int value)
	{
		//Check whether a node with value already exists in the graph
		bool isIn = false;
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i]->label == value)
			{
				isIn = true;
			}
		}

		//if no node exists, create one
		if (!isIn)
		{
			nodes.push_back(new Node(value));
		}
		else
		{
			cout << "Node already in Graph" << endl;
		}
	}

	void addEdge(int from, int to)
	{
		//variables
		bool fromIn = false;
		bool toIn = false;
		Node* fromNode = NULL;
		Node* toNode = NULL;

		//Search every node in the graph for nodes with the from and to values
		//and store those nodes for later use.
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i]->label == from)
			{
				fromIn = true;
				fromNode = nodes[i];
			}
			if (nodes[i]->label == to)
			{
				toIn = true;
				toNode = nodes[i];
			}
		}

		//If both nodes are in the graph
		if (fromIn && toIn)
		{
			//find out if an edge between the nodes already exists
			bool connected = false;
			for (int i = 0; i < fromNode->neighbours.size(); i++)
			{
				if (toNode == fromNode->neighbours[i])
				{
					connected = true;
				}
			}

			//if no edge exists between the nodes create an edge between them
			if (!connected)
			{
				fromNode->neighbours.push_back(toNode);
				toNode->neighbours.push_back(fromNode);
				cout << "New edge created between Node: " << from << " and Node: " << to << endl;
			}
		}
	}
};

int main()
{	
	Graph* G = new Graph();
	G->addNode(1);
	G->addNode(2);
	G->addNode(7);
	G->addNode(6);
	G->addNode(5);
	G->addNode(3);
	G->addNode(9);

	G->addEdge(1, 2);
	G->addEdge(2, 9);
	G->addEdge(2, 7);
	G->addEdge(9, 5);
	G->addEdge(7, 5);
	G->addEdge(7, 6);
	G->addEdge(7, 3);

	delete G;

    return 0;
}

