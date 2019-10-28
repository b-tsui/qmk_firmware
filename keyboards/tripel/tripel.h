#pragma once

#define LEFT_PCB 1
#define MIDDLE_PCB 2
#define RIGHT_PCB 3

#include "quantum.h"

#if (PRO_MICRO_POSITION == LEFT_PCB)
    #define LAYOUT_ortho_7u( \
        l11, l12, l13, l14, l15, m11, m12, m13, m14, m15, r11, r12, r13, r14, r15, \
        l21, l22, l23, l24, l25, m21, m22, m23, m24, m25, r21, r22, r23, r24, r25, \
        l31, l32, l33, l34, l35, m31, m32, m33, m34, m35, r31, r32, r33, r34, r35, \
        l41, l42, l43, l44, l45, m41, m42, m43, m44, m45, r41, r42, r43, r44, r45, \
        l51, l52, l53, l54,                m53,                r52, r53, r54, r51  \
    ) \
    { \
        { r11, r12, r13, r14, r15, r25, r35, r45 }, \
        { r21, r22, r23, r24, r34, r44, r53, r54 }, \
        { r31, r32, r33, r43, r42, r41, r51, r52 }, \
        { l11, l12, l13, l14, l15, l25, l35, l45 }, \
        { l21, l22, l23, l24, l34, l44, l53, l54 }, \
        { l31, l32, l33, l43, l42, l41, l51, l52 }, \
        { m11, m12, m13, m14, m15, m25, m35, m45 }, \
        { m21, m22, m23, m24, m34, m44, m53, KC_NO }, \
        { m31, m32, m33, m43, m42, m41, KC_NO, KC_NO } \
    }
#elif (PRO_MICRO_POSITION == MIDDLE_PCB)
    #define LAYOUT_ortho_7u( \
        l11, l12, l13, l14, l15, m11, m12, m13, m14, m15, r11, r12, r13, r14, r15, \
        l21, l22, l23, l24, l25, m21, m22, m23, m24, m25, r21, r22, r23, r24, r25, \
        l31, l32, l33, l34, l35, m31, m32, m33, m34, m35, r31, r32, r33, r34, r35, \
        l41, l42, l43, l44, l45, m41, m42, m43, m44, m45, r41, r42, r43, r44, r45, \
        l51, l52, l53, l54,                m53,                r52, r53, r54, r51  \
    ) \
    { \
        { l11, l12, l13, l14, l15, l25, l35, l45 }, \
        { l21, l22, l23, l24, l34, l44, l53, l54 }, \
        { l31, l32, l33, l43, l42, l41, l51, l52 }, \
        { m11, m12, m13, m14, m15, m25, m35, m45 }, \
        { m21, m22, m23, m24, m34, m44, m53, KC_NO }, \
        { m31, m32, m33, m43, m42, m41, KC_NO, KC_NO }, \
        { r11, r12, r13, r14, r15, r25, r35, r45 }, \
        { r21, r22, r23, r24, r34, r44, r53, r54 }, \
        { r31, r32, r33, r43, r42, r41, r51, r52 } \
    }
#elif (PRO_MICRO_POSITION == RIGHT_PCB)
    #define LAYOUT_ortho_7u( \
        l11, l12, l13, l14, l15, m11, m12, m13, m14, m15, r11, r12, r13, r14, r15, \
        l21, l22, l23, l24, l25, m21, m22, m23, m24, m25, r21, r22, r23, r24, r25, \
        l31, l32, l33, l34, l35, m31, m32, m33, m34, m35, r31, r32, r33, r34, r35, \
        l41, l42, l43, l44, l45, m41, m42, m43, m44, m45, r41, r42, r43, r44, r45, \
        l51, l52, l53, l54,                m53,                r52, r53, r54, r51  \
    ) \
    { \
        { m11, m12, m13, m14, m15, m25, m35, m45 }, \
        { m21, m22, m23, m24, m34, m44, m53, KC_NO }, \
        { m31, m32, m33, m43, m42, m41, KC_NO, KC_NO }, \
        { r11, r12, r13, r14, r15, r25, r35, r45 }, \
        { r21, r22, r23, r24, r34, r44, r53, r54 }, \
        { r31, r32, r33, r43, r42, r41, r51, r52 }, \
        { l11, l12, l13, l14, l15, l25, l35, l45 }, \
        { l21, l22, l23, l24, l34, l44, l53, l54 }, \
        { l31, l32, l33, l43, l42, l41, l51, l52 } \
    }
#endif
