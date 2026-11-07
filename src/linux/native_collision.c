#include "native_collision.h"

#include <string.h>

static int32_t signed32(uint32_t bits)
{
    int32_t value;memcpy(&value,&bits,sizeof(value));return value;
}

static int32_t add(int32_t a, int32_t b) { return signed32((uint32_t)a+(uint32_t)b); }
static int32_t sub(int32_t a, int32_t b) { return signed32((uint32_t)a-(uint32_t)b); }
static int32_t absolute(int32_t value) { return value<0?sub(0,value):value; }

static void world_bounds(const LL_NativeCollisionBody *body, int32_t bounds[6])
{
    for (unsigned i=0;i<6;i++) bounds[i]=add(body->position[i%3],body->bounds[i]);
}

static int overlaps(const int32_t a[6], const int32_t b[6])
{
    for (unsigned axis=0;axis<3;axis++) if (a[axis]>b[axis+3] || b[axis]>a[axis+3]) return 0;
    return 1;
}

static unsigned axis_for(uint16_t flags)
{
    return (flags&0x18u)==8?1:(flags&0x18u)==16?2:0;
}

static int32_t separation(const int32_t a[6], const int32_t b[6], int32_t point, unsigned axis)
{
    int32_t middle=add(a[axis],a[axis+3])/2;
    return point<middle?sub(sub(a[axis],b[axis+3]),1):add(sub(a[axis+3],b[axis]),1);
}

int ll_native_collision_step(LL_NativeCollisionLink *link,
                             LL_NativeCollisionBody *owner, LL_NativeCollisionBody *target)
{
    if (!link || !owner || !target || link->callback_mode>7) return -1;
    if (!link->active) return 0;
    unsigned mode=link->callback_mode&3u;
    int32_t a[6],b[6];world_bounds(owner,a);world_bounds(target,b);
    if (link->callback_mode>=4) {
        int32_t delta[3];
        for (unsigned axis=0;axis<3;axis++) delta[axis]=sub(owner->position[axis],owner->previous[axis]);
        if (mode==0 || mode==2) {
            /* 457d20/458720 replace the rider's maximumY by the support top. */
            b[4]=a[1];
            if (!mode && (link->flags&0x100u)) target->flags|=0x10000u;
            if (!overlaps(a,b) || !(target->flags&0x20u)) {
                link->flags&=(uint16_t)~0x80u;link->callback_mode=(uint8_t)mode;
                target->flags&=mode?~0x28u:~0x10028u;return 0;
            }
            target->position[0]=add(target->position[0],delta[0]);
            target->position[1]=a[1];target->position[2]=add(target->position[2],delta[2]);
        } else {
            for (unsigned i=0;i<6;i++) b[i]=add(b[i],delta[i%3]);
            if (!overlaps(a,b)) {
                link->flags&=(uint16_t)~0x80u;link->callback_mode=(uint8_t)mode;
                target->flags&=~0x28u;return 0;
            }
            if (target->flags&0x20u) for (unsigned axis=0;axis<3;axis++)
                target->position[axis]=add(target->position[axis],delta[axis]);
            if (a[1]<target->position[1]) { target->flags|=0x28u;target->position[1]=a[1]; }
        }
        return 2;
    }
    if (!mode && (link->flags&0x80u)) return 0;
    if (!overlaps(a,b)) {
        if (!mode && (link->flags&0x40u)) {
            target->flags&=~0x14u;link->flags&=(uint16_t)~0x40u;
        }
        return 0;
    }
    if (!mode) {
        int32_t owner_delta=sub(owner->previous[1],owner->position[1]);
        if ((absolute(sub(target->position[1],a[1]))<300 && (target->flags&0x20u)) ||
            target->previous[1]<=add(a[1],owner_delta)) {
            target->flags=(target->flags|0x28u)&~0x14u;
            link->flags=(uint16_t)((link->flags|0x80u)&~0x40u);link->callback_mode=4;
            return 0; /* Native458018 deliberately defers the Y position setter. */
        }
        int32_t height=sub(target->position[1],b[1]);
        if (!(a[4]<b[1] || sub(target->previous[1],height)<a[4])) {
            target->position[1]=add(a[4],height);return 2;
        }
        link->flags|=0x40u;unsigned axis=axis_for(link->flags);
        int16_t displacement=(int16_t)(uint16_t)separation(a,b,target->position[axis],axis);
        int moved;
        if (!(owner->flags&2u)) {
            target->flags=(target->flags&~4u)|0x10u;
            target->position[axis]=add(target->position[axis],displacement);moved=2;
        } else if (target->flags&0x20u) {
            target->flags=(target->flags&~0x10u)|4u;
            owner->position[axis]=sub(owner->position[axis],displacement);moved=1;
        } else {
            target->position[axis]=add(target->position[axis],displacement);moved=2;
        }
        if (link->flags&0x20u) target->flags&=~0x14u;
        return moved;
    }
    if (mode==1) {
        if (absolute(sub(target->position[1],a[1]))<100 && (target->flags&0x20u)) {
            target->position[1]=a[1];target->flags|=0x28u;link->flags|=0x80u;link->callback_mode=5;
        } else {
            unsigned axis=axis_for(link->flags);
            target->position[axis]=add(target->position[axis],separation(a,b,target->position[axis],axis));
        }
        return 2;
    }
    if (mode==2) {
        if (a[1]<=target->position[1] && target->previous[1]<a[1]) {
            target->position[1]=a[1];target->flags|=0x28u;link->flags|=0x80u;link->callback_mode=6;return 2;
        }
        return 0;
    }
    if (target->previous[1]<a[1] && a[1]<target->position[1]) {
        target->position[1]=a[1];target->flags|=0x28u;link->flags|=0x80u;link->callback_mode=7;
    } else if (a[1]<target->position[1]) {
        unsigned axis=axis_for(link->flags);
        target->position[axis]=add(target->position[axis],separation(a,b,target->position[axis],axis));
    }
    return 2;
}
