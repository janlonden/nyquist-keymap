# Nyquist keymap

## Flash

1. Use QMK Firmware >= 0.19.4.
1. Run `qmk compile -kb keebio/nyquist/rev3 -km jan` from qmk-firmware root folder.
1. Push the reset button on the PCB.
1. Run `qmk flash -kb keebio/nyquist/rev3 -km jan` from qmk-firmware root folder.

## Clean build

To clean build folder run: `qmk clean`.

## Problems?

1. Can't reset? Make sure you use a proper cable and not a charging only one.
