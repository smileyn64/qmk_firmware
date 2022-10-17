#### Controller Parameters ####
# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

#default keyboard version
#set to r2g for r3 or r2g version of keyboard
#todo: this parameter seems to be ignored during compilation
#				the compilator still uses the r1 as from keyboard generic folder rules.mk
DEFAULT_FOLDER = crkbd/r2g

# if firmware size over limit, try this option
# This will cause the final step to take longer, but should get you a smaller compiled size.
# This also disables Action Functions, and Action Macros, both of which are deprecated.
LTO_ENABLE = yes

# Enable VIA
# may have issues with Unicode keymaps
VIA_ENABLE = yes

# This allows you to hold a key (usually Escape by default)
# to reset the EEPROM settings that persist over power loss
# and ready your keyboard to accept new firmware.
BOOTMAGIC_ENABLE = no


#### Console Parameters ####
# This allows you to print messages that can be read using hid_listen.
CONSOLE_ENABLE = no         # Console for debug

# This enables magic commands, typically fired with the default magic key combo LSHIFT+RSHIFT+KEY.
# Magic commands include turning on debugging messages (MAGIC+D) or temporarily toggling NKRO (MAGIC+N).
COMMAND_ENABLE = no         # Commands for debug and configuration


#### Keyboard Parameters ####
# Enables your LED to breath while your computer is sleeping. Timer1 is being used here.
# This feature is largely unused and untested, and needs updating/abstracting.
SLEEP_LED_ENABLE = no

#This enables the in-switch LED backlighting. You can specify the backlight pin by putting this in your config.h:
#define BACKLIGHT_PIN B7
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

#This enables the LED backlighting of the keyboard.
RGBLIGHT_ENABLE = no
RGBLIGHT_DRIVER = WS2812		#WS2811|WS2812|WS2812B|WS2812C|SK6812|SK6812MINI|SK6805|APA102

# This feature allows you to use RGB LED matrices driven by external drivers.
# It hooks into the RGBLIGHT system so you can use the same keycodes as RGBLIGHT to control it.
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812

# This allows you output audio on the C6 pin (needs abstracting).
AUDIO_ENABLE = no

# Use this to debug changes to variable values
VARIABLE_TRACE = no

# This enables split keyboard support (dual MCU like the let’s split and bakingpy’s boards)
# and includes all necessary files located at quantum/split_common
SPLIT_KEYBOARD = yes

# As there is no standard split communication driver for ARM-based split keyboards yet,
# SPLIT_TRANSPORT = custom must be used for these.
# It will prevent the standard split keyboard communication code (which is AVR-specific) from being included,
# allowing a custom implementation to be used.
#SPLIT_TRANSPORT

# Lets you replace the default matrix scanning routine with your own code. For further details, see the Custom Matrix page.
#CUSTOM_MATRIX

# Lets you replace the default key debouncing routine with an alternative one. If custom you will need to provide your own implementation.
#DEBOUNCE_TYPE

# Enables deferred executor support – timed delays before callbacks are invoked. See deferred execution for more information.
DEFERRED_EXEC_ENABLE = no


#### Keymap Parameters ####
# For a keyboard to support a layout, the variable must be defined in it’s <keyboard>.h,
# and match the number of arguments/keys (and preferably the physical layout):
#LAYOUTS = split_3x5_3 split_3x6_3

# A feature that lets you control your mouse cursor and click from your keyboard.
MOUSEKEY_ENABLE = no     # Mouse keys

# This allows you to use the system and audio control key codes.
EXTRAKEY_ENABLE = no    # Audio control and System control

# This enables MIDI sending and receiving with your keyboard.
# To enter MIDI send mode, you can use the keycode MI_ON, and MI_OFF to turn it off.
# This is a largely untested feature, but more information can be found in the quantum/quantum.c file.
MIDI_ENABLE = no

# UNICODE_ENABLE allows you to send Unicode characters using UC(<code point>) in your keymap.
# Code points up to 0x7FFF are supported.
# This covers characters for most modern languages, as well as symbols, but it doesn’t cover emoji.
# UNICODEMAP_ENABLE allows you to send Unicode characters using X(<map index>) in your keymap.
# You will need to maintain a mapping table in your keymap file. All possible code points (up to 0x10FFFF) are supported.
# UCIS_ENABLE allows you to send Unicode characters by inputting a mnemonic corresponding to the character you want to send.
# You will need to maintain a mapping table in your keymap file. All possible code points (up to 0x10FFFF)
# /!\ UNICODE_ENABLE|UNICODEMAP_ENABLE|UCIS_ENABLE methods cannot be active together

UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
UCIS_ENABLE = no

# This enables key lock.
KEY_LOCK_ENABLE = no

# To enable the OLED feature
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306

#The WPM feature uses time between keystrokes to compute a rolling average words per minute rate and makes this available for various uses.
#For split keyboards using soft serial, the computed WPM score will be available on the master AND slave half.
WPM_ENABLE = yes

OCEAN_DREAM_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
    #... your code here...

    ifdef OCEAN_DREAM_ENABLE
        ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
            SRC += Animations/ocean_dream.c
            OPT_DEFS += -DOCEAN_DREAM_ENABLE
        endif
    endif
    ifndef OCEAN_DREAM_ENABLE
        SRC += Animations/ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
endif
