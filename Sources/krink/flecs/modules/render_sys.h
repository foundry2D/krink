#pragma once
#include <krink/flecs/flecs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Component types */
typedef struct {
    double x, y;
} Position, Velocity;

/* This type is used to store handles to everything that the module contains.
 * When the module is loaded, this type will be registered as component, and
 * added to the singleton entity so applications can access module handles from
 * anywhere. */
typedef struct SimpleModule {
    ECS_DECLARE_COMPONENT(Position);
    ECS_DECLARE_COMPONENT(Velocity);
    ECS_DECLARE_ENTITY(Move);
} SimpleModule;

/* This is the function that implements the module loader. It is automatically
 * invoked by the ECS_IMPORT macro. */
void SimpleModuleImport(
    ecs_world_t *world);

/* This macro is used to declare variables that contain the handles inside the
 * module. It is invoked by the ECS_IMPORT macro to declare variables in the
 * scope where the macro is invoked so the contents of the module can be used
 * after the ECS_IMPORT macro. */
#define SimpleModuleImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, Position);\
    ECS_IMPORT_COMPONENT(handles, Velocity);\
    ECS_IMPORT_ENTITY(handles, Move);

#ifdef __cplusplus
}
#endif