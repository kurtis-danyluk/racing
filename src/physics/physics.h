#ifndef	PHYSICS
#define	PHYSICS


#include	<PxPhysicsAPI.h>
#include	"../math/vec3f.h"


#define	PHYSICS_DEFAULT_GRAVITY	0.f, -10.f, 0.f

struct physicsmanager
{
	physx::PxDefaultAllocator default_alloc;
	physx::PxDefaultErrorCallback default_error;

	physx::PxPhysics* sdk;
	physx::PxFoundation* foundation;
	physx::PxCooking* cooking;

	physx::PxMaterial* default_material;

	physx::PxScene* scene;
};

/*	start up the physics manager
	param:	pm				physics manager (modified)
*/
void physicsmanager_startup(struct physicsmanager* pm);

/*	shut down the physics manager
	param:	pm				physics manager (modified)
*/
void physicsmanager_shutdown(struct physicsmanager* pm);


/*	update the physics simulation
	param:	pm				physics manager
	param:	dt				delta time
*/
void physicsmanager_update(struct physicsmanager* pm, float dt);


physx::PxRigidDynamic* physics_addcart(struct physicsmanager* pm, vec3f pos);
physx::PxRigidDynamic* physics_adddynamic_box(struct physicsmanager*, vec3f, vec3f);

/*	add a static triangle mesh stored in a triangle strip vertex buffer
	param:	pm				physics manager
	param:	num_verts		number of vertices in the buffer
	param:	stride			stride between vertices in the buffer
	param:	buf_verts		vertex buffer
*/
void physicsmanager_addstatic_trianglestrip(struct physicsmanager* pm, unsigned num_verts, unsigned stride, float* buf_verts);


#endif