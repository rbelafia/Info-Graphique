
#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <CylinderRenderable.hpp>
#include <FrameRenderable.hpp>
#include <MeshRenderable.hpp>
#include <KeyframedCylinderRenderable.hpp>
#include <KeyframedMeshRenderable.hpp>
#include <FrameRenderable.hpp>
#include <GeometricTransformation.hpp>
#include <iostream>
#include <iomanip>

void movingTree(Viewer& viewer);
void movingCylinder(Viewer& viewer);

void initialize_scene( Viewer& viewer )
{
     movingCylinder(viewer);
    //movingTree(viewer);
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

void movingCylinder( Viewer& viewer )
{
    //Add shader
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl", 
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );

    //Frame
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    viewer.getCamera().setViewMatrix( glm::lookAt( glm::vec3(0, -8, 4 ), glm::vec3(0, 0, 4), glm::vec3( 0, 0, 1 ) ) );

    //Animated cylinder
    auto cylinder = std::make_shared<KeyframedCylinderRenderable>(flatShader);
    cylinder->setParentTransform(glm::mat4(1.0));
    cylinder->setLocalTransform(glm::mat4(1.0));


    MeshRenderablePtr mesh1 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/ballon.obj");
    auto mesh2 = std::make_shared<KeyframedMeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/zepp_helice.obj");
    mesh2->setParentTransform(glm::mat4(1.0));
    mesh2->setLocalTransform(glm::mat4(1.0));
    
    MeshRenderablePtr mesh3 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/cabine.obj");
    MeshRenderablePtr mesh4 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/gouver.obj");
    MeshRenderablePtr mesh5 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/coque.obj");
    MeshRenderablePtr mesh6 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/rope1.obj");
    MeshRenderablePtr mesh7 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/rope2.obj");
    MeshRenderablePtr mesh8 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/rope3.obj");
    MeshRenderablePtr mesh9 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/rope4.obj");
    MeshRenderablePtr mesh10 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/rope5.obj");
    MeshRenderablePtr mesh11 = std::make_shared<MeshRenderable>( flatShader, "../../sfmlGraphicsPipeline/meshes/meshes/rope6.obj");

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

    mesh2->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(glm::vec3{1,0,0}),glm::vec3(1,1,1))),0.1);
    mesh2->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(glm::vec3{2,0,0}),glm::vec3(1,1,1))),1);
    mesh2->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(glm::vec3{3,0,0}),glm::vec3(1,1,1))),2);
    mesh2->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(glm::vec3{0,0,0}),glm::vec3(1,1,1))),3);



    // TODO: Keyframes on parent transformation
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(1,0,0,0),glm::vec3(1,1,1))),0.1);
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(glm::vec3{0,0,0}),glm::vec3(1,1,1))),0.1);
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(glm::vec3{0,0,0}),glm::vec3(1,1,1))),0.1);
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(3,0,0),glm::quat(glm::vec3{0,1,0}),glm::vec3(1,1,1))),0.2);
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(glm::vec3{0,0,0}),glm::vec3(1,1,1))),0.3);

    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,5,0),glm::quat(glm::vec3{0,0,0}),glm::vec3(1,1,1))),0.4);

    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0.0f,0.0f,0.0f),glm::quat(1.0f, 0.0f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f))),0.1f);
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0.0f,0.0f,1.0f),glm::quat(1.0f, 0.0f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f))),1.0f);
    //cylinder->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0.0f,0.0f,-1.0f),glm::quat(1.0f, 0.0f,0.0f,0.0f),glm::vec3(1.0f,1.0f,1.0f))),3.0f);
    






    //...

    // TODO: Keyframes on local transformation
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(1,0,0,0),glm::vec3(1,1,1))),0.0);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(glm::vec3{0,0,1}),glm::vec3(1,1,1))),2);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(glm::vec3{0,0,1}),glm::vec3(1,1,1))),3);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(glm::vec3{0,0,1}),glm::vec3(1,1,1))),4);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(glm::vec3{0,0,1}),glm::vec3(1,1,1))),5);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0.0f,0.0f,0.0f),glm::quat(glm::vec3{0.0f,0.0f,1.0f}),glm::vec3(1.0f,1.0f,1.0f))),0.1f);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0.0f,0.0f,0.0f),glm::quat(glm::vec3{0.0f,0.0f,1.0f}),glm::vec3(1.0f,1.0f,1.0f))),1.0f);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0.0f,0.0f,0.0f),glm::quat(1, 0,0,0),glm::vec3(1.0f,1.0f,1.0f))),0.1f);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,5),glm::quat(1, 0, 0, 0),glm::vec3(1,1,1))),0.1f);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(1, 0, 0, 0),glm::vec3(1,1,1))),1.0f);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,2),glm::quat(1, 0, 0, 0),glm::vec3(1,1,1))),2.0f);
    //cylinder->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,-1),glm::quat(1, 0, 0, 0),glm::vec3(1,1,1))),3.0f);



    //...

    viewer.addRenderable(mesh2);

    viewer.startAnimation();
    viewer.setAnimationLoop(true, 6.0);
}

void movingTree( Viewer& viewer )
{
    //Add shader
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl", 
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );

    //Frame
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    //Tree modeling:
    //The modeling is hierarchical (setLocalTransform, setParentTransform)
    //The animation is hierarchical too (addParentTransformKeyframe, addLocalTransformKeyframe)

    // TODO: Create and animate the main branch 
    KeyframedCylinderRenderablePtr root = std::make_shared<KeyframedCylinderRenderable>(flatShader);
    root->setLocalTransform( GeometricTransformation( glm::vec3{0,0,0}, glm::quat(1,0,0,0), glm::vec3{1,1,1}).toMatrix() );
    // TODO: root->addParentTransformKeyframe(...)
    root->addParentTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0),glm::quat(1,0,0,0),glm::vec3(1,1,1)),0.1);

    //TODO: Add and animate a child branch
    KeyframedCylinderRenderablePtr r1 = std::make_shared<KeyframedCylinderRenderable>(flatShader);
    r1->addParentTransformKeyframe((GeometricTransformation(glm::vec3(0,0,0),glm::quat(1,0,0,0),glm::vec3(1,1,1))),0.5);
    r1->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(0,1,0,0),glm::vec3(1,1,01))),1.0);
    r1->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(0,0,0,0),glm::vec3(1,1,1))),2.0);
    r1->addLocalTransformKeyframe((GeometricTransformation(glm::vec3(0,0,1),glm::quat(0,0,0,0),glm::vec3(1,1,1))),3.0);
    // ...
    HierarchicalRenderable::addChild( root, r1 );
    // ...

    // TODO: Add and animate any other child branchs you want

    viewer.addRenderable(root);

    viewer.startAnimation();
    viewer.setAnimationLoop(true, 6.0);
}
