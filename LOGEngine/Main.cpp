#include "Dependencies.h"

#include "Utils.h"
#include "ShaderUtils.h"

 std::vector<Point> vertices = {
    { 0.5f, 0.5f, 0.0f },
    { 0.5f, -0.5f, 0.0f },
    { -0.5f,  -0.5f, 0.0f },
    { -0.5f,  0.5f, 0.0f }
};

 std::vector<GLuint> indices = {
    0, 1, 3,
    1, 2, 3 
 };

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource =
"    #version 330 core \n"
"    out vec4 FragColor; \n"
"\n"
"void main()\n"
"{\n"
"    FragColor = vec4(0.0f,  1.0f, 1.0f, 1.0f);\n"
"}"
;

int main()
{
    GLFWwindow* window = createWindow("LOGEngine");
    GLuint ModelVAO = CreateVertexArrayObject(vertices, indices);
    GLuint shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
    while (!glfwWindowShouldClose(window))
    {
        ClearAllBuffers();
        processInput(window);
        draw(shaderProgram, ModelVAO, indices.size());
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
	return 0;
}