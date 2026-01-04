#include "pch.h"
#include "Box2DPhysics.h"
#include "Quaternion/Log.h"

namespace QUA {

    Physics* Physics::Create()
    {
        return new Box2DPhysics();
    }

    static b2Vec2 toB2Vec2(Vec2 v) 
    { 
        return b2Vec2{ v.x, v.y }; 
    }

    static Vec2  fromB2Vec2(b2Vec2 v) 
    { 
        return Vec2{ v.x, v.y }; 
    }

    static b2BodyType toB2BodyType(BodyType t) {
        switch (t) {
        case BodyType::Static:    return b2_staticBody;
        case BodyType::Kinematic: return b2_kinematicBody;
        case BodyType::Dynamic:   return b2_dynamicBody;
        default:                  return b2_staticBody;
        }
    }

    Box2DPhysics::Box2DPhysics()
    {

    }

    Box2DPhysics::~Box2DPhysics()
    {

    }

    //World
    World Box2DPhysics::createWorld(Vec2 gravity)
    {
        worlds.push_back(std::make_unique<b2World>(toB2Vec2(gravity)));
        return World{ static_cast<std::uint32_t>(worlds.size() - 1) };
    }
    void Box2DPhysics::destroyWorld(World world)
    {
        assert(world.value < worlds.size());
        worlds[world.value].reset();
    }

    void Box2DPhysics::step(World world, float timeStep, int velocityIterations, int positionIterations)
    {
        b2World* w = worldPtr(world);
        w->Step(timeStep, velocityIterations, positionIterations);
    }

    void Box2DPhysics::setGravity(World world, Vec2 gravity)
    {
        worldPtr(world)->SetGravity(toB2Vec2(gravity));
    }
    Vec2 Box2DPhysics::getGravity(World world) const
    {
        return fromB2Vec2(worldPtr(world)->GetGravity());
    }

    //Bodies
    Body Box2DPhysics::createBody(World world, const BodyDef& desc)
    {
        b2BodyDef bodydef;
        bodydef.type = toB2BodyType(desc.type);
        bodydef.position = toB2Vec2(desc.position);
        bodydef.angle = desc.angleRadians;
        bodydef.linearDamping = desc.linearDamping;
        bodydef.angularDamping = desc.angularDamping;
        bodydef.allowSleep = desc.allowSleep;
        bodydef.awake = desc.awake;
        bodydef.fixedRotation = desc.fixedRotation;
        bodydef.bullet = desc.bullet;
        bodydef.gravityScale = desc.gravityScale;

        b2Body* body = worldPtr(world)->CreateBody(&bodydef);

        bodies.push_back(body);
        return Body{ static_cast<std::uint32_t>(bodies.size() - 1) };
    }
    void Box2DPhysics::destroyBody(Body body)
    {
        b2Body* b = bodyPtr(body);
        b2World* w = b->GetWorld();
        w->DestroyBody(b);
        bodies[body.value] = nullptr;
    }

    void Box2DPhysics::setTransform(Body body, Vec2 pos, float angle)
    {
        bodyPtr(body)->SetTransform(toB2Vec2(pos), angle * 3.1415926535 / -180);
    }
    Vec2 Box2DPhysics::getPosition(Body body) const
    {
        return fromB2Vec2(bodyPtr(body)->GetPosition());
    }
    float Box2DPhysics::getAngle(Body body) const
    {
        return bodyPtr(body)->GetAngle() * -180 / 3.1415926535;
    }

    void Box2DPhysics::setLinearVelocity(Body body, Vec2 v)
    {
        bodyPtr(body)->SetLinearVelocity(toB2Vec2(v));
    }
    Vec2 Box2DPhysics::getLinearVelocity(Body body) const
    {
        return fromB2Vec2(bodyPtr(body)->GetLinearVelocity());
    }

    void Box2DPhysics::applyForceToCenter(Body body, Vec2 force, bool wake)
    {
        bodyPtr(body)->ApplyForceToCenter(toB2Vec2(force), wake);
        QUA_CORE_WARN("ApplyForce");

    }
    void Box2DPhysics::applyLinearImpulseToCenter(Body body, Vec2 impulse, bool wake)
    {
        bodyPtr(body)->ApplyLinearImpulseToCenter(toB2Vec2(impulse), wake);
    }

    void Box2DPhysics::setAsBox(Body body, Vec2 size, const ShapeProps& shapeProps, bool isSensor)
    {
        b2PolygonShape shape;
        shape.SetAsBox(size.x/2, size.y/2);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = shapeProps.density;
        fixtureDef.friction = shapeProps.friction;
        fixtureDef.restitution = shapeProps.restitution;
        fixtureDef.isSensor = isSensor;

        bodyPtr(body)->CreateFixture(&fixtureDef);
    }

    void Box2DPhysics::setAsCircle(Body body, float radius, const ShapeProps& shapeProps, bool isSensor)
    {
        b2CircleShape shape;
        shape.m_p.Set(0.0f, 0.0f);
        shape.m_radius = radius;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = shapeProps.density;
        fixtureDef.friction = shapeProps.friction;
        fixtureDef.restitution = shapeProps.restitution;
        fixtureDef.isSensor = isSensor;

        bodyPtr(body)->CreateFixture(&fixtureDef);
    }
}