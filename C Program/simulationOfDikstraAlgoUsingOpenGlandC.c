// Demonstarion of 3d view of Dijkstra Algo using C and OpenGl 

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<GL/glut.h>

void dijkstra();

// GLOBAL VARIABLES

//Application Display Size
GLsizei windowHeight = 1020, windowWidth = 1080;
 
//Used in drawSquare, square length
GLfloat size = 3.0;

float PI = 3.14285714286;

//Radius of circle
int radius = 30;

//No. of nodes in window
int nodeCount = 0;

//Max No. of nodes that can be created
int maxNodes = 26;

//2X2 matrix between the nodes 
int adjMatrix[26][26];

//No. of nodes selected to draw a line
int lineNodesCount = 0;

//Source node created
int sourceNodeCreated = 0;

//Destination node created
int destinationNodeCreated = 0;

//Dijkstra begin
int dijkstraRun = 0;

//instruction display
int instruction = 1;


//Create node struct
struct node
{	
	int id;
	int xCoordinate;
	int yCoordinate;
}nodes[26], lineNodes[2], sourceNode, destinationNode;


//return distance between two nodes
int computeDistance(struct node a, struct node b)
{
	return (int) sqrt(pow(abs(a.xCoordinate - b.xCoordinate), 2) + pow(abs(a.yCoordinate - b.yCoordinate), 2));
}

//Check if two nodes intersect i.e if to create a new node or select a node 
int noRepeat(int x, int y) 
{	
	//if no nodes on screen, dont bother
	if(!nodeCount)
		return 1;

	//create a temp node for comparison on the clicked coordinate
	struct node temp = {nodeCount, x, y};

	for(int i = 0; i < nodeCount; i++)
	{	
		//if the nodes intersect, assume a node is clicked
		if(computeDistance(temp, nodes[i]) < 2*radius)
		{	 
			//push the clicked node to the stack
			lineNodes[lineNodesCount] = nodes[i];
			return 0;
		}
	}
	//no node was pressed, create a new node at x,y
	return 1;
}

//get perpendicular coordinates to display the text
void getPerpendicularCoordinates(int *x, int *y)
{
	int x1, x2, y1, y2;

	x1 = lineNodes[0].xCoordinate;
	x2 = lineNodes[1].xCoordinate;
	y1 = lineNodes[0].yCoordinate;
	y2 = lineNodes[1].yCoordinate;

	float diff = (x2 - x1)? 0.0001 : x2 - x1;

	float slope = ((float)(y2 - y1)) / (diff);

	float perpendicularSlope = -1*(1 / slope);


	*x = *x + 25; 	
	*y = *y + perpendicularSlope * (*x) + 7;

}

//write Distance between the nodes to screen
void writeDistance(char *text, int x, int y)
{	
	if(instruction)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(x,y);
    int len = strlen(text);
    for(int i = 0; i < len; i++)
    { 
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , text[i]);
    }
    glFlush();
}



//write Label to nodes to screen
void writeLabel(char text, int x, int y)
{	
	//change the color to yellow
	glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(x,y);
    // int len = strlen(text);
    // for(int i = 0; i < len; i++)
    // { 
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , text);
    // }
}

//draw Circle at the given coordinates
void drawCircle(float cx, float cy, float r, float num_segments, char colorCharacter)
{

	float theta,x,y;

	//Give the center of the circle a label [A-Z]
	if(colorCharacter == 'N')
		writeLabel((char)65 + nodeCount ,cx - 5, cy - 14);

	//change the color to green if colorCharacter = 'N'
	if(colorCharacter == 'N')
		glColor3f(0.0, 1.0, 0.0);

	if(colorCharacter == 'B')
		glColor3f(0.0, 0.0, 1.0);

	if(colorCharacter == 'R')
		glColor3f(1.0, 0.0, 0.0);

	//line loop- connect all the points below 
	glBegin(GL_LINE_LOOP);
 
	for(int i = 0; i < num_segments; i++){
		//compute new angle and get the x, y coordinate
		theta = 2.0f * PI * i / num_segments;
 		x = r * cosf(theta);
		y = r * sinf(theta);
 		
 		//draw the point
		glVertex2f(x + cx, y + cy);
	}
	glEnd();

	//flush to output screen
	glFlush();

}

//draw square
void drawSquare(int x, int y)
{
	// y = windowHeight-y;
	// printf("x=%d y=%d \n",x, y );

	glBegin(GL_POLYGON);
		glVertex2f(x+size, y+size);
		glVertex2f(x-size, y+size);
		glVertex2f(x-size, y-size);
		glVertex2f(x+size, y-size);
	glEnd();
	glFlush();
}

//sets the mid point coordinates to the arguments
void getMidPoint(int *midX, int *midY)
{
	*midX = (lineNodes[0].xCoordinate + lineNodes[1].xCoordinate)/2;
	*midY = (lineNodes[0].yCoordinate + lineNodes[1].yCoordinate)/2;
}

//draw lines between two  nodes
void drawLine(char color) 
{
	//set color to white
	if(color == 'N' || color == 'R')
		glColor3f(0.3, 0.3, 0.3);

	if(color == 'D')
		glColor3f(0.8, 0.8, 0.8);

	if(color == 'M')
		glColor3f(0.5, 0.0, 0.0);

	//draw lines between selected nodes (stored in lineNodes)
	glBegin(GL_LINES);
		glVertex2f(lineNodes[0].xCoordinate, lineNodes[0].yCoordinate);
		glVertex2f(lineNodes[1].xCoordinate, lineNodes[1].yCoordinate);
	glEnd();
	glFlush();

	//Mid Point of the line segment to display distance
	int midX, midY;
	char distanceString[10]; 
	//get the mid coordinates 
	getMidPoint(&midX, &midY);  


	//get nodes id, keys for the adjMatrix 
	int id1 = lineNodes[0].id;
	int id2 = lineNodes[1].id;
	//compute distance between the nodes.
	int distance = computeDistance(lineNodes[0], lineNodes[1]);
	//store it in adjMatrix
	adjMatrix[id1][id2] = distance;
	adjMatrix[id2][id1] = distance;

	//Convert distance to string
	sprintf(distanceString, "%d",distance);
	//Display to the window
	getPerpendicularCoordinates(&midX, &midY);
	writeDistance(distanceString, midX, midY);

	glFlush();

	//write both circles' labels again
	writeLabel('A' + lineNodes[0].id, lineNodes[0].xCoordinate - 5, lineNodes[0].yCoordinate - 14);
	writeLabel('A' + lineNodes[1].id, lineNodes[1].xCoordinate - 5, lineNodes[1].yCoordinate - 14);

	glFlush();

	//Display the updated matrix to the console
	if(color == 'N')
	{
		printf("\n");
		for(int i = 0; i < nodeCount; i++)
		{
			for(int j = 0; j < nodeCount; j++)
			{
				printf("%d \t", adjMatrix[i][j]);
			}
			printf("\n");
		}
	}
}


//mouse click handler
void myMouse(int btn, int state, int x, int y) 
{
	//Clear Instructions first
	if(instruction)
	{
		instruction = 0;
		glClear(GL_COLOR_BUFFER_BIT);
	}

	//dont listen to mouse events if dijkstra operation is running
	if(dijkstraRun) 
	{
		return;
	}

	//fix coordinate system
	y = windowHeight-y;

	//left click: create nodes, join nodes
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{	
		// printf("x = %d, y = %d\n",x, y);

		//if not clicked on the circle 
		if (noRepeat(x, y))
		{
			//dont draw if nodeCount > 26;
			if(nodeCount >= 26)
			{
				return;
			}

			//draw new circle
			drawCircle(x, y, radius, 200, 'N');
			lineNodesCount = 0;
			//set the values of the new node
			nodes[nodeCount].xCoordinate = x;
			nodes[nodeCount].yCoordinate = y;
			nodes[nodeCount].id = nodeCount;

			//increase the node count
			nodeCount++;
		} 
		//draw line
		else
		{
			if(lineNodesCount == 1)
			{
				drawLine('N');
				lineNodesCount = 0;
			}
			else
			{
				lineNodesCount += 1;
			}
		}
	}

	//right click: select source and destination nodes
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && (!sourceNodeCreated || !destinationNodeCreated))
	{
		//if nodes are created
		if(nodeCount)
		{	
			//if a node is clicked, lineNodes[0] will have the node clicked
			if(!noRepeat(x, y))
			{
				//if source node is not assigned
				if(!sourceNodeCreated)
				{
					sourceNode = lineNodes[0];
					//source node created
					sourceNodeCreated = 1;
					//change color of the source node to (R)ed
					drawCircle(sourceNode.xCoordinate, sourceNode.yCoordinate, radius, 200, 'R');
				}
				else 
				{
					//first, check if source is not selected again
					if(((sourceNode.xCoordinate - lineNodes[0].xCoordinate) != 0) || ((sourceNode.yCoordinate - lineNodes[0].yCoordinate) != 0 ))
					{
						destinationNode = lineNodes[0];
						//destination node created
						destinationNodeCreated = 1;
						//change color of the destination node to (B)lue
						drawCircle(destinationNode.xCoordinate, destinationNode.yCoordinate, radius, 200, 'B');
					} 
				}

			}
		}
	}

}

//myReshape to Handle change in window size 
void myReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
	windowWidth = w;
	windowHeight = h;
}

//window initilization
void myInit()
{
	glViewport(0,0,windowWidth,windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, 0, windowHeight);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 1);
	glColor3f(1.0, 1.0, 1.0);
	// glPointSize(0);
	 glLineWidth(5);
}


//Function to display instructions
void display_hello()
{
	// writeDistance(" Welcome! To The Simulation of Dijkstra's Algorithn.", 200, 900);
	// writeDistance("#  Use Mouse Left Button to Create Nodes.", 250, 800);
	// writeDistance("#  Select any two Nodes to form a Path.", 250, 770);
	// writeDistance("#  Use Mouse Right Button to select Source and Destrination.", 250, 740);
	// writeDistance("#  Press ENTER key to begin Dijkstra's Algorithm.", 250, 710);


    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    writeDistance(" BANGALORE TECHNOLOGICAL INSTITUTE, BANGALORE", 700, 900);
    glColor3f(1.0, 1.0, 1.0);
    writeDistance(" Department of Computer Science", 845, 850);

    glColor3f(1.0, 0, 1.0);
    writeDistance("___________________________________________________________________________________________________________________________________", 270, 800);

    glColor3f(1.0, 0, 1.0);
    writeDistance("Computer Graphics Mini Project On", 790, 730);
    writeDistance("Simulation of Dijkstra Algorithm", 815, 680);

    writeDistance("By:", 470, 635);
    writeDistance("Shahbajz Alam, Sankar Shah, Prince Yadav", 470, 600);
    writeDistance("6th Semester", 470, 560);
    writeDistance("B.E. Computer Science", 470, 520);

    writeDistance("Under the Guidance of:", 1070, 635);
    writeDistance("Mr. Rajshekhar Sir", 1070, 600);
    writeDistance("Proffesor", 1070, 560);
    writeDistance("Dept. Computer Science", 1070, 520);

    writeDistance("___________________________________________________________________________________________________________________________________", 270, 450);

    writeDistance("Instructions :", 900, 400);
    writeDistance("* Left Click to Create Nodes.", 470, 330);
    writeDistance("* Select atleast two Nodes to form a Path.", 470, 280);
    writeDistance("* Right Click to select Source and Destrination.", 470, 230);
    writeDistance("* Press ENTER key to begin Dijkstra's Algorithm.", 470, 190);
    glFlush();
}

//display function
void myDisplay() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		display_hello();
		glFlush();

}

//fix adjacency matrix: set the distance among the nodes to highest value (99999)
void fixAdjMatrix()
{
	for(int i = 0; i < maxNodes; i++)
	{
		for(int j = 0; j < maxNodes; j++)
		{
			adjMatrix[i][j] = 99999;
		}
	}
}

//keyboard event listener: when enter key is pressed begin dijkstra
void beginDijkstra(unsigned char key, int x, int y)
{
	printf("%d\n",key);

	//if source or destination nodes are not selected dont start
	if(!sourceNodeCreated || !destinationNodeCreated)
	{	
		printf("Source node / destination node not selected\n");
		return;
	}
	//begin dijkstra if enter key is pressed
	if((int)key == 13)
	{	
		dijkstraRun = 1;
		dijkstra();
	}
}



//main function 
int main(int argc, char **argv) 
{
	fixAdjMatrix();
	printf("Hello\n\n");
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Project On Dijksta's Algorithm");
	myInit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(beginDijkstra);
	glutDisplayFunc(myDisplay);
	glutMainLoop();

	return 0;
}

//return unselected node with minimum distance from the node
int getMinimumDistanceNode(int *distanceFromSource, int *selected)
{
	int minimumNode = -1;
	int minimumDistance = 99999;

	//loop through the nodes
	for(int i = 0; i < nodeCount; i++)
	{
		//if the node is not selected and has low distance choose it for now.
		if(selected[i] != 1 && distanceFromSource[i] < minimumDistance)
		{
			minimumNode = i;
			minimumDistance = distanceFromSource[i];
		}
	}

	//return the node with minimum distance 
	return minimumNode;
}

//route source to destination
void routeNodes(int n1, int n2)
{
	lineNodes[0] = nodes[n1];
	lineNodes[1] = nodes[n2];

	drawLine('M');
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Stroing start time
    clock_t start_time = clock();
 
    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}


//Dijkstra's algorithm
void dijkstra()
{

	//distance of all nodes from the source node
	int distanceFromSource[26];

	//node connecting to the current node
	int prev[26];

	//if node is visited
	int selected[26];

	//the current node
	int current;

	//initilize nodes distance with 99999(ie not visited yet), selected to -1(not visited yet), prev to -1(no connection yet)
	for(int i = 0; i < nodeCount; i++)
	{
		distanceFromSource[i] = 99999;
		prev[i] = -1;
		selected[i] = -1;
	}

	//distance of source node to 0 to select it first
	distanceFromSource[sourceNode.id] = 0;

	for(int i = 0; i < nodeCount; i++)
	{
		//get node with minimum distance not selected
		current = getMinimumDistanceNode(distanceFromSource, selected);
		//mark it selected

		if(current == -1)
			break;

		selected[current] = 1;
		printf("\n%c\n", current + 65);

		//loop through all the nodes finding its neighbours
		for(int j = 0; j < nodeCount; j++)
		{
			//if it's already visited dont bother
			if(selected[j] != 1)
			{	
				//if the distance from the current node is less, select it as it's previous node
				if((distanceFromSource[current] + adjMatrix[current][j]) < distanceFromSource[j])
				{	
					distanceFromSource[j] = distanceFromSource[current] + adjMatrix[current][j];

					if(prev[j] != -1)
					{	
						lineNodes[0] = nodes[prev[j]];
						lineNodes[1] = nodes[j];
						delay(700);
						drawLine('R');

						delay(700);
						lineNodes[0] = nodes[current];
						drawLine('D');
					}
					else
					{	
						delay(700);
						lineNodes[1] = nodes[j];
						lineNodes[0] = nodes[current];
						drawLine('D');
					}

					prev[j] = current;
				}
			}
		}

	}

	while(1)
	{
		if(prev[destinationNode.id] == -1)
			break;
		delay(500);
		routeNodes(destinationNode.id, prev[destinationNode.id]);
		destinationNode = nodes[prev[destinationNode.id]];
	}

	//display distance from array and previous array to console
	printf("node(i)\t\tdistance\tprevious\tselected\n");
	for(int i = 0; i < nodeCount; i++)
	{
		printf("%c\t\t%d\t\t%c\t\t%d\n",65+i, distanceFromSource[i], ((prev[i] != -1)? 65+prev[i] : ' ') , selected[i]);
	}

}
