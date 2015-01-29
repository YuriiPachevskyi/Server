obj_dir     := .obj
LIBS        := 
shared_file := client
target      := $(shared_file)
log_status  := -DLOG_STATUS=PRINT_INFO

all_inc +=\
-I ../../includes\
-I ../client\
-I ../../log\

c_src +=\
../../log/Log.cpp\
../client/Client.cpp\
../main/main.cpp

all_objs       := $(c_src:.cpp=.o)
all_objs_nodir := $(notdir $(all_objs))

CC_FLAGS  += -g -c -Wall -fPIC -MD

VPATH = $(dir $(all_objs))
vpath %.o ./$(obj_dir)

.PHONY: all makedir clean
all: makedir $(target)

makedir:
	@mkdir -p $(obj_dir) $(bin_dir)

$(target): $(all_objs_nodir)
	@echo Building target: $@
	@g++  $(addprefix $(obj_dir)/, $(all_objs_nodir)) $(LIBS) -o $(shared_file)
	@echo

%.o:%.cpp
	@echo Building file: $(notdir $<)
	@g++ $(CC_FLAGS) $(all_inc) $(log_status) -o $(obj_dir)/$@ $<

clean:
	rm -rf $(obj_dir) $(shared_file)
	@echo
