#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <string>

#include <texturing/TexturedPlaneRenderable.hpp>
#include <texturing/TexturedCubeRenderable.hpp>
#include <texturing/MultiTexturedCubeRenderable.hpp>
#include <texturing/MipMapCubeRenderable.hpp>
#include <texturing/BillBoardPlaneRenderable.hpp>
#include <lighting/DirectionalLightRenderable.hpp>
#include <texturing/TexturedTriangleRenderable.hpp>
#include <FrameRenderable.hpp>

#include <iostream>

void initialize_scene( Viewer& viewer )
{
    //Position the camera
//    viewer.getCamera().setViewMatrix( glm::lookAt( glm::vec3(0, -8, 8 ), glm::vec3(0, 0, 0), glm::vec3( 0, 0, 1 ) ) );
    viewer.getCamera().setViewMatrix( glm::lookAt( glm::vec3(0, 0, 8 ), glm::vec3(0, 0, 0), glm::vec3( 0, 1, 0 ) ) );

    //Default shader
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );

    //Add a 3D frame to the viewer
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    //Temporary variables
    glm::mat4 parentTransformation(1.0), localTransformation(1.0);
    std::string filename;

    //Textured shader
    //    ShaderProgramPtr texShader = std::make_shared<ShaderProgram>("../shaders/textureVertex.glsl","../shaders/textureFragment.glsl");

    ShaderProgramPtr texShader = std::make_shared<ShaderProgram>(  //"../../sfmlGraphicsPipeline/shaders/simpleTextureVertex.glsl",
            //"../../sfmlGraphicsPipeline/shaders/simpleTextureFragment.glsl",
            "../../sfmlGraphicsPipeline/shaders/multiTextureVertex.glsl",
            "../../sfmlGraphicsPipeline/shaders/multiTextureFragment.glsl");
    viewer.addShaderProgram( texShader );

    //Textured plane
    //filename = "./../../sfmlGraphicsPipeline/textures/checkerboard.png";
    //filename = "./../../sfmlGraphicsPipeline/textures/number_two.jpg";
    std::string filename1 = "./../../sfmlGraphicsPipeline/textures/grass.png";
    std::string filename2 = "./../../sfmlGraphicsPipeline/textures/crate.jpg";

    std::vector<std::string> filenames;

    for( int i=1; i<6;i++){
       std::string tmp = "./../../sfmlGraphicsPipeline/textures/mipmap";
       std::string tmp_bis = std::to_string(i);
       std::string tmp_tierce = ".png";
       std::string final = tmp+tmp_bis+tmp_tierce;
        filenames.push_back(final);
    }

    //TexturedPlaneRenderablePtr texPlane = std::make_shared<TexturedPlaneRenderable>(texShader, filename);
    //TexturedTriangleRenderablePtr texPlane = std::make_shared<TexturedTriangleRenderable>(texShader, filename);
    //TexturedCubeRenderablePtr texPlane = std::make_shared<TexturedCubeRenderable>(texShader, filename);
    //MipMapCubeRenderablePtr texPlane = std::make_shared<MipMapCubeRenderable>(texShader,filenames);
    MultiTexturedCubeRenderablePtr texPlane = std::make_shared<MultiTexturedCubeRenderable>(texShader, filename2, filename1);
    parentTransformation = glm::scale(glm::mat4(1.0), glm::vec3(10.0,10.0,10.0));
    texPlane->setParentTransform(parentTransformation);
    viewer.addRenderable(texPlane);
    viewer.startAnimation();


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
