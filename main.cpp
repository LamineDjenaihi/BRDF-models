
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include"loaderobj.h"
#include "textfile.h"
float px=0.0,py=20.0,pz=10.0,camx=10.0,camy=5.0,camz=5.0;

//GLfloat Kd[3] = { 1.0, 1.0, 1.0};
GLfloat cam[ ] = { 1.0,0.0,0.0};
//float pos[3];
// GLint loc;
GLfloat loc2,loc3,loc4,loc5,loc6,loc7,loc8,loc9,loc10,loc11,loc12,loc13,loc14,loc15;
GLhandleARB v,f,p,v3,f3,p3,v5,f5,p5,f7,p7,v7;
GLhandleARB v2,f2,p2,v4,f4,p4,v6,f6,p6;
char sh='l';
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(60,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);


}

float a = 0;
void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(camx,camy,camz, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
	//glUseProgram(0);
	 GLfloat pos[ ]={px,py,pz};
	  GLfloat cam[ ]={camx,camy,camz};
	  if(sh=='l')
		  {
	glUseProgram(p);
	glUniform3fv(loc3,1,pos);
	glUniform3fv(loc2,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
	glUseProgram(0);
	 }
	  if(sh=='p')
	  {
	glUseProgram(p2);
	glUniform3fv(loc5,1,pos);
	glUniform3fv(loc4,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
    glUseProgram(0);
	  }
	   if(sh=='b')
	  {
	glUseProgram(p3);
	glUniform3fv(loc7,1,pos);
	glUniform3fv(loc6,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
    glUseProgram(0);
	  }
	    if(sh=='c')
	  {
	glUseProgram(p4);
	glUniform3fv(loc9,1,pos);
	glUniform3fv(loc8,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
    glUseProgram(0);
	  }
		 if(sh=='t')
	  {
	glUseProgram(p5);
	glUniform3fv(loc11,1,pos);
	glUniform3fv(loc10,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
    glUseProgram(0);
	  }
		  if(sh=='m')
	  {
	glUseProgram(p7);
	glUniform3fv(loc13,1,pos);
	glUniform3fv(loc12,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
    glUseProgram(0);
	  }
		    if(sh=='n')
	  {
	glUseProgram(p6);
	glUniform3fv(loc14,1,pos);
	glUniform3fv(loc15,1,cam);
	glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
	glScalef(3.0,3.0,3.0);
	RenderOBJModel (&objfile);
	glPushMatrix();
	glTranslatef(5,-3,1);
	glutSolidSphere(2.5,50,50);
	glPopMatrix();
    glUseProgram(0);
	  }
	//a+=0.11;

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {

	switch (key)
	{
	case's':
		py-=0.5;
		break;
		case'z':
			py+=0.5;
		break;
		case'q':
			px-=0.5;
		break;
		case'd':
			px+=0.5;
		break;
		case'a':
			pz-=0.5;
		break;
		case'e':
			pz+=0.5;
		break;
		case'i':
			camy-=1;
		break;
		case'k':
			camy+=1;
		break;
		case'j':
		camx-=1;
		break;
		case'l':
			camx+=1;
		break;
	}

}
void SpecialKeys(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_F1:
		sh='l';
		break;
		case GLUT_KEY_F2:
			sh='p';
		break;
		case GLUT_KEY_F3:
			sh='b';
		break;
		case GLUT_KEY_F4:
			sh='c';
		break;
		case GLUT_KEY_F5:
			sh='t';
		break;
		case GLUT_KEY_F6:
			sh='n';
		break;
		case GLUT_KEY_F7:
			sh='m';
		break;
		
	}

}
#define printOpenGLError() printOglError(__FILE__, __LINE__)

int printOglError(char *file, int line)
{
    //
    // Returns 1 if an OpenGL error occurred, 0 otherwise.
    //
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    while (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s\n", file, line, gluErrorString(glErr));
        retCode = 1;
        glErr = glGetError();
    }
    return retCode;
}


void printInfoLog(GLhandleARB obj)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;

	glGetObjectParameterivARB(obj, GL_OBJECT_INFO_LOG_LENGTH_ARB,
                                         &infologLength);

    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetInfoLogARB(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
        free(infoLog);
    }
}



void setShaders() {

	char *fs = NULL,*fs2 = NULL,*fs3 = NULL,*fs4 = NULL,*fs5 = NULL,*fs6 = NULL,*fs7 = NULL;
	char *vs = NULL,*vs2 = NULL,*vs3 = NULL,*vs4 = NULL,*vs5 = NULL,*vs6 = NULL,*vs7 = NULL;


	// 1- Lire le fichier contenant le source du shader

	vs = textFileRead("lambert.vert");
	fs = textFileRead("lambert.frag");

	vs2 = textFileRead("phong.vert");
	fs2 = textFileRead("phong.frag");
	vs3 = textFileRead("blinn.vert");
	fs3 = textFileRead("blinn.frag");
	vs4 = textFileRead("cook-torrance.vert");
	fs4 = textFileRead("cook-torrance.frag");
	vs5 = textFileRead("TROW.vert");
	fs5 = textFileRead("TROW.frag");
	vs6 = textFileRead("Oren_Nayar.vert");
	fs6 = textFileRead("Oren_Nayar.frag");
	vs7 = textFileRead("beard_maxwell.vert");
	fs7 = textFileRead("beard_maxwell.frag");
	

	// 2- Créer un objet program
	p = glCreateProgramObjectARB();
	p2 = glCreateProgramObjectARB();
	p3 = glCreateProgramObjectARB();
	p4 = glCreateProgramObjectARB();
	p5 = glCreateProgramObjectARB();
	p6 = glCreateProgramObjectARB();
	p7 = glCreateProgramObjectARB();
	// 3- Créer un objet shader 
	v = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);

	v2 = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f2 = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	v3 = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f3 = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	v4 = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f4 = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	v5 = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f5 = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	v6 = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f6 = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	v7 = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
	f7 = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	// 4- Attacher chaque objet shader à l’objet program
	glAttachObjectARB(p,v);
	glAttachObjectARB(p,f);

	glAttachObjectARB(p2,v2);
	glAttachObjectARB(p2,f2);

	glAttachObjectARB(p3,v3);
	glAttachObjectARB(p3,f3);

	glAttachObjectARB(p4,v4);
	glAttachObjectARB(p4,f4);
	glAttachObjectARB(p5,v5);
	glAttachObjectARB(p5,f5);
	glAttachObjectARB(p6,v6);
	glAttachObjectARB(p6,f6);
	glAttachObjectARB(p7,v7);
	glAttachObjectARB(p7,f7);
    //MessageBoxA(0,"GL_MAX_ARRAY_TEXTURE_LAYERS_EXT=","11",0);
	// 5- Lier le source à chaque objet shader
	const char * vv = vs;
	const char * ff = fs;

	const char * vv2 = vs2;
	const char * ff2 = fs2;

	const char * vv3 = vs3;
	const char * ff3 = fs3;
	const char * vv4 = vs4;
	const char * ff4 = fs4;
	const char * vv5 = vs5;
	const char * ff5 = fs5;
	const char * vv6 = vs6;
	const char * ff6 = fs6;
	const char * vv7 = vs7;
	const char * ff7 = fs7;
	glShaderSourceARB(v, 1, &vv,NULL);
	glShaderSourceARB(f, 1, &ff,NULL);

	glShaderSourceARB(v2, 1, &vv2,NULL);
	glShaderSourceARB(f2, 1, &ff2,NULL);
	
	glShaderSourceARB(v3, 1, &vv3,NULL);
	glShaderSourceARB(f3, 1, &ff3,NULL);
	glShaderSourceARB(v4, 1, &vv4,NULL);
	glShaderSourceARB(f4, 1, &ff4,NULL);
	glShaderSourceARB(v5, 1, &vv5,NULL);
	glShaderSourceARB(f5, 1, &ff5,NULL);
	glShaderSourceARB(v6, 1, &vv6,NULL);
	glShaderSourceARB(f6, 1, &ff6,NULL);
	glShaderSourceARB(v7, 1, &vv7,NULL);
	glShaderSourceARB(f7, 1, &ff7,NULL);
	free(vs);free(fs);

	free(vs2);free(fs2);
	free(vs3);free(fs3);
	free(vs4);free(fs4);
	free(vs5);free(fs5);
	free(vs6);free(fs6);
	free(vs7);free(fs7);
	// 6- Compiler chaque objet shader
	glCompileShaderARB(v);
	glCompileShaderARB(f);
	
	glCompileShaderARB(v2);
	glCompileShaderARB(f2);
	
	glCompileShaderARB(v3);
	glCompileShaderARB(f3);
	
	glCompileShaderARB(v4);
	glCompileShaderARB(f4);
	
	glCompileShaderARB(v5);
	glCompileShaderARB(f5);
	
	glCompileShaderARB(v6);
	glCompileShaderARB(f6);
	
	glCompileShaderARB(v7);
	glCompileShaderARB(f7);
	

	printInfoLog(v);
	printInfoLog(f);

	printInfoLog(v2);
	printInfoLog(f2);
	printInfoLog(v3);
	printInfoLog(f3);
	printInfoLog(v4);
	printInfoLog(f4);
	printInfoLog(v5);
	printInfoLog(f5);
	printInfoLog(v6);
	printInfoLog(f6);
	printInfoLog(v7);
	printInfoLog(f7);

	//7- Lier les objets shaders entre eux dans l’objet program
	glLinkProgramARB(p);
	printInfoLog(p);

	glLinkProgramARB(p2);
	printInfoLog(p2);
	glLinkProgramARB(p3);
	printInfoLog(p3);

	glLinkProgramARB(p4);
	printInfoLog(p4);

	glLinkProgramARB(p5);
	printInfoLog(p5);

	glLinkProgramARB(p6);
	printInfoLog(p6);

	glLinkProgramARB(p7);
	printInfoLog(p7);


	// 8- Sélectionner l’objet program
	glUseProgramObjectARB(p);
	glUseProgramObjectARB(p2);
	glUseProgramObjectARB(p3);
	glUseProgramObjectARB(p4);
	glUseProgramObjectARB(p5);
	glUseProgramObjectARB(p6);
	glUseProgramObjectARB(p7);

	// 9- Lier les variables uniform et attribute venant de l’application à l’objet program
	//loc = glGetUniformLocationARB(p,"Ld");
	loc2 = glGetUniformLocation(p,"camera");
	loc3 = glGetUniformLocation(p,"position");
	loc4 = glGetUniformLocation(p2,"camera");
	loc5 = glGetUniformLocation(p2,"position");
	loc6 = glGetUniformLocation(p3,"camera");
	loc7 = glGetUniformLocation(p3,"position");
	loc8 = glGetUniformLocation(p4,"camera");
	loc9 = glGetUniformLocation(p4,"position");
	loc10 = glGetUniformLocation(p5,"camera");
	loc11 = glGetUniformLocation(p5,"position");
	loc12 = glGetUniformLocation(p6,"camera");
	loc13 = glGetUniformLocation(p6,"position");
	loc14 = glGetUniformLocation(p7,"camera");
	loc15 = glGetUniformLocation(p7,"position");
glUseProgram(0);
glUseProgram(0);
glUseProgram(0);
glUseProgram(0);
glUseProgram(0);
glUseProgram(0);
glUseProgram(0);
}




int main(int argc, char **argv) {
	initobj ("model\\BunnyUp.obj");
	printf("F1||lambert\n");
	printf("F2||phong\n");
	printf("F3||blinn\n");
	printf("F4||cook-torrance\n");
	printf("F5||Torrance-Sparrow\n");
	printf("F6||Oren_Nayar\n");
	printf("F7||Beard-Maxwell\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(680,480);
	glutCreateWindow("Premier Shader");

	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(SpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
//	glEnable(GL_CULL_FACE);

	glewInit();
	if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
		printf("Ready for GLSL\n");
	else {
		printf("No GLSL support\n");
		exit(1);
	}

	setShaders();

	glutMainLoop();

	return 0;
}

