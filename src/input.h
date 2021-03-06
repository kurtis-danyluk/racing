#ifndef INPUT
#define	INPUT


#include	<GL/glew.h>
#include	<GLFW/glfw3.h>


#define	INPUT_BUTTON_A		0
#define	INPUT_BUTTON_B		1
#define	INPUT_BUTTON_X		2
#define	INPUT_BUTTON_Y		3
#define	INPUT_BUTTON_LB		4
#define	INPUT_BUTTON_RB		5
#define	INPUT_BUTTON_BACK	6
#define	INPUT_BUTTON_START	7
#define	INPUT_BUTTON_L3		8
#define	INPUT_BUTTON_R3		9
#define	INPUT_BUTTON_DUP	10
#define	INPUT_BUTTON_DRIGHT	11
#define	INPUT_BUTTON_DDOWN	12
#define	INPUT_BUTTON_DLEFT	13

#define	INPUT_AXIS_LEFT_LR	0
#define	INPUT_AXIS_LEFT_UD	1
#define	INPUT_AXIS_TRIGGERS	2
#define	INPUT_AXIS_RIGHT_UD	3
#define	INPUT_AXIS_RIGHT_LR	4

#define	INPUT_MAX_JOYSTICKS	(GLFW_JOYSTICK_LAST+1)

#define	INPUT_FLAG_NONE		0x00
#define	INPUT_FLAG_ENABLED	0x01


struct controller
{
	int num_buttons;
	const unsigned char* buttons;

	int num_axes;
	const float* axes;

	unsigned char flags;
};

struct inputmanager
{
	struct controller controllers[INPUT_MAX_JOYSTICKS];
};


/*	start up the texture manager
	param:	im				input manager (modified)
*/
void inputmanager_startup(struct inputmanager* im);


/*	shut down the input manager
	param:	im				input manager (modified)
*/
void inputmanager_shutdown(struct inputmanager* im);


/*	update the input
	param:	im				input manager (modified)
*/
void inputmanager_update(struct inputmanager* im);


/*	get the name of a given joystick
	param:	im				input manager
	param:	id_joyst		id of the joystick to query
	return:	const char*		name of the joystick
*/
const char* inputmanager_joystickname(struct inputmanager* im, int id_joyst);


#endif
