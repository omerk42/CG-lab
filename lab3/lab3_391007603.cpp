// g++ -std=c++11 lab2.cpp -lglfw -lGL -lglut -lGLEW -o test

#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
// Include GLM: a library for 3D mathematics
#include <glm/glm.hpp>
using namespace glm;

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Error: unable to start GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	
	// Create a window and create its OpenGL context 
	
	// Change size of the window 
	GLFWwindow* window = glfwCreateWindow(800, 600, "My First OpenGL Window", NULL, NULL);
	
	if( window == NULL ){
		fprintf( stderr, "Unable to open GLFW window.\n" );
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Unable to start GLEW\n");
		return -3;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	int zz = 0;

	do{

	  
	  int width, height;
	  glfwGetFramebufferSize(window, &width, &height);
	  float ratio  = width / (float)height;

	  glViewport(0, 0, width, height);
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  glOrtho(-ratio, ratio, -2.f, 2.f, 2.f, -2.f);
	
	  glMatrixMode(GL_MODELVIEW);
	  glLoadIdentity();
	  glRotatef(0.0, 0.0, 0.0, 0.0);

		// Clear the screen
	  glClear( GL_COLOR_BUFFER_BIT );

	  // select color white
	
	glColor3f(1.0f, 1.0f, 1.0f);

	// Create a triangle 
	glBegin(GL_POLYGON);
	                // Begin drawing the Traingle
		 			
		glVertex3f(-0.6f, -0.5f, 0); 
		glVertex3f( 0.6f, -0.5f, 0); 
		glVertex3f( 0.6f, 0.5f, 0); 
		glVertex3f( -0.6f, 0.5f, 0);

	glEnd();  // End of drawing triangle

	glColor3f(0.5f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);                // Begin drawing the Traingle
		
		glVertex3f( -0.6f, 0.5f, 0); 
		glVertex3f( 0.0f, 1.0f, 0); 
		glVertex3f( 0.6f, 0.5f, 0);

	glEnd(); 

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);                // Begin drawing the Traingle
		
		glVertex3f( -0.1f, -0.5f, 0); 
		glVertex3f( -0.1f, 0.05f, 0); 
		glVertex3f( 0.1f, 0.05f, 0);
		glVertex3f( 0.1f, -0.5f, 0); 

	glEnd(); 

	  // Swap buffers
	  glfwSwapBuffers(window);
	  glfwPollEvents();

	} 


	

	// Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}