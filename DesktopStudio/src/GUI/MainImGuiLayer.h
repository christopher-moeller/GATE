#pragma once

#include "ImGuiLayer.h"


class MainImGuiLayer : public ImGuiLayer {
  
public:
    void Init() override;
    void Render() override;
    
};
