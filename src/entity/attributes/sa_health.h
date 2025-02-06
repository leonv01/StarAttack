#ifndef __SA_HEALTH_COMPONENT_H
#define __SA_HEALTH_COMPONENT_H

typedef struct Health_t
{
    int health;
    int maxHealth;
} Health_t;

Health_t InitHealth(int health, int maxHealth);
void AddHealth(Health_t *h1, Health_t h2);

#endif // __SA_HEALTH_COMPONENT_H