#include QMK_KEYBOARD_H

enum custom_layers {
  COLEMAK = 0,
  QWERTY,
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
  OS_SCREENSHOT,
  // Swedish layout symbols whose modifier/key combo differs between Windows and macOS
  SE_LCBR,
  SE_RCBR,
  SE_BSLS,
  SE_PIPE,
  SE_TILD,
  // explicit so it doesn't depend on Shift+base-key, which is 'O with the o umlaut key under Swedish
  SE_COLN,
  // explicit since the bare semicolon HID key produces ö under Swedish
  SE_SCLN,
  // NUMBERS layer digits whose shifted symbol should match the US row (@ $ ^ & * ( )) instead of the Swedish default
  NUM_2,
  NUM_4,
  NUM_6,
  NUM_7,
  NUM_8,
  NUM_9,
  NUM_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // default layer: hard-coded Colemak (works regardless of host OS layout)
  [COLEMAK] = LAYOUT( \
    KC_RALT, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_CAPS, KC_CAPS, KC_RGUI, KC_RCTL, KC_RSFT, KC_LALT, KC_RALT, \
    LT(BROWSER, KC_SPC), KC_G, KC_D, KC_B, KC_SCLN, OS_SCREENSHOT, _______, _______, KC_COMM, MO(RIGHT_LAYERS), KC_DOT, _______, \
    KC_Q, KC_W, KC_F, KC_P, KC_LBRC, DF(COLEMAK), _______, _______, KC_L, KC_U, KC_Y, SE_SCLN, \
    KC_A, KC_R, KC_S, KC_T, KC_QUOT, DF(QWERTY), _______, _______, KC_N, KC_E, KC_I, KC_O, \
    KC_Z, KC_X, KC_C, KC_V, MO(LEFT_LAYERS), MO(NUMBERS), MO(FUNCTION), KC_SPC, KC_H, KC_K, KC_M, KC_J \
  ),

  [QWERTY] = LAYOUT( \
    KC_RALT, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_CAPS, KC_CAPS, KC_RGUI, KC_RCTL, KC_RSFT, KC_LALT, KC_RALT, \
    LT(BROWSER, KC_SPC), KC_T, KC_G, KC_B, KC_SCLN, OS_SCREENSHOT, _______, _______, KC_COMM, MO(RIGHT_LAYERS), KC_DOT, _______, \
    KC_Q, KC_W, KC_E, KC_R, KC_LBRC, DF(COLEMAK), _______, _______, KC_U, KC_I, KC_O, KC_P, \
    KC_A, KC_S, KC_D, KC_F, KC_QUOT, DF(QWERTY), _______, _______, KC_J, KC_K, KC_L, SE_SCLN, \
    KC_Z, KC_X, KC_C, KC_V, MO(LEFT_LAYERS), MO(NUMBERS), MO(FUNCTION), KC_SPC, KC_H, KC_N, KC_M, KC_Y \
  ),

  [LEFT_LAYERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_ENT, KC_LCTL, KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_UP, KC_END, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, MO(DEVELOPMENT), OS_WORD_DEL, KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  // keycodes chosen so these produce / = ' - under a Swedish OS layout (same on Windows and macOS)
  [RIGHT_LAYERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, S(KC_7), _______, S(KC_0), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_NUHS, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_RCTL, _______, _______, _______, _______ \
  ),

  [FUNCTION] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, \
    _______, MO(RGB_MODES), _______, MO(RGB_OPTIONS), _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, \
    _______, KC_PGUP, KC_CAPS, KC_PGDN, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [NUMBERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, LCTL(KC_PGUP), KC_LSFT, LCTL(KC_PGDN), _______, _______, _______, _______, NUM_7, NUM_8, NUM_9, _______, \
    _______, S(KC_TAB), OS_TASK_SW, KC_TAB, _______, _______, _______, _______, NUM_4, KC_5, NUM_6, _______, \
    _______, OS_CUT, OS_COPY, OS_PASTE, _______, _______, _______, _______, KC_1, NUM_2, KC_3, _______, \
    _______, KC_DEL, OS_WORD_DEL, KC_BSPC, _______, _______, _______, _______, NUM_0, KC_DOT, _______, _______ \
  ),

  // keycodes chosen for correct output under a Swedish OS layout on both Windows and macOS
  [DEVELOPMENT] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, S(KC_6), S(KC_EQL), RALT(KC_4), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, S(KC_8), S(KC_9), KC_EXLM, _______, \
    _______, _______, OS_SAVE, MS_BTN3, _______, _______, _______, _______, SE_LCBR, SE_RCBR, SE_PIPE, SE_TILD, \
    _______, MO(DEVELOPMENT), _______, _______, _______, _______, _______, _______, RALT(KC_8), RALT(KC_9), SE_BSLS, _______ \
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

// drops any currently-held Shift for the duration of the tap, then restores it (used to send an AltGr/Shift combo that differs from plain Shift+key)
static void tap_dropping_shift(uint16_t keycode) {
  bool lsft = get_mods() & MOD_BIT(KC_LSFT);
  bool rsft = get_mods() & MOD_BIT(KC_RSFT);
  if (lsft) unregister_code(KC_LSFT);
  if (rsft) unregister_code(KC_RSFT);
  tap_code16(keycode);
  if (lsft) register_code(KC_LSFT);
  if (rsft) register_code(KC_RSFT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case NUM_2:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) tap_dropping_shift(RALT(KC_2)); // @
        else tap_code(KC_2);
      }

      return false;
    case NUM_4:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) tap_dropping_shift(RALT(KC_4)); // $
        else tap_code(KC_4);
      }

      return false;
    case NUM_6:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          tap_dropping_shift(S(KC_RBRC)); // dead circumflex on the ¨/^ key
          tap_code(KC_SPC); // space finalizes the dead key into a standalone ^
        } else tap_code(KC_6);
      }

      return false;
    case NUM_7:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) tap_dropping_shift(S(KC_6)); // &
        else tap_code(KC_7);
      }

      return false;
    case NUM_8:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) tap_dropping_shift(S(KC_NUHS)); // *
        else tap_code(KC_8);
      }

      return false;
    case NUM_9:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) tap_dropping_shift(S(KC_8)); // (
        else tap_code(KC_9);
      }

      return false;
    case NUM_0:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) tap_dropping_shift(S(KC_9)); // )
        else tap_code(KC_0);
      }

      return false;
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
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LGUI(KC_S) : LCTL(KC_S));

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
    case SE_LCBR:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? S(LALT(KC_8)) : RALT(KC_7));

      return false;
    case SE_RCBR:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? S(LALT(KC_9)) : RALT(KC_0));

      return false;
    case SE_BSLS:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? S(LALT(KC_7)) : RALT(KC_MINS));

      return false;
    case SE_PIPE:
      if (record->event.pressed) tap_code16(detected_host_os() == OS_MACOS ? LALT(KC_7) : RALT(KC_NUBS));

      return false;
    case SE_TILD:
      // dead tilde on the ¨/^ key; space finalizes it into a standalone ~
      if (record->event.pressed) {
        tap_code16(RALT(KC_RBRC));
        tap_code(KC_SPC);
      }

      return false;
    case SE_COLN:
      if (record->event.pressed) tap_code16(S(KC_DOT));

      return false;
    case SE_SCLN:
      // shift (e.g. held by MO(LEFT_LAYERS)/MO(RIGHT_LAYERS)) turns ; into :
      if (record->event.pressed) tap_code16((get_mods() & MOD_MASK_SHIFT) ? S(KC_DOT) : S(KC_COMM));

      return false;
    case S(KC_7):
      // both MO(LEFT_LAYERS) and MO(RIGHT_LAYERS) held: send ? instead of the single-shift /
      if (record->event.pressed && (get_mods() & MOD_BIT(KC_LSFT)) && (get_mods() & MOD_BIT(KC_RSFT))) {
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
        tap_code16(S(KC_MINS));
        // both MO keys are still held, so restore the shifts they own
        register_code(KC_LSFT);
        register_code(KC_RSFT);

        return false;
      }

      return true;
    case S(KC_0):
      // both MO(LEFT_LAYERS) and MO(RIGHT_LAYERS) held: send + instead of the single-shift =
      if (record->event.pressed && (get_mods() & MOD_BIT(KC_LSFT)) && (get_mods() & MOD_BIT(KC_RSFT))) {
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
        tap_code16(KC_MINS);
        // both MO keys are still held, so restore the shifts they own
        register_code(KC_LSFT);
        register_code(KC_RSFT);

        return false;
      }

      return true;
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
    case KC_NUHS:
      // both MO(LEFT_LAYERS) and MO(RIGHT_LAYERS) held: send " instead of the single-shift '
      if (record->event.pressed && (get_mods() & MOD_BIT(KC_LSFT)) && (get_mods() & MOD_BIT(KC_RSFT))) {
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
        tap_code16(S(KC_2));
        // both MO keys are still held, so restore the shifts they own
        register_code(KC_LSFT);
        register_code(KC_RSFT);

        return false;
      }

      // only drop RSFT while this key is down, and only restore it if RIGHT_LAYERS is still held
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
      } else if (layer_state_is(RIGHT_LAYERS)) {
        register_code(KC_RSFT);
      }

      return true;
    case KC_SLSH:
      unregister_code(KC_RSFT);

      return true;
    default: return true;
  }
};