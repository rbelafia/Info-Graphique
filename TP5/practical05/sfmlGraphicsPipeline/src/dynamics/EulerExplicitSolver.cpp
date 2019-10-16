#include "./../../include/dynamics/EulerExplicitSolver.hpp"

EulerExplicitSolver::EulerExplicitSolver()
{

}

EulerExplicitSolver::~EulerExplicitSolver()
{

}

void EulerExplicitSolver::do_solve(const float& dt, std::vector<ParticlePtr>& particles)
{
    for(ParticlePtr p : particles) if(!p->isFixed())
        {
            //TODO: Implement explicit euler solver
            //Methods you'll have to use:
            //Particle::getPosition(), Particle::getVelocity(), Particle::getMass(), Particle::getForce()
            //Particle::setPosition(), Particle::setVelocity()
            //p->setForce(p->getMass()*glm::vec3(0,0,-10));
            p->setVelocity(p->getVelocity() + (1/(p->getMass())) * dt * p->getForce());
            p->setPosition(p->getPosition() + dt*p->getVelocity());
        }
}
