#include QMK_KEYBOARD_H
#include "keymap_colemak.h"

extern keymap_config_t keymap_config;

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
  RGB,
  RGB_ANI
};

enum custom_keycodes {
  RALT_Q = SAFE_RANGE,
  RALT_O,
  RALT_W,
  RALT_SHIFT_Q,
  RALT_SHIFT_O,
  RALT_SHIFT_W,
  SPACE__BROWSER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_SOFT] = LAYOUT( \
    KC_RALT, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, _______, _______, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_RALT, \
    SPACE__BROWSER, CM_G, CM_D, CM_B, RALT_O, KC_PSCR, _______, _______, KC_COMM, MO(RIGHT_LAYERS), KC_DOT, _______, \
    CM_Q, CM_W, CM_F, CM_P, RALT_W, DF(COLEMAK_SOFT), _______, _______, CM_L, CM_U, CM_Y, CM_SCLN, \
    CM_A, CM_R, CM_S, CM_T, RALT_Q, DF(COLEMAK_HARD), _______, _______, CM_N, CM_E, CM_I, CM_O, \
    CM_Z, CM_X, CM_C, CM_V, MO(LEFT_LAYERS), TG(CAPSLOCK_SOFT), LCTL(CM_D), KC_SPC, CM_H, CM_K, CM_M, CM_J \
  ),

  [COLEMAK_HARD] = LAYOUT( \
    KC_RALT, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, _______, _______, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_RALT, \
    SPACE__BROWSER, KC_G, KC_D, KC_B, XXXXXXX, KC_PSCR, _______, _______, KC_COMM, MO(RIGHT_LAYERS), KC_DOT, _______, \
    KC_Q, KC_W, KC_F, KC_P, XXXXXXX, DF(COLEMAK_SOFT), _______, _______, KC_L, KC_U, KC_Y, KC_SCLN, \
    KC_A, KC_R, KC_S, KC_T, XXXXXXX, DF(COLEMAK_HARD), _______, _______, KC_N, KC_E, KC_I, KC_O, \
    KC_Z, KC_X, KC_C, KC_V, MO(LEFT_LAYERS), TG(CAPSLOCK_HARD), LCTL(KC_D), KC_SPC, KC_H, KC_K, KC_M, KC_J \
  ),

  [CAPSLOCK_SOFT] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, S(CM_G), S(CM_D), S(CM_B), RALT_SHIFT_O, _______, _______, _______, _______, _______, _______, _______, \
    S(CM_Q), S(CM_W), S(CM_F), S(CM_P), RALT_SHIFT_W, _______, _______, _______, S(CM_L), S(CM_U), S(CM_Y), _______, \
    S(CM_A), S(CM_R), S(CM_S), S(CM_T), RALT_SHIFT_Q, _______, _______, _______, S(CM_N), S(CM_E), S(CM_I), S(CM_O), \
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
    _______, KC_PGUP, KC_DEL, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, \
    MO(RGB_ANI), KC_TAB, KC_ENT, KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, \
    MO(RGB), KC_HOME, KC_UP, KC_END, _______, _______, _______, _______, _______, _______, _______, _______, \
    MO(NUMBERS), KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, \
    MO(FUNCTION), MO(DEVELOPMENT), LCTL(KC_BSPC), KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [RIGHT_LAYERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, _______, KC_EQL, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [NUMBERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, \
    _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, KC_4, KC_5, KC_6, _______, \
    _______, KC_LALT, KC_LSFT, KC_LCTL, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_BSPC, \
    _______, _______, _______, _______, _______, KC_RALT, _______, _______, KC_0, KC_DOT, _______, KC_ENT \
  ),

  [FUNCTION] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, KC_LALT, KC_LSFT, KC_LCTL, _______, KC_RALT, _______, _______, KC_F1, KC_F2, KC_F3, _______ \
  ),

  [DEVELOPMENT] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_EXLM, _______, \
    _______, _______, LCTL(CM_S), _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______ \
  ),

  [BROWSER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(KC_W), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [RGB] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_VAD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAI, RGB_SAD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_HUD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______ \
  ),

  [RGB_ANI] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_M_X, RGB_M_G, RGB_M_T, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_M_SW, RGB_M_SN, RGB_M_K, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};

static uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case RALT_O:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("p"));
      }
      return false;
    case RALT_Q:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("q"));
      }
      return false;
    case RALT_W:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("w"));
      }
      return false;
    case RALT_SHIFT_O:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT("p")));
      }
      return false;
    case RALT_SHIFT_Q:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT("q")));
      }
      return false;
    case RALT_SHIFT_W:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT("w")));
      }
      return false;
    case SPACE__BROWSER:
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(BROWSER);
      } else {
        if (timer_elapsed(key_timer) < 150) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        layer_off(BROWSER);
      }
      return false;
  }
  return true;
};
