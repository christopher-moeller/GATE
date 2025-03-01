#pragma once

#include <glm/glm.hpp>
#include "Camera.h"


namespace Gate {

class StandardCamera : public Camera {
public:
    StandardCamera(float fov, float aspectRatio, float nearPlane, float farPlane);

    glm::mat4 GetViewMatrix() override;
    glm::mat4 GetProjectionMatrix() override;

    void SetPosition(const glm::vec3& position);
    void SetRotation(float yaw, float pitch);
    void Move(const glm::vec3& deltaPosition);
    void Rotate(float yawOffset, float pitchOffset);

    glm::vec3 GetPosition() const { return m_Position; }
    glm::vec3 GetFront() const { return m_Front; }
    
private:
    void UpdateCameraVectors();

    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_Up;
    glm::vec3 m_Right;

    float m_Yaw;
    float m_Pitch;

    float m_FOV;
    float m_AspectRatio;
    float m_NearPlane;
    float m_FarPlane;
};


}
