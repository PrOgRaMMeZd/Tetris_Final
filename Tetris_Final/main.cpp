//
//  main.cpp
//  Tetris_Final
//
//  Created by Данила Дудин on 14.12.2019.
//  Copyright © 2019 Данила Дудин. All rights reserved.
//
#define GL_SILENCE_DEPRECATION
#include "painter.hpp"
#include "game.hpp"
#include <GLUT/GLUT.h>
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;





//GLuint  textura_id;
//struct textura_struct
//{
//int W;
//int H;
//unsigned char *Image;
//}get_textura;
//
//int LoadTexture( char *FileName)
//{
//  FILE *F;
//  /* Открываем файл */
//  if ((F = fopen(FileName, "rb")) == NULL)
//    return 0;
//  /*Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну */
//  fseek(F, 18, SEEK_SET);
//  fread(&(get_textura.W), 2, 1, F);
//  fseek(F, 2, SEEK_CUR); те же безуспешные попытки(((((
//  fread(&(get_textura.H), 2, 1, F);
//
//  printf("%d x %d\n", get_textura.W, get_textura.H);
//
//  /* Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой */
//  if ((get_textura.Image = (unsigned char *) malloc(sizeof(unsigned char)*3*get_textura.W * get_textura.H)) == NULL)
//  {
//    fclose(F);
//    return 0;
//  }
//  /* Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя */
//  fseek(F, 30, SEEK_CUR);
//  fread(get_textura.Image, 3, get_textura.W * get_textura.H, F);
//
//  glGenTextures(1, &textura_id);
//  glBindTexture(GL_TEXTURE_2D, textura_id);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, get_textura.W, get_textura.H, GL_RGB, GL_UNSIGNED_BYTE, get_textura.Image);
//  free(get_textura.Image);
//  fclose(F);
//
//  return 1;
//}



Game game;
int mainwindow,subwindow;
bool PAUSE=true;
char res[9]={0};
int n=500,i=0;


void glutMotionFunc(void (*func) (int x,int y));
void glutPassiveMotionFunc(void (*func) (int x, int y));
void glutEntryFunc(void (*func)(int state));
void mouse_entered(int state){
    if (state==GLUT_ENTERED)
        PAUSE=false;
    else
        PAUSE=true;
}


void renderBitmapString(float x, float y, void *font, char *string)
{ // Помещает строку в указанном месте с указанным шрифтом и содержимым
    char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void *font = GLUT_BITMAP_TIMES_ROMAN_24;


void display()
{
    //    if (PAUSE){
    glutSetWindow(mainwindow);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Painter p;
    game.draw(p);
    glutSwapBuffers();
    //    }
    //    else{
    //        glutSetWindow(mainwindow);
    //        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //        glutSwapBuffers();
    //    }
}
void subdisplay(){
    glutSetWindow(subwindow);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    sprintf(res,"%lld", game.SCORE*i);
    renderBitmapString(0.75, 0.99, (void *)font ,"Tetris Game");
    renderBitmapString(0.3, 0.25 ,(void *)font, "Choose Difficulty mode 1, 2, 3, 4, 5");
    renderBitmapString(-0.9, 0.25, (void *)font ,"SCORE");
    renderBitmapString(-0.55, 0.25, (void *)font ,res);
    if (PAUSE==true)
        renderBitmapString(-0.9,0.99,(void *)font,"PAUSED");
    glutSwapBuffers();
}

void displaygameover(){
    glutSetWindow(mainwindow);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_TEXTURE_2D);
//      glBindTexture(GL_TEXTURE_2D, textura_id);
//         glBegin(GL_QUADS);
//           glTexCoord2d(0,0); glVertex2d(-35,-35 );
//           glTexCoord2d(0,1); glVertex2d(-35, 35 ); безутешные попытки засунуть фотографию в GLUT(((((
//           glTexCoord2d(1,1); glVertex2d( 35, 35 );
//           glTexCoord2d(1,0); glVertex2d( 35,-35 );
//         glEnd();
//    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void subdisplaygameover(){
    glutSetWindow(subwindow);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    sprintf(res,"%lld", game.SCORE*i);
    renderBitmapString(0.75, 0.99, (void *)font ,"GAME OVER");
    renderBitmapString(0.3, 0.25 ,(void *)font, "PRESS F2 TO RESTART OR F1 TO EXIT");
    renderBitmapString(-0.9, 0.25, (void *)font ,"SCORE");
    renderBitmapString(-0.55, 0.25, (void *)font ,res);
    if (PAUSE==true)
        renderBitmapString(-0.9,0.99,(void *)font,"PAUSED");
    glutSwapBuffers();
}


void displayPAUSE(){
    glutSetWindow(mainwindow);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}


void timer(int n)
{
    if (!PAUSE && game.gameover==false){
        game.tick();
        display();
        subdisplay();
        glutTimerFunc(n, timer, n);
    }
    else if (PAUSE && game.gameover==false){
        displayPAUSE();
        subdisplay();
        glutTimerFunc(n, timer, n);
    }
    else if (PAUSE && game.gameover)
    {
        displaygameover();
        subdisplaygameover();
        glutTimerFunc(n, timer, n);
    }
    else if (!PAUSE && game.gameover)
    {
        displaygameover();
        subdisplaygameover();
        glutTimerFunc(n, timer, n);
    }
}

void keyEvent(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            game.keyEvent(Game::LEFT);
            break;
        case GLUT_KEY_RIGHT:
            game.keyEvent(Game::RIGHT);
            break;
        case GLUT_KEY_UP:
            game.keyEvent(Game::UP);
            break;
        case GLUT_KEY_DOWN:
            game.keyEvent(Game::DOWN);
            break;
        case GLUT_KEY_F1:
            exit(0);
        case GLUT_KEY_F2:
            game.restart();
            game.gameover=false;
            game.SCORE=0;
            //        case GLUT_KEY_F1:
            //            n=2000;
            //        case GLUT_KEY_F2:
            //            n=750;
            //        case GLUT_KEY_F4:
            //            n=250;
            //        case GLUT_KEY_F5:
            //            n=100;
    }
    display();
}
void normalkeyEvent(unsigned char key, int x, int y){
    if (key==27){
        if (PAUSE==true)
            PAUSE=false;
        else
            PAUSE=true;
    }
}


int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Russian");
    cout<<"Choose difficulty mode from 1 to 5"<<endl;
    cin>>i;
    if (i==1)
        n=2000;
    else if (i==2)
        n=750;
    else if (i==3)
        n=500;
    else if (i==4)
        n=250;
    else if (i==5)
        n=100;
    else if (i!=1 && i!=2 && i!=3 && i!=4 && i!=5){
        cout<<"Choose difficulty mode from 1 to 5, please"<<endl;
        cin>>i;
        if (i==1)
            n=1000;
        else if (i==2)
            n=750;
        else if (i==3)
            n=500;
        else if (i==4)
            n=250;
        else if (i==5)
            n=1000;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(Well::WIDTH *48, Well::HEIGHT *48);
    glutInitWindowPosition(0, 0);
    mainwindow = glutCreateWindow("Tetris");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Well::WIDTH * 8,
            Well::HEIGHT * 8, 0,
            -1.0, 1.0);
    glutDisplayFunc(display);
    display();
    glutKeyboardFunc(normalkeyEvent);
    glutSpecialFunc(keyEvent);
    //    glutMouseFunc(mouseButton);
    //    glutMotionFunc(mouseMove);
    glutEntryFunc(mouse_entered);
//    if(LoadTexture((char *)"image.bmp") != 1){printf("Не удалось загрузить изображение\n");}
    subwindow = glutCreateSubWindow(mainwindow, 0, 0,Well::WIDTH *48, Well::WIDTH *8);
    glutDisplayFunc(subdisplay);
    //    glutMouseFunc(mouseButton);
    //    glutMotionFunc(mouseMove);
    glutEntryFunc(mouse_entered);
    glutSpecialFunc(keyEvent);
    glutKeyboardFunc(normalkeyEvent);
    glutTimerFunc(n, timer, n);
    glutMainLoop();
}
//ну а теперь как это работает
//выбираем сложность
// пока курсор не находится внутри окна игра автоматически останавливается на паузу
// SCORE отображает очки (10*уровень усложности)
// а теперь попробуем проиграть
//Здесь должна была стоять прекрасная пикча но GLUT староват для таких подвигов (или я недостаточно умен)
//представим что получилось )))
//чтобы начать заново жмякаем F2
//чтобы выйти F1
//чтобы поставить/снять на паузу без курсора esc
//жмякаем F1 и выходим
