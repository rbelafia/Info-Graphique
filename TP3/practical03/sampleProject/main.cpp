#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <FrameRenderable.hpp>
#include <HierarchicalCylinderRenderable.hpp>
#include <HierarchicalMeshRenderable.hpp>
#include <HierarchicalSphereRenderable.hpp>

void addchild (std::shared_ptr<HierarchicalCylinderRenderable> root, ShaderProgramPtr childProg, int i, int x, int y, int z){

    std::shared_ptr<HierarchicalCylinderRenderable> child = std::make_shared <HierarchicalCylinderRenderable>( childProg ) ;

    glm::mat4 childParentTransform ;
    childParentTransform = glm::translate(childParentTransform,glm::vec3(x,y,z));
    child-> setParentTransform ( childParentTransform ) ;

    //glm::mat4 childParentTransform ;
    childParentTransform = glm::rotate(childParentTransform,0.5f,glm::vec3(x,0,0));
    child-> setParentTransform ( childParentTransform ) ;

    glm::mat4 childLocalTransform ;
    childLocalTransform = glm::rotate(childLocalTransform,0.5f,glm::vec3(50,50,50));
    child-> setLocalTransform ( childLocalTransform ) ;

    childLocalTransform = glm::scale(childLocalTransform,glm::vec3(x,y,z));
    child-> setLocalTransform ( childLocalTransform ) ;
        

    HierarchicalRenderable::addChild ( root , child ) ;
    if(i>0){
        i--;
        addchild(child, childProg,i,x+1,y+1,z+1);
        addchild(child, childProg,i,-x-1,-y-1,-z-1);
    }

}

void initialize_scene( Viewer& viewer )
{


    // TODO: Add an hierarchical structure of 3D objects.
    // ...
    // create programs ( you can use the same program for both the child and parent )
    ShaderProgramPtr parentProg = std::make_shared<ShaderProgram>(
            "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
            "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    ShaderProgramPtr childProg = std::make_shared<ShaderProgram>(
            "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
            "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram ( parentProg ) ;
    viewer.addShaderProgram ( childProg ) ;
    // Create renderables
    std::shared_ptr<HierarchicalCylinderRenderable> root = std::make_shared <HierarchicalCylinderRenderable>(parentProg ) ;
    std::shared_ptr<HierarchicalSphereRenderable> child1 = std::make_shared <HierarchicalSphereRenderable>( childProg ) ;
    //std::shared_ptr<HierarchicalSphereRenderable> child2 = std::make_shared <HierarchicalSphereRenderable>( childProg ) ;
    //std::shared_ptr<HierarchicalCylinderRenderable> child3 = std::make_shared <HierarchicalCylinderRenderable>( childProg ) ;
    //std::shared_ptr<HierarchicalCylinderRenderable> child4 = std::make_shared <HierarchicalCylinderRenderable>( childProg ) ;
    // For each element of the hierarchy ,
    // Set local transform and parent transform
    glm::mat4 rootParentTransform ;
    root-> setParentTransform ( rootParentTransform ) ;

    glm::mat4 child1ParentTransform ;
    child1-> setParentTransform ( child1ParentTransform ) ;
    glm::mat4 child1LocalTransform ;
    child1-> setLocalTransform ( child1LocalTransform ) ;
    HierarchicalRenderable::addChild(root, child1);

    /*glm::mat4 child2ParentTransform ;

    child2ParentTransform = glm::translate(child2ParentTransform,glm::vec3(0,0,1));

    child2-> setParentTransform ( child2ParentTransform ) ;
    glm::mat4 child2LocalTransform ;
    child2-> setLocalTransform ( child2LocalTransform ) ;

    glm::mat4 child3ParentTransform ;

    child3ParentTransform = glm::scale(child3ParentTransform,glm::vec3(1,5,5));

    child3-> setParentTransform ( child3ParentTransform ) ;
    glm::mat4 child3LocalTransform ;
    child3-> setLocalTransform ( child3LocalTransform ) ;

    glm::mat4 child4ParentTransform ;
    //exemple rotate
    child4ParentTransform = glm::rotate(child4ParentTransform,0.5f,glm::vec3(2,2,2));
    //exemple rotate
    child4-> setParentTransform ( child4ParentTransform ) ;
    glm::mat4 child4LocalTransform ;
    child4-> setLocalTransform ( child4LocalTransform ) ;

    // Define parent / children relationships
    HierarchicalRenderable::addChild ( root , child1 ) ;*//*
    HierarchicalRenderable::addChild ( child1 , child2 ) ;
    HierarchicalRenderable::addChild ( child2 , child3 ) ;
    HierarchicalRenderable::addChild ( child2 , child4 ) ;*/
    // Add the root of the hierarchy to the viewer

    /*for(int i =0; i <8;i++){
        addchild(root, childProg, i, 2,1,1 );
        addchild(root, childProg, i, -2,1,1 );
    }*/


    viewer.addRenderable ( root) ;
//
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
