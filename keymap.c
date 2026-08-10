#include QMK_KEYBOARD_H
#include "keymap_colemak.h"

enum custom_layers {
  COLEMAK_SOFT = 0,
  COLEMAK_HARD,
  CAPSLOCK_SOFT,
  CAPSLOCK_HARD,
  BROWSER,
  LEFT_LAYERS,
  NUMBERS,
  FUNCTION,
  DEVELOPMENT,
  RIGHT_LAYERS,
  RGB_OPTIONS,
  RGB_MODES
};

// OS-aware shortcuts: send Cmd on macOS, Ctrl/Alt on Windows/Linux
enum custom_keycodes {
  OS_CUT = SAFE_RANGE,
  OS_COPY,
  OS_PASTE,
  OS_SAVE,
  OS_CLOSE_TAB,
  OS_WORD_DEL,
  OS_TASK_SW,
  OS_SCREENSHOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_SOFT] = LAYOUT( \
    KC_RALT, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_CAPS, KC_CAPS, KC_RGUI, KC_RCTL, KC_RSFT, KC_LALT, KC_RALT, \
    LT(BROWSER, KC_SPC), CM_G, CM_D, CM_B, RALT(CM_O), OS_SCREENSHOT, _______, _______, KC_COMM, MO(RIGHT_LAYERS), KC_DOT, _______, \
    CM_Q, CM_W, CM_F, CM_P, RALT(CM_W), DF(COLEMAK_SOFT), _______, _______, CM_L, CM_U, CM_Y, CM_SCLN, \
    CM_A, CM_R, CM_S, CM_T, RALT(CM_Q), DF(COLEMAK_HARD), _______, _______, CM_N, CM_E, CM_I, CM_O, \
    CM_Z, CM_X, CM_C, CM_V, MO(LEFT_LAYERS), MO(NUMBERS), MO(FUNCTION), KC_SPC, CM_H, CM_K, CM_M, CM_J \
  ),

  [COLEMAK_HARD] = LAYOUT( \
    KC_RALT, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_CAPS, KC_CAPS, KC_RGUI, KC_RCTL, KC_RSFT, KC_LALT, KC_RALT, \
    LT(BROWSER, KC_SPC), KC_G, KC_D, KC_B, XXXXXXX, OS_SCREENSHOT, _______, _______, KC_COMM, MO(RIGHT_LAYERS), KC_DOT, _______, \
    KC_Q, KC_W, KC_F, KC_P, XXXXXXX, DF(COLEMAK_SOFT), _______, _______, KC_L, KC_U, KC_Y, KC_SCLN, \
    KC_A, KC_R, KC_S, KC_T, XXXXXXX, DF(COLEMAK_HARD), _______, _______, KC_N, KC_E, KC_I, KC_O, \
    KC_Z, KC_X, KC_C, KC_V, MO(LEFT_LAYERS), MO(NUMBERS), MO(FUNCTION), KC_SPC, KC_H, KC_K, KC_M, KC_J \
  ),

  [CAPSLOCK_SOFT] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, S(CM_G), S(CM_D), S(CM_B), S(RALT(CM_O)), _______, _______, _______, _______, _______, _______, _______, \
    S(CM_Q), S(CM_W), S(CM_F), S(CM_P), S(RALT(CM_W)), _______, _______, _______, S(CM_L), S(CM_U), S(CM_Y), _______, \
    S(CM_A), S(CM_R), S(CM_S), S(CM_T), S(RALT(CM_Q)), _______, _______, _______, S(CM_N), S(CM_E), S(CM_I), S(CM_O), \
    S(CM_Z), S(CM_X), S(CM_C), S(CM_V), _______, _______, _______, _______, S(CM_H), S(CM_K), S(CM_M), S(CM_J) \
  ),

  [CAPSLOCK_HARD] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, S(KC_G), S(KC_D), S(KC_B), _______, _______, _______, _______, _______, _______, _______, _______, \
    S(KC_Q), S(KC_W), S(KC_F), S(KC_P), _______, _______, _______, _______, S(KC_L), S(KC_U), S(KC_Y), _______, \
    S(KC_A), S(KC_R), S(KC_S), S(KC_T), _______, _______, _______, _______, S(KC_N), S(KC_E), S(KC_I), S(KC_O), \
    S(KC_Z), S(KC_X), S(KC_C), S(KC_V), _______, _______, _______, _______, S(KC_H), S(KC_K), S(KC_M), S(KC_J) \
  ),

  [LEFT_LAYERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_ENT, KC_LCTL, KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_UP, KC_END, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, MO(DEVELOPMENT), OS_WORD_DEL, KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [RIGHT_LAYERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, _______, KC_EQL, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_RCTL, _______, _______, _______, _______ \
  ),

  [FUNCTION] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    _______, MO(RGB_MODES), _______, MO(RGB_OPTIONS), _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, KC_PGUP, TG(CAPSLOCK_SOFT), KC_PGDN, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [NUMBERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(KC_PGUP), KC_LSFT, LCTL(KC_PGDN), _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, \
    _______, S(KC_TAB), OS_TASK_SW, KC_TAB, _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, \
    _______, OS_CUT, OS_COPY, OS_PASTE, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______, \
    _______, KC_DEL, OS_WORD_DEL, KC_BSPC, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______ \
  ),

  [DEVELOPMENT] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, S(KC_7), KC_GRAVE, S(KC_4), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_EXLM, _______, \
    _______, _______, OS_SAVE, MS_BTN3, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______, \
    _______, MO(DEVELOPMENT), _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______ \
  ),

  [BROWSER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, MS_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, OS_CLOSE_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [RGB_OPTIONS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, UG_VALU, UG_VALD, _______, _______, \
    _______, _______, _______, MO(RGB_OPTIONS), _______, _______, _______, _______, UG_SATU, UG_SATD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, UG_HUEU, UG_HUED, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, UG_TOGG, _______, _______, _______ \
  ),

  [RGB_MODES] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, UG_NEXT, UG_PREV, UG_SPDD, _______, \
    _______, MO(RGB_MODES), _______, _______, _______, _______, _______, _______, UG_SPDU, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case OS_CUT:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LGUI(KC_X) : LCTL(KC_X));

      return false;
    case OS_COPY:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LGUI(KC_C) : LCTL(KC_C));

      return false;
    case OS_PASTE:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LGUI(KC_V) : LCTL(KC_V));

      return false;
    case OS_SAVE:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LGUI(CM_S) : LCTL(CM_S));

      return false;
    case OS_CLOSE_TAB:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LGUI(KC_W) : LCTL(KC_W));

      return false;
    case OS_WORD_DEL:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LALT(KC_BSPC) : LCTL(KC_BSPC));

      return false;
    case OS_TASK_SW:
      record->event.pressed ? register_code(detected_host_os() == OS_MACOS ? KC_LGUI : KC_LALT) : unregister_code(detected_host_os() == OS_MACOS ? KC_LGUI : KC_LALT);

      return false;
    case OS_SCREENSHOT:
      if (record->event.pressed) {
        if (detected_host_os() == OS_MACOS) tap_code16(LGUI(S(KC_4)));
        else tap_code(KC_PSCR);
      }

      return false;
    case RALT(CM_O):
      if (record->event.pressed) SEND_STRING(SS_RALT("p"));

      return false;
    case RALT(CM_Q):
      if (record->event.pressed) SEND_STRING(SS_RALT("q"));

      return false;
    case RALT(CM_W):
      if (record->event.pressed) SEND_STRING(SS_RALT("w"));

      return false;
    case S(RALT(CM_O)):
      if (record->event.pressed) SEND_STRING(SS_LSFT(SS_RALT("p")));

      return false;
    case S(RALT(CM_Q)):
      if (record->event.pressed) SEND_STRING(SS_LSFT(SS_RALT("q")));

      return false;
    case S(RALT(CM_W)):
      if (record->event.pressed) SEND_STRING(SS_LSFT(SS_RALT("w")));

      return false;
    case MO(LEFT_LAYERS):
      record->event.pressed ? register_code(KC_LSFT) : unregister_code(KC_LSFT);

      return true;
    case MO(RIGHT_LAYERS):
      record->event.pressed ? register_code(KC_RSFT) : unregister_code(KC_RSFT);

      return true;
    case LCTL(KC_BSPC):
    case MO(DEVELOPMENT):
    case KC_UP:
    case KC_LEFT:
    case KC_DOWN:
    case KC_RGHT:
    case KC_HOME:
    case KC_END:
    case KC_ENT:
    case KC_ESC:
    case KC_BSPC:
      unregister_code(KC_LSFT);

      return true;
    case KC_SLSH:
    case KC_QUOT:
    case KC_MINS:
    case KC_EQL:
      unregister_code(KC_RSFT);

      return true;
    default: return true;
  }
};