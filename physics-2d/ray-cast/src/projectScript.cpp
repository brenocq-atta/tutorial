//--------------------------------------------------
// Physics 2D - Ray Cast
// projectScript.cpp
// Date: 2022-10-16
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "projectScript.h"
#include "imgui.h"
#include <atta/component/components/material.h>
#include <atta/component/components/transform.h>
#include <atta/component/components/relationship.h>
#include <atta/component/interface.h>
#include <atta/physics/interface.h>
#include <atta/graphics/interface.h>
#include <atta/graphics/drawer.h>

namespace cmp = atta::component;
namespace phy = atta::physics;
namespace gfx = atta::graphics;

const cmp::Entity ctrl0(7);
const cmp::Entity ctrl1(8);
const cmp::Entity boxes(0);

void Project::onUpdateBefore(float delta) {
    // Reset materials
    for(cmp::Entity box : boxes.get<cmp::Relationship>()->getChildren())
        box.get<cmp::Material>()->set("not-hit");

    // Set hit materials 
    atta::vec3 begin = ctrl0.get<cmp::Transform>()->position;
    atta::vec3 end = ctrl1.get<cmp::Transform>()->position;
    std::vector<cmp::EntityId> hitted = phy::rayCast(begin, end, _onlyFirst);
    for(cmp::Entity box : hitted)
        box.get<cmp::Material>()->set("hit");

}

void Project::onAttaLoop() {
    // Clear old line between control spheres
    gfx::Drawer::clear("control");

    // Create line between control spheres
    gfx::Drawer::Line line;
    line.p0 = ctrl0.get<cmp::Transform>()->position;
    line.p1 = ctrl1.get<cmp::Transform>()->position;
    line.c0 = {1, 0, 0, 1};
    line.c1 = {1, 0, 0, 1};
    gfx::Drawer::add(line, "control");
}

void Project::onUIRender() {
    ImGui::Begin("Ray cast control");
    ImGui::Checkbox("Only first", &_onlyFirst);
    ImGui::End();
}
