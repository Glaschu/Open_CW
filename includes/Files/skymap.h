#ifndef SKYMAP_H
#define SKYMAP_H

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Files/shader.h>
#include <Files/camera.h>

//#include "Texture.h"

class Skymap
{
public:

	Skymap() {

	}
	void CreateBuffers(GLuint VAO, GLuint VBO) {
		bufferVAO = VAO;
		bufferVBO = VBO;
		glGenVertexArrays(1, &bufferVAO);
		glGenBuffers(1, &bufferVBO);
		glBindVertexArray(bufferVAO);
		glBindBuffer(GL_ARRAY_BUFFER, bufferVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
		glBindVertexArray(0);
	}
	GLuint GetVBO() {
		return bufferVBO;
	}
	GLuint GetVAO() {
		return bufferVAO;
	}
	/*GLuint LoadSkyMap() {
		// Cubemap (Skybox)
		std::vector<const GLchar*> faces;
		faces.push_back("resources/images/skybox/right.tga");
		faces.push_back("resources/images/skybox/left.tga");
		faces.push_back("resources/images/skybox/top.tga");
		faces.push_back("resources/images/skybox/bottom.tga");
		faces.push_back("resources/images/skybox/back.tga");
		faces.push_back("resources/images/skybox/front.tga");
		cubemapTexture = TextureLoading::LoadCubemap(faces);
		return cubemapTexture;
	}
	void SkyboxCreate(Shader Skybox, GLuint VAO, glm::mat4 projection, glm::mat4 view, Camera camera) {
		//glm::mat4 view = camera.GetViewMatrix( );
		glm::mat4 model, model2;

		// Draw skybox as last
		glDepthFunc(GL_LEQUAL);  // Change depth function so depth test passes when values are equal to depth buffer's content
		Skybox.Use();
		view = glm::mat4(glm::mat3(camera.GetViewMatrix()));	// Remove any translation component of the view matrix

		glUniformMatrix4fv(glGetUniformLocation(Skybox.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(Skybox.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		// skybox cube
		glBindVertexArray(VAO);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		glDepthFunc(GL_LESS); // Set depth function back to default
	}*/

private:
	GLuint cubemapTexture;
	std::vector<const GLchar*> faces;
	GLuint bufferVAO, bufferVBO;
	GLfloat skyboxVertices[108] = {
		// Positions
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};
};

#endif