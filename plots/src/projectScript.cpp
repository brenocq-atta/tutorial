//--------------------------------------------------
// Plots
// projectScript.cpp
// Date: 2022-08-19
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "projectScript.h"
#include <imgui.h>
#include <implot.h>
#include <implot_demo.cpp>

void Project::onUIRender() {
    std::vector<float> x = {0, 1, 2, 3, 4};
    std::vector<float> y = {0, .5, 3, .5, 1};

    ImGui::Begin("Plot window");
    {
        ImGui::Text("This is a line plot");
        if (ImPlot::BeginPlot("LinePlot")) {
            ImPlot::PlotLine("Line", x.data(), y.data(), x.size());
            ImPlot::EndPlot();
        }
    }
    ImGui::End();

    ImGui::Begin("Another plot window");
    {
        ImGui::Text("Some bar plots");
        if (ImPlot::BeginPlot("BarPlot")) {
            ImPlot::PlotBars("Bars", x.data(), x.size(), 0.7, 1);
            ImPlot::PlotBarsH("BarsH", y.data(), y.size(), 0.4, 1);
            ImPlot::EndPlot();
        }
    }
    ImGui::End();

    bool show = true;
    ImPlot::ShowDemoWindow(&show);
    // Check the demo source code here: https://github.com/epezent/implot/blob/master/implot_demo.cpp
}
