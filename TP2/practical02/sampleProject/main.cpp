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
	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
	
	CylinderRenderablePtr cylinder = std::make_shared<CylinderRenderable>(flatShader);
	MeshRenderablePtr mesh1 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/ballon.obj");
    MeshRenderablePtr mesh2 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/zepp_helice.obj");
    MeshRenderablePtr mesh3 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/cabine.obj");
    MeshRenderablePtr mesh4 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/gouver.obj");
    MeshRenderablePtr mesh5 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/coque.obj");
    MeshRenderablePtr mesh6 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/rope1.obj");
    MeshRenderablePtr mesh7 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/rope2.obj");
    MeshRenderablePtr mesh8 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/rope3.obj");
    MeshRenderablePtr mesh9 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/rope4.obj");
    MeshRenderablePtr mesh10 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/rope5.obj");
    MeshRenderablePtr mesh11 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/rope6.obj");

	viewer.addRenderable(frame);
	viewer.addRenderable (mesh1);
    viewer.addRenderable (mesh2);
    viewer.addRenderable (mesh3);
    viewer.addRenderable (mesh4);
    viewer.addRenderable (mesh5);
    viewer.addRenderable (mesh6);
    viewer.addRenderable (mesh7);
    viewer.addRenderable (mesh8);
    viewer.addRenderable (mesh9);
    viewer.addRenderable (mesh10);
    viewer.addRenderable (mesh11);



	
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
