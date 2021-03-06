#include	"cart.h"

#include	"../math/vec3f.h"
#include	"../physics/physics.h"
#include	"../render/render.h"


/*static float cart_pos[8][3] =
{
	{-CART_WIDTH/2.f, -CART_HEIGHT/2.f, -CART_LENGTH/2.f},
	{-CART_WIDTH/2.f, CART_HEIGHT/2.f, -CART_LENGTH/2.f},
	{CART_WIDTH/2.f, CART_HEIGHT/2.f, -CART_LENGTH/2.f},
	{CART_WIDTH/2.f, -CART_HEIGHT/2.f, -CART_LENGTH/2.f},
	{CART_WIDTH/2.f, CART_HEIGHT/2.f, CART_LENGTH/2.f},
	{-CART_WIDTH/2.f, CART_HEIGHT/2.f, CART_LENGTH/2.f},
	{-CART_WIDTH/2.f, -CART_HEIGHT/2.f, CART_LENGTH/2.f},
	{CART_WIDTH/2.f, -CART_HEIGHT/2.f, CART_LENGTH/2.f}
};*/

static float cart_nor[6][3] =
{
	{-1.f, 0.f, 0.f},
	{1.f, 0.f, 0.f},
	{0.f, -1.f, 0.f},
	{0.f, 1.f, 0.f},
	{0.f, 0.f, -1.f},
	{0.f, 0.f, 1.f}
};

/*static int cart_posindex[36] =
{
	0, 6, 5, 0, 5, 1,
	0, 3, 7, 0, 7, 6,
	0, 1, 2, 0, 2, 3,
	4, 7, 3, 4, 3, 2,
	4, 2, 1, 4, 1, 5,
	4, 5, 6, 4, 6, 7
};*/

static int cart_norindex[36] =
{
	0, 0, 0, 0, 0, 0,
	2, 2, 2, 2, 2, 2,
	4, 4, 4, 4, 4, 4,
	1, 1, 1, 1, 1, 1,
	3, 3, 3, 3, 3, 3,
	5, 5, 5, 5, 5, 5
};

void cart_init(struct cart* c, physicsmanager* pm, vec3f pos)
{
	vec3f dim;

	vec3f_set(dim, CART_WIDTH/2.f, CART_HEIGHT/2.f, CART_LENGTH/2.f);
	c->p_cart = physics_addcart(pm, pos);

	renderable_init(&c->r_cart, RENDER_MODE_TRIANGLES, RENDER_TYPE_SOLID, RENDER_FLAG_NONE);

	vec3f_set(c->r_cart.material.amb, 0.8f, 0.15f, 0.1f);
	vec3f_set(c->r_cart.material.dif, 0.8f, 0.15f, 0.1f);
	vec3f_set(c->r_cart.material.spc, 0.8f, 0.2f, 0.2f);
	c->r_cart.material.shn = 100.f;
}


void cart_generatemesh(struct renderer* r, struct cart* c)
{
	float* ptr;
	int i;

	renderable_allocate(r, &c->r_cart, 36);

	ptr = c->r_cart.buf_verts;

	for (i = 0; i < 36; i++)
	{
		vec3f_copy(ptr, cart_pos[cart_posindex[i]]);
		ptr += RENDER_ATTRIBSIZE_POS;
		vec3f_copy(ptr, cart_nor[cart_norindex[i]]);
		ptr += RENDER_ATTRIBSIZE_NOR;
	}
}