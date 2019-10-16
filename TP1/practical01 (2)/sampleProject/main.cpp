#include <Viewer.hpp>
# include "./../include/ShaderProgram.hpp"
# include "./../include/FrameRenderable.hpp"
# include "./../include/CubeRenderable.hpp"
# include "./../include/IndexedCubeRenderable.hpp"

#define SCR_WIDTH 1024
#define SCR_HEIGHT 768

int main( int argc, char* argv[] )
{
	// Stage 1: Create the window and its OpenGL context
	Viewer viewer(SCR_WIDTH, SCR_HEIGHT);

	// Stage 2: Load resources like shaders, meshes... and make them part of the virtual scene
	// Path to the vertex shader glsl code
	std::string vShader = "./../../sfmlGraphicsPipeline/shaders/defaultVertex.glsl";
	// Path to the fragment shader glsl code
	std::string fShader = "./../../sfmlGraphicsPipeline/shaders/defaultFragment.glsl";
	// Compile and link the shaders into a program
	ShaderProgramPtr defaultShader = std::make_shared<ShaderProgram>(vShader, fShader);
	// Add the shader program to the Viewer
	viewer.addShaderProgram(defaultShader);
	
	// Compile and link the flat shaders into a shader program
	vShader = "./../../sfmlGraphicsPipeline/shaders/flatVertex.glsl";
	fShader = "./../../sfmlGraphicsPipeline/shaders/flatFragment.glsl";
	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(vShader, fShader);

	viewer.addShaderProgram(flatShader);

	// When instantiating a renderable ,
	// you must specify the shader program used to draw it .
	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(defaultShader);
	IndexedCubeRenderablePtr icube = std::make_shared<IndexedCubeRenderable>(flatShader);
	CubeRenderablePtr cube = std::make_shared<CubeRenderable>(flatShader);
	viewer.addRenderable(frame);
	viewer.addRenderable (cube);
	cube->setModelMatrix(glm::translate(cube->getModelMatrix(),glm::vec3(1,1,0)));
	cube->setModelMatrix(glm::scale(cube->getModelMatrix(),glm::vec3(0.5,1.5,1)));
	viewer.addRenderable (icube);
	icube->setModelMatrix(glm::translate(icube->getModelMatrix(),glm::vec3(-1,-1,0)));
	icube->setModelMatrix(glm::rotate (icube->getModelMatrix(),0.5f, glm::vec3(1.,0.5,1.)));



	// Stage 3: Our program loop
	while( viewer.isRunning() )
	{
	    viewer.handleEvent(); 	// user interactivity (keyboard/mouse)
	    viewer.draw();			// rasterization (write in framebuffer)
	    viewer.display();		// refresh window
	}
	
	return EXIT_SUCCESS;
}
