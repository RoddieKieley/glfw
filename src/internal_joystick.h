//
// Created by rkieley on 2021-11-25.
//

#ifndef GLFW_INTERNAL_JOYSTICK_H
#define GLFW_INTERNAL_JOYSTICK_H

//#ifdef __cplusplus
//extern "C" {
//#endif

#include "../include/GLFW/glfw3joystick.h"
#include "../include/GLFW/glfw3common.h"
#include <stdint.h>

#define _GLFW_POLL_PRESENCE     0
#define _GLFW_POLL_AXES         1
#define _GLFW_POLL_BUTTONS      2
#define _GLFW_POLL_ALL          (_GLFW_POLL_AXES | _GLFW_POLL_BUTTONS)

typedef struct _GLFWlibraryjoystick     _GLFWlibraryjoystick;
typedef struct _GLFWinitconfigjoystick  _GLFWinitconfigjoystick;

typedef struct _GLFWmapelement  _GLFWmapelement;
typedef struct _GLFWmapping     _GLFWmapping;
typedef struct _GLFWjoystick    _GLFWjoystick;


// Gamepad mapping element structure
//
struct _GLFWmapelement
{
    uint8_t         type;
    uint8_t         index;
    int8_t          axisScale;
    int8_t          axisOffset;
};

// Gamepad mapping structure
//
struct _GLFWmapping
{
    char            name[128];
    char            guid[33];
    _GLFWmapelement buttons[15];
    _GLFWmapelement axes[6];
};

// Joystick structure
//
struct _GLFWjoystick
{
    GLFWbool        present;
    float*          axes;
    int             axisCount;
    unsigned char*  buttons;
    int             buttonCount;
    unsigned char*  hats;
    int             hatCount;
    char            name[128];
    void*           userPointer;
    char            guid[33];
    _GLFWmapping*   mapping;

    // This is defined in the joystick API's joystick.h
    _GLFW_PLATFORM_JOYSTICK_STATE;
};

struct _GLFWlibraryjoystick
{
    _GLFWjoystick       joysticks[GLFW_JOYSTICK_LAST + 1];
    _GLFWmapping*       mappings;
    int                 mappingCount;

    struct {
//        GLFWmonitorfun  monitor;
        GLFWjoystickfun joystick;
    } callbacks;
};

// Initialization configuration
//
// Parameters relating to the initialization of the library
//
struct _GLFWinitconfigjoystick
{
    GLFWbool      hatButtons;
//    struct {
//        GLFWbool  menubar;
//        GLFWbool  chdir;
//    } ns;
};

// Global state shared between compilation units of GLFW
//
extern _GLFWlibraryjoystick _glfw_joystick;


int _glfwPlatformPollJoystick(_GLFWjoystick* js, int mode);
void _glfwPlatformUpdateGamepadGUID(char* guid);

void _glfwInputJoystick(_GLFWjoystick* js, int event);
void _glfwInputJoystickAxis(_GLFWjoystick* js, int axis, float value);
void _glfwInputJoystickButton(_GLFWjoystick* js, int button, char value);
void _glfwInputJoystickHat(_GLFWjoystick* js, int hat, char value);

void _glfwInitGamepadMappings(void);
_GLFWjoystick* _glfwAllocJoystick(const char* name,
                                  const char* guid,
                                  int axisCount,
                                  int buttonCount,
                                  int hatCount);
void _glfwFreeJoystick(_GLFWjoystick* js);


//#ifdef __cplusplus
//}
//#endif

#endif //GLFW_INTERNAL_JOYSTICK_H
