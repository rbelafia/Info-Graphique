#include "./../include/IndexedCubeRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>


IndexedCubeRenderable::IndexedCubeRenderable(ShaderProgramPtr shaderProgram)
  : Renderable(shaderProgram), m_vBuffer(0), m_cBuffer(0), m_iBuffer(0)
{
	// Build the geometry : just a simple triangle for now
	// lol no it's a cube now
	/*
	POINTS
	 */
	m_positions.push_back( glm::vec3(0,0,0));   //0
	m_positions.push_back( glm::vec3(1,0,0));   //1
	m_positions.push_back( glm::vec3(0,1,0));   //2
	m_positions.push_back( glm::vec3(0,0,1));   //3
	m_positions.push_back( glm::vec3(1,1,0));   //4
	m_positions.push_back( glm::vec3(1,0,1));   //5
    	m_positions.push_back( glm::vec3(0,1,1));   //6
    	m_positions.push_back( glm::vec3(1,1,1));   //7

    m_colors.push_back(glm::vec4(0,0,0,1));
    m_colors.push_back(glm::vec4(1,0,0,1));
    m_colors.push_back(glm::vec4(0,1,0,1));
    m_colors.push_back(glm::vec4(0,0,1,1));
    m_colors.push_back(glm::vec4(1,1,0,1));
    m_colors.push_back(glm::vec4(1,0,1,1));
    m_colors.push_back(glm::vec4(0,1,1,1));
    m_colors.push_back(glm::vec4(1,1,1,1));

	//Describe the triangles to create in order to render the Cube
	//Bottom Square
    m_indexes.push_back( glm::ivec3(0,1,2));
	m_indexes.push_back( glm::ivec3(4,1,2));
	//Top Square
	m_indexes.push_back( glm::ivec3(3,5,6));
	m_indexes.push_back( glm::ivec3(5,6,7));
	//Front Square
	m_indexes.push_back( glm::ivec3(0,1,3));
	m_indexes.push_back( glm::ivec3(1,3,5));
	//Back Square
	m_indexes.push_back( glm::ivec3(2,4,6));
	m_indexes.push_back( glm::ivec3(4,6,7));
	//Right Square
	m_indexes.push_back( glm::ivec3(0,2,3));
	m_indexes.push_back( glm::ivec3(2,3,6));
	//Left Square
	m_indexes.push_back( glm::ivec3(1,4,5));
	m_indexes.push_back( glm::ivec3(4,5,7));

	// Set the model matrix to identity
	m_model = glm::mat4(1.0);

	//Create buffers
	glcheck(glGenBuffers(1, &m_vBuffer)); 	//vertices
	glcheck(glGenBuffers(1, &m_cBuffer)); 	//colors
    glcheck(glGenBuffers(1,&m_iBuffer));	//indexes

	//Activate buffer and send data to the graphics card
	glcheck(glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer));
    glcheck(glBufferData(GL_ARRAY_BUFFER, m_positions.size()*sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW));

	glcheck(glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer));
    glcheck(glBufferData(GL_ARRAY_BUFFER, m_colors.size()*sizeof(glm::vec4), m_colors.data(), GL_STATIC_DRAW));
	    
	glcheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iBuffer));
    glcheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size()*sizeof(glm::ivec3), m_indexes.data(), GL_STATIC_DRAW));
}

void IndexedCubeRenderable::do_draw()
{
	// Get the identifier ( location ) of the uniform modelMat in the shader program
	int modelLocation = m_shaderProgram->getUniformLocation("modelMat");
	// Send the data corresponding to this identifier on the GPU
	glUniformMatrix4fv( modelLocation , 1, GL_FALSE , glm::value_ptr( this->getModelMatrix() ));

	// Get the identifier of the attribute vPosition in the shader program
	GLint positionLocation = m_shaderProgram->getAttributeLocation("vPosition");
	GLint colorLocation = m_shaderProgram->getAttributeLocation("inColor");

	// Activate the attribute array at this location
	glcheck(glEnableVertexAttribArray( positionLocation ));
	// Bind the position buffer on the GL_ARRAY_BUFFER targetcube
	glcheck(glBindBuffer( GL_ARRAY_BUFFER , m_vBuffer ));
	// Specify the location and the format of the vertex position attribute
	glcheck(glVertexAttribPointer( positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));

	//Colors
	glcheck(glEnableVertexAttribArray(colorLocation));
	glcheck(glBindBuffer( GL_ARRAY_BUFFER, m_cBuffer ));
	glcheck(glVertexAttribPointer( colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)0));

	//Indexes Methods
	glcheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iBuffer));

	// Draw the triangles
	//glcheck(glDrawArrays( GL_TRIANGLES, 0, m_positions.size()));
	glcheck(glDrawElements(GL_TRIANGLES, m_indexes.size()*3,GL_UNSIGNED_INT,(void*)0));

	// Release the vertex attribute array
	glcheck(glDisableVertexAttribArray(positionLocation));
	glcheck(glDisableVertexAttribArray(colorLocation));
}

void IndexedCubeRenderable::do_animate(float time) {}

IndexedCubeRenderable::~IndexedCubeRenderable()
{
    glcheck(glDeleteBuffers(1, &m_vBuffer));
	glcheck(glDeleteBuffers(1, &m_cBuffer));
	glcheck(glDeleteBuffers(1, &m_iBuffer));
}
