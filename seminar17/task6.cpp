/*
    Works with string, cstdint libraries
    System of the controlling of the playable character's stats
*/


#include <iostream>
#include <string>
#include <cstdint>


enum class StatusEffect : std::uint32_t {
    NONE       = 0,
    POISONED   = 1u << 0,
    STUNNED    = 1u << 1,
    INVISIBLE  = 1u << 2,
    INVINCIBLE = 1u << 3,
    BURNING    = 1u << 4,
    FROZEN     = 1u << 5,
    BLESSED    = 1u << 6,
    CURSED     = 1u << 7
};

using EffectsMask = std::uint32_t;


inline EffectsMask toMask(StatusEffect e) {
    return static_cast<EffectsMask>(e);
}

inline StatusEffect operator|(StatusEffect a, StatusEffect b) {
    return static_cast<StatusEffect>(toMask(a) | toMask(b));
}

inline StatusEffect operator&(StatusEffect a, StatusEffect b) {
    return static_cast<StatusEffect>(toMask(a) & toMask(b));
}

inline StatusEffect& operator|=(StatusEffect& a, StatusEffect b) {
    a = a | b;
    return a;
}

inline StatusEffect& operator&=(StatusEffect& a, StatusEffect b) {
    a = a & b;
    return a;
}


inline void addEffect(EffectsMask& mask, StatusEffect e) {
    mask |= toMask(e);
}

inline void removeEffect(EffectsMask& mask, StatusEffect e) {
    mask &= ~toMask(e);
}

inline bool hasEffect(EffectsMask mask, StatusEffect e) {
    return (mask & toMask(e)) != 0;
}


bool areEffectsCompatible(EffectsMask mask, StatusEffect newEff) {
    if (newEff == StatusEffect::BURNING && hasEffect(mask, StatusEffect::FROZEN))
        return false;
    if (newEff == StatusEffect::FROZEN && hasEffect(mask, StatusEffect::BURNING))
        return false;
    if (newEff == StatusEffect::BLESSED && hasEffect(mask, StatusEffect::CURSED))
        return false;
    if (newEff == StatusEffect::CURSED && hasEffect(mask, StatusEffect::BLESSED))
        return false;
    return true;
}

struct Character {
    std::string name;
    EffectsMask effects = 0;
};

bool applyEffect(Character& ch, StatusEffect e) {
    if (!areEffectsCompatible(ch.effects, e)) {
        std::cout << "Cannot apply effect to " << ch.name << ": incompatible.\n";
        return false;
    }
    addEffect(ch.effects, e);
    return true;
}

void removeEffect(Character& ch, StatusEffect e) {
    removeEffect(ch.effects, e);
}

std::string effectToString(StatusEffect e) {
    switch (e) {
        case StatusEffect::POISONED:
            return "POISONED";
        case StatusEffect::STUNNED:
            return "STUNNED";
        case StatusEffect::INVISIBLE:
            return "INVISIBLE";
        case StatusEffect::INVINCIBLE:
            return "INVINCIBLE";
        case StatusEffect::BURNING:
            return "BURNING";
        case StatusEffect::FROZEN:
            return "FROZEN";
        case StatusEffect::BLESSED:
            return "BLESSED";
        case StatusEffect::CURSED:
            return "CURSED";
        default:
            return "NONE";
    }
}

void printActiveEffects(const Character& ch) {
    std::cout << ch.name << " effects: ";
    bool first = true;
    auto mask = ch.effects;

    auto printIf = [&](StatusEffect e) {
        if (hasEffect(mask, e)) {
            if (!first) std::cout << ", ";
            std::cout << effectToString(e);
            first = false;
        }
    };

    printIf(StatusEffect::POISONED);
    printIf(StatusEffect::STUNNED);
    printIf(StatusEffect::INVISIBLE);
    printIf(StatusEffect::INVINCIBLE);
    printIf(StatusEffect::BURNING);
    printIf(StatusEffect::FROZEN);
    printIf(StatusEffect::BLESSED);
    printIf(StatusEffect::CURSED);

    if (first) std::cout << "none";
    std::cout << '\n';
}


int main() {
    Character hero{"Hero"};

    applyEffect(hero, StatusEffect::POISONED);
    applyEffect(hero, StatusEffect::BLESSED);
    printActiveEffects(hero);

    applyEffect(hero, StatusEffect::CURSED);
    printActiveEffects(hero);

    removeEffect(hero, StatusEffect::BLESSED);
    applyEffect(hero, StatusEffect::CURSED);
    printActiveEffects(hero);

    applyEffect(hero, StatusEffect::FROZEN);
    printActiveEffects(hero);

    applyEffect(hero, StatusEffect::BURNING);
    printActiveEffects(hero);

    /*
    ---output---
    Hero effects: POISONED, BLESSED
    Cannot apply effect to Hero: incompatible.
    Hero effects: POISONED, BLESSED
    Hero effects: POISONED, CURSED
    Hero effects: POISONED, FROZEN, CURSED
    Cannot apply effect to Hero: incompatible.
    Hero effects: POISONED, FROZEN, CURSED
    */
    return 0;
}
