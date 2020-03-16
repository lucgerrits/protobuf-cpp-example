CXX      := -c++
CXXFLAGS := -std=c++11 -pedantic-errors -Wall -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm -Lprotobuf/.libs/lib -lprotobuf
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
PROTOS_DIR  := $(BUILD)
PROTOS      := $(wildcard protos/*.proto)
PROTO_OBJS  := $(PROTOS:%.proto=$(OBJ_DIR)/%.pb.o)
PROTO_CC  := $(PROTOS:%.proto=$(PROTOS_DIR)/%.pb.cc)
PROTO_PATH  := $(PROTOS:%.proto=$(PROTOS_DIR)/%.proto)
PROTO_INCLUDE  := -I$(PROTOS_DIR) -Iprotobuf/.libs/include

TARGET   := main
INCLUDE  := -Iinclude/ -Iprotobuf/.libs/include -I$(PROTOS_DIR)/protos
SRC      :=                      \
   $(wildcard src/common/*.cpp) \
   $(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS  += $(PROTO_OBJS)

all: build $(APP_DIR)/$(TARGET)

$(PROTOS_DIR)/%.pb.cc: $(PROTOS)
	@mkdir -p $(@D)
	protobuf/src/protoc --cpp_out=$(PROTOS_DIR) $<

$(PROTO_OBJS): $(PROTO_CC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(PROTO_INCLUDE) -c -o $@ $<

$(OBJ_DIR)/%.o: %.cpp $(PROTO_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)
	@echo 
	@echo "Target build:"
	@echo "   $(APP_DIR)/$(TARGET)"

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(PROTOS_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(BUILD)/*
	@# -@rm -rvf $(APP_DIR)/*
	@# -@rm -rvf $(PROTOS_DIR)/*
