#include <iostream>
#include <glew.h>
#include <glfw3.h>
#include "Camera.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ShaderSource.h"
#include "shader.h"
#include "vertexSource/RectangleData.h"
#include "vertexSource/AimData.h"
#include <random>

using namespace std;
using namespace glm;

// window setting variable
GLFWwindow* window;
GLuint WIDTH=800, HEIGHT=600;
bool keys[1024];

// vertex setting variable
GLuint VBO, EBO;
GLint color_location, vertex_location, texture_location;
GLuint texture;

// light setting variable
GLuint lightVAO;
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

// camera setting veriable
Camera camera(vec3(0.0f, 0.0f, 5.0f));
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool firstMouse=true;

// game set
bool isHint = false;
vec3 boxCenter = vec3(0.0f, 0.0f, 0.0f);
float boxLength = 1.0f;
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
};

// set random device
random_device rd;
mt19937 gen(rd());
int minValue = 1; // 最小值
int maxValue = 10; // 最大值
uniform_int_distribution<int> distribution(minValue, maxValue);

void init_window();
void init_vertex();
void init_texture();
void move_camera();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
bool rayInrayIntersectsBoundingBox(vec3 rayStart, vec3 rayDirection, vec3 minPoint, vec3 maxPoint);

int main() {
    init_window();
    Shader shader("/Users/chengxinwu/CLionProjects/OpenGL/ShootingGame/vertexShader/triangleVertex.vs", "/Users/chengxinwu/CLionProjects/OpenGL/ShootingGame/fragmentShader/triangleFrag.frag");
    Shader aimShader("/Users/chengxinwu/CLionProjects/OpenGL/ShootingGame/vertexShader/aimVertex.vs", "/Users/chengxinwu/CLionProjects/OpenGL/ShootingGame/fragmentShader/aimFrag.frag");
    init_vertex();
    init_texture();
    mat4 model;

    while (!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // set aim
        aimShader.use();

        GLint aim_location = glGetAttribLocation(aimShader.Program, "position");
        glVertexAttribPointer(aim_location, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), aimVertices);
        glEnableVertexAttribArray(aim_location);

        glDrawArrays(GL_LINES, 0, 4);

        glBindTexture(GL_TEXTURE_2D, texture);
        shader.use();
        vec3 minPoint = boxCenter - glm::vec3(boxLength / 2.0f);
        vec3 maxPoint = boxCenter + glm::vec3(boxLength / 2.0f);
//        move_camera();
        // Create transformations
        mat4 view;
        mat4 projection;
        if (rayInrayIntersectsBoundingBox(camera.Position, cameraFront, minPoint, maxPoint) and isHint)
        {
            int randomInt = distribution(gen);
            mat4 model2;
            model2 = glm::translate(model2, cubePositions[randomInt]);
            model = model2;
            boxCenter = vec3(0.0f, 0.0f, 0.0f) + cubePositions[randomInt];
        }
        view = camera.GetViewMatrix();
        projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 10000.0f);
        GLint modelLoc = glGetUniformLocation(shader.Program, "model");
        GLint viewLoc = glGetUniformLocation(shader.Program, "view");
        GLint projLoc = glGetUniformLocation(shader.Program, "projection");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // Set value for all varialbe in vertex shader
        color_location = glGetAttribLocation(shader.Program, "color");
        vertex_location = glGetAttribLocation(shader.Program, "position");
        texture_location = glGetAttribLocation(shader.Program, "texCoord");
        glVertexAttribPointer(color_location, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), vertices_color);
        glEnableVertexAttribArray(color_location);
        glVertexAttribPointer(vertex_location, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), vertices);
        glEnableVertexAttribArray(vertex_location);
        glVertexAttribPointer(texture_location, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), vertices_tex);
        glEnableVertexAttribArray(texture_location);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void init_window()
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create Window
    window = glfwCreateWindow(WIDTH, HEIGHT, "LIGHT", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // Set require call back function
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSwapInterval(1);

    glewInit();

    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);

}

void init_vertex()
{
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(aimVertices), aimVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void init_texture()
{
    // init image
    int width, height, nrChannels;
    unsigned char* image = stbi_load("/Users/chengxinwu/CLionProjects/OpenGL/ShootingGame/resources/container.jpg", &width, &height, &nrChannels,0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void move_camera()
{
    if(keys[GLFW_KEY_W])
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if(keys[GLFW_KEY_S])
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if(keys[GLFW_KEY_A])
        camera.ProcessKeyboard(LEFT, deltaTime);
    if(keys[GLFW_KEY_D])
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    //如果按下ESC，把windowShouldClose设置为True，外面的循环会关闭应用
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
    if (key == GLFW_KEY_SPACE){
        if (action == GLFW_PRESS)
        {
            isHint = true;
        }
        else if (action == GLFW_RELEASE)
        {
            isHint = false;
        }
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
    cameraFront = camera.Front;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}

bool rayInrayIntersectsBoundingBox(vec3 rayStart, vec3 rayDirection, vec3 minPoint, vec3 maxPoint)
{
    glm::vec3 tmin = (minPoint - rayStart) / rayDirection;
    glm::vec3 tmax = (maxPoint - rayStart) / rayDirection;

    glm::vec3 t1 = glm::min(tmin, tmax);
    glm::vec3 t2 = glm::max(tmin, tmax);

    float tminMax = glm::max(glm::max(t1.x, t1.y), t1.z);
    float tmaxMin = glm::min(glm::min(t2.x, t2.y), t2.z);

    if (tminMax <= tmaxMin) {
        return true;
    }
    return false;
}
