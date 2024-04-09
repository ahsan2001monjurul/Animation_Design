#include <windows.h>
#include <GL/glut.h>
#include <cmath>

//----for-fuction------
float carX = 0.0;
float busX = 0.0;
float skyX = 0.0;
float shipX = 0.0;

//-------cloud-color-----------
float red = 0.584;
float green = 0.918;
float blue = 1.0;
int frameCount = 0;
int colorIndex = 0;
float customColors[][3] = {
    {0.02, 0.208, 0.298}, // Custom red, green, blue
    {0.584, 0.918, 1.0}
};

//-------island-color-----------
float red1 = 0.698;
float green1 = 1.0;
float blue1 = 0.404;
int frameCount1 = 0;
int colorIndex1 = 0;
float customColors1[][3] = {
    {0.341, 0.525, 0.157}, // Custom red, green, blue
    {0.698, 1.0, 0.404}
};

//-------river-color-----------
float red2 = 0.286;
float green2 = 0.69;
float blue2 = 0.851;
int frameCount2 = 0;
int colorIndex2 = 0;
float customColors2[][3] = {
    {0.055, 0.471, 0.635}, // Custom red, green, blue
    {0.286,0.69,0.851}
};
//-------sun1-color-----------
float red3 = 0.992;
float green3 = 1.0;
float blue3 = 0.745;
int frameCount3 = 0;
int colorIndex3 = 0;
float customColors3[][3] = {
    {0.973, 0.973, 0.973}, // Custom red, green, blue
    {0.992, 1.0, 0.745}
};
//-------sun2-color-----------
float red32 = 1;
float green32 = 0.922;
float blue32 = 0.4;
int frameCount32 = 0;
int colorIndex32 = 0;
float customColors32[][3] = {
    {0.824, 0.8, 0.8}, // Custom red, green, blue
    {1, 0.922, 0.4}
};
//-------sun3-color-----------
float red33 = 1;
float green33 = 0.871;
float blue33 = 0;
int frameCount33 = 0;
int colorIndex33 = 0;
float customColors33[][3] = {
    {0.729, 0.729, 0.698}, // Custom red, green, blue
    {1, 0.871, 0}
};


/////////////circle-formula////////////////////////////
void drawCircle(float centerX, float centerY, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the circle
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * (float(i) / float(segments));
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}
////////////// Dot-line formula////////////////////////////
void drawDottedLine(float startX, float endX, float y, float gap) {
    glColor3f(1.0, 1.0, 1.0); // White color for the dotted line
    glLineWidth(3.0); // Set line width

    for (float x = startX; x <= endX; x += gap * 2) {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + gap, y);
        glEnd();
    }
}
/////////////traingle-blue//////////////////////////////
void drawTriangleblue(float x, float y) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + 265, y);
    glVertex2f(x + 132.5, y - 115);
    glEnd();
}
/////////////traingle-black//////////////////////////////
void drawTriangle(float x, float y) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + 341, y );
    glVertex2f(x + 170.5, y - 153);
    glEnd();
}

/////////////car-design/////////////////
void car(){
    glPushMatrix();
    glTranslatef(carX, 0.0, 0.0);
    glColor3f(1.0,0.522,0.184);
    glBegin(GL_POLYGON);
      glVertex2i(2328, 1262);
      glVertex2i(2381,1337.63);
      glVertex2i(2689, 1337.31 );
      glVertex2i(2688, 1279.31 );
      glVertex2i(2707, 1267.31);
      glVertex2i(2707, 1211.31 );
      glVertex2i(2688, 1190.31);
      glVertex2i(2687, 1125.31);
      glVertex2i(2158, 1123.31 );
      glVertex2i(2214, 1262.31);
     glEnd();

     glColor3f(1.0,0.804,0.435);
     glBegin(GL_POLYGON);
      glVertex2i(2390, 1320);
      glVertex2i(2515,1320.63);
      glVertex2i(2515, 1263.31 );
      glVertex2i(2348, 1263.31);
     glEnd();

     glColor3f(1.0,0.804,0.435);
     glBegin(GL_POLYGON);
      glVertex2i(2525, 1320);
      glVertex2i(2666,1320.63);
      glVertex2i(2666, 1263.31 );
      glVertex2i(2525, 1263.31);
     glEnd();

     glColor3f(0.0, 0.0, 0.0);
    drawCircle(2275, 1146.76, 50, 50);
    drawCircle(2587, 1146.76, 50, 50);
    glColor3f(0.706, 0.694, 0.761);
    drawCircle(2275, 1146.76, 30, 30);
    drawCircle(2587, 1146.76, 30, 30);
    glPopMatrix();
}
/////////////Bus-design/////////////////
void bus(){
    glPushMatrix();
    glTranslatef(busX, 0.0, 0.0);

   glColor3f(0.561,0.482,0.824);
    glBegin(GL_POLYGON);
      glVertex2i(845, 1320);
      glVertex2i(984,1163.63);
      glVertex2i(984, 1018.31 );
      glVertex2i(75, 1018.31 );
      glVertex2i(75, 1320.31);
     glEnd();

    glColor3f(0.824,0.792,0.941);
     glBegin(GL_POLYGON);
      glVertex2i(783, 1301);
      glVertex2i(836,1301);
      glVertex2i(928, 1190.31 );
      glVertex2i(782, 1190.31);
     glEnd();

     glColor3f(0.824,0.792,0.941);
     glBegin(GL_POLYGON);
      glVertex2i(761, 1301);
      glVertex2i(761,1190.31);
      glVertex2i(546, 1190.31 );
      glVertex2i(546, 1301);
     glEnd();

      glColor3f(0.824,0.792,0.941);
     glBegin(GL_POLYGON);
      glVertex2i(310, 1301);
      glVertex2i(310,1190.31);
      glVertex2i(103, 1190.31 );
      glVertex2i(103, 1301);
     glEnd();

     glColor3f(0.824,0.792,0.941);
     glBegin(GL_POLYGON);
      glVertex2i(530, 1301);
      glVertex2i(530,1190.31);
      glVertex2i(329, 1190.31 );
      glVertex2i(329, 1301);
     glEnd();


     glColor3f(0.0, 0.0, 0.0);
    drawCircle(200, 1040.76, 50, 50);
    drawCircle(308, 1040.76, 50, 50);
    drawCircle(880, 1040.76, 50, 50);

    glColor3f(0.706, 0.694, 0.761);
    drawCircle(200, 1040.76, 30, 30);
    drawCircle(308, 1040.76, 30, 30);
    drawCircle(880, 1040.76, 30, 30);

    glPopMatrix();
}
/////////////sky-design/////////////////
void sky(){
    glPushMatrix();
    glTranslatef(skyX, 0.0, 0.0);

    glColor3f(1.0, 1.0, 1.0); // Set circle color to white
    drawCircle(390.64, 1789.76, 100, 100);
    drawCircle(276.55, 1740.1, 100, 100);
    drawCircle(383.56, 1724.42, 100, 100);
    drawCircle(505.33, 1739.18, 100, 100);

    glPopMatrix();
}
/////////////ship-design/////////////////
void ship(){
    glPushMatrix();
    glTranslatef(shipX, 0.0, 0.0);

   //ship-body
    glColor3f(1.0,1.0,1.0);
     glBegin(GL_POLYGON);
      glVertex2i(721, 341);
      glVertex2i(895,445);
      glVertex2i(1972, 445.31 );
      glVertex2i(2107, 353.31);
       glVertex2i(1777, 135);
      glVertex2i(773,135);
      glVertex2i(409, 340 );
     glEnd();
   glColor3f(1.0,1.0,1.0);
     glBegin(GL_POLYGON);
      glVertex2i(1100, 519);
      glVertex2i(1767,519);
      glVertex2i(1862, 446 );
      glVertex2i(1007, 446);
     glEnd();
      glColor3f(1.0,1.0,1.0);
     glBegin(GL_POLYGON);
      glVertex2i(1279, 605);
      glVertex2i(1531,605);
      glVertex2i(1628, 520 );
      glVertex2i(1197, 520);
     glEnd();

    //ship-window
    glColor3f(0.302,0.545,0.643);
     glBegin(GL_POLYGON);
      glVertex2i(461, 310);
      glVertex2i(409, 340);
      glVertex2i(696,340);
      glVertex2i(696, 310 );
     glEnd();

      glColor3f(0.302,0.545,0.643);
     glBegin(GL_POLYGON);
      glVertex2i(905, 414);
      glVertex2i(1415, 414);
      glVertex2i(1415,342);
      glVertex2i(772, 342 );
     glEnd();

     glColor3f(0.302,0.545,0.643);
     glBegin(GL_POLYGON);
      glVertex2i(1108, 499);
      glVertex2i(1415, 499);
      glVertex2i(1415,444);
      glVertex2i(1038, 444 );
     glEnd();
     glColor3f(0.302,0.545,0.643);
     glBegin(GL_POLYGON);
      glVertex2i(1291, 588);
      glVertex2i(1520, 588);
      glVertex2i(1600,520);
      glVertex2i(1227, 520 );
     glEnd();

     glColor3f(0.302,0.545,0.643);
     glBegin(GL_POLYGON);
      glVertex2i(1427, 498);
      glVertex2i(1757, 498);
      glVertex2i(1828,444);
      glVertex2i(1428, 444 );
     glEnd();

      glColor3f(0.302,0.545,0.643);
     glBegin(GL_POLYGON);
      glVertex2i(1963, 414);
      glVertex2i(2059, 356);
      glVertex2i(2025,338);
      glVertex2i(1428, 342 );
      glVertex2i(1428, 414 );
     glEnd();
    glPopMatrix();
}
void bridge(){
    //white-border
  glColor3f(1.0,1.0,1.0);
   glBegin(GL_POLYGON);
      glVertex2i(0,1185);
      glVertex2i(2890, 1185);
      glVertex2i(2890, 1171);
      glVertex2i(0,1171);
     glEnd();
//main-road
  glColor3f(0.353,0.404,0.427);
   glBegin(GL_POLYGON);
      glVertex2i(2890, 1171);
      glVertex2i(2890, 970);
      glVertex2i(0,970);
      glVertex2i(0,1171);
     glEnd();
     // middle dotedline
     drawDottedLine(0, 2633, 1078,260);
//white-border-2
  glColor3f(1.0,1.0,1.0);
   glBegin(GL_POLYGON);
      glVertex2i(0,970);
      glVertex2i(2890, 970);
      glVertex2i(2890, 957 );
      glVertex2i(0, 957);
     glEnd();
//black-underborder
  glColor3f(0.243,0.314,0.353);
   glBegin(GL_POLYGON);
      glVertex2i(0, 957);
      glVertex2i(2890,957);
      glVertex2i(2890,908);
      glVertex2i(0, 908);
     glEnd();
//Tringale-zig-zag
   glColor3f(0.322,0.341,0.353);
    for (int i = 0; i < 8; ++i) {
        drawTriangle(41 + (i * 400), 910); // Positions the triangles along x-axis
       }
//black-pit
  glColor3f(0.322,0.341,0.353);
   glBegin(GL_POLYGON);
      glVertex2i(0, 792);
      glVertex2i(2890,792);
      glVertex2i(2890,771);
      glVertex2i(0, 771);
     glEnd();
//gray-pit
  glColor3f(0.655,0.671,0.678);
   glBegin(GL_POLYGON);
      glVertex2i(0, 771);
      glVertex2i(2890,771);
      glVertex2i(2890,720);
      glVertex2i(0, 720);
     glEnd();
//pillar-1
  glColor3f(0.831,0.835,0.843);
   glBegin(GL_POLYGON);
      glVertex2i(732, 600);
      glVertex2i(732,412);
      glVertex2i(556,412);
      glVertex2i(556,600);
      glVertex2i(414,722);
      glVertex2i(877,722);
     glEnd();
//pillar-2
  glColor3f(0.831,0.835,0.843);
   glBegin(GL_POLYGON);
      glVertex2i(2256, 600);
      glVertex2i(2256,412);
      glVertex2i(2078,412);
      glVertex2i(2078,600);
      glVertex2i(1935,722);
      glVertex2i(2398,722);
     glEnd();
    //Tringaleblue-zig-zag
    glColor3f(red2,green2,blue2);
    for (int i = 0; i < 8; ++i) {
        drawTriangleblue(78 + (i * 400), 910); // Positions the triangles along x-axis
       }
}
void cloud(){
 ///////////////sky////////////////
     glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
      glVertex2i(0, 1936.63);
      glVertex2i(2890,1936.63);
      glVertex2i(2890, 1295.31 );
      glVertex2i(0, 1295.31);
     glEnd();
}
void island(){
      /////////island-left//////////////
       glColor3f(red1,green1,blue1);
    glBegin(GL_POLYGON);
      glVertex2i(278, 1477.85);
      glVertex2i(440.15,1551.45);
      glVertex2i(578.83, 1459.74);
      glVertex2i(766.40, 1433.75);
      glVertex2i(831.87, 1450.83);
      glVertex2i(1169.74, 1295.18);
      glVertex2i(0, 1295.18);
      glVertex2i(0.81, 1412.39);
      glVertex2i(142, 1588.8);
     glEnd();
       /////////island-right//////////////
       glColor3f(red1,green1,blue1);
    glBegin(GL_POLYGON);
      glVertex2i(2604.35, 1477.85);
      glVertex2i(2444.62,1551.45);
      glVertex2i(2305.17, 1459.74);
      glVertex2i(2117.54, 1433.75);
      glVertex2i(2055.43, 1450.83);
      glVertex2i(1714.41, 1295.18);
      glVertex2i(2890, 1295.18);
      glVertex2i(2890, 1412.39);
      glVertex2i(2743.8, 1588.8);
     glEnd();
}
void sun(){
     /////////////sun///////////////////
    glColor3f(red3,green3,blue3); // Sun circle1
    drawCircle(1431.7, 1291.25, 270, 100);
    glColor3f(red32,green32,blue32); // Sun circle2
    drawCircle(1431.7, 1291.25, 220, 100);
    glColor3f(red33,green33,blue33); // Sun circle3
    drawCircle(1431.7, 1291.25, 150, 100);
}
void river(){
        ///////////////river////////////////
  glColor3f(red2,green2,blue2);
   glBegin(GL_POLYGON);
      glVertex2i(0,0);
      glVertex2i(0, 1295.31);
      glVertex2i(2890, 1295.31 );
      glVertex2i(2890,0);
     glEnd();

}
////////////////////////main draw ////////////////////////////////////
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

//////////////////All-function///////////////
    cloud();
    sun();
    island();
    river();
    bridge();
    sky();
    car();
    bus();
    ship();

    glFlush();
    glutSwapBuffers();

}
void update(int value) {
    carX -= 10; // Move the car to the right
    if (carX < -2900.0) {
        carX = 900;
    }
    busX += 10;
    if (busX > 2900.0) {
        busX = -900;
    }
    skyX += 5;
    if (skyX > 2900.0) {
        skyX = -900;
    }
    shipX -= 5;
    if (shipX < -2900.0) {
        shipX = 2900;
    }
    ////---sky-color----------
    if (frameCount < 300) {
        frameCount++;
        if (frameCount == 300) {
            if (colorIndex < 2) {
                red = customColors[colorIndex][0];
                green = customColors[colorIndex][1];
                blue = customColors[colorIndex][2];
                colorIndex++;
            } else {
                colorIndex = 0; // Reset to start the sequence again
            }
            frameCount = 0; // Reset frame count
        }
    }

    ///-----island-color---------
        if (frameCount1 < 300) {
        frameCount1++;
        if (frameCount1 == 300) {
            if (colorIndex1 < 2) {
                red1 = customColors1[colorIndex1][0];
                green1 = customColors1[colorIndex1][1];
                blue1 = customColors1[colorIndex1][2];
                colorIndex1++;
            } else {
                colorIndex1 = 0;
            }
            frameCount1 = 0;
        }
    }
    ///-----river-color---------
        if (frameCount2 < 300) {
        frameCount2++;
        if (frameCount2 == 300) {
            if (colorIndex2 < 2) {
                red2 = customColors2[colorIndex2][0];
                green2 = customColors2[colorIndex2][1];
                blue2 = customColors2[colorIndex2][2];
                colorIndex2++;
            } else {
                colorIndex2 = 0;
            }
            frameCount2 = 0;
        }
    }

        ///-----sun1-color---------
        if (frameCount3 < 300) {
        frameCount3++;
        if (frameCount3 == 300) {
            if (colorIndex3 < 2) {
                red3 = customColors3[colorIndex3][0];
                green3 = customColors3[colorIndex3][1];
                blue3 = customColors3[colorIndex3][2];
                colorIndex3++;
            } else {
                colorIndex3 = 0;
            }
            frameCount3 = 0;
        }
    }
        ///-----sun2-color---------
        if (frameCount32 < 300) {
        frameCount32++;
        if (frameCount32 == 300) {
            if (colorIndex32 < 2) {
                red32 = customColors32[colorIndex32][0];
                green32 = customColors32[colorIndex32][1];
                blue32 = customColors32[colorIndex32][2];
                colorIndex32++;
            } else {
                colorIndex32 = 0;
            }
            frameCount32 = 0;
        }
    }
            ///-----sun1-color---------
        if (frameCount33 < 300) {
        frameCount33++;
        if (frameCount33 == 300) {
            if (colorIndex33 < 2) {
                red33 = customColors33[colorIndex33][0];
                green33 = customColors33[colorIndex33][1];
                blue33 = customColors33[colorIndex33][2];
                colorIndex33++;
            } else {
                colorIndex33 = 0;
            }
            frameCount33 = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1940, 2890);
    glutCreateWindow("The Iconic Padma Bridge");

    glutDisplayFunc(display);
    //glutDisplayFunc(sky);

    glClearColor(0.0, 0.0, 0.0, 0.0); // Set display window colour to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 2890.0, 0.0, 1940.0);
    glutTimerFunc(0, update, 0);
    glutMainLoop();

    return 0;
}
