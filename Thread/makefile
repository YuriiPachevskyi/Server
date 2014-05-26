obj_dir     := obj
bin_dir     := bin
LIBS        := -lpthread
shared_file := server
target      := $(bin_dir)/$(shared_file)

c_src    +=\
Listener.cpp\
Thread.cpp\
main.cpp

# Derive the objects to be built:
all_objs       := $(c_src:.cpp=.o)
# all_objs_nodir := $(notdir $(all_objs))

CC_FLAGS  += -g -c -Wall -fPIC -MD

VPATH = $(dir $(all_objs))
vpath %.o ./$(obj_dir)

# All Target
.PHONY: all makedir clean
all: makedir $(target)

makedir:
	@mkdir -p $(obj_dir) $(bin_dir)

# Tool invocations	
$(target): $(all_objs)
	@echo Building target: $@
	@g++  $(addprefix $(obj_dir)/, $(all_objs)) $(LIBS) -o $(bin_dir)/$(shared_file)
	@echo

%.o:%.cpp
	@echo Building file: $(notdir $<)
	@g++ $(CC_FLAGS)  -o $(obj_dir)/$@ $<

# Other Targets
clean:
	rm -rf $(obj_dir) $(bin_dir)
	@echo
