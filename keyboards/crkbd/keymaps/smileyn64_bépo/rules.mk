# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
MOUSEKEY_ENABLE = yes				# Mouse keys
RGBLIGHT_ENABLE = yes    		# Enable WS2812 RGB underlight.
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
#OLED_ROTATION_90 = yes

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812


# if firmware size over limit, try this option
LTO_ENABLE = yes

#default keyboard version
#set to r2g for r3 or r2g version of keyboard
#todo: this parameter seems to be ignored during compilation
#				the compilator still uses the r1 as from keyboard generic folder rules.mk
DEFAULT_FOLDER = crkbd/r2g


LAYOUTS = split_3x5_3 split_3x6_3

# enable UNICODE & UNICODEMAP functionnalities for BEPO(french) layouts
# it allows the creation of specific keys with commands UC(c) & XP(i, j)
UNICODE_ENABLE = yes
UNICODEMAP_ENABLE = yes
