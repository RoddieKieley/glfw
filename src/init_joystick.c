//
// Created by rkieley on 2021-11-25.
//

#include "internal_joystick.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

// Global state shared between compilation units of GLFW
//
_GLFWlibraryjoystick _glfw_joystick = { GLFW_FALSE };

static _GLFWinitconfigjoystick _glfwInitHintsJoystick =
{
        GLFW_TRUE      // hat buttons
};

//static void terminate_joystick(void)
//{
//    free(_glfw_joystick.mappings);
//    _glfw_joystick.mappings = NULL;
//    _glfw_joystick.mappingCount = 0;
//}

//////////////////////////////////////////////////////////////////////////
//////                        GLFW public API                       //////
//////////////////////////////////////////////////////////////////////////

GLFWAPI int glfwInitJoystick(void)
{
    if (_glfw_joystick.initialized)
        return GLFW_TRUE;

    memset(&_glfw_joystick, 0, sizeof(_glfw_joystick));
    _glfw_joystick.hints.init = _glfwInitHintsJoystick;

    _glfwInitGamepadMappings();

    _glfw_joystick.initialized = GLFW_TRUE;

    return GLFW_TRUE;
}