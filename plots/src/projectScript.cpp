//--------------------------------------------------
// Plots
// projectScript.cpp
// Date: 2022-08-19
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "projectScript.h"
#include <imgui.h>
#include <implot.h>
#include <implot3d.h>

void Project::onUIRender() {
    std::vector<float> x = {0, 1, 2, 3, 4};
    std::vector<float> y = {0, .5, 3, .5, 1};

    ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Once);
    ImGui::Begin("Plot window");
    {
        ImGui::Text("This is a line plot");
        if (ImPlot::BeginPlot("LinePlot")) {
            ImPlot::PlotLine("Line", x.data(), y.data(), x.size());
            ImPlot::EndPlot();
        }
    }
    ImGui::End();

    ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_Once);
    ImGui::Begin("Another plot window");
    {
        ImGui::Text("Some bar plots");
        if (ImPlot::BeginPlot("BarPlot", ImVec2(-1, 200))) {
            ImPlot::PlotBars("Bars", x.data(), x.size(), 0.7, 1);
            ImPlot::PlotBars("BarsH", y.data(), y.size(), 0.4, 1, ImPlotBarsFlags_Horizontal);
            ImPlot::EndPlot();
        }
    }
    ImGui::End();

    ImPlot::ShowDemoWindow();
    ImPlot3D::ShowDemoWindow();
    // Check the ImPlot demo source code here: https://github.com/epezent/implot/blob/master/implot_demo.cpp
    // Check the ImPlot3D demo source code here: https://github.com/brenocq/implot3d/blob/main/implot3d_demo.cpp
}
