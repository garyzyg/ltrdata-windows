CFLAGS = $(CFLAGS) -nologo -O1 /GL /GS- -c /MD /DNDEBUG
LFLAGS = $(LFLAGS) -nologo /LTCG
LINK = link /lib

TARGET = winstrct.lib

all: $(TARGET)

clean:
  -DEL /Q *.obj *.lib

.c.obj:
  $(CC) $(CFLAGS) $*.c

$(TARGET): *.obj
  $(LINK) $(LFLAGS) -out:$@ $**
