#include "MainImGuiLayer.h"
#include "ImGuiContext.h"


void MainImGuiLayer::Init() {
    
}

void MainImGuiLayer::Render() {
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    
    ImGui::Begin("Test");
    ImGui::Text("Hello World");
    ImGui::End();
    
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
}
