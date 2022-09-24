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
LTO_ENABLE      = yes


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
# LTO_ENABLE = yes

DEFAULT_FOLDER = crkbd/rev1

LAYOUTS = split_3x5_3 split_3x6_3

# enable UNICODE & UNICODEMAP functionnalities for BEPO(french) layouts
# it allows the creation of specific keys with commands UC(c) & XP(i, j)
UNICODE_ENABLE = yes
UNICODEMAP_ENABLE = yes
