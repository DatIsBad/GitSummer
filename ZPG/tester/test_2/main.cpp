//----------------------------------------------- *
//Nejdříve budeme potřebovat inicializovat knihovnu GLEW (můžete využít ukázku z minulého cvičení), include knihovny GLEW použijte před knihovnou GLFW.

//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>


//-----------------------------------------------
//Dále budeme potřebovat pole vrcholů, které bude definovat náš model 
//(trojúhelník) a shadery (vertex a fragment).

float points[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

const char* vertex_shader =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "void main () {"
    "     gl_Position = vec4 (vp, 1.0);"
    "}";

 

const char* fragment_shader =
    "#version 330\n"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
    "}";


//-----------------------------------------------
//Upravte main tak, aby jste inicializovali moderní OpenGL (3.3+).

GLFWwindow* window;
glfwSetErrorCallback(error_callback);
if (!glfwInit()) {
    fprintf(stderr, "ERROR: could not start GLFW3\n");
    exit(EXIT_FAILURE);
}

/* //inicializace konkretni verze
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
glfwWindowHint(GLFW_OPENGL_PROFILE,
GLFW_OPENGL_CORE_PROFILE);  //*/

window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
if (!window){
    glfwTerminate();
    exit(EXIT_FAILURE);
}

glfwMakeContextCurrent(window);
glfwSwapInterval(1);

// start GLEW extension handler
glewExperimental = GL_TRUE;
glewInit();


// get version info
printf("OpenGL Version: %s\n",glGetString(GL_VERSION));
printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
printf("Vendor %s\n", glGetString(GL_VENDOR));
printf("Renderer %s\n", glGetString(GL_RENDERER));
printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
int major, minor, revision;
glfwGetVersion(&major, &minor, &revision);
printf("Using GLFW %i.%i.%i\n", major, minor, revision);

int width, height;
glfwGetFramebufferSize(window, &width, &height);
float ratio = width / (float)height;
glViewport(0, 0, width, height);


//----------------------------------------------- *
//Vytvořte VBO (buffer objekt), což je blok paměti s daty a VAO (vertex array) pro následné vykreslování modelu.

//vertex buffer object (VBO)
GLuint VBO = 0;
glGenBuffers(1, &VBO); // generate the VBO
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW);

//Vertex Array Object (VAO)
GLuint VAO = 0;
glGenVertexArrays(1, &VAO); //generate the VAO
glBindVertexArray(VAO); //bind the VAO
glEnableVertexAttribArray(0); //enable vertex attributes
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


//-----------------------------------------------
//Vytvořte vertex a fragment shader a následně shader program

//create and compile shaders
GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertex_shader, NULL);
glCompileShader(vertexShader);
GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
glCompileShader(fragmentShader);
GLuint shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, fragmentShader);
glAttachShader(shaderProgram, vertexShader);
glLinkProgram(shaderProgram);


//-----------------------------------------------
//Upravte vykreslovací smyčku tak aby jste trojúhelník vykreslili

    while (!glfwWindowShouldClose(window)){
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        // draw triangles
        glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
        // update other events like input handling
        glfwPollEvents();
        // put the stuff we’ve been drawing onto the display
        glfwSwapBuffers(window);
    }

glfwDestroyWindow(window);
glfwTerminate();
exit(EXIT_SUCCESS);
}


//-----------------------------------------------
//Kontrola kompilace a linkování program shaderu

GLint status;
glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
if (status == GL_FALSE)
{
    GLint infoLogLength;
    glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
    fprintf(stderr, "Linker failure: %s\n", strInfoLog);
    delete[] strInfoLog;
}