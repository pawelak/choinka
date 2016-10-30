
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <vector>
#include <iostream>

using namespace std;



int ile = 10000;
vector <float> help;
vector <vector<float>> tab;


void makeTree(float x, float y, int ile)
{

	if (ile > 0)
	{
		glBegin(GL_POINTS);
		glPointSize(4); // wielko�� punktu
		for (int i = 0; i < ile; i++)
		{
			glVertex2f(x, y);
			int a = rand() % 3;
			//glColor3f(((rand() % 100)*0.01), ((rand() % 100)*0.01), ((rand() % 100)*0.01));
			glColor3f(0, 1, 0);
			x = tab[a][0] * x + tab[a][1] * y + tab[a][2];
			y = tab[a][3] * x + tab[a][4] * y + tab[a][5];
		}

		glEnd();
	}
}

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszcz�cym

	glColor3f(0.0f, 1.0f, 0.0f);
	// Ustawienie aktualnego koloru rysowania na zielony

	makeTree(400, -500, ile);

	glFlush();
	// Przekazanie polece� rysuj�cych do wykonania
}


void MyInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
}


void ChangeSize(GLsizei horizontal, GLsizei vertical)
// Parametry horizontal i vertical (szeroko�� i wysoko�� okna) s�
// przekazywane do funkcji za ka�dym razem, gdy zmieni si� rozmiar okna
{

	GLfloat AspectRatio;
	// Deklaracja zmiennej AspectRatio okre�laj�cej proporcj� wymiar�w okna

	if (vertical == 0)
		// Zabezpieczenie pzred dzieleniem przez 0
		vertical = 1;

	glViewport(0, -100, horizontal, vertical);
	// Ustawienie wielko�ciokna okna urz�dzenia (Viewport)
	// W tym przypadku od (0,0) do (horizontal, vertical)

	glMatrixMode(GL_PROJECTION);
	// Okre�lenie uk�adu wsp�rz�dnych obserwatora
	glLoadIdentity();
	// Okre�lenie przestrzeni ograniczaj�cej
	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;

	// Wyznaczenie wsp�czynnika proporcji okna
	// Gdy okno na ekranie nie jest kwadratem wymagane jest 
	// okre�lenie okna obserwatora. 
	// Pozwala to zachowa� w�a�ciwe proporcje rysowanego obiektu
	// Do okre�lenia okna obserwatora s�u�y funkcja glOrtho(...)

	if (horizontal <= vertical)
		glOrtho(-50.0, 50.0, -50.0 / AspectRatio, 50.0 / AspectRatio, 1.0, -1.0);
	else
	{
		glViewport(0, -200, horizontal, vertical);
		glOrtho(-50.0*AspectRatio, 50.0*AspectRatio, -50.0, 50.0, 1.0, -1.0);
	}
		
	glMatrixMode(GL_MODELVIEW);
	// Okre�lenie uk�adu wsp�rz�dnych    
	glLoadIdentity();
}


void main(void)
{


	help.push_back(-0.67);
	help.push_back(-0.02);
	help.push_back(0.00);
	help.push_back(-0.18);
	help.push_back(0.81);
	help.push_back(10.00);
	tab.push_back(help);
	help.clear();
	help.push_back(0.40);
	help.push_back(0.40);
	help.push_back(0.00);
	help.push_back(-0.10);
	help.push_back(0.40);
	help.push_back(0.00);
	tab.push_back(help);
	help.clear();
	help.push_back(-0.40);
	help.push_back(-0.40);
	help.push_back(0.00);
	help.push_back(-0.10);
	help.push_back(0.40);
	help.push_back(0.00);
	tab.push_back(help);
	help.clear();
	help.push_back(-0.10);
	help.push_back(0.00);
	help.push_back(0.00);
	help.push_back(0.40);
	help.push_back(0.40);
	help.push_back(-2.00);
	tab.push_back(help);
	help.clear();




	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// Ustawienie trybu wy�wietlania
	// GLUT_SINGLE - pojedynczy bufor wy�wietlania
	// GLUT_RGBA - model kolor�w RGB

	glutCreateWindow("zadanie domowe - choinka");
	// Utworzenie okna i okre�lenie tre�ci napisu w nag��wku okna

	glutDisplayFunc(RenderScene);
	// Okre�lenie, �e funkcja RenderScene b�dzie funkcj� zwrotn� (callback)
	// Biblioteka GLUT b�dzie wywo�ywa�a t� funkcj� za ka�dym razem, gdy
	// trzeba b�dzie przerysowa� okno


	//glutReshapeFunc(ChangeSize);
	//ChangeSize(1000, 1000);
	// Dla aktualnego okna ustala funkcj� zwrotn� odpowiedzialn� za
	// zmiany rozmiaru okna

	MyInit();
	// Funkcja MyInit (zdefiniowana powy�ej) wykonuje wszelkie  
	// inicjalizacje konieczneprzed przyst�pieniem do renderowania


	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT
}
/*************************************************************************************/