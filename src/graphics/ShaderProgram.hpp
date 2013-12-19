#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <GL/glew.h>
#include <GlErrorCheck.hpp>

#include <glm/glm.hpp>
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat2;
using glm::mat3;
using glm::mat4;

#include <string>
using std::string;

namespace Rigid3D {

    /**
     * A \c ShaderProgram encapsulates the compilation, linkage, and usage of both a
     * vertex shader and fragment shader with respect to a single OpenGL program
     * object.
     *
     * The goal of the \c ShaderProgram class is to make loading and using shader
     * programs as painless as possible.
     *
     * Example usage:
     *
     * \code{.cpp}
     *  ShaderProgram shaderProgram;
     *  shaderProgram.loadFromFile("verexShaderFile", "fragmentShaderFile");
     *
     *  shaderProgram.begin();  // calls glUseProgram(...)
     *   ... glDraw*();
     *  shaderProgram.end();    // calls glUseProgram(NULL)
     * \endcode
     */
    class ShaderProgram {
    public:
        ShaderProgram();

        ShaderProgram(const char * ShaderFile, const char * fragmentShaderFile);

        ~ShaderProgram();

        void loadFromFile(const char * vertexShaderFile, const char * fragmentShaderFile);

        void enable();

        void disable();

        GLuint getProgramObject() const;

        GLint getUniformLocation(const char * uniformName) const;

        GLint getAttribLocation(const char * attributeName) const;

        void setUniform(const char * uniformName, bool b);

        void setUniform(const char * uniformName, int i);

        void setUniform(const char * uniformName, unsigned int i);

        void setUniform(const char * uniformName, float f);

        void setUniform(const char * uniformName, float x, float y);

        void setUniform(const char * uniformName, float x, float y, float z);

        void setUniform(const char * uniformName, float x, float y, float z, float w);

        void setUniform(const char * uniformName, const vec2 & v);

        void setUniform(const char * uniformName, const vec3 & v);

        void setUniform(const char * uniformName, const vec4 & v);

        void setUniform(const char * uniformName, const mat2 & m);

        void setUniform(const char * uniformName, const mat3 & m);

        void setUniform(const char * uniformName, const mat4 & m);

        void setUniformSubroutine(GLenum shaderType, const char * subroutineName);


    private:
        struct Shader {
            string sourceCode;
            GLuint shaderObject;
        };

        Shader vertexShader;
        Shader fragmentShader;
        GLuint programObject;
        GLuint prevProgramObject;
        GLuint activeProgram;

        void extractSourceCode(const char * sourceFileName, Shader &shader);

        void createShader(GLenum shaderType);

        void compileShader(const Shader &shader);

        void checkCompilationStatus(const Shader &shader);

        void createShaderProgram();

        void checkLinkStatus();

        void cleanUpResources();

        void deleteShaders();

    };

} // end namespace GlUtils

#endif /* SHADER_HPP_ */