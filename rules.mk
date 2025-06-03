ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

RGB_MATRIX_ENABLE    = yes
RGB_MATRIX_FRAMEBUFFER = yes