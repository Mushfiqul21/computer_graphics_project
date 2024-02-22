#include <GL/glut.h>
#include <cmath>

// Global variables for the position of the car
float carPosX = 0.0f;
float carPosX2 = 0.1f;
float carSpeed = 0.01f; // Reduced car speed

// Function to draw the house
void drawHouse() {
    // Draw house body
    glColor3f(0.7f, 0.5f, 0.5f); // Gray color for the house body
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f); // Bottom left
    glVertex2f(0.5f, -0.5f);  // Bottom right
    glVertex2f(0.5f, 0.4f);   // Top right
    glVertex2f(-0.5f, 0.4f);  // Top left
    glEnd();

    // Draw roof
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray color for the roof
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, 0.4f); // Left point
    glVertex2f(0.6f, 0.4f);  // Right point
    glVertex2f(0.0f, 0.9f);  // Top point
    glEnd();

    // Draw door
    glColor3f(0.8f, 0.7f, 0.3f); // Brown color for the door
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.5f); // Bottom left
    glVertex2f(0.1f, -0.5f);  // Bottom right
    glVertex2f(0.1f, 0.0f);   // Top right
    glVertex2f(-0.1f, 0.0f);  // Top left
    glEnd();
}

// Function to draw a car
void drawCar(float posX, float colorR, float colorG, float colorB) {
   // glColor3f(1.0f, 0.3f, 0.0f); // Orange color for the car
    glColor3f(colorR, colorG, colorB);
    glBegin(GL_QUADS);
    glVertex2f(posX - 0.35f, -0.4f); // Bottom left
    glVertex2f(posX + 0.35f, -0.4f); // Bottom right
    glVertex2f(posX + 0.15f, -0.05f);  // Top right
    glVertex2f(posX - 0.15f, -0.05f);  // Top left
    glEnd();

    // Draw windows
    glColor3f(0.7f, 0.7f, 1.0f); // Light blue color for the windows
    glBegin(GL_QUADS);
    glVertex2f(posX - 0.2f, -0.2f); // Bottom left
    glVertex2f(posX + 0.2f, -0.2f); // Bottom right
    glVertex2f(posX + 0.12f, -0.08f);  // Top right
    glVertex2f(posX - 0.12f, -0.08f);  // Top left
    glEnd();

    // Draw wheels
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color for the wheels
    const float wheelRadius = 0.08f; // Adjust wheel radius
    const float wheelPosY = -0.38f;
    const float wheelOffset = 0.18f;
    const float wheelDist = 0.08f;
    for (int i = -1; i <= 1; i += 2) {
        glBegin(GL_POLYGON);
        for (float angle = 0; angle <= 360; angle += 10) {
            float x = posX + i * wheelOffset + wheelDist * cos(angle * M_PI / 180);
            float y = wheelPosY + wheelDist * sin(angle * M_PI / 180);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

// Function to draw the road
void drawRoad() {
    glColor3f(0.3f, 0.3f, 0.3f); // Gray color for the road
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.3f); // Bottom left
    glVertex2f(1.0f, -0.3f);  // Bottom right
    glVertex2f(1.0f, -0.5f);  // Top right
    glVertex2f(-1.0f, -0.5f); // Top left
    glEnd();
}

// Function to draw the tree
void drawTree(float x, float y, float size) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(size, size, 1.0f);

    // Draw tree leaves
    glColor3f(0.2f, 0.8f, 0.2f); // Green color for the leaves
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.6f);    // Top point
    glVertex2f(0.2f, -0.5f);   // Bottom right
    glVertex2f(-0.2f, -0.5f);  // Bottom left
    glEnd();

    // Draw trunk
    glColor3f(0.6f, 0.3f, 0.0f); // Brown color for the trunk
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.5f); // Bottom left
    glVertex2f(0.05f, -0.5f);  // Bottom right
    glVertex2f(0.05f, -0.6f);  // Top right
    glVertex2f(-0.05f, -0.6f); // Top left
    glEnd();

    glPopMatrix();
}
// Function to draw a sun
void drawSun(float posX, float posY) {
    const int numSegments = 50;
    const float radius = 0.1f;
    glColor3f(1.0f, 1.0f, 0.0f); // White color for the sun
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * M_PI * float(i) / float(numSegments);
        float x = posX + radius * cosf(theta);
        float y = posY + radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}
// Function to draw the grass field
void drawGrassField() {
    glColor3f(0.2f, 0.8f, 0.2f); // Dark green color for the grass
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.5f); // Bottom left
    glVertex2f(1.0f, -0.5f);  // Bottom right
    glVertex2f(1.0f, -1.0f);  // Top right
    glVertex2f(-1.0f, -1.0f); // Top left
    glEnd();
}
// Function to draw clouds
void drawCloud(float posX, float posY) {
    const int numSegments = 50;
    const float radius = 0.08f;
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the clouds
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * M_PI * float(i) / float(numSegments);
        float x = posX + radius * cos(theta);
        float y = posY + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}
// Function to handle window redraw event
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw background color
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Light blue color for the sky
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(-0.6f, 0.85f);
    // Draw clouds
    drawCloud(-0.9f, 0.7f);
    drawCloud(-0.8f, 0.7f);

    drawCloud(-0.2f, 0.8f);
    drawCloud(-0.3f, 0.8f);

    drawCloud(0.4f, 0.7f);
    drawCloud(0.5f, 0.7f);

    drawCloud(0.9f, 0.8f);
    drawCloud(0.8f, 0.8f);

    drawHouse();

    drawRoad();

    drawCar(carPosX, 1.0f, 3.0f, 0.0f);
    drawCar(carPosX2, 1.0f, 0.3f, 0.0f);

    drawTree(-0.7f, 0.0f, 0.5f);
    drawTree(-0.9f, 0.0f, 0.5f);
    drawTree(0.7f, 0.2f, 0.7f);

    drawGrassField();

    glFlush();
}
// Function to handle updates for animation
void update(int value) {
    carPosX += carSpeed; //move first car
    carPosX2 -= carSpeed; // Move the second car in the opposite direction

    if (carPosX > 1.2f)
        carPosX = -1.2f;

    if (carPosX2 < -1.3f)
        carPosX2 = 1.3f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Computer Graphics Project");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D projection

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
