#include "health.h"

Health_t InitHealth(int health, int maxHealth)
{
    return (Health_t){ health, maxHealth };
}

void AddHealth(Health_t *h1, Health_t h2)
{
    int health = h1->health + h2.health;

    if(health > h1->maxHealth)
    {
        h1->health = h1->maxHealth;
    }
}