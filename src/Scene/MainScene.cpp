#include <iostream>
#include <cmath>

#include "MainScene.h"

#define PI 3.14159265358


float DegreeToRadian(float degree) {
    return degree / 180.0 * PI;
}
namespace CG
{
    MainScene::MainScene()
    {
        p0c = { 1.0, 0.0, 0.0 };
        p1c = { 1.0, 0.0, 0.0 };
        p2c = { 1.0, 0.0, 0.0 };
        
        float ro = 1.0;
        float ri = ro * sin(DegreeToRadian(18.0)) / sin(DegreeToRadian(54.0));

        for (int i = 0; i < 10; i += 2) {
            px[i] = cos(DegreeToRadian(36.0 * i + 18.0)); py[i] = sin(DegreeToRadian(36.0 * i + 18.0));
            px[i + 1] = ri * cos(DegreeToRadian(36.0 * i + 54.0)); py[i + 1] = ri * sin(DegreeToRadian(36.0 * i + 54.0));
        }
    }

    MainScene::~MainScene()
    {
    }

    auto MainScene::Initialize() -> bool
    {
        glEnable(GL_DEPTH_TEST);
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
        
        return true;
    }

    void MainScene::Update(double dt)
    {

    }

    void MainScene::Render()
    {
        glClearColor(0.0, 0.0, 0.0, 1); // Black background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPolygonMode(GL_FRONT_AND_BACK, mode);
        glLoadIdentity();
        glPushMatrix();
        
        glTranslatef(xOffset, yOffset, 0.0f);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
        // Start drawing triangles in counter-clockwise (ccw) order
        glBegin(GL_TRIANGLES);

        // Right Up
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[0], py[0]);
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[1], py[1]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[9], py[9]);

        // Up
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[1], py[1]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[2], py[2]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[3], py[3]);

        // Left Up
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[3], py[3]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[4], py[4]);
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[5], py[5]);
        
        // Left Down
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[5], py[5]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[6], py[6]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[7], py[7]);

        // Right Down
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[8], py[8]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[9], py[9]);

        // Mid Left
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[3], py[3]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[5], py[5]);

        // Mid Up
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[1], py[1]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[3], py[3]);

        //Mid Right
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[9], py[9]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[1], py[1]);
         

        //// P0
        //glColor3f(p0c[0], p0c[1], p0c[2]);
        //glVertex2f(-0.5, -0.5);

        //// P1
        //glColor3f(p1c[0], p1c[1], p1c[2]);
        //glVertex2f(0.5, -0.5);

        //// P2
        //glColor3f(p2c[0], p2c[1], p2c[2]);
        //glVertex2f(0, 0.5);

        // End drawing triangles
        glEnd();
        rotation += rotationSpeed;
    }

    void MainScene::OnResize(int width, int height)
    {
        std::cout << "MainScene Resize: " << width << " " << height << std::endl;
    }

    void MainScene::OnKeyboard(int key, int action)
    {
        std::cout << "MainScene OnKeyboard: " << key << " " << action << std::endl;

        if (action == GLFW_RELEASE)
        {
            switch (key)
            {
            case GLFW_KEY_1: // Red
                p0c = { 1.0, 0.0, 0.0 };
                p1c = { 1.0, 0.0, 0.0 };
                p2c = { 1.0, 0.0, 0.0 };
                break;
            case GLFW_KEY_2: // Green
                p0c = { 0.0, 1.0, 0.0 };
                p1c = { 0.0, 1.0, 0.0 };
                p2c = { 0.0, 1.0, 0.0 };
                break;
            case GLFW_KEY_3: // Blue
                p0c = { 0.0, 0.0, 1.0 };
                p1c = { 0.0, 0.0, 1.0 };
                p2c = { 0.0, 0.0, 1.0 };
                break;
            case GLFW_KEY_4: // Rainbow
                p0c = { 1.0, 0.0, 0.0 };
                p1c = { 0.0, 1.0, 0.0 };
                p2c = { 0.0, 0.0, 1.0 };
                break;
            case GLFW_KEY_DOWN:
                yOffset -= 0.1;
                break;
            case GLFW_KEY_UP:
                yOffset += 0.1;
                break;
            case GLFW_KEY_LEFT:
                xOffset -= 0.1;
                break;
            case GLFW_KEY_RIGHT:
                xOffset += 0.1;
                break;
            case GLFW_KEY_RIGHT_SHIFT:
                rotationSpeed += 0.1;
                break;
            case GLFW_KEY_LEFT_SHIFT:
                rotationSpeed -= 0.1;
                break;
            }
        }
    }

    void MainScene::SetMode(int mode)
    {
        switch (mode)
        {
        case 0:
            this->mode = GL_FILL;
            break;
        case 1:
            this->mode = GL_LINE;
            break;
        default:
            this->mode = GL_FILL;
            break;
        }
    }
}