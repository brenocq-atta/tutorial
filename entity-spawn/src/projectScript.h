//--------------------------------------------------
// Entity Spawn
// projectScript.h
// Date: 2022-08-20
// By Breno Cunha Queiroz
//--------------------------------------------------
#ifndef PROJECT_SCRIPT_H
#define PROJECT_SCRIPT_H
#include <atta/script/projectScript.h>
#include <atta/component/interface.h>

namespace cmp = atta::component;

class Project : public atta::script::ProjectScript
{
public:
	void onStart() override;
	void onStop() override;
private:
    cmp::Entity _redCube;
    cmp::Entity _pointLight;
    std::vector<cmp::Entity> _spheres;
};

ATTA_REGISTER_PROJECT_SCRIPT(Project)

#endif// PROJECT_SCRIPT_H
