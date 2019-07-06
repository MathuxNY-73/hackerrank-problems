SOURCES = $(shell ls *.scala)
S = scala
SC = scalac
TARGET = target
CP = $(TARGET):scalatest.jar
SPEC = scala.RomanSpec

compile: $(SOURCES:.scala=.class)

%.class: %.scala
	@echo "Compiling $*.scala.."
	@$(SC) -cp $(CP) -d . $*.scala -feature -deprecation

test: compile
	@$(S) -cp $(CP) org.scalatest.tools.Runner -p . -o -s $(SPEC)

clean:
	@$(RM) *.class
