RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = yes
# TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

# Commands for debug and configuration
COMMAND_ENABLE   = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
