#pragma once

#include "pch.h"
#include "Core.h"
#include "PhysicsTypes.h"

namespace QUA {

    class QUA_API Physics
    {
    public:

        //World
        virtual World createWorld(Vec2 gravity) = 0;
        virtual void destroyWorld(World world) = 0;

        virtual void step(World world, float timeStep, int velocityIterations = 8, int positionIterations = 3) = 0;

        virtual void setGravity(World world, Vec2 gravity) = 0;
        virtual Vec2 getGravity(World world) const = 0;

        //Bodies
        virtual Body createBody(World world, const BodyDef& desc) = 0;
        virtual void destroyBody(Body body) = 0;

        virtual void setTransform(Body body, Vec2 pos, float angle) = 0;
        virtual Vec2 getPosition(Body body) const = 0;
        virtual float getAngle(Body body) const = 0;

        virtual void setLinearVelocity(Body body, Vec2 v) = 0;
        virtual Vec2 getLinearVelocity(Body body) const = 0;

        virtual void applyForceToCenter(Body body, Vec2 force, bool wake) = 0;
        virtual void applyLinearImpulseToCenter(Body body, Vec2 impulse, bool wake) = 0;

        virtual void setAsBox(Body body, Vec2 size, const ShapeProps& shapeProps, bool isSensor) = 0;
        virtual void setAsCircle(Body body, float radius, const ShapeProps& shapeProps, bool isSensor) = 0;

        static Physics* Create();
    };
}