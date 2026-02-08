/*
    Works with iomanip library
    Physical simulation of a particle moving in a medium whose parameters are described by a nested structure.
*/

#include <iostream>
#include <iomanip>

class Particle {
public:
    struct Environment {
        double density;
        double friction;
    };

private:
    double x{};
    double y{};
    double vx{};
    double vy{};
    double mass{};
    Environment env{};

public:
    Particle(double x_, double y_, double mass_, const Environment& env_) : x(x_), y(y_), vx(0.0), vy(0.0), mass(mass_), env(env_) {}

    Particle(double mass_) : Particle(0.0, 0.0, mass_, Environment{1.0, 0.1}) {}

    // applyForce: F = m * a => a = F / m; v += a * dt
    Particle& applyForce(double fx, double fy) {
        const double ax = fx / mass;
        const double ay = fy / mass;
        vx += ax;
        vy += ay;
        return *this;
    }

    Particle& tick(double dt) {
        // F_friction = -k * v, где k = env.density * env.friction
        const double k = env.density * env.friction;

        //a = F / m = -(k/m) * v
        const double ax = -(k / mass) * vx;
        const double ay = -(k / mass) * vy;

        vx += ax * dt;
        vy += ay * dt;

        x += vx * dt;
        y += vy * dt;

        return *this;
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "Particle state:\n";
        std::cout << "  position: (" << x << ", " << y << ")\n";
        std::cout << "  velocity: (" << vx << ", " << vy << ")\n";
        std::cout << "  mass:     " << mass << "\n";
        std::cout << "  env:      density=" << env.density << ", friction=" << env.friction << "\n";
    }
};

int main() {
    Particle::Environment e{1.2, 0.05};
    Particle p(0.0, 0.0, 1.0, e);

    p.applyForce(10.0, 0.0).tick(0.1).tick(0.1);
    p.print();

    Particle p2(2.0); // mass=2, (0,0), v=0, env={1.0, 0.1}
    p2.applyForce(5.0, 3.0).tick(0.2);
    p2.print();
    /*
    ---output---
    Particle state:
    position: (1.982, 0.000)
    velocity: (9.880, 0.000)
    mass:     1.000
    env:      density=1.200, friction=0.050
    Particle state:
    position: (0.495, 0.297)
    velocity: (2.475, 1.485)
    mass:     2.000
    env:      density=1.000, friction=0.100
    */
    return 0;
}
