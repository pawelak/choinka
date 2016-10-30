
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
		glPointSize(4); // wielkoœæ punktu
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
	// Czyszczenie okna aktualnym kolorem czyszcz¹cym

	glColor3f(0.0f, 1.0f, 0.0f);
	// Ustawienie aktualnego koloru rysowania na zielony

	makeTree(400, -500, ile);

	glFlush();
	// Przekazanie poleceñ rysuj¹cych do wykonania
}


void MyInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
}


void ChangeSize(GLsizei horizontal, GLsizei vertical)
// Parametry horizontal i vertical (szerokoœæ i wysokoœæ okna) s¹
// przekazywane do funkcji za ka¿dym razem, gdy zmieni siê rozmiar okna
{

	GLfloat AspectRatio;
	// Deklaracja zmiennej AspectRatio okreœlaj¹cej proporcjê wymiarów okna

	if (vertical == 0)
		// Zabezpieczenie pzred dzieleniem przez 0
		vertical = 1;

	glViewport(0, -100, horizontal, vertical);
	// Ustawienie wielkoœciokna okna urz¹dzenia (Viewport)
	// W tym przypadku od (0,0) do (horizontal, vertical)

	glMatrixMode(GL_PROJECTION);
	// Okreœlenie uk³adu wspó³rzêdnych obserwatora
	glLoadIdentity();
	// Okreœlenie przestrzeni ograniczaj¹cej
	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;

	// Wyznaczenie wspó³czynnika proporcji okna
	// Gdy okno na ekranie nie jest kwadratem wymagane jest 
	// okreœlenie okna obserwatora. 
	// Pozwala to zachowaæ w³aœciwe proporcje rysowanego obiektu
	// Do okreœlenia okna obserwatora s³u¿y funkcja glOrtho(...)

	if (horizontal <= vertical)
		glOrtho(-50.0, 50.0, -50.0 / AspectRatio, 50.0 / AspectRatio, 1.0, -1.0);
	else
	{
		glViewport(0, -200, horizontal, vertical);
		glOrtho(-50.0*AspectRatio, 50.0*AspectRatio, -50.0, 50.0, 1.0, -1.0);
	}
		
	glMatrixMode(GL_MODELVIEW);
	// Okreœlenie uk³adu wspó³rzêdnych    
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
	// Ustawienie trybu wyœwietlania
	// GLUT_SINGLE - pojedynczy bufor wyœwietlania
	// GLUT_RGBA - model kolorów RGB

	glutCreateWindow("zadanie domowe - choinka");
	// Utworzenie okna i okreœlenie treœci napisu w nag³ówku okna

	glutDisplayFunc(RenderScene);
	// Okreœlenie, ¿e funkcja RenderScene bêdzie funkcj¹ zwrotn¹ (callback)
	// Biblioteka GLUT bêdzie wywo³ywa³a t¹ funkcjê za ka¿dym razem, gdy
	// trzeba bêdzie przerysowaæ okno


	//glutReshapeFunc(ChangeSize);
	//ChangeSize(1000, 1000);
	// Dla aktualnego okna ustala funkcjê zwrotn¹ odpowiedzialn¹ za
	// zmiany rozmiaru okna

	MyInit();
	// Funkcja MyInit (zdefiniowana powy¿ej) wykonuje wszelkie  
	// inicjalizacje konieczneprzed przyst¹pieniem do renderowania


	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT
}
/*************************************************************************************/