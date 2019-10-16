#include "./../include/CubeRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"
#include "./../include/gl_helper.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>


CubeRenderable::CubeRenderable(ShaderProgramPtr shaderProgram)
  : Renderable(shaderProgram), m_vBuffer(0), m_cBuffer(0)
{
	// Build the geometry : just a simple triangle for now
	// lol no it's a cube now

	/*
	POINTS
	 */
	
	//xy0
	m_positions.push_back( glm::vec3 (0 ,0 ,0) );
	m_positions.push_back( glm::vec3(1,0,0));
	m_positions.push_back( glm::vec3(0,1,0));
	m_positions.push_back( glm::vec3(1,0,0));
	m_positions.push_back( glm::vec3(0,1,0));
	m_positions.push_back( glm::vec3(1,1,0));

	//x0z
	m_positions.push_back(glm::vec3(0,0,0));
	m_positions.push_back(glm::vec3(1,0,0));
	m_positions.push_back(glm::vec3(0,0,1));
	m_positions.push_back(glm::vec3(1,0,0));
	m_positions.push_back(glm::vec3(0,0,1));
	m_positions.push_back(glm::vec3(1,0,1));

	//0yz face
	m_positions.push_back(glm::vec3(0,0,0));
	m_positions.push_back(glm::vec3(0,1,0));
	m_positions.push_back(glm::vec3(0,0,1));
	m_positions.push_back(glm::vec3(0,1,0));
	m_positions.push_back(glm::vec3(0,0,1));
	m_positions.push_back(glm::vec3(0,1,1));

	//xy1
	m_positions.push_back( glm::vec3(0,0,1));
	m_positions.push_back( glm::vec3(1,0,1));
	m_positions.push_back( glm::vec3(0,1,1));
	m_positions.push_back( glm::vec3(1,0,1));
	m_positions.push_back( glm::vec3(0,1,1));
	m_positions.push_back( glm::vec3(1,1,1));

	//x1z
	m_positions.push_back(glm::vec3(0,1,0));
	m_positions.push_back(glm::vec3(1,1,0));
	m_positions.push_back(glm::vec3(0,1,1));
	m_positions.push_back(glm::vec3(1,1,0));
	m_positions.push_back(glm::vec3(0,1,1));
	m_positions.push_back(glm::vec3(1,1,1));

	//1yz
	m_positions.push_back(glm::vec3(1,0,0));
	m_positions.push_back(glm::vec3(1,1,0));
	m_positions.push_back(glm::vec3(1,0,1));
	m_positions.push_back(glm::vec3(1,1,0));
	m_positions.push_back(glm::vec3(1,0,1));
	m_positions.push_back(glm::vec3(1,1,1));



	/*
	COLORS
	 */
	
	/*//xy0
	m_colors.push_back(glm::vec4(0,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(0,1,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(0,1,0,1));
	m_colors.push_back(glm::vec4(1,1,0,1));

	//x0z
	m_colors.push_back(glm::vec4(0,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(0,0,1,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(0,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));

	//0yz
	m_colors.push_back(glm::vec4(0,0,0,1));
	m_colors.push_back(glm::vec4(0,1,0,1));
	m_colors.push_back(glm::vec4(0,0,1,1));
	m_colors.push_back(glm::vec4(0,1,0,1));
	m_colors.push_back(glm::vec4(0,0,1,1));
	m_colors.push_back(glm::vec4(0,1,1,1));

	//xy1
	m_colors.push_back(glm::vec4(0,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(0,1,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(0,1,1,1));
	m_colors.push_back(glm::vec4(1,1,1,1));

	//x1z
	m_colors.push_back(glm::vec4(0,1,0,1));
	m_colors.push_back(glm::vec4(1,1,0,1));
	m_colors.push_back(glm::vec4(0,1,1,1));
	m_colors.push_back(glm::vec4(1,1,0,1));
	m_colors.push_back(glm::vec4(0,1,1,1));
	m_colors.push_back(glm::vec4(1,1,1,1));

	//1yz
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,1,0,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,1,0,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,1,1,1));
	*/
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));

	m_colors.push_back(glm::vec4(1,1,0.5,1));
	m_colors.push_back(glm::vec4(1,1,0.5,1));
	m_colors.push_back(glm::vec4(1,1,0.5,1));

	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));

	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));

	m_colors.push_back(glm::vec4(1,1,0,1));
	m_colors.push_back(glm::vec4(1,1,0,1));
	m_colors.push_back(glm::vec4(1,1,0,1));
	
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));

	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));

	m_colors.push_back(glm::vec4(0.5,1,0,1));
	m_colors.push_back(glm::vec4(0.5,1,0,1));
	m_colors.push_back(glm::vec4(0.5,1,0,1));
	
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));

	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));
	m_colors.push_back(glm::vec4(1,0,0,1));

	m_colors.push_back(glm::vec4(1,0.5,0,1));
	m_colors.push_back(glm::vec4(1,0.5,0,1));
	m_colors.push_back(glm::vec4(1,0.5,0,1));
	
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));
	m_colors.push_back(glm::vec4(1,0,1,1));



	// Set the model matrix to identity
	m_model = glm::mat4(1.0);

	//Create buffers
	glGenBuffers(1, &m_vBuffer); //vertices
	glcheck(glGenBuffers(1, &m_cBuffer)); //colors

	//Activate buffer and send data to the graphics card
	glcheck(glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer));
    	glcheck(glBufferData(GL_ARRAY_BUFFER, m_positions.size()*sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW));
    	glcheck(glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer));
    	glcheck(glBufferData(GL_ARRAY_BUFFER, m_colors.size()*sizeof(glm::vec4), m_colors.data(), GL_STATIC_DRAW));
}

void CubeRenderable::do_draw()
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
	// Bind the position buffer on the GL_ARRAY_BUFFER target
	glcheck(glBindBuffer( GL_ARRAY_BUFFER , m_vBuffer ));
	// Specify the location and the format of the vertex position attribute
	glcheck(glVertexAttribPointer( positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));


	glcheck(glEnableVertexAttribArray(colorLocation));
	glcheck(glBindBuffer( GL_ARRAY_BUFFER, m_cBuffer ));
	glcheck(glVertexAttribPointer( colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)0));

	// Draw the triangles
	glcheck(glDrawArrays( GL_TRIANGLES, 0, m_positions.size()));

	// Release the vertex attribute array
	glcheck(glDisableVertexAttribArray( positionLocation ));
	glcheck(glDisableVertexAttribArray(colorLocation));
}

void CubeRenderable::do_animate(float time) {}

CubeRenderable::~CubeRenderable()
{
    glcheck(glDeleteBuffers(1, &m_vBuffer));
	glcheck(glDeleteBuffers(1,&m_cBuffer));
}
