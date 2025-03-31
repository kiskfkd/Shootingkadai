#pragma once
class SphereCollider 
{
private:
	float radius_;
public:
	SphereCollider(float radius);
	float GetRadius() { return radius_; }
};

