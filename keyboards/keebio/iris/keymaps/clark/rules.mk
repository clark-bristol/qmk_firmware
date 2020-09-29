RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = yes
TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = no
LEADER_ENABLE = yes
LINK_TIME_OPTIMIZATION_ENABLE = yes
BOOTMAGIC_ENABLE = no

# Commands for debug and configuration
COMMAND_ENABLE   = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
