#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>

#define part 360

FILE *fp;
char *py="./ir.py";
char get[256]="GET\n",quit[256]="QUIT\n";
int number,x[10],y[10],i;

void display( void ){
	int i,n = part;
	float x,y,r = 0.7,x_1,y_1,r_1 = 0.6;
	double rate;
        glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLE_STRIP);
	for(i=0;i<n+1;i++){
		rate = (double)i/n;
		x = r * cos(2.0 * M_PI * rate);
		y = r * sin(2.0 * M_PI * rate);
		x_1 = r_1 * cos(2.0 * M_PI * rate);
		y_1 = r_1 * sin(2.0 * M_PI * rate);
		glVertex3f(x, y, 0.0);
		glVertex3f(x_1,y_1,0.0);
	}
        glEnd();
        glFlush();
}

void timer(int value){
	fputs(get,fp);
//	scanf("%d",&number);
//	for(i=0;i<number;i++){                  
//		fscanf(fp,"%d",&x[i]);
//		fscanf(fp,"%d",&y[i]);
//	}
//	printf("number\t\t%d\n",number);
	glutPostRedisplay();
	glutTimerFunc(100 , timer , 0);
}

int main(int argc , char *argv[]) {
//	fp = popen(py,"w");
//	sleep(10);
	glutInit(&argc, argv);
	glutInitWindowSize(500 , 500);
	glutInitDisplayMode(GLUT_RGBA);
        glutCreateWindow("head-tracking");
	fp = popen(py,"w");
	sleep(12);
        glutDisplayFunc(display);
        glutTimerFunc(100, timer, 0);

        glutMainLoop();
	fputs(quit,fp);
	pclose(fp);
        return 0;
}