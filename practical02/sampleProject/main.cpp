#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <CylinderRenderable.hpp>
#include <FrameRenderable.hpp>
#include <MeshRenderable.hpp>

void initialize_scene( Viewer& viewer )
{
	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
	"../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
	"../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
	viewer.addShaderProgram( flatShader );

	// TODO: add some Renderable objects to the viewer
}

int main() 
{
	Viewer viewer(1280,720);
	initialize_scene(viewer);

	while( viewer.isRunning() )
	{
		viewer.handleEvent();
		viewer.animate();
		viewer.draw();
		viewer.display();
	}	

	return EXIT_SUCCESS;
}
