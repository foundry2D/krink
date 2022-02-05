#pragma once
#include <krink/flecs/flecs.h>

#undef ECS_META_IMPL
#ifndef SYSTEMS_FSM_IMPL
#define ECS_META_IMPL EXTERN
#else
#define ECS_META_IMPL DECLARE
#endif


#ifdef __cplusplus
extern "C" {
#endif

void SystemsFsmImport(ecs_world_t *world);

#ifdef __cplusplus
}
#endif