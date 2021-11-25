//
// Created by rkieley on 2021-11-25.
//

#include "internal_joystick.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

static _GLFWinitconfigjoystick _glfwInitHintsJoystick =
{
        GLFW_TRUE      // hat buttons
};

static void terminate_joystick(void)
{
    free(_glfw_joystick.mappings);
    _glfw_joystick.mappings = NULL;
    _glfw_joystick.mappingCount = 0;
}
