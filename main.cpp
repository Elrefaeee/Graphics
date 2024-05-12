#include <GL/glut.h>
#include <cstdio>
#include <math.h>
#include <ctime>
int coordinate[10] = {-2, -2, -3, 0, 0, 3, 3, 0, 2, -2};
int logWidth = 100;
int logHeight = 100;
int phyHeight = 800;
int phyWidth=800;
int centerX = logWidth/2;
int centerY = logHeight/2;
int timerInterval = 1000; // Interval for the timer in milliseconds
//enemies design
int enemy[10]={-1,-1,-2,0,0,2,2,0,2,-2};
class Print{
	public:
	static void printSome(char *str,int x,int y) {
			glRasterPos2d(x,y);
			for (int i=0;i<strlen(str);i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
			glFlush();
	}
};
class Lines{
public:
	static void line_design(){
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex2f(centerX+7,centerY+7);
			glVertex2f(centerX+18,centerY+18);
	    glEnd();

		glColor3f(1.0f, 1.0f, 1.0f);
	    glBegin(GL_LINES);
			glVertex2f(centerX-7,centerY+7);
			glVertex2f(centerX-18,centerY+18);
	    glEnd();

	    glColor3f(1.0f, 1.0f, 1.0f);
	    glBegin(GL_LINES);
			glVertex2f(centerX+7,centerY-7);
			glVertex2f(centerX+18,centerY-18);
	    glEnd();	

		glColor3f(1.0f, 1.0f, 1.0f);
	    glBegin(GL_LINES);
			glVertex2f(centerX-7,centerY-7);
			glVertex2f(centerX-18,centerY-18);
	    glEnd();	
	}
};
//ENEMIES DESIGN NOT USED
class Enemy{
public:
	void blue_enemy(){
		//glColor3f(1.0f, 1.0f, 1.0f);
	   	glBegin(GL_POLYGON);
	   		glVertex2f(centerX,centerY);
	   		glVertex2f(centerX+enemy[0],centerY+enemy[1]);
	   		glVertex2f(centerX+enemy[2],centerY+enemy[3]);
			glVertex2f(centerX+enemy[4],centerY+enemy[5]);
	    	glVertex2f(centerX+enemy[6],centerY+enemy[7]);
	    	glVertex2f(centerX+enemy[8],centerY+enemy[9]);
	   	glEnd();
	}
	void yellow_enemy(){
		//glColor3f(1.0f, 1.0f, 1.0f);
	   	glBegin(GL_POLYGON);
	   		glVertex2f(centerX,centerY);
	   		glVertex2f(centerX+enemy[0],centerY+enemy[1]);
	   		glVertex2f(centerX+enemy[2],centerY+enemy[3]);
			glVertex2f(centerX+enemy[4],centerY+enemy[5]);
	    	glVertex2f(centerX+enemy[6],centerY+enemy[7]);
	    	glVertex2f(centerX+enemy[8],centerY+enemy[9]);
	   	glEnd();
	}
};
class Time {
public:
    static void timerCallback(int value) {
        glutPostRedisplay();
        glutTimerFunc(timerInterval, timerCallback, 0);
    }

    void startTimer() {
        glutTimerFunc(timerInterval, timerCallback, 0);
    }

    static void stopwatch() {
        char timeString[50];
        int milliseconds = glutGet(GLUT_ELAPSED_TIME) % 1000;
        int seconds = (glutGet(GLUT_ELAPSED_TIME) / 1000) % 60;
        sprintf(timeString, "%02d.%03d", seconds, milliseconds);
        glColor3f(1.0f, 1.0f, 1.0f);
        Print::printSome(timeString, centerX - 3.5, centerY + 25);

        glutPostRedisplay();
    }
};
class Background{
public:
	static void pattern(){
	   float layoutvertices[4][2] = {
	        {centerX, centerY + 45}, 
	        {centerX + 45, centerY},
	        {centerX, centerY - 45},
	        {centerX - 45, centerY}
	    };
	   float layoutvertices2[4][2] = {
	        {centerX, centerY + 50}, 
	        {centerX + 50, centerY},
	        {centerX, centerY - 50},
	        {centerX - 50, centerY}
	    };
	  	float layoutvertices3[4][2] = {
	        {centerX, centerY + 55}, 
	        {centerX + 55, centerY},
	        {centerX, centerY - 55},
	        {centerX - 55, centerY}
	    };
	    //pattern3
	   	glColor3f(0.0f, 0.706f, 0.588f);
		glBegin(GL_POLYGON);
	    for (int i = 0; i < 4; i++) {
	        glVertex2f(layoutvertices3[i][0], layoutvertices3[i][1]);
	    }
	    glEnd();
	    //pattern2
	   	glColor3f(0.906f, 0.816f, 0.039f);
		glBegin(GL_POLYGON);
	    for (int i = 0; i < 4; i++) {
	        glVertex2f(layoutvertices2[i][0], layoutvertices2[i][1]);
	    }
	    glEnd();
	    //pattern1
	   	glColor3f(1.0f, 0.0f, 0.392f);
		glBegin(GL_POLYGON);
	    for (int i = 0; i < 4; i++) {
	        glVertex2f(layoutvertices[i][0], layoutvertices[i][1]);
	    }
	    glEnd();
	}
};
class Player_Design{
public:
	static void design(){ 
	// outer rhombus
	    float vertices1[4][2] = {
	        {centerX, centerY + 10}, 
	        {centerX + 10, centerY},
	        {centerX, centerY - 10},
	        {centerX - 10, centerY}
	    };
	    //inner rhombus
	    float vertices2[4][2] = {
	        {centerX, centerY + 6}, 
	        {centerX + 6, centerY},
	        {centerX, centerY - 6},
	        {centerX - 6, centerY}
	    };
	    //layout rhombus
	    float layoutvertices[4][2] = {
	        {centerX, centerY + 40}, 
	        {centerX + 40, centerY},
	        {centerX, centerY - 40},
	        {centerX - 40, centerY}
	    };
	    //creating layout
	   	glColor3f(0.133f, 0.129f, 0.2f);
		glBegin(GL_POLYGON);
	    for (int i = 0; i < 4; i++) {
	        glVertex2f(layoutvertices[i][0], layoutvertices[i][1]);
	    }
	    glEnd();
	    //creating outer rhombus
	    glColor3f(1.0f, 1.0f, 1.0f);
	    glBegin(GL_POLYGON);
	    for (int i = 0; i < 4; i++) {
	        glVertex2f(vertices1[i][0], vertices1[i][1]);
	    }
	    glEnd();
	    //creating inner rhombus
		glColor3f(0.133f, 0.129f, 0.2f);
		glBegin(GL_POLYGON);
	    for (int i = 0; i < 4; i++) {
	        glVertex2f(vertices2[i][0], vertices2[i][1]);
	    }
	    glEnd();
	}
};
class Control_Player{
public:	
	static void keyboard(unsigned char key, int x, int y) {
	    //closing game key
		if (key == 27) { //escape
	        exit(0);
	    }
	    //if(key == 13){ //enter
	    //	Time::stopwatch();
	    //	glutSpecialFunc(specialKeyboard);
		//}
	}
	//control player
	static void specialKeyboard(int key, int x, int y)
	{
		if(key==GLUT_KEY_UP){
			coordinate[0]=-2;
			coordinate[1]=-2;
			coordinate[2]=-3;
			coordinate[3]= 0;
			coordinate[4]= 0;
			coordinate[5]= 3;
			coordinate[6]= 3;
			coordinate[7]= 0;
			coordinate[8]= 2;
			coordinate[9]=-2;
		}
		if(key== GLUT_KEY_RIGHT){
			coordinate[0]=-2;
			coordinate[1]= 2;
			coordinate[2]= 0;
			coordinate[3]= 3;
			coordinate[4]= 3;
			coordinate[5]= 0;
			coordinate[6]= 0;
			coordinate[7]=-3;
			coordinate[8]=-2;
			coordinate[9]=-2;
		}
		if(key== GLUT_KEY_DOWN){
			coordinate[0]= 2;
			coordinate[1]= 2;
			coordinate[2]= 3;
			coordinate[3]= 0;
			coordinate[4]= 0;
			coordinate[5]= -3;
			coordinate[6]= -3;
			coordinate[7]= 0;
			coordinate[8]=-2;
			coordinate[9]=2;
		}
		if(key== GLUT_KEY_LEFT){
			coordinate[0]= 2;
			coordinate[1]= 2;
			coordinate[2]= 0;
			coordinate[3]= 3;
			coordinate[4]= -3;
			coordinate[5]= 0;
			coordinate[6]= 0;
			coordinate[7]= -3;
			coordinate[8]= 2;
			coordinate[9]=-2;
		}
		glutPostRedisplay();
	}
	static void start_control(){
		glutKeyboardFunc(keyboard);
		glutSpecialFunc(specialKeyboard);
	}
	//player animation
	static void player_arrow(){
    	glColor3f(1.0f, 1.0f, 1.0f);
   		glBegin(GL_POLYGON);
   			glVertex2f(centerX,centerY);
   			glVertex2f(centerX+coordinate[0],centerY+coordinate[1]);
   			glVertex2f(centerX+coordinate[2],centerY+coordinate[3]);
			glVertex2f(centerX+coordinate[4],centerY+coordinate[5]);
    		glVertex2f(centerX+coordinate[6],centerY+coordinate[7]);
    		glVertex2f(centerX+coordinate[8],centerY+coordinate[9]);
   		glEnd();
	}	
};
class Show{
public:
	void init2D(){
		glClearColor(1.0f, 0.0f, 0.392f,1.0f);
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0.0,logWidth,0.0,logHeight);
	}
	void start_display(){
		glutDisplayFunc(display);
	}
	static void display() {
	    glClear(GL_COLOR_BUFFER_BIT);
	    //pattern
	    Background::pattern();
	    //player design
	 	Player_Design::design();   
	    //creating 4 lines 
	    Lines::line_design();
		//control	
		Control_Player::start_control();
		Control_Player::player_arrow();
	    //if(key == 13)
			Time::stopwatch();
		glutSwapBuffers();   
		glFlush();
	}
};
//=======================================================================
int main(int argc, char** argv) {
	Show show;
    glutInit(&argc, argv);
	glutInitWindowSize(phyWidth,phyHeight);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Project Rhombus");
	//glutFullScreen();
	show.init2D();
	show.start_display();
	glutMainLoop();
}
